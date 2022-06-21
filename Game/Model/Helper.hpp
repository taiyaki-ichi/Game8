#pragma once
#include"Vector2D.hpp"
#include<iterator>
#include<numeric>
#include<algorithm>

namespace g8
{
	//vec��ax+by+c=0�ɂ��Ĕ��]������
	Vector2D Frip(Vector2D const& vec, float a, float b, float c);

	//�_�����p�`�̓����ɂ��邩�ǂ���
	template<typename Point,typename Iter>
	constexpr bool IsInclude(Point const& point, Iter first, Iter last);

	//����ab�ƒ���cd�̌�_�̌v�Z
	template<typename Point>
	constexpr Point CalcIntersection(Point const& a, Point const& b, Point const& c, Point const& d);

	//����ax+by+c=0�ŕ�𕪊�����
	//[first,result)��[result,last)�ɂŕ��������
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