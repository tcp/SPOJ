#include <stdio.h>

#define ML 201  /* max lines */
#define MC 201  /* max columns */
#define K  2001 /* max swaps */

int main() {
  int LN[ML], CN[MC];       /* line holder LN, column CN */
  int L, C, i, j;           /* number of lines L, columns C */
  int N;                    /* first number */
  int temp = 0;
  int inv[K];               /* holds all inversions */
  int swapL = 0, swap;      /* swapL swap for lines, total swap (times 2) */
  int cm;                   /* column multiplier */

  /* get L, C and the first number N */
  scanf("%d %d\n", &L, &C);
  scanf("%d", &N);
  
  /* the column multiplier, 'cm', is something I came up with so we dont have
   * to perform mod operations to calculate the column position of every number
   * in a column. The 'cm' should be multiple of C that is lower than the mini-
   * mum value of the first line. Note that we all we need is the one value of
   * the first line and the number of column C. With the column multiplier, we
   * can calculate the position of the numbers more easily.
   *
   * for example:
   * Take input 4 3 2 1 (C = 4). The 'cm' should be 0, so that:
   * 
   * 4 --> pos 4 --> 4 - 4 * 0
   * 3 --> pos 3 --> 3 - 4 * 0
   * 2 --> pos 2 --> 2 - 4 * 0
   * 1 --> pos 1 --> 1 - 4 * 0
   *
   * For input 8 7 6 5 (C = 4), the 'cm' should be 4, which gives us:
   * 
   * 8 --> pos 4 --> 8 - 4 * 1
   * 7 --> pos 3 --> 7 - 4 * 1
   * 6 --> pos 2 --> 6 - 4 * 1
   * 5 --> pos 1 --> 5 - 4 * 1
   *
   * From that, we get that pos = number - C * cm. Doing this more times we can
   * state that cm = [(number - 1) / C] * C. Do not cancel, as we are working 
   * with ranges here.
   *
   * Bear in mind that this is done to calculate the ~position~ of each number.
   * Not the distance to the numbers actual placement (column).
   */
  cm = (N - 1) / C;
  cm = cm * C;
  
  /* Calculate column 1 */
  CN[1] = N - cm - 1;

  /* Calculate line 1 */
  LN[1] = 0;

  /* replaces division */
  while (N > 0) {
    N -= C;
    LN[1] = LN[1] + 1;
  }

  LN[1] -= 1;
  
  /* get numbers and calculate column distance */
  for (i = 2; i <= C; i++) {
    scanf("%d", &CN[i]);
    CN[i] = CN[i] - cm - i; /* calculates distance to correct position*/
  }

  /* get numbers and calculate line distance */
  for (i = 2; i <= L; i++) {
    LN[i] = 0;
    scanf("%d%*[^\n]", &temp);
    while (temp > 0) {
      temp -= C;
      LN[i] = LN[i] + 1;
    }
    LN[i] = LN[i] - i;
  }

  // move : lines
  for (i = 1; i <= L; i++) {
    while (LN[i]) {
      temp = LN[i];
      LN[i] = LN[i] + LN[i+LN[i]];
      LN[i+temp] = 0;
      inv[swapL++] = i+temp;
      inv[swapL++] = i;
    }
  }
  
  /* assignment so we can continue counting column swaps */
  swap = swapL;

  // move : columns
  for (i = 1; i <= C; i++) {
    while (CN[i]) {
      temp = CN[i];
      CN[i] = CN[i] + CN[i+CN[i]];
      CN[i+temp] = 0;
      inv[swap++] = i+temp;
      inv[swap++] = i;
    }
  }
  
  // print # swaps
  printf("%d\n", swap >> 1);

  // print line and column swaps
  for (i = 0; i < swapL; i += 2)
    printf("L %d %d\n", inv[i], inv[i+1]);
    
  for (i = swapL; i < swap; i += 2)
    printf("C %d %d\n", inv[i], inv[i+1]);

  return 0;

}
