#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "anglicanfunction.c"
#include "hlheresy.c"

struct customer
{
    char name[50];
    int password;
    int db1,db2,db3,db4;
}ct;

typedef struct
{
    char name[100];
    char pos[100];
    char htr[100];

}information;


void main()
{
    char username[50];
    int program, order, sum = 0, i = 0,checkpassword,check=0,method,transport=0,mem=0,mem2=0,p3=0,p1=0; //กำหนดให้ทุกอย่างเป็นค่าเริ่มต้น
    int debit1, debit2, debit3, debit4;
    int d1,d2,d3,d4;
    char clear;
    char address[100];

    //play for discount 
    int ans, secret, count,reward=0,discount = 0,laps = 0;
    int lo = 0,up = 99;

    information data;
    int numcount,j,k=0,switch1;


    for (int countload = 0; countload < 36; countload++) //lengthofloading
    {
        load(countload);
        Sleep(rand()%10); //timeofloading
        system("cls");
    }

    FILE *pt;
    pt = fopen("data.txt", "a+");

    printf(" --> Enter Username : ");
    fflush(stdin);
    gets(username); //scanf("%[^\n]",username); <-- this method will bugs

    while(!feof(pt)) //check user.txt
    {
        fscanf(pt,"%s%d%d%d%d%d",ct.name,&ct.password,&ct.db1,&ct.db2,&ct.db3,&ct.db4);
        if (strcmp(ct.name,username)==0 && check !=1) //ตรวจว่า username ที่กรอกมากับ ct.name ที่อยู่ในไฟล์ตรงกันไหม ถ้าตรงคือลูกค้าเก่า
        {
            printf("----------------------------------------\n");
            txtcolor(10, 0);
            printf("     Welcome Back!! %s\n",ct.name);
            //printf("%d %d %d %d",ct.db1,ct.db2,ct.db3,ct.db4); โชว์เลขบัตร
            d1 = ct.db1 ; 
            d2 = ct.db2 ;
            d3 = ct.db3 ;
            d4 = ct.db4 ;
            resetc();
            printf("----------------------------------------\n");
            check = 1; //กำหนดให้ check = 1 คือลูกค้าเก่า

            do{
                printf(" --> Enter password : "); scanf("%d",&checkpassword); 
                if(checkpassword==ct.password) break; //ถ้ากรอกรหัสแล้วตรง หลุดลูป
                if(checkpassword != ct.password) //ถ้าไม่ตรงใส่ใหม่
                {
                    printf("-----------------------------------------------");
                    printf("\n Wrong password Please Enter password again!");
                    printf("\n-----------------------------------------------\n");
                }
            }while(checkpassword != ct.password);
        }
    }

    if(check==0) //ลูกค้าหน้าใหม่ใสซื่อบริสุทธิ์
    {
        printf("---------------------------");
        printf("\n== Welcome to our shop ==");
        printf("\nEnter you new password (4 Number Only): ");
        scanf("%d",&checkpassword);
    }
    system("cls");

    //start main programs
    do
    {
        //showontop
        printf("\n-----------------------------------------------------------\n");
        txtcolor(14,0);
        printf("|  _   _   _ ___ _  _ ___ _   _   __                      |\n");
        printf("| |_) |_) / \\ | |_ /   | / \\ |_) (_                       |\n");
        printf("| |_  |_\\ \\_/ | |_ \\_  |___/__ \\ __)___ __  _        __   |\n");
        printf("| / \\ |_) /__  /\\  |\\ |  |   /  /\\  |   |  / \\ |\\ | (_    |\n");
        printf("| \\_/ | \\ \\_| /--\\ | \\| _|_ /_ /--\\ |  _|_ \\_/ | \\| __)   |\n\n");
        resetc();
        printf("-----------------------------------------------------------\n");
        printf("=======================================\n");
        txtcolor(15,0);
        time_t rawtime; time(&rawtime);
        printf("   %s",ctime(&rawtime)); //ctime(&rawtime)gotoxy(2,9);
        printf("|| Username : %10s             ||\n",username);
        printf("|| Your order : %5d Orders         ||\n",i);
        printf("|| Cost       : %5d THB            ||\n",sum);
        resetc();
        printf("=======================================\n");
        //showontop
        printf("---------------------------------------\n");
        printf("         Name of programs         \n");
        printf("---------------------------------------\n");
        printf("\n||   Anglican Shop         [1]  ||\n"); // ร้านขายของของ
        printf("||   Corpserve             [2]  ||\n");   // รับศพไร้ญาติ
        printf("||   Church Delivery       [3]  ||\n");   // บริการจองรถขนศพ
        printf("||   High-Low Heresy       [4]  ||\n");   //คำนวนบุญบาป
        printf("||   Payment Method        [5]  ||\n");   //จ่าบเงินและส่งของ
        printf("||   Play For Discount     [6]  ||\n");
        printf("||   Exit program          [7]  ||\n");

        do
        {
            printf("\nSelect programs by press number : "); 
            
            if (scanf("%d", &program) != 1)
            {
                printf("error\n");
            }
            if (program != 1 && program != 2 && program != 3 && program != 4 && program != 5 && program != 5 && program != 6 && program != 7)
            {
                printf("---------------------------------------\n");
                txtcolor(12, 0);
                printf(" !!!Error!!! Please try again %d\n",program);
                resetc();
                printf("---------------------------------------\n");
            }
        } while (program != 1 && program != 2 && program != 3 && program != 4 && program != 5 && program != 6 && program != 7);

        switch (program)
        {
            case 1: //anglicanshop
            bookmark1:
            {
                do
                {
                    system("cls");
                    printf("=======================================\n");
                    txtcolor(15,5);
                    printf(" Number of your order : %5d Orders   \n",i);
                    printf(" Cost : %5d THB                      \n",sum);
                    resetc();
                    printf("=======================================\n");
                    txtcolor(2,0);
                    printf("   + Anglican Shop");
                    resetc();
                    printf("\n---------------------------------------\n");
                    printf("   -- List of item   \n");
                    printf("   [1] Holy water             150THB\n");
                    printf("   [2] Gun of heaven          990THB\n");
                    printf("   [3] Crucifix Mhor-Praa     80THB\n");
                    printf("   [4] Bible Book             50THB\n");
                    printf("   [5] Necklace of God        600THB\n");
                    printf("   [6] Reset order\n");
                    txtcolor(12, 0);
                    printf("   [0] Back\n");
                    resetc();
                    //shopmenu();

                    do
                    {
                        printf("\nSelect your order : ");
                        scanf("%d", &order);
                        if ((order != 0 && order != 1 && order != 2 && order != 3 && order != 4 && order != 5 && order != 6))
                        {
                            printf("---------------------------------------\n");
                            txtcolor(12, 0);
                            printf(" !!!Error!!! Please try again \n");
                            resetc();
                            printf("---------------------------------------\n");
                        }
                    } while (order != 0 && order != 1 && order != 2 && order != 3 && order != 4 && order != 5 && order != 6);

                    switch (order)
                    {
                        case 0: i--; break;
                        case 1: sum += 150; break;
                        case 2: sum += 990; break;
                        case 3: sum += 80; break;
                        case 4: sum += 50; break;
                        case 5: sum += 600; break;
                        case 6: mem2 = 0; p3 = 0; sum = 0; i = 0 , mem = 0; i--; p1--; break;
                    } i++; p1 = 1;
                } while (order != 0); 
                system("cls");
            }break;

            case 2: // Corpserve
            {
                do
                {
                    system("cls");
                    txtcolor(14, 0);
                    printf("============================\n");
                    printf("||                        ||\n");
                    printf("||  Welcome to corpserve  ||\n");
                    printf("||                        ||\n");
                    printf("============================\n");
                    resetc();

                    printf("  Go back to main menu [0]\n");
                    printf("               stay in [1]\n");
                    printf("Input:");
                    scanf("%d", &k);

                    switch (k)
                    {
                    case (0):
                        break;
                    case (1):
                        system("cls");
                        txtcolor(14, 0);
                        printf("============================\n");
                        printf("||                        ||\n");
                        printf("||  Welcome to corpserve  ||\n");
                        printf("||                        ||\n");
                        printf("============================\n");
                        resetc();
                        printf("\n");
                        printf("Input Corpse position : ");
                        fflush(stdin);
                        gets(data.pos);
                        printf("---------------------------\n");

                        printf("Input the deceased name in English : ");
                        fflush(stdin);
                        gets(data.name);
                        printf("---------------------------\n");

                        printf("Input the deceased data : ");
                        fflush(stdin);
                        gets(data.htr);

                        printf("---------------------------\n");
                        system("cls");
                        printf("corpse position : %s \n", data.pos);
                        printf("deceased name   : %s\n", data.name);
                        printf("deceasd data    : %s\n\n", data.htr);
                        printf("Do you want to change your details \nYes press [1]  No press [0]\n:");
                        fflush(stdin);
                        scanf("%d", &switch1);
                        if (switch1 == 0)
                        {
                            printf("---------------------------------\n");
                            txtcolor(14, 0);
                            printf("we will pick up the corpse soon\n");
                            resetc();
                            printf("---------------------------------\n");
                            printf("\npress Enter for back to menu .....\n");
                            getch();
                            break;
                        }
                    }
                    break;
                } while (1);
                system("cls");
            }break;

            case 3: //Church Delivery
            {
                do
                {
                    system("cls");
                    printf("=======================================\n");
                    txtcolor(15,5);
                    printf(" Number of your order : %5d Orders   \n",i);
                    printf(" Cost : %5d THB                      \n",sum);
                    resetc();
                    printf("=======================================");
                    printf("\n------------------------------------------------\n");
                    printf("================================================\n");
                    printf("** We will get your address in Payment Method **\n");
                    printf("================================================\n");
                    txtcolor(2,0);
                    printf("   + Church Delivery");
                    resetc();
                    printf("\n------------------------------------------------\n");
                    printf("    -- List of regions   \n");
                    printf("    Bangkok         --> 1000 THB  [1] \n");
                    printf("    Middle and East --> 1500 THB  [2] \n");
                    printf("    Northeast       --> 2500 THB  [3] \n");
                    printf("    North           --> 2500 THB  [4] \n");
                    printf("    South           --> 2500 THB  [5] \n");
                    printf("             Reset => [6] \n");
                    printf("              Back => [0] \n");

                    do
                    {
                        printf("\nWhere do you want our service : "); scanf("%d", &order);
                        if (order != 0 && order != 1 && order != 2 && order != 3 && order != 4 && order != 5 && order != 6)
                        {
                            printf("---------------------------------------\n");
                            txtcolor(12, 0);
                            printf(" !!!Error!!! Please try again \n");
                            resetc();
                            printf("---------------------------------------\n");
                        }
                    } while (order != 0 && order != 1 && order != 2 && order != 3 && order != 4 && order != 5 && order != 6);

                    switch (order)
                    {
                        case 0: i--; break;
                        case 1: sum += 1000; break;
                        case 2: sum += 1500; break;
                        case 3: sum += 2500; break;
                        case 4: sum += 2500; break;
                        case 5: sum += 2500; break;
                        case 6: mem2 = 0; p3 = 0; sum = 0; i = 0 , mem = 0; i--; p1--; break;
                    } i++; p3 = 1; // ถ้าเลือกใช้โปรแกรมนี้ p3 = 1

                } while (order != 0);
                system("cls");
            }break;

            case 4: //High-Low Heresy
            {
                if(heresy() == 1)
                {
                    goto bookmark1;
                }
            }break;

            case 5 : //payment
            {
                if ((p3 == 1) && (p1 == 1))
                {   
                    printf("-------------------------------------------------\n");
                    txtcolor(12, 0);
                    printf("You can't pay for two programs at the same time. \n");
                    printf("please goback to clear all order at any program \n");
                    printf("%d %d \n",p3,p1);
                    printf("please press Enter button to continuous \n");
                    resetc();
                    printf("-------------------------------------------------\n");
                    getch();
                    //break;
                }
                else
                    system("cls");
                    printf("-----------------------------------\n");
                    printf("Number of your order : %d Orders        \n",i);
                    printf("Cost : %dTHB                            \n",sum);
                    printf("-----------------------------------\n");
                    printf("Please select payment method \n");
                    printf("--> Debit Card         [1]\n");
                    printf("--> Bank Transfer      [2]\n");
                    printf("--> Cash on delivery   [3]\n");
                    printf("--> Back to menu       [4]\n");

                    do //check method input
                    {
                        printf("Select number : "); 
                        scanf("%d",&method); // method = getche(); //getch not show but getche will show

                        if ((method != 1) && (method != 2) && (method != 3) && (method != 4))
                        {
                            printf("---------------------------------------\n");
                            txtcolor(12, 0);
                            printf(" !!!Error!!! Please try again \n");
                            resetc();
                            printf("---------------------------------------\n");
                        }
                        else if ((sum == 0) || (i == 0))
                        {
                            printf("---------------------------------------\n");
                            txtcolor(12, 0);
                            printf("You don't need to pay anything \n");
                            resetc();
                            printf("---------------------------------------\n");
                        }
                    } while((method != 1 && method != 2 && method != 3 && method != 4), (sum == 0 && method != 4 && i == 0));

                    if (method == 1 && sum > 0)
                    {
                        if ((check == 0) || (ct.db1 == 0) || (ct.db2 == 0) || (ct.db3 == 0) || (ct.db4 == 0))
                        {
                            do
                            {
                                printf("Enter card number (0000 0000 0000 0000) : ");
                                scanf("%d %d %d %d",&debit1, &debit2, &debit3, &debit4);
                                if(debit1>=9999 || debit2>= 9999 || debit3>= 9999 || debit4>= 9999)
                                {
                                    printf("\nError please check again !");
                                }
                            } while (debit1>=9999 || debit2>=9999 || debit3>=9999 || debit4>=9999);
                            fprintf(pt,"\n%s %d %d %d %d %d", username, checkpassword, debit1, debit2, debit3, debit4); //ถ้าลูกค้าใหม่ซื้อของจะบันทึกข้อมูลทุกอย่างให้ รวมทั้งบัตร
                        }
                        else // odd member (check == 1)
                        {
                            txtcolor(11,0);
                            printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++");
                            printf("\n++                                                ++");
                            printf("\n++ Your Debit Card Number %d %d %d %d     ++",d1,d2,d3,d4);
                            //printf("\n++ Your Debit Card Number %d %d %d %d     ++",ct.db1, ct.db2, ct.db3, ct.db4);
                            printf("\n++                                                ++");
                            printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++");
                            resetc();
                            printf("\n\nEnter for continue purchasing.....\n");
                            getch();

                        }
                        if (p3 == 1) { mem2 = 1;}
                        else mem = 1;
                    }

                    else if (method == 2 && sum > 0) //method 2
                    {
                        printf("\nPlease transfer money to this account : ");
                        txtcolor(11,0);
                        printf("\n----------------------------------------------");
                        printf("\n--               BANGKOK BANK               --");
                        printf("\n--   Account Number : 1234 1111 2222 1111   --");
                        printf("\n--            Mr.Computer EGCO111           --");
                        printf("\n----------------------------------------------");
                        resetc();
                        printf("\n\nSent payment slip to our E-mail or Line application\nAfter you sent Payment slip please wait for checking accuracy! \n");
                        printf("--------------------------------------------------------\n");
                        printf("(Email : EGCO111@hi5.com & LINE ID : @ProtectorOrz )\n");
                        printf("--------------------------------------------------------\n");
                        printf("\nEnter for back to menu ..\n");
                        getch();

                        if (check == 0)
                        {
                            fprintf(pt, "\n%s %d 0 0 0 0", username, checkpassword); //ถ้าลูกค้าใหม่ชำระเงินวิธีนี้จะเก็บ username กับ password ให้
                        }
                        mem2 = 0; p3 = 0; sum = 0; i = 0 , mem = 0, discount = 0; //reset ตัวแปรทุกตัว
                    }
                    else if (method == 3 && sum > 0)
                    {
                        if (p3 == 1)
                        {
                            printf("-------------------------------------------\n");
                            printf("you can't pay this method \n");
                            printf("please press Enter button to continuous \n");
                            printf("-------------------------------------------\n");
                            getch();
                        }
                        else if (mem2 == 0)
                        {
                            printf("-----------------------------------\n");
                            printf("==== Shipping company ====\n");
                            printf("1 Kerry Express     ( +20 THB 1-2 day all Thailand )   -->[1]\n");
                            printf("2 Thailand post     ( +10 THB 3-4 day all Thailand )   -->[2]\n");
                            printf("3 Anglican parcel   ( +5 THB 5-7 days all Thailand )   -->[3]\n");
                            do{
                                printf("Select your shipping company : "); scanf("%d",&transport);
                                if (transport != 1 && transport != 2 && transport != 3)
                                    {
                                        printf("------------------------------------------------------------------------\n");
                                        txtcolor(12,0);
                                        printf("                    Error!!! Please try again \n");
                                        resetc();
                                        printf("------------------------------------------------------------------------\n");
                                    }
                            }while(transport != 1 && transport != 2 && transport != 3);

                            switch(transport)
                            {
                                case 1 : sum += 20; break;
                                case 2 : sum += 10; break;
                                case 3 : sum += 5;  break;
                            }
                            mem = 2;
                        }
                    }

                if ((mem == 1) || (mem == 2))
                {
                    printf("please put your address : ");
                    fflush(stdin);
                    gets(address);
                    printf("----------------------------------------------------------------------------\n");
                    printf("Your track number is : ");
                    txtcolor(9, 0);
                    printf("EA%d%d0TH \n",rand()% 99999,rand()% 99999);
                    resetc();
                    printf("Total price is %d THB \n",sum-discount);
                    printf("We will sent goods at Your address : %s\n",address);
                    printf("----------------------------------------------------------------------------\n");
                    printf("please press Enter button"); getchar();
                    mem2 = 0; p3 = 0; sum = 0; i = 0 , mem = 0, discount = 0,p1 = 0;
                }
                if (mem2 == 1)
                {
                    printf("please put your location : ");
                    fflush(stdin);
                    gets(address);
                    printf("----------------------------------------------------------------------------\n");
                    printf("Total price is %d THB \n",sum-discount);
                    printf("We will go to your location @ : %s\n",address);
                    printf("----------------------------------------------------------------------------\n");
                    printf("please press Enter button for continuous"); getchar();
                    mem2 = 0; p3 = 0; sum = 0; i = 0 , mem = 0, discount = 0,p1 = 0;
                }
                else
                    fclose(pt);
                    system("cls");
            }break;
            
            case 6 :
            {
                system("cls");
                if (laps == 1)
                {
                    printf("------------------------------------\n");
                    printf("You can't play 2 laps/login \n");
                    printf("please try it again another time :D \n");
                    printf("------------------------------------\n");
                    printf("please press Enter button for go back to menu\n"); 
                    getch();
                    system("cls");
                    break;
                }
                
                srand(time(NULL));
                secret = rand()%100;

                printf("*****************************************************************\n");
                txtcolor(12, 0);
                printf("If you guess correctly within 5 times, get a 10 baht discount! \n");
                resetc();
                printf("*****************************************************************\n");

                for (count = 1; count <= 5; count ++)
                {
                    printf("Guess [%d-%d] :  ",lo, up); 
                    scanf("%d",&ans); 
                    //printf("%d",secret);
                    if (ans == secret)
                    {
                        printf("\n<<< Correct >>>\n");
                        reward++;
                        break;
                    }
                    else if (ans<lo || ans>up)
                    {
                        printf("No! Please choose a number in [%d-%d] \n",lo,up);
                    }   
                    else if (ans > secret)
                    {
                        printf("---Less than %d---\n",ans);
                        up = ans-1;
                    }
                    else if (ans < secret)
                    {
                        printf("---More than %d---\n",ans);
                        lo = ans+1;
                    }
                } 
                printf("The answer is %d !!! \n\n",secret);
                lo = 0;up = 99;
                if (reward >=1)
                {
                    printf("------------------------------------\n");
                    printf("you get reward !! \n");
                    printf("You get 10 baht discount!!! \n");
                    printf("------------------------------------\n");
                    discount = 10;
                    laps = 1;
                }
                printf("please press Enter button for go back to menu \n"); 
                getch();
                system("cls");
            }break;
            default:
            {
                if (sum >= 10)
                {
                    printf("------------------------------------\n");
                    txtcolor(12, 0);
                    printf("!! Check out your order !! \n");
                    printf("if you need to quit please clear your order.\n");
                    resetc();
                    printf("------------------------------------\n");
                    printf("Clear orders[y] or Continuous shoping[n] : ");
                    do
                    {
                        scanf("%c",&clear); //strlwr(clear);
                        if (clear == 'y')
                        {
                            sum = 0; i = 0;
                        }
                    }while(clear != 'y' && clear != 'n');
                    system("cls");
                }
                else if (sum == 0)
                {
                    saygoodbye();
                    exit(0);
                }
            }
        }
    }while (5);
}
