#include <stdio.h>

int validate(int board[], int N, int new);
void queen(int board[], int N, int level);

int BOARD[15] = {
    0,
};
int COUNT = 0;

int main()
{
    int N;
    scanf("%d", &N);
    queen(BOARD, N, 0);
    printf("%d", COUNT);
}

int validate(int board[], int N, int new)
{
    for (int i = 0; i < new; ++i)
    {
        if (board[i] == board[new] ||
            (i - new == board[i] - board[new] || new - i == board[i] - board[new]))
            return 0;
    }
    return 1;
}
void queen(int board[], int N, int level)
{
    if (level == N)
        ++COUNT;
    else
    {
        for (int i = 1; i <= N; ++i)
        {
            board[level] = i;
            if (validate(board, N, level))
                queen(board, N, level + 1);
            board[level] = 0;
        }
    }
}