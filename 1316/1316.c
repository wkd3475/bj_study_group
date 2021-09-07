#include <stdio.h>
#include <string.h>

int english[26];

int main(void) {
    int n, num=0;
    char s[101];
    scanf("%d", &n);

    while (n--) {
        char prev = 0;
        for (int i=0; i<26; i++) {
            english[i] = 0;
        }
        scanf("%s", s);


        int isGroup = 1;
        for (int i=0; i<strlen(s); i++) {
            if (s[i] != prev && english[s[i]-'a'] > 0) {
                isGroup = 0;
                break;
            }
            prev = s[i];
            english[s[i]-'a']++;
        }

        if (isGroup) {
            num++;
        }
    }

    printf("%d", num);
    return 0;
}