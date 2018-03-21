#include <iostream>
#define max(x,y) x > y ? x : y

//아직 이해가 잘 안간다.

using namespace std;

const long long NEGINF = numeric_limits<long long>::min();
int n, m, A[100], B[100];
int cache[101][101];

int JLIS(int idxA, int idxB) {
	//메모이제이션
	int& ret = cache[idxA + 1][idxB + 1];
	if (ret != -1) return ret;
	
	//A[idxA],B[idxB]는 존재하므로 2개는 항상 있다.
	ret = 2;
	long long a = (idxA == -1 ? NEGINF : A[idxA]);
	long long b = (idxB == -1 ? NEGINF : B[idxB]);
	long long maxElement = max(a, b);

	//다음원소를 찾는다
	for (int nxtA = idxA + 1; nxtA < n; ++nxtA)
		if (maxElement < A[nxtA])
			ret = max(ret, JLIS(nxtA, idxB) + 1);
	for (int nxtB = idxB + 1; nxtB < m; ++nxtB)
		if (maxElement < B[nxtB])
			ret = max(ret, JLIS(idxA, nxtB));

	return ret;
}