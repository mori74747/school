#include <stdio.h>

typedef struct {
    int x;
}Foo;

void Set_Int(Foo *f, int value);
main()
{

    Foo f;
    Set_Int(&f, 10);

    printf("%d\n", f.x);

    return (0);
}

void Set_Int(Foo *f, int value){

    f->x = value;
    return;
}
