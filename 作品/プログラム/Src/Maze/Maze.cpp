#include "Maze.h"
#include "MazeParameter.h"
#include "../Collision/CollisionManager.h"

CMaze::CMaze() : CObject()
{
	collision_ = nullptr;
}

CMaze::~CMaze()
{

}

void CMaze::Init()
{
	active_ = true;
}

void CMaze::Load()
{
	handle_ = MV1LoadModel("Data/Model/Map/wall.x");
}

void CMaze::Step()
{

}

void CMaze::Update()
{
	MV1SetPosition(handle_, pos_);
}

void CMaze::Draw()
{
	MV1DrawModel(handle_);
}

void CMaze::Delete()
{
	
}

void CMaze::Fin()
{
	Delete();
}

CMaze* CMaze::Clone()
{
	CMaze* clone = new CMaze;
	*clone = *this;

	// モデル複製
	clone->handle_ = MV1DuplicateModel(handle_);

	clone->active_ = true;
	clone->SetTag(OBJECT_TAG_WALL);

	// コリジョンのカテゴリ
	clone->collision_ = static_cast<BoxCollision*>(CollisionManager::GetInstance()->CreateCollision(COLLISION_SHAPE_BOX, COLLISION_CATEGORY_WALL));
	clone->collision_->SetOwner(clone);
	// コリジョンの大きさ
	clone->collision_->SetSize(SIZE_WIDTH, SIZE_HEIGHT, SIZE_DEPS);
	clone->collision_->SetState(COLLISION_STATE_ACTIVE);
	MV1SetScale(handle_, VGet(1.0f, 2.0f, 1.0f));

	return clone;
}