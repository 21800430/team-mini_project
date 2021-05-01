#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "product.h"

int main(void){
    Product *pp[100];
    int count = 0, index = 0, i = 0;
    int menu, no;
    int file = 0;

    file = access("./product.txt", F_OK);
    if(file == 0) {
        count = loadFile(pp);
        index = count;
        printf("=> 로딩 성공!");
    } else {
        printf("=> 파일 없음\n");
    }

    while (1){
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1){
                if (count > 0) {
                        listProduct(pp, index, -1);
                } else {
                        index = 0;
                        printf("데이터가 없습니다.\n");
                }
        }
        else if (menu == 2){
                index++;
                pp[index] = (Product *)malloc(sizeof(Product));
                count++;
                addProduct(pp[index], index);
        }
        else if (menu == 3){
                int no = selectProductNum(pp, index);
                if(no > 0) {
                        updateProduct(pp[no]);
                } else {
                        printf("=> 취소됨!\n");
                }
        } else if (menu == 4){
                int no = selectProductNum(pp, index);
                if(no > 0) {
                        int delOk;
                        printf("정말로 삭제하시겠습니까?(삭제 : 1)");
                        scanf("%d", &delOk);
                        if(delOk == 1) {
                               free(pp[no]);
                                pp[no] = NULL;
                                count--;
                                printf("=> 삭제됨!\n");
                        } else {
                                printf("=> 취소됨!\n");
                        }
                } else {
                        printf("=> 취소됨!\n");
                }
        } else if (menu == 5) {
                saveFile(pp, index);
        } else if (menu == 6) {
                int s;
                printf("\n검색할 종류는?\n");
                printf("1. 이름\n");
                printf("2. 가격\n");
                printf("3. 별점\n");
                scanf("%d", &s);
                if (s == 1) {
                        searchName(pp, index);
                } else if (s == 2) {
                        searchPrice(pp, index);
                } else if (s == 3) {
                        searchStar(pp, index);
                } else {
                        printf("메뉴를 잘못 선택하셨습니다.\n");
                }
        } else {
            printf("메뉴를 잘못 선택하셨습니다.\n");
        }
    }
    printf("종료됨!\n");
    return 0;
}
