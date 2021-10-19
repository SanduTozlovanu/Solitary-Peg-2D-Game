#include <iostream>
#include <graphics.h>
#include <windows.h>
#include <cstring>
#include <MMsystem.h>
#include <stdio.h>
#define MAX 15
using namespace std;
int done=0,options=0,marimea,spatiu, castig, win=0, reset=0, undo=0,hint=0,hint2=0, nrElem=0;
int tabla1[MAX][MAX], tabla2[MAX][MAX],tabla3[MAX][MAX],tabla4[MAX][MAX],tabla5[MAX][MAX],tabla6[MAX][MAX],tabla7[MAX][MAX],tabla8[MAX][MAX],tabla9[MAX][MAX],tabla10[MAX][MAX],stiva[1000];
int xb1[1000],xb2[1000],xb3[1000],yb1[1000],yb2[1000],yb3[1000];
bool pierdere=false;
struct save
{
    int difficulty=0;
    int music=1;
}save;
struct resolution
{
    int x,y;
}res;
void saveFile()
{
    FILE *fptr;
    fptr = fopen("fisier.txt", "wb+");
    fwrite(&save, sizeof(save), 1, fptr);
    fclose(fptr);
}
void savedOptions()
{
    FILE *fptr;
    fptr = fopen("fisier.txt", "rb");
    fread(&save, sizeof(save), 1, fptr);
    fclose(fptr);
}
void lumini()
{
    readimagefile("fundal.jpg",0,0,res.x,res.y);
    delay(100);
    readimagefile("fundal_lumini1.jpg",0,0,res.x,res.y);
    delay(100);
    readimagefile("fundal_lumini2.jpg",0,0,res.x,res.y);
    delay(100);
    readimagefile("fundal_lumini1.jpg",0,0,res.x,res.y);
    delay(100);
}

