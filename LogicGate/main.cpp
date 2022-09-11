
#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<iostream>
#include<math.h>
#include<string>
using namespace std;
int switchOn=0,switchOff=0;
int firstS1=0,secS1=0;
int rFlag=0;
void checkAND(int s1,int s2);
void checkOR(int s1,int s2);
void checkXOR(int s1,int s2);
void checkNOT(int s1);
void checkSR(int s1,int s2);
void checkJK(int s1,int s2);
void Switchmenu(int option);
void createPopupMenus(char s);
void SRtable();
void JKtable();
void welcomeDisplay();
void table(char *out[]);
void drawAND(int h,int k, int r, int x1,int y1, int x2, int y2);
void drawNOT(int h,int k, int r);
void heading(char tex[]){
     glColor3f(1,0,0);
    glRasterPos2f(0,470);
    for(int i=0;i<strlen(tex);i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,tex[i]);
}
void backpage(){
    glColor3f(1,0,0);
    glRasterPos2f(280,-470);
    char masg[]="Press 0 for menu";
    for(int i=0;i<strlen(masg);i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,masg[i]);

}
void terminals()
{
    glColor3f(0.0,0.0,0.0);
	glPointSize(30);
	glBegin(GL_POINTS);
		glVertex2f(-70.0,120.0);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glPointSize(30);
	glBegin(GL_POINTS);
		glVertex2f(-70.0,190.0);
	glEnd();
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2d(-40,120);
    glVertex2d(80,120);
    glEnd();
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2d(-40,180);
    glVertex2d(80,180);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(170,140);
    glVertex2d(270,140);
    glEnd();
}
void bulbOn(int x,int y)
{
	glColor3f(0.9,0.4,0.0);
	glPointSize(50);
	glBegin(GL_POINTS);
		//glVertex2d(300.0,140.0);
		glVertex2d(x,y);
	glEnd();
}
void bulbOff(int x, int y)
{
	glColor3f(1.0,1.0,0.0);
	glPointSize(50);
	glBegin(GL_POINTS);
		glVertex2d(x,y);
	glEnd();
}
void drawAND(int h,int k, int r,int x1,int y1, int x2,int y2){
   // glColor3f(1,0,0);
	glBegin(GL_POLYGON);
		glVertex2f(x1,y1);
		glVertex2f(x1,y2);
		glVertex2f(x2,y2);
		glVertex2f(x2,y1);
	glEnd();
	//glColor3f(1,0,0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 180; i++)
    {

    int x = r * cos(i) + h;
    int y = r * sin(i) - k;
    glVertex3f(x + h,y - k,0);

    x = r * cos(i + 0.1) + h;
    y = r * sin(i + 0.1) - k;
    glVertex2f(x + h,y - k);
    }
    glEnd();

}
void drawNOT(int h, int k, int r){
    glColor3f(1,0,0);

    glBegin(GL_LINES);
    for (int i = 0; i < 180; i++)
    {
    int x = r * cos(i) + h;
    int y = r * sin(i) - k;
    glVertex3f(x + h,y - k,0);

    x = r * cos(i + 0.1) + h;
    y = r * sin(i + 0.1) - k;
    glVertex3f(x + h,y - k,0);
    }
    glEnd();

}
void XORgate(){
    //labels
    char tex[]={"XOR GATE"};
    heading(tex);
    char *lbl[]={"A","B","C"};
    glRasterPos2f(-450,280);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*lbl[0]);
    glRasterPos2f(-450,30);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*lbl[1]);

    glRasterPos2f(340,150);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*lbl[2]);
    bulbOff(300,140);
    glColor3f(0,0,0);
	glBegin(GL_LINES);
    glVertex2d(270,150);
    glVertex2d(220,150);
    glEnd();
    glColor3f(1,0,0);
    drawAND(78,-80,55,90,107,140,212);
	drawNOT(106,-75,8);
    glColor3f(0,0,0);
    glBegin(GL_LINES);
    glVertex2d(90,130);
    glVertex2d(50,130);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(90,170);
    glVertex2d(50,170);
    glEnd();
    //next connector
    glBegin(GL_LINES);
    glVertex2d(50,130);
    glVertex2d(50,30);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(50,170);
    glVertex2d(50,270);
    glEnd();
    //next 2 row nand gates
    glBegin(GL_LINES);
    glVertex2d(50,30);
    glVertex2d(0,30);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(50,270);
    glVertex2d(0,270);
    glEnd();
    //2 nands
    glColor3f(1,0,0);
    drawAND(-24,-135,35,-96,235,-50,307);
	drawNOT(-4,-135,8);
    glColor3f(1,0,0);
    drawAND(-24,-15,35,-96,-10,-50,67);
	drawNOT(-4,-15,8);
	//3rd nand
	glColor3f(1,0,0);
	drawAND(-116,-80,55,-290,107,-220,212);
	drawNOT(-86,-75,8);
	// other connectors
	glColor3f(0,0,0);
	glBegin(GL_LINES);
    glVertex2d(-96,285);
    glVertex2d(-410,285);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(-96,255);
    glVertex2d(-126,255);
    glEnd();
    // 2 other connectors
	glColor3f(0,0,0);
	glBegin(GL_LINES);
    glVertex2d(-96,50);
    glVertex2d(-126,50);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(-96,30);
    glVertex2d(-410,30);
    glEnd();
