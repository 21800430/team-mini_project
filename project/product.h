typedef struct {
    char name[20]; //제목
    int cost; // 가격
    char jenre[20]; //장르
    char writer[20]; //저자
    char publisher[20]; //출판사
    int many; //제고량
    int star; //별점
}Book;

//책을 등록하는 함수
int addBook( Book *b );
//등록된 책을 업데이트하는 함수
int updateBook( Book *b );