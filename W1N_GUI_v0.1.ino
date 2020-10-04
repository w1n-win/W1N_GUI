//======================ARDUINO PROJECT======================
//PROJECT NAME : W1N_GUI
//START DATE   : 2020 Sep 28
//VERSION      : v0.1
//UPDATE DATE  : 2020 Oct 2
//TARGET BOARD : Arduino Uno
//                 Data Logging Shield V1.0 (Deek-Robot)
//                 2.4" TFT LCD Shield (MCUFriend), Mod. "LCD_RST" (Pull Up Vcc)
//AUTHOR       : Winata Panjaya
//=====================^ARDUINO PROJECT^=====================

//=======================PIN RESOURCE========================
//                             // 13[PB5/SCK] := SD_SCK
//                             // 12[PB4/MISO]:= SD_DO
//                             // 11[PB3/MOSI]:= SD_DI
//                             // 10[PB2/SS   := SD_CS
//                             // 9 [PB1]     := LCD_D0
//                             // 8 [PB0]     := LCD_D0
//                             //
//                             // 7 [PD7]     := LCD_D7
//                             // 6 [PD6]     := LCD_D6
// A0[PC0]    := LCD_RD        // 5 [PD5]     := LCD_D5
// A1[PC1]    := LCD_WR        // 4 [PD4]     := LCD_D4
// A2[PC2]    := LCD_RS        // 3 [PD3]     := LCD_D3
// A3[PC3]    := LCD_CD        // 2 [PD2]     := LCD_D2
// A4[PC4/SDA]:= RTC_SDA       // 1 [PD1/Tx]  := 
// A5[PC5/SCL]:= RTS_SCL       // 0 [PD0/Rx]  := 
//======================^PIN RESOURCE^=======================

//==========================LIBRARY==========================
#include "Adafruit_GFX.h"    // Core graphics library
#include "MCUFRIEND_kbv.h"   // Hardware specific library

#include "MonoLogo.h"            //Logo
#include "MonoIcon_Set_32x32.h"  //Icon logo Set
//#include "Fonts/FreeMono9pt7b.h"  //Adafruit_GFX Reminiscent of Courier
//#include "Fonts/FreeSans9pt7b.h"  //Adafruit_GFX Reminiscent of Arial
#include "Fonts/FreeSerif9pt7b.h" //Adafruit_GFX Reminiscent of Times New Roman
//#include "FreeDefaultFonts.h"
//#include "FreeSevenSegNumFontPlusPlus.h"
#include "TouchScreen.h"

//=========================^LIBRARY^=========================

//===========================CLASS===========================
MCUFRIEND_kbv tft;
//==========================^CLASS^==========================

