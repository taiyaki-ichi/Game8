#pragma once
#include<Array>
#include"Vector2D.hpp"
#include<vector>
#include"CollisionDetection/ICollider.hpp"

namespace g8
{
	struct StagePosition
	{
		Vector2D position{};

		//true : 表
		//false : 裏
		bool dimension{};
	};

	struct KinkLine
	{
		//片方の要素は必ず0
		float line{};

		//X軸にそって曲がっているかどうか
		bool isX{};

		//true : 表から裏への折れ線
		//false : 裏から表への折れ線
		bool dir{};
	};

	struct Stage
	{
	public:

		constexpr static int MAX_KINK_LINE_NUM = 2;

		std::array<KinkLine, MAX_KINK_LINE_NUM> kinkLine{};
		int kinkLineNum = 0;

		std::array<int, MAX_KINK_LINE_NUM> activeKinkLineIndexs{};

		float width{};
		float height{};

		template<typename Policy>
		void KinkLineScan(bool dimension,Policy policy)
		{
			for (int i = 0; i < activeKinkLineIndexs.size(); i++)
			{
				if (activeKinkLineIndexs[i] < 0)
					continue;

				auto const& activeKinkLine = kinkLine[activeKinkLineIndexs[i]];

				//折れ線が手前に折れている時
				if (activeKinkLine.dir != dimension)
				{
					//KinkLineがある方向
					float dir = activeKinkLine.line > 0.f ? 1.f : -1.f;
					float edge = activeKinkLine.isX ? width : height;

					//手前に折れれている紙が下の紙と重なるライン
					auto lineInThisDimension = edge / 2.f * dir - (edge / 2.f - std::abs(activeKinkLine.line)) * 2.f * dir;

					policy(activeKinkLine, lineInThisDimension);
				}
			}
		}

		StagePosition Move(StagePosition const& stagePosition, Vector2D const& move)
		{

			StagePosition result{};
			result.position = stagePosition.position + move;
			result.dimension = stagePosition.dimension;

			auto policy = [&result,this](auto const& activeKinkLine, auto line)
			{
				float dir = activeKinkLine.line > 0.f ? 1.f : -1.f;
				float edge = activeKinkLine.isX ? this->width : this->height;
				float& pos = activeKinkLine.isX ? result.position.x : result.position.y;

				if ((dir > 0.f && pos > line) || (dir < 0.f && pos < line))
				{
					auto diff = pos - line;
					pos = edge / 2.f * dir - diff;

					result.dimension = !result.dimension;
				}
			};

			KinkLineScan(stagePosition.dimension, std::move(policy));

			return result;
		}

		//RectがまたいでいるKinkLineの数
		std::array<Rect, MAX_KINK_LINE_NUM + 1> GetSplitRect(Rect const& rect, bool dimension)
		{
			std::array<Rect, MAX_KINK_LINE_NUM + 1> result{};

			result[0] = rect;
			std::size_t i = 0;

			auto policy = [&result, this, &rect, &i](auto const& activeKinkLine, auto line)
			{
				float dir = activeKinkLine.line > 0.f ? 1.f : -1.f;
				float pos = activeKinkLine.isX ? result[i].position.x : result[i].position.y;
				float edge = activeKinkLine.isX ? this->width : this->height;
				float rectEdge = activeKinkLine.isX ? result[i].width : result[i].height;

				pos = (dir > 0) ? pos + rectEdge / 2.f : pos - rectEdge / 2.f;

				if ((dir > 0.f && pos > line) || (dir < 0.f && pos < line))
				{
					auto diff = pos - line;
					pos = edge / 2.f * dir - diff / 2.f;

					if (activeKinkLine.isX)
					{
						result[i].width -= std::abs(diff) / result[i].scale;
						result[i].position.x -= diff / 2.f;

						result[i + 1].width = std::abs(diff) / result[i].scale;
						result[i + 1].height = result[i].height;
						result[i + 1].position.x = pos;
						result[i + 1].position.y = result[i].position.y;
						result[i + 1].scale = result[i].scale;

						if (diff < 0.f && dir < 0.f || diff > 0.f && dir > 0.f)
							std::swap(result[i], result[i + 1]);
					}
					else
					{
						result[i].height -= std::abs(diff) / result[i].scale;
						result[i].position.y -= diff / 2.f;

						result[i + 1].height = std::abs(diff) / result[i].scale;
						result[i + 1].width = result[i].width;
						result[i + 1].position.y = pos;
						result[i + 1].position.x = result[i].position.x;
						result[i + 1].scale = result[i].scale;

						if (diff < 0.f && dir < 0.f || diff > 0.f && dir > 0.f)
							std::swap(result[i], result[i + 1]);
					}

					i++;
				}
			};

			KinkLineScan(dimension, std::move(policy));

			return result;
		}

	};
}