#include<opencv2\opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int myLaplacian(){
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
	Mat grad;
	Laplacian(srcGray,grad,CV_16S,3,1,0,BORDER_DEFAULT);
	convertScaleAbs(grad,grad);
	imshow("X�����scharr",grad);

	imshow("���巽��",grad);
	waitKey(0);
	return 0;
}