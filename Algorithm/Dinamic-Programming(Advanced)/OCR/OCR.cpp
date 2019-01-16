#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

int m, q, n;
vector<char*> origin_words;
vector<int> optical_words;
float first_prob[501];
float i_after_j_prob[501][501];
float i_misu_j_prob[501][501];

float cache[501][501];
int choice[501][501];

float most_like(int prev, int idx) {

	if (idx == n)
		return 0;

	float &ret = cache[prev][idx];
	if (ret != 1.0)
		return ret;

	ret = -1e200;

	int &choose = choice[prev][idx];

	for (int i = 0; i < m; i++) {
		float cand = 
	}

}

void data_in() {

	freopen("./Dinamic-Prgramming(Advanced)/OCR/input.txt", "r", stdin);

	scanf("%d %d ", &m, &q);

	for (int i = 0; i < m; i++) {
		char word[11];
		scanf("%s ", word);
		origin_words.push_back(word);
	}

	for (int i = 0; i < m; i++) {
		scanf("%f ", &first_prob[i]);
	}

	for (int i = 0; i < m; i++) 
		for (int j = 0; j < m; j++) 
			scanf("%f ", &i_after_j_prob[i][j]);
		
	for (int i = 0; i < m; i++) 
		for (int j = 0; j < m; j++) 
			scanf("%f ", &i_misu_j_prob[i][j]);
		
	for (int i = 0; i < q; i++) {
		scanf("%d ", &n);

		for (int j = 0; j < n; j++) {
			char word[11];
			int k;

			scanf("%s ", word);

			for (k = 0; k < origin_words.size(); k++)
				if (strcmp(word, origin_words[k]) == 0)
					break;

			optical_words.push_back(k);
		}
	}



}

int main() {

	data_in();

}