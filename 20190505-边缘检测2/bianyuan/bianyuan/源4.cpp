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
	imshow("��˹�˲����src",src);
	cvtColor(src,srcGray,COLOR_RGB2GRAY);
	imshow("�Ҷ�ͼ��",srcGray);
	namedWindow("��Ե");
	createTrackbar("��ֵ��С", "��Ե", &n, maxN,changeImg);
	Canny(srcGray, dst, 15,45, 3);
	imshow("��Ե", dst);
	waitKey(0);
	system("pause");
	return 0;
}

void  changeImg(int, void *){

}
