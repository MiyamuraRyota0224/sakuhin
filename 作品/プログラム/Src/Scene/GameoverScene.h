#pragma once

#include "Scene.h"
#include "../UI/GameUI.h"

class Gameover : public Scene {
public:
	Gameover();
	virtual ~Gameover();
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
