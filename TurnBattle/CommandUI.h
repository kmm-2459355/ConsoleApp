#pragma once
//======================================
//	コマンドUI
//======================================
// ★ここにインクルードガード(開始)を記入してください。
#ifndef __COMMANDUI_H
#define __COMMANDUI_H

#include "Command.h"
#include "TurnBattle.h"

// プレーヤのコマンド取得
Command GetPlayerCommand(TurnBattle* btl);
// 敵のコマンド取得
Command GetEnemyCommand(Character* ch);

// ★ここにインクルードガード(終了)を記入してください。
#endif