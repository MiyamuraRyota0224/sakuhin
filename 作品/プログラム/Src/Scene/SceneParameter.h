#pragma once

//シーン状態
enum SCENE_STATE {
	SCENE_STATE_INIT,		//初期化
	SCENE_STATE_LOAD,		//ロード
	SCENE_STATE_LOAD_END,	//ロード終了
	SCENE_STATE_LOOP,		//ループ
	SCENE_STATE_FIN,		//後処理
};
//シーンID
enum SCENE_ID
{
	SCENE_ID_TITLE,		//タイトルシーン
	SCENE_ID_PLAY,		//プレイシーン
	SCENE_ID_CLEAR,		//クリアシーン
	SCENE_ID_GAMEOVER,	//ゲームオーバーシーン
	SCENE_ID_NUM,
};

