#include <stdio.h>
#include <string.h>

#define NAME_SIZE 21
#define KAMOKU_SU 3
#define MAX_SEITO_SU 100
#define KOKUGO 0
#define SUGAKU 1
#define EIGO   2

               {
  char mei[NAME_SIZE];
  char sei[NAME_SIZE];
  int tokuten[KAMOKU_SU];
} Exam;

main()
{
       seito[MAX_SEITO_SU + 1];  // 受験者のデータは生徒番号を添え字とする要素に格納するので１要素多く確保する
  char simei[NAME_SIZE * 2];     // 表示用の氏名を格納するために使う(名:20 + 空白:1 + 名:20 + ヌル文字:1)
  int n, i, no;

  scanf("%d", &n);  // 受験者数の入力
  
  for (i = 1; i <= n; i++) {
    scanf("%d", &no);                    // 生徒番号の入力
    scanf("%s %s %d %d %d",              // 生徒番号 no のデータを seito[no] へ入力
                         ,               // 名の入力
                         ,               // 姓の入力
                                      ,  // 国語の得点の入力
                                      ,  // 数学の得点の入力
                                    );   // 英語の得点の入力
  }

  // 入力データを列を揃えて表示
  for (i = 1; i <= n; i++) {
    strncpy(     ,             , NAME_SIZE);  // simei[]に名を(最大 NAME_SIZE 文字)コピー
    strncat(     , " ", 2);                   // simei[]には名が入っているので、この後ろに空白１文字を追加
    strncat(     ,             , NAME_SIZE);  // simei[]に姓を(最大 NAME_SIZE 文字)追加し、"名 姓" の形にする
    printf("%3d %-40s %3d %3d %3d\n",  // %-40s は 40文字幅で左寄せ
            i,                         // 生徒番号の表示
            simei,                     // 氏名の表示
                                    ,  // 国語の得点の表示
                                    ,  // 数学の得点の表示
                                  );   // 英語の得点の表示
  }

  return(0);
}
