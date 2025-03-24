//mediana_ocv.cpp - 2024
 #include <opencv2/opencv.hpp>
 using namespace std;
 using namespace cv;
 
 int main(){
	 Mat_<uchar> a = imread("ruido.png",0);
	 Mat_<uchar> b;
	 medianBlur(a,b,3);
	 imwrite("Medianaocv.png",b);
 }