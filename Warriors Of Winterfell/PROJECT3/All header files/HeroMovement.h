#ifndef MYHEADER_H_INCLUDED
#define MYHEADER_H_INCLUDED

bool gtl=false;
bool gtr=false;
bool gtu=false;
bool gtd=false;
int p1x=450;
int p1y=50;
int p1s = 130;

void heroMovemet()
{
	if(p1x<0)
	{
		p1x=0;
		gtl=false;
		gtr=false;
		gtu=false;
		gtd=false;
	}
	if(p1x+150>=1000)
	{
		p1x=850;
		gtl=false;
		gtr=false;
		gtu=false;
		gtd=false;
	}
	if(p1y<=0)
	{
		p1y=0;
		gtl=false;
		gtr=false;
		gtu=false;
		gtd=false;
	}
	if(p1y+150>=600)
	{
		p1y=450;
		gtl=false;
		gtr=false;
		gtu=false;
		gtd=false;
	}
}

#endif // !MYHEADER_H_INCLUDED
