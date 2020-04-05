#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

priority_queue<int> que1; // 내림차순
priority_queue<int, vector<int>, greater<int>> que2; // 오름차순

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    for(int i=0; i<operations.size(); i++) {
        if(operations[i][0] == 'D') {
            if(que1.empty() || que2.empty()) continue;
            if(que1.top() == que2.top()) {
                priority_queue<int> empty1;
                priority_queue<int, vector<int>, greater<int>> empty2;
                swap(que1, empty1);
                swap(que2, empty2);
                continue;
            }
            
            if(operations[i] == "D 1") {
                que1.pop();
            }
            else if(operations[i] == "D -1") {
                que2.pop();
            }
            
        }
        else if(operations[i][0] == 'I') {
            string nStr = operations[i].substr(2);
            int n = stoi(nStr);
            que1.push(n);
            que2.push(n);
        }
        
    }
    if(!que1.empty() && !que2.empty()) {
        answer.push_back(que1.top());
        answer.push_back(que2.top());
    }
    else {
        answer.push_back(0);
        answer.push_back(0);
    }
    
    return answer;
}