void loadingStorm()
{
    if (save.music==1)
    PlaySound(TEXT("thunder.wav"),NULL, SND_ASYNC);
    lumini();
    lumini();
    readimagefile("fundal.jpg",0,0,res.x,res.y);
    delay(100);
    readimagefile("fundal_fulger1.jpg",0,0,res.x,res.y);
    delay(20);
    lumini();
    readimagefile("fundal.jpg",0,0,res.x,res.y);
    delay(100);
    readimagefile("fundal_fulger1.jpg",0,0,res.x,res.y);
    delay(20);
    for(int i=1;i<=9;i++)
        lumini();
    readimagefile("fundal.jpg",0,0,res.x,res.y);
    delay(100);
    readimagefile("fundal_fulger1.jpg",0,0,res.x,res.y);
    delay(20);
    readimagefile("fundal_fulger2.jpg",0,0,res.x,res.y);
    delay(20);
    readimagefile("fundal.jpg",0,0,res.x,res.y);
    delay(1000);
    while(!ismouseclick(WM_LBUTTONDOWN))
    {
        readimagefile("clic2.jpg",0,0,res.x,res.y);
        delay(90);
        readimagefile("clic1.jpg",0,0,res.x,res.y);
        delay(90);
        readimagefile("clic2.jpg",0,0,res.x,res.y);
        delay(90);
        readimagefile("clic0.jpg",0,0,res.x,res.y);
        delay(90);
    }
}
void dwaitforclick()
{
    while(!ismouseclick(WM_LBUTTONDOWN))
    {
        delay(200);
    }
    clearmouseclick(WM_LBUTTONDOWN);
}
void dloading_screen()
{
    loadingStorm();
    dwaitforclick();
}
void startMenu()
{
    if(ismouseclick(WM_LBUTTONDOWN) && options==0)
    {
        clearmouseclick(WM_LBUTTONDOWN);
        int x=mousex();
        int y=mousey();
        if(x>res.x/2.474 && x<res.x/1.579 && y>res.y/2.857 && y<res.y/2.133 && options==0 )
        {
            if(save.music==1)
            PlaySound(TEXT("Rains.wav"),NULL,SND_LOOP | SND_ASYNC);
            readimagefile("Background_startIsClicked.jpg",0,0,res.x,res.y);
            Sleep(100);
            done=1; //incepe jocul
        }
        if(y>res.y/1.5534 && y<res.y/1.356 && x>res.x/2.33 && x<res.x/1.7 && options==0)
        {
            readimagefile("exitIsClicked.jpg",0,0,res.x,res.y);
            Sleep(100);
            done=2;
            exit(1);
        }
        if(y>res.y/2 && y<res.y/1.63 && x>res.x/2.79 && x<res.x/1.52 && options==0 && save.music==1 && save.difficulty==0)
        {
            readimagefile("Background_optionsIsClicked.jpg",0,0,res.x,res.y);
            Sleep(100);
            readimagefile("optionsMusicOnEasy.jpg",0,0,res.x,res.y);
            options=1; //suntem in optiuni cu music on si easy
        }
        if(y>res.y/2 && y<res.y/1.63 && x>res.x/2.79 && x<res.x/1.52 && options==0 && save.music==0 && save.difficulty==0)
        {
            readimagefile("Background_optionsIsClicked.jpg",0,0,res.x,res.y);
            Sleep(100);
            readimagefile("optionsMusicOffEasy.jpg",0,0,res.x,res.y);
            options=1; //suntem in optiuni cu music on si easy
        }
        if(y>res.y/2 && y<res.y/1.63 && x>res.x/2.79 && x<res.x/1.52 && options==0 && save.music==1 && save.difficulty==1)
        {
            readimagefile("Background_optionsIsClicked.jpg",0,0,res.x,res.y);
            Sleep(100);
            readimagefile("optionsMusicOnHard.jpg",0,0,res.x,res.y);
            options=1;
        }
        if(y>res.y/2 && y<res.y/1.63 && x>res.x/2.79 && x<res.x/1.52 && options==0 && save.music==0 && save.difficulty==1)
        {
            readimagefile("Background_optionsIsClicked.jpg",0,0,res.x,res.y);
            Sleep(100);
            readimagefile("optionsMusicOffHard.jpg",0,0,res.x,res.y);
            options=1;
        }
    }
}
void Options()
{
    if(ismouseclick(WM_LBUTTONDOWN) && options==1)
    {
        clearmouseclick(WM_LBUTTONDOWN);
        int x=mousex();
        int y=mousey();
        if(y>res.y/2 && y<res.y/1.65 && x>res.x/3 && x<res.x/1.5 && save.difficulty==0 && save.music==1)
        {
            readimagefile("Background_musicOnIsClickedEasy.jpg",0,0,res.x,res.y);
            Sleep(100);
            readimagefile("optionsMusicOffEasy.jpg",0,0,res.x,res.y);
            save.music=0;//suntem in optiuni cu muzica off si dificultate easy
            PlaySound(TEXT("FailSound.wav"),NULL,SND_FILENAME | SND_ASYNC);
        }
        else if(y>res.y/2 && y<res.y/1.65 && x>res.x/3 && x<res.x/1.5 && save.difficulty==0 && save.music==0)
        {
            readimagefile("Background_musicOffIsClickedEasy.jpg",0,0,res.x,res.y);
            Sleep(100);
            readimagefile("optionsMusicOnEasy.jpg",0,0,res.x,res.y);
            save.music=1;//suntem in optiuni cu muzica on si dificultate easy
            PlaySound(TEXT("Rains.wav"),NULL,SND_LOOP | SND_ASYNC);
        }
        if(y>res.y/1.57 && y<res.y/1.37 && x>res.x/2.35 && x<res.x/1.68 && save.difficulty==0 && save.music==1)
        {
            readimagefile("backIsClickedOnEasy.jpg",0,0,res.x,res.y);
            Sleep(100);
            readimagefile("Background.jpg",0,0,res.x,res.y);
            options=0;//suntem in meniul principal cu muzica on si dificultate easy
        }
        else if(y>res.y/1.57 && y<res.y/1.37 && x>res.x/2.35 && x<res.x/1.68 && save.difficulty==1 && save.music==1)
        {
            readimagefile("backIsClickedOnHard.jpg",0,0,res.x,res.y);
            Sleep(100);
            readimagefile("Background.jpg",0,0,res.x,res.y);
            options=0;//suntem in meniul principal cu muzica on si dificultate hard
        }
        if(y>res.y/1.57 && y<res.y/1.37 && x>res.x/2.35 && x<res.x/1.68 && save.difficulty==0 && save.music==0)
        {
            readimagefile("backIsClickedOffEasy.jpg",0,0,res.x,res.y);
            Sleep(100);
            readimagefile("Background.jpg",0,0,res.x,res.y);
            options=0;//suntem in meniul principal cu muzica off si dificultate easy
        }
        else if(y>res.y/1.57 && y<res.y/1.37 && x>res.x/2.35 && x<res.x/1.68 && save.difficulty==1 && save.music==0)
        {
            readimagefile("backIsClickedOffHard.jpg",0,0,res.x,res.y);
            Sleep(100);
            readimagefile("Background.jpg",0,0,res.x,res.y);
            options=0;//suntem in meniul principal cu muzica off si dificultate hard
        }
        if(y>res.y/2.76 && y<res.y/2.22 && x>res.x/3.69 && x<res.x/1.297 && save.difficulty==0 && save.music==1)
        {
            readimagefile("easyIsClickedOn.jpg",0,0,res.x,res.y);
            Sleep(100);
            readimagefile("optionsMusicOnHard.jpg",0,0,res.x,res.y);
            save.difficulty=1;
        }
        else if(y>res.y/2.76 && y<res.y/2.22 && x>res.x/3.69 && x<res.x/1.297 && save.difficulty==1 && save.music==1)
        {
            readimagefile("hardIsClickedOn.jpg",0,0,res.x,res.y);
            Sleep(100);
            readimagefile("optionsMusicOnEasy.jpg",0,0,res.x,res.y);
            save.difficulty=0;
        }
        if(y>res.y/2.76 && y<res.y/2.22 && x>res.x/3.69 && x<res.x/1.297 && save.difficulty==0 && save.music==0)
        {
            readimagefile("easyIsClickedOff.jpg",0,0,res.x,res.y);
            Sleep(100);
            readimagefile("optionsMusicOffHard.jpg",0,0,res.x,res.y);
            save.difficulty=1;
        }
        else if(y>res.y/2.76 && y<res.y/2.22 && x>res.x/3.69 && x<res.x/1.297 && save.difficulty==1 && save.music==0)
        {
            readimagefile("hardIsClickedOff.jpg",0,0,res.x,res.y);
            Sleep(100);
            readimagefile("optionsMusicOffEasy.jpg",0,0,res.x,res.y);
            save.difficulty=0;
        }
        if(y>res.y/2 && y<res.y/1.65 && x>res.x/3 && x<res.x/1.5 && save.difficulty==1 && save.music==1)
        {
            readimagefile("Background_musicOnIsClickedHard.jpg",0,0,res.x,res.y);
            Sleep(100);
            readimagefile("optionsMusicOffHard.jpg",0,0,res.x,res.y);
            save.music=0;
            PlaySound(TEXT("Failsound.wav"),NULL,SND_FILENAME | SND_ASYNC);
        }
        else if (y>res.y/2 && y<res.y/1.65 && x>res.x/3 && x<res.x/1.5 && save.difficulty==1 && save.music==0)
        {
            readimagefile("Background_musicOffIsClickedHard.jpg",0,0,res.x,res.y);
            Sleep(100);
            readimagefile("optionsMusicOnHard.jpg",0,0,res.x,res.y);
            save.music=1;
            PlaySound(TEXT("Rains.wav"),NULL,SND_LOOP | SND_ASYNC);
        }
        saveFile();
    }
}
void desenarePatrat(int linia,int coloana,int valoare)
{
    setfillstyle(1,BLACK);
    int patrat;
    patrat=res.y/marimea;
    if (valoare!=-1){bar(spatiu+(coloana*patrat),linia*patrat,spatiu+((coloana+1)*patrat),(linia+1)*patrat);}
    if (valoare==0)
    {
        line (spatiu+(coloana*patrat),linia*patrat,spatiu+(coloana*patrat),(linia+1)*patrat);
        line (spatiu+(coloana*patrat),linia*patrat,spatiu+((coloana+1)*patrat),(linia)*patrat);
        line (spatiu+((coloana+1)*patrat),linia*patrat,spatiu+((coloana+1)*patrat),(linia+1)*patrat);
        line (spatiu+(coloana*patrat),(linia+1)*patrat,spatiu+((coloana+1)*patrat),(linia+1)*patrat);
    }
    if (valoare==1)
    {
        line (spatiu+(coloana*patrat),linia*patrat,spatiu+(coloana*patrat),(linia+1)*patrat);
        line (spatiu+(coloana*patrat),linia*patrat,spatiu+((coloana+1)*patrat),(linia)*patrat);
        line (spatiu+((coloana+1)*patrat),linia*patrat,spatiu+((coloana+1)*patrat),(linia+1)*patrat);
        line (spatiu+(coloana*patrat),(linia+1)*patrat,spatiu+((coloana+1)*patrat),(linia+1)*patrat);
        readimagefile("bitcoin.jpg",spatiu+(coloana*patrat)+1,linia*patrat+1,spatiu+((coloana+1)*patrat)-1,(linia+1)*patrat-1);
    }
}
void nivelul10() // TABLA 10
{
    marimea=11,castig=39;
    for(int i=0; i<marimea; i++)
    {
        for(int j=0; j<marimea; j++)
        {
            tabla10[i][j]=-1;
        }
    }
    for(int i=3; i<marimea-3; i++)
    {
        for(int j=3; j<marimea-3; j++)
        {
            tabla10[i][j]=1;
        }
    }
    tabla10[5][5]=0;
    tabla10[2][4]=1;
    tabla10[2][5]=1;
    tabla10[2][6]=1;
    tabla10[1][5]=1;
    tabla10[4][2]=1;
    tabla10[5][2]=1;
    tabla10[6][2]=1;
    tabla10[5][1]=1;
    tabla10[8][4]=1;
    tabla10[8][5]=1;
    tabla10[8][6]=1;
    tabla10[9][5]=1;
    tabla10[6][8]=1;
    tabla10[5][8]=1;
    tabla10[4][8]=1;
    tabla10[5][9]=1;
    for(int i=0; i<marimea; i++)
    {
        for (int j=0; j<marimea; j++)
        {
            desenarePatrat(i,j,tabla10[i][j]);
        }
    }
}
void nivelul9() // TABLA 9
{
    marimea=9,castig=35;
    for(int i=0; i<marimea; i++)
    {
        for(int j=0; j<marimea; j++)
        {
            tabla9[i][j]=-1;
        }
    }
    for(int i=2; i<marimea-2; i++)
    {
        for(int j=2; j<marimea-2; j++)
        {
            tabla9[i][j]=1;
        }
    }
    tabla9[1][3]=1;
    tabla9[1][4]=1;
    tabla9[1][5]=1;
    tabla9[3][1]=1;
    tabla9[4][1]=1;
    tabla9[5][1]=1;
    tabla9[3][7]=1;
    tabla9[4][7]=1;
    tabla9[5][7]=0;
    tabla9[7][3]=1;
    tabla9[7][4]=1;
    tabla9[7][5]=1;
    for(int i=0; i<marimea; i++)
    {
        for (int j=0; j<marimea; j++)
        {
            desenarePatrat(i,j,tabla9[i][j]);
        }
    }
}
void nivelul8 () //TABLA 8
{
    marimea=9,castig=31;
    int linia,coloana;
    for (linia=0; linia<marimea; linia++)
    {
        for (coloana=0; coloana<marimea; coloana++)
        {
            tabla8[linia][coloana]=-1;
        }
    }
    for (linia=1; linia<marimea-1; linia++)
    {
        for (coloana=1; coloana<marimea-1; coloana++)
        {
            tabla8[linia][coloana]=1;
        }
    }
    tabla8[1][1]=-1;
    tabla8[1][2]=-1;
    tabla8[2][1]=-1;
    tabla8[2][2]=-1;
    tabla8[1][marimea-3]=-1;
    tabla8[1][marimea-2]=-1;
    tabla8[2][marimea-3]=-1;
    tabla8[2][marimea-2]=-1;
    tabla8[marimea-3][1]=-1;
    tabla8[marimea-3][2]=-1;
    tabla8[marimea-2][1]=-1;
    tabla8[marimea-2][2]=-1;
    tabla8[marimea-3][marimea-3]=-1;
    tabla8[marimea-3][marimea-2]=-1;
    tabla8[marimea-2][marimea-3]=-1;
    tabla8[marimea-2][marimea-2]=-1;
    tabla8[marimea/2][marimea/2]=0;
    for(int i=0; i<marimea; i++)
    {
        for (int j=0; j<marimea; j++)
        {
            desenarePatrat(i,j,tabla8[i][j]);
        }
    }
}
void nivelul7() // TABLA 7
{
    marimea=11,castig=39;
    for(int i=0; i<marimea; i++)
    {
        for(int j=0; j<marimea; j++)
        {
            tabla7[i][j]=-1;
        }
    }
    for(int i=2; i<marimea-5; i++)
    {
        for(int j=2; j<marimea-2; j++)
        {
            tabla7[i][j]=1;
        }
    }
    tabla7[3][1]=1;
    tabla7[4][1]=1;
    tabla7[4][4]=0;
    tabla7[3][9]=1;
    tabla7[4][9]=1;
    tabla7[6][3]=1;
    tabla7[6][4]=1;
    tabla7[6][5]=1;
    tabla7[6][6]=1;
    tabla7[6][7]=1;
    tabla7[7][4]=1;
    tabla7[7][5]=1;
    tabla7[7][6]=1;
    tabla7[8][5]=1;
    for(int i=0; i<marimea; i++)
    {
        for (int j=0; j<marimea; j++)
        {
            desenarePatrat(i,j,tabla7[i][j]);
        }
    }
}
void nivelul6() // TABLA 6
{
    marimea=9,castig=16;
    for(int i=0; i<marimea; i++)
    {
        for(int j=0; j<marimea; j++)
        {
            tabla6[i][j]=-1;
        }
    }
    for(int i=3; i<marimea-3; i++)
    {
        for(int j=2; j<marimea-2; j++)
        {
            tabla6[i][j]=0;
        }
    }
    tabla6[1][3]=0;
    tabla6[1][4]=1;
    tabla6[1][5]=0;
    tabla6[2][3]=1;
    tabla6[2][4]=1;
    tabla6[2][5]=1;
    tabla6[5][4]=1;
    tabla6[3][2]=1;
    tabla6[3][3]=1;
    tabla6[3][4]=1;
    tabla6[3][5]=1;
    tabla6[3][6]=1;
    tabla6[4][4]=1;
    tabla6[6][3]=1;
    tabla6[6][4]=1;
    tabla6[6][5]=1;
    tabla6[7][3]=1;
    tabla6[7][4]=1;
    tabla6[7][5]=1;
    for(int i=0; i<marimea; i++)
    {
        for (int j=0; j<marimea; j++)
        {
            desenarePatrat(i,j,tabla6[i][j]);
        }
    }
}
void nivelul5() // TABLA 5
{
    marimea=7,castig=13;
    for(int i=0; i<marimea; i++)
    {
        for(int j=0; j<marimea; j++)
        {
            tabla5[i][j]=-1;
        }
    }
    for(int i=2; i<marimea-1; i++)
    {
        for(int j=2; j<marimea-2; j++)
        {
            tabla5[i][j]=1;
        }
    }
    tabla5[3][1]=1;
    tabla5[1][3]=1;
    tabla5[3][5]=1;
    tabla5[3][3]=0;
    for(int i=0; i<marimea; i++)
    {
        for (int j=0; j<marimea; j++)
        {
            desenarePatrat(i,j,tabla5[i][j]);
        }
    }
}
void nivelul4() // TABLA 4
{
    marimea=8,castig=12;
    for(int i=0; i<marimea; i++)
    {
        for(int j=0; j<marimea; j++)
        {
            tabla4[i][j]=-1;
        }
    }
    tabla4[1][4]=1;
    tabla4[2][2]=1;
    tabla4[2][3]=1;
    tabla4[2][4]=1;
    tabla4[2][5]=1;
    tabla4[2][6]=1;
    tabla4[3][2]=1;
    tabla4[3][2]=1;
    tabla4[3][3]=1;
    tabla4[3][4]=1;
    tabla4[3][5]=1;
    tabla4[3][6]=1;
    tabla4[4][4]=0;
    tabla4[5][4]=1;
    tabla4[6][4]=1;
    for(int i=0; i<marimea; i++)
    {
        for (int j=0; j<marimea; j++)
        {
            desenarePatrat(i,j,tabla4[i][j]);
        }
    }
}
void nivelul3() //TABLA 3
{
    marimea=8,castig=10;
    for(int i=0; i<marimea; i++)
    {
        for(int j=0; j<marimea; j++)
        {
            tabla3[i][j]=-1;
        }
    }
    tabla3[1][4]=1;
    tabla3[2][4]=0;
    tabla3[3][3]=1;
    tabla3[3][4]=1;
    tabla3[3][5]=1;
    tabla3[3][6]=1;
    tabla3[4][1]=1;
    tabla3[4][2]=1;
    tabla3[4][3]=1;
    tabla3[4][4]=1;
    tabla3[5][3]=1;
    tabla3[6][3]=1;
    for(int i=0; i<marimea; i++)
    {
        for (int j=0; j<marimea; j++)
        {
            desenarePatrat(i,j,tabla3[i][j]);
        }
    }
}
void nivelul2() //TABLA 2
{
    marimea=8,castig=12;
    for(int i=0; i<marimea; i++)
    {
        for(int j=0; j<marimea; j++)
        {
            tabla2[i][j]=-1;
        }
    }
    tabla2[1][3]=1;
    tabla2[2][1]=1;
    tabla2[2][2]=1;
    tabla2[2][3]=0;
    tabla2[2][4]=1;
    tabla2[2][5]=1;
    tabla2[3][3]=1;
    tabla2[4][3]=1;
    tabla2[5][1]=1;
    tabla2[5][2]=1;
    tabla2[5][3]=1;
    tabla2[5][4]=1;
    tabla2[5][5]=1;
    tabla2[6][3]=1;
    for(int i=0; i<marimea; i++)
    {
        for (int j=0; j<marimea; j++)
        {
            desenarePatrat(i,j,tabla2[i][j]);
        }
    }
}
void nivelul1() //TABLA 1
{
    marimea=6,castig=6;
    for(int i=0; i<marimea; i++)
    {
        for(int j=0; j<marimea; j++)
        {
            tabla1[i][j]=-1;
        }
    }
    tabla1[2][1]=1;
    tabla1[2][2]=1;
    tabla1[2][3]=1;
    tabla1[1][3]=0;
    tabla1[3][2]=1;
    tabla1[3][3]=1;
    tabla1[3][4]=1;
    tabla1[4][2]=1;
    for(int i=0; i<marimea; i++)
    {
        for (int j=0; j<marimea; j++)
        {
            desenarePatrat(i,j,tabla1[i][j]);
        }
    }
}
bool conditiePierdere(int tabla[MAX][MAX],int hint)
{
    pierdere=true;
    for(int i=1; i<marimea; i++)
    {
        for (int j=1; j<marimea; j++)
        {
            if (tabla[i][j]==1)
            {
                if ((tabla[i-1][j]==1 && tabla[i-2][j]==0) || (tabla[i][j-1]==1 && tabla[i][j-2]==0) || (tabla[i][j+1]==1 && tabla[i][j+2]==0)|| (tabla[i+1][j]==1 && tabla[i+2][j]==0))
                {
                    pierdere=false;
                    return pierdere;
                }
            }
        }
    }
if(pierdere==true && save.music==1 && hint == 0)
            {
                PlaySound(TEXT("Failsound.wav"),NULL,SND_ASYNC);
                delay(1200);
                PlaySound(TEXT("Rains.wav"),NULL,SND_LOOP | SND_ASYNC);
            }
else if(pierdere==true && save.music==0 && hint == 0)
        delay(1000);
}
void push(int stiva[],int coordonata)
   {
    nrElem++;
    stiva[nrElem]=coordonata;
   }
