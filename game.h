#pragma once
#include "DxLib.h"

class GAME
{
public:
	
	//フラグ
	bool keyOn = false;
	bool prevKeyOn = false;
	bool keyRelease = false;

	//変数
	int state;
	int time = 0;

	//コンストラクタ&デストラクタ
	GAME();
	~GAME();

	//初期化
	void Init();
	//state切り替え
	void ChangeState();
	//アップデート
	void Update();
	//描画
	//void Draw();
};