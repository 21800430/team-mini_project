#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "product.h"

int selectMenu() {
	int menu;
	printf("\n***과일마트***\n");
	printf("1. 조회\n");
	printf("2. 추가\n");
	printf("3. 수정\n");
	printf("4. 삭제\n");
	printf("5. 파일저장\n");
	printf("6. 검색\n");
	printf("0. 종료\n");
	printf("=> 원하는 메뉴는? ");
	scanf("%d", &menu);

	return menu;
};

void addProduct(Product *p, int index) {
	printf("이름은? ");
    	scanf("%s", p->name);

    	printf("무게는? ");
    	scanf("%f", &p->weight);

    	printf("가격은? ");
    	scanf("%d", &p->price);

    	printf("별점은? ");
    	scanf("%f", &p->star);

	p->no = index;

	printf("=> 추가됨!\n");
};

void readProduct(Product p) {
	printf("%d %s %.1f %d %.1f\n", p.no, p.name, p.weight, p.price, p.star);
};

void updateProduct(Product *p) {
	printf("이름은? ");
    	scanf("%s", p->name);

    	printf("무게는? ");
    	scanf("%f", &p->weight);

    	printf("가격은? ");
    	scanf("%d", &p->price);

    	printf("별점은? ");
    	scanf("%f", &p->star);

	printf("=> 수정됨!\n");
};

int listProduct(Product *p[], int index, int n) {
	printf("\nNo Name weight price star\n");
	printf("============================\n");
	int i;

	if(n == -1) {
        	for(i = 1; i <= index; i++) {
            		if (p[i] == NULL) continue;
            		readProduct(*p[i]);
        	}
	} else {
        	readProduct(*p[n]);
    	}
};

int selectProductNum(Product *p[], int index) {
    	listProduct(p, index, -1);
    	int num;

    	printf("\n번호는 (취소 :0)? ");
    	scanf("%d", &num);

    	if(p[num] == NULL) {
        	printf("번호를 잘못 입력하셨습니다.\n");
    	}

    	return num;
};

int loadFile(Product *p[]) {
    int i, num;
    FILE *fs;

    fs = fopen("product.txt", "rt");
    for(i = 1; i <= 100; i++) {
        if(feof(fs)) break;
        p[i] = (Product *)malloc(sizeof(Product));
        p[i]->no = i;
        fscanf(fs, "%s", p[i]->name);
        fscanf(fs, "%f", &p[i]->weight);
        fscanf(fs, "%d", &p[i]->price);
        fscanf(fs, "%f", &p[i]->star);
    }
    fclose(fs);

    return i-1;
};

int saveFile(Product *p[], int index) {
    FILE *fs;
    fs = fopen("product.txt", "wt");

    int i;
    for(i = 1; i <= index; i++) {
        if(p[i] == NULL) continue;
        fprintf(fs, "%s %f %d %f", p[i]->name, p[i]->weight, p[i]->price, p[i]->star);
        if(i < index) fprintf(fs, "\n");
    }
    fclose(fs);
    printf("저장됨!\n");
};

void searchName(Product *p[], int index) {
    char search[20];
    int n = 0, i;
    int scnt = 0;

    printf("검색할 이름은? ");
    scanf("%s", search);

    for(i = 1; i <= index; i++) {
        if(p[i] == NULL) continue;
        if(strcmp(p[i]->name, search) == 0) {
            n = i;
            scnt++;
            break;
        }
    }

    if(scnt > 0) {
        listProduct(p, index, n);
    } else {
        printf("=> 검색된 데이터 없음!\n");
    }
};

void searchPrice(Product *p[], int index) {
    int search;
    int n = 0, i;
    int scnt = 0;

    printf("검색할 가격은? ");
    scanf("%d", &search);

    for(i = 1; i <= index; i++) {
        if(p[i] == NULL) continue;
        if(p[i]->price == search) {
            n = i;
            scnt++;
            break;
        }
    }

    if(scnt > 0) {
        listProduct(p, index, n);
    } else {
        printf("=> 검색된 데이터 없음!\n");
    }
};

void searchStar(Product *p[], int index) {
    float search;
    int n = 0, i;
    int scnt = 0;

    printf("검색할 별점은? ");
    scanf("%f", &search);

    for(i = 1; i <= index; i++) {
        if(p[i] == NULL) continue;
        if(p[i]->star == search) {
                n = i;
                scnt++;
                break;
        }
    }

    if(scnt > 0) {
        listProduct(p, index, n);
    } else {
        printf("=> 검색된 데이터 없음!\n");
    }
};
