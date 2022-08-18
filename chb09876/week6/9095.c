#include <stdio.h>

int recipe[11];

int get_recipe(int N)
{
    if (!recipe[N])
        recipe[N] = get_recipe(N - 1) + get_recipe(N - 2) + get_recipe(N - 3);
    return recipe[N];
}

int main()
{
    recipe[1] = 1;
    recipe[2] = 2;
    recipe[3] = 4;
    int T;
    scanf("%d", &T);
    while (T)
    {
        int n;
        scanf("%d", &n);
        printf("%d\n", get_recipe(n));
        --T;
    }
}