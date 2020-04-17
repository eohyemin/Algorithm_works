#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> nums;
    
    for(int i=1; i<=n; i++) {
        nums.push_back(i);
    }
    
    long long fact = 1;
    for(int i=1; i<=n; i++) {
        fact *= i;
    }
    
    while(n>0) {
        fact /= n--;
        int q = (int)(k / fact);
        int r = (int)(k % fact);
        if(r == 0) { 
            q--;
            answer.push_back(nums[q]);
            nums.erase(nums.begin() + q);
            break;
        }
        
        answer.push_back(nums[q]);
        nums.erase(nums.begin() + q);
        k %= fact;
    }
    
    for(int i=nums.size()-1; i>=0; i--) {
        answer.push_back(nums[i]);
    }
    
    return answer;
}