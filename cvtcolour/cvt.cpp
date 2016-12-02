#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;

int main() {
	Mat var1=imread("pic.jpg",1);
  Mat var2(var1.rows,var1.cols,CV_8UC1,Scalar(0));

  cvtColor(var1, var2, CV_RGB2GRAY);
  // cvtColor(var1, var2, CV_BGR2HSV);
  // cvtColor(var1, var2, CV_HSV2BGR);

	namedWindow("windows1", WINDOW_AUTOSIZE);
  namedWindow("windows2", WINDOW_AUTOSIZE);

	imshow("windows1",var1);
  imshow("windows2",var2);
	waitKey(0);
	return 0;
}
