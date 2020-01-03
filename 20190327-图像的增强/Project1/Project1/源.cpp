#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int imgHist(){
	Mat src=imread("e://add2.jpg",1);
	imshow("before",src);
	vector<Mat> channel; // vector<容器类型> 容器名称 vector<Mat> channel;与 Mat channel[3]作用较为相似 容器优势为不固定大小
	// channel[0]; 等价于 channel.at(0);
	split(src,channel);//将三通道彩色图片分解为三个独立的通道信息 channel[0] channel[1] channel[2]
	imshow("before blue",channel[0]);
	imshow("before green",channel[1]);
	imshow("before red",channel[2]);

	/***
	Mat dst;
	cvtColor(src,dst,COLOR_BGR2GRAY);
	imshow("dst",dst);         将目标图像转化为单通道灰度图像

	Mat dstHist;
	equalizeHist(dst,dstHist);
	imshow("dstHist",dstHist);  //将单通道灰度图像直方图均衡化
	**/
	equalizeHist(channel[0],channel[0]);
	equalizeHist(channel[1],channel[1]);
	equalizeHist(channel[2],channel[2]);
	imshow("after blue",channel[0]);
	imshow("after green",channel[1]);
	imshow("after red",channel[2]);

	Mat dstHist;
	//merge(channel,3,dstHist);   //合并三个通道将目标图像存储到dstHist
	merge(channel,dstHist); //使用容器方法只需要两个参数
	imshow("dstHist",dstHist);

	waitKey(0);
	system("pause");
	return 0;
}