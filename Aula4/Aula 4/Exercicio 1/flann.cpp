#include "procimagem.h"

int main() {
  // Carregar as imagens de treino e teste
  Mat_<uchar> ax = imread("janei.png", 0); // treino imagem em escala de cinza
  Mat_<uchar> ay = imread("janei-1.png", 0); // treino
  Mat_<uchar> qx = imread("julho.png", 0); // teste

  // Verificar se as dimensões das imagens de treino são iguais
  if (ax.size() != ay.size()) erro("Erro dimensao");

  // Criar a imagem de saída com as mesmas dimensões da imagem de teste
  Mat_<uchar> qp(qx.rows, qx.cols);

  // Criar as estruturas de dados para alimentar o OpenCV
  Mat_<float> features(ax.rows * ax.cols, 1);
  Mat_<int> saidas(ax.rows * ax.cols, 1);
  int i = 0;

  // Preencher as estruturas de dados com os valores das imagens de treino
  for (int l = 0; l < ax.rows; l++) {
    for (int c = 0; c < ax.cols; c++) {
      features(i, 0) = ax(l, c) / 255.0f; // Normalizar o valor do pixel
      saidas(i) = ay(l, c); // Valor do pixel na imagem de saída
      i++;
    }
  }

  // Criar o índice FLANN com os dados de treino
  flann::Index ind(features, flann::KDTreeIndexParams(32));

  // Estrutura para armazenar a consulta e os resultados
  Mat_<float> query(1, 1);
  vector<int> indices(1);
  vector<float> dists(1);

  // Realizar a previsão para cada pixel da imagem de teste
  for (int l = 0; l < qp.rows; l++) {
    for (int c = 0; c < qp.cols; c++) {
      query(0, 0) = qx(l, c) / 255.0f; // Normalizar o valor do pixel
      // Realizar a busca do vizinho mais próximo
      ind.knnSearch(query, indices, dists, 1, flann::SearchParams(0));
      // Atribuir o valor previsto ao pixel da imagem de saída
      qp(l, c) = saidas(indices[0]);
    }
  }

  // Salvar a imagem de saída
  imwrite("f1-flann.png", qp);

  return 0;
}