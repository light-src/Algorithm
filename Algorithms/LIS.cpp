#include <iostream>

#define INF 987654321
#define max(x,y) x > y ? x : y
#define N 10

int arr[N];
//내가 짠 재귀호출
int LIS(int idx, int prev) {
	int ret = -INF;

	if (idx == N - 1)
		return 1;

	for (int i = idx; i < n i++) {
		if (prev < arr[i]) {
			ret = max(ret, LIS(i, arr[i]));
		}
	}

	return ret + 1;
}

//내가 짠 동적프로그래밍 <- 잘못짰네;;
int cache[N];
int LIS2(int idx, int prev) {
	int ret = -INF;
	int *chk = &cache[idx];

	if (idx == N - 1)
		return 1;
	if (*chk != -1)
		return *chk;

	for (int i = idx; i < N; i++) {
		if (prev < arr[i]) {
			ret = max(ret, LIS(i, arr[i]));
		}
	}

	return ret + 1;
}

//내가짠 것을 책보고 수정
int LIS3(int idx) {
	int *ret = &cache[idx];

	if (idx >= N)
		return 1;

	if (*ret != -1)
		return *ret;

	for (int i = idx + 1; i < N; i++) {
		if (arr[idx] < arr[i]) {
			*ret = max(*ret, LIS3(i));
		}
	}

	return *ret;
}

//시작위치 고정하기 업그레이드
int cache2[N + 1];
int LIS4(int idx) {
	int *ret = &cache[idx + 1];

	if (*ret != -1)
		return *ret;

	for (int i = idx + 1; i < N; i++)
		if (idx == -1 || arr[idx] < arr[i])
			*ret = max(*ret, LIS4(i));
	return *ret;
}

