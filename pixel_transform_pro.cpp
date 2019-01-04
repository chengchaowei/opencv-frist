#include <iostream> // for standard I/O
#include <string>   // for strings
#include <iomanip>  // for controlling float print precision
#include <sstream>  // string to number conversion
#include <opencv2/core/core.hpp>        // Basic OpenCV structures (cv::Mat, Scalar)
#include <opencv2/highgui/highgui.hpp>  // OpenCV window I/O

using namespace cv;
using namespace std;

Mat pixel_transform_fun(Mat src,double alpha,double bate) {

	Mat new_image = Mat::zeros(src.size(), src.type());
	uchar* p;
	for (int i = 0; i < src.rows; ++i) {
		p = src.ptr<uchar>(i);
		for (int j = 0; j < (src.cols*3); ++j) {
			p[j] = alpha*p[j] + bate;
		}
	}
	return src;
}


//int main(int argc, char**argv){
//	cout << "�����������ƫ�ò�����"<<endl;
//	double input1,input2;
//	cin >> input1 >> input2;
//	if (input1 <= 0) {
//		input1 = 0;
//	}
//	namedWindow("old_picture", 1);
//	namedWindow("new_picture", 1);
//	//��ȡ����ǰ��Ƭ
//	Mat src = imread("1.jpg");
//	imshow("old_picture", src);
//	//�����Ժ�
//	imshow("new_picture",pixel_transform_fun(src, input1, input2));	
//	waitKey(0);
//
//}