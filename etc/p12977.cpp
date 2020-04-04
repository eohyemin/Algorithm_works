#include <vector>
#include <iostream>
using namespace std;

int totalSum;
void pick(vector<int> picked, vector<int> nums, int toPick) {
	if(toPick == 0) {
		int sum = 0;
		for(int i=0; i<picked.size(); i++) {
			sum += picked[i];
		}
		bool flag = true;
		for(int i=2; i<sum; i++) {
			if(sum%i == 0) {
				flag = false; break;
			}
		}
		if(flag) totalSum++;
		return;
	}
	int smallest = 0;
	for(int i=0; i<nums.size(); i++) {
    if(!picked.empty() && nums[i] == picked.back()) {
	    smallest = i+1; break;
    }
	}
	for(int next = smallest; next<nums.size(); next++) {
    picked.push_back(nums[next]);
    pick(picked, nums, toPick-1);
    picked.pop_back();
	}
}

int solution(vector<int> nums) {
	int answer = -1;
	vector<int> picked;
	pick(picked, nums, 3);

	answer = totalSum;
	return answer;
}