/* bact09 */
#include <stdio.h>
#include <stdint.h>
#include <math.h>

int main() {
  int N;
  int D, C;
  int i, pos;
  int buf;
  float max, D2;
  
  /* get N */
  scanf("%d\n", &N);
  
  max = -1;

  for (i = 0; i < N; i++) {
    scanf("%d %d\n", &D, &C);
    
    D2 = C*logs[D];

    if (D2 > max) {
      pos = i;
      max = D2;
    }
  }
  
  printf("%d", pos);
  
  return 0;
}
