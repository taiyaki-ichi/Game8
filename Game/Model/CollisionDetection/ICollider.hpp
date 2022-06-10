#pragma once
#include"Rect.hpp"
#include"ColliderTag.hpp"

namespace g8
{
	class ICollider
	{
	public:
		virtual Rect const& GetRect() = 0;
		virtual void AddHitObject(ICollider const&) {};
		virtual ColliderTag GetColliderTag() { return ColliderTag::None; }
	};
}