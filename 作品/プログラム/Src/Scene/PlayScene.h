#pragma once

#include "Scene.h"

class Play : public Scene{
public:
	Play();
	virtual ~Play();
public:
	void Init() override;
	void Load() override;
	void OnLoadEnd() override;
	void Step() override;
	void Update() override;
	void Draw() override;
	void Fin() override;

protected:
	virtual void OnFadeinEnd() override;

private:
	void InitPlayer();
	void InitCristal();
	void InitTreasure();
	void InitStage();
	void InitMaze();
	void InitTime();
	void InitCamera();
	void InitEffect();
	void InitCollision();
	void InitUI();

	void LoadPlayer();
	void LoadCristal();
	void LoadTreasure();
	void LoadStage();
	void LoadMaze();
	void LoadEffect();
	void LoadSound();
	void LoadUI();

private:

};
