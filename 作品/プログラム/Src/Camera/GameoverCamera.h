#pragma once
// �Q�[���I�[�o�[�V�[���Ŏg�p����J����
#include "CameraBase.h"

class GameoverCamera : public CameraBase {
public:
	GameoverCamera();
	~GameoverCamera();

public:
	void Init() override;
	void Step() override;
	void Draw() override;
	void Fin() override;
};
