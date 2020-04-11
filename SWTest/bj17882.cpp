#include <iostream>
#include <vector>
#define MAX_SIZE 50
using namespace std;

int N, M, T;
vector<vector<int>> rounds;
vector<vector<int>> turns;
int rcxy[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
bool visited[MAX_SIZE + 1][MAX_SIZE + 1] = { {false,} };

void inputs() {

	cin >> N >> M >> T;

	rounds.resize(N);
	turns.resize(T);

	for (int i = 0; i < N; i++) {
		vector<int> v;
		v.resize(M);
		for (int j = 0; j < M; j++) {
			cin >> v[j];
		}
		rounds[i] = v;
	}

	for (int i = 0; i < T; i++) {
		vector<int> v;
		int x, d, k;
		cin >> x >> d >> k;
		v.push_back(x); v.push_back(d); v.push_back(k);
		turns[i] = v;
	}

}

void turn(int n, int d, int k) {
	// rounds 배열의 n번째 행을 k만큼 이동시킴 

	vector<int> temps;

	if (d == 0) {
		for (int i = k; i >= 1; i--) {
			temps.push_back(rounds[n][M - i]);
		}

		for (int i = M - 1; i > k - 1; i--) {
			rounds[n][i] = rounds[n][i - k];
		}

		for (int i = k - 1; i >= 0; i--) {
			rounds[n][i] = temps[i];
		}
	}
	else if (d == 1) {
		for (int i = 0; i < k; i++) {
			temps.push_back(rounds[n][i]);
		}
		for (int i = 0; i < M - k; i++) {
			rounds[n][i] = rounds[n][i + k];
		}
		for (int i = M - k; i < M; i++) {
			rounds[n][i] = temps[i - M + k];
		}
	}

}

bool inRange(int x, int y) {
	if (x >= 0 && x < N && y >= 0 && y < M) return true;
	return false;
}

bool checkDfs(int x, int y, int n) {
	
	visited[x][y] = true;
	bool res = false;

	for (int i = 0; i < 4; i++) {
		int nX = x + rcxy[i][0];
		int nY = y + rcxy[i][1];

		if (!inRange(nX, nY)) {
			if (nY == M) nY = 0;
			if (nY == -1) nY = M - 1;
		}

		if (inRange(nX, nY) && !visited[nX][nY] && rounds[nX][nY] == n ) {
			res = true;
			
			rounds[x][y] = 0;
			rounds[nX][nY] = 0;

			checkDfs(nX, nY, n);
			
		}
	}
	return res;

}

void makeSumAndCalc() {

	int c = 0;
	int sum = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (rounds[i][j] != 0) {
				c++;
				sum += rounds[i][j];
			}
		}
	}
	float avg = (float)sum / c;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (rounds[i][j] != 0 && rounds[i][j] > avg) {
				rounds[i][j]--;
			}
			else if (rounds[i][j] != 0 && rounds[i][j] < avg) {
				rounds[i][j]++;
			}
		}
	}

}

int main() {
	
	inputs();

	for (int i = 0; i < T; i++) {
		int x, d, k;
		x = turns[i][0];
		d = turns[i][1];
		k = turns[i][2];
		
		for (int j = 0; j < N; j++) {
			if ((j + 1) % x == 0) {
				turn(j, d, k);
			}
		}

		//dfs로 체크
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				visited[i][j] = false;
			}
		}
		bool res = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (!visited[i][j] && rounds[i][j] != 0 ) {
					bool tRes = checkDfs(i, j, rounds[i][j]);
					if (tRes) res = true;
				}
			}
		}

		if (!res) { // 지운 수 0개일 때
			makeSumAndCalc();
		}

	}

	int totalSum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			totalSum += rounds[i][j];
		}
	}
	cout << totalSum;

	return 0;
}