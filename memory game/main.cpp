#include <iostream>
#include <string>
//#include "stdafx.h"
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include "RandomGeneration.h"
using namespace std;

void gotoxy(short x, short y)
{
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x-1;
    pos.Y = y-1;
    SetConsoleCursorPosition(hCon, pos);

}
class Game
{
    char boardDefault[5][4];
    char boardSet[5][4];
    char boardCurrent[5][4];
    char cmp1, cmp2;
    int tries;
    int t1,t2;
    int t3,t4;
    int i;
public:
    Game()
    {
        i = 0;
        tries = 0;

    }
    void CreateBoard()
    {
        //int  k = 0;
        cout<<"\n\n\n\n";
        cout<<"\t\t\t";
        for(int j = 0; j<4; j++)
        {
            cout<<"\t"<<j;

        }
        cout<<endl<<endl;
        cout<<"\t\t\t\t";
        for (int j = 0; j<25; j++)
        {
            cout<<"*";

        }
        cout<<endl<<endl;
        cout<<"\t";
        char row = 'A';
        for (int i = 0; i<5; i++)
        {
            cout<<"\t"<<row;
            for(int j = 0; j<4; j++)
            {
                boardDefault[i][j] = '@';
                boardCurrent[i][j] = boardDefault[i][j];
                cout<<"\t"<<boardDefault[i][j];
            }
            cout<<endl<<endl;
            cout<<"\t";
            row++;

        }

    }
    void FillBoard()
    {
        char a[10];
        int randno[10];
        int rno, k;
        RandomGeneration *rg;
        rg = new RandomGeneration();
        rno = rg->DrawRandomNumber();
        for(int k = 0; k<10; k++)
        {
            randno[k] = rno *k;
            a[k] = randno[k];
            if(a[k] == '\0')
                a[k] = '%';


        }
        k = 0;
        for (int i = 0; i<5; i++)
        {
            for(int j = 0; j<4; j++)
            {
                boardSet[i][j] = a[k];
                if (k == 9)
                    k = 0;
                else
                    k++;

            }
        }

    }
    void ChangeCell()
    {
        int bb, cnt=0;
        int counter =0;
        int cell_1,cell_2 =0;
        char cellno[2];
        char choice;
        tries = 0;
        cout<<"Enter -1 to exit ";
        CreateBoard();
        i = 0;
        while(true)
        {
            i++;
            int flag = 0;
            for (int m = 0; m<5; m++)
            {
                for(int n = 0; n<4; n++)
                {
                    if (boardCurrent[m][n] == '@')
                    {
                        flag = 1;
                        continue;

                    }
                }
            }
            if (flag == 0)
            {
                system("cls");
                gotoxy(24,9);
                cout<<" Congratulations !!!!!!!!!"<<endl<<endl;
                gotoxy(26,10);
                cout<<"You have completed in "<<tries<<"Tries. ";
                gotoxy(28,13);
                cout<<endl<<"PLAY AGAIN(Y/N)";
                goto bb;

            }
            else
            {
                cc: if(counter>2)
                {
                    system("cls");
                    CurrentMatrix();
                    counter = 0;
                    cnt = 0;
                    goto dd;

                }
                dd: cout<<"Enter the cell number to be opened ";
                cin>>cellno;
                counter++;
                if (strlen(cellno)>2)
                {
                    cout<<"\n Enter valid cell no..";
                    counter ++;
                    goto cc;

                }
                else
                {
                    tries++;
                    if(i ==3)
                    {
                        if(cmp1 != cmp2)
                        {
                            ReplaceWithDefault(t1, t2);
                            boardCurrent[t1][t2]= '@';
                            ReplaceWithDefault(t3,t4);
                            boardDefault[t3][t4]= '@';
                            t1=t2=t3=t4=0;
                            i = 1;
                        }
                        else
                            i =1;
                    }
                    if(cellno[0] == '-' && cellno[1] == '1')
                    {
                        system("cls");
                        gotoxy(28,13);
                        cout<<endl<<" PLAY AGAIN(Y/N)";
                        goto bb;
                        break;

                    }
                    else
                    {
                        switch(cellno[0])
                        {
                        case 'A':
                        case 'a':
                            cell_1 = 0;
                            break;
                        case 'B':
                        case 'b':
                            cell_1 = 1;
                            break;
                        case 'C':
                        case 'c':
                            cell_1 = 2;
                            break;
                        case 'D':
                        case 'd':
                            cell_1 = 3;
                            break;
                        case 'E':
                        case 'e':
                            cell_1 = 4;
                            break;
                        default:
                            {
                                gotoxy(1,22+cnt);
                                cout<<"\n Enter valid cell no..";
                                counter ++;
                                goto cc;
                            }
                        }
                        switch(cellno[1])
                        {
                            case '0':cell_2=0;
                            case '1':cell_2=1;
                            case '2':cell_2=2;
                            case '3':cell_2=3;
                            default:
                                {
                                    gotoxy(1,22+cnt);
                                    cout<<"\n Enter valid cell no..";
                                    counter ++;

                                    goto cc;
                                }
                        }
                        if (boardCurrent[cell_1][cell_2] !='@')
                        {
                            gotoxy(1,22+cnt);
                            cout<<" Cell is already open...";
                            goto dd;

                        }
                        else
                        {
                            IdentifyLocation(cell_1,cell_2,cnt);
                            if(i ==1)
                            {
                                cmp1 = boardSet[cell_1][cell_2];
                                t1 = cell_1;
                                t2 = cell_2;

                            }
                            if (i==2)
                            {
                                cmp2 = boardSet[cell_1][cell_2];
                                t3 = cell_1;
                                t4 = cell_2;

                            }
                            cout<<boardSet[cell_1][cell_2];
                            boardCurrent[cell_1][cell_2] = boardSet[cell_1][cell_2];
                            gotoxy(1,22+cnt);
                            cnt ++;

                        }
                    }
                }
            }
        }
    bb: cin>>choice;
    system("cls");

    while(choice=='Y' || choice =='y');
    }
    void CurrentMatrix()
    {
        int i,j;
        cout<<"\n\n\n\n";
        cout<<"\t\t\t";
        for(j=0; j<4;j++)
        {
            cout<<"\t"<<j;

        }
        cout<<endl<<endl;
        cout<<"\t\t\t";
        for(j=0; j<25;j++)
        {
            cout<<"*";

        }
        cout<<endl<<endl;
        cout<<"\t";
        char row ='A';
        for(i=0; i<5;i++)
        {
            cout<<"\t"<<row;
            for(j=0; j<4;j++)
            {
                if(boardCurrent[i][j] !='\0')
                    cout<<"\t"<<boardCurrent[i][j];
                else
                {
                    boardCurrent[i][j] = '@';
                    cout<<"\t"<<boardCurrent[i][j];

                }
            }
            cout<<"\n";
            row++;
            cout<<"\n\t";
        }
    }
    void IdentifyLocation(int cell_1,int cell_2,int cnt)
    {
        if(cell_1 == 0)
        {
            switch(cell_2)
            {
            case 0:
                gotoxy(25,9);
                break;
            case 1:
                gotoxy(33,9);
                break;
            case 2:
                gotoxy(41,9);
                break;
            case 3:
                gotoxy(49,9);
                break;
            default:
                {
                    gotoxy(1,22+cnt);
                    cout<<"\n Enter valid cell no ";
                    break;
                }

            }
        }
        if(cell_1 == 1)
        {
            switch(cell_2)
            {
                case 0:
                gotoxy(25,11);
                break;
            case 1:
                gotoxy(33,11);
                break;
            case 2:
                gotoxy(41,11);
                break;
            case 3:
                gotoxy(49,11);
                break;

            }
        }
        if(cell_1 == 2)
        {
            switch(cell_2)
            {
                case 0:
                gotoxy(25,13);
                break;
            case 1:
                gotoxy(33,13);
                break;
            case 2:
                gotoxy(41,13);
                break;
            case 3:
                gotoxy(49,13);
                break;

            }
        }
        if(cell_1 == 3)
        {
            switch(cell_2)
            {
                case 0:
                gotoxy(25,15);
                break;
            case 1:
                gotoxy(33,15);
                break;
            case 2:
                gotoxy(41,15);
                break;
            case 3:
                gotoxy(49,15);
                break;

            }
        }
        if(cell_1 == 4)
        {
            switch(cell_2)
            {
                case 0:
                gotoxy(25,17);
                break;
            case 1:
                gotoxy(33,17);
                break;
            case 2:
                gotoxy(41,17);
                break;
            case 3:
                gotoxy(49,17);
                break;

            }
        }
    }

