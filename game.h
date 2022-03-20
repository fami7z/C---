#pragma once

#include <stdio.h>
// �����������Ҫ�����ͷ�ļ�
#include <stdlib.h>
#include <time.h>

// ���ŵĶ���
#define ROW 3
#define COL 3

// ����������
// ��ʼ�����̵ĺ���
void InitBoard(char board[ROW][COL], int row, int col);
// ��ӡ���̵ĺ���
void DisplayBoard(char board[ROW][COL], int row, int col);

void PlayerMove(char board[ROW][COL], int row, int col);

void ComputerMove(char board[ROW][COL], int row, int col);

char IsWin(char board[ROW][COL], int row, int col);

int IsFull(char board[ROW][COL], int row, int col);
