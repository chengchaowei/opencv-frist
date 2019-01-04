#include <iostream> // for standard I/O
#include <string>   // for strings
#include <iomanip>  // for controlling float print precision
#include <sstream>  // string to number conversion
#include <opencv2/core/core.hpp>        // Basic OpenCV structures (cv::Mat, Scalar)
#include <opencv2/highgui/highgui.hpp>  // OpenCV window I/O
#include<algorithm>

using namespace std;
using namespace cv;

Mat smooth_function(Mat image) {//均值滤波，也叫滑窗滤波，移动平均法
	int row, col;
	row = image.rows;
	col = (image.cols)*3;
	for (int i = 1; i < row-1; i++) {
		for (int j = 1; j < col - 1; j++) {
			uchar p0 = image.ptr<uchar>(i - 1)[j - 1];
			uchar p1 = image.ptr<uchar>(i - 1)[j];
			uchar p2 = image.ptr<uchar>(i - 1)[j + 1];
			uchar p3 = image.ptr<uchar>(i)[j - 1];
			uchar p4 = image.ptr<uchar>(i)[j];
			uchar p5 = image.ptr<uchar>(i)[j + 1];
			uchar p6 = image.ptr<uchar>(i + 1)[j - 1];
			uchar p7 = image.ptr<uchar>(i + 1)[j];
			uchar p8 = image.ptr<uchar>(i + 1)[j + 1];
			int zz = int((p0 + p1 + p2 + p3 + p4 + p5 + p6 + p7 + p8) / 9);
			image.ptr<uchar>(i)[j] = (uchar)zz;
		}
	}
	return image;
}


Mat median_function(Mat image) {
	int row, col;
	uchar pixs[9];
	row = image.rows;
	col = (image.cols) * 3;
	for (int i = 1; i < row - 1; i++) {
		for (int j = 1; j < col - 1; j++) {
			int p[9];
			uchar pixs[9];
			pixs[0] = { image.ptr<uchar>(i - 1)[j - 1] };
			pixs[1] = { image.ptr<uchar>(i - 1)[j] };
			pixs[2] = { image.ptr<uchar>(i - 1)[j + 1] };
			pixs[3] = { image.ptr<uchar>(i)[j - 1] };
			pixs[4] = { image.ptr<uchar>(i)[j] };
			pixs[5] = { image.ptr<uchar>(i)[j + 1] };
			pixs[6] = { image.ptr<uchar>(i + 1)[j - 1] };
			pixs[7] = { image.ptr<uchar>(i + 1)[j] };
			pixs[8] = { image.ptr<uchar>(i + 1)[j + 1] };
			for (int k = 0; k < 9; k++) {
				p[k] = int(pixs[k]);
			}
			sort(p,p+8);
			image.ptr<uchar>(i)[j] = (uchar)p[4];
		}
	}
	return image;
}

//int main(int argc, char**argv) {
//	Mat src;
//	namedWindow("test", 1);
//	src = imread("5.jpg");
//	//smooth_function(src);
//	median_function(src);
//	imshow("test", src);
//	waitKey(0);
//	return 0;
//}