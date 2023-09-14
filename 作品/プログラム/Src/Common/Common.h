#pragma once
#include <random>

#define GAME_FPS 60
#define FRAME_RATE (1000 / 60)	//60•ª‚Ì1•b

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

class Common {
public:
	static void Init();
	static void Step();

	static int GetGameDeltaFrame();

	static void InitRandom();
	static int  GetRandom(int min_value, int max_value);
	static float GetRandom(float min_value, float max_value, int digit);

private:
	static int old_time_;
	static int delta_frame_;
	static std::mt19937 mt_;
};
