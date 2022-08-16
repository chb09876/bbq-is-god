#include <stdio.h>

int main(void)
{
  int n;

  scanf("%d", &n);
  printf("%s\n", (n % 2 == 0 ? "CY" : "SK"));
  return (0);
}

