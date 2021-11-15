int check, checkgod, checkkill, checkrg, toshop; // check = ดูว่ากดbackไหม checkgod = ดูว่านับถือพระเจ้าไหม checkkill = ดูว่าฆ่าคนไหม checkrg = ดูว่ากดbackตอนสำนึกผิดไหม toshop = ดูว่ากดไปที่shopไหม

int heresy()
{
    int order, heresy = 0;
    system("cls");
    do
    {
        toshop = 0;
        check = 1;
        printf("\n++++++++++++++++++++++++++++++++++++++++++++++++\n");
        txtcolor(2, 0);
        printf("   + High-Low Heresy \n");
        resetc();
        printf("------------------------------------------------\n\n");
        printf("   [1] Check your heresy\n");
        txtcolor(12, 0);
        printf("   [0] Back to main menu\n\n");
        resetc();

        do
        {
            printf("\nSelect your order : ");
            scanf("%d", &order);
            if (order != 0 && order != 1)
            {
                txtcolor(12, 0);
                printf("--->Error !!! Please try again<--- \n");
                resetc();
            }
        } while (order != 0 && order != 1);
        system("cls");
        switch (order)
        {
        case 0:
            break;
        case 1:
            order = recommend();
            break;
        }
    } while (order != 0);
    return toshop;
}

int steal(void) //การขโมย
{
    printf("\n++++++++++++++++++++++++++++++++++ High-Low Heresy ++++++++++++++++++++++++++++++++++\n\n");
    txtcolor(4, 0);
    printf("   - Have you ever stolen from others?\n");
    resetc();
    printf("   [1] Never\n");
    printf("   [2] Less than 1000 baht\n");
    printf("   [3] Less than 10000 baht\n");
    printf("   [4] Less than 100000 baht\n");
    printf("   [5] More than or equal 100000 baht\n");
    txtcolor(12, 0);
    printf("   [0] Back to High-Low Heresy \n\n");
    resetc();
    return input5();
}

int killanimal(void) //การฆ่าสัตว์
{
    printf("\n++++++++++++++++++++++++++++++++++ High-Low Heresy ++++++++++++++++++++++++++++++++++\n\n");
    txtcolor(4, 0);
    printf("   - Have you ever killed a medium to large animal? \n     (larger than or equal to a bird or rat)\n");
    resetc();
    printf("   [1] Never\n");
    printf("   [2] Less than 5\n");
    printf("   [3] Less than 10\n");
    printf("   [4] Less than 25\n");
    printf("   [5] More than or equal to 25\n");
    txtcolor(12, 0);
    printf("   [0] Back to High-Low Heresy\n\n");
    resetc();
    return input5();
}

int lied(void) //การโกหก
{
    printf("\n++++++++++++++++++++++++++++++++++ High-Low Heresy ++++++++++++++++++++++++++++++++++\n\n");
    txtcolor(4, 0);
    printf("   - Have you ever lied and misrepresented the truth? \n");
    resetc();
    printf("   [1] Never\n");
    printf("   [2] Only a few times\n");
    printf("   [3] Not often\n");
    printf("   [4] Often\n");
    printf("   [5] Regularly\n");
    txtcolor(12, 0);
    printf("   [0] Back to High-Low Heresy\n\n");
    resetc();
    return input5();
}

int adultery(void) //การผิดประเวณี
{
    printf("\n++++++++++++++++++++++++++++++++++ High-Low Heresy ++++++++++++++++++++++++++++++++++\n\n");
    txtcolor(4, 0);
    printf("   - Have you ever committed adultery? \n");
    resetc();
    printf("   [1] Never\n");
    printf("   [2] Ever\n");
    txtcolor(12, 0);
    printf("   [0] Back to High-Low Heresy\n\n");
    resetc();
    return input2();
}

int kill(void) //การฆ่าคน
{
    printf("\n++++++++++++++++++++++++++++++++++ High-Low Heresy ++++++++++++++++++++++++++++++++++\n\n");
    txtcolor(4, 0);
    printf("   - Have you ever killed a human? \n");
    resetc();
    printf("   [1] Never\n");
    printf("   [2] Ever\n");
    txtcolor(12, 0);
    printf("   [0] Back to High-Low Heresy\n\n");
    resetc();
    int heresy = input2() * 3;
    if (heresy > 0)
    {
        checkkill = 1;
    }
    else
        checkkill = 0;
    return heresy;
}

