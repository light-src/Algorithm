#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 2000000000 + 1;

int n;
int cacheLen[501], cacheCnt[501], S[500];

int lis(int start) {

	int &ret = cacheLen[start + 1];
	if (ret != -1)
		return ret;

	ret = 1;
	for (int i = start + 1; i < n; i++) {
		if (start == -1 || S[start] < S[i])
			ret = max(ret, lis(i) + 1);
	}

	return ret;
}

int count(int start) {

	if (lis(start) == 1) return 1;

	int &ret = cacheCnt[start];
	if (ret != -1)
		return ret;

	ret = 0;

	for (int i = start + 1; i < n; i++) {
		if ((start == -1 || S[start] < S[i]) && lis(start) == lis(i) + 1)
			ret = min<long long>(MAX, (long long)ret + count(i));
	}

	return ret;
}

void reconstruct(int idx, vector<int> seq, int skip) {

	if (idx == n)
		return;

	for (int i = idx + 1; i < n; i++) {
		if ((idx == -1 || S[idx] < S[i]) && lis(idx) == lis(i) + 1) {
			skip -= skip > count(i) ? count(i) : 0;
		}
	}


	
}