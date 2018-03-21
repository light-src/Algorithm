#include <iostream>

using namespace std;

//일반 재귀 호출
bool match(const string& w,const string& s){
	int i = 0;

	//매칭되면 값을 올린다.
	while(w[i] == s[i] || w[i] == '?' && i < s.size() && i < w.size())	i++;

	//모든 문자열의 매칭이 끝났을 때 리턴한다.
	if(i == w.size())
		if(i == s.size())
			return true;

	if(w[i] == '*'){// *이 있을 경우에는 모든 경우를 탐색한다.
		for(int skip = 0;skip + i < s.size(); skip++){
			if(match(w.substr(i + 1),s.substr(skip + i)))
				return true;
		}
	}
	//필요. 
	return false;
}

//메모이제이션
int cache[101][101];
string W,S;

int match2(int w, int s){
	
	//각각 대응되는지 판별하기
	while(W[w] == S[s] || W[w] == '?' && w < W.size() && s < S.size())
	{ 
		w++; s++;
	}
	
	//모두 대응 되어 다 읽었는 지 확인하기
	if(w == W.size())
		if(s == S.size())
			return 1;

	int *ret = &cache[w][s];
	
	//이미 계산된 부분 처리하기
	if(*ret != -1) return *ret;

	//*일경우 뒤의 모든 부분 반복하여 확인후 처리하기.
	if(W[w] == '*')
		for(int skip = 0; skip + s < S.size(); s++){
			if(match2(w+1,s+skip))
				return 1;
		}

	return 0;
}

int match3(int w, int s){
	
	//다읽었을 때
	if(w == W.size())
		if(s == S.size())
			return 1;

	int *ret = &cache[w][s];

	//하나씩 읽기
	if(W[w] == S[s] || W[w] == '?' && w < W.size() && s < S.size())
		return *ret = match3(++w,++s);
	
	//이미 계산되었을 때
	if(*ret != -1) 
		return *ret;

	//'*'이 나왔을 때
	if(W[w] == '*')
		if(match3(w+1,s) || match3(w,s+1)/*이부분이 for문을 대체할 수 있게 만든다.*/ && s < S.size())
			return 1;

	return 0;
}

//메모이제이션 시도 했으나 잘못 짰다.
//int cache[101][101];
//
//int match2(const string& w, const string& s){
//	int w_cnt = 0;
//	int s_cnt = 0;
//	
//	//매칭되면 값을 올린다.
//	while(w[w_cnt] == s[s_cnt] || w[w_cnt] == '?' && s_cnt < s.size() && w_cnt < w.size())	{
//		w_cnt++;
//		s_cnt++;
//	}
//
//	//모들 문자열의 매칭이 끝났는지 확인 후 리턴한다.
//	if(w_cnt == w.size())
//		if(s_cnt == s.size())
//			return 1;
//
//	int *ret = &cache[w_cnt][s_cnt]; 
//	//이미 처리된 계산이면 return한다.
//	if(*ret != -1)
//		return *ret;
//
//	if(w[w_cnt] == '*'){// *이 있을 경우에는 모든 경우를 탐색한다.
//		for(int skip = 0; skip + s_cnt < s.size(); skip++){
//			if(match(w.substr(w_cnt + 1),s.substr(skip + s_cnt)))
//				return 1;
//		}
//	}
//
//	return 0;
//}