#include "SoundManager.h"
#include "DxLib.h"

int SoundManager::sound_handle_[SOUND_ID_MAX] = { 0 };

void SoundManager::Load(int group_id)
{
	const int* group = SOUND_GROUP[group_id];

	for (int i = 0; i < SOUND_ID_MAX; i++, group++) {
		int index = (*group);
		if (index < 0 || index > SOUND_ID_MAX) break;

		sound_handle_[index] = LoadSoundMem(SOUND_DATABASE[index].file_path);
	}
}

void SoundManager::PlaySE(int id)
{
	ChangeVolumeSoundMem(255 * 40 / 100, sound_handle_[id]);
	PlaySoundMem(sound_handle_[id], DX_PLAYTYPE_BACK);
}

void SoundManager::PlayBGM(int id)
{
	ChangeVolumeSoundMem(255 * 40 / 100, sound_handle_[id]);
	PlaySoundMem(sound_handle_[id], DX_PLAYTYPE_LOOP);
}

void SoundManager::DeleteSound(int group_id)
{
	const int* group = SOUND_GROUP[group_id];

	for (int i = 0; i < SOUND_ID_MAX; i++, group++) {
		int index = (*group);
		if (index < 0 || index > SOUND_ID_MAX) break;

		DeleteSoundMem(sound_handle_[index]);
		sound_handle_[index] = 0;
	}
}
