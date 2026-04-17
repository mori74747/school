#include   <stdio.h>

typedef enum {
  Zero, One, Two, Three, Four, Five   //  0〜5 までの定義  
} Num1;
typedef enum {
  Six = 6, Seven, Eight, Nine, Ten    //  6〜10 までの定義  
} Num2;

main()
{
  printf("\nNum1型\n");
  printf("Zero  = %d\n", Zero);
  printf("One   = %d\n", One);
  printf("Two   = %d\n", Two);
  printf("Three = %d\n", Three);
  printf("Four  = %d\n", Four);
  printf("Five  = %d\n", Five);
  printf("\nNum2型\n");
  printf("Six   = %d\n", Six);
  printf("Seven = %d\n", Seven);
  printf("Eight = %d\n", Eight);
  printf("Nine  = %d\n", Nine);
  printf("Ten   = %d\n", Ten);

  return(0);
}
