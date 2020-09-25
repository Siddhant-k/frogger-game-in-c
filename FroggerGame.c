#include "LPC17xx.H"
#include "GLCD.h"
#include "GLCD_UTILS.h"
#include <stdlib.h>
#include "uart.h"

//UART Variables 
extern volatile uint32_t UART0_Count;
extern volatile uint8_t UART0_Buffer[BUFSIZE];


int widthb = 260; // Width of the square
int lengthb = 18;
int i;
int j;
int unsigned short color;
int k;
int vx = 3;
int vy = 2;
int mask_val1 = (1<<10); // masking value here for bit 11
int n;
int on_val = 0;  // its active low, so = 0;
int radius = 2;
int lives = 4;

int xx = 130;
//int yy =114;
int yy =222;




int up = (1<<27);
int down = (1<<28);
int right = (1<<29);
int left = (1<<26);
	
void frog(xx,yy){
GLCD_SetTextColor(Green);
GLCD_PutPixel(xx + 1, yy + 1);
GLCD_PutPixel(xx + 1, yy + 2);
GLCD_PutPixel(xx + 1, yy + 3);
GLCD_PutPixel(xx + 1, yy + 4);
GLCD_PutPixel(xx + 1, yy + 5);
GLCD_PutPixel(xx + 1, yy + 6);
GLCD_PutPixel(xx + 1, yy + 10);
GLCD_PutPixel(xx + 1, yy + 11);
GLCD_PutPixel(xx + 1, yy + 16);
GLCD_PutPixel(xx + 1, yy + 16);
GLCD_PutPixel(xx + 2, yy + 1);
GLCD_PutPixel(xx + 2, yy + 6);
GLCD_PutPixel(xx + 2, yy + 7);
GLCD_PutPixel(xx + 2, yy + 8);
GLCD_PutPixel(xx + 2, yy + 9);
GLCD_PutPixel(xx + 2, yy + 10);
GLCD_PutPixel(xx + 2, yy + 11);
GLCD_PutPixel(xx + 2, yy + 12);
GLCD_PutPixel(xx + 2, yy + 13);
GLCD_PutPixel(xx + 2, yy + 14);
GLCD_PutPixel(xx + 2, yy + 15);
GLCD_PutPixel(xx + 2, yy + 16);
GLCD_PutPixel(xx + 3, yy + 1);
GLCD_PutPixel(xx + 3, yy + 6);
GLCD_PutPixel(xx + 3, yy + 7);
GLCD_PutPixel(xx + 3, yy + 8);
GLCD_PutPixel(xx + 3, yy + 9);
GLCD_PutPixel(xx + 3, yy + 10);
GLCD_PutPixel(xx + 3, yy + 11);
GLCD_PutPixel(xx + 3, yy + 12);
GLCD_PutPixel(xx + 3, yy + 13);
GLCD_PutPixel(xx + 3, yy + 14);
GLCD_PutPixel(xx + 3, yy + 15);
GLCD_PutPixel(xx + 3, yy + 16);
GLCD_PutPixel(xx + 4, yy + 5);
GLCD_PutPixel(xx + 4, yy + 6);
GLCD_PutPixel(xx + 4, yy + 7);
GLCD_PutPixel(xx + 4, yy + 8);
GLCD_PutPixel(xx + 4, yy + 9);
GLCD_PutPixel(xx + 4, yy + 10);
GLCD_PutPixel(xx + 4, yy + 11);
GLCD_PutPixel(xx + 4, yy + 12);
GLCD_PutPixel(xx + 5, yy + 5);
GLCD_PutPixel(xx + 5, yy + 6);
GLCD_PutPixel(xx + 5, yy + 7);
GLCD_PutPixel(xx + 5, yy + 8);
GLCD_PutPixel(xx + 5, yy + 9);
GLCD_PutPixel(xx + 5, yy + 10);
GLCD_PutPixel(xx + 5, yy + 11);
GLCD_PutPixel(xx + 5, yy + 12);
GLCD_PutPixel(xx + 5, yy + 13);
GLCD_PutPixel(xx + 6, yy + 5);
GLCD_PutPixel(xx + 6, yy + 6);
GLCD_PutPixel(xx + 6, yy + 7);
GLCD_PutPixel(xx + 6, yy + 8);
GLCD_PutPixel(xx + 6, yy + 9);
GLCD_PutPixel(xx + 6, yy + 10);
GLCD_PutPixel(xx + 6, yy + 11);
GLCD_PutPixel(xx + 6, yy + 12);
GLCD_PutPixel(xx + 6, yy + 13);
GLCD_PutPixel(xx + 7, yy + 5);
GLCD_PutPixel(xx + 7, yy + 6);
GLCD_PutPixel(xx + 7, yy + 7);
GLCD_PutPixel(xx + 7, yy + 8);
GLCD_PutPixel(xx + 7, yy + 9);
GLCD_PutPixel(xx + 7, yy + 10);
GLCD_PutPixel(xx + 7, yy + 11);
GLCD_PutPixel(xx + 7, yy + 12);
GLCD_PutPixel(xx + 7, yy + 13);
GLCD_PutPixel(xx + 8, yy + 3);
GLCD_PutPixel(xx + 8, yy + 4);
GLCD_PutPixel(xx + 8, yy + 5);
GLCD_PutPixel(xx + 8, yy + 6);
GLCD_PutPixel(xx + 8, yy + 7);
GLCD_PutPixel(xx + 8, yy + 8);
GLCD_PutPixel(xx + 8, yy + 9);
GLCD_PutPixel(xx + 8, yy + 10);
GLCD_PutPixel(xx + 8, yy + 11);
GLCD_PutPixel(xx + 8, yy + 12);
GLCD_PutPixel(xx + 8, yy + 13);
GLCD_PutPixel(xx + 8, yy + 14);
GLCD_PutPixel(xx + 9, yy + 3);
GLCD_PutPixel(xx + 9, yy + 4);
GLCD_PutPixel(xx + 9, yy + 5);
GLCD_PutPixel(xx + 9, yy + 6);
GLCD_PutPixel(xx + 9, yy + 7);
GLCD_PutPixel(xx + 9, yy + 8);
GLCD_PutPixel(xx + 9, yy + 9);
GLCD_PutPixel(xx + 9, yy + 10);
GLCD_PutPixel(xx + 9, yy + 11);
GLCD_PutPixel(xx + 9, yy + 12);
GLCD_PutPixel(xx + 9, yy + 13);
GLCD_PutPixel(xx + 9, yy + 14);
GLCD_PutPixel(xx + 10, yy + 5);
GLCD_PutPixel(xx + 10, yy + 6);
GLCD_PutPixel(xx + 10, yy + 7);
GLCD_PutPixel(xx + 10, yy + 8);
GLCD_PutPixel(xx + 10, yy + 9);
GLCD_PutPixel(xx + 10, yy + 10);
GLCD_PutPixel(xx + 10, yy + 11);
GLCD_PutPixel(xx + 10, yy + 12);
GLCD_PutPixel(xx + 10, yy + 13);
GLCD_PutPixel(xx + 11, yy + 5);
GLCD_PutPixel(xx + 11, yy + 6);
GLCD_PutPixel(xx + 11, yy + 7);
GLCD_PutPixel(xx + 11, yy + 8);
GLCD_PutPixel(xx + 11, yy + 9);
GLCD_PutPixel(xx + 11, yy + 10);
GLCD_PutPixel(xx + 11, yy + 11);
GLCD_PutPixel(xx + 11, yy + 12);
GLCD_PutPixel(xx + 11, yy + 13);
GLCD_PutPixel(xx + 12, yy + 5);
GLCD_PutPixel(xx + 12, yy + 6);
GLCD_PutPixel(xx + 12, yy + 7);
GLCD_PutPixel(xx + 12, yy + 8);
GLCD_PutPixel(xx + 12, yy + 9);
GLCD_PutPixel(xx + 12, yy + 10);
GLCD_PutPixel(xx + 12, yy + 11);
GLCD_PutPixel(xx + 12, yy + 12);
GLCD_PutPixel(xx + 12, yy + 13);
GLCD_PutPixel(xx + 13, yy + 5);
GLCD_PutPixel(xx + 13, yy + 6);
GLCD_PutPixel(xx + 13, yy + 7);
GLCD_PutPixel(xx + 13, yy + 8);
GLCD_PutPixel(xx + 13, yy + 9);
GLCD_PutPixel(xx + 13, yy + 10);
GLCD_PutPixel(xx + 13, yy + 11);
GLCD_PutPixel(xx + 13, yy + 12);
GLCD_PutPixel(xx + 14, yy + 1);
GLCD_PutPixel(xx + 14, yy + 6);
GLCD_PutPixel(xx + 14, yy + 7);
GLCD_PutPixel(xx + 14, yy + 8);
GLCD_PutPixel(xx + 14, yy + 9);
GLCD_PutPixel(xx + 14, yy + 10);
GLCD_PutPixel(xx + 14, yy + 11);
GLCD_PutPixel(xx + 14, yy + 12);
GLCD_PutPixel(xx + 14, yy + 13);
GLCD_PutPixel(xx + 14, yy + 14);
GLCD_PutPixel(xx + 14, yy + 15);
GLCD_PutPixel(xx + 14, yy + 16);
GLCD_PutPixel(xx + 15, yy + 1);
GLCD_PutPixel(xx + 15, yy + 6);
GLCD_PutPixel(xx + 15, yy + 7);
GLCD_PutPixel(xx + 15, yy + 8);
GLCD_PutPixel(xx + 15, yy + 9);
GLCD_PutPixel(xx + 15, yy + 10);
GLCD_PutPixel(xx + 15, yy + 11);
GLCD_PutPixel(xx + 15, yy + 12);
GLCD_PutPixel(xx + 15, yy + 13);
GLCD_PutPixel(xx + 15, yy + 14);
GLCD_PutPixel(xx + 15, yy + 15);
GLCD_PutPixel(xx + 15, yy + 16);
GLCD_PutPixel(xx + 16, yy + 1);
GLCD_PutPixel(xx + 16, yy + 2);
GLCD_PutPixel(xx + 16, yy + 3);
GLCD_PutPixel(xx + 16, yy + 4);
GLCD_PutPixel(xx + 16, yy + 5);
GLCD_PutPixel(xx + 16, yy + 6);
GLCD_PutPixel(xx + 16, yy + 10);
GLCD_PutPixel(xx + 16, yy + 11);
GLCD_PutPixel(xx + 16, yy + 16);
GLCD_PutPixel(xx + 17, yy + 10);
GLCD_PutPixel(xx + 17, yy + 11);
GLCD_PutPixel(xx + 17, yy + 16);
GLCD_SetTextColor(Red);
GLCD_PutPixel(xx + 6, yy + 2);
GLCD_PutPixel(xx + 6, yy + 3);
GLCD_PutPixel(xx + 6, yy + 4);
GLCD_PutPixel(xx + 7, yy + 2);
GLCD_PutPixel(xx + 7, yy + 3);
GLCD_PutPixel(xx + 7, yy + 4);
GLCD_PutPixel(xx + 10, yy + 2);
GLCD_PutPixel(xx + 10, yy + 3);
GLCD_PutPixel(xx + 10, yy + 4);
GLCD_PutPixel(xx + 11, yy + 2);
GLCD_PutPixel(xx + 11, yy + 3);
GLCD_PutPixel(xx + 11, yy + 4);
GLCD_PutPixel(xx + 12, yy + 2);
GLCD_PutPixel(xx + 12, yy + 3);
GLCD_PutPixel(xx + 12, yy + 4);
GLCD_PutPixel(xx + 5, yy + 2);
GLCD_PutPixel(xx + 5, yy + 3);
GLCD_PutPixel(xx + 5, yy + 4);
}
void drawSquare(cx, cy, width, length, color) {
	GLCD_SetTextColor(color);
for(i = cx - width/2; i<cx+width/2; i++){
			for(j=cy-length/2; j<cy+length/2; j++){
				GLCD_PutPixel(i,j);
			}
		}
	}
