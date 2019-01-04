//#include <iostream> // for standard I/O
//#include <string>   // for strings
//#include"Params.h"
//#include <iomanip>  // for controlling float print precision
//#include <sstream>  // string to number conversion
//#include <opencv2/core/core.hpp>        // Basic OpenCV structures (cv::Mat, Scalar)
//#include <opencv2/highgui/highgui.hpp>  // OpenCV window I/O
//using namespace std;
//using namespace cv;
//
//int lapla_opreator1[] = { 0, -1, 0,
//					      -1, 4, -1,
//					      0, -1, 0, };
//int lapla_opreator2[] = { -1, -1, -1,
//						 -1, 8, -1,
//						 -1, -1, -1,};
//int lapla_opreator3[] = { 1, -2, 1,
//						 -2, 1, -2,
//						  1, -2, 1,};
//
////设定阈值，二值化图像
////Mat threhold_function(Mat &image, int thresh, int type) {
////	int row, col;
////	row = image.rows;
////	col = image.cols;
////	uchar *src_test;
////	for (int i = 0; i < row; i++) {
////		src_test = image.ptr<uchar>(i);
////		for (int j = 0; j < col * 3; j++) {
////			switch (type)
////			{
////			case 2:
////				if (src_test[j] < thresh) {
////					src_test[j] = LOW;
////				}
////				else {
////					src_test[j] = HIGH;
////				}
////			default:
////				if (src_test[j] < thresh) {
////					src_test[j] = HIGH;
////				}
////				else {
////					src_test[j] = LOW;
////				}
////			}
////		}
////	}
////	return image;
////}
//
//Mat laplacian_function(Mat image, int lapla[9]) {
//	int row, col;
//	float amp = 3;
//	row = image.rows;
//	col = (image.cols)*3;
//	for (int i = 1; i < row-1; i++) {
//		for (int j = 1; j < col-1; j++) {
//			uchar d0 = image.ptr<uchar>(i - 1)[j - 1];
//			uchar d1 = image.ptr<uchar>(i - 1)[j];
//			uchar d2 = image.ptr<uchar>(i - 1)[j + 1];
//			uchar d3 = image.ptr<uchar>(i)[j - 1];
//			uchar d4 = image.ptr<uchar>(i)[j];
//			uchar d5 = image.ptr<uchar>(i)[j + 1];
//			uchar d6 = image.ptr<uchar>(i + 1)[j - 1];
//			uchar d7 = image.ptr<uchar>(i + 1)[j];
//			uchar d8 = image.ptr<uchar>(i + 1)[j + 1];
//			float zz = (d0*lapla[0] + d1*lapla[1] + d2*lapla[2] + d3*lapla[3] + d4*lapla[4] 
//				+ d5*lapla[5] + d6*lapla[6]+ d7*lapla[7] + d8*lapla[8]);
//			int d = int((amp*zz) + 128.0);
//			if (d < 0){
//				d = 0;
//			}
//			if (d > 255){
//				d = 255;
//			}
//			image.ptr<uchar>(i)[j] = uchar(d);
//		}
//	}
//	return image;
//}

//int main(int argc, char**argv) {
//	Mat src;
//	namedWindow("test",1);
//	src = imread("3.jpg");
//	//laplacian_function(src, lapla_opreator1);
//	//laplacian_function(src, lapla_opreator2);
//	laplacian_function(src, lapla_opreator1);
//	imshow("test", src);
//	waitKey(0);
//	//src = threhold_function(src, 180, 2);
//	imshow("test", src);
//	waitKey(0);
//	return 0;
//}

