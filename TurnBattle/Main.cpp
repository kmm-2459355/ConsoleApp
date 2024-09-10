//======================================
//	ターン制バトル メイン
//======================================
#include "Character.h"
#include "TurnBattle.h"
#include "CommandUI.h"
#include "Utility.h"  // InitRand(),GetKey()
#include <stdio.h>  // printf()
// 関数プロトタイプ
void game();

int main()
{
	InitRand();

	int c;
	do {
		game();
		printf("もう一度(y/n)?");
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
		30,         // 攻撃力
		"ゆうしゃ", // 名前
		"");        // アスキーアート
	SetCharacter(&boss,
		130,      // HP
		3,        // MP
		50,       // 攻撃力
		"まおう", // 名前
		"　　Ａ＠Ａ\n" // アスキーアート
		"ψ（▼皿▼）ψ"
	);
	SetCharacter(&zako,
		3,          // HP
		0,          // MP
		2,          // 攻撃力
		"スライム", // 名前 
		"／・Д・＼\n" // アスキーアート
		"～～～～～"
	);
	SetCharacter(&chuboss,
		50,
		0,
		30,
		"中ボス",
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
			cmd = GetPlayerCommand(&btl); // プレイヤーのターン
			isEnd = ExecPlayerTurn(&btl, cmd);
			if (isEnd) break;

			cmd = GetEnemyCommand(&chuboss); // 敵のターン
			isEnd = ExecEnemyTurn(&btl, cmd);
			if (isEnd) break;

			NextTurnBattle(&btl);
		}


	} while (!isEnd);

	
	isEnd = false; 
	do {
		SetTurnBattle(&btl, &player, &boss); // ポインタでプレイヤーとボスを設定
		StartTurnBattle(&btl);
		IntroTurnBattle(&btl);

		Command cmd;
		while (true) {
			cmd = GetPlayerCommand(&btl); // プレイヤーのターン
			isEnd = ExecPlayerTurn(&btl, cmd);
			if (isEnd) break;

			cmd = GetEnemyCommand(&boss); // 敵のターン
			isEnd = ExecEnemyTurn(&btl, cmd);
			if (isEnd) break;

			NextTurnBattle(&btl);
		}

	} while (!isEnd);
	
}