void display_lives(lives){
if(lives==2){
	frog(300,214);
}
if(lives==3){
	frog(300,214);
	frog(300,184);
}
if(lives==4){
	frog(300,214);
		frog(300,184);
	frog(300,154);
}

}
void basic(){
		drawSquare(130,231,260, 18,Navy);
		drawSquare(130,177,260,90,Black);
		drawSquare(130,123,260,18,Navy);
		drawSquare(130,69,260,90,Cyan);
		drawSquare(290,120,60,240,DarkGrey);
		drawSquare(41,12,35,24,Yellow);
		drawSquare(100,12,35,24,Yellow);
		drawSquare(159,12,35,24,Yellow);
		drawSquare(218,12,35,24,Yellow);
	
	
}

void collision(){
	lives = lives-1;

	xx=130;
	yy=222;
//		yy=114;
	basic();
	frog(xx,yy);
}
	
void car1(int* rx){
	int q;
for(q=0; q<3; q++){
	drawSquare(*(rx+q)-10,213,6,18,Black);
	if (*(rx+q)<260-9) *(rx+q)=*(rx+q)+3;
	if (*(rx+q)>=260-9){
		*(rx+q)=1;

	}
	
			drawSquare(*(rx+q),213,18,18,Red);
	
	if(*(rx+q)==1)		drawSquare(260-10,213,18,18,Black);
			for (k=0; k<200; k++);
	if(yy ==  204){
			if((xx-*(rx+q))*(xx-*(rx+q))-(yy-213)*(yy-213)<17){
collision();
			}
}
}
}
void truck2(int* rx){
	int q;
for(q=0; q<3; q++){
	drawSquare(*(rx+q)+22,195,4,18,Black);
	if (*(rx+q)>0) *(rx+q)=*(rx+q)-2;
	if (*(rx+q)<=0){
		*(rx+q)=260;

	}
	
			drawSquare(*(rx+q),195,40,18,Yellow);
	if(*(rx+q)==260)
		drawSquare(0+12,195,40,18,Black);
	if(*(rx+q)<=260 && *(rx+q)>=233)
		drawSquare(274,195,28,18,DarkGrey);

			for(k=0; k<20000; k++);
    if(yy ==  186){
        if((xx-(*(rx+q)-9))*(xx-(*(rx+q)-9))-(yy-195)*(yy-195)<841){
         collision();
        }
    }
}
}
void car3(int* rx){
	int q;
for(q=0; q<3; q++){
	drawSquare(*(rx+q)-10,177,8,18,Black);
	if (*(rx+q)<260-9) *(rx+q)=*(rx+q)+4;
	if (*(rx+q)>=260-9){
		*(rx+q)=1;

	}
	
			drawSquare(*(rx+q),177,18,18,Red);
	if(*(rx+q)==1)		drawSquare(260-10,177,18,18,Black);
			for (k=0; k<20000; k++);
    if(yy ==  168){
        if((xx-*(rx+q))*(xx-*(rx+q))-(yy-177)*(yy-177)<17){
            collision();
        }
    }
}

}
void truck4(int* rx){
	int q;
for(q=0; q<3; q++){
	drawSquare(*(rx+q)+22,159,6,18,Black);
	if (*(rx+q)>0) *(rx+q)=*(rx+q)-3;
	if (*(rx+q)<=0){
		*(rx+q)=260;

	}
	
			drawSquare(*(rx+q),159,40,18,Yellow);
	if(*(rx+q)==260)
		drawSquare(0+12,159,40,18,Black);
	if(*(rx+q)<=260 && *(rx+q)>=233)
		drawSquare(274,159,28,18,DarkGrey);

			for(k=0; k<20000; k++);
    if(yy ==  150){
        if((xx-(*(rx+q)-9))*(xx-(*(rx+q)-9))-(yy-159)*(yy-159)<841){
          collision();
        }
    }

}

}
void car5(int* rx){
	int q;
for(q=0; q<3; q++){
	drawSquare(*(rx+q)-10,141,4,18,Black);
	if (*(rx+q)<260-9) *(rx+q)=*(rx+q)+2;
	if (*(rx+q)>=260-9){
		*(rx+q)=1;

	}
	
			drawSquare(*(rx+q),141,18,18,Red);
	if(*(rx+q)==1)		drawSquare(260-10,141,18,18,Black);
			for (k=0; k<20000; k++);
    if(yy ==  132){
        if((xx-*(rx+q))*(xx-*(rx+q))-(yy-141)*(yy-141)<17){
            collision();
        }
    }
}

}
void pad6(int* rx){
	int q;
for(q=0; q<3; q++){
	drawSquare(*(rx+q)-10,105,2,18,Cyan);
	if (*(rx+q)<260-9) *(rx+q)=*(rx+q)+1;
	if (*(rx+q)>=260-9){
		*(rx+q)=1;

	}
	
			drawSquare(*(rx+q),105,18,18,DarkGreen);
	if(*(rx+q)==1)		drawSquare(260-10,105,18,18,Cyan);
			for (k=0; k<200; k++);
  

	}
   if(yy ==  96){
        if(((xx-*(rx+0))*(xx-*(rx+0))-(yy-105)*(yy-105)<= 17) || ((xx-*(rx+1))*(xx-*(rx+1))-(yy-105)*(yy-105)<= 17) || ((xx-*(rx+2))*(xx-*(rx+2))-(yy-105)*(yy-105)<= 17)){
					xx++;
					frog(xx,yy);
				}
				else{
					collision();
				}
		}
}



