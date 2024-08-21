#include "game.h"
#include "DxLib.h"
#include "player.h"
#include "money.h"
#include "king.h"
#include "Map.h"
#include "UI.h"
#include "camera.h"

/// <summary>
/// コンストラクタ
/// </summary>
GAME::GAME()
{
	
}

/// <summary>
/// デストラクタ
/// </summary>
GAME::~GAME()
{
	
}

/// <summary>
/// 初期化
/// </summary>
void GAME::Init()
{
	//スタート画面にする
	state = STATE_START;
}

/// <summary>
/// state切り替え
/// </summary>
void GAME::ChangeState()
{
	//少し時間を止める.
	WaitTimer(500);

	// ステートが切り替わった瞬間はキー離した判定をリセット.
	keyOn = false;
	keyRelease = false;
	//ステート
	state = state;
	// ステートが切り替わった瞬間、必要なら初期化などの処理を行う
	switch (state)
	{
		// タイトル.
	case STATE_START:
		Init();
		time = 0;
		break;
		// ゲーム中.
	case STATE_GAME:
		break;
		// クリア画面.
	case STATE_END:
		break;
		// その他
	default:
		break;
	}
}

/// <summary>
/// アップデート
/// </summary>
void GAME::Update()
{
	//キー離した瞬間を取る.
	if (keyOn)
	{
		if (CheckHitKey(KEY_INPUT_SPACE) == 0)
		{
			keyOn = false;
			keyRelease = true;
		}
	}
	else if (prevKeyOn == false && CheckHitKey(KEY_INPUT_SPACE) == 1)
	{
		keyRelease = false;
		keyOn = true;
	}
	if (CheckHitKey(KEY_INPUT_SPACE) == 1)
	{
		prevKeyOn = true;
	}
	else
	{
		prevKeyOn = false;
	}

	switch (state)
	{
	case STATE_START:
		// キー入力があったらゲーム開始の状態に
		if (keyRelease)
		{
			state = STATE_GAME;
			ChangeState();
			time = 0;
		}
		break;
	case STATE_GAME:
		break;
	}
}