#pragma once
#include"IPausable.hpp"

namespace g8
{
	class IUpdater : public IPausable
	{
		bool isActive = true;

	public:
		//“–‚½‚è”»’è‚Ì‘O‚ÉŒÄ‚Î‚ê‚é
		virtual void Update1() {};
		//“–‚½‚è”»’è‚ÌŒã‚ÉŒÄ‚Î‚ê‚é
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