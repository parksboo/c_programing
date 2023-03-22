//
//  main.c
//  Quiz
//
//  Created by 박성부 on 2023/03/05.
//

#include <stdio.h>
#include <stdlib.h>

int main1()
{
    
    int rows, columns, i, j, x, y, z;
    
    /* code1 : making 2D array */
    
    printf("array의 ROWS : ");
    scanf("%d", &rows);
    printf("array의 COLUMNS : ");
    scanf("%d", &columns);
    int **d2_array = (int**)malloc(rows * sizeof(int*));
    for (i = 0; i < rows; i++)
    {
        d2_array[i] = (int*)malloc(columns * sizeof(int));
    }
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            d2_array[i][j] = rand() % 100;
        }
    }
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            printf("%d ", d2_array[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < rows; i++) {
        free(d2_array[i]);
    }
    free(d2_array);

    
    /* code2 : sorting x,y,z */
    
    printf("x,y,z를 입력 : ");
    scanf("%d %d %d", &x, &y, &z);
    
    if (x > y) {
        x = x ^ y;
        y = x ^ y;
        x = x ^ y;
    }
    if (x > z) {
        x = x ^ z;
        z = x ^ z;
        x = x ^ z;
    }
    if (y > z) {
        y = y ^ z;
        z = y ^ z;
        y = y ^ z;
    }

    printf("정렬된 3숫자: %d %d %d\n", x, y, z);

    return 0;

}

