 // exercicio2.cpp 
 #include "procimagem.h"
 
 Mat_<Vec3f> marca(Mat_<float> a, Mat_<float> p, float limiar) {
	Mat_<Vec3f> d;
	cvtColor(a,d,COLOR_GRAY2BGR);
	for (int l=0; l<a.rows; l++)
		for (int c=0; c<a.cols; c++)
		if (p(l,c)>=limiar)
			rectangle(d,Point(c,l),Point(c,l),Scalar(0.0,0.0,1.0),3);
 return d;
 }
 
 int main() {
  Mat_<float> a=imread("a.png",0);
  a=a/255;
  Mat_<float> q=imread("q.png",0);
  q=q/255;
  Mat_<Vec3f> resultado;
  // Executa template match CCN
  Mat_<float> p=matchTemplateSame(a, q, TM_CCOEFF_NORMED);
  //Encontra os pontos onde o fundo e o urso são iguais o template
  Mat_<float> pontos= p;
  resultado = marca(a,pontos,0.75);
  imwrite("resultado1.png",255*resultado);
  //Encontra os pontos onde o fundo e o urso tem as cores invertidas do template
  Mat_<float> resultado1 = imread("resultado1.png",0);
  resultado1 = resultado1/255;
  Mat_<float> pontos_invertidos = -1*p;
  resultado = marca(resultado1,pontos_invertidos,0.75);
  imwrite("resultado2.png",255*resultado);
 }