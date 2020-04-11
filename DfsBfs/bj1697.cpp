#include <iostream>
#include <queue>
#define MAX_SIZE 100000
using namespace std;
int minSec = 0;
int chk[MAX_SIZE + 1] = { 0, };

void bfs(int n, int k) {

	queue<pair<int, int>> que;
	que.push({ n, 0 });
	chk[n] = 1;

	while (!que.empty()) {
		pair<int, int> p = que.front();
		que.pop();
		n = p.first;
		int sec = p.second;

		if (n == k) {
			minSec = sec;
			break;
		}

		if (n > 0 && chk[n - 1] == 0) {
			que.push({ n - 1, sec + 1 });
			chk[n - 1] = 1;
		}
		if (n < MAX_SIZE && chk[n + 1] == 0) {
			que.push({ n + 1, sec + 1 });
			chk[n + 1] = 1;
		}
		if (n * 2 <= MAX_SIZE && chk[n * 2] == 0) {
			que.push({ n * 2, sec + 1 });
			chk[n * 2] = 1;
		}
		
	}

}

int main() {

	int n, k;
	cin >> n >> k;

	bfs(n, k);

	cout << minSec;

	return 0;
}