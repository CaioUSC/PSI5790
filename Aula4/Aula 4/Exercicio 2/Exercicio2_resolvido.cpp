//nn.cpp 2024
#include "procimagem.h"

// Função que calcula a distância Euclidiana quadrada entre duas imagens
// usando a funcção cv::norm do openCV
int distanciaQuadratica(Mat_<uchar> a, Mat_<uchar> b) {
  if (a.total() != b.total()) erro("Erro na comparação de imagens");
  return cv::norm(a, b, cv::NORM_L2); // Calcula a norma L2 (distância Euclidiana)
}

int main() {
  MNIST mnist(14,true,true);
  mnist.le("C:/cekeikon5/tiny_dnn/data");
  int erro = 0;
  double t1=tempo();
  for (int i=0; i<mnist.nq;i++){
	int mindist=INT_MAX;  
	int minsai=0;
    for (int l=0; l<mnist.na; l++){
	  int dist = distanciaQuadratica(mnist.QX[i],mnist.AX[l]);
      if (dist<mindist) { mindist=dist; minsai=mnist.ay(l); }
      if (mindist==0){printf("deu 0"); goto saida;}
    }
	saida: mnist.qp(i)=minsai;
	if (mnist.qp(i) != mnist.qy(i)){erro++;}		
    //saida: printf("%d\n",minsai); printf("%d",mnist.QY[i]); mnist.qp(i)=minsai;
  if(i%100==0) printf("%d Imagens\n",i);
  }
  double t2=tempo();
  printf("Erros=%10.2f%%\n",100.0*mnist.contaErros()/mnist.nq);
  printf("Tempo de processamento: %f\n",t2-t1);
}