//connect to 3rd nand
    glBegin(GL_LINES);
    glVertex2d(-126,50);
    glVertex2d(-126,255);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(-126,150);
    glVertex2d(-166,150);
    glEnd();

    glBegin(GL_LINES);
    glVertex2d(-290,190);
    glVertex2d(-326,190);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(-290,130);
    glVertex2d(-326,130);
    glEnd();

    glBegin(GL_LINES);
    glVertex2d(-326,130);
    glVertex2d(-326,30);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(-326,190);
    glVertex2d(-326,285);
    glEnd();

    glPointSize(30);
    glBegin(GL_POINTS);
    glVertex2d(-410,30);
    glVertex2d(-410,285);
    glEnd();

    checkXOR(firstS1,secS1);
}
void JKflipf(){
    char tex[]={"JK FLIP FLOP"};
    heading(tex);
    bulbOff(280,280);
    bulbOff(280,-10);
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES); //terminal inputs
    glVertex2d(17,-50);
    glVertex2d(-100,-50);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(17,20);
    glVertex2d(-30,20);
    glEnd();

    glBegin(GL_LINES);
    glVertex2d(-30,20);
    glVertex2d(-30,90);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(140,-10);
    glVertex2d(260,-10);
    glEnd();
    //diagonal
    glBegin(GL_LINES);
    glVertex2d(-30,90);
    glVertex2d(190,280);
    glEnd();
//flop1
glColor3f(1,0,0);
	drawAND(35,5,55,16,-67,60,45);
	drawNOT(65,5,8);
//jkflop1
    glColor3f(1,0,0);
    drawAND(-85,25,55,-224,5,-150,-103);
	drawNOT(-55,25,8);
	glColor3f(0,0,0);
	glBegin(GL_LINES);
    glVertex2d(-224,-10);
    glVertex2d(-290,-10);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(-224,-50);
    glVertex2d(-330,-50);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(-224,-80);
    glVertex2d(-290,-80);
    glEnd();
    //last terminal to q
    glBegin(GL_LINES);
    glVertex2d(-290,-80);
    glVertex2d(-290,-130);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(-290,-130);
    glVertex2d(240,-130);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(240,-130);
    glVertex2d(240,280);
    glEnd();
//2
    glColor3f(0,0,0);
    glBegin(GL_LINES);
    glVertex2d(17,310);
    glVertex2d(-100,310);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(17,250);
    glVertex2d(-30,250);
    glEnd();

    glBegin(GL_LINES);
    glVertex2d(-30,250);
    glVertex2d(-30,180);
    glEnd();
    //diagonal
    glBegin(GL_LINES);
    glVertex2d(-30,180);
    glVertex2d(210,-10);
    glEnd();
    glBegin(GL_LINES); //to bulb
    glVertex2d(140,280);
    glVertex2d(260,280);
    glEnd();
