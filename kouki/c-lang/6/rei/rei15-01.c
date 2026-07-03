#include <stdio.h>
#include <hamakou.h>
      
struct student {
  int gakunen;      //  学年  
  int kumi;         //   組   
  char namae[20];   //  名前  
};

main()
{
  struct student my_data;

  my_data.gakunen = getint("学年: ");
  my_data.kumi = getint("組: ");
  getstring("名前: ", my_data.namae);

  printf("学年 = %d\n", my_data.gakunen);
  printf("組   = %d\n", my_data.kumi);
  printf("名前 = %s\n", my_data.namae);

  return(0);
}
