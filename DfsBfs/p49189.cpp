#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> cnt;

void dfs(int n, int dist) {
    
    cnt[n] = (cnt[n] == 0 ? dist : min(dist, cnt[n]));
    visited[n] = true;
    vector<int> v = graph[n];
    for(int i=0; i<v.size(); i++) {
        if(!visited[v[i]] || dist+1<cnt[v[i]]) {
            dfs(v[i], dist+1);
        }
    }
    
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    graph.resize(n+1);
    visited.resize(n+1, false);
    cnt.resize(n+1, 0);
    
    for(int i=0; i<edge.size(); i++) {
        graph[edge[i][0]].push_back(edge[i][1]);
		graph[edge[i][1]].push_back(edge[i][0]);
    }
    dfs(1, 0);
    
    int max = 0;
    for(int i=1; i<=n; i++) {
        if(cnt[i] > max) {
            max = cnt[i]; answer = 1;
        }
        else if(cnt[i] == max) {
            answer++;
        }
    }
    
    return answer;
}