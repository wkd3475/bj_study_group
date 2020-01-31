#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> numbers;

int main(void) {
    char input;
    int sum=0, digit=1;

    while (true) {
        input = getchar();

        if (input == '\n')
            break;
        
        numbers.push_back(input-'0');
    }

    sort(numbers.begin(), numbers.end());

    vector<int>::iterator iter;
    for (iter=numbers.begin(); iter!=numbers.end(); iter++) {
        sum += *iter;
    }

    if (numbers.front()!=0 || sum%3!=0) {
        printf("-1\n");
    } else {
        while (numbers.size()) {
            printf("%d", numbers.back());
            numbers.pop_back();
        }
        printf("\n");
    }

    return 0;
}