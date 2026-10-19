
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

  // 入力ファイルのオープン
  in_file = fopen("sum.dat", "r");
  // 例外処理
  if(in_file == NULL){
    fprintf(stderr, "ファイルを開けません。\n");
    exit(2);
  }

  // 数値の読み込み→カウント
  while(fscanf(in_file, "%d", &num) == 1){
    sum += num;
    count++;
  }

  // 入力ファイルのクローズ
  fclose(in_file);

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
    // 例外処理
    if(out_file == NULL){
      fprintf(stderr, "出力ファイルを作成できません。\n");
      exit(2);
    }

    fprintf(out_file, "データ数: %d\n", count);
    fprintf(out_file, "合計%4s: %lld\n", "", sum);
    fprintf(out_file, "平均%4s: %.1f\n", "", avg);
  }
  // 出力ファイルのクローズ
  fclose(out_file);

  return (0);
}
