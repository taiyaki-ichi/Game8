#pragma once
#include"Vector2D.hpp"
#include<iterator>
#include<numeric>
#include<algorithm>

namespace g8
{
	//vec‚ğax+by+c=0‚É‚Â‚¢‚Ä”½“]‚³‚¹‚é
	Vector2D Frip(Vector2D const& vec, float a, float b, float c);

	//“_‚ª‘½ŠpŒ`‚Ì“à‘¤‚É‚ ‚é‚©‚Ç‚¤‚©
	template<typename Point,typename Iter>
	constexpr bool IsInclude(Point const& point, Iter first, Iter last);

	//’¼üab‚Æ’¼ücd‚ÌŒğ“_‚ÌŒvZ
	template<typename Point>
	constexpr Point CalcIntersection(Point const& a, Point const& b, Point const& c, Point const& d);

	//’¼üax+by+c=0‚Å•ï‚ğ•ªŠ„‚·‚é
	template<typename InputIter,typename OutputIter>
	constexpr void SplitConvex(float a, float b, float c, InputIter first, InputIter last,
		OutputIter result1, OutputIter result2);

	//’¼üax+by+c=0‚Å•ï‚ğ•ªŠ„‚·‚é
	//[first,result)‚Æ[result,last)‚É‚Å•ªŠ„‚³‚ê‚é
	template<typename Iter>
	constexpr Iter SplitConvex(Iter first, Iter last, float a, float b, float c);




	template<typename Point, typename Iter>
	constexpr bool IsInclude(Point const& point, Iter first, Iter last)
	{
		for (auto iter = first; iter != last; iter++)
		{
			auto iter2 = (iter + 1) == last ? first : iter + 1;
			auto vec1 = *iter - *iter2;
			auto vec2 = point - *iter;
			if (vec1.Cross(vec2) > 0)
				return false;
		}

		return true;
	}

	template<typename Point>
	constexpr Point CalcIntersection(Point const& a, Point const& b, Point const& c, Point const& d)
	{
		auto vec1 = a - b;
		auto vec2 = c - d;

		auto t = -vec2.Cross(d - b) / vec1.Cross(vec2);

		return vec1 * t + b;
	}

	template<typename InputIter, typename OutputIter>
	constexpr void SplitConvex(float a, float b, float c, InputIter first, InputIter last,
		OutputIter result1, OutputIter result2)
	{
		using Point = typename std::iterator_traits<InputIter>::value_type;

		Point p1{ 0,-c / b };
		Point p2{ -c / a,0 };

		auto isPointEqual = [](auto const& a, auto const& b)->bool {
			auto p = a - b;
			return std::abs(p.x) <= std::numeric_limits<decltype(p.x)>::epsilon()
				&& std::abs(p.y) <= std::numeric_limits<decltype(p.y)>::epsilon();
		};

		auto addResult = [&isPointEqual](auto& iter, auto const& point)-> void {
			if (!isPointEqual(*iter, point))
				*(iter++) = point;
		};

		auto vec1 = p2 - p1;
		auto vec2 = p2 - *(last - 1);
		bool prevSize = vec1.Cross(vec2) > 0;
		auto iter = first;
		for (std::size_t i = 0; i < std::distance(first, last); i++)
		{
			auto prevIter = (iter == first) ? (last - 1) : iter - 1;

			vec2 = p2 - *iter;
			bool newSide = vec1.Cross(vec2) > 0;

			if (newSide != prevSize)
			{
				auto p = CalcIntersection(p1, p2, *prevIter, *iter);

				addResult(result1, p);
				addResult(result2, p);
			}

			if (newSide)
				addResult(result1, *iter);
			else
				addResult(result2, *iter);

			prevSize = newSide;
			iter = (iter + 1 == last) ? first : iter + 1;
		}
	}

	template<typename Iter>
	constexpr Iter SplitConvex(Iter first, Iter last, float a, float b, float c)
	{
		using Point = typename std::iterator_traits<Iter>::value_type;

		Point p1{ 0,-c / b };
		Point p2{ -c / a,0 };

		auto vec1 = p2 - p1;
		auto vec2 = p2 - *(last - 1);
		bool prevSide = vec1.Cross(vec2) > 0;
		Iter leftSideFirstIter, rightSideFirstIter;
		for (auto iter = first; iter != last; iter++)
		{
			vec2 = p2 - *iter;
			bool newSide = vec1.Cross(vec2) > 0;

			if (newSide != prevSide)
			{
				if (newSide)
					leftSideFirstIter = iter;
				else
					rightSideFirstIter = iter;
			}
			
			prevSide = newSide;
		}

		auto [minIter, maxIter] = std::minmax(leftSideFirstIter, rightSideFirstIter);
		auto num = std::distance(minIter, maxIter);
		std::rotate(first, minIter, last);

		return first + num;
	}
}