void log7(int* rx){
	int q;
for(q=0; q<3; q++){
	drawSquare(*(rx+q)+22,87,8,18,Cyan);
	if (*(rx+q)>0) *(rx+q)=*(rx+q)-4;
	if (*(rx+q)<=0){
		*(rx+q)=260;
        
        

	}
	
			drawSquare(*(rx+q),87,40,18,Brown);
	if(*(rx+q)==260)
		drawSquare(0+12,87,40,18,Cyan);
	if(*(rx+q)<=260 && *(rx+q)>=233)
		drawSquare(274,87,28,18,DarkGrey);
	
			for(k=0; k<20000; k++);
		

    

}
    if(yy ==  78){
        if(((xx-*(rx+0))*(xx-*(rx+0))-(yy-87)*(yy-87)<= 841) || ((xx-*(rx+1))*(xx-*(rx+1))-(yy-87)*(yy-87)<= 841) || ((xx-*(rx+2))*(xx-*(rx+2))-(yy-87)*(yy-87)<= 841)){
            xx--;
            frog(xx,yy);
        }
        else{
            collision();
        }
    }
}
void pad8(int* rx){
	int q;
for(q=0; q<3; q++){
	drawSquare(*(rx+q)-10,69,4,18,Cyan);
	if (*(rx+q)<260-9) *(rx+q)=*(rx+q)+2;
	if (*(rx+q)>=260-9){
		*(rx+q)=1;

	}
	
			drawSquare(*(rx+q),69,18,18,DarkGreen);
	if(*(rx+q)==1)		drawSquare(260-10,69,18,18,Cyan);
			for (k=0; k<200; k++);
    
   
}

   if(yy ==  60){
        if(((xx-*(rx+0))*(xx-*(rx+0))-(yy-69)*(yy-69)<= 17) || ((xx-*(rx+1))*(xx-*(rx+1))-(yy-69)*(yy-69)<= 17) || ((xx-*(rx+2))*(xx-*(rx+2))-(yy-69)*(yy-69)<= 17)){
					xx++;
					frog(xx,yy);
				}
				else{
					collision();
				}
		}

}
void log9(int* rx){
	int q;
for(q=0; q<3; q++){
	drawSquare(*(rx+q)+22,51,8,18,Cyan);
	if (*(rx+q)>0) *(rx+q)=*(rx+q)-4;
	if (*(rx+q)<=0){
		*(rx+q)=260;

	}
	
			drawSquare(*(rx+q),51,40,18,Brown);
	if(*(rx+q)==260)
		drawSquare(0+12,51,40,18,Cyan);
	if(*(rx+q)<=260 && *(rx+q)>=233)
		drawSquare(274,51,28,18,DarkGrey);
	
			for(k=0; k<20000; k++);
    
   
    

}
    if(yy ==  42){
        if(((xx-*(rx+0))*(xx-*(rx+0))-(yy-51)*(yy-51)<= 841) || ((xx-*(rx+1))*(xx-*(rx+1))-(yy-51)*(yy-51)<= 841) || ((xx-*(rx+2))*(xx-*(rx+2))-(yy-51)*(yy-51)<= 841)){
            xx--;
            frog(xx,yy);
        }
        else{
            collision();
        }
    }
}
void pad10(int* rx){
int q;
for(q=0; q<3; q++){
	drawSquare(*(rx+q)-10,33,6,18,Cyan);
	if (*(rx+q)<260-9) *(rx+q)=*(rx+q)+3;
	if (*(rx+q)>=260-9){
		*(rx+q)=1;

	}
	
			drawSquare(*(rx+q),33,18,18,DarkGreen);
	if(*(rx+q)==1)		drawSquare(260-10,33,18,18,Cyan);
			for (k=0; k<200; k++);
    
    
}

   if(yy ==  24){
        if(((xx-*(rx+0))*(xx-*(rx+0))-(yy-33)*(yy-33)<= 17) || ((xx-*(rx+1))*(xx-*(rx+1))-(yy-33)*(yy-33)<= 17) || ((xx-*(rx+2))*(xx-*(rx+2))-(yy-33)*(yy-33)<= 17)){
					xx++;
					frog(xx,yy);
				}
				else{
					collision();
				}
		}

}





