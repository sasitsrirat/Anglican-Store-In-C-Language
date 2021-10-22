void load(int l)
{
    int i;

    gotoxy(35,1); printf("\t--------------LOADING--------------\n");
    gotoxy(35,2);printf("\t___________________________________\n\n");
    gotoxy(35,3);printf("\t");
    for (i = 0; i < l; i++)
    {
        txtcolor(0,9); //block0blue1green2cyan3red4magenta5brown6lightgray7darkgray8lightblue9
        printf(" "); //showspaceinloading
        resetc();
    }
    gotoxy(35,4); printf("\t___________________________________\n");
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
void saygoodbye()
{
    printf("------------------------------------\n");
    printf("         === >GOODBYE < ===         \n");
    printf("              > ^-^ <               \n");
    printf("------------------------------------\n");
}
