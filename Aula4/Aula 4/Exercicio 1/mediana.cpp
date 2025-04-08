//mediana_ocv.cpp - 2024
 #include <opencv2/opencv.hpp>
 using namespace std;
 using namespace cv;
 
 int main(){
	 // Aplica um filtro medianBlur com janela 5x5
	 Mat_<uchar> a = imread("qpnn.pgm",0);
	 Mat_<uchar> b;
	 medianBlur(a,b,19);
	 imwrite("Mediana19.png",b);
	 // Aplica um filtro medianBlur com janela 11x11
	 Mat_<uchar> c = imread("qpnn.pgm",0);
	 Mat_<uchar> d;
	 medianBlur(c,d,21);
	 imwrite("Mediana21.png",d);
 }