#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv; 

int main() {
	Mat var1=imread("pic.jpg",1);
	namedWindow("windows1", WINDOW_AUTOSIZE);
	imshow("windows1",var1);
	waitKey(0);
	return 0;
}
	
