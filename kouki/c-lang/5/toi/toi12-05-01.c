#include <stdio.h>
#include <hamakou.h>

int hailstones(int n);

main()
{
  int n, count;

  n = getint("nを入力して下さい: ");

  printf("\n%d から生成されるから生成される「霰」\n\n", n);

  count = hailstones(n);

  printf("\n合計 %d 個\n", count);


  return(0);
}

// [引  数] int型: n
// [戻り値] int型: nの霰の個数ct
// [動  作] n個の霰が空白区切りで表示
int hailstones(int n){
  int ct = 0;
  while(n != 1){
    printf("%d ", n);
    if(n % 2 == 0){
      n = (n / 2);
    }else{
      n = (3*n + 1);
    }
    ct++;
  }
  // 最後の1の表示／カウント
  printf("1\n");
  ct++;
  return(ct);
}