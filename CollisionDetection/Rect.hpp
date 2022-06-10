#pragma once
#include"Vector2D.hpp"

namespace g8
{
	struct Rect
	{
		Vector2D position{};
		float width{};
		float height{};
		float scale{};
		float rotation{};
	};
}