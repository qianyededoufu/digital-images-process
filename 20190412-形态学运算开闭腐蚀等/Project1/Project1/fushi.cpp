/**
#include <iostream> 
#include <opencv2\opencv.hpp> 
using namespace std;
using namespace cv;
int fushi()
 {
	Mat src=imread("e:\\dog.jpg",1);
	if(!src.data){
		cout<<"ERROR"<<endl;
		return -1;
	}
	imshow("src",src);
	Mat dst;
	namedWindow("����/��ʴ Ч��");
	createTrackbar("�˴�С","����/��ʴ Ч��",&thresh,maxThresh,changeimg);
	imshow("dst",dst);
	waitKey(0);
	system("pause");
	return 0;
}
void changeimg(int ,void *)
{   
	Mat element=getStructuringElement(MORPH_RECT,Size(5,5),Point(-1,-1));
	dilate(src,dst,element);	
}
**/