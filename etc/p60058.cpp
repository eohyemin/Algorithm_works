#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool isRight(string str) {
    int left = 0, right = 0;
    for(int i=0; i<str.size(); i++) {
        if(right > left) return false;
        if(str[i] == '(') {
            left++;
        }
        else if(str[i] == ')') {
            if(left != 0) right++;
            else return false;
        }
    }
    if(left == right) return true;
    return false;
}

void stringCat(string w, string *u, string *v) {    
    int left = 0, right = 0;
    for(int i=0; i<w.size(); i++) {
        if(w[i] == '(') left++;
        else if(w[i] == ')') right++;
        if(left == right) {
            *u = w.substr(0, i+1);
            *v = w.substr(i+1, w.size()-i-1);
            return;
        }
    }
}

string reverseStr(string str) {
    string res = "";
    for(int i=0; i<str.size(); i++) {
        if(str[i] == '(') res = res + ")";
        else if(str[i] == ')') res = res + "(";
    }
    return res;
}

string func(string w) {
    string u = "", v = "", str = "";
    if(w == "" || isRight(w)) return w;
    
    stringCat(w, &u, &v);
    
    if(isRight(u)) return u+func(v); //3번
    else { //4번
        str = "(" + func(v) + ")";
        u = u.substr(1, u.size()-2);
        u = reverseStr(u);
        str = str + u;
    }
    return str;
    
}

string solution(string p) {
    string answer = "";
    
    if(isRight(p)) answer = p;
    else answer = func(p);
    
    return answer;
}