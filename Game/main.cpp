#include<iostream>
#include"Vector2D.hpp"
#include"Model/Helper.hpp"

int main()
{
	g8::Vector2D pos{ 1.f,1.f };

	float a = 1.f;
	float b = 0.f;
	float c = 1.f;

	pos = g8::Frip(pos, a, b, c);

	std::cout << pos.x << " , " << pos.y << std::endl;
}