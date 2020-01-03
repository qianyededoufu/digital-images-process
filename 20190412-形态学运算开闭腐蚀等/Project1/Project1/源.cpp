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
	namedWindow("����/��ʴ Ч��");
	createTrackbar("��̬ѧЧ��ѡ��","����/��ʴ Ч��",&flag,maxFlag,changeimg);
	createTrackbar("�˴�С","����/��ʴ Ч��",&kernel,maxKernel,changeimg);
	waitKey(0);
	system("pause");
	return 0;
}
void changeimg(int ,void *){   
	string xName[7]={"���Ͳ���","��ʴ����","���������","���������","��̬ѧ�ݶȲ���","��ñ����","��ñ����"};
	cout<<xName[flag]<<endl;
	Mat element=getStructuringElement(MORPH_RECT,Size(2*kernel+1,2*kernel+1),Point(-1,-1));
	morphologyEx(src,dst,flag,element);		
	imshow("����/��ʴ Ч��",dst);
}
