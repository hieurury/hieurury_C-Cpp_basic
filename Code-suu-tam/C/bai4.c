#include <stdio.h>

int main() {
  int n;
  int a[100][100];


  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &a[i][j]);
    }
  }

  
  int is_identity = 1;
  for (int i = 0; i < n; i++) {
    if (a[i][i] != 1) {
      is_identity = 0;
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j && a[i][j] != 0) {
        is_identity = 0;
        break;
      }
    }
  }

  
  if (is_identity) {
    printf("True");
  } else {
    printf("False");
  }

  return 0;
}