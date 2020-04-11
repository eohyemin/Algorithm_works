#include <string>
#include <vector>
#include <iostream>
using namespace std;

int res = 0;

void dfs(vector<int> numbers, int target, int idx, int sum) {
    if(idx == numbers.size()) {
        if(sum == target) res++;
        return;
    }
    
    dfs(numbers, target, idx+1, sum+numbers[idx]);
    dfs(numbers, target, idx+1, sum-numbers[idx]);
    
}

int solution(vector<int> numbers, int target) {
	int answer = 0;
   
    dfs(numbers, target, 0, 0);
    answer = res;
	return answer;
}