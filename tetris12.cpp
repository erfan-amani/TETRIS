//Erfan Aman Abadi
//game project : TETRIS
//Student ID :986127006
//2020/01/10
#include<windows.h>
#include<conio.h>
#include <stdio.h>
#include <time.h>

char screen[35][56]={0};
char ch1=219;//frame code
char ch2=178;//shapes code
char ch3=0;//in to the frame cod
int time_sleep=200;//time for sleep beetwen moving of shapes
int score=0;
int mood=1;
bool stop=true;
struct record
{
	char name[30];
	int score;
	int time_level;
	struct record *next;
} first,*last;
FILE *easy,*normal,*hard,*legend;
void menu(int);
void start_game(void);
void help(void);
void setting(void);
void setting_difficulty();
void setting_color();
void about(void);
int check_game_over(void);
void getting_record(void);
void print_record(void);
void frame(void);
void next_shape(int);
void select_shape(int);
void check_ful_line(void);
void move_zed(int,int);
void move_el(int,int);
void move_line(int,int);
void move_plus(int,int);
void move_square(int,int);
void zed(int,int,int,int);
void el(int,int,int,int);
void line(int,int,int,int);
void plus(int,int,int,int);
void square(int,int,int,int);
void exit(void);

//****************************************
void gotoxy(int x, int y){
	HANDLE stdOutput;
    COORD pos;
    stdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(stdOutput, pos);
	return;
}
//*******************************************
void menu(int flag)
{
	int i;
	int b=9;//situation of arrow (y of arrow)
	char move;
	int time1,time2;
	
	if(flag==0)
	{
		time1=300;
		time2=50;
	}
	else	//if(flag==1)
	{
		time1=0;
		time2=0;				
	}
	Sleep(time1);
	//drawing tetris
	gotoxy(12,1);
	printf("%c%c%c%c%c%c  %c%c%c%c%c%c  %c%c%c%c%c%c", ch1,ch1,ch1,ch1,ch1,ch1,ch1,ch1,ch1,ch1,ch1,ch1,ch1,ch1,ch1,ch1,ch1,ch1);
	printf("  %c%c%c%c%c%c  %c%c%c%c  %c%c%c%c%c%c", ch1,ch1,ch1,ch1,ch1,ch1,ch1,ch1,ch1,ch1,ch1,ch1,ch1,ch1,ch1,ch1);
	Sleep(time1);
	gotoxy(12,2);
	printf("  %c%c    %c%c        %c%c    %c%c  %c%c   %c%c   %c%c", ch1,ch1,ch1,ch1,ch1,ch1,ch1,ch1,ch1,ch1,ch1,ch1,ch1,ch1);
	Sleep(time1);
	gotoxy(12,3);
	printf("  %c%c    %c%c%c%c%c%c    %c%c    %c%c%c%c%c%c",ch1,ch1,ch1,ch1,ch1,ch1,ch1,ch1,ch1,ch1,ch1,ch1,ch1,ch1,ch1,ch1);
	printf("   %c%c   %c%c%c%c%c%c", ch1,ch1,ch1,ch1,ch1,ch1,ch1,ch1);
	Sleep(time1);
	gotoxy(12,4);
	printf("  %c%c    %c%c        %c%c    %c%c %c%c    %c%c       %c%c", ch1,ch1,ch1,ch1,ch1,ch1,ch1,ch1,ch1,ch1,ch1,ch1,ch1,ch1);
	Sleep(time1);
	gotoxy(12,5);
	printf("  %c%c    %c%c%c%c%c%c    %c%c    %c%c", ch1,ch1,ch1,ch1,ch1,ch1,ch1,ch1,ch1,ch1,ch1,ch1);
	printf("  %c%c  %c%c%c%c  %c%c%c%c%c%c", ch1,ch1,ch1,ch1,ch1,ch1,ch1,ch1,ch1,ch1,ch1,ch1);
	gotoxy(13,7);
	for(i=0;i<22;i++)
	{
		Sleep(time2);
		printf("%c", 240);
	}
	for(i=56;i>34;i--)
	{
		gotoxy(i,7);
		Sleep(time2);
		printf("%c", 240);
	}
	//end of drawing logo (tetris)
	//printing menu choice
	gotoxy(22,9);
	printf(" %c      Play Game      %c", 244,245);
	Sleep(time1);
	gotoxy(22,11);
	printf(" %c        Help         %c", 244,245);
	Sleep(time1);
	gotoxy(22,13);
	printf(" %c       Setting       %c", 244,245);
	Sleep(time1);
	gotoxy(22,15);
	printf(" %c     About Creator   %c", 244,245);
	Sleep(time1);
	gotoxy(22,17);
	printf(" %c       Records       %c", 244,245);
	Sleep(time1);
	gotoxy(22,19);
	printf(" %c        Exit         %c", 244,245);
	gotoxy(23,21);
	for(i=0;i<22;i++)
	{
		Sleep(time2);
		printf("%c", 240);
	}
	for(i=44;i>34;i--)
	{
		gotoxy(i,21);
		Sleep(time2);
		printf("%c", 240);
	}
	//print moving help
	gotoxy(22,23);
	printf("  ********************");	
	gotoxy(22,24);
	printf("  *   up/down = w/s  *");
	gotoxy(22,25);
	printf("  *  select = enter  *");
	gotoxy(22,26);
	printf("  ********************");
	//printing arrows and move those
	gotoxy(20,b);
	printf("%c", 175);//right arrow
	gotoxy(48,b);
	printf("%c", 174);//left arrow
	do
	{
		if(kbhit())
		{
			move=getch();//get action
			Beep(10000000,100);
		}
		switch (move)
		{
			case 's':
				//remove arrow
				gotoxy(20,b);
				printf(" ");
				gotoxy(48,b);
				printf(" ");
				if(b==19)
				{
					b=9;
				}
				else
				{
					b=b+2;
				}
				move=NULL;
				break;
			case 'w':
				//remove arrow
				gotoxy(20,b);
				printf(" ");
				gotoxy(48,b);
				printf(" ");
				if(b==9)
				{
					b=19;
				}
				else
				{
					b=b-2;
				}
				move=NULL;
				break;	
			default:
				Sleep(500);
				gotoxy(20,b);
				printf(" ");
				gotoxy(48,b);
				printf(" ");
				Sleep(500);
				break;		
		}
		gotoxy(20,b);
		printf("%c", 175);
		gotoxy(48,b);
		printf("%c", 174);
	} while(move != 13);
	switch (b)
	{
		case 9:
			start_game();
			break;
		case 11:
			help();
			break;
		case 13:
			setting();
			break;
		case 15:
			about();
			break;
		case 17:
			system("cls");
			print_record();
			break;	
		case 19:
			system("cls");
			exit();
			break;	
	}
}
//*******************************************
void start_game(void)
{
	int shape1,shape2;
	score=0;
	system("cls");
	//making a random number
	srand(time(0));
	shape1=rand()%5+1;
	while(check_game_over()==0)
	{
		shape2=rand()%5+1;
		frame();
		next_shape(shape2);
		select_shape(shape1);
		check_ful_line();
		check_game_over();
		shape1=shape2;
	}
	getting_record();
	//remove and screen
	system("cls");
	for(int j=0;j<35;j++)
	{
		for(int i=0;i<56;i++)
		{
			screen[j][i]={0};
		}
	}
	menu(1);
}
//******************************
void getting_record(void)
{
	system("cls");
	//getting name for keeping record
	struct record *temp;
	temp=(struct record *) malloc (sizeof(struct record));
	gotoxy(15,3);
	printf("Notice !! When you exit and close game from exit key that exist in main menu your record save.\n\n\n**Enter Your Name :  ");
	scanf("%s", temp->name);
	temp->score=score;
	temp->time_level=time_sleep;
	if(first.next == NULL)
	{
		first.next = temp;
		last = temp;
	}
	else
	{
		last->next = temp;
		last = temp;
	}	
	last->next = NULL;
}
//**************************************************
void print_record(void)
{
	char rec[200];
	//opening files
	easy = fopen("record/record_easy.txt" , "r");
	normal = fopen("record/record_normal.txt" , "r");
	hard = fopen("record/record_hard.txt" , "r");
	legend = fopen("record/record_legend.txt" , "r");
	// Print the record of easy mode
	printf("\n\n  Easy Mode : \n\n");
	while( fgets(rec, 200, (FILE*)easy) != NULL ) 
	{ 
		printf("	%s", rec );
	} 
	// Print the record of normal mode
	printf("\n\n  Normal Mode : \n\n");
	while( fgets(rec, 200, (FILE*)normal) != NULL ) 
	{ 
		printf("	%s", rec );
	} 
	// Print the record of hard mode
	printf("\n\n  Hard Mode : \n\n");
	while( fgets(rec, 200, (FILE*)hard) != NULL ) 
	{ 
		printf("	%s", rec );
	} 
	// Print the record of legend mode
	printf("\n\n  Legend Mode : \n\n");
	while( fgets(rec, 200, (FILE*)legend) != NULL ) 
	{ 
		printf("	%s", rec );
	} 
	printf("\n\n** Press Any Key To Continue **");
	getch();
	system("cls");
    menu(1);
}
//**************************************************
void help(void)
{
	int i,j;
	system("cls");
	//draw frame
	for(i=0;i<=30;i++)
	{
		gotoxy(16+i,5);
		printf("%c", 205);
		gotoxy(16+i,17);
		printf("%c", 205);
	}
	//draw frame
	for(i=0;i<=10;i++)
	{
		gotoxy(15,6+i);
		printf("%c", 186);
		gotoxy(47,6+i);
		printf("%c", 186);
	}
	//draw frame
	for(i=0;i<=10;i++)
	{
		gotoxy(31,6+i);
		printf("%c", 186);
	}
	//draw in frame and detail of frame
	gotoxy(15,5);
	printf("%c", 201);
	gotoxy(47,5);
	printf("%c", 187);
	gotoxy(31,5);
	printf("%c", 203);
	gotoxy(20,6);
	printf("Action");
	gotoxy(38,6);
	printf("Key");
	gotoxy(47,7);
	printf("%c", 185);
	gotoxy(15,7);
	printf("%c", 204);
	for(i=0;i<=30;i++)
	{
		gotoxy(16+i,7);
		printf("%c", 205);
	}
	gotoxy(31,7);
	printf("%c", 206);
	gotoxy(18,9);
	printf("Move Right");
	gotoxy(39,9);
	printf("d");
	gotoxy(18,11);
	printf("Move Left");
	gotoxy(39,11);
	printf("a");
	gotoxy(20,13);
	printf("Rotate");
	gotoxy(39,13);
	printf("w");
	gotoxy(20,15);
	printf("Pause");
	gotoxy(38,15);
	printf("esc");
	gotoxy(15,17);
	printf("%c", 200);
	gotoxy(47,17);
	printf("%c", 188);
	gotoxy(31,17);
	printf("%c", 202);
	//continue and go to menu
	gotoxy(16,20);
	printf("** Press Esc To Back To Menu **");
	if(getch() == 27)
	{
		system("cls");
		menu(1);
	}
	else
	{
		help();
	}
}
//***************************************************
void about(void)
{
    char esc;
    system("cls");
    gotoxy(28,10);
    printf("This game producted by :");
    gotoxy(32,12);
    printf("ERFAN AMANABADI");
    gotoxy(35,14);
    printf("e-mail :");
    gotoxy(27,16);
    printf("erfan80amani23@gmail.com");
    gotoxy(25,22);
    printf("Press Esc To Back To Menu.");
    int i,j;
    char c1=177,c2=178;
    for(j=1;j<=2;j++)
    {
		for(i=24;i<=54;i++)
		{
			gotoxy(i,j*9);
			printf("%c", c1);
		}
    }
    for(i=4;i<=10;i+=5)
	{
	    for(j=9;j<=18;j++)
	    {
		    gotoxy(i*6,j);
		    printf("%c", c2);;
	    }
    }
    esc=getch();
    if(esc==27)
    {
        system("cls");
        menu(1);
    }
    else
    	about();
}
//*******************************************
void setting(void)
{
	int b=6;
	char move;
	system("cls");
	gotoxy(12,3);
	printf("SETTING");
	gotoxy(15,6);
	printf("Difficulty");
	gotoxy(15,8);
	printf("Color");
	//print moving help
	gotoxy(13,12);
	printf("  ********************");	
	gotoxy(13,13);
	printf("  *   up/down = w/s  *");
	gotoxy(13,14);
	printf("  *  select = enter  *");
	gotoxy(13,15);
	printf("  ********************");
	gotoxy(12,b);
	printf("%c", 175);
	do
	{
		if(kbhit())
		{
			move=getch();
			Beep(10000000,100);
		}
		switch (move)
		{
			case 's':
				//remove arrow
				gotoxy(12,b);
				printf(" ");
				if(b==12)
				{
					b=6;
				}
				else
				{
					b=b+2;
				}
				move=NULL;
				break;
			case 'w':
				//remove arrow
				gotoxy(12,b);
				printf(" ");
				if(b==6)
				{
					b=12;
				}
				else
				{
					b=b-2;
				}
				move=NULL;
				break;	
			default:
				Sleep(500);
				gotoxy(12,b);
				printf(" ");
				Sleep(500);
				break;		
		}
		gotoxy(12,b);
		printf("%c", 175);
	} while(move != 13);
	switch (b)
	{
		case 6:
			setting_difficulty();
			break;
		case 8:
			setting_color();
			break;				
	}
	system("cls");
	menu(1);
}
//*******************************************
void setting_difficulty(void)
{
	int b=6;
	char move;
	system("cls");
	gotoxy(12,3);
	printf("DIFFICULTY");
	gotoxy(15,6);
	printf("Easy");
	gotoxy(15,8);
	printf("normal");
	gotoxy(15,10);
	printf("Hard");
	gotoxy(15,12);
	printf("Legend");
	//print moving help
	gotoxy(13,18);
	printf("  ********************");	
	gotoxy(13,19);
	printf("  *   up/down = w/s  *");
	gotoxy(13,20);
	printf("  *  select = enter  *");
	gotoxy(13,21);
	printf("  ********************");			

	//printing arrow and move that
	gotoxy(12,b);
	printf("%c", 175);
	do
	{
		if(kbhit())
		{
			move=getch();
			Beep(10000000,100);
		}
		switch (move)
		{
			case 's':
				//remove arrow
				gotoxy(12,b);
				printf(" ");
				if(b==12)
				{
					b=6;
				}
				else
				{
					b=b+2;
				}
				move=NULL;
				break;
			case 'w':
				//remove arrow
				gotoxy(12,b);
				printf(" ");
				if(b==6)
				{
					b=12;
				}
				else
				{
					b=b-2;
				}
				move=NULL;
				break;	
			default:
				Sleep(500);
				gotoxy(12,b);
				printf(" ");
				Sleep(500);
				break;		
		}
		gotoxy(12,b);
		printf("%c", 175);
	} while(move != 13);
	switch (b)
	{
		case 6:
			time_sleep=350;
			break;
		case 8:
			time_sleep=250;
			break;	
		case 10:
			time_sleep=150;
			break;
		case 12:
			time_sleep=50;
			break;			
	}
	system("cls");
	menu(1);
}
//*************************************************
void setting_color(void)
{
	int b=8;
	char move;
	system("cls");
	gotoxy(12,3);
	printf("COLOR");
	gotoxy(12,6);
	printf("Choice ( background color - text and shape color)");
	gotoxy(15,8);
	printf("    red       -     white");
	gotoxy(15,10);
	printf("   black      -   light red");
	gotoxy(15,12);
	printf("   black      -    white");
	gotoxy(15,14);
	printf("   gray       -  light yellow");
	gotoxy(15,16);
	printf("   black      -     green");
	gotoxy(15,18);
	printf("bright white  -   light red");
	gotoxy(15,20);
	printf(" bright white  -     green");
	//print moving help
	gotoxy(13,25);
	printf("  ********************");	
	gotoxy(13,26);
	printf("  *   up/down = w/s  *");
	gotoxy(13,27);
	printf("  *  select = enter  *");
	gotoxy(13,28);
	printf("  ********************");			

	//printing arrow and move that
	gotoxy(11,b);
	printf("%c", 175);
	do
	{
		if(kbhit())
		{
			move=getch();
			Beep(10000000,100);
		}
		switch (move)
		{
			case 's':
				//remove arrow
				gotoxy(11,b);
				printf(" ");
				if(b==20)
				{
					b=8;
				}
				else
				{
					b=b+2;
				}
				move=NULL;
				break;
			case 'w':
				//remove arrow
				gotoxy(11,b);
				printf(" ");
				if(b==8)
				{
					b=20;
				}
				else
				{
					b=b-2;
				}
				move=NULL;
				break;	
			default:
				Sleep(500);
				gotoxy(11,b);
				printf(" ");
				Sleep(500);
				break;		
		}
		gotoxy(11,b);
		printf("%c", 175);
	} while(move != 13);
	switch (b)
	{
		case 8:
			system("color 47");
			break;
		case 10:
			system("color 0c");
			break;	
		case 12:
			system("color 07");
			break;
		case 14:
			system("color 8e");
			break;	
		case 16:
			system("color 02");
			break;	
		case 18:
			system("color fc");
			break;
		case 20:
			system("color f2");
			break;				
	}
	system("cls");
	menu(1);
}
//*************************************************
void pause(void)
{
	int b=24;
	int i,j;
	char move;
	gotoxy(42,24);
	printf("Resume Game");
	gotoxy(42,26);
	printf("Restart");
	gotoxy(42,28);
	printf("Exit");
	//printing arrow and move that
	gotoxy(39,b);
	printf("%c", 175);
	do
	{
		if(kbhit())
		{
			move=getch();
			Beep(10000000,100);
		}
		switch (move)
		{
			case 's':
				//remove arrow
				gotoxy(39,b);
				printf(" ");
				if(b==28)
				{
					b=24;
				}
				else
				{
					b=b+2;
				}
				move=NULL;
				break;
			case 'w':
				//remove arrow
				gotoxy(39,b);
				printf(" ");
				if(b==24)
				{
					b=28;
				}
				else
				{
					b=b-2;
				}
				move=NULL;
				break;	
			default:
				Sleep(500);
				gotoxy(39,b);
				printf(" ");
				Sleep(500);
				break;		
		}
		gotoxy(39,b);
		printf("%c", 175);
	} while(move != 13);
	switch (b)
	{
		case 24:
			for(j=24;j<=30;j=j+2)
			{
				for(i=40;i<=60;i++)
				{
					gotoxy(i,j);
					printf(" ");
				}
			}
			gotoxy(39,24);
			printf(" ");
			stop=false;
			break;
		case 26:
			system("cls");
			for(int j=4;j<35;j++)
			{
				for(int i=3;i<34;i++)
				{
					screen[j][i]={0};
				}
			}
			start_game();
//			save_record();
			exit(0);
		case 28:
			system("cls");
			for(int j=4;j<35;j++)
			{
				for(int i=3;i<34;i++)
				{
					screen[j][i]={0};
				}
			}
			menu(1);
			exit(0);	
			break;	
	}
}
//*************************************************
void select_shape(int shape)
{
	int x=16;
	int y=5;
	
	//choicing a random shape
	switch (shape)
	{
		case 1:
			move_zed(x,y);
			break;
		case 2:
			move_el(x,y);
			break;
		case 3:
			move_line(x,y);
			break;
		case 4:
			move_plus(x,y);
			break;
		case 5:	
			move_square(x,y);
			break;
	}
}
//*******************************************
void next_shape(int shape)
{
	int x,y;
	x=46;
	y=8;
	//clear all shape in frame of next shape
	zed(x,y,1,1);
	el(x,y,1,1);
	line(x,y,1,1);
	plus(x,y,1,1);
	square(x,y,1,1);
	//frame_next_shape();
	switch (shape)
	{
		case 1:
			zed(x,y,0,1);
			break;
		case 2:
			el(x,y,0,1);
			break;
		case 3:
			line(x,y,0,1);
			break;
		case 4:
			plus(x,y,0,1);
			break;
		case 5:	
			square(x,y,0,1);
			break;
	}
}
//*******************************************
int check_game_over(void)
{
	int i;
	int s=300;//time for sleep beetwen each word of game over
	for(i=5;i<34;i++)
	{
		//ending game and printing game over
		if(screen[5][i] != 0 || screen[6][16]!=0)
		{
			system("cls");
            gotoxy(11,5);
			printf("	      ___           ___           ___           ___     ");
			gotoxy(11,6);
			printf("	     /\\  \\         /\\  \\         /\\__\\         /\\  \\    ");
			gotoxy(11,7);
			printf("	    /::\\  \\       /::\\  \\       /::|  |       /::\\  \\   ");
			gotoxy(11,8);
			printf("	   /:/\\:\\  \\     /:/\\:\\  \\     /:|:|  |      /:/\\:\\  \\  ");
			gotoxy(11,9);
			printf("	  /:/  \\:\\  \\   /::\\~\\:\\  \\   /:/|:|__|__   /::\\~\\:\\  \\ ");
			gotoxy(11,10);
			printf("	 /:/__/_\\:\\__\\ /:/\\:\\ \\:\\__\\ /:/ |::::\\__\\ /:/\\:\\ \\:\\__\\");
			gotoxy(11,11);
			printf("	 \\:\\  /\\ \\/__/ \\/__\\:\\/:/  / \\/__/~~/:/  / \\:\\~\\:\\ \\/__/");
			gotoxy(11,12);
			printf("	  \\:\\ \\:\\__\\        \\::/  /        /:/  /   \\:\\ \\:\\__\\  ");
			gotoxy(11,13);
			printf("	   \\:\\/:/  /        /:/  /        /:/  /     \\:\\ \\/__/  ");
			gotoxy(11,14);
			printf("	    \\::/  /        /:/  /        /:/  /       \\:\\__\\    ");
			gotoxy(11,15);
			printf("	     \\/__/         \\/__/         \\/__/         \\/__/    ");
			gotoxy(11,16);
			printf("	      ___           ___           ___           ___     ");
			gotoxy(11,17);
			printf("	     /\\  \\         /\\__\\         /\\  \\         /\\  \\    ");
			gotoxy(11,18);
			printf("	    /::\\  \\       /:/  /        /::\\  \\       /::\\  \\   ");
			gotoxy(11,19);
			printf("	   /:/\\:\\  \\     /:/  /        /:/\\:\\  \\     /:/\\:\\  \\  ");
			gotoxy(11,20);
			printf("	  /:/  \\:\\  \\   /:/__/  ___   /::\\~\\:\\  \\   /::\\~\\:\\  \\ ");
			gotoxy(11,21);
			printf("	 /:/__/ \\:\\__\\  |:|  | /\\__\\ /:/\\:\\ \\:\\__\\ /:/\\:\\ \\:\\__\\");
			gotoxy(11,22);
			printf("	 \\:\\  \\ /:/  /  |:|  |/:/  / \\:\\~\\:\\ \\/__/ \\/_|::\\/:/  /");
			gotoxy(11,23);
			printf("	  \\:\\  /:/  /   |:|__/:/  /   \\:\\ \\:\\__\\      |:|::/  / ");
			gotoxy(11,24);
			printf("	   \\:\\/:/  /     \\::::/__/     \\:\\ \\/__/      |:|\\/__/  ");
			gotoxy(11,25);
			printf("	    \\::/  /       ~~~~          \\:\\__\\        |:|  |    ");
			gotoxy(11,26);
			printf("	     \\/__/                       \\/__/         \\|__|    ");           
			Sleep(2000);
			return 1;
			break;
		}
		
	}
}
//*******************************************
void check_ful_line(void)
{
	int z=1;//number of ful line in one check
	int n,m;
	int number_ful=0;
	int i,j;
	for(j=33;j>=6;j--)
	{
		for(i=4;i<=33;i++)
		{
			if(screen[j][i]!=0)
			{
				number_ful++;
			}
		}
		if(number_ful==30)
		{
			for(n=j;n>=6;n--)
			{
				for(m=4;m<=33;m++)
				{
					screen[n][m]=screen[n-1][m];
				}
			}
			score=score+10*z;
			z++;
			j++;
		}
		number_ful=0;
	}
}
//***************************************
void print_score(void)
{
	int *p;
	p=&score;
	gotoxy(45,20);
	printf("%3d", *p);
}
//**************************************
void frame(void)
{
	char ch4=220;//litile square fo top of frame
	char ch5=205;//two line for top of frame
	int i,j;
	//draw frame
	for(j=3,i=4;j<35,i<35;i++,j++)
	{
		screen[4][j]=ch1;
		screen[34][j]=ch1;
		screen[i][3]=ch1;
		screen[i][34]=ch1;
	}
	//draw top of frame and tetris
	for(j=13;j<26;j++)
	{
		screen[2][j]=ch5;
	}
	screen[2][12]=ch4;
	screen[2][26]=ch4;
	screen[3][10]=ch4;
	screen[3][11]=ch1;
	screen[3][12]=ch1;
	screen[3][14]='T';
	screen[3][15]='.';
	screen[3][16]='E';
	screen[3][17]='.';
	screen[3][18]='T';
	screen[3][19]='.';
	screen[3][20]='R';
	screen[3][21]='.';
	screen[3][22]='I';
	screen[3][23]='.';
	screen[3][24]='S';
	screen[3][26]=ch1;
	screen[3][27]=ch1;
	screen[3][28]=ch4;
	//draw frame for next shape section
	for(j=5;j<14;j++)
	{
		screen[j][38]=186;
		screen[j][55]=186;	
	}
	for(i=39;i<55;i++)
	{
		screen[4][i]=205;
		screen[14][i]=205;
	}
	screen[4][38]=201;
	screen[4][55]=187;
	screen[14][38]=200;
	screen[14][55]=188;
	//draw netx shape
	screen[5][42]='N';
	screen[5][43]='E';
	screen[5][44]='X';
	screen[5][45]='T';
	screen[5][46]=' ';
	screen[5][47]='S';
	screen[5][48]='H';
	screen[5][49]='A';
	screen[5][50]='P';
	screen[5][51]='E';
	//draw frame for next score section
	for(j=17;j<21;j++)
	{
		screen[j][38]=186;
		screen[j][55]=186;	
	}
	for(i=39;i<55;i++)
	{
		screen[17][i]=205;
		screen[21][i]=205;
	}
	screen[17][38]=201;
	screen[17][55]=187;
	screen[21][38]=200;
	screen[21][55]=188;
	//draw score word
	screen[18][44]='S';
	screen[18][45]='C';
	screen[18][46]='O';
	screen[18][47]='R';
	screen[18][48]='E';
	//print frame
	for(j=0;j<35;j++)
	{
		gotoxy(0,0+j);
		for(i=0;i<56;i++)
		{
			//Sleep(150);
			printf("%c", screen[j][i]);
		}	
	}
	print_score();
}
//**************************************
void save_plus(int x,int y,int mood)
{
	switch (mood)
	{
		case 1:
			screen[y][x]=ch2;
			screen[y][x+1]=ch2;
			screen[y+1][x]=ch2;
			screen[y+1][x+1]=ch2;
			screen[y+1][x+2]=ch2;
			screen[y+1][x+3]=ch2;
			screen[y+2][x]=ch2;
			screen[y+2][x+1]=ch2;
			break;	
		case 2:
			screen[y][x]=ch2;
			screen[y][x+1]=ch2;
			screen[y][x+2]=ch2;
			screen[y][x+3]=ch2;
			screen[y][x+4]=ch2;
			screen[y][x+5]=ch2;
			screen[y+1][x+2]=ch2;
			screen[y+1][x+3]=ch2;
			break;
		case 3:
			screen[y][x+2]=ch2;
			screen[y][x+3]=ch2;
			screen[y+1][x]=ch2;
			screen[y+1][x+1]=ch2;
			screen[y+1][x+2]=ch2;
			screen[y+1][x+3]=ch2;
			screen[y+2][x+2]=ch2;
			screen[y+2][x+3]=ch2;
			break;
		case 4:
			screen[y][x+2]=ch2;
			screen[y][x+3]=ch2;
			screen[y+1][x]=ch2;
			screen[y+1][x+1]=ch2;
			screen[y+1][x+2]=ch2;
			screen[y+1][x+3]=ch2;
			screen[y+1][x+4]=ch2;
			screen[y+1][x+5]=ch2;
			break;	
	}	
}
//*****************************************
void save_el(int x,int y,int mood)
{
	switch (mood)
	{
		case 1:
			screen[y][x]=178;
			screen[y][x+1]=178;
			screen[y+1][x]=178;
			screen[y+1][x+1]=178;
			screen[y+2][x]=178;
			screen[y+2][x+1]=178;
			screen[y+2][x+2]=178;
			screen[y+2][x+3]=178;
			break;	
		case 2:
			screen[y][x]=178;
			screen[y][x+1]=178;
			screen[y][x+2]=178;
			screen[y][x+3]=178;
			screen[y][x+4]=178;
			screen[y][x+5]=178;
			screen[y+1][x]=178;
			screen[y+1][x+1]=178;
			break;
		case 3:
			screen[y][x]=178;
			screen[y][x+1]=178;
			screen[y][x+2]=178;
			screen[y][x+3]=178;
			screen[y+1][x+2]=178;
			screen[y+1][x+3]=178;
			screen[y+2][x+2]=178;
			screen[y+2][x+3]=178;
			break;
		case 4:
			screen[y][x+4]=178;
			screen[y][x+5]=178;
			screen[y+1][x]=178;
			screen[y+1][x+1]=178;
			screen[y+1][x+2]=178;
			screen[y+1][x+3]=178;
			screen[y+1][x+4]=178;
			screen[y+1][x+5]=178;
			break;	
	}	
	
}
//*****************************************
void save_line(int x,int y,int mood)
{
	switch (mood)
	{
		case 1:
			screen[y][x]=178;
			screen[y][x+1]=178;
			screen[y+1][x]=178;
			screen[y+1][x+1]=178;
			screen[y+2][x]=178;
			screen[y+2][x+1]=178;
			screen[y+3][x]=178;
			screen[y+3][x+1]=178;
			break;
		case 2:
			screen[y][x]=178;
			screen[y][x+1]=178;
			screen[y][x+2]=178;
			screen[y][x+3]=178;
			screen[y][x+4]=178;
			screen[y][x+5]=178;
			screen[y][x+6]=178;
			screen[y][x+7]=178;
			break;
	}	
	
}
//*****************************************
void save_square(int x,int y,int mood)
{
	screen[y][x]=178;
	screen[y][x+1]=178;
	screen[y][x+2]=178;
	screen[y][x+3]=178;
	screen[y+1][x]=178;
	screen[y+1][x+1]=178;
	screen[y+1][x+2]=178;
	screen[y+1][x+3]=178;
}
//*****************************************
void save_zed(int x,int y,int mood)
{
	switch (mood)
	{
		case 1:
			screen[y][x]=178;
			screen[y][x+1]=178;
			screen[y+1][x]=178;
			screen[y+1][x+1]=178;
			screen[y+1][x+2]=178;
			screen[y+1][x+3]=178;
			screen[y+2][x+2]=178;
			screen[y+2][x+3]=178;
			break;
		case 2:
			screen[y][x+2]=178;
			screen[y][x+3]=178;
			screen[y][x+4]=178;
			screen[y][x+5]=178;
			screen[y+1][x]=178;
			screen[y+1][x+1]=178;
			screen[y+1][x+2]=178;
			screen[y+1][x+3]=178;
			break;
	}	
}
//******************************************
void square(int x,int y,int flag,int mood)
{
	char c;
	if(flag==0)
		c=ch2;
	if(flag==1)
		c=ch3;
	gotoxy(x,y);
	printf("%c",c);
	printf("%c",c);
	printf("%c",c);
	printf("%c",c);
	gotoxy(x,y+1);
	printf("%c",c);
	printf("%c",c);
	printf("%c",c);
	printf("%c",c);		
}
//********************************************
void line(int x,int y,int flag,int mood)
{
	char c;
	if(flag==0)
		c=ch2;
	if(flag==1)
		c=ch3;
	switch (mood)
	{
		case 1:
			gotoxy(x,y);
			printf("%c",c);
			printf("%c",c);
			gotoxy(x,y+1);
			printf("%c",c);
			printf("%c",c);
			gotoxy(x,y+2);
			printf("%c",c);
			printf("%c",c);
			gotoxy(x,y+3);
			printf("%c",c);
			printf("%c",c);
			break;
		case 2:
			gotoxy(x,y);
			printf("%c",c);
			printf("%c",c);
			printf("%c",c);
			printf("%c",c);
			printf("%c",c);
			printf("%c",c);
			printf("%c",c);
			printf("%c",c);
			break;
	}	
	
}
//********************************************
void plus(int x,int y,int flag,int mood)
{
	char c;
	if(flag==0)
		c=ch2;
	if(flag==1)
		c=ch3;
	switch (mood)
	{
		case 1:
			gotoxy(x,y);
			printf("%c",c);
			printf("%c",c);
			gotoxy(x,y+1);
			printf("%c",c);
			printf("%c",c);
			printf("%c",c);
			printf("%c",c);
			gotoxy(x,y+2);
			printf("%c",c);
			printf("%c",c);
			break;	
		case 2:
			gotoxy(x,y);
			printf("%c",c);
			printf("%c",c);
			printf("%c",c);
			printf("%c",c);
			printf("%c",c);
			printf("%c",c);
			gotoxy(x+2,y+1);
			printf("%c",c);
			printf("%c",c);
			break;
		case 3:
			gotoxy(x+2,y);
			printf("%c",c);
			printf("%c",c);
			gotoxy(x,y+1);
			printf("%c",c);
			printf("%c",c);
			printf("%c",c);
			printf("%c",c);
			gotoxy(x+2,y+2);
			printf("%c",c);
			printf("%c",c);
			break;
		case 4:
			gotoxy(x+2,y);
			printf("%c",c);
			printf("%c",c);
			gotoxy(x,y+1);
			printf("%c",c);
			printf("%c",c);
			printf("%c",c);
			printf("%c",c);
			printf("%c",c);
			printf("%c",c);
			break;	
	}	

}
//********************************************
void el(int x,int y,int flag,int mood)
{
	char c;
	if(flag==0)
		c=ch2;
	if(flag==1)
		c=ch3;
	switch (mood)
	{
		case 1:
			gotoxy(x,y);
			printf("%c",c);
			printf("%c",c);
			gotoxy(x,y+1);
			printf("%c",c);
			printf("%c",c);
			gotoxy(x,y+2);
			printf("%c",c);
			printf("%c",c);
			printf("%c",c);
			printf("%c",c);
			break;	
		case 2:
			gotoxy(x,y);
			printf("%c",c);
			printf("%c",c);
			printf("%c",c);
			printf("%c",c);
			printf("%c",c);
			printf("%c",c);
			gotoxy(x,y+1);
			printf("%c",c);
			printf("%c",c);
			break;
		case 3:
			gotoxy(x,y);
			printf("%c",c);
			printf("%c",c);
			printf("%c",c);
			printf("%c",c);
			gotoxy(x+2,y+1);
			printf("%c",c);
			printf("%c",c);
			gotoxy(x+2,y+2);
			printf("%c",c);
			printf("%c",c);
			break;
		case 4:
			gotoxy(x+4,y);
			printf("%c",c);
			printf("%c",c);
			gotoxy(x,y+1);
			printf("%c",c);
			printf("%c",c);
			printf("%c",c);
			printf("%c",c);
			printf("%c",c);
			printf("%c",c);
			break;	
	}	
}
//*******************************************
void zed(int x,int y,int flag,int mood)
{
	char c;
	if(flag==0)
		c=ch2;
	if(flag==1)
		c=ch3;
	switch (mood)
	{
		case 1:
			gotoxy(x,y);
			printf("%c",c);
			printf("%c",c);
			gotoxy(x,y+1);
			printf("%c",c);
			printf("%c",c);
			printf("%c",c);
			printf("%c",c);
			gotoxy(x+2,y+2);
			printf("%c",c);
			printf("%c",c);	
			break;
		case 2:
			gotoxy(x+2,y);
			printf("%c",c);
			printf("%c",c);
			printf("%c",c);
			printf("%c",c);
			gotoxy(x,y+1);
			printf("%c",c);
			printf("%c",c);
			printf("%c",c);
			printf("%c",c);
			break;
	}	
	
}
//**************************************
void move_zed(int x,int y)
{
	int contin=1;//controler of moving
	mood=1;
	char next;//next move
	zed(x,y,0,mood);
	while(contin!=0)
	{
		if(kbhit())
		{
      		next=getch();//getting next move
      	}		
		switch (next)
		{
			case 'w':
					Sleep(150);
					zed(x,y,1,mood);
					if(mood==2)
						mood=1;
					else if(screen[y][x+2]==0 && screen[y+1][x+4]==0 && screen[y+2][x+4]==0)//condition for rotate shape
						mood++;
					zed(x,y,0,mood);
					next=NULL;
					break;
			case 'd':
				Sleep(time_sleep);
				zed(x,y,1,mood);
				//conditins for moving right
				if(mood==1)
				{
					if(screen[y][x+2]==0 && screen[y+1][x+4]==0 && screen[y+2][x+4]==0)
						x=x+2;
				}
				else if(mood==2)
				{
					if(screen[y][x+6]==0 && screen[y+1][x+4]==0)
						x=x+2;
				}
				zed(x,y,0,mood);
				next=NULL;
				break;
			case 'a':
				Sleep(time_sleep);
				zed(x,y,1,mood);
				//conditins for moving left
				if(screen[y][x-1]==0 && screen[y+1][x-1]==0 && screen[y+2][x+1]==0)
					x=x-2;
				zed(x,y,0,mood);
				next=NULL;
				break;
			case 27 :
                while(stop)
                {
                    pause();
                }
				stop=true;	
                next=NULL;
				break;		
			default:	//moving down
				Sleep(time_sleep);
				zed(x,y,1,mood);
				y=y+1;
				zed(x,y,0,mood);				
		}	
		//condinitions for stop moving of shapes
		if(mood==1)
		{
			if(screen[y+2][x]!=0 || screen[y+3][x+2]!=0)
				contin=0;
		}
		else if(mood==2)
		{
			if(screen[y+2][x]!=0 || screen[y+2][x+3]!=0 || screen[y+1][x+4]!=0)
				contin=0;
		}
	}
	save_zed(x,y,mood);//save changes at last
}
//*************************************************
void move_el(int x,int y)
{
	int contin=1;//controler of moving
	mood=1;//next move
	char next;
	el(x,y,0,mood);
	while(contin!=0)
	{
		if(kbhit())
		{
      		next=getch();//getting next move
      	}		
		switch (next)
		{
			case 'w':
					Sleep(150);
					el(x,y,1,mood);
					if(mood==4)
						mood=1;
					else	//conditions for rotate shape
					{
						if(mood==1)
						{
							if(screen[y][x+2]==0 && screen[y+1][x+2]==0 && screen[y+2][x+4]==0)
								mood++;
						}
						else if(mood==2)
						{
								mood++;
						}
						else if(mood==3)
						{
							if(screen[y][x+4]==0 && screen[y+1][x+4]==0 && screen[y+2][x+4]==0)
								mood++;
						}
						else if(mood==4)
						{
								mood++;
						}
					}
					el(x,y,0,mood);
					next=NULL;
					break;
			case 'd':
				Sleep(time_sleep);
				el(x,y,1,mood);
				//conditins for moving right
				if(mood==1)
				{
					if(screen[y][x+2]==0 && screen[y+1][x+2]==0 && screen[y+2][x+4]==0)
						x=x+2;
				}
				else if(mood==2)
				{
					if(screen[y][x+6]==0 && screen[y+1][x+2]==0 )
						x=x+2;
				}
				else if(mood==3)
				{
					if(screen[y][x+4]==0 && screen[y+1][x+4]==0 && screen[y+2][x+4]==0)
						x=x+2;
				}
				else if(mood==4)
				{
					if(screen[y][x+6]==0 && screen[y+1][x+6]==0)
						x=x+2;
				}
				el(x,y,0,mood);
				next=NULL;
				break;
				
			case 'a':
				Sleep(time_sleep);
				el(x,y,1,mood);
				//conditins for moving left
				if(screen[y][x-1]==0 && screen[y+1][x-1]==0 && screen[y+2][x-1]==0)
					x=x-2;
				el(x,y,0,mood);
				next=NULL;
				break;
			case 27:
                while(stop)
                {
                    pause();
                }
				next=NULL;
				stop=true;		
				break;		
			default:	//moving down
				Sleep(time_sleep);
				el(x,y,1,mood);
				y=y+1;
				el(x,y,0,mood);					
		}		
		//condinitions for stop moving of shapes
		if(mood==1)
		{
			if(screen[y+3][x]!=0 || screen[y+3][x+2]!=0)
				contin=0;
		}
		else if(mood==2)
		{
			if(screen[y+2][x]!=0 || screen[y+1][x+2]!=0 || screen[y+1][x+4]!=0)
				contin=0;
		}
		else if(mood==3)
		{
			if(screen[y+1][x]!=0 || screen[y+3][x+2]!=0)
				contin=0;
		}
		else if(mood==4)
		{
			if(screen[y+2][x]!=0 || screen[y+2][x+2]!=0 || screen[y+2][x+4]!=0)
				contin=0;
		}
	}
	save_el(x,y,mood);//save changes at last
}
//*************************************************
void move_line(int x,int y)
{
	int contin=1;
	mood=1;
	char next;//keeping key for moving
	line(x,y,0,mood);
	while(contin!=0)
	{
		if(kbhit())
		{
      		next=getch();
      	}		
		switch (next)
		{
			case 'w':
					Sleep(150);
					line(x,y,1,mood);
					if(mood==2)
						mood=1;
					else 
					{
						if(mood==1)
						{
							if(screen[y][x+2]==0 && screen[y][x+4]==0 && screen[y][x+6]==0)
								mood++;
						}
						else if(mood==2)
						{
							if(screen[y][x+8]==0)
								mood++;
						}
					}
					line(x,y,0,mood);
					next=NULL;
					break;
			case 'd':
				Sleep(time_sleep);
				line(x,y,1,mood);
				//conditins for moving right
				if(mood==1)
				{
					if(screen[y][x+2]==0 && screen[y+1][x+2]==0 && screen[y+2][x+2]==0 && screen[y+3][x+2]==0)
						x=x+2;
				}
				else if(mood==2)
				{
					if(screen[y][x+8]==0)
						x=x+2;	
				}
				line(x,y,0,mood);
				next=NULL;
				break;
			case 'a':
				Sleep(time_sleep);
				line(x,y,1,mood);
				//condition for move left
				if(screen[y][x-1]==0 && screen[y+1][x-1]==0 && screen[y+2][x-1]==0 && screen[y+3][x-1]==0)
					x=x-2;
				line(x,y,0,mood);
				next=NULL;
				break;
			case 27 :
                while(stop)
                {
                    pause();
                }
                next=NULL;
                stop=true;	
				break;			
			default:
				Sleep(time_sleep);
				line(x,y,1,mood);
				y=y+1;
				line(x,y,0,mood);					
		}		
		//condinitions for stop moving of shapes
		if(mood==1)
		{
			if(screen[y+4][x]!=0)
				contin=0;
		}
		else if(mood==2)
		{
			if(screen[y+1][x]!=0 || screen[y+1][x+2]!=0 || screen[y+1][x+4]!=0 || screen[y+1][x+6]!=0)
				contin=0;
		}
	}
	save_line(x,y,mood);
}
//*************************************************
void move_square(int x,int y)
{
	mood=1;
	char next;
	square(x,y,0,mood);
	while(screen[y+2][x]==0  && screen[y+2][x+2]==0)
	{
		if(kbhit())
		{
      		next=getch();
      	}		
		switch (next)
		{
			case 'd':
				Sleep(time_sleep);
				square(x,y,1,mood);
				if(screen[y][x+4]==0  && screen[y+1][x+4]==0)
					x=x+2;
				square(x,y,0,mood);
				next=NULL;
				break;
			case 'a':
				Sleep(time_sleep);
				square(x,y,1,mood);
				if(screen[y][x-1]==0  && screen[y+1][x-1]==0)
					x=x-2;
				square(x,y,0,mood);
				next=NULL;
				break;
			case 27 :
                while(stop)
                {
                    pause();
                }
				stop=true;		
                next=NULL;
				break;		
			default:
				Sleep(time_sleep);
				square(x,y,1,mood);
				y=y+1;
				square(x,y,0,mood);					
		}		
	}
	save_square(x,y,mood);
}
//*************************************************
void move_plus(int x,int y)
{
	int contin=1;//controler of moving
	mood=1;//next move
	char next;
	plus(x,y,0,mood);
	while(contin!=0)
	{
		
		if(kbhit())
		{
      		next=getch();//getting next move
      	}		
		switch (next)
		{
			case 'w':
					Sleep(150);
					plus(x,y,1,mood);
					if(mood==4)
						mood=1;
					else	//condition for rotate shape
					{
						if(mood==1)
						{
							if(screen[y][x+2]==0 && screen[y+1][x+4]==0 && screen[y+2][x+2]==0)
								mood++;
						}
						else if(mood==2)
						{
						//	if(screen[y][x+6]==0 && screen[y+1][x+4]==0)
								mood++;
						}
						else if(mood==3)
						{
							if(screen[y][x+4]==0 && screen[y+1][x+4]==0 && screen[y+2][x+4]==0)
								mood++;
						}
						else if(mood==4)
						{
						//	if(screen[y][x+4]==0 && screen[y+1][x+6]==0 && screen[y+2][x+2]==0)
								mood++;
						}
					}
					plus(x,y,0,mood);
					next=NULL;
					break;
			case 'd':
				Sleep(time_sleep);
				plus(x,y,1,mood);
				//conditins for moving left
				if(mood==1)
				{
					if(screen[y][x+2]==0 && screen[y+1][x+4]==0 && screen[y+2][x+2]==0)
						x=x+2;
				}
				else if(mood==2)
				{
					if(screen[y][x+6]==0 && screen[y+1][x+4]==0)
						x=x+2;
				}
				else if(mood==3)
				{
					if(screen[y][x+4]==0 && screen[y+1][x+4]==0 && screen[y+2][x+4]==0)
						x=x+2;
				}
				else if(mood==4)
				{
					if(screen[y][x+4]==0 && screen[y+1][x+6]==0 && screen[y+2][x+2]==0)
						x=x+2;
				}
				plus(x,y,0,mood);
				next=NULL;
				break;
			case 'a':
				Sleep(time_sleep);
				plus(x,y,1,mood);
				//conditin for moving right
				if(screen[y][x-1]==0 && screen[y+1][x-1]==0 && screen[y+2][x-1]==0)
					x=x-2;		
				plus(x,y,0,mood);
				next=NULL;
				break;
			case 27 :
                while(stop)
                {
                    pause();
                }
				next=NULL;
				stop=true;		
				break;	
			default:	//moving down
				Sleep(time_sleep);
				plus(x,y,1,mood);
				y=y+1;
				plus(x,y,0,mood);				
		}			
		//condinitions for stop moving of shapes
		if(mood==1)
		{
			if(screen[y+3][x]!=0 || screen[y+2][x+2]!=0)
				contin=0;
		}
		else if(mood==2)
		{
			if(screen[y+1][x]!=0 || screen[y+2][x+2]!=0 || screen[y+1][x+4]!=0)
				contin=0;
		}
		else if(mood==3)
		{
			if(screen[y+2][x]!=0 || screen[y+3][x+2]!=0)
				contin=0;
		}
		else if(mood==4)
		{
			if(screen[y+2][x]!=0 || screen[y+2][x+2]!=0 || screen[y+2][x+4]!=0)
				contin=0;
		}
	}
	save_plus(x,y,mood);
}
//*************************************************
void save_record(void)
{
	struct record *temp = &first;
	//opening files
	easy = fopen("record/record_easy.txt" , "a+");
	normal = fopen("record/record_normal.txt" , "a+");
	hard = fopen("record/record_hard.txt" , "a+");
	legend = fopen("record/record_legend.txt" , "a+");
	//start saving 
	while(temp->next != NULL)
	{
		temp=temp->next;
		switch (temp->time_level)
		{
			case 50:
				fprintf(legend, "\n%s\t\t%d", temp->name, temp->score);
				break;
			case 150:
				fprintf(hard, "\n%s\t\t%d", temp->name, temp->score);
				break;
			case 250:
				fprintf(normal, "\n%s\t\t%d", temp->name, temp->score);
				break;
			case 350:
				fprintf(easy, "\n%s\t\t%d", temp->name, temp->score);
				break;	
		}
	}
	//closing files
	fclose(easy);
	fclose(normal);
	fclose(hard);
	fclose(legend);
}
//*************************************************
void exit(void)
{
	system("cls");
	gotoxy(20,5);
	printf(" _____   _____   _____   _____        _____  __    __  _____ ");
	gotoxy(20,6);
	printf("/  ___| /  _  \\ /  _  \\ |  _  \\      |  _  \\ \\ \\  / / | ____|");
	gotoxy(20,7);
	printf("| |     | | | | | | | | | | | |      | |_| |  \\ \\/ /  | |__  ");
	gotoxy(20,8);
	printf("| |  _  | | | | | | | | | | | |      |  _  (   \\  /   |  __| ");
	gotoxy(20,9);
	printf("| |_| | | |_| | | |_| | | |_| |      | |_| |   / /    | |___ ");
	gotoxy(20,10);
	printf("\\_____/ \\_____/ \\_____/ |_____/      |_____/  /_/     |_____|");
	Sleep(1000);
	gotoxy(0,15);
}
//*************************************************
int main(void)
{	
	system("color 47");
	menu(0);
	save_record();
	
}


