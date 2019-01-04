//#include <iostream> // for standard I/O
//#include <string>   // for strings
//#include <iomanip>  // for controlling float print precision
//#include <sstream>  // string to number conversion
//#include <opencv2/core/core.hpp>        // Basic OpenCV structures (cv::Mat, Scalar)
//#include <opencv2/highgui/highgui.hpp>  // OpenCV window I/O
//
//using namespace std;
//using namespace cv;
//
//
//
//Mat &addWeighted_pro(Mat &src1, double alpha, Mat &src2)
//{
//	//uchar pix1 = pixel_traval(src1);
//	//uchar pix2 = pixel_traval(src2);
//	CV_Assert(src1.depth() != sizeof(uchar));
//	CV_Assert(src2.depth() != sizeof(uchar));
//	int nRows1 = src1.rows;
//	int nRows2 = src2.rows;
//	int nCols1 = src1.cols*src1.channels();
//	int nCols2 = src2.cols*src2.channels();
//	if (src1.isContinuous()) {
//		nCols1 *= nRows1;
//		nRows1 = 1;
//	}
//	if (src1.isContinuous()) {
//		nCols2 *= nRows2;
//		nRows2 = 1;
//	}
//	uchar* p1;
//	uchar* p2;
//	for (int i = 0; i < nRows1; ++i) {
//		p1 = src1.ptr<uchar>(i);
//		p2 = src2.ptr<uchar>(i);
//		for (int j = 0; j < nCols1; ++j) {
//			//system("pause");//ÏñËØ²Ù×÷
//			p1[j] = alpha*p2[j]+(1.0 - alpha)*p1[j];
//		}
//	}
//	return src1;
//}

//int main(int argc, char **argv)
//{
//	double alpha = 0.5;
//	double beta;
//	double input;
//	cin >> input;
//	Mat src1, src2, dst;
//	if (alpha >= 0 && alpha <= 1)
//	{
//		alpha = input;
//	}
//	src1 = imread("1.jpg");
//	src2 = imread("2.jpg");
//	namedWindow("oro", 1);
//	addWeighted_pro(src1, alpha, src2);
//	imshow("oro", src1);
//	cvWaitKey(0);
//	return 0;
//
//}

