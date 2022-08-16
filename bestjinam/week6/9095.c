#include <stdio.h>

int main (void)
{
  int n, num;
  int res[10];
  int i;

  res[0] = 1;
  res[1] = 2;
  res[2] = 4;

  i = 3;
  while (i < 10)
  {
    res[i] = res[i-1] + res[i-2] + res[i-3];
    i ++;
  }
  scanf("%d", &n);
  while (n--)
  {
    scanf("%d", &num);
    printf("%d\n", res[num - 1]);
  }
  return 0;
}
