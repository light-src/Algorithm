#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <vector>
#define MAX 51

int N, D, P, T;
int A[MAX][MAX], degree[MAX];
double cache[100][MAX];
int town[MAX];

double search(int day, int t,int i) {

	if (day == D)
		return t == town[i] ? 1.0 : 0.0;

	double &ret = cache[day][t];
	if (ret != 0)
		return ret;

	for (int next = 0; next < N; next++) {
		if (A[t][next])
			ret += search(day + 1, next, i) / degree[t];
	}

	return ret;

}

void data_in() {
	int C;
	freopen("./Dinamic-Programming(Basic)/NUMB3RS/input.txt", "r", stdin);

	scanf("%d ", &C);

	for (int i = 0; i < C; i++) {
		memset(degree, 0, sizeof(int)*MAX);
		scanf("%d %d %d ", &N, &D, &P);

		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				scanf("%d ", &A[j][k]);
			}
		}

		scanf("%d ", &T);

		for (int i = 0; i < T; i++) {
			scanf("%d ", &town[i]);
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				degree[i] += A[i][j];
			}
		}

		for (int i = 0; i < T; i++) {
			printf("%.8lf ", search(0, P, i));

			memset(cache, 0, sizeof(double) * 100 * MAX);
		}

		printf("\n");
	}
}

int main() {
	data_in();
}