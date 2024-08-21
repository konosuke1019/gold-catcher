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
	// �c�w���C�u��������������
	if (DxLib_Init() == -1)
	{
		return -1;	// �G���[���N�����璼���ɏI��
	}

	// ��ʃ��[�h�̃Z�b�g
	ChangeWindowMode(false);
	SetGraphMode(1600, 900, 16);

	SetDrawScreen(DX_SCREEN_BACK);	// ����ʂ�`��Ώۂɂ���
	SetUseZBufferFlag(TRUE);		// �y�o�b�t�@���g�p����
	SetWriteZBufferFlag(TRUE);		// �y�o�b�t�@�ւ̏������݂��s��
	SetUseBackCulling(TRUE);		// �o�b�N�J�����O���s��
	
	//�C���X�^���X��
	GAME* game = new GAME();
	Camera* camera = new Camera();
	Player* player = new Player();
	King* king = new King();
	Village* village = new Village();
	Money* money = new Money();
	Map* map = new Map();
	UI* ui = new UI();
	
	//���Ԃ̎擾
	int firstTime = 0;
	int secondTime = 0;

	//�G�X�P�[�v�L�[��������邩�E�C���h�E��������܂Ń��[�v
	LONGLONG frameTime = 0;
	
	//���[�h
	map->Load();
	game->Init();
	
	//�Q�[���̗���
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{	
		//�t�H���g�̐ݒ�
		ChangeFont("�x�X�g�e��DOT", false);
		
		//�t���[���̎擾
		frameTime = GetNowHiPerformanceCount();

		//��ʂ�����������
		ClearDrawScreen();

		//�`��
		ui->Draw(game->state);
		
		//state���Ƃɏ������s��
		switch (game->state)
		{
			//�^�C�g��
		case STATE_START:
			break;
			
			//�Q�[����
		case STATE_GAME:
			//���Ԑݒ�
			secondTime = GetNowCount();
			game->time = secondTime - firstTime - 1000;
			game->time *= 0.001;

			SetFontSize(90);
			//DrawFormatString(100, 100, GetColor(255, 255, 255), "TIME:%d�b", game->time);

			//�A�b�v�f�[�g
			player->Update();
			king->Update();
			money->Update(*player);
			camera->Update(*player);

			//�`��
			map->Draw();
			village->Draw();
			king->Draw();
			money->Draw();
			player->Draw();
			break;

			//���U���g
		case STATE_END:
			king->Draw();
			break;
			
			//���̑�
		default:
			break;
		}

		//����
		game->Update();
		
		//����ʂ̓��e��\��ʂɔ��f������
		ScreenFlip();

		//�G��60fps�Œ�
		while ((GetNowHiPerformanceCount() - frameTime) < 16667) {}
	}

	//�폜
	delete(player);
	delete(king);
	delete(village);
	delete(camera);
	delete(money);
	delete(map);
	delete(ui);
	delete(game);

	//�c�w���C�u�����̌�n��
	DxLib_End();

	//�\�t�g�̏I��
	return 0;
}