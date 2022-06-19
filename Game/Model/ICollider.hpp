#pragma once
#include"Rect.hpp"
#include"IPausable.hpp"
#include"ObjectTag.hpp"

namespace g8
{
	class ICollider : public IPausable
	{
		bool isActive = true;

	public:
		virtual Rect const& GetRect() = 0;
		virtual void Hit(ICollider const&) {};
		virtual ObjectTag GetTag() { return ObjectTag::None; }

		void Pause() override {
			isActive = false;
		}
		void Resume() override {
			isActive = true;
		}
		bool IsActive() override {
			return isActive;
		}
	};
}