#include <string>
#include <vector>
#include <queue>
using namespace std;
vector<int> visited;

int bfs(string begin, string target, vector<string> words) {
    queue<string> que;
    
    for(int i=0; i<words.size(); i++) {
        int diff = 0;
        for(int j=0; j<words[i].size(); j++) {
            if(begin[j] != words[i][j]) diff++;
        }
        if(diff == 1) {
            que.push(words[i]);
            visited[i] = 1;
        }
    }
    
    while(!que.empty()) {
        
        begin = que.front();
        que.pop();
        int cnt = 0;
        for(int i=0; i<words.size(); i++) {
            if(words[i] == begin) {
                cnt = visited[i]; break;
            }
        }
        if(begin == target) {
            return cnt;
        }
        
        for(int i=0; i<words.size(); i++) {
            int diff = 0;
            for(int j=0; j<words[i].size(); j++) {
                if(begin[j] != words[i][j]) diff++;
            }
            if(diff == 1 && visited[i] == 0) {
                que.push(words[i]);
                visited[i] = cnt+1;
            }
        }
    }
    return 0;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    visited.resize(words.size(), 0);
    
    // words에 target 존재하지 않으면 0 return
    bool flag = false;
    for(int i=0; i<words.size(); i++) {
        if(words[i] == target) {
            flag = true; break;
        }
    }
    if(!flag) return answer;
    
    answer = bfs(begin, target, words);
    
    return answer;
}