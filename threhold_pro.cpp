//#include<iostream>
//#include"Params.h"
//#include <string>   // for strings
//#include <iomanip>  // for controlling float print precision
//#include <sstream>  // string to number conversion
//#include <opencv2/core/core.hpp>        // Basic OpenCV structures (cv::Mat, Scalar)
//#include <opencv2/highgui/highgui.hpp>  // OpenCV window I/O
//using namespace cv;
//using namespace std;
//
//画出直方图
//void histPrint_function(long hist[256]) {
//	for (int i = 0; i < 255; i++) {
//		int temp = hist[i];
//		temp = temp / 100;
//		while (temp) {
//			cout << ".";
//			temp--;
//		}
//		cout << endl;
//	}
//}
//设定阈值，二值化图像
//Mat threhold_function(Mat &image, int thresh, int type) {
//	int row, col;
//	row = image.rows;
//	col = image.cols;
//	uchar *src_test;
//	for (int i = 0; i < row; i++) {
//		src_test = image.ptr<uchar>(i);
//		for (int j = 0; j < col * 3; j++) {
//			switch (type)
//			{
//			case 2:
//				if (src_test[j] < thresh) {
//					src_test[j] = LOW;
//				}
//				else {
//					src_test[j] = HIGH;
//				}
//			default:
//				if (src_test[j] < thresh) {
//					src_test[j] = HIGH;
//				}
//				else {
//					src_test[j] = LOW;
//				}
//			}
//		}
//	}
//	return image;
//}
//直方图平滑化
//void histsmooth_function(long hist[256]) {
//	for (int i = 0; i <= 255; i++) {
//		switch (i)
//		{
//		case 0:
//			hist[0] = (0 + 0 + hist[0] + hist[1] + hist[2]) / 5;
//			break;
//		case 1:
//			hist[1] = (0 + hist[0] + hist[1] + hist[2] + hist[3]) / 5;
//			break;
//		case 254:
//			hist[254] = (hist[252] + hist[253] + hist[254] + hist[255] + 0) / 5;
//			break;
//		case 255:
//			hist[255] = (hist[253] + hist[254] + hist[255] + 0 + 0) / 5;
//			break;
//		default:
//			hist[i] = (hist[i - 2] + hist[i - 1] + hist[i] + hist[i + 1] + hist[i + 2])/5;
//			break;
//		}
//	}
//	histPrint_function(hist);
//}
//
//求图像的直方图
//long  histgram_function(Mat &image) {
//	int row, col,n;
//	long hist[256];
//	row = image.rows;
//	col = image.cols;
//	for (int n = 0; n <= 255; n++) {
//		hist[n] = 0;
//	}
//	uchar *src_test;
//	for (int i = 0; i < row; i++) {
//		src_test = image.ptr<uchar>(i);
//		for (int j = 0; j < col * 3;j++) {
//			hist[src_test[j]]++;
//		}
//	}
//	histPrint_function(hist);
//	histsmooth_function(hist);
//	return *hist;
//}

//int main(int argc, char**avgv) {
//	int thresh_input, type_input;
//	//cin >> thresh_input >> type_input;
//	Mat src;
//	//namedWindow("test", 1);
//	src = imread("2.jpg");
//	//threhold_function(src, thresh_input, type_input);
//	histgram_function(src);	
//	//imshow("test", src);
//	//waitKey(0);
//	system("pause");
//	return 0;
//}





