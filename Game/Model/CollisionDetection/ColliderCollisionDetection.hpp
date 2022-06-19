#pragma once
#include<iterator>
#include<type_traits>
#include"ColliderCollisionDetection.hpp"

namespace g8
{
	template<typename InputIterator>
	void ColliderCollisionDetection(InputIterator first, InputIterator last)
	{
		using value_type = typename std::iterator_traits<InputIterator>::value_type;

		if constexpr (std::is_pointer_v<value_type>)
		{
			ColliderCollisionDetection(first, last,
				[](auto iter1, auto iter2) {
					iter1->AddHitCollider(**iter2);
					iter2->AddHitCollider(**iter1);
				},
				[](auto lhs, auto rhs) {
					return (*lhs)->IsActive() && (*rhs)->IsActive() && IsHit((*lhs)->GetRect(), (*lhs)->GetRect());
				});
		}
		else
		{
			ColliderCollisionDetection(first, last,
				[](auto iter1, auto iter2) {
					iter1->AddHitCollider(*iter2);
					iter2->AddHitCollider(*iter1);
				},
				[](auto const& lhs, auto const& rhs) {
					return lhs->IsActive() && rhs->IsActive() && IsHit(lhs->GetRect(), lhs->GetRect());
				});
		}
	}
}