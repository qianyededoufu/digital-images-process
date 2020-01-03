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
	imshow("ԭʼͼ",src);	
	namedWindow("�����˲�");
	createTrackbar("���Ӵ�С","�����˲�",&i,maxValue,changeImgF);
	namedWindow("��ֵ�˲�");
	createTrackbar("���Ӵ�С","��ֵ�˲�",&i,maxValue,changeImgJ);
	namedWindow("��˹�˲�");
	createTrackbar("���Ӵ�С","��˹�˲�",&i,maxValue,changeImgG);
	namedWindow("��ֵ�˲�");
	createTrackbar("���Ӵ�С","��ֵ�˲�",&i,maxValue,changeImgZ);
	waitKey(0);
	return 0;
}
void  changeImgF(int ,void *)
{
	int sizeNum=i*2+1;
	boxFilter(src,dst,-1,Size(sizeNum,sizeNum));
	imshow("�����˲�",dst);
	cout<<"���Ӵ�СΪ"<<sizeNum<<"*"<<sizeNum<<endl;
}
void  changeImgJ(int ,void *)
{
	int sizeNum=i*2+1;
	blur(src,dst,Size(sizeNum,sizeNum));
	imshow("��ֵ�˲�",dst);
	cout<<"���Ӵ�СΪ"<<sizeNum<<"*"<<sizeNum<<endl;
}
void  changeImgG(int ,void *)
{
	int sizeNum=i*2+1;
	GaussianBlur(src,dst,Size(sizeNum,sizeNum),0,0);
	imshow("��˹�˲�",dst);
	cout<<"���Ӵ�СΪ"<<sizeNum<<"*"<<sizeNum<<endl;
}
void  changeImgZ(int ,void *)
{
	int sizeNum=i*2+1;
	if(sizeNum==1||sizeNum==0)
		sizeNum=3;
	medianBlur(src,dst,sizeNum);
	imshow("��ֵ�˲�",dst);
	cout<<"���Ӵ�СΪ"<<sizeNum<<"*"<<sizeNum<<endl;
}

