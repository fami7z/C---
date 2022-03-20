#include "game.h"

// ��ʼ������
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';  // ��ʼ����������Ԫ��Ϊ�ո�
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
//		if(i<row-1)   // ���һ�в���ӡ��������
//			printf("---|---|---\n");
//	}
//}
// ���ϴ���ֻ������ 3��3 �����̣���ͨ��

// ��ӡ����
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	// 
	for (i = 0; i < row; i++)
	{
		// ��ӡÿһ�У�����Ԫ�� + "|"
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if(j < col-1)    //���һ�в���ӡ "|"
				printf("|");
		}
		printf("\n");
		// ��ӡ�м� "---"
		if (i < row - 1)   // ���һ�в���ӡ "---"
		{
			int j = 0;
			for (j = 0; j < col; j++)
			{
				printf("---");
				if(j < col-1)
					printf("|");  // ���һ�в���ӡ "|"
			}
		}
		printf("\n");
	}
}

// �������
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("����ߣ�->\n");
	while (1)
	{
		printf("��������������꣺-> ");
		scanf_s("%d %d", &x, &y);
		// �ж�����Ϸ���
		if (x > 0 && x <= row && y > 0 && y <= col)
		{
			// ����
			// �ж������Ƿ�ռ��
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("���걻ռ�ã�����������\n");
			}
		}
		else
		{
			printf("����Ƿ�������������");
		}
	}
}

// ��������
void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("�����ߣ�>\n");
	while (1)
	{
		// ���� 0-2 �������
		int x = rand() % row;
		int y = rand() % col;
		// �ж��Ƿ�ռ��
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

// �ж���Ϸ״̬
char IsWin(char board[ROW][COL], int row, int col)
{
	// �ж�����
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];  // ע��˴������ 
		}
	}
	// �ж�����
	int j = 0;
	for (j = 0; j < row; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ')
		{
			return board[1][j];  // ע��˴������ 
		}
	}
	// �ж϶Խ���
	if (board[0][0] == board[1][1] && board[2][2] == board[1][1] && board[1][1] != ' ')
	{
		return board[1][1];  // ע��˴������ 
	}
	if (board[0][2] == board[1][1] && board[2][0] == board[1][1] && board[1][1] != ' ')
	{
		return board[1][1];  // ע��˴������ 
	}
	// �ж�ƽ��
	int result = IsFull(board,row,col);
	if (result == 1)
	{
		return 'Q';   // ƽ��
	}
	return 'C';  // ��Ϸ����
}

// �ж����������
int IsFull(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;            // δ��
		}
	}
	return 1;  
}


