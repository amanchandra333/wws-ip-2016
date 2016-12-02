#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;

Mat var1=imread("pic.jpg",1);
Mat var3(var1.rows,var1.cols,CV_8UC3,Scalar(0,0,0));

int main() {

  namedWindow("windows3", WINDOW_AUTOSIZE);
  namedWindow("windows4", WINDOW_AUTOSIZE);

  int a,b,c,d,e,f;
  createTrackbar("R","windows4",&a,255);
  createTrackbar("G","windows4",&b,255);
  createTrackbar("B","windows4",&c,255);
  createTrackbar("delR","windows4",&d,255);
  createTrackbar("delG","windows4",&e,255);
  createTrackbar("delB","windows4",&f,255);


  while(1) {
  for (int i = 0; i < var1.rows; i++) {
    for (int j = 0; j < var1.cols; j++) {
      int B=var1.at<Vec3b>(i,j)[0];
      int R=var1.at<Vec3b>(i,j)[1];
      int G=var1.at<Vec3b>(i,j)[2];

      // if (G<b+e && G>b-e) {
      //   var3.at<Vec3b>(i,j)[1]=G;
      // }
      // else
      // var3.at<Vec3b>(i,j)[1]=0;
      //
      // if (B<c+f && B>c-f) {
      //   var3.at<Vec3b>(i,j)[0]=B;
      // }
      // else
      // var3.at<Vec3b>(i,j)[0]=0;
      //
      // if (R<a+d && R>a-d) {
      //   var3.at<Vec3b>(i,j)[2]=R;
      // }
      // else
      // var3.at<Vec3b>(i,j)[2]=0;

      if (G<b+e && G>b-e && B<c+f && B>c-f && R<a+d && R>a-d ) {
        var3.at<Vec3b>(i,j)={B,G,R};
      }
      else
      var3.at<Vec3b>(i,j)={0,0,0};

    }
  }
  imshow("windows3",var3);
	//  imshow("windows1",var1);
  //  imshow("windows2",var2);
   waitKey(1);
 }
	 return 0;
}
