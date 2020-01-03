#include<opencv2\opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv; 
void  changeImg(int ,void *);

Mat src,srcGray;
int kenel=1,kenelMax=20;

int main()
{
	src = imread("e:\\lena.jpg",1);
	imshow("src",src);
	GaussianBlur(src,src,Size(3,3),0,0,BORDER_DEFAULT);
	imshow("高斯滤波后的src",src);
	cvtColor(src,srcGray,COLOR_RGB2GRAY);
	imshow("灰度化的src",src);
	namedWindow("sobel算法实现");
	createTrackbar("核的大小","sobel算法实现",&kenel,kenelMax,changeImg);
	waitKey(0);
	return 0;
}
void  changeImg(int ,void *)
{
	kenel=kenel*2+1;
	if(kenel==0||kenel==1)
		kenel=3;
	Mat grad_x,grad_y,abs_grad_x,abs_grad_y,dst;
	Sobel(srcGray,grad_x,CV_16S,1,0,kenel,1,1,BORDER_DEFAULT);
	convertScaleAbs(grad_x,abs_grad_x);
	imshow("X方向的sobel",abs_grad_x);

	Sobel(srcGray,grad_y,CV_16S,1,0,kenel,1,1,BORDER_DEFAULT);
	convertScaleAbs(grad_y,abs_grad_y);
	imshow("Y方向的sobel",abs_grad_y);

	addWeighted(abs_grad_x,0.5,abs_grad_y,0.5,0,dst);
	imshow("sobel算法实现",dst);
	cout<<"算子大小为"<<kenel<<"*"<<kenel<<endl;
	waitKey(0);
}