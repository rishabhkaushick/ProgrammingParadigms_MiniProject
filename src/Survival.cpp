#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<time.h>
#include<iostream.h>
#include<stdlib.h>

#define MAX 1000
int a,maxx,maxy,x=0,y=0,ax,ay;
int dist=0,b,c=0,l1,l2,l3,l4,tf=0,cx1,cx2,hard=0;
int inx1,inx2,arcx,lg1,score=0,end=0;
char ch,me[20];
class game1
{
	public:
	void lines();
	void perform1();
	void obstacle1(int);
	void obstacle2(int);
	void car1(int,int);
	void hit(int,int,int);
	void firstpage();
	void lastpage();
	int ll1,ll2;
};
class game:public game1
{
	public:
	void perform();
	void obstacle(int,int);
	void car(int,int);
	void obstacleCreator();
	int gameover(int);

}g;
void game1:: firstpage()
{
	char decide;
	settextstyle(0,HORIZ_DIR,4);
	outtextxy(200,100,"SURVIVAL");
	settextstyle(0,0,1);
	outtextxy(13,183,"EASY");
	outtextxy(maxx-97,maxy-297,"HARD");
	rectangle(10,180,100,280);
	rectangle(maxx-10,maxy-200,maxx-100,maxy-300);
	outtextxy(200,ay,"Press -> right key for hard ");
	outtextxy(200,ay+10,"Press <- left key for easy");
	while(1)
	{
		if(kbhit())
		{
			decide=getch();
			switch(decide)
			{
				case 75:
				perform1();
				goto l;
				break;
				case 77:
				g.perform();
				goto l;
				break;
			}
		}
	}
	l:
}
void game1::hit(int ll1,int ll2,int lg1)
{
	if(y>=maxy-100)
	{
		if(((lg1>l1 && lg1<l2)||(lg1>l2 && lg1<l3))&&((ll1>l1 && ll1<l2)&&(ll2>l2 &&ll2<l3))
		   ||((lg1>l2 && lg1<l3)||(lg1>l3 && lg1<l4))&&((ll1>l2 && ll1<l3)&&(ll2>l3 &&ll2<l4))
		   ||((lg1>l1 && lg1<l2)||(lg1>l3 && lg1<l4))&&((ll1>l1 && ll1<l2)&&(ll2>l3 &&ll2<l4))
		   ||((lg1>l3 && lg1<l4) && (ll1>l3 && ll1<l4)&&(tf==0))
		   ||((lg1>l1 && lg1<l2) && (ll1>l1 && ll1<l2)&&(tf==0))
		   ||((lg1>l2 && lg1<l3) && (ll1>l2 && ll1<l3)&&(tf==0)))
		{
			if(((lg1>l3 && lg1<l4) && (ll1>l1 && ll1<l2)&&(tf==0))
			|| ((lg1>l3 && lg1<l4) && (ll1>l2 && ll1<l3)&&(tf==0)))
			goto ro;
			else
			{
				settextstyle(SANS_SERIF_FONT,HORIZ_DIR,7);
				outtextxy(50,ay,"YIKES!!");
				delay(2000);
				end=1;
			}
		}
		else
		{       ro:
			score+=10;
		}
	}
}
void game1::obstacle1(int l)
{
	if(l==1)
	rectangle(ll1=l1+20,y,l2-20,y+50);
	if(l==2)
	rectangle(ll1=l2+20,y,l3-20,y+50);
	if(l==3)
	rectangle(ll1=l3+20,y,l4-20,y+50);
}
void game1::obstacle2(int l)
{
	if(l==1)
	{
		rectangle(ll1=l1+20,y,l2-20,y+50);
		rectangle(ll2=l2+20,y,l3-20,y+50);
	}
	if(l==2)
	{
		rectangle(ll1=l2+20,y,l3-20,y+50);
		rectangle(ll2=l3+20,y,l4-20,y+50);
	}
	if(l==3)
	{
		rectangle(ll1=l1+20,y,l2-20,y+50);
		rectangle(ll2=l3+20,y,l4-20,y+50);
	}
}
void game1:: car1(int cx1,int cx2)
{
	arc(arcx-cx1+cx2,maxy-40,0,180,10);
	rectangle(lg1=inx1-cx1+cx2,maxy,inx2-cx1+cx2,maxy-40);
}
void game1::perform1()
{
	cx1=0,cx2=0,c=0;
	int co=0,n=0,nn,j=0;
	while(1)
	{
		setbkcolor(8);
		lines();
		g.car1(cx1,cx2);
		y+=10;
		if(tf==0)
			g.obstacle1(b);
		if(tf==1)
			g.obstacle2(b);
		if(y>=maxy)
		{
			y=0;
			b++;
		}
		if(b>3)
		{
			b=1;
			c++;
			if(c%2==0)
			tf=0;
			else
			tf=1;
		}
		if(kbhit())
		{
			hard++;
			ch=getch();
			if((ch==77 && (cx1==60 && cx2==0))
			|| (ch==75 && (cx1==0 && cx2==60)))
			{
				cx1=0,cx2=0;
				goto yo;
			}
			if(ch==75)
			{
				cx1=60;
				cx2=0;
			}
			if(ch==77)
			{
				cx1=0;
				cx2=60;
			}
			if(ch==27)
			exit(0);
			if(!(co>30))
			if(hard%2==0)
			co=co+2;
		}
		yo:
		g.hit(ll1,ll2,lg1);
		if(end==1)
		break;
		sprintf(me,"SCORE: %d",score);
		settextstyle(0,0,1);
		outtextxy(10,10,me);
		delay(nn=50-co);
		n=n+nn;
		cleardevice();
	}
}
void game1::lines ()
{
	line(l1=0.3*maxx,0,0.3*maxx,maxy);
	line(l2=0.4*maxx,0,0.4*maxx,maxy);
	line(l3=0.5*maxx,0,0.5*maxx,maxy);
	line(l4=0.6*maxx,0,0.6*maxx,maxy);
}
void game1:: lastpage()
{
	cleardevice();
	setbkcolor(5);
	for(int b=0;b<getmaxcolor()-5;b++)
	{
		settextstyle(SANS_SERIF_FONT,HORIZ_DIR,b);
		outtextxy(ax-200,ay,"GAME OVER!");
		delay(200);
		cleardevice();
	}
	delay(200);
	outtextxy(10,10,me);
	delay(2000);
}
struct queue
{
	int l[MAX];
	int top;
	int i[MAX];
	int bottom;
}s;

