#include <cstdio>
using namespace std;

int dp[101][1001];

int main(void) {
    int n,s,m;
    int input;
    scanf("%d%d%d", &n, &s, &m);

    dp[0][s]=1;
     
    for(int i=1; i<=n; i++){
        scanf("%d", &input);
        for(int j=0; j<=m; j++){
            if(dp[i-1][j]==1){
                if(j+input<=m) 
                    dp[i][j+input]=1;
                if(j-input>=0)
                    dp[i][j-input]=1;
            }            
        }
    }

    for(int j=m; j>=0; j--){
        if(dp[n][j]==1){
            printf("%d", j);
            return 0;
        } 
    }
    printf("-1");
    return 0;
}