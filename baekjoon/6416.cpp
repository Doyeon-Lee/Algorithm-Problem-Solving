#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

bool isTree(set<int> &s){

}

int main(){
    int T = 1;
    int u, v; //u -> v
    string str = "";
    int node_cnt = 0;
    int edge_cnt = 0;
    set<int> s;

    while(1){ 
        scanf("%d%d", &u, &v);
        if(u == 0){
            str = node_cnt == edge_cnt + 1 ? "" : " not";
            printf("Case %d is%s a tree.\n", T, str.c_str());

            s.clear();
            node_cnt = edge_cnt = 0;
            T++;
        }
        else if(u < 0) return 0; //음의 정수가 주어지면

        //트리 만들기
        if(s.find(u) == s.end()){
            s.insert(u);
            node_cnt++;
        }
        edge_cnt++;
    }
}