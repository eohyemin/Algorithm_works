#include <iostream>
#define MAX_SIZE 100
using namespace std;

long long nums[MAX_SIZE + 1] = { 0, };

long long func(int n) {

	if (n <= 3) {
		return nums[n] = 1;
	}
	if (nums[n]) return nums[n];
	
	if (nums[n - 3] == 0) func(n - 3);
	if (nums[n - 2] == 0) func(n - 2);

	return nums[n] = nums[n - 3] + nums[n - 2];
	
}

int main() {
	int testCnt, n;
	cin >> testCnt;

	while(testCnt--) {
		cin >> n;
		cout << func(n) << endl;
	}

	return 0;
}