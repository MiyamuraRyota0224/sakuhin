#pragma once
#include "SoundParameter.h"
#include <vector>

class SoundManager {
public:
	static void Load(int group_id);
	static void PlaySE(int id);
	static void PlayBGM(int id);
	static void DeleteSound(int group_id);

private:
	static int sound_handle_[SOUND_ID_MAX];
};
