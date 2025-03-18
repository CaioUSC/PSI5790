//Exercicio_Extra.cpp
// Passos
// Pintar o fundo de uma cor diferente de branco Utilizando a tecnica de semente
// Percorrer a imagem encontrar pixel pretos
// Contar quantos buracos existem neste componente preto encontrado
// Usar o primeiro pixel como semente e pintar conforme o numero de buracos encontrados
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
 
Mat_<Vec3b> pintaBorda(Mat_<Vec3b> a,int ls,int cs,int buracos){
	Mat_<Vec3b> b=a.clone(); 
	  queue<int> q;
	  q.push(ls); q.push(cs); //(1)
	  while (!q.empty()) { //(2)
		int l=q.front(); q.pop(); //(3)
		int c=q.front(); q.pop(); //(3)
		if (b(l,c)==Vec3b(1,1,1)) {
		  if (buracos ==0){b(l,c) = Vec3b(0,0,255);}
		  else if (buracos ==1){b(l,c) = Vec3b(0,255,0);}
		  else if (buracos >1){b(l,c) = Vec3b(255,0,0);}
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
 
Mat_<Vec3b> EncontraBuracos(Mat_<Vec3b> a, int ls, int cs) {
      Mat_<Vec3b> b=a.clone(); 
	  queue<int> q;
	  queue<int> qb;
	  int buracos = 0;
	  q.push(ls); q.push(cs); //(1)
	  while (!q.empty()) { //(2)
		int l=q.front(); q.pop(); //(3)
		int c=q.front(); q.pop(); //(3)
		if (b(l,c)==Vec3b(0,0,0)) {
		  b(l,c) = Vec3b(1,1,1);
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
		else if(b(l,c)==Vec3b(255,255,255)){
			qb.push(l); qb.push(c);
			buracos++;
		}
		while(!qb.empty()){
		  int lb=qb.front(); qb.pop(); //(3)
		  int cb=qb.front(); qb.pop(); //(3)	
		  if (b(lb,cb)==Vec3b(255,255,255)){
		  b(lb,cb)=Vec3b(254,254,254); //(5)
		  if(lb!=0){	
		  qb.push(lb-1); qb.push(cb); //6-acima
		  }
		  if(lb!=b.rows-1){
		  qb.push(lb+1); qb.push(cb); //6-abaixo
		  }
		  if(cb!=b.cols-1){
		  qb.push(lb); qb.push(cb+1); //6-direita
		  }
		  if(cb!=0){
		  qb.push(lb); qb.push(cb-1); //6-esq
		  }		
		}
		}	
	  }
	  b = pintaBorda(b,ls,cs,buracos);
	  return b;
 }
 
 int main() {
  Mat_<Vec3b> a=imread("c2.bmp",1);
  Mat_<Vec3b> b=pintaFundo(a,1,1);
      for (int l=1; l<a.rows-1; l++)
		for (int c=1; c<a.cols-1; c++)
		  if(a(l,c)==Vec3b(0,0,0)){
			  b = EncontraBuracos(b,l,c);
		  }
  imwrite("fila.png",b);
 }
 