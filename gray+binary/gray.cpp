#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;

int main() {
	Mat var1=imread("pic.jpg",1);
  Mat var2(var1.rows,var1.cols,CV_8UC1,Scalar(0));
  Mat var3(var1.rows,var1.cols,CV_8UC1,Scalar(0));

  for (int i = 0; i < var1.rows; i++) {
    for (int j = 0; j < var1.cols; j++) {
      int B=var1.at<Vec3b>(i,j)[0];
      int R=var1.at<Vec3b>(i,j)[1];
      int G=var1.at<Vec3b>(i,j)[2];
      var2.at<uchar>(i,j)=(R+B+G)/3;
      if ((R+B+G)/3>150) {
        var3.at<uchar>(i,j)=0;
      }
      else
      var3.at<uchar>(i,j)=255;
    }
  }
	namedWindow("windows1", WINDOW_AUTOSIZE);
  namedWindow("windows2", WINDOW_AUTOSIZE);
  namedWindow("windows3", WINDOW_AUTOSIZE);

	imshow("windows1",var1);
  imshow("windows2",var2);
  imshow("windows3",var3);

	waitKey(0);
	return 0;
}
