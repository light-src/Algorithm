#include <iostream>
//cache는 먼저 초기화 해둔다. 보통 -1로 한다.
//memset을 이용하여 초기화 하면 좋다.
int cache[101][101];

int bino(int n, int r){
	//ret는 참조형 reference이다.
	int *ret = &cache[n][r];

	//기저사례에 먼저 접근한다.
	if(n == r || r == 0) return 1;

	//이전에 이 값을 계산한 적이 있으면 곧장 반환한다.
	if(*ret != -1) return *ret;

	//정답을 계산한다.
	return *ret = bino(n-1,r-1) + bino(n-1,r);
}