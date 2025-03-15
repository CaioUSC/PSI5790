//Elimina_ruido_sal.cpp
 #include <opencv2/opencv.hpp>
 using namespace std;
 using namespace cv;
 int main() {
  Mat_<uchar> a=imread("mickeyruibr.bmp",0);
  Mat_<uchar> b(a.rows,a.cols);
  for (int l=0; l<a.rows-1; l++)
    for (int c=0; c<a.cols-1; c++)
      if (a(l,c)==255 && a(l,c+1)==0 && a(l+1,c) ==0)
        b(l,c)=0;
	  else
		b(l,c)=a(l,c);  
  imwrite("eliminaruibr.bmp",b);
 }