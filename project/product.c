//CRUD ����
#include<stdio.h>
#include "product.h"

//å�� ����ϴ� �Լ�
int addBook( Book *b ){
    printf("å ������?: ");
    scanf("%[^\n]s",b->name);
    printf("å ���ڴ�?: ");
    scanf("%[^\n]s",b->writer);
    printf("å ���ǻ��?: ");
    scanf("%[^\n]s",b->publisher);
    printf("å �帣��?: ");
    scanf("%[^\n]s",b->jenre);
    printf("å ������??: ");
    scanf("%[^\n]s",b->cost);
    printf("å �����?: ");
    scanf("%d",b->many);
    printf("å ������?: ");
    scanf("%[^\n]s",b->star);
    printf("=> ��ϵǾ����ϴ�\n");
    return 1;
}
//��ϵ� å�� ������Ʈ�ϴ� �Լ�
int updateBook( Book *b[], int index ){
    printf("å ������?: ");
    scanf("%[^\n]s",b[index]->name);
    printf("å ���ڴ�?: ");
    scanf("%[^\n]s",b[index]->writer);
    printf("å ���ǻ��?: ");
    scanf("%[^\n]s",b[index]->publisher);
    printf("å �帣��?: ");
    scanf("%[^\n]s",b[index]->jenre);
    printf("å ������??: ");
    scanf("%[^\n]s",b[index]->cost);
    printf("å �����?: ");
    scanf("%d",b[index]->many);
    printf("å ������?: ");
    scanf("%[^\n]s",b[index]->star);
    printf("=> �����Ǿ����ϴ�\n");
    return 1;
}