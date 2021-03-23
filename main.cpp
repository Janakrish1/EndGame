#include <iostream>
#include <stdlib.h>
#include <graphics.h>
#include <time.h>
#include <conio.h>
#include <dos.h>
#include <windows.h>
#include <MMSystem.h>
#include <stdio.h>
#include <thread>
using namespace std;
void bomb();
void play_music();
static char ch;
static int score = 0;
static int lyf = 3;

class ell
{
public:
    void FILL_ENVIRONMENT()
    {
        //GAME ENVIRONMENT IS FILLED
        setfillstyle(SOLID_FILL,LIGHTBLUE);
        floodfill(0,0,1);
        setfillstyle(SOLID_FILL,GREEN);
        setcolor(GREEN);
        ellipse(775,800,0,360,800,200);
        fillellipse(775,800,800,200);

        setcolor(WHITE);
        ellipse(275,225,0,360,50,25);
        fillellipse(275,225,50,25);
        setfillstyle(SOLID_FILL,WHITE);
        floodfill(275,225,15);

        setcolor(WHITE);
        ellipse(525,120,0,360,50,25);
        fillellipse(525,120,50,25);
        setfillstyle(SOLID_FILL,WHITE);
        floodfill(525,120,15);

        setcolor(WHITE);
        ellipse(800,100,0,360,50,25);
        fillellipse(800,100,50,25);
        setfillstyle(SOLID_FILL,WHITE);
        floodfill(800,100,15);

        setcolor(WHITE);
        ellipse(950,220,0,360,50,25);
        fillellipse(950,220,50,25);
        setfillstyle(SOLID_FILL,WHITE);
        floodfill(950,220,15);

        setcolor(WHITE);
        ellipse(1300,150,0,360,50,25);
        fillellipse(1300,150,50,25);
        setfillstyle(SOLID_FILL,WHITE);
        floodfill(1300,150,15);

    }
}ell;



//LOADING SCREEN
class LOADING
{
public:

    int x = 618,y = 500,radius;

    void load()
    {
        for(int j=0;j<=250;j++)
        {
            setfillstyle(SOLID_FILL,14);
            floodfill(0,0,14);
            settextstyle(TRIPLEX_FONT,HORIZ_DIR,9);
            outtextxy(550,325,"Loading...");
            setcolor(0);
            setbkcolor(14);
            setcolor(RED);
            circle(x+j,y,20);
            setfillstyle(XHATCH_FILL,BROWN);
            floodfill(x+j,y,4);
            setcolor(RED);
            delay(5);
            cleardevice();
        }
    }
}load;

//TITLE ENDGAME
class TITLE
{
   public:
       void title()
       {

        for(int i = 30;i<= 290; i++)
        {
            setfillstyle(SOLID_FILL,BLACK);
            floodfill(0,0,5);
            settextstyle(TRIPLEX_FONT,HORIZ_DIR,9);
            setcolor(RED);
            outtextxy(i,350,"THE ENDGAME");
            delay(50);
        }
            cleardevice();


       }

       void start()
       {
          while(!kbhit())
            {
                setcolor(RED);
                settextstyle(TRIPLEX_FONT,HORIZ_DIR,9);
                outtextxy(500,350,"START");
                setcolor(BLACK);
                settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
                outtextxy(500,450,"PRESS ANY KEY");
                setbkcolor(11);
                delay(100);
                cleardevice();
            }
       }
}ti;

//RAINBOW
class rainbow
{
public:

    void rbow()
    {
            int x, y, i;
            x = 600;
            y = 750;

            for (i=30; i<200; i++)
            {
                delay(100);
                setcolor(i/10);
                arc(x, y, 0, 180, i-10);
            }
    }

}rnbow;


class randm  //RANDOM NUMBER GENERATION FOR DECIDING IT TO BE A BOMB OR A SNOWBALL
{
public:
    int rb;
    void rndm1()
    {
        srand(time(0));
        rb = rand() % 100;
    }
}rn1,rn2,rn3;