//flop2
    glColor3f(1,0,0);
    drawAND(35,-140,55,16,224,60,330);
    drawNOT(65,-140,8);
//jkflop2
glColor3f(1,0,0);
    drawAND(-85,-155,55,-224,257,-150,362);
	drawNOT(-55,-155,8);
	glColor3f(0,0,0);
	glBegin(GL_LINES);
    glVertex2d(-224,350);
    glVertex2d(-290,350);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(-224,310);
    glVertex2d(-330,310);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(-224,270);
    glVertex2d(-290,270);
    glEnd();
    //last terminal to q
    glBegin(GL_LINES);
    glVertex2d(-290,350);
    glVertex2d(-290,400);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(-290,400);
    glVertex2d(220,400);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(220,400);
    glVertex2d(220,-10);
    glEnd();
    //connect
    glBegin(GL_LINES);
    glVertex2d(-290,270);
    glVertex2d(-290,-10);
    glEnd();

    glPointSize(30);
    glBegin(GL_POINTS);
    glVertex2d(-320,-50);
    glVertex2d(-320,320);
    glEnd();

    checkJK(firstS1,secS1);

}

void flipf(){
     char tex[]={"SR FLIP FLOP"};
    heading(tex);
    bulbOff(240,240);
    bulbOff(240,-50);
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2d(-130,-90);
    glVertex2d(-250,-90);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(-130,0);
    glVertex2d(-190,0);
    glEnd();

    glBegin(GL_LINES);
    glVertex2d(-190,0);
    glVertex2d(-190,50);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(40,-50);
    glVertex2d(240,-50);
    glEnd();
    //diagonal
    glBegin(GL_LINES);
    glVertex2d(-190,50);
    glVertex2d(160,240);
    glEnd();
//flop1
glColor3f(0,1,0);
    drawAND(-25,28,75,-130,-120,-20,10);
	drawNOT(15,25,8);

    glColor3f(0,0,0);
    glBegin(GL_LINES);
    glVertex2d(-130,270);
    glVertex2d(-250,270);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(-130,210);
    glVertex2d(-200,210);
    glEnd();

    glBegin(GL_LINES);
    glVertex2d(-200,210);
    glVertex2d(-200,130);
    glEnd();
    //diagonal
    glBegin(GL_LINES);
    glVertex2d(-200,130);
    glVertex2d(180,-50);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(40,240);
    glVertex2d(240,240);
    glEnd();
//flop2
glColor3f(1,0,0);
    drawAND(-20,-120,75,-130,170,-20,310);
    drawNOT(20,-120,8);
    glColor3f(0,0,0);
    glPointSize(30);
    glBegin(GL_POINTS);
    glVertex2d(-237,270);
    glVertex2d(-237,-90);
    glEnd();
    checkSR(firstS1,secS1);
}
void checkXOR(int s1,int s2)
{
    if(s1 ^ s2==0){
        bulbOn(300,140);
    }else{
        bulbOff(300,140);
    }
}
void checkSR(int s1,int s2){
    int s11,s22;
    if(s1==0 && s2==1){
        bulbOn(240,240);
        bulbOff(240,-50);
        s11=s1;s22=s2;
    }else if(s1==1&& s2==0){
        bulbOff(240,240);
        bulbOn(240,-50);
        s11=s1;s22=s2;
    }else if (s1==1 && s2==1){
        if(s11==0 && s22==1){
        bulbOn(240,240);
        bulbOff(240,-50);
        }else{
        bulbOff(240,240);
        bulbOn(240,-50);
        }
    }
}
void checkJK(int s1,int s2){
    if(s1==0 && s2==1){
        bulbOn(280,280);
        bulbOff(280,-10);
    }else if((s1==1&& s2==0)|| (s1==1 && s2==1)){
        bulbOff(280,280);
        bulbOn(280,-10);

    }
}
void andGate()
{
    char tex[]={"AND GATE"};
    heading(tex);
    int r=76,h=60,k=200;
//labels
    char *lbl[]={"A","B","C"};
    glRasterPos2f(-120,190);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*lbl[0]);
    glRasterPos2f(-120,120);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*lbl[1]);

    glRasterPos2f(340,150);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*lbl[2]);

    bulbOff(300,140);
    terminals();
	glColor3f(1,0,0);
	glBegin(GL_POLYGON);
		glVertex2f(63,70);
		glVertex2f(63,210);
		glVertex2f(150,210);
		glVertex2f(150,70);
	glEnd();
	glColor3f(1,0,0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 180; i++)
    {
    int x = r * cos(i) - h;
    int y = r * sin(i) + k;
    glVertex3f(x + k,y - h,0);

    x = r * cos(i + 0.1) - h;
    y = r * sin(i + 0.1) + k;
    glVertex3f(x + k,y - h,0);
    }
    glEnd();

	checkAND(firstS1,secS1);
}
void checkAND(int s1,int s2)
{
    if(s1 & s2!=0){
        bulbOff(300,140);
    }else{
        bulbOn(300,140);
    }
}
void orGate()
{
    char tex[]={"OR GATE"};
    heading(tex);
    int r=70,h=60,k=200;
    //labels
    char *lbl[]={"A","B","C"};
    glRasterPos2f(-120,190);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*lbl[0]);
    glRasterPos2f(-120,120);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*lbl[1]);

    glRasterPos2f(340,150);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*lbl[2]);
    bulbOff(300,140);

    glColor3f(0,0,0);
    terminals();
	glColor3f(1,0,0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 180; i++)
    {
    int x = r * cos(i) - h;
    int y = r * sin(i) + k;
    glVertex3f(x + k,y - h,0);

    x = r * cos(i + 0.1) - h;
    y = r * sin(i + 0.1) + k;
    glVertex3f(x + k,y - h,0);
    }
    glEnd();

    glColor3f(1,1,1);
    drawAND(35,-70,65,16,-67,60,45);
    glColor3f(0,0,0);
    glBegin(GL_LINES);
    glVertex2d(-40,120);
    glVertex2d(110,120);
    glEnd();

    glBegin(GL_LINES);
    glVertex2d(-40,180);
    glVertex2d(110,180);
    glEnd();

	checkOR(firstS1,secS1);
}
void checkOR(int s1,int s2)
{
    if(s1 | s2!=0){
        bulbOff(300,140);
    }else{
        bulbOn(300,140);
    }
}
void notGate()
{
    char tex[]={"NOT GATE"};
    heading(tex);
    bulbOff(300,170);
    glColor3f(0.0,0.0,0.0);
	glPointSize(30);
	glBegin(GL_POINTS);
		glVertex2f(-70.0,150.0);
	glEnd();
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2d(-40,150);
    glVertex2d(80,150);
    glEnd();
	glColor3f(1,0,0);
	glBegin(GL_POLYGON);
		glVertex2f(80,90);
		glVertex2f(80,220);
		glVertex2f(210,170);
	glEnd();
	drawNOT(110,-86,10);
	glBegin(GL_LINES);
    glVertex2d(230,170);
    glVertex2d(310,170);
    glEnd();

    char *msg[5]={"A","B","0","1"};
    glColor3f(0,0,0);
    glRasterPos2f(-450,-200);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[0]);
    glRasterPos2f(-350,-200);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[1]);

    glRasterPos2f(-450,-270);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[2]);
    glRasterPos2f(-350,-270);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[3]);



    glRasterPos2f(-450,-330);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[3]);
    glRasterPos2f(-350,-330);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[2]);

    glBegin(GL_LINE_LOOP);
    glVertex2d(-470,-340);
    glVertex2d(-470,-150);
    glVertex2d(-300,-150);
    glVertex2d(-300,-340);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(-390,-340);
    glVertex2d(-390,-150);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(-300,-340);
    glVertex2d(-300,-150);
    glEnd();
