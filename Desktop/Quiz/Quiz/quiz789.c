//
//  quiz789.c
//  Quiz
//
//  Created by 박성부 on 2023/03/16.
//
/*
 Quiz7
 
 question : 500x500 sparse matrix의 2d array와 1d array 표현 방식에서 2d array로 표현하는 것이 메모리 상으로 이득이 되는 지점은?
 
 1) 2D array의 메모리 사용
 array의 시작 주소를 정의하는 메모리 : 1 byte
 500 rows 각각의 시작 주소를 정의하는 메모리 : 500 byte
 각각의 rows들에 할당된 메모리 : 500 * 500 = 250000 byte
 
    1 + 500 + 250000 =250501
 
 2) sparse matrix representation을 structure로 만들어 1D array로 저장한 경우의 메모리 사용
 1D array의 시작 주소를 정의하는 메모리 : 1 byte
 array의 크기( number of rows/columns/values )를 나타내는 array[0]에 할당된 메모리 : 3 byte
 x개의 nonzero element를 가질 경우 필요한 메모리 : 3 * x = 3x
 
    1 + 3 + 3x = 3x +4
 
 3) 두가지 경우에 할당된 메모리값을 비교
 
 250501 > 3x +4
 250497 > 3x
 x > 83499 일 때 2D array로 나타내는 것이 메모리상으로 더 효율적인 방법이다.
 
 Quiz8
 
 startingPos[0] = 1;
 for (i = 1; i < numCols; i++) {
 startingPos[i] = 0;
 }
 for (i = 1; i <= numTerms; i++) {
 startingPos[a[i].col]++;
 }
 for (i = 1; i < numCols; i++) {
 startingPos[i] += startingPos[i - 1];
 }
 
 */

//Quiz9

#define max_size 100
#include <stdio.h>
#include <string.h>
void stringremove(char *s, int i, int j);

int main() {
    int i;
    char a[max_size] = "123456789";
    stringremove(a, 2, 3);
    
}

void stringremove(char *s, int i, int j) {
    int x;

    if (i + j > strlen(s)) {
        printf("Error: Index out of range.\n");
        return;
    }

    for (x = i - 1; x < strlen(s) - j; x++) {
        s[x] = s[x + j];
    }
    s[x] = '\0';
    for(i=0;i<strlen(s);i++) {
        printf("%c\n",s[i]);
    }
}