//====================VARIABLE DECLARATION===================
//GRAYSCALE            RGB565      RGB                  HEX
#define C_BLACK        0x0000      //rgb(  0,  0,  0) 	#000000  
#define C_GREYDARK     0x528A      //rgb( 80, 80, 80)   #505050
#define C_GREY         0xAD55      //rgb(169,169,169) 	#A9A9A9 
#define C_SILVER       0xC618      //rgb(192,192,192) 	#C0C0C0   
#define C_GREYLIGHT    0xDEFB      //rgb(220,220,220) 	#DCDCDC
#define C_WHITE        0xFFFF      //rgb(255,255,255) 	#FFFFFF 
//RED                  RGB565      RGB                  HEX
#define C_RED          0xF800      //rgb(255,  0,  0) 	#FF0000
#define C_MAROON       0x8800      //rgb(139,  0,  0)   #8B0000
#define C_CRIMSON      0xD8A7      //rgb(220, 20, 60)   #DC143C 
#define C_REDCORAL     0xF410      //rgb(240,128,128) 	#F08080
//PINK                 RGB565      RGB                  HEX
#define C_PINK         0xFDB8      //rgb(255,182,193) 	#FFB6C1 
#define C_MAGENTA      0xF81F      //rgb(255  ,0,255) 	#FF00FF 
#define C_PINKDEEP     0xF8B2      //rgb(255, 20,147) 	#FF1493 
#define C_PINKHOT      0xFB56      //rgb(255,105,180) 	#FF69B4
#define C_PINKLIGHT    0xFF3C      //rgb(255,228,225) 	#FFE4E1
//PURPLE               RGB565      RGB                  HEX
#define C_PURPLE       0x780F      //rgb(128,  0,128) 	#800080 
#define C_INDIGO       0x4810      //rgb( 75,  0,130) 	#4B0082 
#define C_PURPLEDARK   0x901A      //rgb(148,  0,211) 	#9400D3 
#define C_VIOLET       0xEC1D      //rgb(238,130,238) 	#EE82EE
#define C_PURPLELIGHT  0xDD1B      //rgb(221,160,221) 	#DDA0DD
//GREEN                RGB565      RGB                  HEX
#define C_GREEN        0x07E0      //rgb(  0,255,  0) 	#00FF00
#define C_GREENDARK    0x03E0      //rgb(  0,128,  0) 	#008000
#define C_OLIVE        0x7BE0      //rgb(128,128,  0) 	#808000 
#define C_GREENYELLOW  0xAFE5      //rgb(173,255, 47) 	#ADFF2F
#define C_GREENSPRING  0x07EF      //rgb(  0,255,127) 	#00FF7F
#define C_GREENPALE    0x9FD3      //rgb(152,251,152) 	#98FB98 
//CYAN                 RGB565      RGB                  HEX
#define C_CYAN         0x07FF      //rgb(  0,255,255) 	#00FFFF
#define C_CYANDARK     0x03EF      //rgb(  0,128,128) 	#008080 
#define C_TURQUOISE    0x471A      //rgb( 64,224,208) 	#40E0D0  
#define C_AQUAMARINE   0x7FFA      //rgb(127,255,212) 	#7FFFD4  
#define C_CYANLIGHT    0xE7FF      //rgb(224,255,255) 	#E0FFFF 
//BLUE                 RGB565      RGB                  HEX
#define C_BLUE         0x001F      //rgb(  0,  0,255) 	#0000FF 
#define C_BLUENIGHT    0x000A      //rgb(  0,  0, 82) 	#000052 
#define C_BLUENAVY     0x0010      //rgb(  0,  0,128) 	#000080 
#define C_BLUEROYAL    0x435C      //rgb( 65,105,225) 	#4169E1
#define C_BLUESKY      0x867D      //rgb(135,206,235) 	#87CEEB
#define C_BLUELIGHT    0xB71C      //rgb(176,224,230) 	#B0E0E6
//ORANGE                 RGB565      RGB                  HEX
#define C_ORANGE       0xFDA0      //rgb(255,180,  0)   #FFB400
#define C_ORANGERED    0xFA20      //rgb(255, 69,  0)  	#FF4500
#define C_ORANGESALMON 0xFD0F      //rgb(255,160,122) 	#FFA07A
//YELLOW                 RGB565      RGB                  HEX
#define C_YELLOW       0xFFE0      //rgb(255,255,  0) 	#FFFF00
#define C_YELLOWLIGHT  0xFFEC      //rgb(255,255,100) 	#FFFF64
//BROWN                RGB565      RGB                  HEX
#define C_BROWN        0xA145      //rgb(165, 42, 42) 	#A52A2A 
#define C_BROWNDARK    0x8A22      //rgb(139, 69, 19) 	#8B4513 
#define C_CHOCOLATE    0xD343      //rgb(210,105, 30) 	#D2691E
#define C_BROWNLIGHT   0xDDD0      //rgb(222,184,135) 	#DEB887
#define C_KHAKIDARK    0xF731      //rgb(240,230,140) 	#F0E68C
#define C_KHAKI        0xBDAD      //rgb(189,183,107) 	#BDB76B

#define MINPRESSURE 200
#define MAXPRESSURE 1000

const int XP=6, XM=A2, YP=A1, YM=7;   // TouchScreen Port 
//const int TS_LEFT=78, TS_RIGHT=914, TS_TOP=57, TS_BOT=882; //PORTRAIT CALIBRATION [240x320]
const int TS_LEFT=75, TS_RIGHT=886, TS_TOP=910, TS_BOTTOM=100; //LANDSCAPE CALIBRATION [320x240]
TouchScreen ts = TouchScreen(XP,YP,XM,YM,300); //X+ ~ X- resistance is 300 Ohm

