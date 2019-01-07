#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string.h>
#define MAX 100

int W1, W2;
int arr1[MAX];
int arr2[MAX];
int cache[MAX][MAX];


int JLIS(int idx1, int idx2) {

	int& ret = cache[idx1][idx2];
	if (ret)
		return ret;

	if (arr1[idx1] != arr2[idx2])
		ret = 1;
	else
		ret = 2;
		
	int max_val = std::max(arr1[idx1], arr2[idx2]);

	for (int i = idx1; i < W1; i++) {
		for (int j = idx2; j < W2; j++) {
			if (arr1[i] > max_val) {
				ret = std::max(ret, JLIS(i, idx2) + 1);
			}
			if (arr2[j] > max_val) {
				ret = std::max(ret, JLIS(idx1, j) + 1);
			}
		}
	}

	return ret;
}

void data_in() {
	
	int N;

	freopen("./Dinamic-Programming(Basic)/JLIS/input.txt", "r", stdin);

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		memset(arr1, 0, sizeof(int)*MAX);
		memset(arr2, 0, sizeof(int)*MAX);
		memset(cache, 0, sizeof(int)*MAX*MAX);
		scanf("%d %d ", &W1, &W2);

		for (int j = 0; j < W1; j++) {
			scanf("%d ", &arr1[j]);
		}

		for (int j = 0; j < W2; j++) {
			scanf("%d ", &arr2[j]);
		}

		int result = JLIS(-1, -1) - 1;
		printf("%d\n", result);
	}
}

int main() {

	data_in();

}