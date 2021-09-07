#include <stdio.h>

int main(void) {
    char a[4];
    char b[4];
    int a_i, b_i;
    scanf("%s", a);
    scanf("%s", b);

    a_i = (a[2]-'0')*100 + (a[1]-'0')*10 + (a[0]-'0');
    b_i = (b[2]-'0')*100 + (b[1]-'0')*10 + (b[0]-'0');

    if (a_i < b_i) {
        printf("%d", b_i);
    } else {
        printf("%d", a_i);
    }
    return 0;
}