#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> stairs;
vector<int> visited;

void visit() {
	
	visited[0] = stairs[0];
	visited[1] = stairs[0] + stairs[1];
	visited[2] = max(stairs[0] + stairs[2], stairs[1] + stairs[2]);

	for (int i = 3; i < n; i++) {
		visited[i] = max(visited[i - 2] + stairs[i], visited[i - 3] + stairs[i - 1] + stairs[i]);
	}

}

int main() {

	cin >> n;

	stairs.resize(n, 0);
	visited.resize(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> stairs[i];
	}
	visit();
	cout << visited[n-1];

	return 0;
}