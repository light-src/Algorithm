#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N;
int W, H;
int block[4][3][2] = {
	{{0,0}, {0,1}, {1,0}},
	{{0,0}, {1,0}, {1,-1}},
	{{0,0}, {1,0}, {1,1}},
	{{0,0}, {0,1}, {1,1}}
};

bool set(int x, int y, int board[][20], int type, int delta) {

	bool ret = true;

	for (int i = 0; i < 3; i++) {
		int nxtX = x + block[type][i][1];
		int nxtY = y + block[type][i][0];

		if (nxtX < 0 || nxtX >= W || nxtY < 0 || nxtY >= H)
			ret = false;

		if ((board[nxtY][nxtX] += delta) > 1)
			ret = false;
	}

	return ret;
}

int cover_cnt(int board[][20]) {
	int nxtX = -1, nxtY = -1;
	int ret = 0;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (board[i][j] == 0) {
				nxtX = j;
				nxtY = i;
				break;
			}
		}
		if (nxtY != -1)
			break;
	}

	if (nxtX == -1) {
		return 1;
	}

	for (int i = 0; i < 4; i++) {

		if (set(nxtX, nxtY, board, i, 1)) {
			ret += cover_cnt(board);
		}

		set(nxtX, nxtY, board, i, -1);
	}

	return ret;
}

void data_in() {
	
	int board[20][20];
	
	freopen("./Brute-force/BOARDCOVER/input.txt", "r",stdin);

	scanf("%d ", &N);
	for (int i = 0; i < N; i++) {

		memset(board, 0, sizeof(int) * 20 * 20);
		
		scanf("%d %d ", &H, &W);

		for (int j = 0; j < H; j++) {
			for (int k = 0; k < W; k++) {
				char c;
				scanf("%c ", &c);

				if (c == '.')
					board[j][k] = 0;
				else if (c == '#')
					board[j][k] = 1;
			}
		}

		printf("%d\n", cover_cnt(board));
	}

}

int main() {
	data_in();
}
