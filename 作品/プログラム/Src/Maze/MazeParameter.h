#pragma once

enum MAZE_ID {
	ID_WALL,
	ID_GOAL,
	ID_MAX,
	ID_END = -1
};

namespace {
	// â°ïù
	constexpr int MAX_X = 23;
	// ècïù
	constexpr int MAX_Z = 23;
	// ÇPÉ}ÉXÇÃëÂÇ´Ç≥
	constexpr float SIZE_WIDTH = 10.0f;
	constexpr float SIZE_HEIGHT = 20.0f;
	constexpr float SIZE_DEPS = 10.0f;
}