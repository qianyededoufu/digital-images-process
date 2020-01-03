#include <iostream> 
#include <opencv2\opencv.hpp> 
#include<string>

using namespace std;
using namespace cv;

void changeimg(int ,void *);

int imgSrc1=1,imgGmmar=0,maxGammar=100,imgSrc2=10-imgSrc1;
double maxSrc1=10;

char fileName1[100],fileName2[100];


Mat Src1,Src2;
Mat Dst;
int main()
{   
	cin>>fileName1;
	cin>>fileName2;
	Src1=imread(fileName1),Src2=imread(fileName2);
    namedWindow("demo");
	imshow("before1",Src1);
	imshow("before2",Src2);
	if(Src1.size!=Src2.size){
		resize(Src2,Src2,Size(Src1.cols,Src1.rows));
	}
	createTrackbar("Src1","demo",&imgSrc1,maxSrc1,changeimg);
	createTrackbar("Gmmar","demo",&imgGmmar,maxGammar,changeimg);
	waitKey(0);
	system("pause");
	return 0;
}
void changeimg(int ,void *)
{   
	addWeighted(Src1,(double)(imgSrc1*0.1),Src2,(double)(imgSrc2*0.1),imgGmmar,Dst);
	cout<<"现在通道值为"<<imgSrc1<<endl;
	cout<<"现在Gammar的通道值为"<<imgSrc2<<endl;
	imshow("demo", Dst);
	
}
