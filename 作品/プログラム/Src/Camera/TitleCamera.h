#pragma once
// �^�C�g���V�[���Ŏg�p����J����
#include "CameraBase.h"

class TitleCamera : public CameraBase {
public:
	TitleCamera();
	~TitleCamera();

public:
	void Init() override;
	void Step() override;
	void Draw() override;
	void Fin() override;
};
