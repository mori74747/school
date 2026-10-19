
  #include <stdio.h>
  #include <stdlib.h>
  #include <ctype.h>

  main(int argc, char *argv[])
  {
    FILE *fp;
    unsigned char data[16];
    size_t n;
    int i;
    unsigned long addr = 0;

    if(argc != 2){
      fprintf(stderr, "不正な入力です。\n");
      return 2;
    }

    fp = fopen(argv[1], "rb");
    if(fp == NULL){
      printf("ファイルを開けません。\n");
      return 2;
    }

    printf("%s%2s", "addr","");
    for(i = 0; i < 16; i++){
      printf(" +%X", i);
    }
    printf("%8s%s", "","キャラクタ\n");

    while((n = fread(data, 1, 16, fp)) > 0){
      printf("%04lX%3s", addr, "");

      for(i = 0; i < 16; i++){
        if(i < n){
          printf("%02X ", data[i]);
        }else{
          printf("%3s","");
        }
      }

      printf("%3s", "");

      for(i = 0; i < (int)n; i++){
        if(isprint(data[i])){
          printf("%c", data[i]);
        }else{
          printf(".");
        }
      }

      printf("\n");
      addr += 16;
    }

    fclose(fp);
    return 0;
  }
