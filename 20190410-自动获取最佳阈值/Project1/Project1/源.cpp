
/**
#include <iostream> 
#include <opencv2\opencv.hpp> 
using namespace std;
using namespace cv;

void changeimg(int ,void *);

Mat  srcgray ;
Mat dst;
int thresh=0;
int maxValue=255;
int leixing,maxLeixing=4;
int main()
 {
	 Mat src=imread("e:\\bike.jpg",1);
	if (!src.data) { cout << "error" << endl; return -1; }
	imshow("src",src);
	cout<<"请输入阈值"<<endl;

	cvtColor(src,srcgray,COLOR_RGB2GRAY);
	Mat dst(srcgray.rows,srcgray.cols,CV_8UC1);	
	threshold(srcgray,dst,thresh,maxValue,THRESH_BINARY);
	imshow("THRESH_BINARY", dst);

	int maxThresh=255;
	namedWindow("THRESH_BINARY");
	createTrackbar("阈值","THRESH_BINARY",&thresh,maxThresh,changeimg);
	createTrackbar("类型","THRESH_BINARY",&leixing,maxLeixing,changeimg);

	waitKey(0);
	system("pause");
	return 0;
}
void changeimg(int ,void *)
{   
	threshold(srcgray,dst,thresh,maxValue,leixing);
	imshow("THRESH_BINARY", dst);	
}

**/