void initialise()
{
	s.top=-1;
	s.bottom=0;
}

int empty()
{
	if(s.top==(s.bottom-1))
	return 1;
	else
	return 0;
}

int full()
{
	if(s.top==MAX-1)
	return 1;
	else
	return 0;
}

void enqueue(int n)
{

	if(n<4)
	{
		int i1,i2;
		int j,k;
		int counter =0;
		int c1=0, c2=0;

		if(full()==1)
		{
		cout<<"Stack Overflow"<<endl;
		}
		else
		{
			if(n==1)
			{
				j=2;
				k=3;
			}
			if(n==2)
			{
				j=1;
				k=3;
			}
			if(n==3)
			{
				j=1;
				k=2;
			}
			for(i1=s.bottom;i1<=s.top;i1++)
			{
				if(n==s.l[i1])
				{
					if(s.i[i1]<150)
					{
						counter=1;
					}
				}
				else if(j==s.l[i1])
				{
					if(s.i[i1]<90)
					{
						c1=1;
					}
				}
				else if(k==s.l[i1])
				{
					if(s.i[i1]<90)
					{
						c2=1;
					}
				}
				else
				{
				}
			}
			if((c1==1)&&(c2==1))
			{
				counter =1;
			}
			if(counter==0)
			{
				s.top++;
				s.l[s.top]=n;
				s.i[s.top]=0;
			}
		}
	}
}

