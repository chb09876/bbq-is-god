#include <stdio.h>
#include <stdlib.h>
int main(void)
{
  int n;
  int coin;
  int total;
  int i;
  int *res;

  scanf("%d", &n);
  scanf("%d", &total);
  res = calloc(sizeof(int), (total + 1));
  while (n--)
  {
    scanf("%d", &coin);
    i = coin;
    res[i] += 1;
    while (i <= total)
    {
      res[i] += res[i - coin];
      i++;
    }
  }
  printf("%d\n", res[total]);
  free(res);
  return (0);
}