Adafruit_GFX_Button Tab_1, Tab_2, Tab_3, Tab_4, Tab_5;
int touch_X, touch_Y;  //Touch position: X & Y
int Tab_Session = 0;   //Default=0 Splash Screen (Logo)
int col[8];
//===================^VARIABLE DECLARATION^==================

//====================FUNCTION DECLARATION===================
void ShowMsgXY(int x, int y, int sz, uint16_t clor,const GFXfont *f, String msg)
{ //Stylize Font
  tft.setFont(f);
  tft.setCursor(x, y);
  tft.setTextColor(clor);
  tft.setTextSize(sz);
  tft.print(msg);
}

void ShowMsg(int x, int y, int sz, uint16_t clor, String msg)
{ //Default Simple Font [5x7]px
  tft.setFont();      
  tft.setCursor(x, y - (7*sz));
  tft.setTextColor(clor);
  tft.setTextSize(sz);
  tft.print(msg);
}

bool Touch_getXY(void)
{
  TSPoint p = ts.getPoint();
  pinMode(YP, OUTPUT);      //restore shared pins
  pinMode(XM, OUTPUT);
  digitalWrite(YP, HIGH);   //because TFT control pins
  digitalWrite(XM, HIGH);
  bool pressed = (p.z > MINPRESSURE && p.z < MAXPRESSURE);
  if (pressed) {
    touch_X = map(p.y,TS_LEFT,TS_RIGHT,0,tft.width()); 
    touch_Y = map(p.x,TS_TOP,TS_BOTTOM,0,tft.height());
  }
   return pressed;
}

void DrawFrame()
{
  tft.fillScreen(C_BLUENIGHT);
  Tab_1.drawButton(false);
  Tab_2.drawButton(false);
  Tab_3.drawButton(false);
  Tab_4.drawButton(false);
  Tab_5.drawButton(false);
  tft.drawBitmap( 16,206,MonoIcon_Home_32x32   ,32,32,C_WHITE);  
  tft.drawBitmap( 80,206,MonoIcon_Graph_32x32  ,32,32,C_WHITE); 
  tft.drawBitmap(144,206,MonoIcon_Disket_32x32 ,32,32,C_WHITE); 
  tft.drawBitmap(208,206,MonoIcon_Setting_32x32,32,32,C_WHITE); 
  tft.drawBitmap(272,206,MonoIcon_Info_32x32   ,32,32,C_WHITE);   
}

void Animation_loading(int x, int y, int sz)
{
  col[0] = tft.color565(155,   0,  50);
  col[1] = tft.color565(170,  30,  80);
  col[2] = tft.color565(195,  60, 110);
  col[3] = tft.color565(215,  90, 140);
  col[4] = tft.color565(230, 120, 170);
  col[5] = tft.color565(250, 150, 200);
  col[6] = tft.color565(255, 180, 220);
  col[7] = tft.color565(255, 210, 240);
  
  for (int i = 8; i > 0; i--) {
    tft.fillCircle(x+(20*sz)*(cos(-(i+0)*3.1416/4)),y+(20*sz)*(sin(-(i+0)*3.1416/4)),5*sz,col[0]); delay(15);
    tft.fillCircle(x+(20*sz)*(cos(-(i+1)*3.1416/4)),y+(20*sz)*(sin(-(i+1)*3.1416/4)),5*sz,col[1]); delay(15);
    tft.fillCircle(x+(20*sz)*(cos(-(i+2)*3.1416/4)),y+(20*sz)*(sin(-(i+2)*3.1416/4)),5*sz,col[2]); delay(15);
    tft.fillCircle(x+(20*sz)*(cos(-(i+3)*3.1416/4)),y+(20*sz)*(sin(-(i+3)*3.1416/4)),5*sz,col[3]); delay(15);
    tft.fillCircle(x+(20*sz)*(cos(-(i+4)*3.1416/4)),y+(20*sz)*(sin(-(i+4)*3.1416/4)),5*sz,col[4]); delay(15);
    tft.fillCircle(x+(20*sz)*(cos(-(i+5)*3.1416/4)),y+(20*sz)*(sin(-(i+5)*3.1416/4)),5*sz,col[5]); delay(15);
    tft.fillCircle(x+(20*sz)*(cos(-(i+6)*3.1416/4)),y+(20*sz)*(sin(-(i+6)*3.1416/4)),5*sz,col[6]); delay(15);
    tft.fillCircle(x+(20*sz)*(cos(-(i+7)*3.1416/4)),y+(20*sz)*(sin(-(i+7)*3.1416/4)),5*sz,col[7]); delay(15);
  }
}

