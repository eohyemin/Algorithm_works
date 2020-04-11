#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<char> strs;

int solution(string s) {
    int answer = 0;
    
    for(int i=0; i<s.size(); i++) {
        if(strs.empty()) strs.push(s[i]);
        else {
            char c = strs.top();
            if(c == s[i]) strs.pop();
            else strs.push(s[i]);
        }
    }
    if(strs.empty()) answer = 1;
    
    return answer;
}