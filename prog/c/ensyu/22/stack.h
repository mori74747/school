#define STACK_SIZE 10        // スタックのデータ格納領域の大きさ

typedef struct{
    int storage[STACK_SIZE]; // スタックのデータ格納領域
    int sp;                  // 次に格納するデータの位置(初期値は0)
} Stack;

void initStack(Stack *s);
int push(Stack *s, int data);
int pop(Stack *s, int *data);