void Scan_Touch ()
{
  bool down = Touch_getXY();
  Tab_1.press(down && Tab_1.contains(touch_X,touch_Y));
  Tab_2.press(down && Tab_2.contains(touch_X,touch_Y));
  Tab_3.press(down && Tab_3.contains(touch_X,touch_Y));
  Tab_4.press(down && Tab_4.contains(touch_X,touch_Y));
  Tab_5.press(down && Tab_5.contains(touch_X,touch_Y));
       
  if (Tab_1.justPressed()) {
    DrawFrame();
    Tab_1.drawButton(true);
    tft.drawBitmap( 16,206,MonoIcon_Home_32x32   ,32,32,C_YELLOW); 
    Tab_Session = 10;    
  } 
  if (Tab_2.justPressed()) {
    DrawFrame();
    Tab_2.drawButton(true);
    tft.drawBitmap( 80,205,MonoIcon_Graph_32x32  ,32,32,C_YELLOW); 
    Tab_Session = 20;    
  }  
  if (Tab_3.justPressed()) {
    DrawFrame();
    Tab_3.drawButton(true);
    tft.drawBitmap(144,205,MonoIcon_Disket_32x32 ,32,32,C_YELLOW); 
    Tab_Session = 30;    
  }
  if (Tab_4.justPressed()) {
    DrawFrame();
    Tab_4.drawButton(true);
    tft.drawBitmap(208,205,MonoIcon_Setting_32x32,32,32,C_YELLOW); 
    Tab_Session = 40;    
  }
  if (Tab_5.justPressed()) {
    DrawFrame();
    Tab_5.drawButton(true);
    tft.drawBitmap(272,205,MonoIcon_Info_32x32   ,32,32,C_YELLOW);  
    Tab_Session = 50;    
  }  
}

void SplashScreen() //SPLASHSCREEN
{
  tft.fillRect(  0,0,319,198,C_WHITE);
  tft.drawBitmap(  80, 80,W1N_LogoW_Mono_66x63px ,66,63 ,C_BLUEROYAL);
  tft.drawBitmap( 146, 48,W1N_LogoI_Mono_26x95px ,26,95 ,C_GREENSPRING);
  tft.drawBitmap( 182, 80,W1N_LogoN_Mono_62x63px ,62,63 ,C_ORANGE);
  tft.fillRect( 80,148,166,18,C_BLUEROYAL);
  tft.drawBitmap(  84,150,W1N_LogoD_Mono_157x14px,157,14,C_WHITE); 
  Tab_Session = 99;   
}

void Sesion_Tab1() //HOME Session
{
  ShowMsg(0,16, 2, C_WHITE, "HOME");
  ShowMsgXY(0,32, 1, C_PINK, &FreeSerif9pt7b,  "HOME");
}

void Sesion_Tab2() //GRAPH Session
{
  ShowMsg(0,16, 2, C_WHITE, "GRAPH");
  ShowMsgXY(0,32, 1, C_PINK, &FreeSerif9pt7b,  "GRAPH");
}

void Sesion_Tab3() //DISKET Session
{
  ShowMsg(0,16, 2, C_WHITE, "DISKET");
  ShowMsgXY(0,32, 1, C_PINK, &FreeSerif9pt7b,  "DISKET");
}

void Sesion_Tab4() //SETTING Session
{
  ShowMsg(0,16, 2, C_WHITE, "Screen is " + String(tft.width()) + "x" + String(tft.height()));
  ShowMsgXY(0,32, 1, C_PINK, &FreeSerif9pt7b,  "Screen is " + String(tft.width()) + "x" + String(tft.height()));
}

