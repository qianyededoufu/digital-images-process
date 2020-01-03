#include <iostream> 
#include <opencv2\opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	char fileName[50];
	cin>>fileName;
	Mat src=imread(fileName,1);

	Mat srcgrey;
	cvtColor(src,srcgrey,COLOR_BGR2GRAY);

	int channel[1]={0};
	Mat hist;
	int dim=1;
	int histSize=256;
	float hrange[2]={0,255};
	const float *range[1]={hrange};
	int hist_h=500;
	calcHist(&srcgrey,1,channel,Mat(),hist,dim,&histSize,range);
	Mat histImage(500,500,CV_8UC3,Scalar(0,0,0));
	normalize(hist,hist,0,histImage.rows,NORM_MINMAX);
	int bin_w=cvRound((float)histImage.cols/255);

	Point startPoint,endPoint;
	for(int i=0;i<256;i++){
		startPoint=Point(bin_w*(i),hist_h-cvRound(hist.at<float>(i)));
		endPoint=Point(bin_w*(i+1),hist_h-cvRound(hist.at<float>(i+1)));
		line(histImage,startPoint,endPoint,Scalar(0,255,255),2);
	}
	imshow("src",srcgrey);
	imshow("hist",histImage);
	waitKey(0);
    return 0;
}