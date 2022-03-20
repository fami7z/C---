//#include <stdio.h>
#include "game.h"    // 头文件的包含，game.h 中已经包含了 stdio.h，故无须重复引用。

void menu()
{
	printf("**************************\n");
	printf("******    1. play   ******\n");
	printf("******    0. exit   ******\n");
	printf("**************************\n");
}

void game()
{
	// 存储数据-二维数组
	char board[ROW][COL];
	// 初始化棋盘 - 初始化为空格
	InitBoard(board, ROW, COL);
	// 打印棋盘 - 本质是打印数组
	DisplayBoard(board, ROW, COL);

	char ret = 0; // 接收游戏状态

	while (1)
	{
		// 玩家下棋
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判读输赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')  // C : Continue
			break;

		// 电脑下棋
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判读输赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
	}
	if (ret == '*')
	{
		printf("玩家赢了！\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢了！\n");
	}
	else
	{
		printf("平局！\n");
	}
	DisplayBoard(board, ROW, COL);
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));  //产生随机数

	do
	{
		menu();
		printf("请选择：");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			printf("\n三子棋游戏\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			break;
		}
	} while (input);

	return 0;
}