#pragma once
#include"IPausable.hpp"

namespace g8
{
	class IUpdater : public IPausable
	{
		bool isActive = true;

	public:
		//�����蔻��̑O�ɌĂ΂��
		virtual void Update1() {};
		//�����蔻��̌�ɌĂ΂��
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