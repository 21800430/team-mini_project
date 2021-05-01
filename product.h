typedef struct product{
    int no;
    char name[50];
    float weight;
    int price;
    float star;
} Product;

int selectMenu();
void addProduct(Product *p, int index);
void readProduct(Product p);
void updateProduct(Product *p);
int listProduct(Product *p[], int index, int n);
int selectProductNum(Product *p[], int index);
int loadFile(Product *p[]);
int saveFile(Product *p[], int index);
void searchName(Product *p[], int index);
void searchPrice(Product *p[], int index);
void searchStar(Product *p[], int index);
