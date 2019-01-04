#include<iostream>
#include"Params.h"
#include <string>   // for strings
#include <iomanip>  // for controlling float print precision
#include <sstream>  // string to number conversion
#include <opencv2/core/core.hpp>        // Basic OpenCV structures (cv::Mat, Scalar)
#include <opencv2/highgui/highgui.hpp>  // OpenCV window I/O

using namespace std;
using namespace cv;

int cx_diff[] = { 0, 0, 0,
				  0, 1, -1,
                  0, 0, 0 };
int cy_diff[] = { 0, 0, 0,
                  0, 1, 1,
                  0, -1, 0 };
int cx_roberts[] = {0, 0, 0,
				    0, 1, 0,
				    0, 0, -1 };
int cy_roberts[] = { 0, 0, 0,
					 0, 0, 1,
					 0, -1, 0 };
int cx_sobel[] = { -1, 0, 1,
				  -2, 1, 2,
				  -1, 0, 1 };
int cy_sobel[] = { -1,-2,-1,	
					0, 0, 0,
					1, 2, 1 };


Mat gradient_function(Mat& image,int cx[9],int cy[9]) {

	int row, col;
	float amp = 1;
	row = image.rows;
	col = image.cols * 3;
	for (int i = 1; i < row-1; i++) {	
		for (int j = 1; j < col-1; j++) {
			uchar d0 = image.ptr<uchar>(i-1)[j-1];
			uchar d1 = image.ptr<uchar>(i-1)[j];
			uchar d2 = image.ptr<uchar>(i-1)[j + 1];
			uchar d3 = image.ptr<uchar>(i)[j - 1];
			uchar d4 = image.ptr<uchar>(i)[j];
			uchar d5 = image.ptr<uchar>(i)[j + 1];
			uchar d6 = image.ptr<uchar>(i + 1)[j - 1];
			uchar d7 = image.ptr<uchar>(i + 1)[j];
			uchar d8 = image.ptr<uchar>(i + 1)[j + 1];
			uchar xx = (d0*cx[0] + d1*cx[1] + d2*cx[2] + d3*cx[3]
				+ d4*cx[4] + d5*cx[5] + d6*cx[6] + d7*cx[7] + d8*cx[8]);
			uchar yy = (d0*cy[0] + d1*cy[1] + d2*cy[2] + d3*cy[3]
				+ d4*cy[4] + d5*cy[5] + d6*cy[6] + d7*cy[7] + d8*cy[8]);
			float zz = (float)sqrt(xx*xx + yy*yy);
			if (zz > 255) {
				zz = 255;
			}
			image.ptr<uchar>(i)[j] = (uchar)(amp*zz);
		}
	}
	return image;
}


//int main(int argc, char**argv) {
//	Mat src;
//	namedWindow("test", 1);
//	src = imread("2.jpg");
//	//gradient_function(src,cx_diff,cy_diff);
//	gradient_function(src, cx_roberts, cy_roberts);
//	//gradient_function(src, cx_sobel, cy_sobel);
//	imshow("test", src);
//	waitKey(0);
//	return 0;
//}