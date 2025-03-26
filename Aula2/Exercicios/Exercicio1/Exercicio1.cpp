//mediana_ocv.cpp - 2024
 #include <opencv2/opencv.hpp>
 using namespace std;
 using namespace cv;
 
 int main(){
	 // Aplica um filtro medianBlur com janela 5x5
	 Mat_<uchar> a = imread("fever-1.pgm",0);
	 Mat_<uchar> b;
	 medianBlur(a,b,5);
	 imwrite("fever1Mediana.png",b);
	 // Aplica um filtro medianBlur com janela 11x11
	 Mat_<uchar> c = imread("fever-2.pgm",0);
	 Mat_<uchar> d;
	 medianBlur(c,d,11);
	 imwrite("fever2Mediana.png",d);
 }