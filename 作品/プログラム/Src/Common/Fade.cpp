#include "Fade.h"
#include "DxLib.h"

#define PARAM_MAX 255

int Fade::handle_ = 0;
float Fade::param_ = 0;
float Fade::value_ = 0;
Fade::FadeStatus Fade::status_ = FADE_END;

void Fade::Init()
{
	handle_ = LoadGraph("Data/Fade/Fade.png");
}

// フェード更新
void Fade::Step()
{
	if (status_ == FADE_OUT) {
		param_ += value_;
		if (param_ >= PARAM_MAX) {
			param_ = PARAM_MAX;
			status_ = FADE_END;
		}
	}
	else if (status_ == FADE_IN) {
		param_ -= value_;
		if (param_ <= 0) {
			param_ = 0;
			status_ = FADE_END;
		}
	}
}

// フェード描画
void Fade::Draw()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, (int)param_);
	DrawGraph(0, 0, handle_, FALSE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void Fade::Fin()
{
	DeleteGraph(handle_);
}

// フェードイン開始
void Fade::FadeIn(int time)
{
	param_ = PARAM_MAX;
	value_ = PARAM_MAX / (float)time;
	status_ = FADE_IN;
}

// フェードアウト開始
void Fade::FadeOut(int time)
{
	param_ = 0;
	value_ = PARAM_MAX / (float)time;
	status_ = FADE_OUT;
}