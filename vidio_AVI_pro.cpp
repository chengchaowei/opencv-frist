//#include<highgui.h>
//
//int main(int argc, char**argv)
//{
//	cvNamedWindow("vidio_AVI", CV_WINDOW_AUTOSIZE);
//	CvCapture* capture = cvCreateFileCapture(argv[1]);
//	IplImage* frame;
//	while (1)
//	{
//		frame = cvQueryFrame(capture);
//		if (!frame)
//			break;
//		cvShowImage("vidio_AVI", frame);
//		cvWaitKey(2000);
//		cvReleaseCapture(&capture);
//		cvDestroyWindow("vidio_AVI");
//	}
//
//}