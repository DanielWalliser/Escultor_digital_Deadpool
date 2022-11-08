#include "sculptor.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

Sculptor::Sculptor(int _nx, int _ny, int _nz){
    nx = _nx; ny = _ny; nz = _nz;
    r = 1; g= 1; b = 1;
    v = new Voxel**[nx];
     for (int i =0; i<nx; i++){
      v[i] = new Voxel*[ny];

        for (int j =0; j<ny; j++){
       v[i][j]= new Voxel[nz];
      }
    }
}

Sculptor::~Sculptor(){
    for(int i = 0; i < nx; i++){
        for (int j = 0; j < ny; j++){
            delete[] v[i][j];
        }
    }
    for (int i=0; i <nx; i++){
        delete[] v[i];
    }

    delete[] v;
    nx = 0; ny = 0; nz = 0;
}

void Sculptor::setColor(float r, float g, float b, float a){
    Sculptor::r = r; Sculptor::g = g; Sculptor::b = b; Sculptor::a = a;
}

void Sculptor::putVoxel(int x, int y, int z){
    v[x][y][z].show = true; 
    v[x][y][z].r = r; v[x][y][z].g = g; v[x][y][z].b = b; v[x][y][z].a = a;    

}

void Sculptor::cutVoxel(int x, int y, int z){
    v[x][y][z].show = false;
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
	for(int x = x0; x<x1; x++){
       for (int y = y0; y<y1; y++){
           for (int z = z0; z<z1; z++){
               v[x][y][z].show=true;
               v[x][y][z].r = r;
               v[x][y][z].g = g;
               v[x][y][z].b = b;
               v[x][y][z].a = a;
           }}}}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for(int x = x0; x<x1; x++){
       for (int y = y0; y<y1; y++){
           for (int z = z0; z<z1; z++){
               v[x][y][z].show = false;
           }}}}

void Sculptor::putSphere(int xcentro, int ycentro, int zcentro, int raio){	
  int i, j, k;
  
  for( i = -raio; i<=raio; i++){
      for(j = -raio; j<=raio; j++){
          for(k = -raio; k<=raio; k++){
         
            if ((i*i+j*j+k*k) < raio*raio){
              putVoxel(i+xcentro,j+ycentro,k+zcentro);
            }}}}}

void Sculptor::cutSphere(int xcentro, int ycentro, int zcentro, int raio){
  int i, j, k;
	
  for(i = -raio; i<raio; i++){
      for(j = -raio; j<raio; j++){
          for(k = -raio; k<raio; k++){
            if((i*i+j*j+k*k) < raio*raio){
              cutVoxel(i+xcentro,j+ycentro,k+zcentro);
            }}}}}

void Sculptor::putEllipsoid(int xcentro, int ycentro, int zcentro, int rx, int ry, int rz){
   float newx, newy, newz;
   int x, y, z;

    for ( x = 0; x < nx; x++){
        for ( y = 0; y < ny; y++){
            for ( z = 0; z < nz; z++){
            newx = ((float)(x-xcentro)*(float)(x-xcentro))/(rx * rx);
            newy = ((float)(y-ycentro)*(float)(y-ycentro))/(ry * ry);
            newz = ((float)(z-zcentro)*(float)(z-zcentro))/(rz * rz);
            if ((newx + newy + newz) < 1){
                putVoxel(x,y,z);
            }}}}}

void Sculptor::cutEllipsoid(int xcentro, int ycentro, int zcentro, int rx, int ry, int rz){
   double newx, newy, newz;
   int x, y, z;
   
    for ( x = 0; x < nx; x++){
        for ( y = 0; y < ny; y++){
            for ( z = 0; z < nz; z++){
            newx = ((float)(x-xcentro)*(float)(x-xcentro))/(rx * rx);
            newy = ((float)(y-ycentro)*(float)(y-ycentro))/(ry * ry);
            newz = ((float)(z-zcentro)*(float)(z-zcentro))/(rz * rz);

            if ((newx + newy + newz) < 1){
                cutVoxel(x,y,z);
            }}}}}

