#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> mem;

int tile(int num) {
	if (num == 1 || num == 2) return mem[num] = num;

	if (mem[num - 2] == 0) mem[num-2] = tile(num - 2);
	if (mem[num - 1] == 0) mem[num - 1] = tile(num - 1);
	mem[num] = mem[num - 2] + mem[num - 1];
	return mem[num] %= 15746;
}

int main() {
	cin >> n;
	mem.resize(n+1, 0);

	int res = tile(n);
	cout << res;

	return 0;
}