void god(void) //การเชื่อในพระเจ้า
{
    int order;
    printf("\n++++++++++++++++++++++++++++++++++ High-Low Heresy ++++++++++++++++++++++++++++++++++\n\n");
    txtcolor(4, 0);
    printf("   - Do you believe in GOD?");
    resetc();
    printf("        (/| o  o |\\)\n");
    printf("   [1] No                            ( (Y)  )  DOG?\n");
    printf("   [2] Yes                            /    \\ \n");
    txtcolor(12, 0);
    printf("   [0] Back to High-Low Heresy");
    resetc();
    printf("       (      )/)\n\n");
    do
    {
        printf("\nSelect your order : ");
        scanf("%d", &order);
        if (order != 0 && order != 1 && order != 2)
        {
            txtcolor(12, 0);
            printf("--->Error !!! Please try again<--- \n");
            resetc();
        }
    } while (order != 0 && order != 1 && order != 2);
    switch (order)
    {
    case 0:
        check = 0;
        break;
    case 1:
        checkgod = 0;
        break;
    case 2:
        checkgod = 1;
        break;
    }
    system("cls");
}

int sum(void) //รวมบาปทั้งหมด
{
    int sum = 0;
    do
    {
        checkrg = 0;
        sum = steal();
    } while (checkrg == 1);
    if (check != 1)
    {
        sum = 0;
    }
    else
    {
        do
        {
            checkrg = 0;
            sum = sum + killanimal();
        } while (checkrg == 1);
    }
    if (check != 1)
    {
        sum = 0;
    }
    else
    {
        do
        {
            checkrg = 0;
            sum = sum + lied();
        } while (checkrg == 1);
    }
    if (check != 1)
    {
        sum = 0;
    }
    else
    {
        do
        {
            checkrg = 0;
            sum = sum + adultery();
        } while (checkrg == 1);
    }
    if (check != 1)
    {
        sum = 0;
    }
    else
    {
        do
        {
            checkrg = 0;
            sum = sum + kill();
        } while (checkrg == 1);
    }
    if (check != 1)
    {
        sum = 0;
    }
    else
        god();
    if (check != 1)
    {
        sum = 0;
    }
    return sum;
}

int regret(int heresy) //ถามความสำนึกผิด
{
    int order, newheresy;
    system("cls");
    printf("\n----------------------------------------------------------------------------\n\n");
    txtcolor(3, 0);
    printf("   - Do you regret your actions?\n");
    resetc();
    printf("   [1] Yes\n");
    printf("   [2] No\n");
    txtcolor(12, 0);
    printf("   [0] Back \n\n");
    resetc();

    do
    {
        printf("\nSelect your order : ");
        scanf("%d", &order);
        if (order != 0 && order != 1 && order != 2)
        {
            txtcolor(12, 0);
            printf("--->Error !!! Please try again<--- \n");
            resetc();
        }
    } while (order != 0 && order != 1 && order != 2);

    switch (order)
    {
    case 0:
        newheresy = 0;
        checkrg = 1;
        break;
    case 1:
        newheresy = heresy / 2;
        checkrg = 0;
        break; //ถ้าสำนึกผิด บาปลดลงครึ่งหนึ่ง
    case 2:
        newheresy = heresy;
        checkrg = 0;
        break;
    }
    return newheresy;
}

int recommend(void) //คำแนะนำ

