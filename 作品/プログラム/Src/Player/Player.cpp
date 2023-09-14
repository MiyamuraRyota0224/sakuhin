#include "Player.h"
#include "../Input/Input.h"
#include "../Common/MyMath.h"
#include "../Common/Common.h"
#include "../Camera/CameraManager.h"
#include "../Collision/CollisionManager.h"
#include "../Cristal/CristalManager.h"
#include "../Treasure//TreasureManager.h"
#include "../Scene/SceneManager.h"
#include "../Scene/SceneParameter.h"
#include <math.h>

namespace {
	// 初期位置
	constexpr VECTOR FIRST_POS = { 10.0f, 0.0f, -20.0f };
	// 移動の速さ
	constexpr float PLAYER_SPEED = 0.3f;
	// 速度上昇率
	constexpr float UP_SPEED = 1.5f;
	// 速度低下率
	constexpr float DOWN_SPD = 0.5f;
	// 回転速度
	constexpr float ROT_SPEED = 0.025f;
	// プレイヤーの大きさ
	constexpr float SIZE_X = 1.0f;
	constexpr float SIZE_Y = 1.5f;
	constexpr float SIZE_Z = 1.0f;
	constexpr float COLLISION_RADIUS = 1.0f;
}

CPlayer::CPlayer() : CObject()
{
	hasObject_ = false;
	canCarry_ = false;
	canToutch_ = false;
	isTouch_ = false;
	isOnGimmik_ = false;
	collision_box = nullptr;
	collision_sphere = nullptr;
	move_ = { 0.0f };
	old_pos_ = { 0.0f };
	restart_pos_ = { 0.0f };
	dir_ = { 0.0f };
	state_ = STATE_DEFAULT;
}

CPlayer::~CPlayer()
{

}

void CPlayer::Init()
{
	active_ = true;
	pos_ = FIRST_POS;
	old_pos_ = pos_;
	restart_pos_ = FIRST_POS;
	SetTag(OBJECT_TAG_PLAYER);
	
	// コリジョン設定
	// box
	collision_box = static_cast<BoxCollision*>(CollisionManager::GetInstance()->CreateCollision(COLLISION_SHAPE_BOX, COLLISION_CATEGORY_PLAYER));
	collision_box->SetOwner(this);
	collision_box->SetSize(VGet(SIZE_X, SIZE_Y, SIZE_Z));

	// sphere
	collision_sphere = static_cast<SphereCollision*>(CollisionManager::GetInstance()->CreateCollision(COLLISION_SHAPE_SPHERE, COLLISION_CATEGORY_PLAYER));
	collision_sphere->SetOwner(this);
	collision_sphere->SetRadius(COLLISION_RADIUS);

}

void CPlayer::Load()
{
	
}

void CPlayer::Step()
{
	switch (state_)
	{
	case STATE_DEFAULT:
		Defaultexec();
		break;
	case STATE_WALK:
		Walkexec();
		break;
	case STATE_CARRY:
		Carryexec();
		break;
	case STATE_TOUTCH:
		Toutchexec();
		break;
	}
}

void CPlayer::Update()
{
	MV1SetPosition(handle_, pos_);
	MV1SetRotationXYZ(handle_, rot_);
}

void CPlayer::Draw()
{
	MV1DrawModel(handle_);

	if (canCarry_ == true)
	{
		DrawFormatString(0, 0, GetColor(255, 0, 0), "持つ");
	}

	if (canToutch_ == true)
	{
		DrawFormatString(0, 0, GetColor(0, 255, 255), "触れる");
	}

}

void CPlayer::Delete()
{
	if (handle_ != -1) {
		MV1DeleteModel(handle_);
		handle_ = -1;
	}

	if (collision_box) {
		collision_box->SetState(COLLISION_STATE_NONE);
	}

	if (collision_sphere) {
		collision_sphere->SetState(COLLISION_STATE_NONE);
	}
}

void CPlayer::Fin()
{
	Delete();
}

void CPlayer::Reset()
{
	// プレイヤーの座標を初期座標に戻す
	pos_ = FIRST_POS;
}

