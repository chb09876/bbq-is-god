#include <stdio.h>

void search_doc(char *doc, char *word)
{
    int i, j;
    int cnt;
    i = 0;
    j = 0;
    cnt = 0;

    while (doc[i] != 0)
    {
        if (doc[i] == word[j])
        {
            j++;
            if (word[j] == 0)
            {
                cnt++;
                j = 0;
            }
        }
        else
        {
            j = 0;
            if (doc[i] == word[j])
                j++;
        }
        i++;
    }

    printf("%d", cnt);
}

int main()
{
    char doc[2500];
    char word[50];

    scanf("%[^\n]s", doc);
    getchar();
    scanf("%[^\n]s", word);
    getchar();
    //if (word[3] != '\n')
    //    printf("hey %d\n", word[3]);

    search_doc(doc, word);

    return (0);
}