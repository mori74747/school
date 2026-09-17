#define QUEUE_SIZE 10           // キューの大きさ(保存したい要素数+1)

typedef struct {
    int storage[QUEUE_SIZE];    // [queue1.c]整数データを格納する配列
    int head;                   // [queue1.c]次に取り出すデータの位置 [queue2.c]最後に取り出したデータの位置
    int tail;                   // [queue1.c]次にデータを格納する位置 [queue2.c]最後に格納したデータの位置
} Queue;

void initQueue(Queue *q);
int  enQueue(Queue *q, int data);
int  deQueue(Queue *q, int *data);