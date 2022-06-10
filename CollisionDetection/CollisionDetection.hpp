#pragma once
#include"Helper.hpp"

namespace g8
{
	template<typename InputIterator,typename OutputIterator,typename IsHitPolicy>
	void CollisionDetection(InputIterator first, InputIterator last, OutputIterator result,IsHitPolicy isHItPolicy)
	{
		auto iter1= first;
		while (iter1 != last)
		{
			auto iter2 = iter1 + 1;
			while (iter2 != last)
			{
				if (isHItPolicy(*iter1, *iter2))
				{
					*(result++) = iter1;
					*(result++) = iter2;
				}

				iter2++;
			}

			iter1++;
		}
	}

	template<typename InputIterator, typename OutputIterator>
	void CollisionDetection(InputIterator first, InputIterator last, OutputIterator result)
	{
		CollisionDetection(first, last, result, [](auto const& rhs, auto const& lhs) {return IsHit(rhs, lhs); });
	}
}