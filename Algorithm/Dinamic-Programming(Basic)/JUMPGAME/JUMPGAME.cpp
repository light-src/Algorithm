#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#define MAX 100

int cache[MAX][MAX];
int A[MAX][MAX];
int M;

int jump_game(int y, int x) {

	if (x >= M || y >= M)
		return 0;
	
	if (x == M - 1 && y == M - 1)
		return 1;

	int &ret = cache[y][x];
	if (ret != -1)
		return ret;

	return ret = jump_game(y + A[y][x], x) || jump_game(y, x + A[y][x]);

}

void data_in() {
	int N;

	freopen("./Dinamic-Programming(Basic)/JUMPGAME/input.txt", "r", stdin);

	scanf("%d ", &N);

	for (int i = 0; i < N; i++) {
		
		memset(cache, -1, sizeof(int)*MAX*MAX);
		scanf("%d ", &M);

		for (int j = 0; j < M; j++) {
			for (int k = 0; k < M; k++) {
				scanf("%d ", &A[j][k]);
			}
		}

		printf("%s\n",jump_game(0, 0) > 0 ? "YES": "NO");
	}


}

int main() {
	data_in();
}