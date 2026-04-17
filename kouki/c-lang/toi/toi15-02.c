#include <stdio.h>
      
struct student {
  int id;         // 出席番号 
  char name[20];  // 氏名 
  int kokugo;     // 国語の点数 
  int suugaku;    // 数学の点数 
  int eigo;       // 英語の点数 
};

main()
{
  struct student data[4] = {
    {1, "浜工太郎",  65,  90, 100},
    {2, "藤枝花子",  82,  73,  63},
    {3, "青島一郎",  74,  31,  41},
    {4, "島田和馬", 100,  95,  98},
  };

  int i;

  for (i = 0; i < 4; i++){
    printf("%d %s の合計点は",         ,           );
    printf("           \n",                                );
  }

  return(0);
}
