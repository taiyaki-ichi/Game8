#pragma once
#include<algorithm>
#include"CollisionDetection/ColliderCollisionDetection.hpp"

namespace g8
{
	template<typename UpdaterContainer, typename ColliderContainer>
	class Panel
	{
		UpdaterContainer updaters{};
		ColliderContainer colliders{};

	public:
		void Update()
		{
			for (auto& u : updaters)
				u.Update1();
			
			ColliderCollisionDetection(std::begin(c), std::begin(c));

			for (auto& u : updaters)
				u.Update2();
		}

		void AddUpdater(typename UpdaterContainer::value_type const& value) {
			updaters.push_back(value);
		}
		void RemoveUpdater(typename UpdaterContainer::value_type const& value) {
			std::remove(std::begin(updaters), std::end(updaters), value);
		}
		void AddCollider(typename ColliderContainer::value_type const& value) {
			colliders.push_back(value);
		}
		void RemoveCollider(typename ColliderContainer::value_type const& value) {
			std::remove(std::begin(colliders), std::end(colliders), value);
		}
	};

}