//rows

    glBegin(GL_LINES);
    glVertex2d(-470,-220);
    glVertex2d(-300,-220);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(-470,-280);
    glVertex2d(-300,-280);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(-470,-340);
    glVertex2d(-300,-340);
    glEnd();

	checkNOT(firstS1);
}
void checkNOT(int s1)
{
    if(s1 ==0){
        bulbOff(300,170);
    }else{
        bulbOn(300,170);
    }
}
/*void Display(void)
{
    //std::cout<<"Display 1 called"<<std::endl;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    welcomeDisplay();
    glFlush();
    glutSwapBuffers();
}*/
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	char *out[]={"0","0","0","1"};
	andGate();
	table(out);
	backpage();
	glutPostRedisplay();
	glutSwapBuffers();
}
void display2()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	char *out[]={"0","1","1","1"};
	orGate();
	table(out);
	backpage();
	glutPostRedisplay();
	glutSwapBuffers();
}
void display3()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	notGate();
	backpage();
	glutPostRedisplay();
	glutSwapBuffers();
}
void display4()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	flipf();
	SRtable();
	backpage();
	glutPostRedisplay();
	glutSwapBuffers();
}
void display5()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	JKflipf();
	JKtable();
	backpage();
	glutPostRedisplay();
	glutSwapBuffers();
}
void display6()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	char *out[]={"0","1","1","0"};
	XORgate();
	table(out);
	backpage();
	glutPostRedisplay();
	glutSwapBuffers();
}
void Switchmenu(int option)
{
    switch(option){
    case 1:firstS1=1; cout<<firstS1;break;
    case 2:firstS1=0;cout<<firstS1;break;
    case 3:secS1=1;cout<<secS1;break;
    case 4:secS1=0;cout<<secS1;break;

    }

}
void keys(unsigned char key, int x,int y){
    switch (key) {
        case '0':
            std::cout<<"back Pressed"<<std::endl;
            glutDisplayFunc(welcomeDisplay);
            glutKeyboardFunc(keys);
            break;
	    case '1':
	        std::cout<<"1 Pressed"<<std::endl;
            glutKeyboardFunc(keys);
            firstS1=0;
            secS1=0;
            glutDisplayFunc(display);
            createPopupMenus('a');
            break;
        case '2':
            std::cout<<"2 Pressed"<<std::endl;
            firstS1=0;
            secS1=0;
            glutDisplayFunc(display2);
            createPopupMenus('a');
            break;
        case '3':
            std::cout<<"3 Pressed"<<std::endl;
            firstS1=0;
            secS1=0;
            glutDisplayFunc(display3);
            createPopupMenus('o');
            break;
        case '4':
            std::cout<<"4 Pressed"<<std::endl;
            firstS1=0;
            secS1=0;
            glutDisplayFunc(display4);
            createPopupMenus('a');
            break;
        case '5':
            std::cout<<"5 Pressed"<<std::endl;
            firstS1=0;
            secS1=0;
            glutDisplayFunc(display5);
            createPopupMenus('a');
            break;
        case '6':
            std::cout<<"6 Pressed"<<std::endl;
            firstS1=0;
            secS1=0;
            glutDisplayFunc(display6);
            createPopupMenus('a');
            break;

    }
   // glutPostRedisplay();
}


