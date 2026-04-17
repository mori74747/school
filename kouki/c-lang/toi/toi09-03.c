#include <stdio.h>
      
main() // 3行5列の表の各行と列の合計を、最終行と最終列に格納後、表を表示する 
{
  int row, col;
  int t[5][3] = {
    {10,20,30,40,50},{11,12,13,14,15},{21,22,23,24,25}
  };

  for (row = 0; row < 3; row++) {
    for (col = 0; col < 5; col++) {
      t[5][col] = t[5][col] + t[row][col]; // 行データの合計 
      t[row][3] = t[row][3] + t[row][col]; // 列データの合計 
    }
    t[5][3] = t[5][3] + t[5][row];         // 合計の合計を求める 
  }
  for (row = 0; row < 3; row++) {          // 表中のデータを合計と共に表示する  
    for (col = 0; col < 5; col++) {
      printf("%3d ",t[row][col]);
    }
    printf('\n');
  }
  return(0);
}
