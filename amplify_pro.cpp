#include <iostream> // for standard I/O
#include <string>   // for strings
#include"Params.h"
#include <iomanip>  // for controlling float print precision
#include <sstream>  // string to number conversion
#include <opencv2/core/core.hpp>        // Basic OpenCV structures (cv::Mat, Scalar)
#include <opencv2/highgui/highgui.hpp>  // OpenCV window I/O
using namespace std;
using namespace cv;

Mat amplify_function(Mat image) {
	int row = image.rows;
	int col = (image.cols) * 3;
	int amp = 3;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			int pixs = amp*int(image.ptr<uchar>(i)[j]);
			if (pixs > 255){
				pixs = 255;
			}
			image.ptr<uchar>(i)[j] = uchar(pixs);
		}
	}
	return image;
}

Mat range_function(Mat image) {
	int row = image.rows;
	int col = (image.cols) * 3;
	int fmax = 0;
	int fmin = 255;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			int pixs = int(image.ptr<uchar>(i)[j]);
			if (pixs > fmax){
				fmax = pixs;
			}
			if (pixs < fmin) {
				fmin = pixs;
			}
		}
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			image.ptr<uchar>(i)[j] = (uchar)((255 / (fmax - fmin))*(int(image.ptr<uchar>(i)[j]) - fmin));
		}
	}
	return image;
}

Mat plane_function(Mat image) {
	int row = image.rows;
	int col = (image.cols) * 3;
	long pix[256];
	for (int n = 0; n < 256; n++) {
		pix[n] = 0;
	}
	//uchar *src_test;
	for (int i = 0; i < row; i++) {
		//src_test = image.ptr<uchar>(i);
		for (int j = 0; j < col;j++) {	
			int src_test = int(image.ptr<uchar>(i)[j]);
			pix[src_test]++;
		}
	}
	
	//for (int i = 0; i < 256; i++) {
	//	cout << pix[i] << endl;
	//}
	double CDF[256];
	for (int n = 0; n < 256; n++) {
		CDF[n] = 0.0;
	}
	pix[0] = (pix[0] / (row*col));
	CDF[0] = pix[0];
	for (int i = 1; i < 256; i++) {
		double temp = ((pix[i]) / double(row*col));//注意：用double类型，用int类型会丢失掉小数，累计分布函数就是利用小数来计算，不能丢掉小数部分
		CDF[i] = temp + CDF[i - 1];
		cout << CDF[i] << endl;
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			//if ((int(image.ptr<uchar>(i)[j])) > 255){
			//	image.ptr<uchar>(i)[j] = uchar(255);
			//}
			image.ptr<uchar>(i)[j] = (uchar)(255 * (CDF[int(image.ptr<uchar>(i)[j])]));
		}
	}
	return image;
}

//int main(int argc, char**argv) {
//	Mat src;
//	namedWindow("test", 1);
//	src = imread("9.png");
//	//amplify_function(src);
//	//range_function(src);
//	plane_function(src);
//	imshow("test", src);
//	waitKey(0);
//	return 0;
//}