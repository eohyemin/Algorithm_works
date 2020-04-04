#include <iostream>
#include <vector>
#define MAX_SIZE 20
using namespace std;

int n, minSub = 1000;
int s[MAX_SIZE + 1][MAX_SIZE + 1];

void func(vector<int> picked, int toPick) {
	if (toPick == 0) {
		int startSum = 0, linkSum = 0;
		vector<int> restPick;
		
		int i = 0, c = 1;
		while (c <= n) {
			if (i<picked.size() && picked[i] == c) i++;
			else restPick.push_back(c); 
			c++;
		}
		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				if (i != j) {
					startSum += s[picked[i]][picked[j]];
					linkSum += s[restPick[i]][restPick[j]];
				}
			}
		}
		minSub = minSub > abs(startSum - linkSum) ? abs(startSum - linkSum) : minSub;
		return;
	}
	int smallest = picked.empty() ? 0 : picked.back() + 1;
	
	for (int i = smallest; i <= n; i++) {
		picked.push_back(i);
		func(picked, toPick - 1);
		picked.pop_back();
	}

}

int main() {

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> s[i][j];
		}
	}
	vector<int> picked;
	picked.push_back(1);
	func(picked, n / 2 - 1);
	cout << minSub;

	return 0;
}