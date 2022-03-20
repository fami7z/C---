//#include <stdio.h>
#include "game.h"    // ͷ�ļ��İ�����game.h ���Ѿ������� stdio.h���������ظ����á�

void menu()
{
	printf("**************************\n");
	printf("******    1. play   ******\n");
	printf("******    0. exit   ******\n");
	printf("**************************\n");
}

void game()
{
	// �洢����-��ά����
	char board[ROW][COL];
	// ��ʼ������ - ��ʼ��Ϊ�ո�
	InitBoard(board, ROW, COL);
	// ��ӡ���� - �����Ǵ�ӡ����
	DisplayBoard(board, ROW, COL);

	char ret = 0; // ������Ϸ״̬

	while (1)
	{
		// �������
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�ж���Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')  // C : Continue
			break;

		// ��������
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�ж���Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
	}
	if (ret == '*')
	{
		printf("���Ӯ�ˣ�\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ�ˣ�\n");
	}
	else
	{
		printf("ƽ�֣�\n");
	}
	DisplayBoard(board, ROW, COL);
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));  //���������

	do
	{
		menu();
		printf("��ѡ��");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			printf("\n��������Ϸ\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			break;
		}
	} while (input);

	return 0;
}