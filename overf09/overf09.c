/* OVERF09 @ br.spoj.pl */
#include <stdio.h>

int main() {
  int N, P, Q;
  char c;
  
  scanf("%d", &N);
  
  scanf("%d %c %d", &P, &c, &Q);
  
  if (c == '*') {
    if (P * Q <= N) {
      printf("OK\n");
      return 0;
    }
  }
  else {
    if (P + Q <= N) {
      printf("OK\n");
      return 0;
    }
  }
  
  printf("OVERFLOW\n");
  
  return 0;
}