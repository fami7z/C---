#include "game.h"

// 初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';  // 初始化数组所有元素为空格
		}
	}
}

//void DisplayBoard(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < row; i++)
//	{
//		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
//		if(i<row-1)   // 最后一行不打印下列内容
//			printf("---|---|---\n");
//	}
//}
// 以上代码只适用于 3×3 的棋盘，不通用

// 打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	// 
	for (i = 0; i < row; i++)
	{
		// 打印每一行：数组元素 + "|"
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if(j < col-1)    //最后一列不打印 "|"
				printf("|");
		}
		printf("\n");
		// 打印行间 "---"
		if (i < row - 1)   // 最后一行不打印 "---"
		{
			int j = 0;
			for (j = 0; j < col; j++)
			{
				printf("---");
				if(j < col-1)
					printf("|");  // 最后一列不打印 "|"
			}
		}
		printf("\n");
	}
}

// 玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家走：->\n");
	while (1)
	{
		printf("请输入落棋的坐标：-> ");
		scanf_s("%d %d", &x, &y);
		// 判断坐标合法性
		if (x > 0 && x <= row && y > 0 && y <= col)
		{
			// 下棋
			// 判断坐标是否被占用
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("坐标被占用，请重新输入\n");
			}
		}
		else
		{
			printf("坐标非法，请重新输入");
		}
	}
}

// 电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("电脑走：>\n");
	while (1)
	{
		// 生成 0-2 的随机数
		int x = rand() % row;
		int y = rand() % col;
		// 判断是否被占用
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

// 判断游戏状态
char IsWin(char board[ROW][COL], int row, int col)
{
	// 判断三行
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];  // 注意此处的设计 
		}
	}
	// 判断三列
	int j = 0;
	for (j = 0; j < row; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ')
		{
			return board[1][j];  // 注意此处的设计 
		}
	}
	// 判断对角线
	if (board[0][0] == board[1][1] && board[2][2] == board[1][1] && board[1][1] != ' ')
	{
		return board[1][1];  // 注意此处的设计 
	}
	if (board[0][2] == board[1][1] && board[2][0] == board[1][1] && board[1][1] != ' ')
	{
		return board[1][1];  // 注意此处的设计 
	}
	// 判断平局
	int result = IsFull(board,row,col);
	if (result == 1)
	{
		return 'Q';   // 平局
	}
	return 'C';  // 游戏继续
}

// 判断棋盘满与否
int IsFull(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;            // 未满
		}
	}
	return 1;  
}


