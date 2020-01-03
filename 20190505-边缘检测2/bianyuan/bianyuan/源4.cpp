#include<opencv2\opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

void  changeImg(int, void *);

Mat srcGray,dst;
int n=1,maxN=50;

int main(){
	Mat src=imread("d:\\shuiguo.png",1);
	if(!src.data){
		cout<<"ERROR!"<<endl;
		return -1;
	}
	imshow("src",src);
	Mat srcGray,dst;
	GaussianBlur(src,src,Size(3,3),0,0,BORDER_DEFAULT);
	imshow("高斯滤波后的src",src);
	cvtColor(src,srcGray,COLOR_RGB2GRAY);
	imshow("灰度图像",srcGray);
	namedWindow("边缘");
	createTrackbar("阈值大小", "边缘", &n, maxN,changeImg);
	Canny(srcGray, dst, 15,45, 3);
	imshow("边缘", dst);
	waitKey(0);
	system("pause");
	return 0;
}

void  changeImg(int, void *){

}
