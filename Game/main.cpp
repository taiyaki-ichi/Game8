#include<iostream>
#include"Vector2D.hpp"
#include"Model/Helper.hpp"
#include<array>

int main()
{
	std::array<g8::Vector2D, 4> ps{ {
		{0,0},
		{2,0},
		{2,2},
		{0,2}
		} };


	auto result = g8::SplitConvex(ps.begin(), ps.end(), 2, 1, -4);
	for (auto iter = ps.begin(); iter != result; iter++)
		std::cout << iter->x << "," << iter->y << std::endl;
	std::cout << std::endl;
	for (auto iter = result; iter != ps.end(); iter++)
		std::cout << iter->x << "," << iter->y << std::endl;
	std::cout << std::endl;


}

