#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#define MAX 8
#define INF 987654321;

using namespace std;

int H;
double dist[MAX][MAX];

double TSP(vector<int> &path, vector<bool> &visited, double currentLength) {

	double ret = INF;

	if (path.size() == H) {
		return currentLength + dist[path.back()][path[0]];
	}

	for (int i = 0; i < H; i++) {
		if (visited[i]) continue;

		int toNode = path.back();

		visited[i] = true;
		path.push_back(i);

		ret = min(ret, TSP(path, visited, currentLength + dist[toNode][i]));

		visited[i] = false;
		path.pop_back();
	}

	return ret;
}

void data_in() {
	FILE *f;
	int N;
	f = fopen("./Brute-force/TSP(BF)/input.txt", "r");

	fscanf(f, "%d ", &N);

	for (int i = 0; i < N; i++) {
		fscanf(f, "%d ", &H);

		memset(dist, 0, sizeof(double)*H*H);

		for (int j = 0; j < H; j++) {
			for (int k = 0; k < H; k++) {
				fscanf(f, "%lf ", &dist[j][k]);
			}
		}

		vector<int> path;
		vector<bool> visited(H, false);

		path.push_back(0);
		visited[0] = true;
		
		printf("%lf ", TSP(path, visited, 0));
	}
}

int main() {
	data_in();
}
