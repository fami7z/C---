#pragma once

#include <stdio.h>
// 产生随机数需要引入的头文件
#include <stdlib.h>
#include <time.h>

// 符号的定义
#define ROW 3
#define COL 3

// 函数的声明
// 初始化棋盘的函数
void InitBoard(char board[ROW][COL], int row, int col);
// 打印棋盘的函数
void DisplayBoard(char board[ROW][COL], int row, int col);
// 玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col);
// 电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col);
// 判断输赢状态
char IsWin(char board[ROW][COL], int row, int col);
// 判断棋盘是否下满
int IsFull(char board[ROW][COL], int row, int col);