{
    int order, Sum;
    Sum = sum();
    if (check != 1)
    {
        return 1;
    }
    else
    {
        printf("\n++++++++++++++++++++++++++++++++++ High-Low Heresy ++++++++++++++++++++++++++++++++++\n\n");
        if (Sum <= 30 && checkkill == 0)
        {
            printf("   You are a very good person.                                                     /\\_/\\\n");
            if (checkgod == 0)
            {
                printf("   Even if you don't believe in God, but you can always change your mind.        >( ^ ^ )<\n");
            }
            else
                printf("   Even if you already believe in God, but you can still learn more dogma.       >( ^ ^ )<\n");
            txtcolor(5, 0);
            printf("   We recommend purchasing a Bible book in the Anglican Shop.");
            resetc();
            printf("                       / \\\n");
            printf("                                                                                   (___)S");
        }
        else if (Sum <= 100 && checkkill == 0)
        {
            printf("   You are a good person, but there are still some heresies.                          /\\_/\\\n");
            if (checkgod == 0)
            {
                printf("   let's try changing your mind to believe in God.                                  >( o o )<\n");
            }
            else
                printf("   Even if you already believe in God, but don't forget to always remember God.     >( o o )<\n");
            txtcolor(5, 0);
            printf("   We recommend purchasing a Bible book and Crucifix Mhor-Praa in the Anglican Shop.");
            resetc();
            printf("   / \\\n");
            printf("                                                                                      (___)S");
        }
        else if (Sum <= 250 && checkkill == 0)
        {
            printf("   You are quite a heresy person.                                                               /\\_/\\\n");
            if (checkgod == 0)
            {
                printf("   Why do not you try to rely on God?                                                         >( 0 0 )<\n");
            }
            else
                printf("   God is still by your side. But don't forget to remember and keep worshiping God.           >( 0 0 )<\n");
            txtcolor(5, 0);
            printf("   We recommend purchasing a Bible book, Crucifix Mhor-Praa and Holy water in the Anglican Shop.");
            resetc();
            printf(" / \\\n");
            printf("                                                                                                (___)S");
        }
        else if (Sum <= 560 && checkkill == 1)
        {
            printf("   You have many heresies, but they can be fixed.                                               /\\_/\\\n");
            if (checkgod == 0)
            {
                printf("   Turn to worship God before it's too late.                                                  >( > < )<\n");
            }
            else
                printf("   Pay more attention to worship and following God's dogma.                                   >( > < )<\n");
            txtcolor(5, 0);
            printf("   We recommend purchasing a Bible book, Holy water and Necklace of God in the Anglican Shop.");
            resetc();
            printf("    / \\\n");
            txtcolor(5, 0);
            printf("   At this time, Crucifix Mhor-Praa probably won't help you much. But you can buy it for others.");
            resetc();
            printf("(___)/\n");
        }
        else if (Sum <= 560)
        {
            printf("   You have many heresies, but they can be fixed.                                               /\\_/\\\n");
            if (checkgod == 0)
            {
                printf("   Turn to worship God before it's too late.                                                  >( > < )<\n");
            }
            else
                printf("   Pay more attention to worship and following God's dogma.                                   >( > < )<\n");
            txtcolor(5, 0);
            printf("   We recommend purchasing a Bible book, Holy water and Necklace of God in the Anglican Shop.");
            resetc();
            printf("    / \\\n");
            txtcolor(5, 0);
            printf("   At this time, Crucifix Mhor-Praa probably won't help you much. But you can buy it for others.");
            resetc();
            printf("(___)/\n");
        }
        else if (Sum >= 560)
        {
            printf("   You've come too far to turn back, your heresies are too much to forgive.   /\\_/\\\n");
            printf("   The only thing that will help you is wearing the Necklace of God         >( x x )<\n");
            printf("   and holding the Gun of heaven at all times.                                 / \\\n");
            printf("   Pray to God even if God may not listen to you.                             (___)__\n");
            txtcolor(5, 0);
            printf("   Of course, we have Necklace of God and Gun of heaven for sale in the Anglican Shop.\n");
            resetc();
        }
        printf("\n   [1] Go to Anglican Shop\n");
        txtcolor(12, 0);
        printf("   [0] Back to main menu\n\n");
        resetc();
        do
        {
            printf("\nSelect your order : ");
            scanf("%d", &order);
            if (order != 0 && order != 1)
            {
                txtcolor(12, 0);
                printf("--->Error !!! Please try again<--- \n");
                resetc();
            }
        } while (order != 0 && order != 1);
        if (order == 1)
        {
            toshop = 1;
        }
    }
    system("cls");
    return 0;
}

int input5(void) //รับ 5 order
{
    int heresy = 0, order;
    do
    {
        printf("\nSelect your order : ");
        scanf("%d", &order);
        if (order != 0 && order != 1 && order != 2 && order != 3 && order != 4 && order != 5)
        {
            txtcolor(12, 0);
            printf("--->Error !!! Please try again<--- \n");
            resetc();
        }
    } while (order != 0 && order != 1 && order != 2 && order != 3 && order != 4 && order != 5);
    switch (order)
    {
    case 0:
        check = 0;
        break;
    case 1:
        heresy = 0;
        break;
    case 2:
        heresy = 10;
        heresy = regret(heresy);
        break;
    case 3:
        heresy = 30;
        heresy = regret(heresy);
        break;
    case 4:
        heresy = 70;
        heresy = regret(heresy);
        break;
    case 5:
        heresy = 120;
        heresy = regret(heresy);
        break;
    }
    system("cls");
    return heresy;
}

int input2(void) //รับ 2 order
{
    int order, heresy = 0;
    do
    {
        printf("\nSelect your order : ");
        scanf("%d", &order);
        if (order != 0 && order != 1 && order != 2)
        {
            txtcolor(12, 0);
            printf("--->Error !!! Please try again<--- \n");
            resetc();
        }
    } while (order != 0 && order != 1 && order != 2);
    switch (order)
    {
    case 0:
        check = 0;
        break;
    case 1:
        heresy = 0;
        break;
    case 2:
        heresy = 100;
        heresy = regret(heresy);
        break;
    }
    system("cls");
    return heresy;
}
