#pragma once
#include"Vector2D.hpp"

namespace g8
{
	//vecをax+by+c=0について反転させる
	Vector2D Frip(Vector2D const& vec, float a, float b, float c);
}