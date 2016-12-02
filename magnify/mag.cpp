#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;

const int tol=50;

Mat var1=imread("pic.jpg",1);
Mat var3(var1.rows*2,var1.cols*2,CV_8UC3,Scalar(0,0,0));
Mat var4(var1.rows/2,var1.cols/2,CV_8UC3,Scalar(0,0,0));


int main() {
  namedWindow("windows3", WINDOW_AUTOSIZE);
  namedWindow("windows4", WINDOW_AUTOSIZE);
  namedWindow("windows5", WINDOW_AUTOSIZE);


  for (int i = 0; i < var1.rows; i++) {
    for (int j = 0; j < var1.cols; j++) {
      for (int a=2*i;a<=2*i+1;a++) {
        for (int b=2*j;b<=2*j+1;b++) {
          var3.at<Vec3b>(a,b)=var1.at<Vec3b>(i,j);
        }
      }
    }
  }

  for (int i = 0; i < var4.rows; i++) {
    for (int j = 0; j < var4.cols; j++) {
      int av0=0,av1=0,av2=0;
      for (int a=2*i;a<=2*i+1;a++) {
        for (int b=2*j;b<=2*j+1;b++) {
          av0+=var1.at<Vec3b>(a,b)[0];
          av1+=var1.at<Vec3b>(a,b)[1];
          av2+=var1.at<Vec3b>(a,b)[2];
          var4.at<Vec3b>(i,j)={av0/3,av1/3,av2/3};
        }
      }
    }
  }


  imshow("windows4",var1);
  imshow("windows3",var3);
  imshow("windows5",var4);
  waitKey(0);
  return 0;

}
