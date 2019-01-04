#include <iostream> // for standard I/O
#include <string>   // for strings
#include"Params.h"
#include <iomanip>  // for controlling float print precision
#include <sstream>  // string to number conversion
#include <opencv2/core/core.hpp>        // Basic OpenCV structures (cv::Mat, Scalar)
#include <opencv2/highgui/highgui.hpp>  // OpenCV window I/O
using namespace std;
using namespace cv;


int main(int argc, char**argv) {
	Mat src;
	namedWindow("test", 1);
	src = imread("9.png");
	imshow("test", src);
	waitKey(0);
	return 0;
}







