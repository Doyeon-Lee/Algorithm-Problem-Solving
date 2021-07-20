#include <iostream>
#include <vector>
using namespace std;

int root[1000000];

int find(int num){
    if(root[num] == num) return num;
    else return root[num] = find(root[num]);
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    
    for(int i = 1;i <=n;i++)
        root[i] = i;

    for(int i = 0;i < m;i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if(a == 0){
            root[find(b)] = find(c);
        }
        else{ //a == 1 이면 b와 c가 같은 집합인가?
            if(find(b) == find(c)) printf("YES\n");
            else printf("NO\n");
        }
    }

}