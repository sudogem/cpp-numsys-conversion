/* Project Name: Number Systems Conversion                          */
/* Description : This program will convert decimal to binary,       */
/*               binary to decimal, octal to binary, binary to hexa */
/*               and etc.                                           */
/* Coded by: Arman Ortega aka mindhaï¿½K++                            */
/* Subject course :Computer Architecture w/ Assembly Language       */
/* Instructor : Mr. Francis Baylon                                  */

// #include<curses.h>
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>


/* Function Declarations */
void dispmenu(void);
void highlightChoice(int selectedChoice);
int getChoice(void);
void splash_screen(void);
void creator();
void displayInitMenu(void);
void initgraphix();
void destroygraphix();
void drawbox(int left,int top,int right,int bottom,int color);
void box1(int left,int top,int right,int bottom,
          int opendirection,int shadecolor,int mydelay,int tweening);


void decimal_to_binary();
void decimal_to_hexa();
void decimal_to_octal();


void binary_to_decimal();
void binary_to_hexa();
void binary_to_octal();


void hexa_to_decimal();
void hexa_to_binary();
void hexa_to_octal();


void octal_to_decimal();
void octal_to_binary();
void octal_to_hexa();
void octal_to_hexa1();
void octal_to_hex(long n);

/* Constant */
#define ARROWUP 72
#define ARROWDOWN 80
#define GOINGRIGHT 1
#define GOINGDOWN 2
#define GOINGLEFT 3
#define DELAY 20
#define TWEEN_DELAY2 5   /* box open left/right tween delay */
#define TWEEN_DELAY 3   /* smallbox open left/right tween delay*/
#define WITH_TWEEN 1
#define WITH_NO_TWEEN 0
#define DECIMAL_ERROR_MESSAGE "The inputted number is not a valid decimal."
#define DECIMAL_ERROR_MESSAGE1 "Please input a valid decimal no. (:"
#define BINARY_ERROR_MESSAGE "The inputted number is not a valid binary."
#define BINARY_ERROR_MESSAGE1 "Please input a valid binary no. (:"
#define OCTAL_ERROR_MESSAGE "The inputted number is not a valid octal."
#define OCTAL_ERROR_MESSAGE1 "Please input a valid octal no. Thanks:)"
#define HEXA_ERROR_MESSAGE "The inputted number is not valid hexa."
#define HEXA_ERROR_MESSAGE1 "Please input a valid hexa no. (:"

/* Global variables */
int starty=13;
int startx=30;

int xprint=20;
int yprint=32;

int choiceID;
int xprintout=20;
int yprintout=34;

int xgetinput=25;
int ygetinput=16;


/* -------------------------DISPLAY THE INITIAL MENU---------------------------*/
void displayInitMenu(void){
   // delay(1000);
   box1(28,8,52,10,GOINGDOWN,YELLOW,3,WITH_TWEEN);delay(DELAY+10);
   textcolor(YELLOW|BLINK);gotoxy(29,9);cprintf("< < <   M E N U   > > >");

   box1(28,12,52,12+14,GOINGDOWN,YELLOW,10,WITH_TWEEN);delay(DELAY);
   textcolor(WHITE);

   gotoxy(startx,starty);cprintf("® Decimal to Binary ¯");delay(DELAY);
   gotoxy(startx,starty+1);cprintf("® Decimal to Hexa   ¯");delay(DELAY);
   gotoxy(startx,starty+2);cprintf("® Decimal to Octal  ¯");delay(DELAY);
   gotoxy(startx,starty+3);cprintf("® Binary  to Decimal¯");delay(DELAY);
   gotoxy(startx,starty+4);cprintf("® Binary  to Hexa   ¯");delay(DELAY);
   gotoxy(startx,starty+5);cprintf("® Binary  to Octal  ¯");delay(DELAY);
   gotoxy(startx,starty+6);cprintf("® Hexa    to Decimal¯");delay(DELAY);
   gotoxy(startx,starty+7);cprintf("® Hexa    to Binary ¯");delay(DELAY);
   gotoxy(startx,starty+8);cprintf("® Hexa    to Octal  ¯");delay(DELAY);
   gotoxy(startx,starty+9);cprintf("® Octal   to Decimal¯");delay(DELAY);
   gotoxy(startx,starty+10);cprintf("® Octal   to Binary ¯");delay(DELAY);
   gotoxy(startx,starty+11);cprintf("® Octal   to Hexa   ¯");delay(DELAY);
   gotoxy(startx,starty+12);cprintf("® Quit              ¯");delay(DELAY);

   textcolor(RED);textbackground(BLACK);
   gotoxy(30,50);cprintf("Note: Use arrow keys to move the selection.");
}

