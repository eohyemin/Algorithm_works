#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int visitCnt = 1;
vector<bool> visited;

bool func(vector<vector<string>> tickets, vector<string>* answer, string start) {
    
    if(visitCnt == tickets.size()) {
        answer->push_back(start);
        return true;
    }
    
    for(int i=0; i<tickets.size(); i++) {
        if(tickets[i][0] == start && !visited[i]) {
            visited[i] = true;
            answer->push_back(start);
            visitCnt++;
            bool res = func(tickets, answer, tickets[i][1]);
            if(!res) {
                visited[i] = false;
                answer->pop_back();
                visitCnt--;
            }
            else return true;
        }
    }
    return false;
    
}

vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer;
    visited.resize(tickets.size(), false);
    sort(tickets.begin(), tickets.end()); // 알파벳순 정렬
    for(int i=0; i<tickets.size(); i++) {
        if(tickets[i][0] == "ICN") {
            answer.push_back("ICN");
            visited[i] = true;
            bool res = func(tickets, &answer, tickets[i][1]);
            if(res) break;
            else {
                visited[i] = false;
                answer.pop_back();
            }
        }
    }
    
    
	return answer;
}