#include <cstdio>
#include <vector>
using namespace std;

int dp[41];
vector<int> v;

int main(void) {
    int num_seat, num_fixed_seat;
    int before_fixted_seat=0;
    int fixed_seat;
    int result = 1;
    scanf("%d", &num_seat);
    scanf("%d", &num_fixed_seat);

    dp[0] = 1;
    dp[1] = 1;
    for (int i=2; i<=40; i++) {
        dp[i] = dp[i-1]+dp[i-2];
    }

    for (int i=0; i<num_fixed_seat; i++) {
        scanf("%d", &fixed_seat);
        v.push_back(fixed_seat-before_fixted_seat-1);
        before_fixted_seat = fixed_seat;
    }
    v.push_back(num_seat-before_fixted_seat);

    for (vector<int>::iterator iter=v.begin(); iter!=v.end(); iter++) {
        result *= dp[*iter];
    }
    printf("%d", result);
    return 0;
}