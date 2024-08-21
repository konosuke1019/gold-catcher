#include<vector>
#include "DxLib.h"
#include "game.h"
#include "Player.h"
#include "king.h"
#include "village.h"
#include "money.h"
#include "Map.h"
#include "camera.h"
#include "UI.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1)
	{
		return -1;	// エラーが起きたら直ちに終了
	}

	// 画面モードのセット
	ChangeWindowMode(false);
	SetGraphMode(1600, 900, 16);

	SetDrawScreen(DX_SCREEN_BACK);	// 裏画面を描画対象にする
	SetUseZBufferFlag(TRUE);		// Ｚバッファを使用する
	SetWriteZBufferFlag(TRUE);		// Ｚバッファへの書き込みを行う
	SetUseBackCulling(TRUE);		// バックカリングを行う
	
	//インスタンス化
	GAME* game = new GAME();
	Camera* camera = new Camera();
	Player* player = new Player();
	King* king = new King();
	Village* village = new Village();
	Money* money = new Money();
	Map* map = new Map();
	UI* ui = new UI();
	
	//時間の取得
	int firstTime = 0;
	int secondTime = 0;

	//エスケープキーが押されるかウインドウが閉じられるまでループ
	LONGLONG frameTime = 0;
	
	//ロード
	map->Load();
	game->Init();
	
	//ゲームの流れ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{	
		//フォントの設定
		ChangeFont("ベストテンDOT", false);
		
		//フレームの取得
		frameTime = GetNowHiPerformanceCount();

		//画面を初期化する
		ClearDrawScreen();

		//描画
		ui->Draw(game->state);
		
		//stateごとに処理を行う
		switch (game->state)
		{
			//タイトル
		case STATE_START:
			break;
			
			//ゲーム中
		case STATE_GAME:
			//時間設定
			secondTime = GetNowCount();
			game->time = secondTime - firstTime - 1000;
			game->time *= 0.001;

			SetFontSize(90);
			//DrawFormatString(100, 100, GetColor(255, 255, 255), "TIME:%d秒", game->time);

			//アップデート
			player->Update();
			king->Update();
			money->Update(*player);
			camera->Update(*player);

			//描画
			map->Draw();
			village->Draw();
			king->Draw();
			money->Draw();
			player->Draw();
			break;

			//リザルト
		case STATE_END:
			king->Draw();
			break;
			
			//その他
		default:
			break;
		}

		//制御
		game->Update();
		
		//裏画面の内容を表画面に反映させる
		ScreenFlip();

		//雑に60fps固定
		while ((GetNowHiPerformanceCount() - frameTime) < 16667) {}
	}

	//削除
	delete(player);
	delete(king);
	delete(village);
	delete(camera);
	delete(money);
	delete(map);
	delete(ui);
	delete(game);

	//ＤＸライブラリの後始末
	DxLib_End();

	//ソフトの終了
	return 0;
}