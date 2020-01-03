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
	imshow("��˹�˲����src",src);
	cvtColor(src,srcGray,COLOR_RGB2GRAY);
	imshow("�ҶȻ���src",src);
	namedWindow("sobel�㷨ʵ��");
	createTrackbar("�˵Ĵ�С","sobel�㷨ʵ��",&kenel,kenelMax,changeImg);
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
	imshow("X�����sobel",abs_grad_x);

	Sobel(srcGray,grad_y,CV_16S,1,0,kenel,1,1,BORDER_DEFAULT);
	convertScaleAbs(grad_y,abs_grad_y);
	imshow("Y�����sobel",abs_grad_y);

	addWeighted(abs_grad_x,0.5,abs_grad_y,0.5,0,dst);
	imshow("sobel�㷨ʵ��",dst);
	cout<<"���Ӵ�СΪ"<<kenel<<"*"<<kenel<<endl;
	waitKey(0);
}