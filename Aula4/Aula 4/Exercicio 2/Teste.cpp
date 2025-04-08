//nn.cpp 2024
#include "procimagem.h"


Mat_<uchar> vizinhanca11(Mat_<uchar> a, int lc, int cc) {
    Mat_<uchar> d(1,1);
    d(0) = a(lc, cc);
    return d;
}

int hamming2(Mat_<uchar> a, Mat_<uchar> b) {
 if (a.total()!=b.total()) erro("Erro hamming");
 int soma=0;
 for (int i=0; i<a.total() ; i++)
   if (a(i)!=b(i)) soma++;
 return soma;
}

int hamming(Mat_<uchar> a, Mat_<uchar> b) {
  if (a.total()!=b.total()) erro("Erro hamming");
  int soma=0;
  for (int l=1; l<a.rows - 1 ; l++)
    for (int c=1; c<a.cols-1; c++){
     if (a(l,c)!=b(l,c)) soma++; 
    }
  return soma;
 }

int main() {
  MNIST mnist(14,true,true);
  mnist.le("C:/cekeikon5/tiny_dnn/data");
  int erro = 0;
  for (int i=0; i<mnist.nq;i++){
	int mindist=INT_MAX;  
	int minsai=0;
    for (int l=0; l<mnist.na; l++){
	  int dist = hamming(mnist.QX[i],mnist.AX[l]);
      if (dist<mindist) { mindist=dist; minsai=mnist.AY[l]; }
      if (mindist==0) goto saida;}
    }
	saida: mnist.qp(i)=minsai;
	if (mnist.qp(i) != mnist.QY[i])
		erro++;
		//printf("%d\n",erro);
    printf("%d",minsai); printf("%d",mnist.QY[i]); mnist.qp(i)=minsai;
  }
  printf("\n%d\n",erro);
}