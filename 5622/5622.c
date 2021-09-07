#include <stdio.h>
#include <string.h>

int main(void) {
    char s[20];
    int n, sum=0;
    scanf("%s", s);
    for (int i=0; i<strlen(s); i++) {
        n = s[i] - 'A';

        if (n>=0 && n<3) {
            sum += 3;
        } else if (n>=3 && n<6) {
            sum += 4;
        } else if (n>=6 && n<9) {
            sum += 5;
        } else if (n>=9 && n<12) {
            sum += 6;
        } else if (n>=12 && n<15) {
            sum += 7;
        } else if (n>=15 && n<19) {
            sum += 8;
        } else if (n>=19 && n<22) {
            sum += 9;
        } else if (n>=22 && n<26) {
            sum += 10;
        }
    }
    printf("%d", sum);
    return 0;
}