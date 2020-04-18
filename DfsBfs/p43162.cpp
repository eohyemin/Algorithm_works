#include <string>
#include <vector>
using namespace std;

vector<int> visited;

void dfs(int row, int n, vector<vector<int>> computers) {
    
    visited[row] = 1;
    
    for(int i=0; i<n; i++) {
        if(i != row && computers[row][i] && !visited[i]) {
            dfs(i, n, computers);
        }
    }
    
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    visited.resize(n, 0);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(computers[i][j] && !visited[i]) {
                dfs(i, n, computers); answer++;
            }
        }
    }
    
    return answer;
}