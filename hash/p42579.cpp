#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

typedef struct {
    int totalPlays;
    string genre;
} tPlays;

vector<tPlays> musicPlays; 
map<string, vector<pair<int, int>>> music; // genre, plays, idx

bool desc(tPlays x, tPlays y) {
    return x.totalPlays > y.totalPlays;
}

bool comp(pair<int, int> x, pair<int, int> y) {
    if(x.first > y.first) return true;
    if(x.first == y.first && x.second < y.second) return true;
    return false;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    for(int i=0; i<plays.size(); i++) {
        music[genres[i]].push_back({plays[i], i});
        bool flag = false;
        for(int j=0; j<musicPlays.size(); j++) {
            if(musicPlays[j].genre == genres[i]) {
                flag = true;
                musicPlays[j].totalPlays += plays[i];
                break;
            }
        }
        if(!flag) {
            musicPlays.push_back({plays[i], genres[i]});
        }
    }
    sort(musicPlays.begin(), musicPlays.end(), desc);
    
    map<string, vector<pair<int, int>>>::iterator it;
    
    for(int i=0; i<musicPlays.size(); i++) {
        string genre = musicPlays[i].genre;
        it = music.find(genre);
        
        vector<pair<int, int>> v = it->second;
        sort(v.begin(), v.end(), comp);
        answer.push_back(v[0].second);
        if(v.size() >=2 )
            answer.push_back(v[1].second);
    }
    
    return answer;
}