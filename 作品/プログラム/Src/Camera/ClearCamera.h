#pragma once
// クリアシーンで使用するカメラ
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