/* -----------------------DISPLAY THE MAIN MENU-------------------------------*/
void dispmenu(void){

   /*box1(28,8,52,10,GOINGDOWN,YELLOW,12,WITH_NO_TWEEN);*/
   /*textcolor(YELLOW|BLINK);gotoxy(29,9);cprintf("< < <   M E N U   > > >");*/
   /*box1(28,12,52,12+14,GOINGDOWN,YELLOW,12,WITH_NO_TWEEN);*/
   textcolor(WHITE);
   gotoxy(startx,starty);cprintf("® Decimal to Binary ¯");
   gotoxy(startx,starty+1);cprintf("® Decimal to Hexa   ¯");
   gotoxy(startx,starty+2);cprintf("® Decimal to Octal  ¯");
   gotoxy(startx,starty+3);cprintf("® Binary  to Decimal¯");
   gotoxy(startx,starty+4);cprintf("® Binary  to Hexa   ¯");
   gotoxy(startx,starty+5);cprintf("® Binary  to Octal  ¯");
   gotoxy(startx,starty+6);cprintf("® Hexa    to Decimal¯");
   gotoxy(startx,starty+7);cprintf("® Hexa    to Binary ¯");
   gotoxy(startx,starty+8);cprintf("® Hexa    to Octal  ¯");
   gotoxy(startx,starty+9);cprintf("® Octal   to Decimal¯");
   gotoxy(startx,starty+10);cprintf("® Octal   to Binary ¯");
   gotoxy(startx,starty+11);cprintf("® Octal   to Hexa   ¯");
   gotoxy(startx,starty+12);cprintf("® Quit              ¯");

   textcolor(RED);
   gotoxy(30,50);cprintf("Note: Use arrow keys to move the selection.");
}

/* ---------------------HIGHLIGHT THE SELECTED CHOICE----------------------*/
void highlightChoice(int selectedChoice){
  textcolor(BLACK);
  textbackground(YELLOW);
  switch(selectedChoice){
    case 1:  gotoxy(startx,starty);cprintf("® Decimal to Binary ¯");
            break;
    case 2:  gotoxy(startx,starty+1);cprintf("® Decimal to Hexa   ¯");
            break;
    case 3:  gotoxy(startx,starty+2);cprintf("® Decimal to Octal  ¯");
            break;
    case 4:  gotoxy(startx,starty+3);cprintf("® Binary  to Decimal¯");
            break;
    case 5:  gotoxy(startx,starty+4);cprintf("® Binary  to Hexa   ¯");
            break;
    case 6:  gotoxy(startx,starty+5);cprintf("® Binary  to Octal  ¯");
            break;
    case 7:  gotoxy(startx,starty+6);cprintf("® Hexa    to Decimal¯");
            break;
    case 8:  gotoxy(startx,starty+7);cprintf("® Hexa    to Binary ¯");
            break;
    case 9:  gotoxy(startx,starty+8);cprintf("® Hexa    to Octal  ¯");
            break;
    case 10: gotoxy(startx,starty+9);cprintf("® Octal   to Decimal¯");
            break;
  case 11: gotoxy(startx,starty+10);cprintf("® Octal   to Binary ¯");
            break;
    case 12: gotoxy(startx,starty+11);cprintf("® Octal   to Hexa   ¯");
            break;
    case 13: gotoxy(startx,starty+12);cprintf("® Quit              ¯");
            break;
  }
}

/* --------------------------GET THE SELECTED CHOICE---------------------------*/
int getChoice(void){
   int ch,i;
   int choiceID;

   dispmenu();
   highlightChoice(choiceID);
   while(ch!=13){
     ch=getch();
     /*    printf("%d",ch); */
      switch(ch){
        case ARROWUP :/* arrow up */
                choiceID--;
                if (choiceID<1) {
                  choiceID=13;
                }
        break;
        case ARROWDOWN : /* arrow down */
                choiceID++;
                if (choiceID>13) {
                choiceID=1;
                }
	 break;
     }
     dispmenu();
     highlightChoice(choiceID);
  }
  return choiceID;
}