int peek(int stiva[])
{
    return stiva[nrElem];
}
int pop (int stiva[])
{
    int rezultat=peek(stiva);
    nrElem--;
    return rezultat;
}
bool backtracking(int tabla[MAX][MAX],int castigul)
{
        if (castigul == 0)
        {
            return true;
        }
        else
        {
            for(int i=1;i<marimea-1;i++)
            {
                for(int j=1;j<marimea-1;j++)
                {
                    if(tabla[i][j]==1)
                    {
                        if(tabla[i-1][j]==1 && tabla[i-2][j]==0)
                        {


                            int copied1_tabla[MAX][MAX];
                            for (int i = 0; i < marimea; i++)
                            {
                                for (int j = 0; j < marimea; j++)
                                {
                                     copied1_tabla[i][j] = tabla[i][j];
                                }
                            }
                            copied1_tabla[i][j]=0;
                            copied1_tabla[i-1][j]=0;
                            copied1_tabla[i-2][j]=1;
                            xb1[castig-castigul]=i;
                            yb1[castig-castigul]=j;
                            xb2[castig-castigul]=i-1;
                            yb2[castig-castigul]=j;
                            xb3[castig-castigul]=i-2;
                            yb3[castig-castigul]=j;
                            if(backtracking(copied1_tabla,castigul-1))
                                return true;
                        }

                        if (tabla[i][j-1]==1 && tabla[i][j-2]==0)
                        {
                            int copied2_tabla[MAX][MAX];
                            for (int i = 0; i < marimea; i++)
                            {
                                for (int j = 0; j < marimea; j++)
                                {
                                    copied2_tabla[i][j] = tabla[i][j];
                                }
                            }
                            copied2_tabla[i][j]=0;
                            copied2_tabla[i][j-1]=0;
                            copied2_tabla[i][j-2]=1;
                            xb1[castig-castigul]=i;
                            yb1[castig-castigul]=j;
                            xb2[castig-castigul]=i;
                            yb2[castig-castigul]=j-1;
                            xb3[castig-castigul]=i;
                            yb3[castig-castigul]=j-2;
                            if(backtracking(copied2_tabla,castigul-1))
                                return true;
                        }
                        if (tabla[i][j+1]==1 && tabla[i][j+2]==0)
                        {
                            int copied3_tabla[MAX][MAX];
                            for (int i = 0; i < marimea; i++)
                            {
                                for (int j = 0; j < marimea; j++)
                                {
                                    copied3_tabla[i][j] = tabla[i][j];
                                }
                            }
                            copied3_tabla[i][j]=0;
                            copied3_tabla[i][j+1]=0;
                            copied3_tabla[i][j+2]=1;
                            xb1[castig-castigul]=i;
                            yb1[castig-castigul]=j;
                            xb2[castig-castigul]=i;
                            yb2[castig-castigul]=j+1;
                            xb3[castig-castigul]=i;
                            yb3[castig-castigul]=j+2;
                            if(backtracking(copied3_tabla,castigul-1))
                                return true;
                        }
                        if (tabla[i+1][j]==1 && tabla[i+2][j]==0)
                        {
                            int copied4_tabla[MAX][MAX];
                            for (int i = 0; i < marimea; i++)
                            {
                                for (int j = 0; j < marimea; j++)
                                {
                                    copied4_tabla[i][j] = tabla[i][j];
                                }
                            }
                            copied4_tabla[i][j]=0;
                            copied4_tabla[i+1][j]=0;
                            copied4_tabla[i+2][j]=1;
                            xb1[castig-castigul]=i;
                            yb1[castig-castigul]=j;
                            xb2[castig-castigul]=i+1;
                            yb2[castig-castigul]=j;
                            xb3[castig-castigul]=i+2;
                            yb3[castig-castigul]=j;
                            if(backtracking(copied4_tabla,castigul-1))
                                return true;
                        }
                    }
                }
            }
        return false;
        }
}
void mutarePiesa(int patrat,int tabla[MAX][MAX],int castigul)
{
    int linia1,coloana1,linia2,coloana2,x,y;
    int click=false;
    undo=0;
    do
        if(ismouseclick(WM_LBUTTONDOWN) && !click)//cand dai click
        {
            click=true;
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();
            if(y>res.y/2.66 && y<res.y/2.286 && x>res.x/40 && x<res.x/6.66 && nrElem!=0)
            {
                readimagefile("undo_reset_3.jpg",0,0,res.x/6,res.y);
                Sleep(100);
                readimagefile("undo_reset_1.jpg",0,0,res.x/6,res.y);
                undo=1;
                hint2=0;
            }
            linia1=y/patrat;
            coloana1=(x-spatiu)/patrat;
            if(y>res.y/2.05 && y<res.y/1.758 && x>res.x/40 && x<res.x/6.66)
            {
                reset=1;
                nrElem=0;
                hint2=0;
            }
            if(y>res.y/1.7 && y<res.y/1.5 && x>res.x/40 && x<res.x/6.66)
            {
                hint=1;
                readimagefile("undo_reset_4.jpg",0,0,res.x/6,res.y);
                Sleep(100);
                readimagefile("undo_reset_1.jpg",0,0,res.x/6,res.y);
            }
        }
    while (!click);
    click=false;
    do
        if(ismouseclick(WM_LBUTTONDOWN) && !click)
        {
            click=true;
            clearmouseclick(WM_LBUTTONDOWN);
            x=mousex();
            y=mousey();
            if(y>res.y/2.66 && y<res.y/2.286 && x>res.x/40 && x<res.x/6.66 && nrElem!=0)
            {
                readimagefile("undo_reset_3.jpg",0,0,res.x/6,res.y);
                Sleep(100);
                readimagefile("undo_reset_1.jpg",0,0,res.x/6,res.y);
                undo=1;
                hint=0;
            }
            linia2=y/patrat;
            coloana2=(x-spatiu)/patrat;
            if(y>res.y/2.05 && y<res.y/1.758 && x>res.x/40 && x<res.x/6.66)
            {
                 reset=1;
                 nrElem=0;
                 hint=0;
            }
            if(y>res.y/1.7 && y<res.y/1.5 && x>res.x/40 && x<res.x/6.66)
            {
                hint=1;
                readimagefile("undo_reset_4.jpg",0,0,res.x/6,res.y);
                Sleep(100);
                readimagefile("undo_reset_1.jpg",0,0,res.x/6,res.y);
            }
        }
    while (!click && tabla[linia1][coloana1]==1);
    if(undo==1)
    {
        castig++;
        coloana2=pop(stiva);
        linia2=pop(stiva);
        coloana1=pop(stiva);
        linia1=pop(stiva);
        if(tabla[linia1][coloana1]!=-1) desenarePatrat(linia1,coloana1,1);
        if(tabla[(linia1+linia2)/2][(coloana1+coloana2)/2]!=-1) desenarePatrat((linia1+linia2)/2,(coloana1+coloana2)/2,1);
        if(tabla[linia2][coloana2]!=-1) desenarePatrat(linia2,coloana2,0);
        if(tabla[linia1][coloana1]!=-1){tabla[linia1][coloana1]=1;}
        if(tabla[(linia1+linia2)/2][(coloana1+coloana2)/2]!=-1) {tabla[(linia1+linia2)/2][(coloana1+coloana2)/2]=1;}
        if(tabla[linia2][coloana2]!=-1){tabla[linia2][coloana2]=0;}
    }
    if(hint==1)
    {
        if(hint2==1)
        {
                for(int i=0;i<castig;i++)
                {
                    xb1[i]=xb1[i+1];
                    yb1[i]=yb1[i+1];
                    xb2[i]=xb2[i+1];
                    yb2[i]=yb2[i+1];
                    xb3[i]=xb3[i+1];
                    yb3[i]=yb3[i+1];
                }
                push(stiva,xb1[0]);
                push(stiva,yb1[0]);
                push(stiva,xb3[0]);
                push(stiva,yb3[0]);
                tabla[xb1[0]][yb1[0]]=0;
                tabla[xb2[0]][yb2[0]]=0;
                tabla[xb3[0]][yb3[0]]=1;
                desenarePatrat(xb1[0],yb1[0],0);
                desenarePatrat(xb2[0],yb2[0],0);
                desenarePatrat(xb3[0],yb3[0],1);
                castig--;
        }
        else
        {
            if(backtracking(tabla,castig))
            {
                tabla[xb1[0]][yb1[0]]=0;
                tabla[xb2[0]][yb2[0]]=0;
                tabla[xb3[0]][yb3[0]]=1;
                desenarePatrat(xb1[0],yb1[0],0);
                desenarePatrat(xb2[0],yb2[0],0);
                desenarePatrat(xb3[0],yb3[0],1);
                push(stiva,xb1[0]);
                push(stiva,yb1[0]);
                push(stiva,xb3[0]);
                push(stiva,yb3[0]);
                castig--;
                hint2=1;
            }
        }
        cout<<"am terminat backtracking-ul"<<endl;
        hint=0;
    }
    if((tabla[linia2][coloana2]==0)&&(tabla[linia1][coloana1]==1)&&(tabla[(linia1+linia2)/2][(coloana1+coloana2)/2]==1))
    {
        if(linia1==linia2 && undo==0 )
        {
            if ((coloana2-coloana1==2)||(coloana1-coloana2==2))
            {
                hint2=0;
                push(stiva,linia1);
                push(stiva,coloana1);
                push(stiva,linia2);
                push(stiva,coloana2);
                tabla[linia1][coloana1]=0;
                tabla[linia1][(coloana1+coloana2)/2]=0;
                tabla[linia2][coloana2]=1;
                desenarePatrat(linia1,coloana1,0);
                desenarePatrat((linia1+linia2)/2,(coloana1+coloana2)/2,0);
                desenarePatrat(linia2,coloana2,1);
                castig--;
                if(castig!=0)
                {
                    conditiePierdere(tabla,0);
                };
            }
        }
        else if (coloana1==coloana2 && undo==0)
        {
            if((linia1-linia2==2)||(linia2-linia1==2))
            {
                hint2=0;
                push(stiva,linia1);
                push(stiva,coloana1);
                push(stiva,linia2);
                push(stiva,coloana2);
                tabla[linia1][coloana1]=0;
                tabla[(linia1+linia2)/2][coloana1]=0;
                tabla[linia2][coloana2]=1;
                desenarePatrat(linia1,coloana1,0);
                desenarePatrat((linia1+linia2)/2,(coloana1+coloana2)/2,0);
                desenarePatrat(linia2,coloana2,1);
                castig--;
                if(castig!=0)
                {
                    conditiePierdere(tabla,0);
                };
            }
        }
    }
}
void gameplay(int number)
{
    switch (number)
    {
        case 1:nivelul1();break;
        case 2:nivelul2();break;
        case 3:nivelul3();break;
        case 4:nivelul4();break;
        case 5:nivelul5();break;
        case 6:nivelul6();break;
        case 7:nivelul7();break;
        case 8:nivelul8();break;
        case 9:nivelul9();break;
        case 10:nivelul10();break;
    }
     do
            {
                 if(reset==1)
                {
                    readimagefile("undo_reset_2.jpg",0,0,res.x/6,res.y);
                    Sleep(100);
                    readimagefile("undo_reset_1.jpg",0,0,res.x/6,res.y);
                    switch (number)
                    {
                        case 1:nivelul1();break;
                        case 2:nivelul2();break;
                        case 3:nivelul3();break;
                        case 4:nivelul4();break;
                        case 5:nivelul5();break;
                        case 6:nivelul6();break;
                        case 7:nivelul7();break;
                        case 8:nivelul8();break;
                        case 9:nivelul9();break;
                        case 10:nivelul10();break;
                    }
                    reset=0;
                }
                switch (number)
                                    {
                        case 1:mutarePiesa(res.y/marimea,tabla1,castig);break;
                        case 2:mutarePiesa(res.y/marimea,tabla2,castig);break;
                        case 3:mutarePiesa(res.y/marimea,tabla3,castig);break;
                        case 4:mutarePiesa(res.y/marimea,tabla4,castig);break;
                        case 5:mutarePiesa(res.y/marimea,tabla5,castig);break;
                        case 6:mutarePiesa(res.y/marimea,tabla6,castig);break;
                        case 7:mutarePiesa(res.y/marimea,tabla7,castig);break;
                        case 8:mutarePiesa(res.y/marimea,tabla8,castig);break;
                        case 9:mutarePiesa(res.y/marimea,tabla9,castig);break;
                        case 10:mutarePiesa(res.y/marimea,tabla10,castig);break;
                    }
            }
        while((castig!=0) && (pierdere==false));
        nrElem=0;
        hint2=0;
        if(castig==0)
        {
            win++;
            if(save.music==1)
            {
                PlaySound(TEXT("winmusic.wav"),NULL,SND_ASYNC);
                delay(1300);
                PlaySound(TEXT("Rains.wav"),NULL,SND_LOOP | SND_ASYNC);
            }
            else
            delay (500);
        }

        readimagefile("castel.jpg",0,0,res.x,res.y);
        readimagefile("undo_reset_1.jpg",0,0,res.x/6,res.y);
        pierdere=false;
}
void finish(int win)
{
        clearviewport();
        settextstyle(3,0,8);
        if(win==5)
            outtextxy(res.x/4,res.y/2.28,"Felicitari, ai castigat 5 jocuri!");
        if(win==4)
            outtextxy(res.x/4,res.y/2.28,"Felicitari, ai castigat 4 jocuri!");
        if(win==3)
            outtextxy(res.x/4,res.y/2.28,"Felicitari, ai castigat 3 jocuri!");
        if(win==2)
            outtextxy(res.x/4,res.y/2.28,"Felicitari, ai castigat 2 jocuri!");
        if(win==1)
            outtextxy(res.x/4,res.y/2.28,"Felicitari, ai castigat 1 joc!");
        if(win==0)
            outtextxy(res.x/4,res.y/2.28,"Felicitari, ai pierdut cu succes!");
        if(save.music==1)
            PlaySound(TEXT("finalwin.wav"),NULL,SND_ASYNC);
}
void startGame()
{
    if (save.difficulty==1)
    {
        gameplay(6);
        gameplay(7);
        gameplay(8);
        gameplay(9);
        gameplay(10);
        finish(win);
    }
    else if (save.difficulty==0)
    {
        gameplay(1);
        gameplay(2);
        gameplay(3);
        gameplay(4);
        gameplay(5);
        finish(win);
    }
}
int main()
{
    res.x=1600;
    res.y=1000;
    spatiu=(res.x-res.y);
    initwindow(res.x,res.y);
    savedOptions();
    dloading_screen();
    readimagefile("Background.jpg",0,0,res.x,res.y);
    while(done==0)
    {
        startMenu();
        Options();
    }
    readimagefile("castel.jpg",0,0,res.x,res.y);
    readimagefile("undo_reset_1.jpg",0,0,res.x/6,res.y);
    startGame();
    getch();
    closegraph();
    return 0;
}