class snow_man      //CREATING SNOWMAN AND SNOWBALL
{
public:
     int speed = 10;
     int cirx1=300,cirx2=275,cirx3=325,ellx1=300;
     char arr1[100],arr2[100];
    void create_mo()
    {

                setcolor(WHITE);
                circle(cirx1,600,50);
                setfillstyle(SOLID_FILL,WHITE);
                floodfill(cirx1,600,WHITE);

                setcolor(WHITE);
                circle(cirx1,700,70);
                setfillstyle(SOLID_FILL,WHITE);
                floodfill(cirx1,700,WHITE);

                setcolor(BLACK);
                circle(cirx2,575,5);
                setfillstyle(SOLID_FILL,BLACK);
                floodfill(cirx2,575,BLACK);

                setcolor(BLACK);
                circle(cirx3,575,5);
                setfillstyle(SOLID_FILL,BLACK);
                floodfill(cirx3,575,BLACK);

                setcolor(BLACK);
                ellipse(ellx1,600,0,360,10,5);
                fillellipse(ellx1,600,10,5);
                setfillstyle(SOLID_FILL,BLACK);
                floodfill(ellx1,600,BLACK);

                if(GetAsyncKeyState(VK_RIGHT))
                {
                    cirx1 += speed;
                    cirx2 += speed;
                    cirx3 += speed;
                    ellx1 += speed;
                }

                else if(GetAsyncKeyState(VK_LEFT))
                {
                    cirx1 -= speed;
                    cirx2 -= speed;
                    cirx3 -= speed;
                    ellx1 -= speed;
                }
                setcolor(RED);
                setbkcolor(LIGHTBLUE);
                settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
                sprintf(arr1,"LYF = %d",lyf);
                outtextxy(1250,50,arr1);
                setcolor(RED);
                setbkcolor(LIGHTBLUE);
                settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
                sprintf(arr2,"SCORE = %d",::score);
                outtextxy(1250,70,arr2);


    }

    void snow_ball(int a,int b)     //CREATING A SNOWBALL
    {
                setcolor(WHITE);
                setfillstyle(SOLID_FILL,WHITE);
                circle(a,b+2,20);
                floodfill(a,b,WHITE);
                //setcolor(LIGHTBLUE);
    }

    void snow_ball2(int a,int b)  //FUNCTION FOR BOMB
        {
                setcolor(YELLOW);
                setfillstyle(SOLID_FILL,YELLOW);
                circle(a,b+2,25);
                floodfill(a,b,YELLOW);
                //setcolor(LIGHTBLUE);
        }

}sm,sb;


//CREATING A RED SNOWMAN
class sm2
{
public:
     int speed = 10;
     int cirx7=300,cirx8=275,cirx9=325,ellx2=300;
    void create_mo2()
    {

                setcolor(YELLOW);
                circle(cirx7,600,50);
                setfillstyle(SOLID_FILL,YELLOW);
                floodfill(cirx7,600,YELLOW);

                setcolor(YELLOW);
                circle(cirx7,700,70);
                setfillstyle(SOLID_FILL,YELLOW);
                floodfill(cirx7,700,YELLOW);

                setcolor(RED);
                circle(cirx8,575,5);
                setfillstyle(SOLID_FILL,RED);
                floodfill(cirx8,575,RED);

                setcolor(RED);
                circle(cirx9,575,5);
                setfillstyle(SOLID_FILL,RED);
                floodfill(cirx9,575,RED);

                setcolor(RED);
                ellipse(ellx2,600,0,360,10,5);
                fillellipse(ellx2,600,10,5);
                setfillstyle(SOLID_FILL,RED);
                floodfill(ellx2,600,RED);

                if(GetAsyncKeyState(VK_UP))
                {
                    cirx7 += speed;
                    cirx8 += speed;
                    cirx9 += speed;
                    ellx2 += speed;
                }

                else if(GetAsyncKeyState(VK_DOWN))
                {
                    cirx7 -= speed;
                    cirx8 -= speed;
                    cirx9 -= speed;
                    ellx2 -= speed;
                }
    }

}sm2;

void bomb(int a,int b)  //FUNCTION FOR BOMB
        {
                setcolor(RED);
                setfillstyle(SOLID_FILL,RED);
                circle(a,b+2,30);
                floodfill(a,b,RED);
                //setcolor(LIGHTBLUE);
        }


class level
{
public:

