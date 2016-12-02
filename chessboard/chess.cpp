#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;

int main() {
	Mat var1(400,400,CV_8UC3,Scalar(0,0,0));
  for (int i = 0; i < var1.rows; i++) {
    for (int j = 0; j < var1.cols; j++) {
      int a=i/50;
      int b=j/50;
      if ((a+b)%2) {
        var1.at<Vec3b>(i,j)={150,255,255};
      }
      else
      var1.at<Vec3b>(i,j)={0,0,0};
    }
  }
	namedWindow("windows1", WINDOW_AUTOSIZE);
	imshow("windows1",var1);
	waitKey(0);
	return 0;
}
