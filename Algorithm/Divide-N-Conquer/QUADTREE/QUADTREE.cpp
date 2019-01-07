#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

string::iterator it;

string quad_tree(string::iterator& it) {

	string ret;

	if (*it != 'x') {
		ret.push_back(*it);
		it++;
		return ret;
	}

	it++;
	
	string x;
	x.push_back('x');
	string w1 = quad_tree(it);
	string w2 = quad_tree(it);
	string w3 = quad_tree(it);
	string w4 = quad_tree(it);

	return x + w3 + w4 + w1 + w2;
}

void data_in() {

	int C;
	string quadtree;
	freopen("./Divide-N-conquer/QUADTREE/input.txt","r",stdin);

	scanf("%d ", &C);

	for (int i = 0; i < C; i++) {
		getline(cin, quadtree);

		it = quadtree.begin();
		cout << quad_tree(it) << endl;
	}
}

int main() {

	data_in();

}