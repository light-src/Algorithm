#include <iostream>
#define N 10

int board[N][N];

//재귀적으로
bool JumpToNext(int y, int x){
	int value = board[y][x];

	if(y > N || x > N) return false; 

	if(y == N-1 && x == N-1) return true;

	return JumpToNext(y + value,x) || JumpToNext(y,value + x);
}

//메모이제이션
int cache[N][N];
int JumpToNext2(int y,int x){
	int value = board[y][x];
	int *ret = &cache[y][x];

	if(y > N || x > N) return 0; 
	if(y == N-1 && x == N-1) return 1;

	if(*ret != -1)
		return *ret;

	return *ret = JumpToNext(y + value,x) + JumpToNext(y,value + x);
}