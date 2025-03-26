//exercio_1.cpp
#include "procimagem.h"

int main() {
	//pontos na imagem de entrada
  Mat_<float> src = (Mat_<float>(4,2) <<
    138,36,
    319,25,
    113,320,
    354,320);
    // pontos que queremos na imagem de saida
  Mat_<float> dst = (Mat_<float>(4,2) <<
    121,29,
    347,29,
    122,318,
    349,318);
  Mat_<double> m=getPerspectiveTransform(src,dst);
  cout << m << endl;

  //Corrige a perspectiva
  Mat_<Vec3b> a=imread("calib_result.jpg",1);
  Mat_<Vec3b> b;
  warpPerspective(a,b,m,a.size());
  imwrite("Resultado.jpg",b);

}