    void level1()
    {
        for(int m = 30;m<= 290; m++)
                        {
                            setfillstyle(SOLID_FILL,BLACK);
                            floodfill(0,0,5);
                            setbkcolor(BLACK);
                            settextstyle(TRIPLEX_FONT,HORIZ_DIR,9);
                            setcolor(RED);
                            outtextxy(m,350,"LEVEL 1");
                            settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
                            setcolor(LIGHTCYAN);

                            outtextxy(m,500,"LEFT AND RIGHT ARROWS");
                            settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
                            setcolor(LIGHTCYAN);
                            outtextxy(m,600,"TO MOVE SNOWMAN");
                            delay(10);
                        }
    }
    void level2()
    {
         for(int i = 30;i<= 290; i++)
                        {
                            setbkcolor(BLACK);
                            setfillstyle(SOLID_FILL,BLACK);
                            floodfill(0,0,5);
                            settextstyle(TRIPLEX_FONT,HORIZ_DIR,9);
                            setcolor(RED);
                            outtextxy(i,350,"LEVEL 2");
                            settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
                            setcolor(LIGHTCYAN);

                            outtextxy(i,500,"LEFT AND RIGHT ARROWS");
                            settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
                            setcolor(LIGHTCYAN);
                            outtextxy(i,600,"TO MOVE SNOWMAN");

                            settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
                            setcolor(LIGHTCYAN);

                            outtextxy(i,675,"UP AND DOWN ARROWS TO MOVE");

                            delay(10);
                        }
                cleardevice();
    }

}lev;


struct axis         //INITIALIZING VARIABLES
{
    int xaxis1;
    int xaxis2;
}axis;


