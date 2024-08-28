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
	ChangeWindowMode(true);
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
	int firstTime = GetNowCount();
	int secondTime;

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
		ui->Draw(game->state,money->point);
		map->Draw();
		//state���Ƃɏ������s��
		switch (game->state)
		{
			//�^�C�g��
		case STATE_START:
			break;
		case STATE_CHUT:
			player->Update();
			money->Update(*player,game->time,game->state);
			village->Draw();
			money->Draw(game->state);
			player->Draw();
			camera->Update(*player);
			break;
			//�Q�[����
		case STATE_GAME:
			//���Ԑݒ�
			secondTime = GetNowCount();
			game->time = secondTime - firstTime;
			game->time *= 0.001;

			SetFontSize(50);
			if (game->time < 0)
			{
				DrawFormatString(10, 10, GetColor(255, 255, 255), "�I���܂Ŏc��:%d�b", 60 - game->time);
			}

			//�A�b�v�f�[�g
			player->Update();
			king->Update(game->state);
			money->Update(*player,game->time,game->state);
			camera->Update(*player);

			//�`��
			village->Draw();
			king->Draw(game->state);
			money->Draw(game->state);
			player->Draw();
			if (60 - game->time < 0)
			{
				game->state = STATE_END;
			}
			break;

			//���U���g
		case STATE_END:
			king->Update(game->state);
			king->Draw(game->state);
			camera->Update(*player);
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