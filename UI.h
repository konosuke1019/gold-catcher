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
    
    //�ϐ�
    int TitleGraph;
    int TitleBackGraph;
    int ButtonGraph;
    int ButtonCount;

    //�R���X�g���N�^&�f�X�g���N�^
    UI();
    ~UI();

    ////����
    //void Update();
    //�`��
    void Draw(int state);
};