void frog_up(){
	yy = yy - 18;
	basic();
	frog(xx,yy);
	
	}

void frog_down(){
  
	yy = yy + 18;

	basic();
	frog(xx,yy);
	
	}
	
void frog_left(){
  
	xx = xx - 18;

	basic();
	frog(xx,yy);
	}
	
void frog_right(){
  
	xx = xx + 18;

	basic();
	frog(xx,yy);
	}









int main() {
		
		int home=0;
		char char_from_pc = 'w';
		int arrayr1[3]={20,100,200};
		int arrayr2[3]={230,150,50};
		int arrayr3[3]={25,100,200};
		int arrayr4[3]={100,175,240};
		int arrayr5[3]={80,155,230};
		int arrayr6[3]={20,75,150};
		int arrayr7[3]={20,100,180};
		int arrayr8[3]={240,55,180};
		int arrayr9[3]={60,160,260};
		int arrayr10[3]={100,145,240};
		UARTInit(0, 57600);

    GLCD_Init();               //Initializes the LCD display
    GLCD_Clear(Black);         //Clear display and set background color to black
    basic();
		drawSquare(12,12,24,24,Navy);
		drawSquare(71,12,24,24,Navy);
		drawSquare(130,12,24,24,Navy);
		drawSquare(189,12,24,24,Navy);
		drawSquare(248,12,24,24,Navy);

	
    frog(xx,yy);



		
	while (1){
		
		display_lives(lives);
		car1(arrayr1);
		truck2(arrayr2);
		car3(arrayr3);
		truck4(arrayr4);
		car5(arrayr5);
		pad6(arrayr6);
		log7(arrayr7);
		pad8(arrayr8);
		log9(arrayr9);
		pad10(arrayr10);
	
		
		
  if (yy==6 && (xx>=0 && xx<=24)){ 
    home = home + 1;
	//	frog(6,yy);
		//ax=1;
		yy=222;
		xx=130;
    frog(130,222);
	}
	
	if (yy==6&&(xx>=58 && xx<=83)){
		home=home+1;
		//frog(66,yy);
		//bx=1;
		yy=222;
		xx=130;
		frog(130,222);
	}
	
	if(yy==6&& (xx>=118 && xx<=142)){
		home=home+1;
	//	frog(124,yy);
		//cx=1;
		yy=222;
		xx=130;
		frog(130,222);
	}
	
	if (yy==6&&(xx>=177 && xx<=201)){
		home=home+1;
	//	frog(183,yy);
		//dx=1;
		yy=222;
		xx=130;
		frog(130,222);
	}
	
	if(yy==6&& (xx>=236 && xx<=260)){
		home=home+1;
	//	frog(242,yy);
	//	ex=1;
		yy=222;
		xx=130;
		frog(130,222);
	}

	
     if(home == 5){
    GLCD_DisplayString(13,13,"You Won!");
}
     if(lives == 0){
   GLCD_DisplayString(13,13,"LOSER!");
			 
			 if (xx<=0){
				 collision();
			 }
			 if (xx>=260){
				 collision();
			 }
}
		
			//UART code for Part C
				if ( UART0_Count != 0 ) {
						char_from_pc = UART0_Buffer[0];						
						UARTSend( 0, (uint8_t *)UART0_Buffer, UART0_Count);
						UART0_Count = 0;
//					if(char_from_pc=='w')
//					frog_up();
//					if(char_from_pc=='s')
//					frog_down();
//					if(char_from_pc=='a')
//					frog_left();
//					if(char_from_pc=='d')
//					frog_right();
//					
//				}


					
			if(((LPC_GPIO1->FIOPIN & up) == 0) || (char_from_pc=='w')){
			frog_up();
		}
		
		if(((LPC_GPIO1->FIOPIN & down) == 0) || (char_from_pc=='s')) {
			frog_down();
			}
		
		if(((LPC_GPIO1->FIOPIN & left) == 0) || (char_from_pc=='a')){
			frog_left();
				}
		
		if(((LPC_GPIO1->FIOPIN & right) == 0) || (char_from_pc=='d')){
			frog_right();		
					}
	}
}
}
