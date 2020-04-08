#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<string> bn1;
vector<string> bn2;

void decToBinary(vector<int> arr1, vector<int> arr2) {
    
    for(int i=0; i<arr1.size(); i++) {
        int n = arr1[i];
        string str = "";
        
        while(n != 0) {
            int p = n / 2;
            str = to_string(n % 2) + str;
            n = p;
        }
        
        while(str.size() < arr1.size()) {
            str = "0" + str;
        }
        str.resize(arr1.size());
        bn1.push_back(str);
    }
    
    for(int i=0; i<arr2.size(); i++) {
        int n = arr2[i];
        string str = "";
        
        while(n != 0) {
            int p = n / 2;
            str = to_string(n % 2) + str;
            n = p;
        }
        
        while(str.size() < arr2.size()) {
            str = "0" + str;
        }
        str.resize(arr2.size());
        bn2.push_back(str);
    }
    
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    decToBinary(arr1, arr2);
    
    for(int i=0; i<n; i++) {
        string str = "";
        for(int j=0; j<n; j++) {
            int n1 = bn1[i][j] - '0';
            int n2 = bn2[i][j] - '0';
            
            if(n1 || n2) str += "#";
            else str += " ";
        }
        answer.push_back(str);
    }
    
    return answer;
}