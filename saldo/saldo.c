/* SALDO @ br.spoj.pl */
#include <stdio.h>

#define MAX(a,b) (a) > (b) ? (a) : (b)

int main() {
  int N, A, B;
  int i;
  int k = 1;
  int max, new_max;
  int start, stop, temp;
  
  scanf("%d\n", &N);

  while (N) {
    max = 0;
    new_max = 0;
    start = 0;
    stop = 0;
    temp = 1;
    
    for (i = 1; i <= N; i++) {
      scanf("%d %d\n", &A, &B);
     
      new_max = MAX(A-B, new_max+A-B);
      
      if (new_max == 0) {
        continue;
      }
      else if (new_max < 0) {
        new_max = 0;
        temp = i+1;
      }
      else if (max <= new_max) {
        start = temp;
        max = new_max;
        stop = i;
      }
    }
    
    printf("Teste %d\n", k++);

    if (start == 0 || start == N+1)
      printf("nenhum\n\n");
    else if (start && stop == 0)
      printf("%d %d\n\n", start, N);
    else
      printf("%d %d\n\n", start, stop);

    scanf("%d\n", &N);
  }
  
  return 0;
}