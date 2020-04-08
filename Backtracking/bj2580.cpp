#include <iostream>
#include <vector>
#define MAX_SIZE 9
using namespace std;

int arr[MAX_SIZE + 1][MAX_SIZE + 1];
vector<pair<int, int>> saveZero;

bool chk(int x, int y, int n) {

	for (int i = 0; i < MAX_SIZE; i++) {
		if (i != y && arr[x][i] == n) return false;
	}

	for (int i = 0; i < MAX_SIZE; i++) {
		if (i != x && arr[i][y] == n) return false;
	}

	int rX = x % 3;
	int rY = y % 3;

	for (int i = x - rX; i <= x - rX + 2; i++) {
		for (int j = y - rY; j <= y - rY + 2; j++) {
			if (arr[i][j] == n) return false;
		}
	}
	return true;

}

void print() {
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void func(int n) {

	pair<int, int> xy = saveZero[n];

	int x = xy.first;
	int y = xy.second;

	
	for (int i = 1; i <= 9; i++) {
		if (chk(x, y, i)) {
			arr[x][y] = i;
			if (n == saveZero.size() - 1) {
				print();
				return;
			}
			func(n+1);
			arr[x][y] = 0;
		}
	}
	
}

int main() {

	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) saveZero.push_back({ i, j });
		}
	}
	
	func(0);
	
	return 0;
}