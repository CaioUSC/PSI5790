#include <iostream>
#include <vector>
#include <queue>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void bfs(Mat& image, Mat& visited, int x, int y) {
    int rows = image.rows;
    int cols = image.cols;
    queue<pair<int, int>> q;
    q.push({x, y});
    visited.at<uchar>(x, y) = 1;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && image.at<uchar>(nx, ny) == 255 && visited.at<uchar>(nx, ny) == 0) {
                visited.at<uchar>(nx, ny) = 1;
                q.push({nx, ny});
            }
        }
    }
}

int countConnectedComponents(Mat& image) {
    int rows = image.rows;
    int cols = image.cols;
    Mat visited = Mat::zeros(rows, cols, CV_8U);
    int count = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (image.at<uchar>(i, j) == 255 && visited.at<uchar>(i, j) == 0) {
                bfs(image, visited, i, j);
                ++count;
            }
        }
    }

    return count;
}

int main() {
    // Carrega a imagem em escala de cinza
    Mat image = imread("letras.bmp", IMREAD_GRAYSCALE);

    if (image.empty()) {
        cout << "Não foi possível carregar a imagem!" << endl;
        return -1;
    }

    // Binariza a imagem (assumindo que a imagem já está em binário)
    threshold(image, image, 128, 255, THRESH_BINARY);

    int components = countConnectedComponents(image);
    cout << "Número de componentes conexos: " << components << endl;

    return 0;
}