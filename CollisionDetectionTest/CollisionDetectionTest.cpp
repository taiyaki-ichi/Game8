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
		TEST_METHOD(CrossLineTest001)
		{
			using namespace g8;

			Vector2D p1{ 0.f,0.f };
			Vector2D p2{ 1.f,0.f };
			Vector2D p3{ 1.f,1.f };
			Vector2D p4{ 0.f,1.f };

			Assert::IsTrue(CrossDetection(p1, p3, p2, p4));
			Assert::IsTrue(CrossDetection(p1, p2, p1, p2));
			Assert::IsFalse(CrossDetection(p1, p2, p3, p4));
			Assert::IsFalse(CrossDetection(p2, p3, p4, p1));
		}
		
		TEST_METHOD(IsHitTest001)
		{
			using namespace g8;

			Rect rect1{ {0.f,0.f},10.f,10.f,1.f,0.f };
			Rect rect2{ {5.f,0.f},10.f,10.f,1.f,0.f };

			Assert::IsTrue(IsHit(rect1, rect2));
		}

		TEST_METHOD(IsHitTest002)
		{
			using namespace g8;

			Rect rect1{ {0.f,0.f},10.f,10.f,1.f,0.f };
			Rect rect2{ {0.f,0.f},10.f,10.f,1.f,0.5f };

			Assert::IsTrue(IsHit(rect1, rect2));
		}

		TEST_METHOD(CollisionDetectionTest001)
		{
			using namespace g8;

			Rect rect1{ {0.f,0.f},10.f,10.f,1.f,0.f };
			Rect rect2{ {5.f,0.f},10.f,10.f,1.f,0.f };

			std::array<Rect,2> rects{ rect1,rect2 };
			std::array<decltype(rects.begin()), 2> rectIters{};

			CollisionDetection(rects.begin(), rects.end(), rectIters.begin());

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

			Rect rect1{ {0.f,0.f},10.f,10.f,1.f,0.f };
			Rect rect2{ {5.f,0.f},10.f,10.f,1.f,0.f };

			RectWrapper rectWrapper1{ rect1,1 };
			RectWrapper rectWrapper2{ rect2,2 };

			std::array<RectWrapper, 2> rectWrappers{ rectWrapper1,rectWrapper2 };
			std::array<decltype(rectWrappers.begin()), 2> rectWrapperIters{};

			CollisionDetection(rectWrappers.begin(), rectWrappers.end(), rectWrapperIters.begin(),
				[](auto const& lhs, auto const& rhs) {return IsHit(lhs.rect, lhs.rect); });

			Assert::IsTrue(
				(&(rectWrappers[0]) == &(*rectWrapperIters[0]) && &(rectWrappers[1]) == &(*rectWrapperIters[1])) ||
				(&(rectWrappers[0]) == &(*rectWrapperIters[1]) && &(rectWrappers[1]) == &(*rectWrapperIters[0]))
			);

		}


	};
}
