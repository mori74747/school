#include <stdio.h>
#include <hamakou.h>

int main()
{
  int n = getint("開始要素数を入力：");
  int i = n;

  while (1) {

    int a[i];

    printf("a[]の大きさ: %dバイト\n", (int)sizeof(a));
    printf("a[]の要素数: %d個\n", (int)(sizeof(a) / sizeof(int)));

    a[i] = i;
    printf("a[%d] = %d\n", i, a[i]);
    printf("----------------------\n");
    i++;   // 1個ずつ増やす
  }

  return(0);
}