void dequeue()
{
	if(empty()==1)
	{
		cout<<"Underflow"<<endl;
	}
	else
	{
		s.bottom++;
	}
}

void display()
{
	if(empty()==1)
	{
		cout<<"Underflow"<<endl;
	}
	else
	{
		int j=0;
		printf("\n");
		for(j=s.bottom;j<=s.top;j++)
		{
			cout<<"lane = "<<s.l[j];
			cout<<"i = "<<s.i[j];
		}
	}
}

int rand_int(int a,int b)
{
    //The basic function here is like (rand() % range)+ Lower_bound

    srand(time(0));
    if (a > b)
	return((rand() % (a-b+1)) + b);
    else if (b > a)
	return((rand() % (b-a+1)) + a);
    else
	return a;
}
int game::gameover(int carlane1)
{
	int j=0;int counter=0;
	for(j=s.bottom;j<=s.top;j++)
	{
		if((s.i[j]>360)&&(s.i[j]<400)&&(carlane1==s.l[j]))
		{
			counter=1;
			break;
		}
	}
	return counter;
}

void game::obstacle(int lane, int i)
{
	if(lane==1)
	rectangle(ax-120,10+i,ax-70,50+i);
	if(lane==2)
	rectangle(ax-56,10+i,ax-6,50+i);
	if(lane==3)
	rectangle(ax+8,10+i,ax+58,50+i);
}

void game::obstacleCreator()
{
	int r;
	if(dist<300)
	{
		r=rand_int(1,8);
	//	cout<<r<<endl;
		enqueue(r);
	}
	else if((dist<600)&&(dist>=300))
	{
		r=rand_int(1,6);
	//	cout<<r<<endl;
		enqueue(r);
	}
	else if(dist>=900)
	{
		r=rand_int(1,4);
	//	cout<<r<<endl;
		enqueue(r);
	}
	else
	{
		r=rand_int(1,5);
	//	cout<<r<<endl;
		enqueue(r);
	}
}

void game:: car(int lane, int i)
{
	//arc(ax-30,maxy-40,0,180,10);
	//rectangle(ax-20,maxy,ax-40,maxy-40);
	if(lane==1)
	rectangle(ax-120,10+i,ax-70,50+i);
	if(lane==2)
	rectangle(ax-56,10+i,ax-6,50+i);
	if(lane==3)
	rectangle(ax+8,10+i,ax+58,50+i);
}

void game::perform()
{
	initialise();
	int j;
	int ch;
	int carlane=2;
	while(g.gameover(carlane)==0)
	{
		//cout<<"Counter = " <<g.gameover(carlane);
		while((!kbhit())&&(gameover(carlane)==0))
		{
			setbkcolor(8);
			g.car(carlane,400);
			lines();
			sprintf(me,"SCORE: %d",score);
		outtextxy(10,10,me);
		dist++;
			g.obstacleCreator();
			for(j=s.bottom;j<=s.top;j++)
			{
				if(s.i[j]==maxy)
				{       score += 100;
					dequeue();
				}
				g.obstacle(s.l[j],s.i[j]);
				(s.i[j])++;
			}
			//display();
			delay(3);
			cleardevice();
		}
		if(kbhit())
		{
			ch=getch();
			//cout<<"Ch= "<<ch<<endl;
			if((ch==75)&&(carlane>1))
			{
				carlane--;
			}
			if((ch==77)&&(carlane<3))
			{
				carlane++;
			}
		}
	}
}

int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,(char *)"C:\\TURBOC3\\BGI");
	maxx=getmaxx();
	maxy=getmaxy();
	ax=maxx/2 ;
	ay=maxy/2;
	arcx=ax-30;
	inx1=ax-40;
	inx2=ax-20;
	g.firstpage();
	g.lastpage();
	exit(0);
	closegraph();
	return 0;
}
