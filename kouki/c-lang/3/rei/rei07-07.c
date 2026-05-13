#include <stdio.h>
#include <hamakou.h>

main()
{
  int n, i;
  n = getint("要素数を入力してください：");
  int a[n];
  
  printf("a[]の大きさ: %dバイト\n", sizeof(a));
  printf("a[]の要素数: %d個\n", sizeof(a) / sizeof(int));
  for (i = 0; i < n; i++) {
    a[i] = i;
  }

  for (i = 0; i < n; i++) {
    printf("a[%d] = %d\n", i, a[i]);
  }

  return(0);
}
