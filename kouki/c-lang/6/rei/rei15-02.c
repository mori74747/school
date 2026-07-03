#include <stdio.h>
#include <hamakou.h>
      
struct student {
  int gakunen;      //  学年  
  int kumi;         //   組   
  char namae[20];   //  名前  
};

main()
{
  struct student my_data = { 2, 1, "浜工太郎" };

  printf("学年 = %d\n", my_data.gakunen);
  printf("組   = %d\n", my_data.kumi);
  printf("名前 = %s\n", my_data.namae);

  return(0);
}
