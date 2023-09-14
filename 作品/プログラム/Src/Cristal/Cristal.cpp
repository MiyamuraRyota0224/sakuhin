#include "cristal.h"
#include "../Collision/CollisionManager.h"
#include "../Time/TimeManager.h"

namespace {
	// âÒì]ë¨ìx
	constexpr float ROTATION_SPD = 0.05f;
	constexpr float SIZE_WIDTH = 1.5f;
	constexpr float SIZE_HEIGHT = 2.0f;
	constexpr float SIZE_DEPS = 1.5f;
	constexpr float COLLISION_RADIUS = 4.0f;
	constexpr VECTOR POS = { 15.0f, 2.0f, -10.0f };
}

CCristal::CCristal()
{
	SetTag(OBJECT_TAG_CRISTAL);
	isCheck_ = false;
	collision_ = nullptr;
}

CCristal::~CCristal()
{
	
}

void CCristal::Init()
{
	pos_ = POS;

	// ÉRÉäÉWÉáÉìê›íË
	collision_ = static_cast<SphereCollision*>(CollisionManager::GetInstance()->CreateCollision(COLLISION_SHAPE_SPHERE, COLLISION_CATEGORY_CRISTAL));
	collision_->SetOwner(this);
	collision_->SetRadius(COLLISION_RADIUS);
}

void CCristal::Load()
{
	handle_ = MV1LoadModel("Data/Model/Map/cristal.x");
}

void CCristal::Step()
{
	rot_.y += ROTATION_SPD;
}

void CCristal::Update()
{
	MV1SetPosition(handle_, pos_);
	MV1SetRotationXYZ(handle_, rot_);
}

void CCristal::Draw()
{
	MV1DrawModel(handle_);
}

void CCristal::Delete()
{
	if (handle_ != -1) {
		MV1DeleteModel(handle_);
		handle_ = -1;
	}

	if (collision_) {
		collision_->SetState(COLLISION_STATE_NONE);
	}
}

void CCristal::Fin()
{
	Delete();
}

void CCristal::OnCollisionEnter(CObject* another)
{

}

void CCristal::Reset()
{
	if (isCheck_ == true)
	{
		TimeManager::GetInstance()->Reset();
	}
}