#include <stdio.h>
      
void proc( int a ); // 関数プロトタイプ宣言 
      
main()
{
  proc(1);  // １回目の呼び出し 
  proc(2);  // ２回目の呼び出し 
      
  return(0);
}

void proc( int a )
{
  int b;  // ローカル変数宣言（初期化していないので値は不明） 
 
  printf("a = %d, b = %d\n", a, b);
       
  b = 10;
 
  return;
}
