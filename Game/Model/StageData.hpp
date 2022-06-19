#pragma once
#include<array>
#include<vector>
#include"Vector2D.hpp"
#include"Rect.hpp"


namespace g8
{
	struct KinkLine
	{
		//true : •\‚©‚çŒ©‚Ä’J
		//false : •\‚©‚çŒ©‚Ä— 
		bool dir;

		//ax+by+c=0
		float a, b, c;
	};

	struct StageData
	{
		static constexpr std::size_t MAX_KINK_LINE = 3;

		float width;
		float height;

		std::array<KinkLine, MAX_KINK_LINE> kinkLines{};
		std::size_t activeKinkLineNum = 0;

		Vector2D player{};
		std::vector<Rect> frontGrounds{};
		std::vector<Rect> backGrounds{};
		
	};
}