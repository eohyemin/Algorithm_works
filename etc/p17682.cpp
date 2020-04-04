#include <string>
#include <cmath>
#include <vector>

using namespace std;

int solution(string dartResult) {
	int answer = 0;

	vector<int> nums;
	nums.resize(3, 0);

	int idx = -1;

	for(int i=0; i<dartResult.size(); i++) {
    
    if(dartResult[i] >= '0' && dartResult[i] <= '9') {
	      idx++;
        if(dartResult[i+1] == '0') {
            nums[idx] = 10; i++;
        }
        else {
            nums[idx] = dartResult[i] - '0';
        }
    }
    else if(dartResult[i] == 'D') {
        nums[idx] = pow(nums[idx], 2);
    }
    else if(dartResult[i] == 'T') {
        nums[idx] = pow(nums[idx], 3);
    }
    else if(dartResult[i] == '*') {
        if(idx == 0) {
            nums[idx] = nums[idx] * 2;
        }
        else {
            nums[idx-1] = nums[idx-1] * 2;
            nums[idx] = nums[idx] * 2;
        }
    }
    else if(dartResult[i] == '#') {
        nums[idx] = nums[idx] * (-1);
    }
	}
	for(int i=0; i<nums.size(); i++) {
    answer += nums[i];
	}
	return answer;
}