int main()
{
        PlaySound("gameaudio2", NULL,SND_ASYNC);    //PLAYBACK SOUND
        int flag = 0;
        int gd = DETECT,gm;
        initgraph(&gd,&gm,"");      //OPENING GRAPHICS TERMINAL
        int scrwid = 1536, scrhei = 834;
        initwindow(scrwid,scrhei,"THE ENDGAME");    //CREATING MY GAME WINDOW
        bool game_run = TRUE;       //BOOL DATA TYPE FOR TRUE OR FALSE
        int yaxis_motion;
        char arr2[100];
        ti.title();
        ti.start();
        delay(20);
        setcolor(BLACK);
        floodfill(0,0,5);

        cleardevice();          //CLEARING THE DEVICE
        load.load();
        setbkcolor(BLACK);
        lev.level1();
        ell.FILL_ENVIRONMENT();
        sm.create_mo();

    while(game_run)
        {
                PlaySound("gameaudio3", NULL,SND_ASYNC);    //GAMEAUDIO
                ell.FILL_ENVIRONMENT();
                sm.create_mo();
                axis.xaxis1 = rand() % 1450;
                rn1.rndm1();
                /*GAME WORKING*/
              for(yaxis_motion = 0;yaxis_motion<=650;yaxis_motion += 4)
                    {
                        if((rn1.rb <=50))
                        {
                            bomb(axis.xaxis1,yaxis_motion);
                              if((yaxis_motion <= 650) && (yaxis_motion >= 550))
                        {
                                    if( axis.xaxis1 <= (sm.cirx1 + 50) && axis.xaxis1 >= (sm.cirx1 - 50))
                                    {
                                        ::lyf--;
                                        yaxis_motion +=100;
                                    }
                        }
                            ell.FILL_ENVIRONMENT();
                            sm.create_mo();
                        }
                        else
                        {
                            sb.snow_ball(axis.xaxis1,yaxis_motion);
                            if((yaxis_motion <= 650) && (yaxis_motion >= 550))
                        {
                                    if( axis.xaxis1 <= (sm.cirx1 + 50) && axis.xaxis1 >= (sm.cirx1 - 50))
                                    {

                                        ::score++;
                                        yaxis_motion +=100;
                                    }
                        }
                            ell.FILL_ENVIRONMENT();
                            sm.create_mo();
                        }
                        setcolor(RED);
                        setbkcolor(LIGHTBLUE);
                        settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
                        sprintf(arr2,"SCORE = %d",::score);
                        outtextxy(1250,70,arr2);
                    if(::score == 3)
                        game_run = FALSE;
                    if(::lyf == 0)
                        goto label1;
                    }
        }

        ::score = 0;
        ::lyf += 1;

        lev.level2();
        load.load();
        setbkcolor(BLACK);

        ell.FILL_ENVIRONMENT();
        sm.create_mo();
        sm2.create_mo2();
//game_run = TRUE;
           /*  while(game_run)
        {
             PlaySound("gameaudio", NULL,SND_ASYNC);
                ell.FILL_ENVIRONMENT();
                sm.create_mo();
                sm2.create_mo2();
                axis.xaxis1 = rand() % 1450;
                axis.xaxis2 = rand() % 1450;
                rn1.rndm1();
                rn2.rndm1();
              for(yaxis_motion = 0;yaxis_motion<=650;yaxis_motion += 4)
                    {
                        if((rn1.rb <=50) || (rn2.rb <=50))
                        {
                            bomb(axis.xaxis1,yaxis_motion);
                            bomb(axis.xaxis2,yaxis_motion);
                              if((yaxis_motion <= 650) && (yaxis_motion >= 550))
                        {
                                    if(( axis.xaxis1 <= (sm.cirx1 + 50) && axis.xaxis1 >= (sm.cirx1 - 50)) || ( axis.xaxis2 <= (sm.cirx1 + 50) && axis.xaxis2 >= (sm.cirx1 - 50)) || ( axis.xaxis1 <= (sm2.cirx7 + 50) && axis.xaxis1 >= (sm2.cirx7 - 50)) || ( axis.xaxis2 <= (sm2.cirx7 + 50) && axis.xaxis2 >= (sm2.cirx7 - 50)))
                                    {
                                        ::lyf-=1;
                                        yaxis_motion +=100;
                                        goto label1;
                                    }
                        }
                            ell.FILL_ENVIRONMENT();
                            sm.create_mo();
                            sm2.create_mo2();
                        }
                        else
                        {
                            sb.snow_ball(axis.xaxis1,yaxis_motion);
                             sb.snow_ball(axis.xaxis2,yaxis_motion);
                            if((yaxis_motion <= 650) && (yaxis_motion >= 550))
                        {
                                    if(( axis.xaxis1 <= (sm.cirx1 + 50)) && (axis.xaxis1 >= (sm.cirx1 - 50)) || ( axis.xaxis2 <= (sm.cirx1 + 50) && axis.xaxis2 >= (sm.cirx1 - 50)) || ( axis.xaxis1 <= (sm2.cirx7 + 50) && axis.xaxis1 >= (sm2.cirx7 - 50)) || ( axis.xaxis2 <= (sm2.cirx7 + 50) && axis.xaxis2 >= (sm2.cirx7 - 50)))
                                    {

                                        ::score+=2;
                                        yaxis_motion +=100;
                                        goto label1;
                                    }
                        }
                            ell.FILL_ENVIRONMENT();
                            sm.create_mo();
                            sm2.create_mo2();
                        }
                        setcolor(RED);
                        setbkcolor(LIGHTBLUE);
                        settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
                        sprintf(arr2,"SCORE = %d",::score);
                        outtextxy(1250,70,arr2);
                    }

*/
game_run = TRUE;
    while(game_run)
        {
             srand(time(0));
             PlaySound("gameaudio3", NULL,SND_ASYNC);    //GAMEAUDIO
                ell.FILL_ENVIRONMENT();
                sm.create_mo();
                sm2.create_mo2();
                axis.xaxis1 = rand() % 1450;
                axis.xaxis2 = rand() % 1450;
                rn1.rndm1();
                rn2.rndm1();
                /*GAME WORKING*/
             for(yaxis_motion = 0;yaxis_motion<=650;yaxis_motion += 4)
                    {
                        if((rn1.rb <=50))
                        {
                            bomb(axis.xaxis1,yaxis_motion);
                            bomb(axis.xaxis2,yaxis_motion);
                              if((yaxis_motion <= 650) && (yaxis_motion >= 550))
                        {
                                    if(( axis.xaxis1 <= (sm.cirx1 + 50) && axis.xaxis1 >= (sm.cirx1 - 50)) || ( axis.xaxis2 <= (sm.cirx1 + 50) && axis.xaxis2 >= (sm.cirx1 - 50)) || ( axis.xaxis1 <= (sm2.cirx7 + 50) && axis.xaxis1 >= (sm2.cirx7 - 50)) || ( axis.xaxis2 <= (sm2.cirx7 + 50) && axis.xaxis2 >= (sm2.cirx7 - 50)))
                                    {
                                        ::lyf--;
                                        yaxis_motion +=100;
                                    }
                        }
                            ell.FILL_ENVIRONMENT();
                            sm.create_mo();
                            sm2.create_mo2();
                        }
                        if(rn1.rb >=50)
                        {
                            sb.snow_ball(axis.xaxis1,yaxis_motion);
                            sb.snow_ball2(axis.xaxis2,yaxis_motion);
                            if((yaxis_motion <= 650) && (yaxis_motion >= 550))
                        {
                                   if(( axis.xaxis1 <= (sm.cirx1 + 50) && axis.xaxis1 >= (sm.cirx1 - 50)) || ( axis.xaxis2 <= (sm.cirx1 + 50) && axis.xaxis2 >= (sm.cirx1 - 50)) || ( axis.xaxis1 <= (sm2.cirx7 + 50) && axis.xaxis1 >= (sm2.cirx7 - 50)) || ( axis.xaxis2 <= (sm2.cirx7 + 50) && axis.xaxis2 >= (sm2.cirx7 - 50)))
                                    {

                                        ::score++;
                                        yaxis_motion +=100;
                                    }
                        }
                            ell.FILL_ENVIRONMENT();
                            sm.create_mo();
                            sm2.create_mo2();
                        }


                        if((rn2.rb <=50))
                        {
                            bomb(axis.xaxis2,yaxis_motion);
                            bomb(axis.xaxis1,yaxis_motion);
                              if((yaxis_motion <= 650) && (yaxis_motion >= 550))
                        {
                                    if(( axis.xaxis1 <= (sm.cirx1 + 50) && axis.xaxis1 >= (sm.cirx1 - 50)) || ( axis.xaxis2 <= (sm.cirx1 + 50) && axis.xaxis2 >= (sm.cirx1 - 50)) || ( axis.xaxis1 <= (sm2.cirx7 + 50) && axis.xaxis1 >= (sm2.cirx7 - 50)) || ( axis.xaxis2 <= (sm2.cirx7 + 50) && axis.xaxis2 >= (sm2.cirx7 - 50)))
                                    {
                                        ::lyf--;
                                        yaxis_motion +=100;
                                    }
                        }
                            ell.FILL_ENVIRONMENT();
                            sm.create_mo();
                            sm2.create_mo2();
                        }
                        if(rn2.rb >=50)
                        {
                            sb.snow_ball2(axis.xaxis2,yaxis_motion);
                            sb.snow_ball(axis.xaxis1,yaxis_motion);
                            if((yaxis_motion <= 650) && (yaxis_motion >= 550))
                        {
                                   if(( axis.xaxis1 <= (sm.cirx1 + 50) && axis.xaxis1 >= (sm.cirx1 - 50)) || ( axis.xaxis2 <= (sm.cirx1 + 50) && axis.xaxis2 >= (sm.cirx1 - 50)) || ( axis.xaxis1 <= (sm2.cirx7 + 50) && axis.xaxis1 >= (sm2.cirx7 - 50)) || ( axis.xaxis2 <= (sm2.cirx7 + 50) && axis.xaxis2 >= (sm2.cirx7 - 50)))
                                    {

                                        ::score++;
                                        yaxis_motion +=100;
                                    }
                        }
                            ell.FILL_ENVIRONMENT();
                            sm.create_mo();
                            sm2.create_mo2();
                        }

                    if(::score == 2)
                        game_run = FALSE;
                    if(::lyf == 0)
                        goto label1;


                    }


        label1:
                PlaySound("gameaudio4", NULL,SND_ASYNC);
                        if((lyf == 0) || (::score == 20) || (ch == 'x'))
                            {
                                cleardevice();
                                setbkcolor(BLACK);
                                for(int i = 30;i<= 290; i++)
                                {
                                    setfillstyle(SOLID_FILL,BLACK);
                                    floodfill(0,0,5);
                                    settextstyle(TRIPLEX_FONT,HORIZ_DIR,9);
                                    setcolor(RED);
                                    outtextxy(i,350,"GAME OVER");
                                    delay(10);
                                }
                                PlaySound("gameaudio4", NULL,SND_ASYNC);
                                rnbow.rbow();

                                game_run = FALSE;
                            }

        }
        closegraph();
        return 0;
}
