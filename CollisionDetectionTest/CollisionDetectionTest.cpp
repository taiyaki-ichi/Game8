#include "pch.h"
#include "CppUnitTest.h"
#include"CollisionDetection.hpp"
#include<vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CollisionDetectionTest
{
	TEST_CLASS(CollisionDetectionTest)
	{
	public:
		TEST_METHOD(IsHitTest001)
		{
			using namespace g8;

			Rect rect1{ {0.f,0.f},10.f,10.f,1.f};
			Rect rect2{ {5.f,0.f},10.f,10.f,1.f };

			Assert::IsTrue(IsHit(rect1, rect2));
		}

		TEST_METHOD(IsHitTest002)
		{
			using namespace g8;

			Rect rect1{ {0.f,0.f},10.f,10.f,1.f };
			Rect rect2{ {0.f,0.f},10.f,10.f,1.f };

			Assert::IsTrue(IsHit(rect1, rect2));
		}

		TEST_METHOD(CollisionDetectionTest001)
		{
			using namespace g8;

			Rect rect1{ {0.f,0.f},10.f,10.f,1.f };
			Rect rect2{ {5.f,0.f},10.f,10.f,1.f };

			std::array<Rect,2> rects{ rect1,rect2 };
			std::vector<decltype(rects.begin())> rectIters{};

			CollisionDetection(rects.begin(), rects.end(), [&rectIters](auto iter1, auto iter2) {
				rectIters.push_back(iter1);
				rectIters.push_back(iter2);
				});

			Assert::IsTrue(
				(&(rects[0]) == &(*rectIters[0]) && &(rects[1]) == &(*rectIters[1])) ||
				(&(rects[0]) == &(*rectIters[1]) && &(rects[1]) == &(*rectIters[0]))
			);
		}

		struct RectWrapper
		{
			g8::Rect rect{};
			int id{};
		};

		TEST_METHOD(CollisionDetectionTest002)
		{
			using namespace g8;

			Rect rect1{ {0.f,0.f},10.f,10.f,1.f };
			Rect rect2{ {5.f,0.f},10.f,10.f,1.f };

			RectWrapper rectWrapper1{ rect1,1 };
			RectWrapper rectWrapper2{ rect2,2 };

			std::array<RectWrapper, 2> rectWrappers{ rectWrapper1,rectWrapper2 };
			std::vector<decltype(rectWrappers.begin())> rectWrapperIters{};

			CollisionDetection(rectWrappers.begin(), rectWrappers.end(), [&rectWrapperIters](auto iter1, auto iter2) {
				rectWrapperIters.push_back(iter1);
				rectWrapperIters.push_back(iter2);
				},
				[](auto const& lhs, auto const& rhs) {return IsHit(lhs.rect, lhs.rect); });

			Assert::IsTrue(
				(&(rectWrappers[0]) == &(*rectWrapperIters[0]) && &(rectWrappers[1]) == &(*rectWrapperIters[1])) ||
				(&(rectWrappers[0]) == &(*rectWrapperIters[1]) && &(rectWrappers[1]) == &(*rectWrapperIters[0]))
			);

		}


	};
}
