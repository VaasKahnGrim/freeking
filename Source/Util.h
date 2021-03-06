#pragma once

#include "Vector.h"
#include "Matrix4x4.h"
#include <vector>

namespace Freeking
{
	struct Util
	{
		static std::vector<char> LoadFile(const std::string& filepath);
		static std::shared_ptr<class Texture2D> LoadTexture(const std::string& path);
		static std::shared_ptr<class ShaderProgram> LoadShader(const std::string& vertPath, const std::string& fragPath);
		static std::shared_ptr<class Font> LoadFont(const std::string& path);
		static Vector2f ScreenSpaceToPixelPosition(const Vector2f& point, const Vector4i& viewport);
		static bool WorldPointToNormalisedScreenPoint(const Vector3f& position, Vector2f& result, const Matrix4x4& projectionMatrix, const Matrix4x4& viewMatrix, float maxDistance, float& distance);
	};
}
