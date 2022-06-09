#pragma once
#include<cmath>

namespace g8math
{
	class Vector2D
	{
	public:
		float x = 0.f;
		float y = 0.f;

		constexpr Vector2D() {};
		constexpr Vector2D(float inX, float inY) :x{ inX }, y{ inY }{};


		constexpr Vector2D operator+(Vector2D const& rhs) const noexcept {
			return { x + rhs.x, y + rhs.y };
		}

		constexpr Vector2D operator-(Vector2D const& rhs) const noexcept {
			return { x - rhs.x,y - rhs.y };
		}

		constexpr Vector2D operator*(Vector2D const& rhs) const noexcept {
			return { x * rhs.x,y * rhs.y };
		}

		constexpr Vector2D operator/(Vector2D const& rhs) const noexcept {
			return{ x / rhs.x, y / rhs.y };
		}


		constexpr Vector2D& operator+=(Vector2D const& rhs) noexcept {
			x += rhs.x;
			y += rhs.y;
			return *this;
		}

		constexpr Vector2D& operator-=(Vector2D const& rhs) noexcept {
			x -= rhs.x;
			y -= rhs.y;
			return *this;
		}

		constexpr Vector2D& operator*=(Vector2D const& rhs) noexcept {
			x *= rhs.x;
			y *= rhs.y;
			return *this;
		}

		constexpr Vector2D& operator/=(Vector2D const& rhs) noexcept {
			x /= rhs.x;
			y /= rhs.y;
			return *this;
		}

		constexpr friend Vector2D operator+(Vector2D const& lhs, float rhs) noexcept {
			return { lhs.x + rhs,lhs.y + rhs };
		}

		constexpr friend Vector2D operator+(float lhs, Vector2D const& rhs) noexcept {
			return { lhs + rhs.x,lhs + rhs.y };
		}

		constexpr friend Vector2D operator-(Vector2D const& lhs, float rhs) noexcept {
			return { lhs.x - rhs,lhs.y - rhs };
		}

		constexpr friend Vector2D operator-(float lhs, Vector2D const& rhs) noexcept {
			return { lhs - rhs.x,lhs - rhs.y };
		}

		constexpr friend Vector2D operator*(Vector2D const& lhs, float rhs) noexcept {
			return { lhs.x * rhs,lhs.y * rhs };
		}

		constexpr friend Vector2D operator*(float lhs, Vector2D const& rhs) noexcept {
			return { lhs * rhs.x,lhs * rhs.y };
		}

		constexpr friend Vector2D operator/(Vector2D const& lhs, float rhs) noexcept {
			return { lhs.x / rhs,lhs.y / rhs };
		}

		constexpr friend Vector2D operator/(float lhs, Vector2D const& rhs) noexcept {
			return { lhs / rhs.x,lhs / rhs.y };
		}


		constexpr float LengthSq() const noexcept {
			return x * x + y * y;
		}

		float Length() const noexcept{
			return std::sqrtf(LengthSq());
		}

		constexpr Vector2D Normalize() const noexcept {
			return *this / Length();
		}

		Vector2D& NormalizeSelf() noexcept {
			float l = Length();
			x /= l;
			y /= l;
			return *this;
		}

		constexpr float Dot(Vector2D const& rhs) const noexcept {
			return x * rhs.x + y * rhs.y;
		}

		constexpr float Cross(Vector2D const& rhs) const noexcept {
			return x * rhs.y - y * rhs.x;
		}

		Vector2D Rotation(float rot) const noexcept {
			float x = x * std::cos(rot) - y * std::sin(rot);
			float y = x * std::sin(rot) + y * std::cos(rot);
			return { x,y };
		}

		Vector2D& RotationSelf(float rot) noexcept {
			float x = x * std::cos(rot) - y * std::sin(rot);
			float y = x * std::sin(rot) + y * std::cos(rot);
			this->x = x;
			this->y = y;
			return *this;
		}

	};
}