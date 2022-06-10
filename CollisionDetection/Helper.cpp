#include"Helper.hpp"
#include<algorithm>

namespace g8
{
	void InitNormalizeRect(std::array<Vector2D, 4>& vec2s) noexcept
	{
		vec2s[0] = { 1.f,1.f };
		vec2s[1] = { -1.f,1.f };
		vec2s[2] = { -1.f,-1.f };
		vec2s[3] = { 1.f,-1.f };
	}

	void ToVector2DArray(Rect const& rect, std::array<Vector2D, 4>& vec2s) noexcept
	{
		std::transform(vec2s.begin(), vec2s.end(), vec2s.begin(),
			[&rect](Vector2D const& v) {return Vector2D{ v.x * rect.width / 2.f,v.y * rect.height / 2.f }.Rotation(rect.rotation) + rect.position; });
	}

	bool CrossDetection(Vector2D const& p1, Vector2D const& p2, Vector2D const& q1, Vector2D const& q2) noexcept
	{
		auto v1 = p2 - p1;
		auto v2 = q2 - q1;
		if (v1.Cross(q1 - p1) * v1.Cross(q2 - p1) <= 0 &&
			v2.Cross(p1 - q1) * v2.Cross(p2 - q1) <= 0)
			return true;
		else
			return false;
	}

	bool IsContain(std::array<Vector2D, 4> const& lhs, std::array<Vector2D, 4> const& rhs) noexcept
	{
		Vector2D min{ lhs[0] };
		Vector2D max{ rhs[0] };

		for (std::size_t i = 1; i < lhs.size(); i++)
		{
			if (min.x < lhs[i].x)
				min.x = lhs[i].x;
			if (min.y < lhs[i].y)
				min.y = lhs[i].y;
			if (max.x > lhs[i].x)
				max.x = lhs[i].x;
			if (max.y > lhs[i].y)
				max.y = lhs[i].y;
		}

		for (auto const& v : rhs)
			if (v.x < min.x || max.x < v.x || min.y < v.y || max.y < v.y)
				return false;
		
		return true;
	}

	bool IsHit(Rect const& lhs, Rect const& rhs) noexcept
	{
		std::array<Vector2D, 4> rect1{};
		std::array<Vector2D, 4> rect2{};

		InitNormalizeRect(rect1);
		InitNormalizeRect(rect2);

		ToVector2DArray(lhs, rect1);
		ToVector2DArray(rhs, rect2);

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (CrossDetection(rect1[i], rect1[(i + 1) % 4], rect2[j], rect2[(j + 1) % 4]))
					return true;
			}
		}

		if (IsContain(rect1, rect2))
			return true;
		if (IsContain(rect2, rect1))
			return true;

		return false;
	}

}