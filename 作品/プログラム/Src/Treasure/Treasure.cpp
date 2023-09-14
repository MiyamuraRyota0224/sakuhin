#include "Treasure.h"
#include "../Collision/CollisionManager.h"
#include "../Player/PlayerManager.h"

namespace {
	constexpr float COLLISION_RADIUS = 1.0f;
	constexpr float SIZE_RADIUS = 0.5f;
	constexpr float HAS_HEIGHT = 0.8f;
	constexpr VECTOR FIRST_POS = { 13.0f, 0.5f, -15.0f };
}

CTreasure::CTreasure()
{
	SetTag(OBJECT_TAG_TREASURE);
	rad_ = 0.0f;
	restart_pos_ = { 0.0f };
	isHeld_ = false;
	isOnGimmik_ = false;
	collision_ = nullptr;
}

CTreasure::~CTreasure()
{

}

void CTreasure::Init()
{
	pos_ = FIRST_POS;
	restart_pos_ = FIRST_POS;
	rad_ = SIZE_RADIUS;

	// コリジョン設定
	collision_ = static_cast<SphereCollision*>(CollisionManager::GetInstance()->CreateCollision(COLLISION_SHAPE_SPHERE, COLLISION_CATEGORY_TREASURE));
	collision_->SetOwner(this);
	collision_->SetRadius(COLLISION_RADIUS);
}

void CTreasure::Load()
{
	handle_ = MV1LoadModel("Data/Model/Object/Treasure.x");
}

void CTreasure::Step()
{
	// 持たれているなら
	if (isHeld_ == true)
	{
		// プレイヤーの前に移動する
		CPlayer* player = PlayerManager::GetInstance()->GetPlayer();
		VECTOR player_pos = player->GetPos();
		VECTOR player_rot = player->GetRot();

		pos_.x = player_pos.x + rad_ * sinf(player_rot.y);
		pos_.z = player_pos.z + rad_ * cosf(player_rot.y);
		pos_.y = HAS_HEIGHT;
	}
	// 持たれていないなら
	else
	{
		// 地面に置かれる
		pos_.y = SIZE_RADIUS;
	}
}

void CTreasure::Update()
{
	MV1SetPosition(handle_, pos_);
	MV1SetRotationXYZ(handle_, rot_);
}

void CTreasure::Draw()
{
	MV1DrawModel(handle_);
}

void CTreasure::Delete()
{
	if (handle_ != -1) {
		MV1DeleteModel(handle_);
		handle_ = -1;
	}

	if (collision_) {
		collision_->SetState(COLLISION_STATE_NONE);
	}
}

void CTreasure::Fin()
{
	Delete();
}

void CTreasure::OnCollisionEnter(CObject* another)
{
	// ギミック床に置かれているなら
	if (another->ObjectHasTag(OBJECT_TAG_GIMMIK_FLOOR))
	{
		isOnGimmik_ = true;
		restart_pos_ = pos_;
	}
	else
	{
		isOnGimmik_ = false;
	}
}

void CTreasure::Reset()
{
	if (isOnGimmik_ == false)
	{
		// リスタートの位置に戻る
		pos_ = restart_pos_;
	}
}

void CTreasure::SetIsHeld(bool isHeld)
{
	isHeld_ = isHeld;
}