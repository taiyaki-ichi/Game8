#pragma once
#include"ColliderCollisionDetection.hpp"

namespace g8
{
	template<typename InputIterator>
	void ColliderCollisionDetection(InputIterator first, InputIterator last)
	{
		ColliderCollisionDetection(first, last,
			[](auto iter1, auto iter2) {
				iter1->AddHitCollider(*iter2);
				iter2->AddHitCollider(*iter1);
			},
			[](auto const& lhs, auto const& rhs) {
				return IsHit(lhs.GetRect(), lhs.GetRect());
			});
	}
}