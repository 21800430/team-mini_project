#ifdef PRODUCT_H
#else 
#include "product.h"
#endif

//제목 검색
void searchName( Book *b[], int count );
//가격 검색
void searchCost( Book *b[], int count );
//장르 검색
void searchGenre( Book *b[], int count );
//저자 검색
void searchWriter( Book *b[], int count );
//출판사 검색
void searchPublisher( Book *b[], int count );
//별점 검색
void searchStar( Book *b[], int count );
//재고량 검색
void searchMany( Book *b[], int count );
// 파일 불러오기
int loadFile(Book *b[]);
// 파일 저장하기
int saveFile(Book *b[], int index);
