#pragma once

#include "Math.h"
#include <cmath>
#include <ostream>
#include <sstream>

namespace Freeking
{
	template<typename T>
	class Vector2
	{

	public:

		Vector2() :
			x(0),
			y(0)
		{

		}

		Vector2(T v) :
			x(v),
			y(v)
		{

		}

		Vector2(T x, T y) :
			x(x),
			y(y)
		{

		}

		Vector2(const Vector2<int>& v) :
			x((T)v.x),
			y((T)v.y)
		{

		}

		Vector2(const Vector2<float>& v) :
			x((T)v.x),
			y((T)v.y)
		{

		}

		Vector2(const Vector2<double>& v) :
			x((T)v.x),
			y((T)v.y)
		{

		}

		Vector2<T> operator-(const Vector2<T>& v) const
		{
			return Vector2<T>(x - v.x, y - v.y);
		}

		Vector2<T> operator+(const Vector2<T>& v) const
		{
			return Vector2<T>(x + v.x, y + v.y);
		}

		Vector2<T> operator-() const
		{
			return Vector2<T>(-x, -y);
		}

		const Vector2<T>& operator+=(const Vector2<T>& v)
		{
			x += v.x;
			y += v.y;

			return *this;
		}

		const Vector2<T>& operator-=(const Vector2<T>& v)
		{
			x -= v.x;
			y -= v.y;

			return *this;
		}

		Vector2<T> operator*(const T v) const
		{
			return Vector2<T>(x * v, y * v);
		}

		Vector2<T> operator/(const T v) const
		{
			return Vector2<T>(x / v, y / v);
		}

		Vector2<T> operator/(const Vector2<T>& v) const
		{
			return Vector2<T>(x / v.x, y / v.y);
		}

		const Vector2<T>& operator*=(const T v)
		{
			x *= v;
			y *= v;

			return *this;
		}

		const Vector2<T>& operator*=(const Vector2<T>& rhs)
		{
			x *= rhs.x;
			y *= rhs.y;

			return *this;
		}

		const Vector2<T> operator*(const Vector2<T>& rhs) const
		{
			Vector2<T> temp(*this);
			return temp *= rhs;
		}

		const Vector2<T>& operator/=(const T v)
		{
			x /= v;
			y /= v;

			return *this;
		}

		bool operator==(const Vector2<T>& v) const
		{
			return (v.x == x) && (v.y == y);
		}

		bool operator!=(const Vector2<T>& v) const
		{
			return !(*this == v);
		}

		Vector2<T> Normalise() const
		{
			float l = Length();

			return Vector2<T>(x / l, y / l);
		}

		float Length() const
		{
			return sqrt(x * x + y * y);
		}

		float Angle() const
		{
			return atan2(y, x);
		}

		Vector2<T> Absolute() const
		{
			return Vector2<T>(x, y);
		}

		float Dot(const Vector2<T>& v) const
		{
			return (x * v.x) + (y * v.y);
		}

		float SquaredLength() const
		{
			return x * x + y * y;
		}

		float SquaredLength(const Vector2<T>& v) const
		{
			return x * v.x + y * v.y;
		}

		Vector2<T> Unit() const
		{
			float l = Length();

			return Vector2<T>(x / l, y / l);
		}

		float LengthBetween(const Vector2<T>& v) const
		{
			return (*this - v).Length();
		}

		const T* Base() const
		{
			return &x;
		}

		T* Base()
		{
			return &x;
		}

		std::string ToString() const
		{
			std::stringstream stream;
			stream << x << " " << y;

			return stream.str();
		}

		T& operator[](int index)
		{
			return *(((T*)this) + index);
		}

		const T& operator[](int index) const
		{
			return *(((const T*)this) + index);
		}

		T x, y;

	};

	template<typename T>
	std::ostream& operator<<(std::ostream& out, const Vector2<T>& v)
	{
		return out << v.ToString();
	}

	template<typename T>
	std::istream& operator>>(std::istream& in, Vector2<T>& v)
	{
		return in >> v.x >> v.y;
	}

	typedef Vector2<float> Vector2f;
	typedef Vector2<int> Vector2i;
	typedef Vector2<double> Vector2d;

	template<typename T>
	class Vector3
	{

	public:

		Vector3() :
			x(0),
			y(0),
			z(0)
		{

		}

		Vector3(T v) :
			x(v),
			y(v),
			z(v)
		{

		}

		Vector3(T x, T y, T z) :
			x(x),
			y(y),
			z(z)
		{

		}

		Vector3(const Vector3<int>& v) :
			x((T)v.x),
			y((T)v.y),
			z((T)v.z)
		{

		}

		Vector3(const Vector3<float>& v) :
			x((T)v.x),
			y((T)v.y),
			z((T)v.z)
		{

		}

