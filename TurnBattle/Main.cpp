//======================================
//	�^�[�����o�g�� ���C��
//======================================
#include "Character.h"
#include "TurnBattle.h"
#include "CommandUI.h"
#include "Utility.h"  // InitRand(),GetKey()
#include <stdio.h>  // printf()
// �֐��v���g�^�C�v
void game();

int main()
{
	InitRand();

	int c;
	do {
		game();
		printf("������x(y/n)?");
		while (true) {
			c = GetKey();
			if (c == 'y' || c == 'n') {
				break;
			}
		}
	} while (c == 'y');

	return 0;
}

void game()
{
	Character player;
	Character boss;
	Character zako;
	Character chuboss;
	TurnBattle btl;

	SetCharacter(&player,
		100,        // HP
		15,         // MP
		30,         // �U����
		"�䂤����", // ���O
		"");        // �A�X�L�[�A�[�g
	SetCharacter(&boss,
		130,      // HP
		3,        // MP
		50,       // �U����
		"�܂���", // ���O
		"�@�@�`���`\n" // �A�X�L�[�A�[�g
		"�Ձi���M���j��"
	);
	SetCharacter(&zako,
		3,          // HP
		0,          // MP
		2,          // �U����
		"�X���C��", // ���O 
		"�^�E�D�E�_\n" // �A�X�L�[�A�[�g
		"�`�`�`�`�`"
	);
	SetCharacter(&chuboss,
		50,
		0,
		30,
		"���{�X",
		"^-^"
	);

	bool isEnd = false;

	do {
		SetTurnBattle(&btl, &player, &zako); 
		StartTurnBattle(&btl);
		IntroTurnBattle(&btl);

		Command cmd;
		while (true) {
			cmd = GetPlayerCommand(&btl); 
			isEnd = ExecPlayerTurn(&btl, cmd);
			if (isEnd) break;

			cmd = GetEnemyCommand(&zako); 
			isEnd = ExecEnemyTurn(&btl, cmd);
			if (isEnd) break;

			NextTurnBattle(&btl);
		}

	} while (!isEnd);


	isEnd = false; 
	do {
		SetTurnBattle(&btl, &player, &chuboss);
		StartTurnBattle(&btl);
		IntroTurnBattle(&btl);

		Command cmd;
		while (true) {
			cmd = GetPlayerCommand(&btl); // �v���C���[�̃^�[��
			isEnd = ExecPlayerTurn(&btl, cmd);
			if (isEnd) break;

			cmd = GetEnemyCommand(&chuboss); // �G�̃^�[��
			isEnd = ExecEnemyTurn(&btl, cmd);
			if (isEnd) break;

			NextTurnBattle(&btl);
		}


	} while (!isEnd);

	
	isEnd = false; 
	do {
		SetTurnBattle(&btl, &player, &boss); // �|�C���^�Ńv���C���[�ƃ{�X��ݒ�
		StartTurnBattle(&btl);
		IntroTurnBattle(&btl);

		Command cmd;
		while (true) {
			cmd = GetPlayerCommand(&btl); // �v���C���[�̃^�[��
			isEnd = ExecPlayerTurn(&btl, cmd);
			if (isEnd) break;

			cmd = GetEnemyCommand(&boss); // �G�̃^�[��
			isEnd = ExecEnemyTurn(&btl, cmd);
			if (isEnd) break;

			NextTurnBattle(&btl);
		}

	} while (!isEnd);
	
}