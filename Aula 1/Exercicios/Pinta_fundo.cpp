 #include <opencv2/opencv.hpp>
 #include <queue>
 using namespace std; using namespace cv;
Mat_<Vec3b> pintaFundo(Mat_<Vec3b> a, int ls, int cs) {
  Mat_<Vec3b> b=a.clone();
  int rows = b.rows;
  int cols = b.cols;
  queue<int> q;
  q.push(ls); q.push(cs); //(1)
  while (!q.empty()) { //(2)
    int l=q.front(); q.pop(); //(3)
    int c=q.front(); q.pop(); //(3)
    if (b(l,c)==Vec3b(255,255,255)) { //(4)
      b(l,c)=Vec3b(100,100,100); //(5)
	  if(l!=0){	
      q.push(l-1); q.push(c); //6-acima
      }
	  if(l!=b.rows-1){
	  q.push(l+1); q.push(c); //6-abaixo
	  }
	  if(c!=b.cols-1){
      q.push(l); q.push(c+1); //6-direita
      }
	  if(c!=0){
	  q.push(l); q.push(c-1); //6-esq
	  }	
	}
  }
  return b;
 }
 
  int main() {
	  Mat_<Vec3b> a=imread("c2.bmp",1);
	  Mat_<Vec3b> b=pintaFundo(a,1,1);
	  imwrite("fila.png",b);
 }