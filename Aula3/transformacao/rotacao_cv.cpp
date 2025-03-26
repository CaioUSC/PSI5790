// rotacao_cv.cpp 2024
#include "procimagem.h"
int main() {
  Mat_<uchar> ent=imread("lennag.jpg",0); 
  Mat_<uchar> sai;
  // cria a matriz de rotação
  Mat_<double> m=getRotationMatrix2D(Point2f(ent.cols/2,ent.rows/2), 30, 1);
  cout << m << endl;
  warpAffine(ent, sai, m, ent.size(), INTER_LINEAR, BORDER_CONSTANT, Scalar(255));
  imwrite("rotacao_cv.jpg",sai);
}
