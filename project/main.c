//main.c
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include "product.h"
#include "manager.h"

int main(void) {
    Book *bp[100];
    int count = 0, index = 0, i = 0;
    int menu, no;
    int file = 0;
    
    file = access("./booklist.txt", F_OK);
    if(file == 0) {
        count = loadFile(bp);
        index = count;
        printf("=> 파일을 불러왔습니다.\n");
    } else {
        printf("=> 파일이 존재하지 않습니다.\n");
    }
    
    while(menu != 0) {
        menu = selectMenu();
        if(menu == 0) break;
        else if(menu == 1) {
            if(count > 0) {
                booklist(bp, index, -1);
            } else {
                printf("등록된 책이 없습니다.\n");
            }
        } else if(menu == 2) {
            index++;
            bp[index] = (Book *)malloc(sizeof(Book));
            count++;
            addBook(bp[index]);
        } else if(menu == 3) {
            no = selectBookNum(bp, index);
            if(no > 0) {
                updateBook(bp[no]);
            } else {
                printf("=> 취소되었습니다.\n");
            }
        } else if(menu == 4) {
            deleteBook(bp, index);
        } else if(menu == 5) {
            saveFile(bp, index);
        } else if(menu == 6) {
            int s;
            printf("1. 이름\n");
            printf("2. 저자\n");
            printf("3. 출판사\n");
            printf("4. 가격\n");
            printf("5. 장르\n");
            printf("6. 별점\n");
            printf("7. 재고량\n");
            printf("=> 검색할 종류를 선택해주세요. ");
            scanf("%d", &s);
	    getchar();
            
            if(s == 1) {
                searchName(bp, index);
            } else if(s == 2) {
                searchWriter(bp, index);
            } else if(s == 3) {
                searchPublisher(bp, index);
            } else if(s == 4) {
                searchCost(bp, index);
            } else if(s == 5) {
                searchGenre(bp, index);
            } else if(s == 6) {
                searchStar(bp, index);
            } else if(s == 7) {
                searchMany(bp, index);
            } else {
                printf("메뉴를 잘못 선택하셨습니다.\n");
            }
        } else {
            printf("메뉴를 잘못 선택하셨습니다.\n");
        }
    }
    printf("종료되었습니다.\n");
    return 0;
}
