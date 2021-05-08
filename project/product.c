//CRUD 구현
#include<stdio.h>
#include "product.h"

// 메뉴를 띄우는 함수
int selectMenu() {
    int menu;
    printf("\n===한동서점===\n");
    printf("1. 도서목록\n");
    printf("2. 도서추가\n");
    printf("3. 정보수정\n");
    printf("4. 도서삭제\n");
    printf("5. 파일저장\n");
    printf("6. 도서검색\n");
    printf("0. 종료\n");
    printf("=> 원하시는 메뉴를 선택해주세요. ");
    scanf("%d", &menu);
    
    return menu;
}

//책을 등록하는 함수
int addBook( Book *b ){
    printf("책 번호는?: ");
    scanf("%d",&b->no);
    getchar();
    printf("책 제목은?: ");
    scanf("%[^\n]s",b->name);
    getchar();
    printf("책 저자는?: ");
    scanf("%[^\n]s",b->writer);
    getchar();
    printf("책 출판사는?: ");
    scanf("%[^\n]s",b->publisher);
    getchar();
    printf("책 장르는?: ");
    scanf("%[^\n]s",b->jenre);
    getchar();
    printf("책 가격은??: ");
    scanf("%d",&b->cost);
    getchar();
    printf("책 재고량은?: ");
    scanf("%d",&b->many);
    getchar();
    printf("책 별점는?: ");
    scanf("%f",&b->star);
    getchar();
    printf("=> 등록되었습니다\n");
    return 1;
}
//등록된 책을 업데이트하는 함수
int updateBook( Book *b){
    printf("책 번호는?: ");
    scanf("%d",&b->no);
    getchar();
    printf("책 제목은?: ");
    scanf("%[^\n]s",b->name);
    getchar();
    printf("책 저자는?: ");
    scanf("%[^\n]s",b->writer);
    getchar();
    printf("책 출판사는?: ");
    scanf("%[^\n]s",b->publisher);
    getchar();
    printf("책 장르는?: ");
    scanf("%[^\n]s",b->jenre);
    getchar();
    printf("책 가격은??: ");
    scanf("%d",&b->cost);
    getchar();
    printf("책 재고량은?: ");
    scanf("%d",&b->many);
    getchar();
    printf("책 별점는?: ");
    scanf("%f",&b->star);
    getchar();
    printf("=> 수정되었습니다\n");
    return 1;
}

// 도서목록의 내용을 나열하는 함수
void readBook(Book b){
    printf("%d %s %s %s %s %d %d %.1f", b.no, b.name, b.writer, b.publisher, b.jenre, b.cost, b.many, b.star);
}

// 도서목록의 틀을 표시하는 함수
int booklist(Book *b[], int index, int n) {
    printf("\nNo Name  writer  publisher  jenre  cost  many star\n");
    printf("====================================================\n");
    int i;
    
    if(n == -1) {
        for(i = 1; i <= index; i++) {
            if(b[i] == NULL) continue;
            readBook(*b[i]);
        }
    } else {
        readBook(*b[n]);
    }
}

// 원하는 책의 정보를 삭제하는 함수

// 원하는 책의 번호를 선택하는 함수
int selectBookNum(Book *b[], int index) {
    booklist(b, index, -1);
    int num;
    
    printf("\n원하는 책의 번호를 입력해주세요. (취소 : 0)");
    scanf("%d", &num);
    
    if(b[num] == NULL) {
        printf("번호를 잘못 입력하셨습니다.\n");
    }
    
    return num;
}

int deleteBook(Book *B){
}
