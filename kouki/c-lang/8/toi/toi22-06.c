#include <stdio.h>
#include <stdlib.h>

main()
{
  FILE *in_file;      // 入力ファイルのファイルポインタ
  FILE *out_file;     // 出力ファイルのファイルポインタ
  int num;            // 入力用整数
  int count = 0;      // データ数
  long long sum = 0;  // 合計
  double avg;         // 平均
  char buff[256];     // 入力用バッファ変数

  // 入力ファイルのオープン
  in_file = fopen("sum.dat", "r");
  // エラー処理
  if(in_file == NULL){
    fprintf(stderr, "ファイルを開けません。\n");
    exit(2); // 異常終了である非ゼロを返してプログラム終了
  }

  // 数値の読み込み→カウント
  while(fgets(buff, sizeof(buff), in_file) != NULL){
    sscanf(buff, "%d", &num);
    sum += num;
    count++;
  }

  fclose(in_file); // 入力ファイルのクローズ

  // 結果の表示
  if(count == 0){
    printf("データ数: %d\n", count);
  }else{

    avg = (double)sum / count;

    printf("データ数: %d\n", count);
    printf("合計%4s: %lld\n", "", sum);
    printf("平均%4s: %.1f\n", "", avg);

    // 出力ファイルのオープン
    out_file = fopen("sum.ans", "w");
    // エラー処理
    if(out_file == NULL){
      fprintf(stderr, "出力ファイルを作成できません。\n");
      exit(2); // 異常終了である非ゼロを返してプログラム終了
    }

    fprintf(out_file, "データ数: %d\n", count);
    fprintf(out_file, "合計%4s: %lld\n", "", sum);
    fprintf(out_file, "平均%4s: %.1f\n", "", avg);
  }
  fclose(out_file); // 出力ファイルのクローズ

  return (0);
}
