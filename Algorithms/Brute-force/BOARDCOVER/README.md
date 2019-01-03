#BOADCOVER

##문제 링크
<https://algospot.com/judge/problem/read/BOARDCOVER>

##해설
게임판을 덮는 모든 경우를 생성하는 완전 탐색을 이용해 해결할 수 있다.  
하지만 모든 칸을 어떻게 덮느냐를 생각하는 게 중요하다.  
여기서는 모든 칸을 왼쪽 위에서부터 순서대로 두어서 완전 탐색을 가능하게 했다.  

```c++
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
``` 

세부적으로 눈에띄는 아이디어는 set함수를 두고 delta를 이용해 블록이 덮어지고,  
들어내어지는 과정을 한번에 처리하여 코드를 간결하게 한 것이다.
```c++
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
```