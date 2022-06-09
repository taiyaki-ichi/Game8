#include "pch.h"
#include "CppUnitTest.h"
#include"Vector2D.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MathTest
{
	

	TEST_CLASS(MathTest)
	{
	public:
		
		TEST_METHOD(TestVector2D001)
		{
			using namespace g8math;

			Vector2D a{ 1.f,2.f };
			Vector2D b{ 3.f,4.f };

			auto result1 = a + b;
			auto result2 = a - b;
			auto result3 = a * b;
			auto result4 = a / b;

			Assert::AreEqual<float>(1.f + 3.f, result1.x);
			Assert::AreEqual<float>(2.f + 4.f, result1.y);
			Assert::AreEqual<float>(1.f - 3.f, result2.x);
			Assert::AreEqual<float>(2.f - 4.f, result2.y);
			Assert::AreEqual<float>(1.f * 3.f, result3.x);
			Assert::AreEqual<float>(2.f * 4.f, result3.y);
			Assert::AreEqual<float>(1.f / 3.f, result4.x);
			Assert::AreEqual<float>(2.f / 4.f, result4.y);
		}

		TEST_METHOD(TestVector2D002)
		{
			using namespace g8math;

			Vector2D a{ 3.f,4.f };

			Vector2D result1{ 1.f,2.f };
			Vector2D result2{ 1.f,2.f };
			Vector2D result3{ 1.f,2.f };
			Vector2D result4{ 1.f,2.f };

			result1 += a;
			result2 -= a;
			result3 *= a;
			result4 /= a;

			Assert::AreEqual<float>(1.f + 3.f, result1.x);
			Assert::AreEqual<float>(2.f + 4.f, result1.y);
			Assert::AreEqual<float>(1.f - 3.f, result2.x);
			Assert::AreEqual<float>(2.f - 4.f, result2.y);
			Assert::AreEqual<float>(1.f * 3.f, result3.x);
			Assert::AreEqual<float>(2.f * 4.f, result3.y);
			Assert::AreEqual<float>(1.f / 3.f, result4.x);
			Assert::AreEqual<float>(2.f / 4.f, result4.y);
		}

		TEST_METHOD(TestVector2D003)
		{
			using namespace g8math;

			Vector2D a{ 1.f,2.f };

			Vector2D result1 = a + 3.f;
			Vector2D result2 = a - 3.f;
			Vector2D result3 = a * 3.f;
			Vector2D result4 = a / 3.f;

			Assert::AreEqual<float>(1.f + 3.f, result1.x);
			Assert::AreEqual<float>(2.f + 3.f, result1.y);
			Assert::AreEqual<float>(1.f - 3.f, result2.x);
			Assert::AreEqual<float>(2.f - 3.f, result2.y);
			Assert::AreEqual<float>(1.f * 3.f, result3.x);
			Assert::AreEqual<float>(2.f * 3.f, result3.y);
			Assert::AreEqual<float>(1.f / 3.f, result4.x);
			Assert::AreEqual<float>(2.f / 3.f, result4.y);


			Vector2D result5 = 3.f + a;
			Vector2D result6 = 3.f - a;
			Vector2D result7 = 3.f * a;
			Vector2D result8 = 3.f / a;

			Assert::AreEqual<float>(3.f + 1.f, result5.x);
			Assert::AreEqual<float>(3.f + 2.f, result5.y);
			Assert::AreEqual<float>(3.f - 1.f, result6.x);
			Assert::AreEqual<float>(3.f - 2.f, result6.y);
			Assert::AreEqual<float>(3.f * 1.f, result7.x);
			Assert::AreEqual<float>(3.f * 2.f, result7.y);
			Assert::AreEqual<float>(3.f / 1.f, result8.x);
			Assert::AreEqual<float>(3.f / 2.f, result8.y);
		}

		TEST_METHOD(TestVector2D004)
		{
			using namespace g8math;

			Vector2D a{ 3.f,4.f };

			Assert::AreEqual<float>(3.f * 3.f + 4.f * 4.f, a.LengthSq());
			Assert::AreEqual<float>(std::sqrtf(3.f * 3.f + 4.f * 4.f), a.Length());
		}


		TEST_METHOD(TestVector2D005)
		{
			using namespace g8math;

			Vector2D a{ 3.f,4.f };
			auto l = a.Length();

			auto result = a.Normalize();
			a.NormalizeSelf();

			Assert::AreEqual<float>(3.f / l, result.x);
			Assert::AreEqual<float>(4.f / l, result.y);
			Assert::AreEqual<float>(3.f / l, a.x);
			Assert::AreEqual<float>(4.f / l, a.y);
		}


	};
}
