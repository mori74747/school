/*
予想
  cnt == 1 
  cnt == 2
  ...
  cnt == 17  まで続いてプログラムが終了する。
*/

#include <stdio.h>
#include <stdlib.h>
      
#define FOREVER    1
#define STOP      17
      
void f( void );

main()
{
  while (FOREVER) {
    f();
  }
}

void f( void )
{
  static int cnt = 0;

  printf("cnt = %d\n", ++cnt);
  if (cnt == STOP) {
    exit(0);
  }
}

/*
理由
  while(FOREVER)はFOREVERに1が置き換えられることから無限ループに
  関数fを永遠と繰り返す処理になる
  関数f内で宣言された変数 cnt は staticで宣言する静的変数なため、初めの1回だけ宣言／初期化される。
  STOPになるまで関数fに入るたびcntをカウントし続け、"cnt = 1"... と表示し続ける。
  STOPは17に置き換えられるため、17回目の表示が終わった後、if文で判定が真になり、exit()によってプログラムが終了する。
*/