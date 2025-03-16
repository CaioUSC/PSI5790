//Elimina_ruido_sal_pimenta.cpp
 #include <opencv2/opencv.hpp>
 using namespace std;
 using namespace cv;
 int main() {
  Mat_<uchar> a=imread("eliminaruibrpr3.bmp",0);
  Mat_<uchar> b(a.rows,a.cols);
  for (int l=0; l<a.rows-1; l++)
    for (int c=0; c<a.cols-1; c++)
      if (a(l,c)==255 && a(l,c-1)==0 && a(l-1,c) ==0)
        b(l,c)=0; 
	  else
		if (a(l,c)==0 && a(l,c-1)==255 && a(l-1,c) ==255)
			b(l,c)=255;
		else	
			b(l,c)=a(l,c);			
  imwrite("eliminaruibrpr4.bmp",b);
 }
