#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;

Mat var1=imread("pic.jpg",1);
Mat var2(var1.rows,var1.cols,CV_8UC1,Scalar(0));
Mat var3(var1.rows,var1.cols,CV_8UC1,Scalar(0));



int main() {

  // namedWindow("windows1", WINDOW_AUTOSIZE);
  // namedWindow("windows2", WINDOW_AUTOSIZE);
  namedWindow("windows3", WINDOW_AUTOSIZE);
//  namedWindow("windows4", 1);

  int a;
  createTrackbar("track","windows3",&a,255);
  while(1) {
  for (int i = 0; i < var1.rows; i++) {
    for (int j = 0; j < var1.cols; j++) {
      int B=var1.at<Vec3b>(i,j)[0];
      int R=var1.at<Vec3b>(i,j)[1];
      int G=var1.at<Vec3b>(i,j)[2];
      var2.at<uchar>(i,j)=(R+B+G)/3;
      if ((R+B+G)/3>a) {
        var3.at<uchar>(i,j)=0;
      }
      else
      var3.at<uchar>(i,j)=255;
    }
  }
  imshow("windows3",var3);
	//  imshow("windows1",var1);
  //  imshow("windows2",var2);
   waitKey(1);
 }
	 return 0;
}
