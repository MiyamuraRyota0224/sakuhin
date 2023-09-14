#include "CollisionManager.h"
#include "SphereCollision.h"
#include "BoxCollision.h"
#include "../Common/MyMath.h"
#include "../Common/Common.h"
#include "../Player/PlayerManager.h"

CollisionManager* CollisionManager::instance_ = nullptr;

CollisionManager::CollisionManager()
{
	optimize_interval_ = 0.0f;
	optimize_timer_ = 0.0f;
}

CollisionManager::~CollisionManager()
{
	Fin();
}

void CollisionManager::Init()
{
}

void CollisionManager::Step()
{
	for (int i = 0; i < COLLISION_CATEGORY_NUM; i++) {
		for (auto collision : collisions_[i]) {
			collision->Step();
		}
	}

	optimize_timer_ += Common::GetGameDeltaFrame();
}

void CollisionManager::Update()
{
	for (int i = 0; i < COLLISION_CATEGORY_NUM; i++) {
		for (auto collision : collisions_[i]) {
			collision->Update();
		}
	}
}

void CollisionManager::Draw()
{
	for (int i = 0; i < COLLISION_CATEGORY_NUM; i++) {
		for (auto collision : collisions_[i]) {
				collision->Draw();
		}
	}
}

void CollisionManager::Delete()
{
	for (int i = 0; i < COLLISION_CATEGORY_NUM; i++) {
		for (auto collision : collisions_[i]) {
			delete collision;
		}
		collisions_[i].clear();
	}
}

void CollisionManager::Fin()
{
	Delete();
}

// コリジョン生成
Collision* CollisionManager::CreateCollision(int shape, int category)
{
	Collision* collision = nullptr;
	switch (shape) {
		case COLLISION_SHAPE_SPHERE: collision = new SphereCollision; break;
		case COLLISION_SHAPE_BOX: collision = new BoxCollision; break;
	}

	if (collision) {
		collision->SetState(COLLISION_STATE_ACTIVE);
		collisions_[category].push_back(collision);
	}
	return collision;
}

// コリジョンチェック
void CollisionManager::CheckCollision()
{
	CheckPlayerAndWall();			// プレイヤーと壁の当たり判定
	CheckPlayerAndTreasure();		// プレイヤーとトレジャーの当たり判定
}

void CollisionManager::CheckPlayerAndWall()
{
	auto player_collisions = collisions_[COLLISION_CATEGORY_PLAYER];
	auto wall_collisions = collisions_[COLLISION_CATEGORY_WALL];
	for (auto wall_collision : wall_collisions) {
		if (!wall_collision->IsCheck()) continue;
		for (auto player_collision : player_collisions) {
			if (!player_collision->IsCheck()) continue;
			if (wall_collision->CheckCollision(player_collision)) {
				wall_collision->GetOwner()->OnCollisionEnter(player_collision->GetOwner());
				player_collision->GetOwner()->OnCollisionEnter(wall_collision->GetOwner());
			}
		}
	}
}

void CollisionManager::CheckPlayerAndTreasure()
{
	auto player_collisions = collisions_[COLLISION_CATEGORY_PLAYER];
	auto treasure_collisions = collisions_[COLLISION_CATEGORY_TREASURE];
	for (auto treasure_collision : treasure_collisions) {
		if (!treasure_collision->IsCheck()) continue;
		for (auto player_collision : player_collisions) {
			if (!player_collision->IsCheck()) continue;
			if (treasure_collision->CheckCollision(player_collision)) {
				treasure_collision->GetOwner()->OnCollisionEnter(player_collision->GetOwner());
				player_collision->GetOwner()->OnCollisionEnter(treasure_collision->GetOwner());
			}
		}
	}
}

void CollisionManager::CheckTreasureAndGimmikFloor()
{

}