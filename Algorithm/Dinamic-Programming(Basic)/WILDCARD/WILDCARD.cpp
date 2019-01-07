#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <queue>
#include <string.h>
#include <algorithm>
#define MAX 50
using namespace std;

string pattern;
string word;
vector<string> q;
int cache[MAX][MAX];

//int wild_card(int i, int j) {
//
//	int& ret = cache[i][j];
//	if (ret != -1)
//		return ret;
//	
//	ret = 0;
//
//	if (i == pattern.size()) 
//		return ret = (j == word.size());
//
//	if (pattern[i] == word[j] || pattern[i] == '?')
//		return ret += wild_card(i + 1, j + 1);
//	
//	if (pattern[i] == '*') {
//		for (int k = 0; j + k <= word.size(); k++)
//			ret += wild_card(i + 1, j + k);
//	}
//
//	return ret;
//}

int wild_card(int w, int s) {
	int& ret = cache[w][s];
	if (ret != -1)
		return ret;

	while (w < pattern.size() && s < word.size() && (pattern[w] == '?' || pattern[w] == word[s])) {
		++w;
		++s;
	}

	if (w == pattern.size()) return ret = (s == word.size());

	if(pattern[w] == '*')
		for (int sk = 0; sk + s <= word.size(); sk++) {
			if (wild_card(w + 1, s + sk))
				return ret = 1;
		}

	return ret = 0;
}

void data_in() {
	int N;

	freopen("./Dinamic-Programming(Basic)/WILDCARD/input.txt", "r", stdin);

	scanf("%d ", &N);

	for (int i = 0; i < N; i++) {
		int M;
		
		getline(cin, pattern);

		scanf("%d ", &M);

		for (int j = 0; j < M; j++) {
			memset(cache, -1, sizeof(int)*MAX*MAX);
			getline(cin, word);
			string result = wild_card(0, 0) > 0 ? word + "\n" : "";
			if (result != "")
				q.push_back(result);
		}
		sort(q.begin(), q.end());
		for (int j = 0; j < q.size(); j++) {
			cout << q[j];
		}
		q.erase(q.begin(), q.end());
	}
}

int main() {
	data_in();
}