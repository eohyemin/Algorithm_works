#include <iostream>
#include <vector>
#include <queue>
#define MAX_SIZE 50
using namespace std;

int arr[MAX_SIZE + 1][MAX_SIZE + 1];
int visited[MAX_SIZE + 1][MAX_SIZE + 1] = { {0,} };
int rcxy[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
vector<int> sum;
vector<int> cnt;
int n, L, R, num = 0, totalCnt = 0;
bool flag = false;

bool inRange(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < n) return true;
	return false;
}

bool checkSub(int x, int y, int nX, int nY) {
	int sub = abs(arr[x][y] - arr[nX][nY]);
	if (sub >= L && sub <= R) return true;
	return false;
}

void bfs(int x, int y) {
	queue<pair<int, int>> que;
	num++;

	que.push({ x, y });
	visited[x][y] = num;

	while (!que.empty()) {
		pair<int, int> xy = que.front();
		que.pop();
		int x = xy.first;
		int y = xy.second;

		// inRange-true, visited-0, xy와 nXnY차이가 L~R사이
		for (int i = 0; i < 4; i++) {
			int nX = x + rcxy[i][0];
			int nY = y + rcxy[i][1];

			if (inRange(nX, nY) && visited[nX][nY] == 0 && checkSub(x, y, nX, nY)) {
				flag = true;
				que.push({ nX, nY });
				visited[nX][nY] = num;
			}
		}
	}

}

void getAvg() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int tNum = visited[i][j];
			sum[tNum] += arr[i][j];
			cnt[tNum]++;
		}
	}

	for (int i = 1; i < sum.size(); i++) {
		if (sum[i]!=0 && cnt[i]!=0) {
			sum[i] /= cnt[i];
		}
			
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int tNum = visited[i][j];
			arr[i][j] = sum[tNum];
		}
	}
}

int main() {

	cin >> n >> L >> R;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	sum.resize(n*n + 1, 0);
	cnt.resize(n*n + 1, 0);

	///////////////////////////////////////

	while (true) {

		flag = false;
		num = 0;

		for (int i = 0; i < sum.size(); i++) {
			sum[i] = cnt[i] = 0;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				visited[i][j] = 0;
			}
		}
		/// 초기화
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visited[i][j] == 0) bfs(i, j);
			}
		}

		if (!flag) {
			break;
		}
		else {
			totalCnt++;
			getAvg();
			/*
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					cout << arr[i][j] << " ";
				}
				cout << endl;
			}
			cout << "---------------------" << endl;
			*/
		}
	}
	cout << totalCnt;
	return 0;
}