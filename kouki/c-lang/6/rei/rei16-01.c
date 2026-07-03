#include <stdio.h>
      
typedef struct {
  int gakunen;      //  学年  
  int kumi;         //   組   
  char namae[20];   //  名前  
} Student;

main()
{
  Student my_data = { 2, 1, "浜工太郎" };

  printf("学年 = %d\n", my_data.gakunen);
  printf("組   = %d\n", my_data.kumi);
  printf("名前 = %s\n", my_data.namae);

  return(0);
}
