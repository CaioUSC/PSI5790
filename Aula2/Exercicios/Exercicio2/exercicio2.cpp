 // exercicio2.cpp 
 #include "procimagem.h"
 
 Mat_<Vec3f> marca(Mat_<float> a, Mat_<float> p,Mat_<float> pi, float limiar) {
	Mat_<Vec3f> d;
	cvtColor(a,d,COLOR_GRAY2BGR);
	for (int l=0; l<a.rows; l++)
		for (int c=0; c<a.cols; c++){
		if (p(l,c)>=limiar)
			circle(d,Point(c,l),0.5,Scalar(0,0,1),1);
		if (pi(l,c)>=limiar)
			circle(d,Point(c,l),0.5,Scalar(0,0,1),1);		
		}
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
  Mat_<float> pontos = p;
  //Encontra os pontos onde o fundo e o urso tem as cores invertidas do template
  Mat_<float> pontos_invertidos = -1*p;
  //Marca os pontos que cruzam o liminar definido
  resultado = marca(a,pontos,pontos_invertidos,0.75);
  imwrite("resultado.png",255*resultado);
 }