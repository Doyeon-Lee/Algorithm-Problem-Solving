#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = -1; //친구들을 모두 투입해도 취약 지점을 전부 점검할 수 없는 경우에는 -1을 return 해주세요!!!!!!!!!!!!!!!!!
    //순열 사용을 위해 오름차순 정렬
    sort(dist.begin(), dist.end());
    int s = dist.size();
    int ws = weak.size();
    
    //친구들을 같은 방향으로 보내면 원형을 일직선으로 만들 수 있다
    //첫 인덱스를 뒤에 추가할 때 n만큼 더해주면 된다
    for(int i = 0;i < ws;i++){
        weak.push_back(weak[0] + n);
        auto iter = weak.begin();
        weak.erase(iter);

        //친구들의 모든 경우를 순열로 탐색하며 가장 적은 값을 찾아낸다; 백트래킹
        do{
            int cnt = 0; //친구 수
            int w = 0; //weak의 인덱스
          
            for(int j = 0;j < s;j++){
                cnt++;
                int val = weak[w] + dist[j];
                
                while(w < ws && val >= weak[w])
                    w++;
                if(w == ws) break;
            }
    
            if(w == ws && (answer == -1 || answer > cnt)) answer = cnt;
        
        }while(next_permutation(dist.begin(),dist.end()));
    }

    return answer;
}