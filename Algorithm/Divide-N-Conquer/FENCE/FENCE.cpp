#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 20000

using namespace std;

int N;
int height[MAX];

int FENCE(int start, int end) {
	int ret;

	if (start == end)
		return height[start];

	int mid = (start + end) / 2;
	ret = max(FENCE(start, mid), FENCE(mid + 1, end));

	int left, right;
	left = mid;
	right = mid + 1;

	int max_height = min(height[left], height[right]);

	int width = 2;

	while (true) {
		int rectangle = max_height * width++;

		ret = max(ret, rectangle);
		
		if (left > start && right < end)
		{
			max_height = height[left - 1] > height[right + 1] ?
				min(max_height, height[--left]) : min(max_height, height[++right]);
		}
		else if (left > start) {
			max_height = min(max_height,height[--left]);
		}
		else if (right < end) {
			max_height = min(max_height, height[++right]);
		}
		else
			break;
	}

	return ret;
}

void data_in(){
	int C;

	freopen("./Divide-N-conquer/FENCE/input.txt", "r", stdin);

	scanf("%d ",&C);

	for (int i = 0; i < C; i++) {
		
		memset(height, 0, sizeof(int) * MAX);

		scanf("%d ", &N);

		for (int j = 0; j < N; j++) {
			scanf("%d ",&height[j]);
		}

		printf("%d ", FENCE(0, N-1));
	}


}

int main() {
	data_in();
}