#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Mat sitePro(Mat src);
Mat reSizeImg(Mat src);
Mat imgFlip(Mat src);
Mat imgX(Mat src);

int main(){
	Mat src=imread("e://qi.jpeg",1);
	Mat dst;
	char a;
	while(1){
		cout<<"输入a 图像平移-输入b 图像缩放-输入c 图像翻转 d图像旋转"<<endl;
		cin>>a;
		if(a=='q'){
			break;
		}
		switch (a)
		{
			case 'a':sitePro(src);
				break;
			case 'b':reSizeImg(src);
				break;
			case 'c':imgFlip(src);
				break;
			case 'd':imgX(src);
				break;

		}
	}
	
	
	return 0;
}
Mat sitePro(Mat src){
	Mat dst;
	float x,y;
	cout<<"请输入X轴图像偏移"<<endl;
	cin>>x;
	cout<<"请输入Y轴图像偏移"<<endl;
	cin>>y;
	Mat m=Mat::zeros(2,3,CV_32FC1);
	m.at<float>(0,0)=1;
	m.at<float>(0,2)=x;
	m.at<float>(1,1)=1;
	m.at<float>(1,2)=y;
	warpAffine(src,dst,m,src.size());
	imshow("src",src);
	imshow("dst",dst);
	waitKey(5000);
	return dst;
}
Mat reSizeImg(Mat src){
	Mat dst;
	int n;
	cout<<"请输入缩放倍数"<<endl;
	cin>>n;
	resize(src,dst,Size(src.cols/n,src.rows/n));
	imshow("src",src);
	imshow("dst",dst);
	waitKey(5000);
	return dst;
}
Mat imgFlip(Mat src){
	Mat dst;
	cout<<"请输入一个数字 0为X轴翻转 正数为Y轴翻转 负数为XY轴同时翻转"<<endl;
	int n;
	cin>>n;
	flip(src,dst,n);
	imshow("src",src);
	imshow("dst",dst);
	waitKey(5000);
	return dst;
}
Mat imgX(Mat src){
	Mat dst(src.rows,src.cols,src.type());
	double n;
	cout<<"请输入翻转角度"<<endl;
	cin>>n;
	Point2f center(src.cols/2,src.rows/2);
	Mat rot=getRotationMatrix2D(center,n,1.0);
	warpAffine(src,dst,rot,dst.size());
	imshow("src",src);
	imshow("dst",dst);
	waitKey(5000);
	return dst;
}
