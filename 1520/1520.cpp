#include <cstdio>
#include <utility>
using namespace std;

int inputArray[501][501];
int action[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void 

int main() {
    int height, width;
    scanf("%d %d", &height, &width);

    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            scanf("%d", &inputArray[i][j]);
        }
    }

    // for (int i=0; i<=height; i++) {
    //     inputArray[i][width] = INT32_MAX;
    // }

    // for (int i=0; i<=width; i++) {
    //     inputArray[height][i] = INT32_MAX;
    // }

    findWays(height, width);

    for (int i=height-1; i>0; i--) {
        for (int j=width-1; j>0; j--) {

        }
    }



    return 0;
}