#pragma once

namespace g8
{
	class IPausable
	{
	public:
		virtual void Pause() = 0;
		virtual void Resume() = 0;

		virtual bool IsActive() = 0;
	};
}