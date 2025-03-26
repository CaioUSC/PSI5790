//linear.cpp - 2024
#include "procimagem.h"
int main(int argc, char** argv) {
  if (argc!=5) {
    printf("linear: Muda resolucao de imagem usando interpolacao bilinear.\n");
    printf("linear ent.pgm sai.pgm nl nc\n");
    erro("Erro: Numero de argumentos invalido");
  }
  Mat_<uchar> a=imread(argv[1],0); if (a.total()==0) erro("Erro leitura");
  int nl,nc;
  // Entrada e o numero de linha e colunas
  if (sscanf(argv[3],"%d",&nl)!=1) erro("Erro: Leitura nl");
  if (sscanf(argv[4],"%d",&nc)!=1) erro("Erro: Leitura nc");
  Mat_<uchar> b(nl,nc);
  for (int l=0; l<b.rows; l++)
    for (int c=0; c<b.cols; c++) {
	  // Calcula distancias 	
      double ald = l * ((a.rows-1.0)/(b.rows-1.0));
      double acd = c * ((a.cols-1.0)/(b.cols-1.0));
      int fal=int(ald); int fac=int(acd);
      // distancia linha e distancia coluna
      double dl=ald-fal; double dc=acd-fac;
	  // Calcula os pesos	
      double p1=(1-dl)*(1-dc);
      double p2=(1-dl)*dc;
      double p3=dl*(1-dc);
      double p4=dl*dc;
      // cvRound mesma coisa que o Round mas do OpenCV
      b(l,c)= cvRound(
                p1*a(fal,fac)   + p2*a(fal,fac+1)  +
                p3*a(fal+1,fac) + p4*a(fal+1,fac+1)
              );
    }
  imwrite(argv[2],b);
}
