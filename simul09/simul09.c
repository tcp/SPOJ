/* simul09 */
#include <stdio.h>

#define maxM 1001
#define maxN 1000000000



int main() {
  int N, M;
  int i, j;
  int inv = 0;
  int X, Y;
  int tab[maxM][2];
  char buf;
  long long int sum = 0;
  
  scanf("%d %d", &N, &M);
  
  for (i = 0; i < M; i++) {
    scanf("%*c %c %d %d", &buf, &X, &Y);
//    printf("char is %c, X is %d, Y is %d\n", buf, X, Y);
    if (X > Y) {
      X = X + Y;
      Y = X - Y;
      X = X - Y; 
    }
    if ((int) buf - 'I' == 0) {
      tab[inv][0] = X;
      tab[inv][1] = Y;
      inv++;
    }
    else {
      if (inv == 0) {
        sum = (Y*(Y+1)/2) - (X*(X-1)/2);
        printf("%lld\n", sum);
      }
      else {
  //      printf("this is the table:\n");
        for (j = 0; j < inv; j++)
  //        printf("pos %d : %d - %d\n", j, tab[j][0], tab[j][1]);
  //      printf("entrei, com X = %d, Y = %d!\n", X, Y);
        for (j = X; j <= Y; j++) {
  //        printf("j is %d, inv is %d.\n", j, inv);
          int k = inv;
          int index = j;
          while (k) {
  //          printf("is j on the table? ");
  //          printf("lets see.. %d <= %d <= %d\n", tab[k-1][0], j, tab[k-1][1]);
  //          if (j <= tab[k-1][1]) printf("LOLEI!\n");
            if (j >= tab[k-1][0] && j <= tab[k-1][1]) //{printf("yes. go to ");
              j = tab[k-1][0] + tab[k-1][1] - j; //printf("%d.\n", j);}
            k--;
          }
  //        printf("no.\n");
  //        printf("sum = %lld + %d\n", sum, j);
          sum += j;
  //          sleep(5);
          j = index;
        }
        printf("%lld\n", sum);
      }
      sum = 0;
    }
  }
  
  return 0;
}