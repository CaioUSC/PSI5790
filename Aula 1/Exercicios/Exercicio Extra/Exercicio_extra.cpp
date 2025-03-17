//Exercicio Extra
// Passos
// Pintar o fundo de uma cor diferente de branco Utilizando a tecnica de semente
// Percorrer a imagem encontrar pixel pretos 
#include <iostream>
#include <vector>
#include <queue>
#include <opencv2/opencv.hpp>
 using namespace std;
 using namespace cv;
 int CountElementos(Mat_<uchar> a, int ls, int cs) {
  int count;	 
  queue<int> q;
  q.push(ls); q.push(cs); //(1)
  while (!q.empty()) { //(2)
    int l=q.front(); q.pop(); //(3)
    int c=q.front(); q.pop(); //(3)
    if (a(l,c)==0) { //(4)
      a(l,c)=255; //(5)
      q.push(l-1); q.push(c); //6-acima
      q.push(l+1); q.push(c); //6-abaixo
      q.push(l); q.push(c+1); //6-direita
      q.push(l); q.push(c-1); //6-esq
    }
  }
 }
 int main() {
  int count = 0;	 
  Mat_<uchar> a=imread("c32.bmp",1);
  for (int l=1; l<a.rows-1; l++)
	for (int c=1; c<a.cols-1; c++)
		if(a(l,c)==0){
		CountElementos(a,l,c);
		count++;
		}
  cout << "Número de componentes conexos: " << count << endl;
 }