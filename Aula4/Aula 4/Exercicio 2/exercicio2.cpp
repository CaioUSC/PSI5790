#include "procimagem.h"
int main(){
 MNIST mnist(14,true,true); //redimensiona imagens para 14
 //inverte preto/branco=true,
 //crop bounding box=false
  mnist.le("C:/cekeikon5/tiny_dnn/data");
  mnist.qp.setTo(10); //Coloca uma classificacao errada de proposito
  Mat_<uchar> e=mnist.geraSaidaErros(5,4); //Organiza 10000 imagens em 100 linhas e 100 colunas
  imwrite("visualiza.png",e); //Imprime 10000 imagens-teste como visual.png
  
  int na; // Numero de amostras de treinamento (60000)
  vector< Mat_<uchar> > AX;  // Vetor de 60000 imagens de treinamento 
                             // redimensionadas, com cores invertidas, e com BBox.
  vector<int> AY; // Classificacoes das imagens de treinamento (0 a 9)
  Mat_<float> ax; // Imagens de treinamento convertidos para float, cada imagem por linha. 
  Mat_<float> ay; // Classificacoes das imagens de treinamento convertidas para float (0 a 9)
  int nq; // Numero de imagens testes (10000)
  vector< Mat_<uchar> > QX; // Vetor de imagens de teste
                            // redimensionadas, com cores invertidas, e com BBox.
  vector<int> QY; // Classificacoes das imagens de teste (0 a 9)
  Mat_<float> qx; // Imagens de teste convertidos para FLT, cada imagem numa linha. 
  Mat_<float> qy; // Classificacoes das imagens de teste  (0 a 9)
  Mat_<float> qp; // Matriz ja alocado para colocar as saidas dos algoritmos de aprendizagem.
                  // Matriz tem uma coluna e 10000 linhas.
}