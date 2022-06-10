#pragma once
#include"Vector2D.hpp"

namespace g8
{
	class Player
	{
		Vector2D position{};

	public:
		void Update1();

		void Update2();

		void AddHitObject();
	};
}