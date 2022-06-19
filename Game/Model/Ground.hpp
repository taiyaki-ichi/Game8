#pragma once
#include"ICollider.hpp"

namespace g8
{
	class Ground : public ICollider
	{
		Rect rect{};

	public:
		Ground(Rect rect)
			:rect{ rect }
		{}
	};
}