void createPopupMenus(char s) {

if(s!='o'){
	int subMenu_A = glutCreateMenu(Switchmenu);
	glutAddMenuEntry("ON",1);
	glutAddMenuEntry("OFF",2);

	int subMenu_B = glutCreateMenu(Switchmenu);
	glutAddMenuEntry("ON",3);
	glutAddMenuEntry("OFF",4);


	glutCreateMenu(Switchmenu);
	glutAddSubMenu("Terminal A", subMenu_A);
	glutAddSubMenu("Terminal B", subMenu_B);

	// attach the menu to the right button
}else{
    glutCreateMenu(Switchmenu);
	glutAddMenuEntry("ON",1);
	glutAddMenuEntry("OFF",2);

}
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}
void JKtable(){
    char *msg[6]={"J","K","Q","q","0","1"};
    glColor3f(0,0,0);

    glRasterPos2f(-450,-200);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[0]);
    glRasterPos2f(-380,-200);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[1]);
    glRasterPos2f(-250,-200);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[2]);
    glRasterPos2f(-150,-200);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[3]);

    glRasterPos2f(-450,-270);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[5]);
    glRasterPos2f(-350,-270);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[4]);
    glRasterPos2f(-250,-270);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[5]);
    glRasterPos2f(-150,-270);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[4]);

    glRasterPos2f(-450,-330);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[5]);
    glRasterPos2f(-350,-330);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[5]);
    glRasterPos2f(-250,-330);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[5]);
    glRasterPos2f(-150,-330);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[4]);

    glRasterPos2f(-450,-390);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[4]);
    glRasterPos2f(-350,-390);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[5]);
    glRasterPos2f(-250,-390);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[4]);
    glRasterPos2f(-150,-390);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[5]);

    glRasterPos2f(-450,-450);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[4]);
    glRasterPos2f(-350,-450);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[4]);
    glRasterPos2f(-250,-450);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[5]);
    glRasterPos2f(-150,-450);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[5]);
