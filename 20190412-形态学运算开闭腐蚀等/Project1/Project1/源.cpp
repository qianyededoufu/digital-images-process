#include <iostream> 
#include <opencv2\opencv.hpp> 
using namespace std;
using namespace cv;

void changeimg(int ,void *);

Mat src;
Mat dst;
int kernel=1,maxKernel=20;
int flag=0,maxFlag=6;
int main()
 {
	char fileName[50];
	cin>>fileName;
	src=imread(fileName,1);
	if(!src.data){
		cout<<"ERROR"<<endl;
		return -1;
	}
	imshow("src",src);
	namedWindow("膨胀/腐蚀 效果");
	createTrackbar("形态学效果选择","膨胀/腐蚀 效果",&flag,maxFlag,changeimg);
	createTrackbar("核大小","膨胀/腐蚀 效果",&kernel,maxKernel,changeimg);
	waitKey(0);
	system("pause");
	return 0;
}
void changeimg(int ,void *){   
	string xName[7]={"膨胀操作","腐蚀操作","开运算操作","闭运算操作","形态学梯度操作","顶帽操作","黑帽操作"};
	cout<<xName[flag]<<endl;
	Mat element=getStructuringElement(MORPH_RECT,Size(2*kernel+1,2*kernel+1),Point(-1,-1));
	morphologyEx(src,dst,flag,element);		
	imshow("膨胀/腐蚀 效果",dst);
}
