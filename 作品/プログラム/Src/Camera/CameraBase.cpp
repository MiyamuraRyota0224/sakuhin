#include "CameraBase.h"


CameraBase::CameraBase()
{
	pos_ = VGet(0.0f, 0.0f, 0.0f);
	look_ = VGet(0.0f, 0.0f, 0.0f);
	up_vec_ = VGet(0.0f, 1.0f, 0.0f);
	rot_ = VGet(0.0f, 0.0f, 0.0f);
	dir_ = VGet(0.0f, 0.0f, 0.0f);
}

CameraBase::~CameraBase()
{
}

void CameraBase::Update()
{
	SetCameraPositionAndTargetAndUpVec(pos_, look_, up_vec_);
}