    void ReplaceWithDefault(int val1,int val2)
    {
        switch(val1)
        {
        case 0:
            {
                switch(val2)
                {
                case 0:
                    gotoxy(25,9);
                    cout<<"@";
                    break;
                case 1:
                    gotoxy(33,9);
                    cout<<"@";
                    break;
                case 2:
                    gotoxy(41,9);
                    cout<<"@";
                    break;
                case 3:
                    gotoxy(49,9);
                    cout<<"@";
                    break;
                }
                break;
            }
        case 1:
            {
                switch(val2)
                {
                    case 0:
                        gotoxy(25,11);
                        cout<<"@";
                        break;
                    case 1:
                        gotoxy(33,11);
                        cout<<"@";
                        break;
                    case 2:
                        gotoxy(41,11);
                        cout<<"@";
                        break;
                    case 3:
                        gotoxy(49,11);
                        cout<<"@";
                        break;
                }
                break;
            }
        case 2:
            {
                switch(val2)
                {
                    case 0:
                        gotoxy(25,13);
                        cout<<"@";
                        break;
                    case 1:
                        gotoxy(33,13);
                        cout<<"@";
                        break;
                    case 2:
                        gotoxy(41,13);
                        cout<<"@";
                        break;
                    case 3:
                        gotoxy(49,13);
                        cout<<"@";
                        break;
                }
                break;
            }
            case 3:
            {
                switch(val2)
                {
                    case 0:
                        gotoxy(25,15);
                        cout<<"@";
                        break;
                    case 1:
                        gotoxy(33,15);
                        cout<<"@";
                        break;
                    case 2:
                        gotoxy(41,15);
                        cout<<"@";
                        break;
                    case 3:
                        gotoxy(49,15);
                        cout<<"@";
                        break;
                }
                break;
            }
            case 4:
            {
                switch(val2)
                {
                    case 0:
                        gotoxy(25,17);
                        cout<<"@";
                        break;
                    case 1:
                        gotoxy(33,17);
                        cout<<"@";
                        break;
                    case 2:
                        gotoxy(41,17);
                        cout<<"@";
                        break;
                    case 3:
                        gotoxy(49,17);
                        cout<<"@";
                        break;
                }
                break;
            }
        }
    }
};
int main()
{
    Game g;
    g.FillBoard();
    g.ChangeCell();
}
