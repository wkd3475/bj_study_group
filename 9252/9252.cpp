#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

string first, second;
int dp[1002][1002];

void find(int i, int j) {
    if (dp[i][j]==0) {
        return;
    }
    if (first[i-1] == second[j-1]) {
        find(i-1, j-1);
        cout<<first[i-1];
    } else if (dp[i][j] == dp[i-1][j]) {
        find(i-1, j);
    } else {
        find(i, j-1);
    }
    return;
}

int main(void) {
    cin>>first;
    cin>>second;
    for (int i=1; i<=first.length(); i++) {
        int check=0;
        for (int j=1; j<=second.length(); j++) {
            if (first[i-1] == second[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout<<dp[first.length()][second.length()]<<"\n";
    
    find(first.length(), second.length());
    cout<<"\n";
    return 0;
}