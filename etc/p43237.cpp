#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int solution(vector<int> budgets, int M) {
    int answer = 0;
    
    long sum = 0;
    for(int i=0; i<budgets.size(); i++) {
        sum += budgets[i];
    }
    
    int start = 0;
    int end = budgets[0];
    for(int i=1; i<budgets.size(); i++) {
        if(budgets[i] > end) end = budgets[i];
    }
    if(sum <= M) {
        answer = end;
        return answer;
    }
    
    int bound;
    long minGap = M;
    while(start <= end) {
        bound = (start + end) / 2;
        
        long sum = 0;
        for(int i=0; i<budgets.size(); i++) {
            if(budgets[i] < bound) sum += budgets[i];
            else sum += bound;
        }
        if(sum <= M) {
            start = bound + 1;
        }
        else if(sum > M) {
            end = bound - 1;
        }
        long gap = M - sum;
        if(gap > 0 && gap < minGap) {
            answer = bound;
        }
    }
    
    return answer;
}