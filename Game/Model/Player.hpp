#pragma once
#include"Vector2D.hpp"
#include"IObject.hpp"
#include"CollisionDetection/ICollider.hpp"

namespace g8
{
	class Player : public IStageObject, public ICollider
	{
		Rect collider{};

	public:
		void Update1() override;
		void Update2() override;

		Rect const& GetRect() override;
		void AddHitObject(ICollider const&) override;
		ColliderTag GetColliderTag() override;
	};
}