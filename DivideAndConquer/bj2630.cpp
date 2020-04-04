#include <iostream>
#define MAX_SIZE 128
using namespace std;

int n;
int wTotal, bTotal;
int arr[MAX_SIZE + 1][MAX_SIZE + 1];

void divide(int x, int y, int size) {

	bool flag = true; 
	int tmp = arr[x][y];
	for (int i = x; i < x+size; i++) {
		for (int j = y; j < y+size; j++) {
			if (arr[i][j] != tmp) {
				flag = false; break;
			}
		}
	}

	if (flag && !tmp) {
		wTotal++; return;
	}
	if (flag && tmp) {
		bTotal++; return;
	}

	if (!flag) {
		divide(x, y, size / 2);
		divide(x, y + size / 2, size / 2);
		divide(x + size / 2, y + size / 2, size / 2);
		divide(x + size / 2, y, size / 2);
	}

}

int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	divide(0, 0, n);

	cout << wTotal << endl << bTotal << endl;

}