#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include "manager.h"
//���� �˻�
void searchName( Book *b[], int count ){
    printf("�˻��� ����: ");
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
    if(fail == count) printf("��ġ�ϴ� ����� �����ϴ�.\n");
}
//���� �˻�
void searchCost( Book *b[], int count ){
    printf("�˻��� ����(�˻� ���� ���� å ���): ");
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
    if(fail == count) printf("��ġ�ϴ� ����� �����ϴ�.\n");
}

//�帣 �˻�
void searchGenre( Book *b[], int count ){
    printf("�˻��� �帣: ");
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
    if(fail == count) printf("��ġ�ϴ� ����� �����ϴ�.\n");
}