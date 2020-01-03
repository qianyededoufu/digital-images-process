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
		cout<<"����a ͼ��ƽ��-����b ͼ������-����c ͼ��ת dͼ����ת"<<endl;
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
	cout<<"������X��ͼ��ƫ��"<<endl;
	cin>>x;
	cout<<"������Y��ͼ��ƫ��"<<endl;
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
	cout<<"���������ű���"<<endl;
	cin>>n;
	resize(src,dst,Size(src.cols/n,src.rows/n));
	imshow("src",src);
	imshow("dst",dst);
	waitKey(5000);
	return dst;
}
Mat imgFlip(Mat src){
	Mat dst;
	cout<<"������һ������ 0ΪX�ᷭת ����ΪY�ᷭת ����ΪXY��ͬʱ��ת"<<endl;
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
	cout<<"�����뷭ת�Ƕ�"<<endl;
	cin>>n;
	Point2f center(src.cols/2,src.rows/2);
	Mat rot=getRotationMatrix2D(center,n,1.0);
	warpAffine(src,dst,rot,dst.size());
	imshow("src",src);
	imshow("dst",dst);
	waitKey(5000);
	return dst;
}
