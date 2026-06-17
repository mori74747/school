#include <stdio.h>

int global = 1;  //  グローバル変数  

main()
{
  int local = 2;  //  ローカル変数  

  printf("global = %d\n", global); //  グローバル変数 global が使用できる  
  printf("local = %d\n", local);   //  ローカル変数 local が使用できる  
  //  ここから新しいブロック  
  {
    int very_local;  //  ブロック内のローカル変数  

     very_local = global + local;  // 外側のブロックの変数は参照可
     printf("very_local = %d\n", very_local);  //  このブロック内で使用可  
     global *= 10; // 外側のブロックの変数は参照可
     local *= 10;  // 外側のブロックの変数は参照可
  }
  printf("very_local = %d\n", very_local);     // 使用不可（エラーとなる） 
  printf("local = %d\n", local);
  printf("global = %d\n", global);

  return(0);
}
