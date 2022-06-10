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

		StagePosition Move(StagePosition const& stagePosition, Vector2D const& move)
		{
			StagePosition result{};
			result.position = stagePosition.position + move;
			result.dimension = stagePosition.dimension;

			if (result.position.x > width / 2.f)
				result.position.x = width / 2.f;
			if (result.position.x < -width / 2.f)
				result.position.x = -width / 2.f;
			if (result.position.y > height / 2.f)
				result.position.y = height / 2.f;
			if (result.position.y < -height / 2.f)
				result.position.y = -height / 2.f;


			for (int i = 0; i < activeKinkLineIndexs.size(); i++)
			{
				if (activeKinkLineIndexs[i] < 0)
					continue;

				auto const& activeKinkLine = kinkLine[activeKinkLineIndexs[i]];

				//折れ線が手前に折れている時
				if (activeKinkLine.dir != stagePosition.dimension)
				{
					//KinkLineがある方向
					float dir = activeKinkLine.line > 0.f ? 1.f : -1.f;
					float edge = activeKinkLine.isX ? width : height;
					float& pos = activeKinkLine.isX ? result.position.x : result.position.y;

					//手前に折れれている紙が下の紙と重なるライン
					auto line = edge / 2.f * dir - (edge / 2.f - std::abs(activeKinkLine.line)) * 2.f * dir;

					if ((dir > 0.f && pos > line)|| (dir < 0.f && pos < line))
					{
						auto diff = pos - line;
						pos = edge / 2.f * dir - diff;

						result.dimension = !result.dimension;
					}

				}
				//奥に折れている場合
				else
				{
					float& pos = activeKinkLine.isX ? result.position.x : result.position.y;
					if (std::abs(pos) > std::abs(activeKinkLine.line))
					{
						pos = activeKinkLine.line;
					}
				}
			}

			return result;
		}

	};
}