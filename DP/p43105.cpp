#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    vector<vector<int>> sum;
    sum.resize(triangle.size());
    
    for(int i=0; i<triangle.size(); i++) {
        vector<int> v;
        v.resize(i+1, 0);
        if(i == 0) v[0] = triangle[0][0];
        if(i == 1) {
            v[0] = triangle[0][0] + triangle[1][0];
            v[1] = triangle[0][0] + triangle[1][1];
        }
        if(i > 1) {
            v[0] = sum[i-1][0] + triangle[i][0];
            v[i] = sum[i-1][i-1] + triangle[i][i];
            for(int j=1; j<i; j++) {
                v[j] = max(sum[i-1][j-1], sum[i-1][j]) + triangle[i][j];
            }
        }
        sum[i] = v;
    }
    
    vector<int> v = sum[sum.size()-1];
    answer = v[0];
    for(int i=1; i<v.size(); i++) {
        answer = max(answer, v[i]);
    }
    
    return answer;
}