//CRUD 구현
#include<stdio.h>
#include "product.h"

//책을 등록하는 함수
int addBook( Book *b ){
    printf("책 제목은?: ");
    scanf("%[^\n]s",b->name);
    printf("책 저자는?: ");
    scanf("%[^\n]s",b->writer);
    printf("책 출판사는?: ");
    scanf("%[^\n]s",b->publisher);
    printf("책 장르는?: ");
    scanf("%[^\n]s",b->jenre);
    printf("책 가격은??: ");
    scanf("%[^\n]s",b->cost);
    printf("책 재고량은?: ");
    scanf("%d",b->many);
    printf("책 별점는?: ");
    scanf("%[^\n]s",b->star);
    printf("=> 등록되었습니다\n");
    return 1;
}
//등록된 책을 업데이트하는 함수
int updateBook( Book *b[], int index ){
    printf("책 제목은?: ");
    scanf("%[^\n]s",b[index]->name);
    printf("책 저자는?: ");
    scanf("%[^\n]s",b[index]->writer);
    printf("책 출판사는?: ");
    scanf("%[^\n]s",b[index]->publisher);
    printf("책 장르는?: ");
    scanf("%[^\n]s",b[index]->jenre);
    printf("책 가격은??: ");
    scanf("%[^\n]s",b[index]->cost);
    printf("책 재고량은?: ");
    scanf("%d",b[index]->many);
    printf("책 별점는?: ");
    scanf("%[^\n]s",b[index]->star);
    printf("=> 수정되었습니다\n");
    return 1;
}