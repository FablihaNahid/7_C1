#include "iGraphics.h"
#include "bitmap_loader.h"
#include "myheader1.h"

//background rendering

int background[2];
int background_x[] = {0,0},background_y[]={0,0};

int timecount=0;
char str_time[10];

void showTime()
{
	timecount ++;

}

void change_background()
{ for(int i=0;i<2;i++)
	{
		background_x[i] -= 10; //left slide
		if(background_x[i]+800<0) //left slide out of frame
			background_x[i] = background_x[(i+1)%2]+800;

	}
} //backgroundrendering




void ShowScore(void);
void ReadScore(void);
void knifeThrow();
void knightrun();



void runww2();

int speedWW2;


int point=0;
char keepScore[1000];
char pname[100];


int speedWW = 10;
int speedJS = 6;
int speedNK=10;
int counter =0;
int birdx=0;

int birdy=260;
int image1;

int recx=100;
int recy=100;
int jonwidth=115;
int flagRight =1;
int flagLeft =1;

int timeCount=0;
int scoreCount=0;
int health=0;

char scorePlus[100];
char gg[100];

int playImage;
int scoreImage;
int instructImage;
int backgroundImage;
int playPage;
int scorePage;
int instructPage;
int jonsnow;
int whitewalker;
int gameover;
int knifeImage;
int nightking;
int whitewalker2;
int youWinImage;

int nightkingX=750;
int nightkingY = 150;

int snowX=100;
int snowY=150;
int whiteX=800;
int whiteY=150;
int white2X=700;
int white2Y=150;

int knifeButton=0;
int knifeX= 100;
int knifeY=190;


int t;
int s;
int dx=20;
int dy=30;
int jumpTimer,jumpDownTimer;
int snowJumpTimer=12;


void runww();
void scoreCounter();
void timeCounter();

struct ScoreInfo
{

    char name[10];
    int score;



};

ScoreInfo HighScore[7];


int gameState= -1;

//enum GameStates{menuPage=-1,gamePlayPage,highScorePage,instructionsPage,gameOverPage};

void snowjump()
{
	snowY=snowY+dx;
    if(snowY>=500)
    {

        dx=-dx;

    }
    if(snowY<=150)
    {
        dx=0;
        snowY=150;
    }

}

