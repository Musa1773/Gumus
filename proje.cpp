#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
//A map of the game and sequences for characters' movements
int saha[33][17]={0};
int ThiefSutun[500];
int ThiefSatir[500];
int PoliceSutun[500];
int PoliceSatir[500];

//this code provides access to the desired x and y coordinates
void gotoxy(short x, short y) {
	HANDLE hConsoleOutput;
	COORD Cursor_Pos = {x-1, y-1};

	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_Pos);
}
//code of game's map
void cerceve(int x1, int y1, int x2, int y2,int tur)
{
    int i;
    for(i=x1; i<=x2;i++)
    {
        saha[i][y1] = tur;

        saha[i][y2] = tur;

    }
    for(i=y1; i<=y2;i++)
    {
        saha[x1][i] = tur;

        saha[x2][i] = tur;

    }
    for(i=3; i<5 ;i++)
    {
        saha[5][i] = tur;
        saha[6][i] = tur;

        saha[27][i] = tur;
        saha[28][i] = tur;
	 }
	 for(i=1; i<3 ;i++)
	 {
    
      	saha[17][i] = tur;
      	saha[18][i] = tur;
      }
 	for(i=13; i<19 ;i++)
	 {
    
      	saha[i][6] = tur;
      	
      }
      
       	for(i=9; i<13 ;i++)
	 {
    
      		saha[21][i] = tur;
      		saha[22][i] = tur;
      	
      }
      		saha[23][12] = tur;
      		saha[24][12] = tur;
      	
		  	saha[13][7] = tur;
      		saha[14][7] = tur;
      		
      		saha[11][11] = tur;
      		saha[12][11] = tur;
      		
     	for(i=7; i<13 ;i++)
	 {
    
      	saha[i][10] = tur;
      	
      }
      	
           	for(i=5; i<11 ;i++)
	 {
    
      	saha[i][15] = tur;
      	
      }
      
  }
void cerceve1(int x1, int y1, int x2, int y2,int tur) {
	
     
      	
            saha[32][8] = tur;
            saha[31][8] = tur;
      		
	 	
}
//this code prints the codes of the game map
void ekrani_bas()
{
    int x,y;
    for(x=0;x<34;x++)
    {


        for(y=0;y<18;y++)
        {
        gotoxy(x+1,y+1);
            if(saha[x][y]==1)
            {
                printf("%c",219);
            }

            else if(saha[x][y]==2)
            {
                printf("%c",176);
            }
            else if(saha[x][y]==3)
                printf("%c",88);

        }
    }
}
//character positions when starting the game
int x1, y1, x2;
randomAta()
{
    srand(time(NULL));
	x1=1+rand()%16;
	y1=2+rand()%16;
	x2=x1*2;

}
int x3, y2, x4;
randomAta2()
{
    srand(time(NULL));
	x3=1+rand()%16;
	y2=2+rand()%32;
	x4=x3*2;

}