void Sculptor::writeOFF(const char *filename){
    int nVoxels = 0;
    int dimensao;
    int  i, j, k, a, b, c;
    float fix = 0.5;
    std::ofstream endArq;
    endArq.open(filename);
    if (endArq.is_open()){
        endArq<<"OFF\n";

        for (i = 0; i < nx; i++){
            for (j = 0; j <ny; j++){
                for (k = 0; k <nz; k++){
                    if(v[i][j][k].show == true){
                    nVoxels++;
                    }}}}
      
        endArq<<nVoxels * 8<<" "<<nVoxels * 6 << " " << "0" << "\n"; 

        for (a = 0; a < nx; a++){
            for (b = 0; b < ny; b++){
                for (c = 0; c < nz; c++){
                    if(v[a][b][c].show == true){
                        endArq << a - fix << " " << b + fix << " " << c - fix << "\n" << flush;
                        endArq << a - fix << " " << b - fix << " " << c - fix << "\n" << flush;
                        endArq << a + fix << " " << b - fix << " " << c - fix << "\n" << flush;
                        endArq << a + fix << " " << b + fix << " " << c - fix << "\n" << flush;
                        endArq << a - fix << " " << b + fix << " " << c + fix << "\n" << flush;
                        endArq << a - fix << " " << b - fix << " " << c + fix << "\n" << flush;
                        endArq << a + fix << " " << b - fix << " " << c + fix << "\n" << flush;
                        endArq << a + fix << " " << b + fix << " " << c + fix << "\n" << flush;
                    }}}}

        nVoxels = 0;

        for (a= 0; a<nx; a++){
            for (b = 0; b<ny; b++){
                for (c= 0; c<nz; c++){
                    if(v[a][b][c].show == true){
                    dimensao = nVoxels * 8;
                    endArq << fixed;

                    endArq << "4" << " " << 0+dimensao << " " << 3+dimensao << " " << 2+dimensao << " " << 1+dimensao << " ";
                    endArq << setprecision(2)<<v[a][b][c].r << " " << setprecision(2)<<v[a][b][c].g <<" " << setprecision(2)<<v[a][b][c].b << " " << setprecision(2) << v[a][b][c].a << "\n";

                    endArq << "4" << " " << 4+dimensao << " " << 5+dimensao << " " << 6+dimensao << " " << 7+dimensao << " ";
                    endArq << setprecision(2)<<v[a][b][c].r << " " << setprecision(2)<<v[a][b][c].g <<" " << setprecision(2)<<v[a][b][c].b << " " << setprecision(2) << v[a][b][c].a << "\n";

                    endArq << "4" << " " << 0+dimensao << " " << 1+dimensao << " " << 5+dimensao << " " << 4+dimensao << " ";
                    endArq << setprecision(2)<<v[a][b][c].r << " " << setprecision(2)<<v[a][b][c].g <<" " << setprecision(2)<<v[a][b][c].b << " " << setprecision(2) << v[a][b][c].a << "\n";

                    endArq << "4" << " " << 0+dimensao << " " << 4+dimensao << " " << 7+dimensao << " " << 3+dimensao << " ";
                    endArq << setprecision(2)<<v[a][b][c].r << " " << setprecision(2)<<v[a][b][c].g <<" " << setprecision(2)<<v[a][b][c].b << " " << setprecision(2) << v[a][b][c].a << "\n";

                    endArq << "4" << " " << 3+dimensao << " " << 7+dimensao << " " << 6+dimensao << " " << 2+dimensao << " ";
                    endArq << setprecision(2)<<v[a][b][c].r << " " << setprecision(2)<<v[a][b][c].g <<" " << setprecision(2)<<v[a][b][c].b << " " << setprecision(2) << v[a][b][c].a << "\n";

                    endArq << "4" << " " << 1+dimensao << " " << 2+dimensao << " " << 6+dimensao << " " << 5+dimensao << " ";
                    endArq << setprecision(2)<<v[a][b][c].r << " " << setprecision(2)<<v[a][b][c].g <<" " << setprecision(2)<<v[a][b][c].b << " " << setprecision(2) << v[a][b][c].a << "\n";

                    nVoxels++;
                    }}}}}
    else{
    cout << "Erro ao executar arquivo de texto.";}
    
    endArq.close();
}
