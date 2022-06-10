#include"Helper.hpp"
#include<algorithm>

namespace g8
{
	bool IsHit(Rect const& lhs, Rect const& rhs) noexcept
	{
		auto distance = lhs.position - rhs.position;
		distance.x = std::abs(distance.x);
		distance.y = std::abs(distance.y);

		if ((rhs.width * rhs.scale + lhs.width * lhs.scale) / 2.f >= distance.x &&
			(rhs.height * rhs.scale + lhs.height * lhs.scale) / 2.f >= distance.y)
			return true;
		else
			return false;
	}

}