/* ---------------------------MAIN FUNCTION---------------------------------*/
void main(void){
   int choice;

   splash_screen();
   textmode(64);
   _setcursortype(_NOCURSOR);
   highvideo(); /* sets video to high */
   textbackground(BLACK);
   displayInitMenu();
   choiceID=1;
   highlightChoice(choiceID);
    for(;;){
        dispmenu();
        choice=getChoice();
        switch(choice){
          case 1:
            box1(10,35,70,45,GOINGRIGHT,YELLOW,TWEEN_DELAY2,WITH_TWEEN);
            decimal_to_binary();
            box1(10,35,70,45,GOINGLEFT,BLACK,TWEEN_DELAY2,WITH_TWEEN);
            break;
          case 2:
            box1(10,35,70,45,GOINGRIGHT,YELLOW,TWEEN_DELAY2,WITH_TWEEN);
            decimal_to_hexa();
            box1(10,35,70,45,GOINGLEFT,BLACK,TWEEN_DELAY2,WITH_TWEEN);
            break;
          case 3:
            box1(10,35,70,45,GOINGRIGHT,YELLOW,TWEEN_DELAY2,WITH_TWEEN);
            decimal_to_octal();
            box1(10,35,70,45,GOINGLEFT,BLACK,TWEEN_DELAY2,WITH_TWEEN);
            break;
          case 4:
            box1(10,35,70,45,GOINGRIGHT,YELLOW,TWEEN_DELAY2,WITH_TWEEN);
            binary_to_decimal();
            box1(10,35,70,45,GOINGLEFT,BLACK,TWEEN_DELAY2,WITH_TWEEN);
            break;
          case 5:
            box1(10,35,70,45,GOINGRIGHT,YELLOW,TWEEN_DELAY2,WITH_TWEEN);
            binary_to_hexa();
            box1(10,35,70,45,GOINGLEFT,BLACK,TWEEN_DELAY2,WITH_TWEEN);
            break;
          case 6:
            box1(10,35,70,45,GOINGRIGHT,YELLOW,TWEEN_DELAY2,WITH_TWEEN);
            binary_to_octal();
            box1(10,35,70,45,GOINGLEFT,BLACK,TWEEN_DELAY2,WITH_TWEEN);
            break;
          case 7:
            box1(10,35,70,45,GOINGRIGHT,YELLOW,TWEEN_DELAY2,WITH_TWEEN);
            hexa_to_decimal();
            box1(10,35,70,45,GOINGLEFT,BLACK,TWEEN_DELAY2,WITH_TWEEN);
            break;
          case 8:
            box1(10,35,70,45,GOINGRIGHT,YELLOW,TWEEN_DELAY2,WITH_TWEEN);
            hexa_to_binary();
            box1(10,35,70,45,GOINGLEFT,BLACK,TWEEN_DELAY2,WITH_TWEEN);
            break;
          case 9:
            box1(10,35,70,45,GOINGRIGHT,YELLOW,TWEEN_DELAY2,WITH_TWEEN);
            hexa_to_octal();
            box1(10,35,70,45,GOINGLEFT,BLACK,TWEEN_DELAY2,WITH_TWEEN);
            break;
          case 10:
            box1(10,35,70,45,GOINGRIGHT,YELLOW,TWEEN_DELAY2,WITH_TWEEN);
            octal_to_decimal();
            box1(10,35,70,45,GOINGLEFT,BLACK,TWEEN_DELAY2,WITH_TWEEN);
            break;
          case 11:
            box1(10,35,70,45,GOINGRIGHT,YELLOW,TWEEN_DELAY2,WITH_TWEEN);
            octal_to_binary();
            box1(10,35,70,45,GOINGLEFT,BLACK,TWEEN_DELAY2,WITH_TWEEN);
            break;
          case 12:
            box1(10,35,70,45,GOINGRIGHT,YELLOW,TWEEN_DELAY2,WITH_TWEEN);
            octal_to_hexa();
            box1(10,35,70,45,GOINGLEFT,BLACK,TWEEN_DELAY2,WITH_TWEEN);
            break;
          case 13:
            creator();
            exit(0);
            break;
          default:
            highlightChoice(choiceID);
          }
      }

}

/* -------------------------INITIALIZE GRAPHICS-----------------------------*/
void initgraphix(){
   int gd=DETECT,gm;
   int errcode;

  initgraph(&gd,&gm,"..\\bgi");
  errcode=graphresult();
  if (errcode!=grOk){
      printf("Graphics error : %s.\n",grapherrormsg(errcode));
      getch();
      exit(1);
  }
}
void destroygraphix(){
 closegraph();
}

void splash_screen(void){
   int maxX,maxY;
   initgraphix();
   maxX=getmaxx();
   maxY=getmaxy();


  /* shadow */
  setcolor(DARKGRAY);
  settextstyle(0,HORIZ_DIR,1);
  outtextxy(maxX/4+51,maxY/2+2,"Number Systems Conversion v1.0");
  /* outline text */
  setcolor(WHITE);
  outtextxy(maxX/4+50,maxY/2,"Number Systems Conversion v1.0");

  setcolor(DARKGRAY);
  line(maxX/4,maxY/2+12,maxX/4+700,maxY/2+12);
  line(maxX/4+40,maxY/2-50,maxX/4+40,maxY/2+40);
  //exit(1);
  delay(1000);
  destroygraphix();
}


void creator(){
  int maxX,maxY;
  getch();
}