void CPlayer::OnCollisionEnter(CObject* another)
{
	// 壁に当たった時
	if (another->ObjectHasTag(OBJECT_TAG_WALL))
	{
		pos_ = old_pos_;
	}

	// 物体の近くに来た時
	// 持ち上げる動作が可能に
	if(another->ObjectHasTag(OBJECT_TAG_TREASURE))
	{
		canCarry_ = true;
	}
	
	// クリスタルの近くに来た時
	// 触れる動作が可能に
	if (another->ObjectHasTag(OBJECT_TAG_CRISTAL))
	{
		canToutch_ = true;
	}
	
	// ゴール床に乗ったら
	if (another->ObjectHasTag(OBJECT_TAG_GOAL) && hasObject_ == true)
	{
		SceneManager::GetInstance()->ChangeScene(SCENE_ID_CLEAR);
	}
}

void CPlayer::Move()
{
	old_pos_ = pos_;

	move_ = { 0.0f };

	//プレイヤーの向き
	if (CInput::IsCont(KEY_LEFT))
	{
		rot_.y -= ROT_SPEED;
		if (rot_.y < 0.0f) rot_.y += 2.0f * DX_PI_F;
	}

	if (CInput::IsCont(KEY_RIGHT))
	{
		rot_.y += ROT_SPEED;
		if (rot_.y > 2.0f * DX_PI_F) rot_.y -= 2.0f * DX_PI_F;
	}

	// 移動処理
	if (CInput::IsCont(KEY_W))
	{
		dir_.x = sinf(rot_.y);
		dir_.z = cosf(rot_.y);
		move_.x += dir_.x * PLAYER_SPEED;
		move_.z += dir_.z * PLAYER_SPEED;
	}

	if (CInput::IsCont(KEY_S))
	{
		dir_.x = sinf(rot_.y);
		dir_.z = cosf(rot_.y);
		move_.x += dir_.x * (-PLAYER_SPEED);
		move_.z += dir_.z * (-PLAYER_SPEED);
	}

	if (CInput::IsCont(KEY_A))
	{
		dir_.x = sinf(rot_.y + (0.5f * DX_PI_F));
		dir_.z = cosf(rot_.y + (0.5f * DX_PI_F));
		move_.x += dir_.x * (-PLAYER_SPEED);
		move_.z += dir_.z * (-PLAYER_SPEED);
	}

	if (CInput::IsCont(KEY_D))
	{
		dir_.x = sinf(rot_.y + (0.5f * DX_PI_F));
		dir_.z = cosf(rot_.y + (0.5f * DX_PI_F));

		move_.x += dir_.x * (PLAYER_SPEED);
		move_.z += dir_.z * (PLAYER_SPEED);
	}

	// 物を持っているとき
	// 移動速度低下
	if (hasObject_ == true)
	{
		move_.x *= DOWN_SPD;
		move_.z *= DOWN_SPD;
	}
	// 持っていないとき
	else
	{
		// ダッシュ
		if(CInput::IsCont(KEY_LSHIFT))
		{
			move_.x *= UP_SPEED;
			move_.z *= UP_SPEED;
		}
	}

	pos_ = MyMath::VecAdd(pos_, move_);
	
}

void CPlayer::Action()
{
	// 物体の持ち離し
	if (canCarry_ == true)
	{
		if (CInput::IsPush(KEY_F))
		{
			state_ = STATE_CARRY;
		}
	}

	// クリスタルに触れる
	// 物を持っていないときのみ
	if (canToutch_ == true)
	{
		if (CInput::IsPush(KEY_E))
		{
			state_ = STATE_TOUTCH;
		}
	}
}

void CPlayer::Defaultexec()
{
	Move();

	if (move_.x != 0 || move_.z != 0)
	{
		state_ = STATE_WALK;
	}

	Action();

	
}

void CPlayer::Walkexec()
{
	Move();

	if (move_.x == 0 && move_.z == 0)
	{
		state_ = STATE_DEFAULT;
	}

	Action();

	
}

void CPlayer::Carryexec()
{
	// 持っているとき
	if (hasObject_ == true)
	{
		// 地面に置く
		hasObject_ = false;
		TreasureManager::GetInstance()->GetTreasure()->SetIsHeld(hasObject_);
	}
	// 持っていないとき
	else
	{
		// 持つ
		hasObject_ = true;
		TreasureManager::GetInstance()->GetTreasure()->SetIsHeld(hasObject_);
	}

	
	state_ = STATE_DEFAULT;
	
}

void CPlayer::Toutchexec()
{
	isTouch_ = true;
	CristalManager::GetInstance()->GetCristal()->SetIsCheck(true);

	state_ = STATE_DEFAULT;
	
	
}