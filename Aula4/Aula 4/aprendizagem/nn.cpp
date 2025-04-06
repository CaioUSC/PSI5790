//nn.cpp 2024
#include "procimagem.h"

// cria um vetor de 1,9 do ponto passado
Mat_<uchar> vizinhanca33(Mat_<uchar> a, int lc, int cc) {
  Mat_<uchar> d(1,9);
  int i=0;
  for (int l=-1; l<=1; l++)
    for (int c=-1; c<=1; c++) {
      d(i)=a(lc+l,cc+c); i++;
    }
  return d;
}
// distancia de hamming (conta quantos pixels são diferentes)
int hamming(Mat_<uchar> a, Mat_<uchar> b) {
  if (a.total()!=b.total()) erro("Erro hamming");
  int soma=0;
  for (int i=0; i<a.total() ; i++)
    if (a(i)!=b(i)) soma++;
  return soma;
}

int main() {
  Mat_<uchar> AX=imread("ax.bmp",0); // Imagem de treino
  Mat_<uchar> AY=imread("ay.bmp",0); // Imagem resposta de treino
  Mat_<uchar> QX=imread("qx.bmp",0); // Imagem de teste
  // preenche com branco para deixar borda branca
  Mat_<uchar> QP(QX.size(),255);
  for (int l=1; l<QP.rows-1; l++) {
    if (l%10==0) printf("%d\n",l);
    for (int c=1; c<QP.cols-1; c++) {
      Mat_<uchar> qx=vizinhanca33(QX,l,c);
      //acha vizinho mais proximo de qx em AX
      int mindist=INT_MAX;
      uchar minsai=0;
      for (int l2=1; l2<AX.rows-1; l2++)
        for (int c2=1; c2<AX.cols-1; c2++) {
          Mat_<uchar> ax=vizinhanca33(AX,l2,c2);
          int dist=hamming(qx,ax);
          if (dist<mindist) { mindist=dist; minsai=AY(l2,c2); }
          if (mindist==0) goto saida;
        }
      saida: QP(l,c)=minsai;
    }
  }
  imwrite("qpnn.pgm",QP);
}
