#include "Goal.h"
#include "MazeParameter.h"
#include "../Collision/CollisionManager.h"

namespace {
	constexpr float WALL_WIDTH = 5.0f;
	constexpr float WALL_HEIGHT = 5.0f;
	constexpr float WALL_DEPS = 5.0f;
	constexpr float SIZE_X = 1.0f;
	constexpr float SIZE_Y = 1.0f;
	constexpr float SIZE_Z = 1.0f;
}

CGoal::CGoal() : CObject()
{
	collision_ = nullptr;
}

CGoal::~CGoal() 
{

}

void CGoal::Init()
{
	active_ = true;
}

void CGoal::Load()
{
	handle_ = MV1LoadModel("Data/Model/Map/goal.x");
}

void CGoal::Step()
{
	
}

void CGoal::Update()
{
	MV1SetPosition(handle_, pos_);
}

void CGoal::Draw()
{
	MV1DrawModel(handle_);
}

void CGoal::Delete()
{

}

void CGoal::Fin()
{

}

CGoal* CGoal::Clone()
{
	CGoal* clone = new CGoal;
	*clone = *this;

	// モデル複製
	clone->handle_ = MV1DuplicateModel(handle_);

	clone->active_ = true;
	clone->SetTag(OBJECT_TAG_GOAL);

	// コリジョンのカテゴリ
	clone->collision_ = static_cast<BoxCollision*>(CollisionManager::GetInstance()->CreateCollision(COLLISION_SHAPE_BOX, COLLISION_CATEGORY_WALL));
	clone->collision_->SetOwner(clone);
	// コリジョンの大きさ
	clone->collision_->SetSize(SIZE_WIDTH, SIZE_HEIGHT, SIZE_DEPS);
	clone->collision_->SetState(COLLISION_STATE_ACTIVE);
	MV1SetScale(handle_, VGet(1.0f, 1.0f, 1.0f));

	return clone;
}