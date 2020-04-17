#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> visited;
int rcxy[4][2];
int cnt;

bool inRange(int x, int y, int m, int n) {
    if(x>=0 && x<m && y>=0 && y<n) return true;
    return false;
}

void dfs(int x, int y, vector<vector<int>> picture) {
    
    visited[x][y] = 1;
    int m = picture.size();
    int n = picture[0].size();
    int num = picture[x][y];
    
    for(int i=0; i<4; i++) {
        int nX = x + rcxy[i][0];
        int nY = y + rcxy[i][1];
        if(inRange(nX, nY, m, n) && picture[nX][nY] == num && visited[nX][nY] == 0) {
            visited[nX][nY] = 1; cnt++;
            dfs(nX, nY, picture);
        }
    }
    
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    visited.resize(m);
    for(int i=0; i<m; i++) {
        vector<int> v; v.resize(n, 0);
        visited[i] = v;
    }
    rcxy[0][0] = -1; rcxy[0][1] = 0;
    rcxy[1][0] = 1; rcxy[1][1] = 0;
    rcxy[2][0] = 0; rcxy[2][1] = -1;
    rcxy[3][0] = 0; rcxy[3][1] = 1;
    
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(picture[i][j] > 0 && visited[i][j] == 0) {
                number_of_area++; cnt = 1;
                dfs(i, j, picture);
                //cout << cnt << endl;
                max_size_of_one_area = (cnt > max_size_of_one_area) ? cnt : max_size_of_one_area;
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}