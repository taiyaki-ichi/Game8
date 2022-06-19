#pragma once
#include"IPausable.hpp"

namespace g8
{
	class IUpdater : public IPausable
	{
		bool isActive = true;

	public:
		//当たり判定の前に呼ばれる
		virtual void Update1() {};
		//当たり判定の後に呼ばれる
		virtual void Update2() {};

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