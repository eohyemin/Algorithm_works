#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
    while(b!=0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

long long solution(int w,int h)
{
	long long answer = 1;
    long long sub = gcd(w, h);
    
    if(w == h) {
        answer = (long long)w*h - w;
    }
    else {
        answer = (long long)w*h - ((w/sub + h/sub)*sub - sub);
    }
    
	return answer;
}