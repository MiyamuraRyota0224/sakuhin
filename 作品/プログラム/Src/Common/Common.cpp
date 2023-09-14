#include "DxLib.h"
#include "Common.h"
#include <time.h>

using namespace std;

int Common::old_time_ = 0;
int Common::delta_frame_ = 0;
mt19937 Common::mt_;

void Common::Init()
{
	old_time_ = GetNowCount();
}

void Common::Step()
{
	int now_time = GetNowCount();
	delta_frame_ = (now_time - old_time_) / (1000 / GAME_FPS);

	old_time_ = now_time;
}

// デルタフレーム取得（1ループに掛かった時間をFPS基準で何フレーム掛かったかを返す）
int Common::GetGameDeltaFrame()
{
#ifdef _DEBUG
	// デバッグ中は必ず１（ブレーク中にもゲームが進むため）
	return 1;
#else
	return delta_frame_;
#endif
}

void Common::InitRandom()
{
	// 乱数シード設定
	random_device rand;
	mt_.seed(rand());
}

// 乱数取得
int Common::GetRandom(int min_value, int max_value)
{
	int range = max_value - min_value + 1;
	return (mt_() % range) + min_value;
}

// 小数点第5位までの乱数
float Common::GetRandom(float min_value, float max_value, int digit)
{
	int coe = 1;
	for (int i = 0; i < digit - 1; i++) {
		coe *= 10;
	}

	float min = (min_value) * coe;
	float max = (max_value) * coe;
	int range = static_cast<int>(max - min);

	// ランダム範囲が無い場合は最小値を返す
	if (range == 0) return min;

	return ((mt_() % range) + min) / coe;
}
