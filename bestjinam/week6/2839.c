#include <stdio.h>

int _min(int n1, int n2)
{
  if (n1 == -1 || n2 == -1)
    return (n1 == -1 ? n2 : n1);
  else
    return (n1 > n2 ? n2 : n1);
}

int main(void)
{
  int n;  
  int num[5001];
  int i = 6;

  num[1] = -1;
  num[2] = -1;
  num[3] = 1;
  num[4] = -1;
  num[5] = 1;
  scanf("%d", &n);
  while (i <= n)
  {
    if (num[i - 3] != -1 || num[i - 5] != -1)
      num[i] = _min(num[i - 3], num[i - 5]) + 1;
    else
      num[i] = -1;
    i ++;
  }
  printf("%d\n", num[n]);
  return (0);
}
