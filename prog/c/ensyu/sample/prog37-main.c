#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <hamakou.h>

#include "hash.h"

int readData(char *filename, HashEntry tbl[]);
unsigned int elfhash(unsigned char *name, int tbl_size);
int selectMenu(HashEntry tbl[]);
void searchByKey(HashEntry tbl[]);
int updateByKey(HashEntry tbl[]);
void removeByKey(HashEntry tbl[]);
void printHashTableCondition(HashEntry tbl[], int tbl_size);

int main(int argc, char *argv[])
{
  HashEntry tbl[TBL_SIZE];
  char key[KEY_LEN], *value;

  initHashTable(tbl, TBL_SIZE);

  if (argc != 2) {
    // コマンドライン引数が正しくなければプログラム終了
    fprintf(stderr, "Invalid argument!\n");
    exit(5);
  }
  if (readData(argv[1], tbl) == 0) {
    // データファイルが正しく読み込めなければプログラム終了
    fprintf(stderr, "File open error!\n");
    exit(8);
  }

  selectMenu(tbl);	// 処理メニューの選択

  return(0);
}

// キーと値のペアからなるテキストファイルを入力し、ハッシュテーブルに格納する
//	filename：入力ファイル名
//	tbl[]	：ハッシュテーブル
int readData(char *filename, HashEntry tbl[])
{
  char data[VAL_LEN], key[KEY_LEN], value[VAL_LEN];
  FILE *fp;
  int state;
  
  if ((fp = fopen(filename, "r")) == NULL) {
    return(0); 
  } else {
    while (fgets(data, sizeof(data), fp) != NULL) { // テキストファイルから１行入力
      sscanf(data, "%s %s", key, value);            // データをキーと値のペアに分離
      if (updateElement(tbl, key, value) == 0) {    // キーと値のペアをハッシュテーブルに格納
        // メモリの確保に失敗したらプログラムを終了
        fprintf(stderr, "memory allocation failed.\n");
        exit(15);
      }
    }
  }
  fclose(fp);

  return(1);
}

// 処理メニューを選択する
int selectMenu(HashEntry tbl[])
{
  char str[20];
  int num;

  do {
    num = 0;
    do {
      printf("1:検索 2:更新 3:削除 4:全表示 5:全削除 6:終了> ");
      fgets(str, sizeof(str), stdin);
      sscanf(str, "%d", &num);
      // 正しいメニューを選択するまで再入力を繰り返す
    } while (num <= 0 || num > 6);
    putchar('\n');
  
    switch (num) {
    case 1:	// キーによる検索
      searchByKey(tbl);
      break;
    case 2:	// キーによる更新
      if (updateByKey(tbl) == 0) {
        fprintf(stderr, "memory allocation error.\n");
      }
      break;
    case 3:	// キーによる削除
      removeByKey(tbl);
      break;
    case 4:	// ハッシュテーブルの全要素を表示
      printHashTable(tbl, TBL_SIZE);
      break;
    case 5:	// ハッシュテーブルの全要素の削除と終了
    case 6:
      freeHashTable(tbl, TBL_SIZE);
      break;
    }
    putchar('\n');
  } while (num < 6);

  return(num);
}

// キーによる検索
void searchByKey(HashEntry tbl[])
{
  char key[KEY_LEN], *value;

  getstring("Key: ", key);
  if ((value = getValue(tbl, key)) == NULL) {
    printf("Not found.\n");
  } else {
    printf("%s\n", value);
  }
}

// キーによる更新
int updateByKey(HashEntry tbl[])
{
  char key[KEY_LEN], *value, new_value[VAL_LEN];
  int state;

  // 検索するキーを入力し、
  getstring("Key: ", key);
  if ((value = getValue(tbl, key)) == NULL) {
    printf("Not found.\n");
  } else {
    printf("%s -> %s\n", key, value);
  }
  // キーが見つかったら、新しい値で更新
  getstring("new value: ", new_value);
  if ((state = updateElement(tbl, key, new_value)) > 0) {
    printf("%s -> %s\n", key, new_value);
  }
  return(state);
}

// キーによる削除
void removeByKey(HashEntry tbl[])
{
  char key[KEY_LEN], *value;

  getstring("Key: ", key);
  if (removeElement(tbl, key) == 0) {
    printf("Not found.\n");
  } else {
    printf("%s removed\n", key);
  }
}