/* ---------------------------DECIMAL TO BINARY---------------------------------*/
void decimal_to_binary(void){
  int dec,bin,n,i=0,a[100];

  box1(10,31,70,33,GOINGRIGHT,YELLOW,TWEEN_DELAY,WITH_TWEEN);
  drawbox(10,31,70,33,YELLOW);
  textcolor(WHITE);

  gotoxy(xprint,yprint);cprintf("< < < Decimal to Binary Conversion > > >");
  textcolor(WHITE);
  gotoxy(xprint+3,yprint+5);cprintf("Enter a Decimal number:");
  scanf("%d",&dec);

    do
    {
        a[i]=dec%2;
        dec=dec/2;
        i++;
    } while(dec!=0);
    gotoxy(xprint+3,yprint+7);cprintf("Binary equivalent:");
    for(n=i-1;n>=0;n--)
      cprintf("%d",a[n]);
    getch();
    box1(10,31,70,33,GOINGLEFT,BLACK,TWEEN_DELAY,WITH_TWEEN);
}

/* ---------------------------DECIMAL TO HEXA-----------------------------------*/
void decimal_to_hexa(){
 int i;
 long dec;
 long a[100];

 box1(10,31,70,33,GOINGRIGHT,YELLOW,TWEEN_DELAY,WITH_TWEEN);
 drawbox(10,31,70,33,YELLOW);
 textcolor(WHITE);

 gotoxy(xprint,yprint);cprintf("< < < Decimal to Hexa Conversion > > >");
 textcolor(WHITE);
 gotoxy(xprint+3,yprint+5);cprintf("Enter a Decimal number:");
 scanf("%ld",&dec);



 i=0;
 while(dec!=0){
   a[i]=dec%16;
   dec=dec/16;
   i++;
 }

 i--;
 gotoxy(xprint+3,yprint+7);cprintf("Hexa equivalent:");

 for(;i>=0;i--) {
    if(a[i]>=10){
        switch(a[i]){
        case 10:
           cprintf("A");
           break;
        case 11:
           cprintf("B");
           break;
        case 12:
           cprintf("C");
           break;
        case 13:
           cprintf("D");
           break;
        case 14:
           cprintf("E");
           break;
        case 15:
           cprintf("F");
           break;
        }
    }
    else {
        cprintf("%.0ld",a[i]);
    }
 }
 getch();
 box1(10,31,70,33,GOINGLEFT,BLACK,TWEEN_DELAY,WITH_TWEEN);
}

/* --------------------------DECIMAL TO OCTAL-----------------------------------*/
void decimal_to_octal(void){
  int i;
  int dec,a[10];

   box1(10,31,70,33,GOINGRIGHT,YELLOW,TWEEN_DELAY,WITH_TWEEN);
   drawbox(10,31,70,33,YELLOW);
   textcolor(WHITE);

   gotoxy(xprint,yprint);cprintf("< < < Decimal to Octal Conversion > > >");
   textcolor(WHITE);
   gotoxy(xprint+3,yprint+5);cprintf("Enter a Decimal number:");
   scanf("%d",&dec);
   if isdigit(dec) {
	   cprintf("dec.");
   }
   i=0;
   while(dec!=0)
   {
       a[i]= dec % 8;
       dec=dec/8;
       i++;
   }
   gotoxy(xprint+3,yprint+7);cprintf("Octal equivalent:");

   i--;
   for(;i>=0;i--){
     cprintf("%d",a[i]);
   }

   getch();
   box1(10,31,70,33,GOINGLEFT,BLACK,TWEEN_DELAY,WITH_TWEEN);
}

/* -----------------------BINARY TO DECIMAL-------------------------------------*/
void binary_to_decimal(void){
   char bin[100];
   int j;
   int n,a[6];
   double x,y,total,sum;

   box1(10,31,70,33,GOINGRIGHT,YELLOW,TWEEN_DELAY,WITH_TWEEN);
   drawbox(10,31,70,33,YELLOW);
   textcolor(WHITE);

   gotoxy(xprint,yprint);cprintf("< < < Binary to Decimal Conversion > > >");
   textcolor(WHITE);
   gotoxy(xprint+3,yprint+5);cprintf("Enter a Binary number:");

     scanf("%s",&bin);
     /* check if it s binary */
     for(j=strlen(bin)-1;j>-1;j--){
       if ((bin[j]=='1') || (bin[j]=='0')){
         /* printf(" binary cya YIPEEY!!! :)");*/
       }
       else {
         /*printf(" dili binary cya huh :( \n");*/
         gotoxy(xprint-2,yprint+7);
         textcolor(GREEN|BLINK);
         cprintf(BINARY_ERROR_MESSAGE);
         gotoxy(xprint-2,yprint+8);
         cprintf(BINARY_ERROR_MESSAGE1);
         getch();
         box1(10,31,70,33,GOINGLEFT,BLACK,TWEEN_DELAY,WITH_TWEEN);
         return;
       }
     }

     x=2.0;
     y=0.0;
     total=0.0;
     sum=0.0;
     for(j=strlen(bin)-1;j>-1;j--){
      sum=((bin[j]-49)+1) * pow(x,y);
      /*printf("\n%d times ",bin[j]-48);*/
      /*printf(" %.0lf raised to the %.0lf is %.0lf:",x,y,pow(x,y));*/
      total+=sum;
      y++;
     }
     gotoxy(xprint+3,yprint+7);
     cprintf("Decimal equivalent:%.0lf",total);

   getch();
   box1(10,31,70,33,GOINGLEFT,BLACK,TWEEN_DELAY,WITH_TWEEN);
}

