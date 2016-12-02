#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;

const int tol=50;

Mat var1=imread("pic.jpg",1);
Mat var3(var1.rows*var1.cols/2000,256,CV_8UC3,Scalar(0,0,0));


int main() {
  namedWindow("windows3", WINDOW_AUTOSIZE);
  namedWindow("windows4", WINDOW_AUTOSIZE);

  int blue=0,green=0,red=0;
  for (int i = 0; i < 256 ; i++) {
    for (int a = 0; a < var1.rows; a++) {
      for (int b = 0; b < var1.cols; b++) {
        if (var1.at<Vec3b>(a,b)[0]==i)
          blue++;
        if (var1.at<Vec3b>(a,b)[1]==i)
          green++;
        if (var1.at<Vec3b>(a,b)[0]==i)
          red++;
      }
    }
    for(int j=0;j<blue/2000;j++)
      var3.at<Vec3b>(i,j)[0]=255;
  }


  imshow("windows4",var1);
  imshow("windows3",var3);
  waitKey(0);
  return 0;

}