int main()
{
	//this code to select the difficulty level of the game
	int q;
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("Enter the diffucltiy level (Easy=1,Hard=2) = ");
	scanf("%d", &q);
	switch (q){
		case 1:
		case 2:	
		do{
		do {
		
		randomAta();
        }
        while(((abs(x2-32)/2)+abs(y1-9))<16);
	}
    while((x2==6&&y1==4)||(x2==6&&y1==5)||(x2==6&&y1==16)||(x2==8&&y1==11)||(x2==8&&y1==16)||(x2==10&&y1==11)||(x2==10&&y1==16)||(x2==12&&y1==11)||(x2==12&&y1==12)||(x2==14&&y1==7)||(x2==14&&y1==8)||(x2==16&&y1==7)||(x2==18&&y1==7)||(x2==18&&y1==2)||(x2==18&&y1==3)||(x2==22&&y1==10)||(x2==22&&y1==11)||(x2==22&&y1==12)||(x2==22&&y1==13)||(x2==24&&y1==13)||(x2==28&&y1==4)||(x2==28&&y1==5));
    do{
    	do {
		
		randomAta2();
        }
        while(((abs(x4-x2)/2)+abs(y2-y1)) < 16);
	}
    while((x4==6&&y2==4)||(x4==6&&y2==5)||(x4==6&&y2==16)||(x4==8&&y2==11)||(x4==8&&y2==16)||(x4==10&&y2==11)||(x4==10&&y2==16)||(x4==12&&y2==11)||(x4==12&&y2==12)||(x4==14&&y2==7)||(x4==14&&y2==8)||(x4==16&&y2==7)||(x4==18&&y2==7)||(x4==18&&y2==2)||(x4==18&&y2==3)||(x4==22&&y2==10)||(x4==22&&y2==11)||(x4==22&&y2==12)||(x4==22&&y2==13)||(x4==24&&y2==13)||(x4==28&&y2==4)||(x4==28&&y2==5));
    
    cerceve(0,0,33,17,2);
    cerceve1(0,0,33,17,3);
    ekrani_bas();
    int sx=x2,sy=y1;
    int dy=0,dx=0;
    int px=x4,py=y2;
    int dy1=0,dx1=0;
    unsigned char tus;
    int a=0, b=0;
    int devam=0;
    int o;
	int yon;
	

//This code allows for the movement of characters
    do
    {
    	
        if(kbhit())
        {
            tus=getch();
            if(tus==224)
            {
                tus=getch();
                switch(tus)
                {
                    case 72:dy=-1; dx=0;
                    sx=sx+dx;
                    sy=sy+dy;
                    yon = 1-rand()%3;
                	px=px+dx;
                    py=py+yon;
                    o=72;
                        break;
                    case 80:dy=1; dx=0;
                    sx=sx+dx;
                    sy=sy+dy;
                    yon = 1-rand()%3;
                    px=px+dx;
                    py=py+yon;
                    o=80;
                        break;
                    case 77: dx=2; dy=0;
                    sx=sx+dx;
                    sy=sy+dy;
                    yon = 2-rand()%5;
                    px=px+yon;
                    py=py+dy;
                    o=77;
                        break;
                    case 75: dx=-2; dy=0;
                    sx=sx+dx;
                    sy=sy+dy;
                    yon = 2-rand()%5;
					px=px+yon;
                    py=py+dy;
                    o=75;
                        break;
                      
 
     
                }
                
            }
        }
//condition codes for characters not to pass through walls
        if(sx==28&&sy==4&&o==75){
        	sx=30; sy=4;
		}       
		if(sx==28&&sy==4&&o==80){
        	sx=28; sy=3;
		}
		if(sx==28&&sy==4&&o==77){
        	sx=26; sy=4;
		}
		if(sx==28&&sy==5&&o==75){
        	sx=30; sy=5;
		}
		if(sx==28&&sy==5&&o==77){
        	sx=26; sy=5;                         
        }
        if(sx==28&&sy==5&&o==72){
        	sx=28; sy=6;                         
        }
        if(sx==18&&sy==2&&o==77){
        	sx=16; sy=2;                         
        }
        if(sx==18&&sy==3&&o==77){
        	sx=16; sy=3;                         
        }
        if(sx==6&&sy==4&&o==77){
        	sx=4; sy=4;                         
        }
        if(sx==6&&sy==5&&o==77){
        	sx=4; sy=5;                         
        }
        if(sx==14&&sy==7&&o==77){
        	sx=12; sy=7;                         
        }
        if(sx==14&&sy==8&&o==77){
        	sx=12; sy=8;                         
        }
        if(sx==22&&sy==10&&o==77){
        	sx=20; sy=10;                         
        }
        if(sx==22&&sy==11&&o==77){
        	sx=20; sy=11;                         
        }
        if(sx==22&&sy==12&&o==77){
        	sx=20; sy=12;                         
        }
        if(sx==22&&sy==13&&o==77){
        	sx=20; sy=13;                         
        }
        if(sx==8&&sy==11&&o==77){
        	sx=6; sy=11;                         
        }
        if(sx==12&&sy==12&&o==77){
        	sx=10; sy=12;                         
        }
        if(sx==6&&sy==16&&o==77){
        	sx=4; sy=16;                         
        }
        if(sx==6&&sy==4&&o==75){
        	sx=8; sy=4;
		}
		if(sx==6&&sy==5&&o==75){
        	sx=8; sy=5;
		}
		if(sx==18&&sy==7&&o==75){
        	sx=20; sy=7;
		}
		if(sx==14&&sy==8&&o==75){
        	sx=16; sy=8;
		}
		if(sx==18&&sy==2&&o==75){
        	sx=20; sy=2;
		}
		if(sx==18&&sy==3&&o==75){
        	sx=20; sy=3;
		}
		if(sx==22&&sy==10&&o==75){
        	sx=24; sy=10;
		}
		if(sx==22&&sy==11&&o==75){
        	sx=24; sy=11;
		}
		if(sx==22&&sy==12&&o==75){
        	sx=24; sy=12;
		}
		if(sx==24&&sy==13&&o==75){
        	sx=26; sy=13;
		}
		if(sx==12&&sy==11&&o==75){
        	sx=14; sy=11;
		}
		if(sx==12&&sy==12&&o==75){
        	sx=14; sy=12;
		}
		if(sx==10&&sy==16&&o==75){
        	sx=12; sy=16;
		}
		if(sx==6&&sy==16&&o==80){
        	sx=6; sy=15;
		}
		if(sx==8&&sy==16&&o==80){
        	sx=8; sy=15;
		}
		if(sx==10&&sy==16&&o==80){
        	sx=10; sy=15;
		}
		if(sx==8&&sy==11&&o==80){
        	sx=8; sy=10;
		}
		if(sx==10&&sy==11&&o==80){
        	sx=10; sy=10;
		}
		if(sx==12&&sy==11&&o==80){
        	sx=12; sy=10;
		}
		if(sx==22&&sy==10&&o==80){
        	sx=22; sy=9;
		}
		if(sx==24&&sy==13&&o==80){
        	sx=24; sy=12;
		}
		if(sx==14&&sy==7&&o==80){
        	sx=14; sy=6;
		}
		if(sx==16&&sy==7&&o==80){
        	sx=16; sy=6;
		}
		if(sx==18&&sy==7&&o==80){
        	sx=18; sy=6;
		}
		if(sx==6&&sy==4&&o==80){
        	sx=6; sy=3;
		}
		if(sx==6&&sy==5&&o==72){
        	sx=6; sy=6;                         
        }
        if(sx==18&&sy==3&&o==72){
        	sx=18; sy=4;                         
        }
        if(sx==14&&sy==8&&o==72){
        	sx=14; sy=9;                         
        }
        if(sx==16&&sy==7&&o==72){
        	sx=16; sy=8;                         
        }
        if(sx==18&&sy==7&&o==72){
        	sx=18; sy=8;                         
        }
        if(sx==8&&sy==11&&o==72){
        	sx=8; sy=12;                         
        }
        if(sx==10&&sy==11&&o==72){
        	sx=10; sy=12;                         
        }
        if(sx==12&&sy==12&&o==72){
        	sx=12; sy=13;                         
        }
        if(sx==22&&sy==13&&o==72){
        	sx=22; sy=14;                         
        }
        if(sx==24&&sy==13&&o==72){
        	sx=24; sy=14;                         
        }
        if(sx==6&&sy==16&&o==72){
        	sx=6; sy=17;                         
        }
        if(sx==8&&sy==16&&o==72){
        	sx=8; sy=17;                         
        }
        if(sx==10&&sy==16&&o==72){
        	sx=10; sy=17;                         
        }
        if(sx==28&&sy==5&&o==72){
        	sx=28; sy=6;                         
        }
        if(sx==32&&sy==8&&o==72){
        	sx=32; sy=9;                         
        }
        if(sx==30&&sy==9&&o==75){
        	sx=32; sy=9;                         
        }
        if(sx==32&&sy==10&&o==80){
        	sx=32; sy=9;                         
        }
        if(sx>32)
            sx=32;
        if(sx<2)
            sx=2;
        if(sy>17)
            sy=17;
        if(sy<2)
            sy=2;
            
       
	   
	   
	  
            
              if(px==28&&py==4&&o==75){
        	px=30; py=4;
		}       
		if(px==28&&py==4&&o==80){
        	px=28; py=3;
		}
		if(px==28&&py==4&&o==77){
        	px=26; py=4;
		}
		if(px==28&&py==5&&o==75){
        	px=30; py=5;
		}
		if(px==28&&py==5&&o==77){
        	px=26; py=5;                         
        }
        if(px==28&&py==5&&o==72){
        	px=28; py=6;                         
        }
        if(px==18&&py==2&&o==77){
        	px=16; py=2;                         
        }
        if(px==18&&py==3&&o==77){
        	px=16; py=3;                         
        }
        if(px==6&&py==4&&o==77){
        	px=4; py=4;                         
        }
        if(px==6&&py==5&&o==77){
        	px=4; py=5;                         
        }
        if(px==14&&py==7&&o==77){
        	px=12; py=7;                         
        }
        if(px==14&&py==8&&o==77){
        	px=12; py=8;                         
        }
        if(px==22&&py==10&&o==77){
        	px=20; py=10;                         
        }
        if(px==22&&py==11&&o==77){
        	px=20; py=11;                         
        }
        if(px==22&&py==12&&o==77){
        	px=20; py=12;                         
        }
        if(px==22&&py==13&&o==77){
        	px=20; py=13;                         
        }
        if(px==8&&py==11&&o==77){
        	px=6; py=11;                         
        }
        if(px==12&&py==12&&o==77){
        	px=10; py=12;                         
        }
        if(px==6&&py==16&&o==77){
        	px=4; py=16;                         
        }
        if(px==6&&py==4&&o==75){
        	px=8; py=4;
		}
		if(px==6&&py==5&&o==75){
        	px=8; py=5;
		}
		if(px==18&&py==7&&o==75){
        	px=20; py=7;
		}
		if(px==14&&py==8&&o==75){
        	px=16; py=8;
		}
		if(px==18&&py==2&&o==75){
        	px=20; py=2;
		}
		if(px==18&&py==3&&o==75){
        	px=20; py=3;
		}
		if(px==22&&py==10&&o==75){
        	px=24; py=10;
		}
		if(px==22&&py==11&&o==75){
        	px=24; py=11;
		}
		if(px==22&&py==12&&o==75){
        	px=24; py=12;
		}
		if(px==24&&py==13&&o==75){
        	px=26; py=13;
		}
		if(px==12&&py==11&&o==75){
        	px=14; py=11;
		}
		if(px==12&&py==12&&o==75){
        	px=14; py=12;
		}
		if(px==10&&py==16&&o==75){
        	px=12; py=16;
		}
		if(px==6&&py==16&&o==80){
        	px=6; py=15;
		}
		if(px==8&&py==16&&o==80){
        	px=8; py=15;
		}
		if(px==10&&py==16&&o==80){
        	px=10; py=15;
		}
		if(px==8&&py==11&&o==80){
        	px=8; py=10;
		}
		if(px==10&&py==11&&o==80){
        	px=10; py=10;
		}
		if(px==12&&py==11&&o==80){
        	px=12; py=10;
		}
		if(px==22&&py==10&&o==80){
        	px=22; py=9;
		}
		if(px==24&&py==13&&o==80){
        	px=24; py=12;
		}
		if(px==14&&py==7&&o==80){
        	px=14; py=6;
		}
		if(px==16&&py==7&&o==80){
        	px=16; py=6;
		}
		if(px==18&&py==7&&o==80){
        	px=18; py=6;
		}
		if(px==6&&py==4&&o==80){
        	px=6; py=3;
		}
		if(px==6&&py==5&&o==72){
        	px=6; py=6;                         
        }
        if(px==18&&py==3&&o==72){
        	px=18; py=4;                         
        }
        if(px==14&&py==8&&o==72){
        	px=14; py=9;                         
        }
        if(px==16&&py==7&&o==72){
        	px=16; py=8;                         
        }
        if(px==18&&py==7&&o==72){
        	px=18; py=8;                         
        }
        if(px==8&&py==11&&o==72){
        	px=8; py=12;                         
        }
        if(px==10&&py==11&&o==72){
        	px=10; py=12;                         
        }
        if(px==12&&py==12&&o==72){
        	px=12; py=13;                         
        }
        if(px==22&&py==13&&o==72){
        	px=22; py=14;                         
        }
        if(px==24&&py==13&&o==72){
        	px=24; py=14;                         
        }
        if(px==6&&py==16&&o==72){
        	px=6; py=17;                         
        }
        if(px==8&&py==16&&o==72){
        	px=8; py=17;                         
        }
        if(px==10&&py==16&&o==72){
        	px=10; py=17;                         
        }
        if(px==28&&py==5&&o==72){
        	px=28; py=6;                         
        }
        if(px==32&&py==8&&o==72){
        	px=32; py=9;                         
        }
        if(px==30&&py==9&&o==75){
        	px=32; py=9;                         
        }
        if(px==32&&py==10&&o==80){
        	px=32; py=9;                         
        }
        if(px>32)
            px=32;
        if(px<2)
            px=2;
        if(py>17)
            py=17;
        if(py<2)
            py=2;
            

            
            
            
            
            
            
            
            
            
            
		int yon;
        ThiefSutun[0]=sx;
        ThiefSatir[0]=sy;
        
		

		
	
		
        
        PoliceSutun[0]=px;
        PoliceSatir[0]=py;
        int i;


        

        
//code of the sub-function that allows the movement of characters
        for(i=0;i<=a;i++)
        {
            gotoxy(ThiefSutun[i],ThiefSatir[i]);printf("T");

        }
        for(i=0;i<=b;i++)
        {
            gotoxy(PoliceSutun[i],PoliceSatir[i]);printf("P");

        }
        

       

        

        Sleep(50);

        


        for(i=0;i<=a;i++)
        {
            gotoxy(ThiefSutun[i],ThiefSatir[i]);printf(" ");

        }
        for(i=0;i<=b;i++)
        {
            gotoxy(PoliceSutun[i],PoliceSatir[i]);printf(" ");

        }

     if(sx==32&&sy==9){
	   printf(" ");
       printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nYou WIN");
       return 0;
   }
       if(px==32&&py==9){
	   printf(" ");
       printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nYou LOSE");
       return 0;
        }
    } while (devam==0);
			break;
			
	}
	



}