/* -----------------------BINARY TO OCTAL---------------------------------------*/
void binary_to_octal(void){
  int i=0,a[5],t=0;
  long int bin;

  box1(10,31,70,33,GOINGRIGHT,YELLOW,TWEEN_DELAY,WITH_TWEEN);
  drawbox(10,31,70,33,YELLOW);
  textcolor(WHITE);

  gotoxy(xprint,yprint);cprintf("< < < Binary to Octal Conversion > > >");
  textcolor(WHITE);
  gotoxy(xprint+3,yprint+5);cprintf("Enter a binary number:");
  scanf("%ld",&bin);

  while(bin!=0)
  {
  a[i]=bin%1000;
  bin=bin/1000;
      if(a[i]>111) t=1;
  i++;
  }
  i--;
  if(t==1){
  gotoxy(xprint-2,yprint+7);
  textcolor(GREEN|BLINK);
  cprintf(BINARY_ERROR_MESSAGE);
  gotoxy(xprint-2,yprint+8);
  cprintf(BINARY_ERROR_MESSAGE1);
  getch();
  box1(10,31,70,33,GOINGLEFT,BLACK,TWEEN_DELAY,WITH_TWEEN);
  return;
  }
  gotoxy(xprint+3,yprint+7);cprintf("Octal equivalent:");
  if(t==0)
  for(;i>=0;i--)  {
    switch(a[i]){
      case 0:
          cprintf("0");
          break;
      case 1:
          cprintf("1");
          break;
      case 10:
          cprintf("2");
          break;
      case 11:
          cprintf("3");
          break;
      case 100:
          cprintf("4");
          break;
      case 101:
          cprintf("5");
          break;
      case 110:
          cprintf("6");
          break;
      case 111:
          cprintf("7");
          break;
      default:
          gotoxy(xprint-2,yprint+7);
          textcolor(GREEN|BLINK);
          cprintf(BINARY_ERROR_MESSAGE);
          gotoxy(xprint-2,yprint+8);
          cprintf(BINARY_ERROR_MESSAGE1);
          getch();
          box1(10,31,70,33,GOINGLEFT,BLACK,TWEEN_DELAY,WITH_TWEEN);
          return;
    }
  }
   getch();
   box1(10,31,70,33,GOINGLEFT,BLACK,TWEEN_DELAY,WITH_TWEEN);
}


/* -----------------------BINARY TO HEXA----------------------------------------*/
void binary_to_hexa(void){
  int i=0,a[5],t=0;
  long int n;


   box1(10,31,70,33,GOINGRIGHT,YELLOW,TWEEN_DELAY,WITH_TWEEN);
   drawbox(10,31,70,33,YELLOW);
   textcolor(WHITE);

   gotoxy(xprint,yprint);cprintf("< < < Binary to Hexa Conversion > > >");
   textcolor(WHITE);
   gotoxy(xprint+3,yprint+5);cprintf("Enter a binary number:");
      scanf("%ld",&n);

      while(n!=0){
        a[i]=n%10000;
         n=n/10000;
          if(a[i]>1111)
            t=1;
             i++;
      }
      i--;
      gotoxy(xprint+3,yprint+7);cprintf("Hexa equivalent:");
      if(t==0)
          for(;i>=0;i--)   {
            switch(a[i]) {
               case 0:
                  cprintf("0");
                  break;
               case 1:
                  cprintf("1");
                  break;
               case 10:
                  cprintf("2");
                  break;
               case 11:
                  cprintf("3");
                  break;
               case 100:
                  cprintf("4");
                  break;
               case 101:
                  cprintf("5");
                  break;
               case 110:
                  cprintf("6");
                  break;
               case 111:
                  cprintf("7");
                  break;
               case 1000:
                  cprintf("8");
                  break;
               case 1001:
                  cprintf("9");
                  break;
               case 1010:
                  cprintf("A");
                  break;
               case 1011:
                  cprintf("B");
                  break;
               case 1100:
                  cprintf("C");
                  break;
               case 1101:
                  cprintf("D");
                  break;
               case 1110:
                  cprintf("E");
                  break;
               case 1111:
                  printf("F");
                  break;
               default:
                  gotoxy(xprint+3,yprint+7);cprintf(BINARY_ERROR_MESSAGE);
                  gotoxy(xprint+3,yprint+8);cprintf(BINARY_ERROR_MESSAGE1);
                  break;
            }
         }
         if(t==1){
            gotoxy(xprint+3,yprint+7);cprintf(BINARY_ERROR_MESSAGE);
         }
  getch();
  box1(10,31,70,33,GOINGLEFT,BLACK,TWEEN_DELAY,WITH_TWEEN);
}

