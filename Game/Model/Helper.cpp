#include"Helper.hpp"
#include<DirectXMath.h>

namespace g8
{
	Vector2D Frip(Vector2D const& vec, float a, float b, float c)
	{
		a *= -1.f;

		auto len = std::sqrt(a * a + b * b);
		auto dis = c / len;
		auto moveX = dis * a / len;
		auto moveY = dis * b / len;

		using namespace DirectX;

		XMFLOAT3 result{ vec.x + moveX,vec.y + moveY ,0.f };
		XMFLOAT3 axis{ b,-a,0.f };

		auto resultVector = XMLoadFloat3(&result);
		auto axisVector = XMLoadFloat3(&axis);

		resultVector = XMPlaneTransform(resultVector, XMMatrixRotationAxis(axisVector, XM_PI));
		XMStoreFloat3(&result, resultVector);

		return { -(result.x - moveX),result.y - moveY };
	}
}