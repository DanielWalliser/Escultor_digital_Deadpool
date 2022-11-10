#include <iostream>
#include <fstream>
#include <string>
#include "sculptor.h"
#include <cstdlib>

int main(void){
  Sculptor deadpool(116,100,100);

  //Deadpool
  //Cabeca
  deadpool.setColor(0.6824,0,0,0.34);
  deadpool.putEllipsoid(50,50,50,23,30,20); //Face
  deadpool.putSphere(50,59,53,23); //Cranio
  deadpool.putEllipsoid(50,75,60,14,6,20); //Gorro
  deadpool.putEllipsoid(73,54,50,2,8,5); //Orelha
  deadpool.putEllipsoid(27,54,50,2,8,5); //Orelha
  deadpool.putEllipsoid(50,28,43,14,6,10);//Queixo
  deadpool.putEllipsoid(50,26,56,12,40,12); //Pescoco
  deadpool.cutBox(0,115,0,12,0,99);
  deadpool.putEllipsoid(50,19,48,2,3,5); //Pomo de Adao
  deadpool.putEllipsoid(50,45,33,2,3,5); //Nariz
  deadpool.putBox(49,52,42,45,29,32); //Nariz
  deadpool.putBox(48,53,42,43,30,32); //Nariz

  deadpool.setColor(0.0,0.0,0.0,1.0); //Mascara preta
  deadpool.putEllipsoid(57,55,35,10,16,5);
  deadpool.putEllipsoid(43,55,35,10,16,5);
  deadpool.putBox(40,41,58,61,30,31);

  deadpool.setColor(1.0,1.0,1.0,1.0); //Olhos
  deadpool.putEllipsoid(57,55,35,7,3,5);
  deadpool.putEllipsoid(43,55,35,7,3,5);
  
  deadpool.setColor(0.0,0.0,0.0,1.0); //Parte grossa da lamina
  deadpool.putBox(20,109,59,63,47,50);
  deadpool.putBox(109,110,59,63,47,50);
  deadpool.putBox(110,111,59,63,47,50);
  deadpool.putBox(111,112,60,63,48,49);
  deadpool.putBox(112,113,60,63,48,49);
 
  deadpool.setColor(0.7529,0.7529,0.7529,0.75); //Parte do corte da lamina
  deadpool.putBox(20,110,57,58,48,49); 
  deadpool.putBox(20,110,58,59,47,50);
  deadpool.putBox(109,111,57,58,48,49);
  deadpool.putBox(110,112,58,59,48,49);
  deadpool.putBox(111,113,59,60,48,49);
  deadpool.putBox(112,114,60,61,48,49);
  deadpool.putBox(113,114,61,62,48,49);
  deadpool.putBox(113,114,62,63,48,49);
  deadpool.putBox(114,115,61,62,48,49);

  deadpool.setColor(0.8549,0.6471,0.1255,0.49); //Guarda da espada
  deadpool.putEllipsoid(19,59,48,1,7,4);
  deadpool.putBox(0,1,58,63,47,50);
 
  deadpool.setColor(0.5804,0.0,0.8275,0.41); //Cabo da espada
  deadpool.putBox(1,19,58,63,47,50);

  deadpool.setColor(0.7216,0.451,0.2,0.46); //Bala
  deadpool.putBox(49,51,64,66,91,95);

  deadpool.setColor(0.5765,0.3608,0.1608,0.37); //Bala
  deadpool.putBox(49,51,64,66,95,98);

  deadpool.setColor(1.0,0.0,0.0,0.6); //Sangue
  deadpool.putBox(113,114,30,60,48,49);
  deadpool.putVoxel(114,25,48);
  deadpool.putBox(110,111,20,57,48,49);
  deadpool.putBox(106,107,20,57,48,49);
  deadpool.putBox(100,104,50,57,48,49);
  deadpool.putBox(94,100,55,57,48,49);
  deadpool.putVoxel(103,46,48);
  deadpool.putBox(93,94,34,57,48,49);
  deadpool.putBox(93,111,56,57,48,49);
  deadpool.putBox(70,82,56,57,48,49);
  deadpool.putVoxel(53,58,82);
  deadpool.putVoxel(46,62,82);
  deadpool.putVoxel(48,64,79);
  deadpool.putVoxel(54,61,80);
  deadpool.putVoxel(52,67,82);
  deadpool.putVoxel(47,59,85);
  deadpool.putVoxel(48,68,83);
  deadpool.putVoxel(53,67,81);
  deadpool.putVoxel(52,62,81);
  deadpool.putVoxel(48,60,78);

  deadpool.setColor(0.8275,0.8275,0.8275,0.20); //Rastro da bala
  deadpool.putBox(49,51,64,66,30,89);
  
  deadpool.setColor(0.0,0.0,0.0,1.0); //Base
  deadpool.putEllipsoid(50,12,57,30,1,30);

  deadpool.setColor(1.0,0.0,0.0,1.0); //Base
  deadpool.putEllipsoid(50,12,57,20,1,20);

  deadpool.setColor(0.8549,0.6471,0.1255,0.49); //?
  deadpool.putBox(76,80,70,71,35,36);
  deadpool.putBox(75,76,67,70,35,36);
  deadpool.putBox(76,80,66,67,35,36);
  deadpool.putBox(79,80,64,67,35,36);
  deadpool.putVoxel(79,62,35);

  deadpool.setColor(0.0706,0.0392,0.5608,0.3);//Enfeite espada
  deadpool.putBox(0,1,38,58,48,49);

  deadpool.setColor(1.0,1.0,1.0,1.0); //Pontos brancos da espada
  deadpool.putBox(4,5,58,63,47,50);
  deadpool.putBox(7,8,58,63,47,50);
  deadpool.putBox(10,11,58,63,47,50);
  deadpool.putBox(13,14,58,63,47,50);
  deadpool.putBox(16,17,58,63,47,50);

  deadpool.setColor(0.4,0.4,0.4,0.4); //Cabo da flecha
  deadpool.putBox(50,51,20,90,70,71);

  deadpool.setColor(0.0,0.6588,0.4196,0.33); //Pena da flecha
  deadpool.putBox(49,52,16,20,70,71);
  
  deadpool.setColor(0.7529,0.7529,0.7529,0.75); // Ponta da flecha
  deadpool.putVoxel(50,93,70);
  deadpool.putBox(49,52,92,93,70,71);
  deadpool.putBox(48,53,91,92,70,71);
  deadpool.putBox(47,54,90,91,70,71);
  
  deadpool.writeOFF((const char*)"deadpool.off");
  }
