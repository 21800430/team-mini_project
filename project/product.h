typedef struct {
    char name[20]; //����
    int cost; // ����
    char jenre[20]; //�帣
    char writer[20]; //����
    char publisher[20]; //���ǻ�
    int many; //����
    int star; //����
}Book;

//å�� ����ϴ� �Լ�
int addBook( Book *b );
//��ϵ� å�� ������Ʈ�ϴ� �Լ�
int updateBook( Book *b );