void iDraw()
{
    //place your drawing codes here
    iClear();



    if (gameState==-1)


    {




        iShowImage(120,0,1000,800,backgroundImage);
        iShowImage(birdx+20,birdy+300,231,80,playImage);
        iShowImage(birdx+20,birdy+108,231,80,scoreImage);
        iShowImage(birdx+15,birdy-100,285,80,instructImage);
    }



    if (gameState==0)
    {




        iShowImage(0,0,1000,800,playPage);


		for(int i=0;i<2;i++)
		{
		iShowImage(background_x[i],0,1000,800,background[i]);

		} //backgroundrendering


        iShowImage(snowX,snowY,115,150,jonsnow);

		iShowImage(white2X,white2Y,150,250,whitewalker2);
		iShowImage(whiteX,whiteY,125,150,whitewalker);

        iShowImage(750,648,150,150,t);
        iShowImage(100,648,150,150,s);


        sprintf(gg, "%d", timeCount);//will
        iSetColor(0,0,0);
        iText(845,715,gg, GLUT_BITMAP_TIMES_ROMAN_24);

		sprintf(scorePlus, "%d", scoreCount);//will
        iSetColor(0,0,0);
        iText(205,715,scorePlus, GLUT_BITMAP_TIMES_ROMAN_24);




      /*  if (knifeButton==1)
        {

            iSetTimer(25,knifeThrow);
            iShowImage(knifeX,knifeY,50,40,knifeImage);





        }*/





        if (snowX>=2 && snowX<=980)
        {

            flagRight=1;
            flagLeft=1;



        }

        else
        {

            flagRight=0;
            flagLeft=0;

        }

        if(snowX >=900)
        {
            snowX=898;
        }
        if(snowX <=5)
        {
            snowX=6;
        }



		if(snowX>=whiteX && snowX<=whiteX+50 && snowY==whiteY)
			gameState=3;



		 if(snowX>=white2X && snowX<=white2X+50 && snowY==white2Y)
            gameState=3;




		if (gameState==3)
            whiteX=800;




        /* flagRight=1;
         flagLeft=1;*/

        /*if (snowX==50){

          flagLeft=0;


          }*/
    }


		if(gameState!=0 && gameState!=4 && gameState!=3 && gameState!=1 && gameState!=2)
		{
		   timeCount =0;
		}


    else if(gameState==1)
    {
        iShowImage(0,0,1000,800,scorePage);
        iSetColor(0,0,0);
       ShowScore();



        iText(420, 550,"Your Score :", GLUT_BITMAP_TIMES_ROMAN_24);

		timeCount=0;


    }
    else if (gameState==3)
    {
        iShowImage(100,180,750,500,gameover);
        //  sprintf(scorePlus, "%d", scoreCount);//will
        iSetColor(255,255,255);
        iText(85,715,"Your score :", GLUT_BITMAP_TIMES_ROMAN_24);
        iText(255,715,scorePlus, GLUT_BITMAP_TIMES_ROMAN_24);
		timeCount=0;

		HighScore[2].score = scoreCount;
    }


    else if(gameState==2)
    {
        iShowImage(0,0,1000,800,instructPage);
		timeCount=0;


    }


    if (timeCount == 25)
    {

        gameState=4;
    }

    else	if (gameState==4)


    {
        iShowImage(0,0,1000,800,instructPage);

        iShowImage(0,0,1000,800,playPage);


		for(int i=0;i<2;i++)
		{
		iShowImage(background_x[i],0,1000,800,background[i]);

		} //backgroundrendering


        iShowImage(snowX,snowY,110,140,jonsnow);
        iShowImage(nightkingX,nightkingY,265,180,nightking);
        iShowImage(750,648,150,150,t);
        iShowImage(100,648,150,150,s);


        sprintf(gg, "%d", timeCount);//will
        iSetColor(0,0,0);
        iText(845,715,gg, GLUT_BITMAP_TIMES_ROMAN_24);

        sprintf(scorePlus, "%d", scoreCount);//will
        iSetColor(0,0,0);
        iText(205,715,scorePlus, GLUT_BITMAP_TIMES_ROMAN_24);



		if(snowX>=nightkingX && snowX<=nightkingX+40 && snowY==nightkingY)
			gameState=3;


        if (knifeButton==1)
       {

            iSetTimer(25,knifeThrow);
            iShowImage(knifeX,knifeY,95,14,knifeImage);




        }


	if (health==2)

		gameState=5;


    }


	 else if (gameState==5)

        {
            iShowImage(0,0,1000,800,youWinImage);
			timeCount=0;
        }

}




void iPassiveMouse(int x, int y)
{
    ;
}



void iMouseMove(int mx, int my)
{
    printf("x = %d, y= %d\n", mx, my);
    //place your codes here


}


void iMouse(int button, int state, int mx, int my)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {

        if (mx>= birdx+20 && mx<=birdx+300 && my>=birdy+300 && my<=birdy+500)

            gameState= 0 ;

        else if(mx>= birdx+20 && mx<=birdx+200 && my>=birdy+105 && my<=birdy+350)
            gameState=1;

        else if(mx>= birdx+20 && mx<=birdx+200 && my>=birdy-105 && my<=birdy+250)
            gameState=2;



        //place your codes here
        //	printf("x = %d, y= %d\n",mx,my);
        //x += 10;
        //y += 10;
    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here
        //x -= 10;
        //y -= 10;
    }
}

/*
 function iKeyboard() is called whenever the user hits a key in keyboard.
 key- holds the ASCII value of the key pressed.
 */
