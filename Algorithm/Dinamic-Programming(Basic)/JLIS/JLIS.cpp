#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#define MAX 101

int W1, W2;
int arr1[MAX];
int arr2[MAX];
int cache[MAX][MAX];

long long NEGINF = std::numeric_limits<long long>::min();

int JLIS(int idx1, int idx2) {

	int& ret = cache[idx1+1][idx2+1];
	if (ret != 0)
		return ret;

	ret = 0;
	
	long long first = idx1 == -1 ? NEGINF : arr1[idx1];
	long long second = idx2 == -1 ? NEGINF : arr2[idx2];

	long long max_val = std::max(first, second);

	for (int i = idx1 + 1; i < W1; i++) {
		if (arr1[i] > max_val) {
			ret = std::max(ret, JLIS(i, idx2) + 1);
		}
	}

	for (int i = idx2 + 1; i < W2; i++ ) {
		if (arr2[i] > max_val) {
			ret = std::max(ret, JLIS(idx1, i) + 1);
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

		int result = JLIS(-1, -1);
		printf("%d\n", result == 0 ? 1 : result);
	}
}

int main() {

	data_in();

}