void Sesion_Tab5() //INFO Session
{
  ShowMsg(10,32, 3, C_YELLOW, "WIN GUI V0.1");
  ShowMsgXY(10,32+16, 1, C_WHITE, &FreeSerif9pt7b, "Author: winata Panjaya");
  ShowMsgXY(10,32+32, 1, C_WHITE, &FreeSerif9pt7b, "Email: winata.w1n@gmail");
  ShowMsgXY(10,32+48, 1, C_WHITE, &FreeSerif9pt7b, "Project's page: http://www.XYZ");
  //ShowMsg(10,42, 1, C_WHITE, "Author: winata Panjaya");
  //ShowMsg(10,52, 1, C_WHITE, "Email: winata.w1n@gmail");
  //ShowMsg(10,62, 1, C_WHITE, "Project's page: http://www.XYZ");

  ShowMsg(10, 110+0 , 1, C_PINK, "DISCLAIMER");
  ShowMsg(10, 110+8 , 1, C_WHITE, "THE PROGRAM 'AS IS' WITHOUT WARRANTY OF ANY KIND,");
  ShowMsg(10, 110+16, 1, C_WHITE, "EITHER EXPRESSED OR IMPLIED, INCLUDING, BUT NOT ");
  ShowMsg(10, 110+24, 1, C_WHITE, "LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANT-");
  ShowMsg(10, 110+32, 1, C_WHITE, "ABILITY AND FITNESS FOR A PARTICULAR PURPOSE.");
  ShowMsg(10, 110+40, 1, C_WHITE, "THE ENTIRE RISK AS TO THE QUALITY AND PERFORMANCE");
  ShowMsg(10, 110+48, 1, C_WHITE, "OF THE PROGRAM IS WITH YOU. SHOULD THE PROGRAM"); 
  ShowMsg(10, 110+56, 1, C_WHITE, "PROVE DEFECTIVE, YOU ASSUME THE COST OF ALL");
  ShowMsg(10, 110+64, 1, C_WHITE, "NECESSARY SERVICING, REPAIR OR CORRECTION."); 
  Tab_Session = 99; 
}
//===================^FUNCTION DECLARATION^==================

void setup()
{
  tft.reset();
  uint16_t TFTID = tft.readID();
  tft.begin(TFTID);
  tft.setRotation(1);         //0=PORTRAIT, 1=LANDSCAPE, 2=180 PORTRAIT, 3=180 LANDSCAPE.
  tft.invertDisplay(false);   //Inverting Screen Colors
  //tft.fillScreen(C_WHITE);

  Tab_1.initButton(&tft, 32,222,56,36,C_BLUENAVY,C_BLUENAVY,C_BLUEROYAL,"",1);
  Tab_2.initButton(&tft, 96,222,56,36,C_BLUENAVY,C_BLUENAVY,C_BLUEROYAL,"",1);
  Tab_3.initButton(&tft,160,222,56,36,C_BLUENAVY,C_BLUENAVY,C_BLUEROYAL,"",1);
  Tab_4.initButton(&tft,224,222,56,36,C_BLUENAVY,C_BLUENAVY,C_BLUEROYAL,"",1);
  Tab_5.initButton(&tft,288,222,56,36,C_BLUENAVY,C_BLUENAVY,C_BLUEROYAL,"",1);
  DrawFrame(); 
}

void loop(void)
{
  Scan_Touch();
  switch (Tab_Session) {
    case  0 ...  9:     //Splash Screen
      SplashScreen(); break;
    case 10 ... 19:     //HOME Session
      Sesion_Tab1();  break;
    case 20 ... 29:     //GRAPH Session
      Sesion_Tab2();  break;
    case 30 ... 39:     //DISKET Session
      Sesion_Tab3();  break;
    case 40 ... 49:     //SETTING Session
      Sesion_Tab4();  break;
    case 50 ... 59:     //INFO Session
      Sesion_Tab5();  break;
  }  

// while (1);    //HALT
} 
// END
