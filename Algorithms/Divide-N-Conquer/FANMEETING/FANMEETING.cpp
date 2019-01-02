#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#define MAX 200000

using namespace std;
//karatsuba
void normalize(vector<int>& num) {

	num.push_back(0);

	for (int i = 0; i < num.size(); i++) {

		if (num[i] < 0) {
			int borrow = ceil((float)abs(num[i]) / 10);
			num[i + 1] = borrow;
			num[i] += borrow * 10;
		}

		if (num[i] > 10) {
			num[i + 1] += num[i] / 10;
			num[i] %= 10;
		}
	}

	while (num.size() > 1 && num.back() == 0) num.pop_back();
}
void addTo(vector<int>& a, const vector<int>& b, int k) {

	if (b.size() + k > a.size()) {
		for (int i = 0; i < b.size() + k - a.size(); i++)
			a.push_back(0);
	}

	for (int i = k, j = 0; i < a.size(); i++, j++) {
		a[i] += b[j];
	}
	//normalize(a);

	//while (a.size() > 1 && a.back() == 0) a.pop_back();
}
void subFrom(vector<int>& a, vector<int>& b) {

	for (int i = 0; i < b.size(); i++) {
		a[i] -= b[i];
	}
	//normalize(a);

	//while (a.size() > 1 && a.back() == 0) a.pop_back();
}
vector<int> multiply(const vector<int>& a, const vector<int>& b) {
	vector<int> c(a.size() + b.size() + 1, 0);

	for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < b.size(); j++) {
			c[i + j] += a[i] * b[j];
		}

	//normalize(c);

	return c;
}
vector<int> karatsuba(const vector<int>& a, const vector<int>& b) {
	int an = a.size(), bn = b.size();

	if (an < bn) return karatsuba(b, a);

	if (an == 0 || bn == 0) return vector<int>();

	if (an <= 50) return multiply(a, b);

	int half = an / 2;

	vector<int> a0(a.begin(), a.begin() + half);
	vector<int> a1(a.begin() + half, a.end());
	vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
	vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());

	vector<int> z2 = karatsuba(a1, b1);
	vector<int> z0 = karatsuba(a0, b0);

	addTo(a0, a1, 0);
	addTo(b0, b1, 0);

	vector<int> z1 = karatsuba(a0, b0);
	subFrom(z1, z0);
	subFrom(z1, z2);

	vector<int>ret;
	addTo(ret, z0, 0);
	addTo(ret, z1, half);
	addTo(ret, z2, half + half);
	return ret;
}
//karatsuba end

void str_to_int_arr(const string hyper, const string fan, vector<int>& hyper_val, vector<int>& fan_val) {

	int H = hyper.size();
	int F = fan.size();

	hyper_val = vector<int>(H);
	fan_val = vector<int>(F);

	for (int i = H-1, j = 0; i >= 0; i--, j++) hyper_val[i] = (hyper[j] == 'M');
	for (int i = 0; i < F; i++) fan_val[i] = (fan[i] == 'M');

}

int hug_cnt(vector<int> hyper, vector<int> fan) {

	vector<int> result = karatsuba(hyper, fan);
	int all_hug = 0;

	for (int i = hyper.size() - 1; i < fan.size(); i++) {
		
		if (result[i] == 0)
			all_hug++;
	}

	return all_hug;
}

void data_in() {
	FILE  *f;
	int N;
	string hyper;
	string fan;

	f = freopen("./Divide-N-Conquer/FANMEETING/input.txt", "r", stdin);

	scanf("%d ", &N);

	for (int i = 0; i < N; i++) {
		cin >> hyper;
		cin >> fan;

		vector<int> hyper_val,fan_val;
		str_to_int_arr(hyper, fan, hyper_val, fan_val);
		int res = hug_cnt(hyper_val, fan_val);
		printf("%d\n", res);
	}

}

int main() {
	data_in();
}