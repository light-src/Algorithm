#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string.h>
#define MAX 100
int M;
int arr[MAX];
int cache[MAX + 1];

int LIS(int idx) {
	int &ret = cache[idx + 1];
	if (ret != 0)
		return ret;

	ret = 1;
	for (int i = idx + 1; i < M; i++) {
		if(idx == -1 || arr[i] > arr[idx])
			ret = std::max(ret, LIS(i) + 1);
	}

	return ret;
}

void data_in() {
	int N;

	freopen("./Dinamic-Programming(Basic)/LIS/input.txt", "r", stdin);

 	scanf("%d ", &N);

	for (int i = 0; i < N; i++) {

		memset(arr, 0, sizeof(int)*MAX);
		memset(cache, 0, sizeof(int)*MAX);

		scanf("%d ", &M);

		for (int j = 0; j < M; j++) {
			scanf("%d ", &arr[j]);
		}

		int result = LIS(-1) - 1;

		printf("%d\n", result);

	}
}

int main() {
	data_in();
}