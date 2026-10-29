typedef List* Stack;

void initStack(Stack *s);
int push(Stack *s, int data);
int pop(Stack *s, int *data);
void freeStack(Stack *s);