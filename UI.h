#pragma once
#include "DxLib.h"

enum STATE
{
    STATE_START,
    STATE_CHUT,
    STATE_GAME,
    STATE_END,
};

class UI
{
public:
    
    //�ϐ�
    int TitleGraph;
    int TitleBackGraph;
    int boardGraph;
    int paperGraph;
    int coinGraph;
    int billGraph;
    int boxGraph;
    int ButtonGraph;
    int ButtonCount;
    int lastscore;
    //�R���X�g���N�^&�f�X�g���N�^
    UI();
    ~UI();

    ////����
    //void Update();
    //�`��
    void Draw(int state,int score);
};