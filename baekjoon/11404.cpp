#include <iostream>
using namespace std;
#define INF 1000000000 //1e9
#define MAX 101 //최대 도시의 개수

int main(){
    int n, m, a, b, c;
    int city[MAX][MAX];
    scanf("%d%d", &n, &m);
    fill(&city[0][0], &city[MAX-1][MAX], INF);
    
    for(int i = 0;i < m;i++){
        scanf("%d%d%d", &a, &b, &c);
        city[a][b] = min(city[a][b], c);
    }
    
    for(int i = 1;i <= n;i++)
        city[i][i] = 0;
        

    for(int k = 1;k <= n;k++){
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                if(i == k || j == k || i == j) continue;
                city[i][j] = min(city[i][j], city[i][k] + city[k][j]);
            }
        }
    }

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++)
            printf("%d ", city[i][j] == INF ? 0 : city[i][j]);
        printf("\n");
    }
}