#pragma once

#include "CameraBase.h"

class PlayCamera : public CameraBase {
public:
	PlayCamera();
	~PlayCamera();

public:
	void Init() override;
	void Step() override;
	void Draw() override;
	void Fin() override;

private:

};
