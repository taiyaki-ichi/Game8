#pragma once
#include"Rect.hpp"
#include<array>

namespace g8
{
	//Rect同士が当たっているかどうか
	bool IsHit(Rect const&, Rect const&) noexcept;
}