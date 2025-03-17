//Elimina_ruido_sal_pimenta.cpp
 #include <opencv2/opencv.hpp>
 using namespace std;
 using namespace cv;
 int main() {
  Mat_<uchar> a=imread("mickeyr.bmp",0);
  Mat_<uchar> b(a.rows,a.cols);
  int soma,l;
  double mean;
  for (int l=1; l<a.rows-1; l++)
    for (int c=1; c<a.cols-1; c++){
		soma = a(l-1,c-1) + a(l-1,c) + a(l-1,c+1) + a(l,c-1) + a(l,c) + a(l,c+1) + a(l+1,c-1) + a(l+1,c) +(l+1,c+1);
		mean = soma/9;
		if (mean >= 127)
			b(l,c) = 255;
		else
			b(l,c) = 0;
	}
  imwrite("eliminaruibrpr.bmp",b);
 }
 
