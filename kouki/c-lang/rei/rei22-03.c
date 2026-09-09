#include  <stdio.h>   // ファイルに関して定義されているヘッダファイル 
#include  <stdlib.h>  // 標準ライブラリ用ヘッダファイル 

int main()
{
  FILE  *in_fp;  // 入力ファイルへのファイルポインタ 
  FILE  *out_fp; // 出力ファイルへのファイルポインタ 
  char  *in_filename  = "in_num.txt";   // データを入力するファイル 
  char  *out_filename = "out_num.txt";  // データを出力するファイル 
  int   x, y;   // ファイルからの入力データ用入力変数 
  int   z1, z2; // 計算結果を格納する変数 

  in_fp = fopen(in_filename, "r"); // 入力ファイルのオープン 
  if (in_fp == NULL){
    fprintf(stderr, "%sがオープンできませんでした。\n", in_filename);
    exit(8); // 異常終了である非ゼロを返してプログラム終了 
  }

  fscanf(in_fp, "%d", &x); // ファイルから数字を読み取りｘへ格納 
  printf("x = %d\n", x);
  fscanf(in_fp, "%d", &y); // ファイルから数字を読み取りｙへ格納 
  printf("y = %d\n", y);

  fclose(in_fp); // 入力ファイルのクローズ 

  z1 = x + y;
  z2 = x - y;
  printf("z1 = %d\n", z1); // z1を標準出力へ表示 
  printf("z2 = %d\n", z2); // z2を標準出力へ表示 

  out_fp = fopen(out_filename, "w"); // 出力先ファイルのオープン 
  if (out_fp == NULL){
    fprintf(stderr, "%sがオープンできませんでした。\n", out_filename);
    exit(8); // 異常終了である非ゼロを返してプログラム終了 
  }

  fprintf(out_fp, "z1 = %d\n", z1); // z1を出力ファイルへ書き込む 
  fprintf(out_fp, "z2 = %d\n", z2); // z2を出力ファイルへ書き込む 

  fclose(out_fp); //  出力ファイルのクローズ  

  return(0);
}
