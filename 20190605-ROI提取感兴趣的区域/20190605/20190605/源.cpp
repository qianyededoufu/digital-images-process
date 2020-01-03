#include<opencv2\opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;  
int min(){
	Mat src=imread("E:\\lena.jpg",1);
	if(src.empty()){
		cerr<<"can't open image"<<endl;
	}
	imshow("show",src);
	Mat roiImage(src.size(),CV_8UC3);
	src(Rect(10,10,20,300)).copyTo(roiImage);
	imshow("roi",roiImage);
	waitKey(0);
	system("pause");
	return 0;
}
