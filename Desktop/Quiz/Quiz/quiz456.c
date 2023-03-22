//
//  quiz456.c
//  Quiz
//
//  Created by 박성부 on 2023/03/06.
//
#define MAX_DRGREE 101
#include <stdio.h>
#include <stdlib.h>

// polynomial structure 정의
typedef struct {
    int degree;
    float coef[MAX_DRGREE];
} polynomial;

polynomial Attatch(polynomial poly, int coef, float expon);
polynomial Remove(polynomial poly, int coef);
void printPoly(polynomial poly);

int main2() {
    
    //Quiz4 : row별로 크기가 다른 2D array를 만드는 코드
    
    int i, j, rows, coef, *length, **randomRowsArray;
    int **make2dArray(int length[], int rows);
    float expon;
    
    printf("-----------------Quiz4----------------\n");
    
    printf("rows to make array : ");
    scanf("%d",&rows);
    if (rows<1)
    {
        fprintf(stderr,"improper value of rows\n");
        exit(EXIT_FAILURE);
    }
    length = (int*)malloc( rows * sizeof(int) );
    if (length == NULL) {
        fprintf(stderr,"lack of memory\n");
        exit(EXIT_FAILURE);
    }
    for (i = 0 ; i < rows ; i++)
    {
        length[i]=rand()%10 + 1;
    }
    randomRowsArray = make2dArray(length, rows);
    
    for (i = 0; i < rows; i++) {
        for (j = 0; j < length[i]; j++) {
            printf("%d ", randomRowsArray[i][j]);
        }
        printf("\n");
    }
    
    for (i = 0 ; i < rows ; i++) {
        free(randomRowsArray[i]);
    }
    free(randomRowsArray);
    free(length);
    
    //Quiz5 : 직사각형, 삼각형, 원을 정의할 수 있는 structure 만들기
    
    typedef struct {
        float length;
        float width;
    } recangle;
    
    typedef struct {
        float a_side;
        float b_side;
        float c_side;
    } triangle;
    
    typedef struct {
        float radious;
    } circle;
    
    //Quiz6 : 다항식을 정의하고 그 다항식에서 특정항을 빼거나 더할 수 있느 코드

    printf("\n\n-----------------Quiz6----------------\n");
    
    //다항식 정의하기
    polynomial a;
    a.degree = rand() % 15 +1;
    for (i = 0 ; i <= a.degree ; i++) {
        a.coef[i] = rand() %10;
    }
    
    printPoly(a);
    
    //Attatch함수 작동 시험
    printf("\n\n-------------Attatch test-------------");
    printf("\ncoefficient for Attatch : ");
    scanf("%d", &coef);
    printf("\nexponent for Attatch    : ");
    scanf("%f", &expon);
    
    a = Attatch(a, coef, expon);
    
    printPoly(a);
    
    //Remove함수 작동 시험
    printf("\n\n-------------Remove test--------------");
    printf("\ncoefficient for Remove : ");
    scanf("%d", &coef);
    
    a = Remove(a, coef);
    
    printPoly(a);
    
    
    return 0;
}

//length[]와 rows를 통해 2D array를 만드는 make2dArray함수 (quiz4)
int **make2dArray(int length[], int rows)
{
    int i, j;
    int **D2_Array=(int**)malloc(rows*sizeof(int*));
    
    if (D2_Array == NULL) exit(EXIT_FAILURE);
    
    for (i = 0 ; i < rows ; i++) {
        D2_Array[i]=(int*)malloc(length[i]*sizeof(int));
        if (D2_Array[i] == NULL) exit(EXIT_FAILURE);
    }
    for (i = 0; i < rows; i++) {
        for (j = 0; j < length[i]; j++) {
            D2_Array[i][j] = rand() % 100;
        }
    }
    return D2_Array;
}
//polynomial를 입력으로 받고 print해주는 함수
void printPoly(polynomial poly) {
    int i;
    for (i = poly.degree ; i >=0 ; i--) {
        if (poly.coef[i]) {
            if (i)
                printf("%.2f * x^%d + ", poly.coef[i], i);
            else
                printf("%.2f\n", poly.coef[i] );
        }
        else continue;
        
    }
}
//polynomial와 coefficient, exponent를 입력으로 받고 해당 항을 더해주는 함수
polynomial Attatch(polynomial poly, int coef, float expon)
{
    poly.coef[coef] = poly.coef[coef] + expon;
    return poly;
}
//polynomial와 coefficient를 입력으로 받고 해당 항을 제거하는 함수
polynomial Remove(polynomial poly, int coef)
{
    poly.coef[coef] = 0;
    return poly;
}
