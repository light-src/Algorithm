#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <algorithm>
#define MAX 100

int arr[MAX][MAX];
int cache[MAX][MAX];
int H;

int triangle_path(int y, int x) {
	
	if (y == H - 1)
		return arr[y][x];

	int&ret = cache[y][x];
	if (ret != 0)
		return ret;

	return ret = arr[y][x] + std::max(triangle_path(y + 1, x), triangle_path(y + 1, x + 1));
}

void data_in() {

	int N;
	int result;
	freopen("./Dinamic-Programming(Basic)/TRIANGLEPATH/input.txt", "r", stdin);

	scanf("%d ", &N);

	for (int i = 0; i < N; i++) {
		
		memset(arr, 0, sizeof(int)*MAX*MAX);
		memset(cache, 0, sizeof(int)*MAX*MAX);

		scanf("%d ", &H);

		for (int j = 0; j < H; j++) {
			for (int k = 0; k < j + 1; k++) {
				scanf("%d ", &arr[j][k]);
			}
		}
		result = triangle_path(0, 0);
		printf("%d\n",result);
	}
}

int main() {
	data_in();
}