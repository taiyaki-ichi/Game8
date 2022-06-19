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

			//��
			std::vector<Ground> ground{};
			Player player(stageData.player);
		

			//��x���܂�Ă��Ȃ���Ԃ̕\��
			for (auto& r : stageData.frontGrounds)
			{
				auto& g = ground.emplace_back(r);
				panel[0].AddCollider(&g);
			}

			//��x���܂�Ă��Ȃ���Ԃ̗���
			for (auto& r : stageData.backGrounds)
			{
				auto& g = ground.emplace_back(r);
				panel[1].AddCollider(&g);
			}

			//��͍ċA�I�ɂ���


		

		}
	};
}