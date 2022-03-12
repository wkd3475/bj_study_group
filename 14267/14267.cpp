#include <cstdio>

int superior[100001];
int weight[100001];
int dp[100001];

int get_total_compliment(int num) {
    if (superior[num] == -1)
        return 0;
    if (dp[superior[num]] == 0 && superior[num] != 1) {
        dp[superior[num]] = get_total_compliment(superior[num]) + weight[superior[num]];
        return dp[superior[num]] + weight[num];
    }
    return dp[superior[num]] + weight[num];
}

int main(void) {
    int total_employee_num, total_compliment_num;
    int target_employee, input_weight;

    scanf("%d %d", &total_employee_num, &total_compliment_num);

    for (int i=1; i<=total_employee_num; i++) {
        scanf("%d", &superior[i]);
    }

    for (int i=1; i<=total_compliment_num; i++) {
        scanf("%d", &target_employee);
        scanf("%d", &input_weight);
        weight[target_employee] += input_weight;
    }

    for (int i=1; i<= total_employee_num; i++) {
        if (dp[i] == 0)
            dp[i] = get_total_compliment(i);
        printf("%d ", dp[i]);
    }
    return 0;
}

//  start at : 2022-03-12 23:00
// solved at : 2022-03-13 00:05