#include "procimagem.h"

int main() {
  // Carregar as imagens de treino e teste
  Mat_<Vec3b> ax = imread("janei.png", 1); // treino imagem em escala de cinza
  Mat_<uchar> ay = imread("janei-1.png", 0); // treino
  Mat_<Vec3b> qx = imread("julho.png", 1); // teste

  // Verificar se as dimensões das imagens de treino são iguais
  if (ax.size() != ay.size()) erro("Erro dimensao");

  // Criar a imagem de saída com as mesmas dimensões da imagem de teste
  Mat_<uchar> qp(qx.rows, qx.cols);

  // Criar as estruturas de dados para alimentar o OpenCV
  Mat_<float> features(ax.rows * ax.cols, 3);
  Mat_<int> saidas(ax.rows * ax.cols, 1);
  int i = 0;

  // Preencher as estruturas de dados com os valores das imagens de treino
  for (int l=0; l<ax.rows; l++)
    for (int c=0; c<ax.cols; c++) {
      features(i,0)=ax(l,c)[0]/255.0;
      features(i,1)=ax(l,c)[1]/255.0;
      features(i,2)=ax(l,c)[2]/255.0;
      saidas(i)=ay(l,c);
      i=i+1;
    }

    flann::Index ind(features,flann::KDTreeIndexParams(8));
    // Aqui, as 4 arvores estao criadas
  
    Mat_<float> query(1,3);
    vector<int> indices(1);
    vector<float> dists(1);
    for (int l=0; l<qp.rows; l++)
      for (int c=0; c<qp.cols; c++) {
        query(0)=qx(l,c)[0]/255.0;
        query(1)=qx(l,c)[1]/255.0;
        query(2)=qx(l,c)[2]/255.0;
        // Zero indica sem backtracking (Checa os numeros de vizinhos se existe um mais proximo)
        // cor que queremos buscar, '','',numero de vizinhos
        ind.knnSearch(query,indices,dists,1,flann::SearchParams(0));
        qp(l,c)=saidas(indices[0]);
      }
    imwrite("f1-flann.png",qp);
  }