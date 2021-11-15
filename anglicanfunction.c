void load(int l)
{
    int i;

    printf("\n\t--------------LOADING--------------\n");
    printf("\t___________________________________\n\n");
    printf("\t");
    for (i = 0; i < l; i++)
    {
        txtcolor(0,9); //block0blue1green2cyan3red4magenta5brown6lightgray7darkgray8lightblue9
        printf(" "); //showspaceinloading
        resetc();
    }
    printf("\n\t___________________________________\n");
}
void txtcolor(int txt, int back)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), back * 16 + txt);
}
void resetc(void)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}
void gotoxy(short x, short y)
{
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void saygoodbye(void)
{
    printf("------------------------------------\n");
    printf("         === > GOODBYE < ===         \n");
    printf("               > ^-^ <               \n");
    printf("------------------------------------\n");
}
int random_between(int min, int max)
{
    int r = (rand() / (float) RAND_MAX) * (max + 1) + min;
    return r > max ? max: r;
}
