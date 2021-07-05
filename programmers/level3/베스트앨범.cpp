/*
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct music{
    int total_play = 0;
    vector<pair<int, int>> plays;
};

bool music_compare(struct music &a, struct music &b){
    return a.total_play > b.total_play;
}

bool pair_compare(pair<int, int> &a, pair<int, int> &b){
    if(a.first == b.first)
        return a.second < b.second;
    else return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, music> m;
    struct music Music;
    
    //map에 데이터 삽입
    for(int i = 0;i < genres.size();i++){
        Music = m[genres[i]];
        if(Music.total_play){
            Music = m[genres[i]];
            Music.total_play += plays[i];
            Music.plays.push_back(make_pair(plays[i], i));
            m[genres[i]] = Music;
        }
        else{ //처음 보는 장르이면
            Music.total_play = plays[i];
            Music.plays.push_back(make_pair(plays[i], i));
            m[genres[i]] = Music;
        }
    }
    
    //vector로 변환하여 정렬
    vector<music> v;
    for(auto iter =  m.begin();iter != m.end();iter++)
        v.push_back(iter->second);
    
    sort(v.begin(), v.end(), music_compare);

    //총합과 각 장르별 재생수로 정렬
    for(int i = 0;i < v.size();i++){
        sort(v[i].plays.begin(), v[i].plays.end(), pair_compare);
        answer.push_back(v[i].plays[0].second);
        if(v[i].plays.size() > 1) answer.push_back(v[i].plays[1].second);
    }

    return answer;
}
*/

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <utility>

using namespace std;
bool compare (pair<int, int> left, pair<int, int> right){
    if(left.first > right.first){
        return true;
    }else if(left.first == right.first){
        if(left.second < right.second){
            return true;
        }
    }
    return false;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> summap;
    unordered_map<string, vector<pair<int, int>>> genmap;
    for (int i = 0; i < genres.size(); i++) {
        summap[genres[i]] += plays[i];
        genmap[genres[i]].push_back(make_pair(plays[i], i));
    }
    vector<pair<int, string>> fororder;
    for (auto x : summap) {
        fororder.push_back(make_pair(x.second, x.first));
    }
    sort(fororder.begin(), fororder.end());
    while (fororder.size() > 0) {
        pair<int, string> temp= fororder.back();
        fororder.pop_back();
        vector<pair<int, int>> a = genmap[temp.second];
        sort(a.begin(), a.end(), compare);
        int lastn = 2;
        if (a.size() < 2) {
            lastn = a.size();
        }
        for (int i = 0; i < lastn; i++) {
            answer.push_back(a[i].second);
        }
    }

    return answer;
}