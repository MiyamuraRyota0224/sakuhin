#include "Map.h"
#include "MapParameter.h"

Map::Map(int id)
{
	id_ = id;
	handle_ = -1;
}

Map::~Map()
{
	Fin();
}

void Map::Init()
{
}

void Map::Load()
{
	handle_ = MV1LoadModel(MAP_DATABASE[id_].DATA_PATH);
}

void Map::Step()
{
}

void Map::Update()
{
	MV1SetPosition(handle_, MAP_POS);
}

void Map::Draw()
{
	MV1DrawModel(handle_);
}

void Map::Delete()
{
	MV1DeleteModel(handle_);
}

void Map::Fin()
{
	Delete();
}
