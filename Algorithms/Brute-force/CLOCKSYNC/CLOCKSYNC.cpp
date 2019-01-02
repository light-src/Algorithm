#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#define CLOCKNUM 16
#define SWNUM 10
#define INF 987654321

using namespace std;

int clk[CLOCKNUM];

char swtch[10][17] = {
	"xxx.............",
	"...x...x.x.x....",
	"....x.....x...xx",
	"x...xxxx........",
	"......xxx.x.x...",
	"x.x...........xx",
	"...x..........xx",
	"....xx.x......xx",
	".xxxxx..........",
	"...xxx...x...x.."
};

bool are_alined() {
	bool ret = true;

	for (int i = 0; i < CLOCKNUM; i++) {
		if (clk[i] != 12) {
			ret = false;
			break;
		}
	}

	return ret;
}

void push_sw(int sw) {

	for (int j = 0; j < CLOCKNUM; j++) {
		if (swtch[sw][j] == 'x') {
			clk[j] += 3;

			if (clk[j] >= 15)
				clk[j] -= 12;
		}
	}
}

int swtch_cnt(int sw_num) {
	//±âÀú»ç·Ê
	if (sw_num == SWNUM) return  are_alined() ? 0 : INF;

	int ret = INF;

	for (int i = 0; i < 4; i++) {

		ret = min(ret, i + swtch_cnt(sw_num + 1)); 
		push_sw(sw_num);
		
	}

	return ret;
}


void data_in() {
	
	FILE *f;
	int N;

  	f = freopen("./Brute-force/CLOCKSYNC/input.txt","r",stdin);
	
	fscanf(f, "%d ", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < CLOCKNUM; j++) {
			fscanf(f, "%d ", &clk[j]);
		}

		int min_value = swtch_cnt(0);
		printf("%d\n", min_value == INF ? 0 : min_value);
	}	
}

int main() {
	data_in();
}
