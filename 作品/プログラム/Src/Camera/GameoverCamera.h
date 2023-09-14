#pragma once
// ゲームオーバーシーンで使用するカメラ
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
