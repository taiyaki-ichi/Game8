#pragma once
#include"Panel.hpp"
#include"IUpdater.hpp"
#include"ICollider.hpp"
#include"StageData.hpp"
#include"Ground.hpp"
#include"Player.hpp"

#include<vector>

namespace g8
{
	class Stage
	{
		using StagePanel = Panel<std::vector<IUpdater*>, std::vector<ICollider*>>;

	public:
		Stage(StageData&& stageData)
		{
			std::array<StagePanel, StageData::MAX_KINK_LINE * 2> panel{};

			//‰¼
			std::vector<Ground> ground{};
			Player player(stageData.player);
		

			//ˆê“x‚àÜ‚ê‚Ä‚¢‚È‚¢ó‘Ô‚Ì•\–Ê
			for (auto& r : stageData.frontGrounds)
			{
				auto& g = ground.emplace_back(r);
				panel[0].AddCollider(&g);
			}

			//ˆê“x‚àÜ‚ê‚Ä‚¢‚È‚¢ó‘Ô‚Ì— –Ê
			for (auto& r : stageData.backGrounds)
			{
				auto& g = ground.emplace_back(r);
				panel[1].AddCollider(&g);
			}

			
			std::array<Vector2D, 4> paper{ {
				{stageData.width / 2.f,stageData.height / 2.f},
				{-stageData.width / 2.f,stageData.height / 2.f},
				{-stageData.width / 2.f,-stageData.height / 2.f},
				{stageData.width / 2.f,-stageData.height / 2.f}
				} };

			for (std::size_t i = 0; i < stageData.MAX_KINK_LINE; i++)
			{
				auto const& kinkLine = stageData.kinkLines[i];

				



			}


		

		}
	};
}