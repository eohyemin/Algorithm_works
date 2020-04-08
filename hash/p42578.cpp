#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> clothMap;
    
    int res = clothes.size();
    for(int i=0; i<clothes.size(); i++) {
        vector<string> cloth = clothes.at(i);
        
        map<string, int>::iterator iter;
        if((iter = clothMap.find(cloth[1])) == clothMap.end()) {         
            clothMap.insert(make_pair(cloth[1], 1));
        }
        else {
            int cnt = clothMap[cloth[1]];
            cnt++;
            clothMap[cloth[1]] = cnt;
        }
    }
    
    for(auto iter = clothMap.begin(); iter!=clothMap.end(); iter++) {
        answer *= clothMap[iter->first]+1;
    }
    answer--;
    
    return answer;
}