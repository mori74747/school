#include <stdio.h>
#include <stdlib.h>

int combi(int n, int r);
void combiTail(int n, int r, long long ans[]);

int main(int argc, char *argv[])
{
  int n, r;

  if (argc < 3) {
    fprintf(stderr, "第1引数にnを、第2引数にrを指定してください。\n");
    exit(1);
  }
  sscanf(argv[1], "%d", &n);
  sscanf(argv[2], "%d", &r);

  printf("%d\n", combi(n, r));

  return(0);
}

// パスカルの三角形の上からn段目、左からr番目の値
int combi(int n, int r)
{
  // nCr の分子と分母が大きな値になるので long long で計算する
  long long ans[2] = {1, 1}; // ans[0] … nCr の分子, ans[1] … nCr の分母

  // nCr = nCn-r の関係があるので r と n - r の小さい方で計算
  if (r > n - r) {
    r = n - r;
  }
  combiTail(n, r, ans);

  return(               );
}

// ans[0] は nCr の分子、ans[1]は nCr の分母
void combiTail(int n, int r, long long ans[])
{

}
