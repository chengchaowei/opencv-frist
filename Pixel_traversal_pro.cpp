#include <iostream> // for standard I/O
#include <string>   // for strings
#include <iomanip>  // for controlling float print precision
#include <sstream>  // string to number conversion
#include <opencv2/core/core.hpp>        // Basic OpenCV structures (cv::Mat, Scalar)
#include <opencv2/highgui/highgui.hpp>  // OpenCV window I/O

using namespace cv;
using namespace std;


Mat &pixel_tral(Mat &src)//, const uchar* const table)
{
	CV_Assert(src.depth() != sizeof(uchar));
	int channels = src.channels();
	int nRows = src.rows;
	int nCols = src.cols*channels;
	if (src.isContinuous())
	{
		nCols *= nRows;
		nRows = 1;
	}
	uchar *p;
	for (int i = 0; i < nRows; ++i)
	{
		p = src.ptr<uchar>(i);
			for (int j=0; j < (nCols/2);)
			{
				//p[j] = table[p[j]];
				for (int k = 0; k < 3; ++k) {
					int pix = p[j+k];
					p[j+k] = p[nCols - j-(2-k)];
					p[nCols - j - (2 - k)] = pix;
				}
				j  = j + 3;
			}
	}
	return src;
}

//int main(int args, char** argv)
//{
//	Mat src1 = imread("1.jpg");
//	//uchar table[256*3];
//	//for (int i = 0; i < 256; ++i)
//	//{
//	//	if (i < 100) {
//	//		table[i] = 0;
//	//		table[i * 3 + 1] = 50;
//	//		table[i * 3 + 2] = 50;
//	//	}
//	//	if (i >= 100 && i < 200) {
//	//		table[i] = 100;
//	//		table[i * 3 + 1] = 150;
//	//		table[i * 3 + 2] = 150;
//	//	}
//	//	if (i > 200) {
//	//		table[i] = 200;
//	//		table[i * 3 + 1] = 250;
//	//		table[i * 3 + 2] = 250;
//	//	}
//	//}
//	namedWindow("old_pix", 1);
//	imshow("old_pix", src1);
//	waitKey(0);
//
//	//imshow("old_pix", pixel_tral(src1, table));
//	imshow("old_pix", pixel_tral(src1));
//	waitKey(0);
//}
