#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
//#include <string.h>
#define MAX 50
using namespace std;

string pattern;
string word;
int cache[MAX][MAX];

int wild_card(int i, int j) {

	if (j > word.size() || i > pattern.size())
		return 0;

	if (!pattern[i] && !word[j])
		return 1;

	if (pattern[i] == '?' || pattern[i] == word[j])
		return wild_card(i + 1, j + 1);

	if (pattern[i] != word[j] && pattern[i] != '*')
		return 0;

	int &ret = cache[i][j];
	if (ret != -1)
		return ret;

	//pattern[i] 값이 *일때
	for (int k = j + 1; k < word.size(); k++) {
		ret |= wild_card(i, k) || wild_card(i + 1, k);
	}

	return ret;
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
			cout << result;
		}
	}
}

int main() {
	data_in();
}