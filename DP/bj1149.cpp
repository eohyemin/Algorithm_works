#include <vector>
#include <iostream>
#include <algorithm>
#define MAX_SIZE 1000

using namespace std;

int n;
int idx;
vector<vector<int>> cost;
int minimum[MAX_SIZE + 1][3] = { 0, };

int calMin(int i, int j) {

	if (i == 0) {
		return minimum[i][j] = cost[i][j];
	}
	if (minimum[i - 1][(j + 1) % 3] == 0) {
		minimum[i - 1][(j + 1) % 3] = calMin(i - 1, (j + 1) % 3);
	}
	if (minimum[i - 1][(j + 2) % 3] == 0) {
		minimum[i - 1][(j + 2) % 3] = calMin(i - 1, (j + 2) % 3);
	}
	return minimum[i][j] = min(minimum[i - 1][(j + 1) % 3], minimum[i - 1][(j + 2) % 3]) + cost[i][j];

}

int main() {
	cin >> n;
	cost.resize(n);

	for (int i = 0; i < n; i++) {
		int r, g, b;
		cin >> r >> g >> b;
		vector<int> v; v.resize(3);
		v[0] = r; v[1] = g; v[2] = b;
		cost[i] = v;
	}
	
	for (int i = 0; i < 3; i++) {
		minimum[n - 1][i] = calMin(n - 1, i);
	}

	int m = min(minimum[n - 1][0], minimum[n - 1][1]);
	m = min(m, minimum[n - 1][2]);

	cout << m;

	return 0;
}