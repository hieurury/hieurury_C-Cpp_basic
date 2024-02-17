#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);

  if (n >= 1 && n < 1000) {
    int a[n][n];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        a[i][j] = (i == 0 || i == n - 1 || j== 0 || j == n - 1 || i == j || i + j == n - 1) ? '#' : ' ';
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        printf("%c ", a[i][j]);
      }
      printf("\n");
    }
  } 

  return 0;
}