//labels
    glRasterPos2f(330,250);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[2]);
    glRasterPos2f(330,-40);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[3]);

    glRasterPos2f(-360,310);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[0]);
    glRasterPos2f(-360,-70);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[1]);

    glBegin(GL_LINE_LOOP);
    glVertex2d(-470,-470);
    glVertex2d(-470,-150);
    glVertex2d(-100,-150);
    glVertex2d(-100,-470);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(-390,-470);
    glVertex2d(-390,-150);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(-300,-470);
    glVertex2d(-300,-150);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(-210,-470);
    glVertex2d(-210,-150);
    glEnd();
//rows

    glBegin(GL_LINES);
    glVertex2d(-470,-220);
    glVertex2d(-100,-220);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(-470,-280);
    glVertex2d(-100,-280);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(-470,-340);
    glVertex2d(-100,-340);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(-470,-400);
    glVertex2d(-100,-400);
    glEnd();

}
void SRtable(){
    char *msg[6]={"S","R","Q","q","0","1"};
    glColor3f(0,0,0);

    glRasterPos2f(-450,-200);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[0]);
    glRasterPos2f(-350,-200);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[1]);
    glRasterPos2f(-250,-200);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[2]);
    glRasterPos2f(-150,-200);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[3]);

    glRasterPos2f(-450,-270);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[5]);
    glRasterPos2f(-350,-270);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[4]);
    glRasterPos2f(-250,-270);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[5]);
    glRasterPos2f(-150,-270);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[4]);

    glRasterPos2f(-450,-330);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[5]);
    glRasterPos2f(-350,-330);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[5]);
    glRasterPos2f(-250,-330);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[5]);
    glRasterPos2f(-150,-330);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[4]);

    glRasterPos2f(-450,-390);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[4]);
    glRasterPos2f(-350,-390);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[5]);
    glRasterPos2f(-250,-390);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[4]);
    glRasterPos2f(-150,-390);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[5]);

    glRasterPos2f(-450,-450);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[4]);
    glRasterPos2f(-350,-450);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[4]);
    glRasterPos2f(-250,-450);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[5]);
    glRasterPos2f(-150,-450);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[5]);
//labels
    glRasterPos2f(290,220);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[2]);
    glRasterPos2f(290,-70);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[3]);

    glRasterPos2f(-280,250);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[0]);
    glRasterPos2f(-280,-90);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[1]);

    glBegin(GL_LINE_LOOP);
    glVertex2d(-470,-470);
    glVertex2d(-470,-150);
    glVertex2d(-100,-150);
    glVertex2d(-100,-470);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(-390,-470);
    glVertex2d(-390,-150);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(-300,-470);
    glVertex2d(-300,-150);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(-210,-470);
    glVertex2d(-210,-150);
    glEnd();
