typedef struct {
    int no; //번호
    char name[20]; //제목
    int cost; // 가격
    char jenre[20]; //장르
    char writer[20]; //저자
    char publisher[20]; //출판사
    int many; //재고량
    float star; //별점
}Book;
#define PRODUCT_H

//책을 등록하는 함수
int addBook( Book *b );
//등록된 책을 업데이트하는 함수
int updateBook( Book *b);
// 원하는 책의 정보를 불러오는 함수
void readBook(Book b);
// 책의 목록을 나열하는 함수
int booklist(Book *b[], int index, int n);
// 책의 번호를 고르는 함수
int selectBookNum(Book *b[], int index);
// 책의 정보를 삭제하는 함수
int deleteBook(Book *b);
//메뉴를 보유주는 함수
int selectMenu();
