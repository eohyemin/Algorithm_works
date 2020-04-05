#include <iostream>
#define MAX_SIZE 15
using namespace std;

int n;
int totalCnt;
int columnChk[MAX_SIZE + 1] = { 0, };
int incLineChk[MAX_SIZE * 2 + 1] = { 0, };
int decLineChk[MAX_SIZE * 2 + 1] = { 0, };

void nQueen(int row) {
	if (row == n + 1) {
		totalCnt++; return;
	}
	for (int i = 1; i <= n; i++) {
		if (columnChk[i] == 0 && incLineChk[i+row] == 0 && decLineChk[n+row-i] == 0) {
			columnChk[i] = 1; incLineChk[i + row] = 1; decLineChk[n + row - i] = 1;
			nQueen(row + 1);
			columnChk[i] = 0; incLineChk[i + row] = 0; decLineChk[n + row - i] = 0;
		}
	}
}

int main() {

	cin >> n;

	nQueen(1);

	cout << totalCnt;

}