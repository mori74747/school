#include <stdio.h>

#define DATA_SIZE  20  //  データの個数の設定  

int input( void );     //  関数input のプロトタイプ宣言  

main()
{
  int data[DATA_SIZE];  //  データを格納する配列  
  int max_idx;          //  最大値の番号を格納する変数  

  int i,j, work;

  /*============ データの入力 ============*/
  printf("\n＜＜%d個のデータを入力してください＞＞\n" ,DATA_SIZE);
  for (i = 0; i < DATA_SIZE; i++) {
    printf("data[%2d] = " ,i);
    data[i] = input();
  }

  /*========== データの並べ換え ==========*/
  for (i = 0; i < DATA_SIZE - 1; i++) {
    max_idx = i;                      // 仮の最大値の番号を保存 
    for (j = i + 1; j < DATA_SIZE; j++) {
      if (data[max_idx] < data[j]) {  // 並べ換えの必要があるか 
        max_idx = j;                  // 最大値の番号を保存 
      }
    }
    if (max_idx != i) {               // max_idx が変化しているか 
      work          = data[i];        // -+                
      data[i]       = data[max_idx];  //  |- 入れ替え処理  
      data[max_idx] = work;           // -+                
    }
  }

  /*============= 結果の出力 =============*/
  printf("\n** 降順に並べ換えた結果 **\n");
  for (i = 0; i < DATA_SIZE; i++) {
    printf("%2d番目＝%d\n", i + 1, data[i]);  //  ソート後のデータ表示  
  }

  return(0);
}

/*----------------------------------+
 | 整数値の入力                     |
 | 関数名：input                    |
 | 引数  ：無し                     |
 | 戻り値：入力した整数（int型）    |
 +----------------------------------*/
#define BUFF_SIZE  100  //  バッファサイズ設定  

int input( void )
{
  char line[BUFF_SIZE];  //  データ入力用ラインバッファ    
  int dat;               //  入力された数値を格納する変数  

  fgets(line, sizeof(line), stdin);  //  データ入力  
  sscanf(line, "%d", &dat);          //  数値に変換  

  return(dat);
}
