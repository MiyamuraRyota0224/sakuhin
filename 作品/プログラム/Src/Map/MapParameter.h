#pragma once

#include <DxLib.h>

#define MAP_POS VGet(0.0f, -1.0f, 0.0f)
#define MAP_SIZE 700.0f

enum MapID {
	MAP_ID_MONO,
	MAP_ID_NUM
};
struct MapParameter {
	const char DATA_PATH[128];
};

static const MapParameter MAP_DATABASE[MAP_ID_NUM] = {
	"Data/Model/Map/floor.x"
};
