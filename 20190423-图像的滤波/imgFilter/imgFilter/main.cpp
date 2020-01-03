#include <iostream> 
#include <opencv2\opencv.hpp> 
using namespace std;
using namespace cv;
void  changeImgF(int ,void *);
void  changeImgJ(int ,void *);
void  changeImgG(int ,void *);
void  changeImgZ(int ,void *);
Mat src,dst;
int i=1,maxValue=10;
int main()
 {
	src=imread("e://digPro//flower.jpg",1);
	imshow("原始图",src);	
	namedWindow("方框滤波");
	createTrackbar("算子大小","方框滤波",&i,maxValue,changeImgF);
	namedWindow("均值滤波");
	createTrackbar("算子大小","均值滤波",&i,maxValue,changeImgJ);
	namedWindow("高斯滤波");
	createTrackbar("算子大小","高斯滤波",&i,maxValue,changeImgG);
	namedWindow("中值滤波");
	createTrackbar("算子大小","中值滤波",&i,maxValue,changeImgZ);
	waitKey(0);
	return 0;
}
void  changeImgF(int ,void *)
{
	int sizeNum=i*2+1;
	boxFilter(src,dst,-1,Size(sizeNum,sizeNum));
	imshow("方框滤波",dst);
	cout<<"算子大小为"<<sizeNum<<"*"<<sizeNum<<endl;
}
void  changeImgJ(int ,void *)
{
	int sizeNum=i*2+1;
	blur(src,dst,Size(sizeNum,sizeNum));
	imshow("均值滤波",dst);
	cout<<"算子大小为"<<sizeNum<<"*"<<sizeNum<<endl;
}
void  changeImgG(int ,void *)
{
	int sizeNum=i*2+1;
	GaussianBlur(src,dst,Size(sizeNum,sizeNum),0,0);
	imshow("高斯滤波",dst);
	cout<<"算子大小为"<<sizeNum<<"*"<<sizeNum<<endl;
}
void  changeImgZ(int ,void *)
{
	int sizeNum=i*2+1;
	if(sizeNum==1||sizeNum==0)
		sizeNum=3;
	medianBlur(src,dst,sizeNum);
	imshow("中值滤波",dst);
	cout<<"算子大小为"<<sizeNum<<"*"<<sizeNum<<endl;
}

