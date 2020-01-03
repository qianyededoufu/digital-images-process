#include <iostream> 
#include <opencv2\opencv.hpp> 
using namespace std;
using namespace cv;
int equalizeHist();
int equalizeHist_Color();
Mat matSrc;
int input();
int demo()
{
input();	
if(matSrc.channels()==1)
{
	 equalizeHist();
}
else if (matSrc.channels() == 3)
{
   equalizeHist_Color();
}
   waitKey(0);
    return 0;
}
int  input()
{
	char FileName[50];
	cout<<"input file name"<<endl;
	cin >> FileName;
	matSrc= imread(FileName,-1);
	if (!matSrc.data)
	{
		cout << "error" << endl;
		return -1;
	}
imshow("src", matSrc);
 return 0;
}
int equalizeHist()
{
    // 直方图均衡化
    Mat matResult;
    equalizeHist(matSrc, matResult);
	cout<<"gray image histrogram"<<endl;
    imshow("equlizeHist", matResult);
       return 0;
}

int equalizeHist_Color()
{
    cout<<"color image histrogram"<<endl;
	Mat matArray[3];
    split(matSrc, matArray);
    // 直方图均衡化
    for (int i = 0; i < 3; i++)
    {
        equalizeHist(matArray[i], matArray[i]);
    }
    Mat matResult;
    merge(matArray, 3, matResult);
     imshow("equlizeHist", matResult);
    return 0;
}
