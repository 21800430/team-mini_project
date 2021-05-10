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
    for( int i = 1; i < count; i++) {
        if(b[i] != NULL){
            if(strstr(b[i]->name,title)){
                readBook(*b[i]);
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
    for( int i = 1 ; i < count ; i++){
        if(b[i]!=NULL){
            if(b[i]->cost <= cost){
                readBook(*b[i]);
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
    for( int i = 1; i < count; i++) {
        if(b[i] != NULL){
            if(strstr(b[i]->genre,genre)){
                readBook(*b[i]);
            }
            else fail++;
        }
    }
    if(fail == count) printf("일치하는 결과가 없습니다.\n");
}

//저자 검색
void searchWriter( Book *b[], int count ){
    printf("검색할 저자: ");
    char writer[20];
    int fail=1;
    scanf("%[^\n]s",writer);
    getchar();
    printf("\n------------------\n");
    for( int i = 1; i < count; i++) {
        if(b[i] != NULL){
            if(strstr(b[i]->writer,writer)){
                readBook(*b[i]);
            }
            else fail++;
        }
    }
    if(fail == count) printf("일치하는 결과가 없습니다.\n");
}
//출판사 검색
void searchPublisher( Book *b[], int count ){	
    printf("검색할 출판사: ");
    char publisher[20];
    int fail=0;
    scanf("%[^\n]s",publisher);
    getchar();
    printf("\n------------------\n");
    for( int i = 1; i < count; i++) {
        if(b[i] != NULL){
            if(strstr(b[i]->publisher,publisher)){
                readBook(*b[i]);
            }
            else fail++;
        }
    }
    if(fail == count) printf("일치하는 결과가 없습니다.\n");
}
//별점 검색
void searchStar( Book *b[], int count ){	
    printf("검색할 별점(몇 점 이상): ");
    int fail = 1;
    float star = 0;
    scanf("%f",&star);
    getchar();
    printf("\n------------------\n");
    for( int i = 1 ; i < count ; i++){
        if(b[i]!=NULL){
            if(b[i]->star >= star){
                readBook(*b[i]);
            }
            else fail++;
        }
    }
    if(fail == count) printf("일치하는 결과가 없습니다.\n");
}
//재고량 검색
void searchMany( Book *b[], int count ){
    printf("검색할 재고량(몇 개 이상): ");
    int fail = 1, many;
    scanf("%d",&many);
    getchar();
    printf("\n------------------\n");
    for( int i = 1 ; i < count ; i++){
        if(b[i]!=NULL){
            if(b[i]->many >= many){
                readBook(*b[i]);
            }
            else fail++;
        }
    }
    if(fail == count) printf("일치하는 결과가 없습니다.\n");
}

// 파일 불러오기

int loadFile(Book *b[]) {
    int i, num;
    FILE *fs;
    
    fs = fopen("booklist.txt", "rt");
    for(i = 1; i <=100; i++) {
        if(feof(fs)) break;
        b[i] = (Book *)malloc(sizeof(Book));
        b[i]->no = i;
        
        fscanf(fs, "%s", b[i]->name);
        fscanf(fs, "%s", b[i]->writer);
        fscanf(fs, "%s", b[i]->publisher);
        fscanf(fs, "%s", b[i]->genre);
        fscanf(fs, "%d", &b[i]->cost);
        fscanf(fs, "%d", &b[i]->many);
        fscanf(fs, "%f", &b[i]->star);
    }
    fclose(fs);
    
    return i;
}

// 파일 저장하기
int saveFile(Book *b[], int index) {
    FILE *fs;
    fs = fopen("booklist.txt", "wt");
    
    int i;
    for(i = 1; i < index; i++) {
        if(b[i] == NULL) continue;
        fprintf(fs, "%s %s %s %s %d %d %.1f", b[i]->name, b[i]->writer, b[i]->publisher, b[i]->genre, b[i]->cost, b[i]->many, b[i]->star);
        if(i < index) fprintf(fs, "\n");
    }
    fclose(fs);
    printf("저장완료!\n");
}
