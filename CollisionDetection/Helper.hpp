#pragma once
#include"Rect.hpp"
#include<array>

namespace g8
{
	//Rect���m���������Ă��邩�ǂ���
	bool IsHit(Rect const&, Rect const&) noexcept;
}