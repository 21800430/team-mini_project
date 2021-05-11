typedef struct {
    int no; //번호
    char name[50]; //제목
    int cost; // 가격
    char genre[50]; //장르
    char writer[50]; //저자
    char publisher[50]; //출판사
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
void deleteBook(Book *b[], int index, int no);
//메뉴를 보여주는 함수
int selectMenu();
