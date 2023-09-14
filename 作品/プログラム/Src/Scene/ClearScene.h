#pragma once

#include "Scene.h"
#include "../UI/GameUI.h"

class Clear : public Scene {
public:
	Clear();
	virtual ~Clear();
public:
	void Init() override;
	void Load() override;
	void OnLoadEnd() override;
	void Step() override;
	void Update() override;
	void Draw() override;
	void Fin() override;

private:
	GameUI* ui_logo_;
	GameUI* ui_press_;
};