//rows

    glBegin(GL_LINES);
    glVertex2d(-470,-220);
    glVertex2d(-100,-220);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(-470,-280);
    glVertex2d(-100,-280);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(-470,-340);
    glVertex2d(-100,-340);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(-470,-400);
    glVertex2d(-100,-400);
    glEnd();

}
void table(char *out[]){
    char *msg[5]={"A","B","C","0","1"};
    glColor3f(0,0,0);
    glRasterPos2f(-450,-200);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[0]);
    glRasterPos2f(-350,-200);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[1]);
    glRasterPos2f(-250,-200);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[2]);

    glRasterPos2f(-450,-270);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[3]);
    glRasterPos2f(-350,-270);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[3]);
    glRasterPos2f(-250,-270);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*out[0]);


    glRasterPos2f(-450,-330);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[3]);
    glRasterPos2f(-350,-330);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[4]);
    glRasterPos2f(-250,-330);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*out[1]);

    glRasterPos2f(-450,-390);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[4]);
    glRasterPos2f(-350,-390);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[3]);
    glRasterPos2f(-250,-390);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*out[2]);

    glRasterPos2f(-450,-450);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[4]);
    glRasterPos2f(-350,-450);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*msg[4]);
    glRasterPos2f(-250,-450);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*out[3]);

    glBegin(GL_LINE_LOOP);
    glVertex2d(-470,-470);
    glVertex2d(-470,-150);
    glVertex2d(-200,-150);
    glVertex2d(-200,-470);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(-390,-470);
    glVertex2d(-390,-150);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(-300,-470);
    glVertex2d(-300,-150);
    glEnd();
//rows

    glBegin(GL_LINES);
    glVertex2d(-470,-220);
    glVertex2d(-200,-220);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(-470,-280);
    glVertex2d(-200,-280);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(-470,-340);
    glVertex2d(-200,-340);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(-470,-400);
    glVertex2d(-200,-400);
    glEnd();
}
void welcomeDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glColor3f(1,0,0);
    glRasterPos2f(-128,320);
    char masg[]="LOGIC GATE SIMULATION";
    for(int i=0;i<strlen(masg);i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,masg[i]);

    glRasterPos2f(-300,160);
    char masg1[]="ALEEMA PK                                                      4SO19CS013";
    for(int i=0;i<strlen(masg1);i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,masg1[i]);
    glRasterPos2f(-300,100);
    char masg2[]="ANNAPURNA KG                                             4SO19CS022";
    for(int i=0;i<strlen(masg2);i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,masg2[i]);
    glRasterPos2f(-100,40);
    char masg3[]="1. AND GATE";
    for(int i=0;i<strlen(masg3);i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,masg3[i]);
        glRasterPos2f(-100,0);
    char masg4[]="2. OR GATE";
    for(int i=0;i<strlen(masg4);i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,masg4[i]);
glRasterPos2f(-100,-40);
    char masg5[]="3. NOT GATE";
    for(int i=0;i<strlen(masg5);i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,masg5[i]);
        glRasterPos2f(-100,-80);
    char masg6[]="4. SR FLIP FLOP ";
    for(int i=0;i<strlen(masg6);i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,masg6[i]);
    glRasterPos2f(-100,-120);
    char masg7[]="5. JK FLIP FLOP ";
    for(int i=0;i<strlen(masg7);i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,masg7[i]);
        glRasterPos2f(-100,-160);
    char masg8[]="6. XOR using NAND gate";
    for(int i=0;i<strlen(masg8);i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,masg8[i]);
    glutPostRedisplay();
	glutSwapBuffers();

}
void init()
{
    glClearColor(1,1,1,1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-500,500,-500,500);
	glMatrixMode(GL_MODELVIEW);
}
int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(800,600);
	glutCreateWindow("LOGIC GATE SIMULATION");
	init();
	glutDisplayFunc(welcomeDisplay);
	glutKeyboardFunc(keys);
	glutMainLoop();
}
