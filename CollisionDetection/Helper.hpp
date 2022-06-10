#pragma once
#include"Rect.hpp"
#include<array>

namespace g8
{
	//一辺の長さが2の正方形の点を反時計回りの順に入れ込む
	void InitNormalizeRect(std::array<Vector2D, 4>&) noexcept;

	//Rectからその四角形を構成する四点を計算
	void ToVector2DArray(Rect const&, std::array<Vector2D, 4>&) noexcept;

	//p1, p2 からなる線と q1, q2 からなる線が交差しているかどうか
	bool CrossDetection(Vector2D const& p1, Vector2D const& p2, Vector2D const& q1, Vector2D const& q2) noexcept;

	//片方の四角形が完全に他方の内側にあるかどうかの判定
	bool IsContain(std::array<Vector2D, 4> const&, std::array<Vector2D, 4> const&) noexcept;

	//Rect同士が当たっているかどうか
	bool IsHit(Rect const&, Rect const&) noexcept;
}