#include <stdio.h>
#include <string.h>

int main()
{
    char doc[2501];
    gets(doc);
    char search[51];
    gets(search);

    int count = 0;
    char *work = doc;
    while (*work)
    {
        if (strncmp(work, search, strlen(search)) == 0)
        {
            work += strlen(search);
            ++count;
        }
        else
            ++work;
    }
    printf("%d", count);
}