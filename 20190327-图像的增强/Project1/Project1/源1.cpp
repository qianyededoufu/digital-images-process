#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main(){
	char fileName[50];
	cin>>fileName;
	Mat src=imread(fileName,-1);
	imshow("beforeImg",src);
	if(src.channels()==1){
		Mat dstHist;
		equalizeHist(src,dstHist);
		imshow("dstHist",dstHist);
	}else if(src.channels()==3){
		Mat channel[3];
		split(src,channel);//将三通道彩色图片分解为三个独立的通道信息 channel[0] channel[1] channel[2]
		equalizeHist(channel[0],channel[0]);
		equalizeHist(channel[1],channel[1]);
		equalizeHist(channel[2],channel[2]);
		Mat dstHist;
		merge(channel,3,dstHist);
		imshow("dstHist",dstHist);
	}
	waitKey(0);
	system("pause");
	return 0;
}