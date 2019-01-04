#include <iostream> // for standard I/O
#include <string>   // for strings
#include"Params.h"
#include <iomanip>  // for controlling float print precision
#include <sstream>  // string to number conversion
#include <opencv2/core/core.hpp>        // Basic OpenCV structures (cv::Mat, Scalar)
#include <opencv2/highgui/highgui.hpp>  // OpenCV window I/O
using namespace std;
using namespace cv;

int prew[8][9] = {{1,1,1,1,-2,1,-1,-1,-1,}, 
                  {1,1,1,1,-2,-1,1,-1,-1,},
				  {1,1,-1,1,-2,-1,1,1,-1,},
				  {1,-1,-1,1,-2,-1,1,1,1,},
				  {-1,-1,-1,1,-2,1,1,1,1,},
				  {-1,-1,1,-1,-2,1,1,1,1,},
				  {-1,1,1,-1,-2,1,-1,1,1,},
				  {1,1,1,-1,-2,1,-1,-1,1,},
                  };

Mat prewitt_function(Mat image, int prew[8][9]) {
	int row, col;
	row = image.rows;
	col = (image.cols)*3;
	for (int i = 1; i < row-1; i++) {
		for (int j = 1; j < col-1; j++) {
			uchar d0 = image.ptr<uchar>(i - 1)[j - 1];
			uchar d1 = image.ptr<uchar>(i - 1)[j];
			uchar d2 = image.ptr<uchar>(i - 1)[j + 1];
			uchar d3 = image.ptr<uchar>(i)[j - 1];
			uchar d4 = image.ptr<uchar>(i)[j];
			uchar d5 = image.ptr<uchar>(i)[j + 1];
			uchar d6 = image.ptr<uchar>(i + 1)[j - 1];
			uchar d7 = image.ptr<uchar>(i + 1)[j];
			uchar d8 = image.ptr<uchar>(i + 1)[j + 1];
			int temp1 = 0,temp = 0;
			for (int k = 0; k < 8; k++) {
				int zz = int(d0*prew[k][0]+d1*prew[k][1]+d2*prew[k][2]+d3*prew[k][3]+d4*prew[k][4]
					+d5*prew[k][5]+d6*prew[k][6]+d7*prew[k][7]+d8*prew[k][8]);
				temp = zz;
				if (temp > 0 & (temp > temp1)) {
					temp1 = temp;
				}
				if (temp <= 0) {
					temp1 = 0;
				}
			}
			image.ptr<uchar>(i)[j] = (uchar)temp1;
		}
	}
	return image;
}

//int main(int argc, char**argv) {
//	Mat src;
//	namedWindow("test", 1);
//	src = imread("3.jpg");
//	prewitt_function(src, prew);
//	imshow("test", src);
//	waitKey(0);
//	return 0;
//}