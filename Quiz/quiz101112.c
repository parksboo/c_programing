//
//  quiz101112.c
//  Quiz
//
//  Created by 박성부 on 2023/03/22.
//

#define MAX 100
#include <stdio.h>
#include <string.h>

//quiz10
int strnchar(char *s, char p);
int pmatch (char* string, char* pat);
void mkfailure(char* pat);

int main(void) {
    int num;
    char p, str[MAX];
    printf("input string : ");
    scanf("%s",str);
    printf("input character : ");
    scanf(" %c", &p);
    getchar();
    num = strnchar(str, p);
    printf("number of character : %d\n",num);

    return 0;
}

int strnchar(char *s, char p) {
    int i, pnum = 0;
    for (i = 0 ; i < strlen(s) ; i++) {
        if (s[i] == p) {
            pnum++;
        }
    }
    return pnum;
}
/*
 Quiz 11.
 
 (a) failure ( aaaab ) = -1 0 1 2 -1
 
 (b) failure ( ababaa ) = -1 -1 0 1 2 0
 
 (c) failure ( abaabaab ) = -1 -1 0 0 1 2 3 1
 
 Quiz 12.
 */
int pmatch (char* string, char* pat)
{
    int i, j, failure[100];
    unsigned long lens, lenp;
    lens = strlen(string);
    lenp =strlen(pat);
    
for (i = 0, j = 0; i < lens && j < lenp; ) {
    if (string[i] == pat[j]) {
        i++;
        j++;
    }
    else if (j == 0)
        i++;
    else j = failure[j-1] + 1;
}
return (j == lenp ? i - (int)lenp : -1);
}

void mkfailure(char* pat) {
    int lenp = (int)strlen(pat);
    int i;
    for(i = 0 ; i < lenp; i++) {
        
    }
    
}
