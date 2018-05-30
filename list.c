#include <stdio.h>
#include <string.h>

void main() {
  char buffer[410000], data[410000];
  int n, i, next[410000];
  int j;

  scanf("%s", buffer);
  n = strlen(buffer)+1;
  for(i = 0; i < n + 1; i++) {
    data[i + 1] = buffer[i];
    next[i] = i + 1;
  }

  for(i = 0; i <= n+1; i++)
    printf("%c  ", data[i]);
  printf("\n");

  for(i = 0; i < n+1; i++)
    printf("%2d ", next[i]);
  printf("\n\n");

  i = 0;
  while(data[next[i]] != 0) {
    if(data[next[i]] == 'a') {
      data[++n] = '!';
      next[n] = next[next[i]];
      next[next[i]] = n;
    }
    else if(data[next[i]] == 'e') {
      do {
        next[i] = next[next[i]];
      } while(data[next[i]] == 'e');
    }
    else {
    }
    printf("---\n");
    printf("%d : %c\n", next[i], data[next[i]]);
    for(j = 0; j <= n+1; j++)
      printf("%c  ", data[j]);
    printf("\n");
    for(j = 0; j < n+1; j++)
      printf("%2d ", next[j]);
    printf("\n");

    i = next[i];
  }

  for(i = 0; i <= n+1; i++)
    printf("%c  ", data[i]);
  printf("\n");

  for(i = 0; i < n+1; i++)
    printf("%2d ", next[i]);
  printf("\n\n");

  for(i = 0; data[next[i]] != 0; i = next[i])
    printf("%c", data[next[i]]);
  printf("\n");
}

