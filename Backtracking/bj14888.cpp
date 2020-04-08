#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//int nums[MAX_SIZE + 1];
//int ops[MAX_SIZE];
vector<int> nums;
vector<int> ops;
int maximum, minimum, cnt = 0;

int getRes(int n) {

	//ops에서 pop하진 말고 하나씩 계산
	/*
	for (int i = 0; i < n; i++) {
		cout << ops[i] << " ";
	}
	cout << endl;
	*/
	int res = nums[0];

	for (int i = 0; i < n; i++) {
		switch (ops[i]) {
		case 1: res += nums[i + 1]; break;
		case 2: res -= nums[i + 1]; break;
		case 3: res *= nums[i + 1]; break;
		case 4: res /= nums[i + 1]; break;
		default: break;
		}
	}

	return res;
}

void pick(int start, int end) {
	if (start == end) {
		int res = getRes(end + 1);
		if (cnt == 0) {
			maximum = minimum = res; cnt++;
		}
		else {
			if (res > maximum) maximum = res;
			else if (res < minimum) minimum = res;
		}
		return;
	}

	for (int i = start; i <= end; i++) {
		swap(ops[start], ops[i]);
		pick(start + 1, end);
		swap(ops[start], ops[i]);
	}

}

int main() {
	int n;
	cin >> n; 
	nums.resize(n); 
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	
	for (int i = 1; i <= 4; i++) { // 1:+, 2:-, 3:*, 4:/ 
		int op;
		cin >> op;
		if (op > 0) {
			while (op--) {
				ops.push_back(i);
			}
		}
	}

	pick(0, n - 2);
	cout << maximum << endl;
	cout << minimum << endl;

	/*
	for (int i = 0; i < n-1; i++) {
		cout << ops[i] << " ";
	}
	*/
	return 0;
}