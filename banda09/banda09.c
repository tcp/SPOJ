/* BANDA09 */
#include <stdio.h>

#define maxM 10001
#define maxN 101

int main() {
  int N, M;
  int X, Y, Z;
  int i, j, k;
  int m1, m2, m3;
  int max = -1;
  int buf;
  int m[maxN][maxN] = { 0 };
  
  scanf("%d %d\n", &N, &M);
  
  if (N == 3 || M == 0) {
    printf("1 2 3");
    return;
  }

  for (j = 0; j < M; j++) {
    scanf("%d %d %d", &X, &Y, &Z);
    m[X][Y] = Z;
    m[Y][X] = Z;
  }
  
  for (i = 1; i <= N; i++) {
    for (j = i+1; j <= N; j++) {
      if (max - m[i][j] > 200) continue;
      for (k = j+1; k <= N; k++) {
        if (m[i][j]+m[j][k]+m[i][k] > max) {
          m1 = i; m2 = j; m3 = k;
          max = m[i][j] + m[j][k] + m[i][k];
        }
      }
    }
  }

  printf("%d %d %d\n", m1, m2, m3);
  
  return 0;
}
