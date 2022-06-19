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

			//仮
			std::vector<Ground> ground{};
			Player player(stageData.player);
		

			//一度も折れていない状態の表面
			for (auto& r : stageData.frontGrounds)
			{
				auto& g = ground.emplace_back(r);
				panel[0].AddCollider(&g);
			}

			//一度も折れていない状態の裏面
			for (auto& r : stageData.backGrounds)
			{
				auto& g = ground.emplace_back(r);
				panel[1].AddCollider(&g);
			}

			//後は再帰的にやれる


		

		}
	};
}