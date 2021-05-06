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

// 파일 불러오기
int loadFile(Book *b[]) {
    int i, num;
    FILE *fs;
    
    fs = fopen("booklist.txt", "rt");
    for(i = 1; i <= 100; i++) {
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
    
    return i-1;
}

// 파일 저장하기
int saveFile(Book *b[], int index) {
    FILS *fs;
    fs = fopen("booklist.txt", "wt");
    
    int i;
    for(i = 1; i <= index; i++) {
        if(b[i] == NULL) continue;
        fprintf(fs, "%s %s %s %s %d %d %.1f", b[i]->name, b[i]->writer, b[i]->publisher, b[i]->genre, b[i]->cost, b[i]->many, b[i]->star);
        if(i < index) fprintf(fs, "\n");
    }
    fclose(fs);
    printf("저장완료!\n");
}
