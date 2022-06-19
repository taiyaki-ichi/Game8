#pragma once
#include"Vector2D.hpp"
#include"IUpdater.hpp"
#include"ICollider.hpp"

namespace g8
{
	class Player : public IUpdater, public ICollider
	{
		Rect collider{};

	public:
		Player(Vector2D pos)
		{}

		void Update1() override;
		void Update2() override;

		Rect const& GetRect() override;
		void Hit(ICollider const&) override;
		ObjectTag GetTag() override;
	};
}