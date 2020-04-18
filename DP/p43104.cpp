#include <string>
#include <vector>
#include <iostream>
#define MAX_SIZE 80
using namespace std;

long long sides[MAX_SIZE+1] = {0,};

long long getSide(int N) {
    if (N==1 || N==2) {
        sides[N] = 1;
        return sides[N];
    }
    
    if(sides[N-1] == 0) sides[N-1] = getSide(N-1);
    if(sides[N-2] == 0) sides[N-2] = getSide(N-2);
    sides[N] = sides[N-1] + sides[N-2];
    return sides[N];
    
}

long long solution(int N) {
    long long answer = 0;
    
    answer = (getSide(N) + getSide(N+1)) * 2;
    
    return answer;
}