/* -----------------------HEXA TO DECIMAL---------------------------------------*/
void hexa_to_decimal(void){
  int i,a[20];
  unsigned long int h=0,m=1;
  char s[20];

   box1(10,31,70,33,GOINGRIGHT,YELLOW,TWEEN_DELAY,WITH_TWEEN);
   drawbox(10,31,70,33,YELLOW);
   textcolor(WHITE);

   gotoxy(xprint,yprint);cprintf("< < < Hexa to Decimal Conversion > > >");
   textcolor(WHITE);
   gotoxy(xprint+3,yprint+5);cprintf("Enter a hexa number:");
   scanf("%s",s);
   gotoxy(xprint+3,yprint+7);cprintf("Decimal equivalent:");
   for(i=0;s[i]!=NULL;i++)
   {
    switch(s[i])
    {
      case '0':
          a[i]=0;
          break;
      case '1':
          a[i]=1;
          break;
      case '2':
          a[i]=2;
          break;
      case '3':
          a[i]=3;
          break;
      case '4':
          a[i]=4;
          break;
      case '5':
          a[i]=5;
          break;
      case '6':
          a[i]=6;
          break;
      case '7':
          a[i]=7;
          break;
      case '8':
          a[i]=8;
          break;
      case '9':
          a[i]=9;
          break;
      case 'a':
      case 'A':
          a[i]=10;
          break;
      case 'b':
      case 'B':
          a[i]=11;
          break;
      case 'c':
      case 'C':
          a[i]=12;
          break;
      case 'd':
      case 'D':
          a[i]=13;
          break;
      case 'e':
      case 'E':
          a[i]=14;
          break;
      case 'f':
      case 'F':
          a[i]=15;
          break;
      default:
          gotoxy(xprint+3,yprint+7);cprintf(HEXA_ERROR_MESSAGE);
          gotoxy(xprint+3,yprint+8);cprintf(HEXA_ERROR_MESSAGE1);
          break;
    }
   }
   i--;
   for(;i>=0;i--){
      h=h+a[i]*m;
      m=m*16;
   }
   cprintf("%ld ",h);

  getch();
  box1(10,31,70,33,GOINGLEFT,BLACK,TWEEN_DELAY,WITH_TWEEN);
}

/* -----------------------HEXA TO BINARY----------------------------------------*/
void hexa_to_binary() {
  int i;
  char s[20];

  box1(10,31,70,33,GOINGRIGHT,YELLOW,TWEEN_DELAY,WITH_TWEEN);
  drawbox(10,31,70,33,YELLOW);
  textcolor(WHITE);

  gotoxy(xprint,yprint);cprintf("< < < Hexa to Binary Conversion > > >");
  textcolor(WHITE);
  gotoxy(xprint+3,yprint+5);cprintf("Enter a Hexa number:");
  scanf("%s",s);
  gotoxy(xprint+3,yprint+7);cprintf("Binary equivalent:");
  for(i=0;s[i]!=NULL;i++) {
    switch(s[i]) {
      case '0':
      printf("0000");
      break;
      case '1':
      printf("0001");
      break;
      case '2':
      printf("0010");
      break;
      case '3':
      printf("0011");
      break;
      case '4':
      printf("0100");
      break;
      case '5':
      printf("0101");
      break;
      case '6':
      printf("0110");
      break;
      case '7':
      printf("0111");
      break;
      case '8':
      printf("1000");
      break;
      case '9':
      printf("1001");
            break;
      case 'a':
      case 'A':
        printf("1010");
        break;
      case 'b':
      case 'B':
        printf("1011");
        break;
      case 'c':
      case 'C':
        printf("1100");
        break;
      case 'd':
      case 'D':
        printf("1101");
        break;
      case 'e':
      case 'E':
        printf("1110");
        break;
      case 'f':
      case 'F':
        printf("1111");
        break;
      default:
        gotoxy(xprint+3,yprint+7);cprintf(HEXA_ERROR_MESSAGE);
        gotoxy(xprint+3,yprint+8);cprintf(HEXA_ERROR_MESSAGE1);
        break;
      }
  }
  getch();
  box1(10,31,70,33,GOINGLEFT,BLACK,TWEEN_DELAY,WITH_TWEEN);
}

