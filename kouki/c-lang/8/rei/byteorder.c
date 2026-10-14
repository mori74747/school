#include <stdio.h>

main()
{
  int i, a = 0x1234ABCD;
  unsigned char byte;
  FILE *fp;

  for (i = 0; i < (int)sizeof(a); i++) {
    // x86プロセッサはリトルエンディアン
    printf("%p: %02X\n", (unsigned char *)&a + i, ((unsigned char *)&a)[i]);
  }
  putchar('\n');

  fp = fopen("byteorder.dat", "w");
  fwrite(&a, sizeof(a), 1, fp);
  fclose(fp);

  fp = fopen("byteorder.dat", "r");
  while (fscanf(fp, "%c", &byte) != EOF) {
    printf("%02X\n", byte);
  }
  fclose(fp);
  
  putchar('\n');

  return(0);
}
