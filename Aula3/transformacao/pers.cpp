//pers.cpp grad-2018
#include "procimagem.h"

int main() {
	//pontos na imagem de entrada
  Mat_<float> src = (Mat_<float>(4,2) <<
    73,0,
    533,0,
    -22,479,
    629,479);
    // pontos que queremos na imagem de saida
  Mat_<float> dst = (Mat_<float>(4,2) <<
    16,0,
    630,0,
    14,479,
    630,479);
  Mat_<double> m=getPerspectiveTransform(src,dst);
  cout << m << endl;
  //Verifica se a transformacao esta fazendo o que queremos usando a coordenada -22,479
  Mat_<double> v=(Mat_<double>(3,1) << -22,479,1);
  Mat_<double> w=m*v;
  cout << w << endl;
  // normaliza dividindopela terceira coodernada
  cout << w(0)/w(2) << " " << w(1)/w(2) << endl;

  //Corrige a perspectiva
  Mat_<Vec3b> a=imread("ka0.jpg",1);
  Mat_<Vec3b> b;
  warpPerspective(a,b,m,a.size());
  imwrite("ka1.jpg",b);

  //Refaz a perspectiva
  // calcula a matriz inversa inv()
  m=m.inv();
  warpPerspective(b,b,m,b.size());
  imwrite("ka2.jpg",b);
}
