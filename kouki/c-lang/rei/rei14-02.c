#include <stdio.h>
      
void proc( int a );  // 関数プロトタイプ宣言 
void dummy( void );  // 関数プロトタイプ宣言 
      
main()
{
  proc(1);  // １回目の呼び出し 
  dummy();  // 何もしないダミー関数 
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
      
void dummy( void )
{
  int x = -50;

  return;
}
