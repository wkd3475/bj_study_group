#include <cstdio>
#include <vector>
using namespace std;

vector<int> v;
int dp[41];

int main(void) {
    int n,m;
    int vip, prev_vip=0;
    int result = 1;
    
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2; i<=40; i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    
    scanf("%d", &n);
    scanf("%d", &m);
    for(int i=1; i<=m; i++){
        scanf("%d", &vip);
        v.push_back(vip-prev_vip-1);
        prev_vip = vip;
    }
    v.push_back(n-vip);
    
    for(vector<int>::iterator iter=v.begin(); iter!=v.end(); iter++) {
        result *= dp[*iter];
    }
    printf("%d", result);

    return 0;
}