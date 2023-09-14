#include "DxLib.h"
#include "Common/Common.h"
#include "Scene/SceneManager.h"
#include "Scene/SceneParameter.h"
#include "Input/Input.h"



//FPS計測用
int g_nFrameCnt = 0;		//FPSカウント
float g_fFramerate = 0.0f;	//フレームレート
int g_nLastTime = 0;		//以前計測した時間

void DrawFramerate();		//FPS表示

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	//ウィンドウサイズを変更
	SetGraphMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32);

	//描画するスクリーンを設定する
	SetDrawScreen(DX_SCREEN_BACK);

	// 必要なマネージャークラスを生成、初期化
	// シーンマネージャー
	SceneManager::CreateInstance();
	SceneManager* scene_manager = SceneManager::GetInstance();
	scene_manager->StartFirstScene(SCENE_ID_TITLE);

	
	

	Common::Init();

	int nCurrentTime = 0;			//現在の経過時間
	int nOldTime = GetNowCount();	//以前の経過時間

	// Ｚバッファを有効にする
	// SetUseZBuffer3D(TRUE);

	// Ｚバッファへの書き込みを有効にする
	// SetWriteZBuffer3D(TRUE);

	

	
	while (ProcessMessage() != -1) {
		//システムに処理を返す
		Sleep(1);

		//今の経過時間を取得
		nCurrentTime = GetNowCount();

		//以前の時間から1/60秒経過していたら処理を実行
		if (nCurrentTime - nOldTime >= FRAME_RATE)
		{
			//時間の更新
			nOldTime = nCurrentTime;

			// ↓画面を消す/////////////////////////////////////////////
			ClearDrawScreen();

			// 入力更新
			CInput::StepInput();
			// ゲーム関連共通項目更新
			Common::Step();
			// シーンの更新
			scene_manager->Loop();
	

#ifdef _DEBUG
			//フレームレートの描画
			DrawFramerate();
#endif
			ScreenFlip();

			if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
				break;
			}
		}
	}

	// 後処理
	SceneManager::DeleteInstance();
	

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}

//FPS表示
void DrawFramerate()
{
	//フレーム数をカウント
	g_nFrameCnt++;

	//現在の時間
	int nCurrentTime = GetNowCount();

	//前回の時間からの経過時間
	float fLapsedTime = (float)(nCurrentTime - g_nLastTime);

	//前回の時間から１秒以上経過していたらフレームレートを更新
	if (fLapsedTime >= 1000)
	{
		//フレームレート計算
		float fFrameCnt = (float)(g_nFrameCnt * 1000);	//フレーム回数をミリ秒に合わせる
		g_fFramerate = fFrameCnt / fLapsedTime;			//フレームレートを求める

		g_nFrameCnt = 0;				//フレームカウントをクリア
		g_nLastTime = nCurrentTime;		//時間を更新
	}

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	SetDrawBright(255, 255, 255);

	//フレームレートの表示
	DrawFormatString(WINDOW_WIDTH - 95, WINDOW_HEIGHT - 20, GetColor(255, 0, 0), "FPS[%.2f]", g_fFramerate);
}