/* --------------------------HEXA TO OCTAL------------------------------------*/
void hexa_to_octal(){
  int i,a[20];
  unsigned long int h=0,m=1;
  char s[20];

   box1(10,31,70,33,GOINGRIGHT,YELLOW,TWEEN_DELAY,WITH_TWEEN);
   drawbox(10,31,70,33,YELLOW);
   textcolor(WHITE);

   gotoxy(xprint,yprint);cprintf("< < < Hexa to Octal Conversion > > >");
   textcolor(WHITE);
   gotoxy(xprint+3,yprint+5);cprintf("Enter a hexa number:");
   scanf("%s",s);
    /* Converting hexa to decimal first */
    for(i=0;s[i]!=NULL;i++)
    {
      switch(s[i])
      {
        case '0':
        a[i]=0;
        break;
        case '1':
        a[i]=1;
        break;
        case '2':
        a[i]=2;
        break;
        case '3':
        a[i]=3;
        break;
        case '4':
        a[i]=4;
        break;
        case '5':
        a[i]=5;
        break;
        case '6':
        a[i]=6;
        break;
        case '7':
        a[i]=7;
        break;
        case '8':
        a[i]=8;
        break;
        case '9':
        a[i]=9;
        break;
        case 'a':
        case 'A':
        a[i]=10;
        break;
        case 'b':
        case 'B':
        a[i]=11;
        break;
        case 'c':
        case 'C':
        a[i]=12;
        break;
        case 'd':
        case 'D':
        a[i]=13;
        break;
        case 'e':
        case 'E':
        a[i]=14;
        break;
        case 'f':
        case 'F':
        a[i]=15;
        break;
        default:
              gotoxy(xprint+3,yprint+7);cprintf(HEXA_ERROR_MESSAGE);
              gotoxy(xprint+3,yprint+8);cprintf(HEXA_ERROR_MESSAGE1);
              break;
      }
    }
    i--;
    for(;i>=0;i--)
    {
      h=h+a[i]*m;
      m=m*16;
    }
  /* then converting from decimal to octal */
  i=0;
  gotoxy(xprint+3,yprint+7);cprintf("Octal equivalent:");
  while(h!=0)
  {
    a[i]=h%8;
    h=h/8;
    i++;
  }
  i--;
  for(;i>=0;i--)
    cprintf("%d",a[i]);
  getch();
  box1(10,31,70,33,GOINGLEFT,BLACK,TWEEN_DELAY,WITH_TWEEN);
}

/* --------------------------OCTAL TO DECIMAL----------------------------------*/
void octal_to_decimal(void){
  unsigned long n,i=0,a,p=1,t=0;

   box1(10,31,70,33,GOINGRIGHT,YELLOW,TWEEN_DELAY,WITH_TWEEN);
   drawbox(10,31,70,33,YELLOW);
   textcolor(WHITE);

   gotoxy(xprint,yprint);cprintf("< < < Octal to Decimal Conversion > > >");
   textcolor(WHITE);
   gotoxy(xprint+3,yprint+5);cprintf("Enter an Octal number:");
   scanf("%ld",&n);

   i=0;
   gotoxy(xprint+3,yprint+7);cprintf("Decimal equivalent:");
   while(n!=0)
   {
    a=n%10;
    if(a>7)
     t=1;
    n=n/10;
    i=i+a*p;
    p=p*8;
   }
   if(t==0)
    cprintf("%.0ld",i);
   else if(t==1) {
     gotoxy(xprint+3,yprint+7);cprintf(OCTAL_ERROR_MESSAGE);
     gotoxy(xprint+3,yprint+8);cprintf(OCTAL_ERROR_MESSAGE1);
   }

  getch();
  box1(10,31,70,33,GOINGLEFT,BLACK,TWEEN_DELAY,WITH_TWEEN);
}


/* --------------------------OCTAL TO BINARY----------------------------------*/
void octal_to_binary(){
  char oct[20],*ptr;
  register int i;

  box1(10,31,70,33,GOINGRIGHT,YELLOW,TWEEN_DELAY,WITH_TWEEN);
  drawbox(10,31,70,33,YELLOW);
  textcolor(WHITE);

  gotoxy(xprint,yprint);cprintf("< < < Octal to Binary Conversion > > >");
  textcolor(WHITE);
  gotoxy(xprint+3,yprint+5);cprintf("Enter an Octal number:");

  ptr=oct; /* assign ptr the starting address of oct */
  scanf("%s",&oct);
  /*gets(oct);*/

  i=0;  /* check first if it is an octal no. */
  while(oct[i]!=NULL){
    if ((oct[i]-49)>6){ /* convert to an integer equivalent (decimal value of 0) */
      gotoxy(xprint-2,yprint+7);
      textcolor(GREEN|BLINK);
      cprintf(OCTAL_ERROR_MESSAGE);
      gotoxy(xprint-2,yprint+8);
      cprintf(OCTAL_ERROR_MESSAGE1);
      getch();
      box1(10,31,70,33,GOINGLEFT,BLACK,TWEEN_DELAY,WITH_TWEEN);
      return;
    }
  i++;
  }


  gotoxy(xprint+3,yprint+7);cprintf("Binary equivalent:");
  while(*ptr){
     switch(*ptr){
         case '0':
          printf("000");
          break;
         case '1':
          printf("001");
          break;
         case '2':
          printf("010");
          break;
         case '3':
          printf("011");
          break;
         case '4':
          printf("100");
          break;
         case '5':
          printf("101");
          break;
         case '6':
          printf("110");
          break;
         case '7':
          printf("111");
          break;
     }
     *ptr++;
 }

 getch();
 box1(10,31,70,33,GOINGLEFT,BLACK,TWEEN_DELAY,WITH_TWEEN);
}

