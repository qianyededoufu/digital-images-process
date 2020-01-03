#include<opencv2\opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;	
int main()
{ 
	VideoCapture cap("e:\\1.mp4");
	Mat frame;
	if (cap.isOpened()==false){
		cout<<"open error!"<<endl;
		system("pause");
		return -1;
	}
	int totalFrame=cap.get(CAP_PROP_FRAME_COUNT);
	char outFile[50];
	for(int i=1;i<=totalFrame;i++){
		cap.read(frame);
		if(frame.empty()){
			break;
		}
		cvtColor(frame,frame,COLOR_RGB2GRAY);
		blur(frame,frame,Size(3,3));
		Canny(frame,frame,100,200);
		sprintf(outFile,"e:\\pic\\%d.bmp",i);
		if(i%24==0){
			imwrite(outFile,frame);		
		}
		imshow("video",frame);
		waitKey(15);
	}
	cap.release();
	destroyAllWindows();
	return 0;
} 
