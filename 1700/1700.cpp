#include <cstdio>

int hole[102];
int inputs[102];

int isOn(int key, int num) {
    for (int i=1; i<=num; i++) {
        if (key==hole[i]) {
            return 1;
        }
    }
    return 0;
}

int getNext(int inputNow, int inputEnd, int key) {
    for (int i=inputNow+1; i<=inputEnd; i++) {
        if (inputs[i]==key) {
            return i;
        }
    }

    return inputEnd+1;
}

int getPlug(int inputNow, int inputEnd, int holeEnd) {
    int result;
    int max=0;
    for (int i=1; i<=holeEnd; i++) {
        int val = getNext(inputNow, inputEnd, hole[i]);
        if (max < val) {
            result = i;
            max = val;
        }
    }
    return result;
}

int main(void) {
    int N, K;
    int num=0;
    int result=0;
    scanf("%d %d", &N, &K);
    for (int i=1; i<=K; i++) {
        scanf("%d", &inputs[i]);
    }

    for (int i=1; i<=K; i++) {
        if (isOn(inputs[i], num)) {
            continue;
        }

        if (num<N) {
            hole[num+1] = inputs[i];
            num++;
        } else {
            int get = getPlug(i, K, N);
            hole[get] = inputs[i];
            result++;
        }
    }

    printf("%d", result);

    return 0;
}