#define STACK_SIZE 20        // スタックのデータ格納領域の大きさ

typedef struct{
    char storage[STACK_SIZE]; // スタックのデータ格納領域
    int sp;                   // 次に格納するデータの位置(初期値は0)
} Stack;

void initStack(Stack *s);
int push(Stack *s, char data);
int pop(Stack *s, char *data);