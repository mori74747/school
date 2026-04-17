#include <stdio.h>

main()
{
  char moji;            // 文字を格納する変数定義     
  
  moji = 'A';           // 文字 A を変数 moji に代入  
  moji++;               // 変数 moji をインクリメント 
  printf("%c\n",moji);  // 変数 moji を文字型で表示   
  moji += 3;            // 変数 moji を +3            
  printf("%c\n",moji);  // 変数 moji を文字型で表示   
  
  return(0);
}
