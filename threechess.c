#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "threechess.h"

void meun()//��ӡ�˵�
{
	printf("           meun           \n");
	printf("---------------------------\n");
	printf("-----  1.Start game.   ----\n");
	printf("-----  0.Exit game.    ----\n");
	printf("---------------------------\n");
}

void game()//��ʼ��Ϸ
{
	char board[ROWS][COLS];
	char ret = 0;
	init_board(board,ROWS,COLS);
	display_board(board, ROWS, COLS);
	do
	{
		player_move(board, ROWS, COLS);
		ret = check_win(board,ROWS,COLS);
		if( 'X' == ret){ printf("Player win!\n");break; }
		if( 'O' == ret){ printf("Computer win!\n");break; }
		if( ' ' == ret){ printf("Dogfall!\n");break; }
		computer_move(board,ROWS,COLS);
		ret = check_win(board,ROWS,COLS);
		if( 'X' == ret){ printf("Player win!\n");break; }
		if( 'O' == ret){ printf("Computer win!\n");break; }
		if( ' ' == ret){ printf("Dogfall!\n");break; }
	}while(1);
}

void init_board(char board[ROWS][COLS], int x,int y)//��ʼ����Ϸ
{
	memset(board,' ',ROWS*COLS*sizeof(char));
}

void display_board(char board[ROWS][COLS], int x,int y)//��ӡ����
{
	int i = 0;
	int j = 0;
	for(i = 0; i<x; i++)
	{
		printf(" %c | %c | %c \n",board[i][0], board[i][1], board[i][2]);
		if( 2!=i )printf("---|---|---\n");	
	}
}
void player_move(char board[ROWS][COLS],int x,int y)//�����
{
	int i = 0;
	int j = 0;
	while(1)
	{
		printf("Player input>: ");
		scanf("%d %d",&i, &j);  //�������
		if( ' ' == board[i-1][j-1] \
			&& (i-1)>=0 && (i-1)<x \
			&& (j-1)>=0 && (j-1)<y ) //λ�úϷ��Լ��
			{
				board[i-1][j-1] = 'X';
				display_board(board, ROWS, COLS);
				break;
			}
		else printf("Error input!\n");
	}
}
void computer_move(char board[ROWS][COLS],int x,int y)//������
{
	int i = 0;
	int j = 0;
	printf("Computer input>:");
	while(1)
	{
		i = rand()%3;
		j = rand()%3;
		if(  ' ' == board[i][j] )//λ�úϷ��Լ��
		{
			printf("%d %d\n", i+1, j+1);
			board[i][j] = 'O';
			display_board(board, ROWS, COLS);
			break;
		}
	}
}

char check_win(char board[ROWS][COLS],int x,int y)//�����Ӯ
{
	int i = 0;
	int j = 0;
	int count = 0;
	for(i = 0; i<x; i++)
	{
		if(board[0][i] == board[1][i] && board[0][i] == board[2][i]) //�����
		{
			if( 'X' == board[0][i] ) return 'X';  
			if( 'O' == board[0][i] ) return 'O';
		}
		if(board[i][0] == board[i][1] && board[i][0] == board[i][2]) //�����
		{
			if( 'X' == board[i][0] ) return 'X';
			if( 'O' == board[i][0] ) return 'O';
		}
	}
	if(board[0][0] == board[1][1] && board[0][0] == board[2][2])   //���б�� 
	{
		if( 'X' == board[0][0] ) return 'X';
		if( 'O' == board[0][0] ) return 'O';
	}
	if(board[0][2] == board[1][1] && board[0][2] == board[2][0])   //���б��
	{
		if( 'X' == board[1][1] ) return 'X';
		if( 'O' == board[1][1] ) return 'O';
	}
	for(i = 0; i<x; i++)
	{
		for(j = 0;j<y; j++)
		{
			if( ' ' != board[i][j])count++;
		}
	}
	if( 9 == count) return ' ';
	return 0;
	
}

