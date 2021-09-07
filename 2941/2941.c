#include <stdio.h>
#include <string.h>

int main(void) {
    char s[105];
    int num = 0;
    scanf("%s", s);

    int base = 0;
    int end = strlen(s);

    while (base < end) {
        if (s[base]=='c') {
            if (s[base+1]=='=' || s[base+1]=='-') {
                num++;
                base=base+2;
                continue;
            }
        } else if (s[base]=='d') {
            if (s[base+1]=='z' && s[base+2]=='=') {
                num++;
                base=base+3;
                continue;
            }
            if (s[base+1]=='-') {
                num++;
                base=base+2;
                continue;
            }
        } else if (s[base]=='l' && s[base+1]=='j') {
            num++;
            base=base+2;
            continue;
        } else if (s[base]=='n' && s[base+1]=='j') {
            num++;
            base=base+2;
            continue;
        } else if (s[base]=='s' && s[base+1]=='=') {
            num++;
            base=base+2;
            continue;
        } else if (s[base]=='z' && s[base+1]=='=') {
            num++;
            base=base+2;
            continue;
        }
        num++;
        base=base+1;
    }

    printf("%d", num);

    return 0;
}