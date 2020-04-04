#include <iostream>
#include <vector>
#define MAX_SIZE 1000
using namespace std;

int r, c, sec;
int airX = -1, airY = -1, airX2 = -1, airY2 = -1;
int arr[MAX_SIZE + 1][MAX_SIZE + 1];
int diffArr[MAX_SIZE + 1][MAX_SIZE + 1];
vector<pair<int, int>> rcxy;

bool inRange(int x, int y) {
	if (x < 0 || x >= r || y < 0 || y >= c || arr[x][y] == -1) return false;
	return true;
}

void diff(int x, int y) {
	if (arr[x][y] != 0 && arr[x][y] != -1) {
		int n = arr[x][y] / 5;
		int cnt = 0;
		for (int i = 0; i < 4; i++) {
			if (inRange(x + rcxy[i].first, y + rcxy[i].second)) {
				diffArr[x + rcxy[i].first][y + rcxy[i].second] += n;
				cnt++;
			}
		}
		diffArr[x][y] -= cnt * n;
	}
	if (x == r - 1 && y == c - 1) return;
	if (y == c - 1) {
		diff(x + 1, 0); return;
	}
	diff(x, y + 1);

}

void clean1() {
	int x = airX; int y = airY;
	int x2 = x, y2 = y;
	
	while(true) {
		if (x == 0 && y != c-1) y2 = y + 1;
		if (y == 0 && x != 0) x2 = x - 1;
		if (y == c - 1 && x != airX) x2 = x + 1;
		if (x == airX && y > 1) y2 = y - 1;
		if (x == airX && y == 1) break;

		if (diffArr[x][y] != -1) diffArr[x][y] = diffArr[x2][y2];
		diffArr[x2][y2] = 0;
		x = x2; y = y2;
	}
}

void clean2() {
	int x = airX2; int y = airY2;
	int x2 = x; int y2 = y;

	while (true) {
		if (x == airX2 && y == 1) break;
		if (y == 0 && x != r - 1) x2 = x + 1;
		if (x == r - 1 && y != c - 1) y2 = y + 1;
		if (y == c - 1 && x != airX2) x2 = x - 1;
		if (x == airX2 && y > 1) y2 = y - 1;
		
		if (diffArr[x][y] != -1) diffArr[x][y] = diffArr[x2][y2];
		diffArr[x2][y2] = 0;
		x = x2; y = y2;
	}
}

int main() {

	cin >> r >> c >> sec;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == -1) {
				if (airX == -1) {
					airX = i; airY = j;
				}
				else {
					airX2 = i; airY2 = j;
				}
			}
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			diffArr[i][j] = arr[i][j];
		}
	}
	rcxy.push_back({ -1, 0 }); rcxy.push_back({ 1, 0 });
	rcxy.push_back({ 0, -1 }); rcxy.push_back({ 0, 1 });
	
	for (int i = 0; i < sec; i++) {
		diff(0, 0);
		clean1();
		clean2();

		for (int j = 0; j < r; j++) {
			for (int k = 0; k < c; k++) {
				arr[j][k] = diffArr[j][k];
			}
		}
	}

	int sum = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if(diffArr[i][j] != -1) sum += arr[i][j];
		}
	}

	cout << sum;

	return 0;
}