		Vector3(const Vector3<double>& v) :
			x((T)v.x),
			y((T)v.y),
			z((T)v.z)
		{

		}

		Vector3<T> operator+(const Vector3<T>& v) const
		{
			return Vector3<T>(x + v.x, y + v.y, z + v.z);
		}

		Vector3<T> operator-(const Vector3<T>& v) const
		{
			return Vector3<T>(x - v.x, y - v.y, z - v.z);
		}

		Vector3<T> operator-() const
		{
			return Vector3<T>(-x, -y, -z);
		}

		Vector3<T> operator*(const T v) const
		{
			return Vector3<T>(x * v, y * v, z * v);
		}

		Vector3<T> operator*(const Vector3<T>& v) const
		{
			return Vector3<T>(x * v.x, y * v.y, z * v.z);
		}

		Vector3<T> operator/(const T v) const
		{
			return Vector3<T>(x / v, y / v, z / v);
		}

		Vector3<T> operator/(const Vector3<T>& v) const
		{
			return Vector3<T>(x / v.x, y / v.y, z / v.z);
		}

		Vector3<T> operator%(const Vector3<T>& v) const
		{
			return Vector3<T>(x % v.x, y % v.y, z % v.z);
		}

		const Vector3<T>& operator+=(const Vector3<T>& v)
		{
			x += v.x; y += v.y; z += v.z;

			return *this;
		}

		const Vector3<T>& operator-=(const Vector3<T>& v)
		{
			x -= v.x; y -= v.y; z -= v.z;

			return *this;
		}

		const Vector3<T>& operator*=(const T v)
		{
			x *= v; y *= v; z *= v;

			return *this;
		}

		const Vector3<T>& operator/=(const T v)
		{
			x /= v; y /= v; z /= v;

			return *this;
		}

		const Vector3<T>& operator*=(const Vector3<T>& v)
		{
			x *= v.x; y *= v.y; z *= v.z;

			return *this;
		}

		const Vector3<T>& operator/=(const Vector3<T>& v)
		{
			x /= v.x; y /= v.y; z /= v.z;

			return *this;
		}

		bool operator==(const Vector3<T>& v) const
		{
			return (v.x == x) && (v.y == y) && (v.z == z);
		}

		bool operator!=(const Vector3<T>& v) const
		{
			return !(*this == v);
		}

		bool operator<(const Vector3<T>& v) const
		{
			return (x < v.x) || (y < v.y) || (z < v.z);
		}

		bool operator>(const Vector3<T>& v) const
		{
			return (x > v.x) || (y > v.y) || (z > v.z);
		}

		bool operator<(const T v) const
		{
			return (x < v) || (y < v) || (z < v);
		}

		bool operator>(const T v) const
		{
			return (x > v) || (y > v) || (z > v);
		}

		float operator|(const Vector3<T>& v) const
		{
			return Dot(v);
		}

		Vector3<T> operator^(const Vector3<T>& v) const
		{
			return Cross(v);
		}

		const Vector3<T>& Mul(const Vector3<T>& v)
		{
			*this *= v;

			return *this;
		}

		const Vector3<T>& Div(const Vector3<T>& v)
		{
			*this /= v;

			return *this;
		}

		const Vector3<T>& DivSingle(T v)
		{
			*this /= v;

			return *this;
		}

		const Vector3<T>& MulSingle(T v)
		{
			*this *= v;

			return *this;
		}

		float Length() const
		{
			return sqrt(SquaredLength());
		}

		float SquaredLength() const
		{
			return (float)(x * x + y * y + z * z);
		}

		float Dot(const Vector3<T>& v) const
		{
			return (x * v.x) + (y * v.y) + (z * v.z);
		}

		Vector3<T> Normalise() const
		{
			float l = Length();

			return Vector3<T>(x / l, y / l, z / l);
		}

		Vector3<T> Floor() const
		{
			return Vector3<T>(floor(x), floor(y), floor(z));
		}

		Vector3<T> Absolute() const
		{
			return Vector3<T>(x, y, z);
		}

		Vector3<T> Cross(const Vector3<T>& v) const
		{
			return Vector3<T>(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
		}

		Vector2<T> XY() const
		{
			return Vector2<T>(x, y);
		}

		Vector2<T> XZ() const
		{
			return Vector2<T>(x, z);
		}

		float AngleBetween(const Vector3<T>& v) const
		{
			float cosAngle = Dot(v);

			if (cosAngle >= 1.0f)
			{
				return 0.0f;
			}
			else if (cosAngle <= -1.0f)
			{
				return Math::PI;
			}
			else
			{
				return acos(cosAngle);
			}
		}

		float LengthBetween(const Vector3<T>& v) const
		{
			return (*this - v).Length();
		}

		Vector3<T> Unit() const
		{
			float l = Length();

			return Vector3<T>(x / l, y / l, z / l);
		}

		Vector3<T> ToRadians() const
		{
			return Vector3<T>(Math::DegreesToRadians(x),
				Math::DegreesToRadians(y),
				Math::DegreesToRadians(z));
		}

		Vector3<T> ToDegrees() const
		{
			return Vector3<T>(Math::RadiansToDegrees(x),
				Math::RadiansToDegrees(y),
				Math::RadiansToDegrees(z));
		}

		std::string ToString() const
		{
			std::stringstream stream;
			stream << x << " " << y << " " << z;

			return stream.str();
		}

		const T* Base() const
		{
			return &x;
		}

		T* Base()
		{
			return &x;
		}

		T& operator[](int index)
		{
			return *(((T*)this) + index);
		}

		const T& operator[](int index) const
		{
			return *(((const T*)this) + index);
		}

		T x, y, z;

	};

