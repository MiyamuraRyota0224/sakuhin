#pragma once
// �N���A�V�[���Ŏg�p����J����
#include "CameraBase.h"

class ClearCamera : public CameraBase {
public:
	ClearCamera();
	~ClearCamera();

public:
	void Init() override;
	void Step() override;
	void Draw() override;
	void Fin() override;
};
