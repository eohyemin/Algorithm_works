#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> key2;
vector<vector<int>> nLock;
int n, m;

void rotate(vector<vector<int>> key) {
    key2.resize(m); 
    for(int i=0; i<key.size(); i++) {
        int k = 0;
        vector<int> v; v.resize(m);
        key2[i] = v;
        for(int j=key.size()-1; j>=0; j--) {
            key2[i][k] = key[j][i];
            k++;
        }
    }
}

void update(vector<vector<int>> lock) {
    int newSize = n + 2 * (m-1);
    nLock.resize(newSize);
    for(int i=0; i<newSize; i++) {
        vector<int> v; v.resize(newSize);
        nLock[i] = v;
        for(int j=0; j<newSize; j++) {
            if(i>=m-1 && i<=newSize-m && j>=m-1 && j<=newSize-m) {
                nLock[i][j] = lock[i-m+1][j-m+1];
            }
            else {
                nLock[i][j] = -1;
            }
        }
    }
}

bool isUnLock(vector<vector<int>> res) {
    bool flag = true;
    
    for(int i=m-1; i<=n+m-2; i++) {
        for(int j=m-1; j<=n+m-2; j++) {
            if(res[i][j] != 1) {
                flag = false; break;
            }
        }
    }
    return flag;
}

bool check() { // key2와 nLock 비교
    vector<vector<int>> res; //nLock + key2값 저장
    res.resize(nLock.size());
    for(int x=0; x<=nLock.size()-m; x++){
        for(int y=0; y<=nLock.size()-m; y++){
            for(int i=0; i<nLock.size(); i++) {
                vector<int> v; v.resize(nLock.size());
                res[i] = v;
                for(int j=0; j<nLock.size(); j++) {
                    if(i>=x && i<=x+m-1 && j>=y && j<=y+m-1) {
                        res[i][j] = nLock[i][j] + key2[i-x][j-y];
                    }
                    else res[i][j] = nLock[i][j];
                }
            }
            if(isUnLock(res)) return true;
        }
    }
    return false;
    
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    
    m = key.size();
    n = lock.size();
    
    update(lock);
    key2 = key;
    
    for(int i=0; i<4; i++) {
        if(answer = check()) break;
        key = key2;
        rotate(key);
    }
    
    return answer;
}