	template<typename T>
	inline const Vector3<T> operator*(T s, const Vector3<T>& v)
	{
		return Vector3<T>(v.x * s, v.y * s, v.z * s);
	}

	template<typename T>
	inline const Vector3<T> operator/(T s, const Vector3<T>& v)
	{
		return Vector3<T>(s / v.x, s / v.y, s / v.z);
	}

	template<typename T>
	std::ostream& operator<<(std::ostream& out, const Vector3<T>& v)
	{
		return out << v.ToString();
	}

	template<typename T>
	std::istream& operator>>(std::istream& in, Vector3<T>& vec)
	{
		return in >> vec.x >> vec.y >> vec.z;
	}

	typedef Vector3<float> Vector3f;
	typedef Vector3<int> Vector3i;
	typedef Vector3<double> Vector3d;

	template<typename T>
	class Vector4
	{

	public:

		typedef const Vector4<T> CV4;

		Vector4() :
			x(0),
			y(0),
			z(0),
			w(0)
		{

		}

		Vector4(T x, T y, T z, T w) :
			x(x),
			y(y),
			z(z),
			w(w)
		{

		}

		Vector4(T v) :
			x(v),
			y(v),
			z(v),
			w(v)
		{

		}

		Vector4(Vector3<T> xyz, T w) :
			x(xyz.x),
			y(xyz.y),
			z(xyz.z),
			w(w)
		{

		}

		Vector4(const Vector4<int>& v) :
			x((T)v.x),
			y((T)v.y),
			z((T)v.z),
			w((T)v.w)
		{

		}

		Vector4(const Vector4<float>& v) :
			x((T)v.x),
			y((T)v.y),
			z((T)v.z),
			w((T)v.w)
		{

		}

		Vector4(const Vector4<double>& v) :
			x((T)v.x),
			y((T)v.y),
			z((T)v.z),
			w((T)v.w)
		{

		}

		Vector4(const Vector3<int>& v) :
			x((T)v.x),
			y((T)v.y),
			z((T)v.z),
			w(0)
		{

		}

		Vector4(const Vector3<float>& v) :
			x((T)v.x),
			y((T)v.y),
			z((T)v.z),
			w(0)
		{

		}

		Vector4(const Vector3<double>& v) :
			x((T)v.x),
			y((T)v.y),
			z((T)v.z),
			w(0)
		{

		}

		Vector4<T> operator*(const T v) const
		{
			return Vector4<T>(x * v, y * v, z * v, w * v);
		}

		const Vector4<T>& operator*=(T rhs)
		{
			x *= rhs;
			y *= rhs;
			z *= rhs;
			w *= rhs;

			return *this;
		}

		Vector3<T> xyz() const
		{
			return Vector3<T>(x, y, z);
		}

		float Dot(const Vector4<T>& v) const
		{
			return x * v.x + y * v.y + z * v.z + w * v.w;
		}

		T& operator[](int index)
		{
			return *(((T*)this) + index);
		}

		const T& operator[](int index) const
		{
			return *(((const T*)this) + index);
		}

		const T* Base() const
		{
			return &x;
		}

		T* Base()
		{
			return &x;
		}

		Vector4<T> Normalise() const
		{
			float l = Length();

			return Vector4<T>(x / l, y / l, z / l, w / l);
		}

		float Length() const
		{
			return sqrt(x * x + y * y + z * z + w * w);
		}

		std::string ToString() const
		{
			std::stringstream stream;
			stream << x << " " << y << " " << z << " " << w;

			return stream.str();
		}

		T x, y, z, w;

	};

	template<typename T>
	std::ostream& operator<<(std::ostream& out, const Vector4<T>& v)
	{
		return out << v.ToString();
	}

	template<typename T>
	std::istream& operator>>(std::istream& in, Vector4<T>& v)
	{
		return in >> v.x >> v.y >> v.z >> v.w;
	}

	typedef Vector4<float> Vector4f;
	typedef Vector4<int> Vector4i;
	typedef Vector4<double> Vector4d;
}
