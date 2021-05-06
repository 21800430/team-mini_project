#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include "manager.h"
//제목 검색
void searchName( Book *b[], int count ){
    printf("검색할 제목: ");
    char title[20];
    int fail = 1;
    scanf("%[^\n]s",title);
    getchar();
    printf("\n------------------\n");
    for( int i = 0; i < count; i++) {
        if(b[i] != NULL){
            if(strstr(b[i]->name,title)){
                printf("%d",i+1);
                readBook(b[i]);
            }
            else fail++;
        }
    }
    if(fail == count) printf("일치하는 결과가 없습니다.\n");
}
//가격 검색
void searchCost( Book *b[], int count ){
    printf("검색할 가격(검색 가격 이하 책 출력): ");
    int fail = 1, cost;
    scanf("%d",&cost);
    getchar();
    for( int i = 0 ; i < count ; i++){
        if(b[i]!=NULL){
            if(b[i]->cost == cost){
                printf("%d", i+1);
                readBook(b[i]);
            }
            else fail++;
        }
    }
    if(fail == count) printf("일치하는 결과가 없습니다.\n");
}

//장르 검색
void searchGenre( Book *b[], int count ){
    printf("검색할 장르: ");
    char genre[20];
    int fail=1;
    scanf("%[^\n]s",genre);
    getchar();
    printf("\n------------------\n");
    for( int i = 0; i < count; i++) {
        if(b[i] != NULL){
            if(strstr(b[i]->name,genre)){
                printf("%d",i+1);
                readBook(b[i]);
            }
            else fail++;
        }
    }
    if(fail == count) printf("일치하는 결과가 없습니다.\n");
}