#include"Model/Stage.hpp"
#include<iostream>

int main()
{

	g8::Stage stage{};
	stage.width = 200.f;
	stage.height = 200.f;

	stage.kinkLine[0].line = 80;
	stage.kinkLine[0].isX = true;
	stage.kinkLine[0].dir = false;

	stage.kinkLine[1].line = 80;
	stage.kinkLine[1].isX = false;
	stage.kinkLine[1].dir = false;

	stage.activeKinkLineIndexs[0] = 0;
	stage.activeKinkLineIndexs[1] = 1;

	stage.kinkLineNum = 0;

	g8::StagePosition pos{};
	pos.dimension = true;

	g8::Rect rect{ pos.position,20,20,1.f };

	while (true)
	{
		std::cout << (pos.dimension ? "omote" : "ura") << std::endl;
		std::cout << "pos x : " << pos.position.x << std::endl;
		std::cout << "pos y : " << pos.position.y << std::endl;
		std::cout << std::endl;

		rect.position = pos.position;
		auto rects = stage.GetSplitRect(rect, pos.dimension);

		for (auto& r : rects)
		{
			std::cout << "pos x : " << r.position.x << std::endl;
			std::cout << "pos y : " << r.position.y << std::endl;
			std::cout << "width: " << r.width << std::endl;
			std::cout << "height: " << r.height << std::endl;
			std::cout << std::endl;
		}

		std::cout << std::endl;
		std::cout << std::endl;
		float x, y;
		std::cin >> x >> y;

		pos = stage.Move(pos, { x,y });
	}


}