/* --------------------------OCTAL TO HEXA------------------------------------*/
void octal_to_hexa(){
    unsigned long n,i=0,a,p=1,t=0;

    box1(10,31,70,33,GOINGRIGHT,YELLOW,TWEEN_DELAY,WITH_TWEEN);
    drawbox(10,31,70,33,YELLOW);
    textcolor(WHITE);
    gotoxy(xprint,yprint);printf("< < < Octal to Hexa Conversion > > >");
    textcolor(WHITE);
    gotoxy(xprint+3,yprint+5);printf("Enter an Octal number:");
    scanf("%ld",&n);
    i=0;
    while(n!=0){
       a=n%10;
       if(a>7)
       t=1;
       n=n/10;
       i=i+a*p;
       p=p*8;
    }
    if(t==0){
        gotoxy(xprint+3,yprint+7);
        cprintf("Hexadecimal equivalent:");
        octal_to_hex(i);
    }
     else if(t==1){
         gotoxy(xprint-2,yprint+7);
         textcolor(GREEN|BLINK);
         cprintf(OCTAL_ERROR_MESSAGE);
         gotoxy(xprint-2,yprint+8);
         cprintf(OCTAL_ERROR_MESSAGE1);
         getch();
         box1(10,31,70,33,GOINGLEFT,BLACK,TWEEN_DELAY,WITH_TWEEN);
         return;
     }

    getch();
    box1(10,31,70,33,GOINGLEFT,BLACK,TWEEN_DELAY,WITH_TWEEN);
}

void octal_to_hex(long n){
   long i;
  if(n>0)
  {
   i=n%16;
   n=n/16;
   octal_to_hex(n);
   if(i>=10)
   {
    switch(i)
    {
     case 10:
      cprintf("A");
      break;
     case 11:
      cprintf("B");
      break;
     case 12:
      cprintf("C");
      break;
     case 13:
      cprintf("D");
      break;
     case 14:
      cprintf("E");
      break;
     case 15:
      cprintf("F");
      break;
    }
   }
   else
    cprintf("%ld",i);
  }
}

/* ---------------------------DRAW BOX---------------------------------*/
void drawbox(int left,int top,int right,int bottom,int color){
  int ctr,ctr2;
  char topLeftChar    = 'Ú';
  char topRightChar   = '¿';
  char bottomLeftChar = 'À';
  char bottomRightChar= 'Ù';
  char horizontalChar = 'Ä';
  char verticalChar   = '³';

 textcolor(color);
 gotoxy(left,top);putch(topLeftChar);
 gotoxy(right,top);putch(topRightChar);
 gotoxy(left,bottom);putch(bottomLeftChar);
 gotoxy(right,bottom);putch(bottomRightChar);

 for(ctr=left+1;ctr < right;ctr++){
    gotoxy(ctr,top);putch(horizontalChar);
    gotoxy(ctr,bottom);putch(horizontalChar);
 }

 for(ctr=top+1;ctr<bottom;ctr++){
    gotoxy(left,ctr);putch(verticalChar);
    gotoxy(right,ctr);putch(verticalChar);
 }

}

/* -----------------DRAW BOX/SHADING/MOTION TWEENING ----------------------------*/
void box1(int left,int top,int right,int bottom,int opendirection,int shadecolor,int mydelay,int tweening){
  int i;
  int ctr,ctr2;

 _setcursortype(_NOCURSOR);
  switch(opendirection){
     case GOINGDOWN: /* open downward */
        textbackground(shadecolor);
        for(ctr=top+1;ctr < bottom;ctr++) {
          for(ctr2=left+1;ctr2<right;ctr2++){
            gotoxy(ctr2,ctr);putch(' ');
          }
        if (tweening) delay(mydelay);
        }
        drawbox(left,top,right,bottom,shadecolor);
        break;
     case GOINGRIGHT: /* open to left*/
      textbackground(shadecolor);
      for(ctr=left+1;ctr < right;ctr++){
          for(ctr2=top+1;ctr2<bottom;ctr2++){
              gotoxy(ctr,ctr2);putch(' ');
          }
        if (tweening) delay(mydelay);
      }
      drawbox(left,top,right,bottom,shadecolor);
      break;
     case GOINGLEFT : /* erase shading */
      textbackground(shadecolor);
      for(ctr=right;ctr >= left;ctr--){
        for(ctr2=top;ctr2<=bottom;ctr2++){
            gotoxy(ctr,ctr2);putch(' ');
        }
      if (tweening) delay(mydelay);
      }
      break;
  }
}