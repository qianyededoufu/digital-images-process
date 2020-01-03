#include<opencv2\opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int mySobel1(){
	Mat src=imread("e:\\chaijing.jpg",1);
	if(!src.data){
		cout<<"ERROR!"<<endl;
		return -1;
	}
	imshow("src",src);
	Mat srcGray,dst;
	GaussianBlur(src,src,Size(3,3),0,0,BORDER_DEFAULT);
	imshow("��˹�˲����src",src);
	cvtColor(src,srcGray,COLOR_RGB2GRAY);
	Mat gradX,gradY;
	Scharr(srcGray,gradX,CV_16S,1,0,1,0,BORDER_DEFAULT);
	convertScaleAbs(gradX,gradX);
	imshow("X�����scharr",gradX);

	Scharr(srcGray,gradY,CV_16S,1,0,1,0,BORDER_DEFAULT);
	convertScaleAbs(gradY,gradY);
	imshow("Y�����scharr",gradY);
	addWeighted(gradX,0.5,gradY,0.5,0,dst);
	imshow("���巽��",dst);
	waitKey(0);
	return 0;
}