void iKeyboard(unsigned char key)
{
    if (key == 'q')
    {
        exit(0);
    }

    if (key == 'b')
    {
        gameState=-1;
    }

    if(key == 'd')
    {
        if ((gameState==0 || gameState==4)&& flagRight==1)


            snowX+=speedJS;


    }
    if(key == 'a')
    {
        if ((gameState==0 || gameState==4) && flagLeft==1 )


            snowX-=speedJS;
    }


    if(key == ' ')
    {
		//printf("%d\n",p);
        iResumeTimer(snowJumpTimer);
        dx=20;

        scoreCount++;

    }
    if (key =='x')
        snowY-=speedJS;

    if(key == 's')
    {
        knifeButton=1;
		//knifeX++;
        knifeX=snowX+30;
		knifeY=snowY+30;
    }


	 if (key =='n')
        gameState=4;

}


void iSpecialKeyboard(unsigned char key)
{

    if (key == GLUT_KEY_END)
    {
        exit(0);
    }
    if(key ==GLUT_KEY_RIGHT)
    {

        birdx =birdx+15;
    }

    //place your codes for other keys here
}



int wx=10;
void runww()
{

    if (gameState==0)
    {
        whiteX= whiteX-speedWW;

        if (whiteX <=2)
           whiteX=800;

    }

}



void runww2()
{

    if (gameState==0)
    {
        white2X=white2X-10;

        if (white2X <=2)
           white2X=1000;

    }

}





void knightrun()
{

    if (gameState==4)
    {
        nightkingX= nightkingX-speedNK;

        if (nightkingX <-10 )
            speedNK= -speedNK;

		if (nightkingX>950)
            speedNK= -speedNK;



    }

}

void knifeThrow()
{

    knifeX=knifeX+5;

            if (knifeX==nightkingX+85 && ( knifeY>=nightkingY && knifeY<=nightkingY+175))
            {


                knifeX= 10000;
                health++;

            }


}



void timeCounter()
{

    timeCount++;

}




void ReadScore()
{

    FILE *fp = fopen("score.txt", "r");






    for(int i=0; i<2; i++)

    {

        fscanf(fp, " %d", &HighScore[i].score);




    }


    fclose(fp);



}



void ShowScore()
{



    sprintf(keepScore, "%d", HighScore[2].score);
    iText(550, 550,keepScore, GLUT_BITMAP_TIMES_ROMAN_24);


}




int main()
{
    //place your own initialization codes here.s

    ReadScore();
    iInitialize(1000, 800, "Demo");

	iSetTimer(1000,showTime);
	iSetTimer(10,change_background);
	rx = 5;
	ry = 7;

	pic_x = 0;
	pic_y = 0;


    backgroundImage=iLoadImage("images\\mmback.jpg");
    playImage=iLoadImage("images\\play.png");
    instructImage=iLoadImage("images\\instructions.png");
    scoreImage=iLoadImage("images\\asd3.png");

    playPage=iLoadImage("images\\b4.jpg");
    instructPage=iLoadImage("images\\instructpage.png");
    scorePage=iLoadImage("images\\scorepage1.png");

    jonsnow=iLoadImage("images\\jonsnow.png");
    whitewalker =iLoadImage("images\\whitewalker.png");

    gameover =iLoadImage("images\\gameover.png");

    knifeImage=iLoadImage("images\\knifeimage1.png");
    nightking=iLoadImage("images\\nightking.png");
	whitewalker2=iLoadImage("images\\whitewalker2.png");

	youWinImage=iLoadImage("images\\youWinImage.png");

    t=iLoadImage("images\\t1.png");
    s=iLoadImage("images\\s1.png");



    iSetTimer(30,runww);

    iSetTimer(20,runww2);

	iSetTimer(30,knightrun);

    iSetTimer(snowJumpTimer,snowjump);

	iSetTimer(600,timeCounter);

	background[0] = iLoadImage("images\\back.jpg");
	background[1] = iLoadImage("images\\back1.png");

    iStart(); // it will start drawing

    return 0;
}


