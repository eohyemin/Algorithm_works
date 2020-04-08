#include <iostream>
#define MAX_SIZE 67
using namespace std;

__int64 arr[MAX_SIZE + 1] = { 0, };

__int64 koong(__int64 n) {
	if (arr[n] == 0) {
		if (n < 2) return arr[n] = 1;
		if (n == 2) return arr[n] = 2;
		if (n == 3) return arr[n] = 4;

		for (int i = 1; i <= 4; i++) {
			if (arr[n - i] == 0) arr[n - i] = koong(n - i);
			arr[n] += arr[n - i];
		}
	}
	return arr[n];
}

int main() {

	int cnt;
	cin >> cnt;
	while (cnt--) {
		int n;
		cin >> n;
		cout << koong(n) << endl;
	}
}