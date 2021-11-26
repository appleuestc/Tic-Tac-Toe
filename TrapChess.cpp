#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void play(); //游戏主体
void printboard(char arr[3][3]); //打印棋盘
void human(); //玩家下棋
void compu(); //电脑下棋
int full(); //判断盘满
int result(); //判断输赢
char arr[3][3];
int main()
{
    srand((unsigned int)time(NULL));
    int a, b;
    for (a = 0; a < 3; a++)
    {
        for (b = 0; b < 3; b++)
        {
            arr[a][b] = '.';
        }
    }
    play();
}
void play()
{
    int flag = 0;
    printboard(arr);
    while (1)
    {
        printf("Your turn.\n");
        human();
        printboard(arr);
        flag = result();
        if (flag == 1)
        {
            printf("You win!\n");
            break;
        }
        flag = full();
        if (flag == 2)
        {
            printf("The board is full.Game ends.\n");
            break;
        }
        printf("Computer's turn.\n");
        compu();
        printboard(arr);
        flag = result();
        if (flag == 1)
        {
            printf("You lose!\n");
            break;
        }
    }
    getchar();
    getchar();
}
void printboard(char arr[3][3])
{
    int a, b;
    for (a = 0; a < 3; a++)
    {
        for (b = 0; b < 3; b++)
        {
            printf("%c", arr[a][b]);
        }
        printf("\n");
    }
}
void human()
{
    printf("Enter a place.\n");
    int x, c, d;
    while (1) {
        scanf_s("%d", &x);
        c = 2 - (x - 1) / 3;
        d = (x - 1) % 3;
        if (((c >= 0) && (c <= 2)) && ((d >= 0) && (d <= 2)))
        {
            if (arr[c][d] == '.')
            {
                arr[c][d] = 'X';
                break;
            }
            else
            {
                printf("There's already a chess.\n");
            }
        }
        else
        {
            printf("You entered a wrong place.\n");
        }
    }
}
int result()
{
    //行
    int i = 0;
    for (i = 0; i < 3; i++)
    {
        if (((arr[i][0] == arr[i][1]) && (arr[i][1] == arr[i][2])) &&
            ((arr[i][0] != '.')))
        {
            return 1;
        }
    }
    //列
    for (i = 0; i < 3; i++)
    {
        if ((arr[0][i] == arr[1][i]) && (arr[1][i] == arr[2][i]) && ((arr[0][i] !=
            '.')))
        {
            return 1;
        }
    }
    //对角线
    if ((arr[0][0] == arr[1][1]) && (arr[1][1] == arr[2][2]) && ((arr[0][0] != '.')))
    {
        return 1;
    }
    if ((arr[0][2] == arr[1][1]) && (arr[1][1] == arr[2][0]) && ((arr[0][2] != '.')))
    {
        return 1;
    }
}
void compu()
{
    int e, f;
    while (1)
    {
        e = rand() % 3;
        f = rand() % 3;
        if (arr[e][f] == '.')
        {
            arr[e][f] = 'O';
            break;
        }
    }
}
int full()
{
    int h, i, count = 0;
    for (h = 0; h < 3; h++)
    {
        for (i = 0; i < 3; i++)
        {
            if (arr[h][i] != '.')
            {
                count++;
            }
        }
    }
    if (count == 9)
    {
        return 2;
    }
}