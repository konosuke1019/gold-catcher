#pragma once
#include "DxLib.h"

enum STATE
{
    STATE_START,
    STATE_GAME,
    STATE_END,
};

class UI
{
public:
    
    //変数
    int TitleGraph;
    int TitleBackGraph;
    int ButtonGraph;
    int ButtonCount;

    //コンストラクタ&デストラクタ
    UI();
    ~UI();

    ////制御
    //void Update();
    //描画
    void Draw(int state);
};