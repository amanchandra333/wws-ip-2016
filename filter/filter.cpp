#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <math.h>

using namespace std;
using namespace cv;

const int tol=50;

Mat var1=imread("pic.jpg",1);
Mat var4(var1.rows,var1.cols,CV_8UC3,Scalar(0,0,0));
Mat var5(var1.rows,var1.cols,CV_8UC3,Scalar(0,0,0));

int main() {

  int kernel[3][3];
  int gaussian[3][3]={1,2,1,2,4,2,1,2,1};
  int Gx[3][3]={-1,0,1,-2,0,2,-1,0,1};
  int Gy[3][3]={-1,-2,-1,0,0,0,1,2,1};
  int div=1;


  for(int x=0; x<3; x++) {
    for(int y=0;y<3;y++) {
      kernel[x][y]=1;
    }
  }


  namedWindow("windows4", WINDOW_AUTOSIZE);
  namedWindow("windows5", WINDOW_AUTOSIZE);
  namedWindow("windows6", WINDOW_AUTOSIZE);


  for (int i = 1; i < var4.rows-1; i++) {
    for (int j = 1; j < var4.cols-1; j++) {
      int av0=0,av1=0,av2=0;
      int gx0=0,gx1=0,gx2=0;
      int gy0=0,gy1=0,gy2=0;
      for (int a=i-1,x=0;a<i+2;a++,x++) {
        for (int b=j-1,y=0;b<j+2;b++,y++) {
          // av0+=gaussian[x][y]*var1.at<Vec3b>(a,b)[0];
          // av1+=gaussian[x][y]*var1.at<Vec3b>(a,b)[1];
          // av2+=gaussian[x][y]*var1.at<Vec3b>(a,b)[2];

          gx0+=Gx[x][y]*var1.at<Vec3b>(a,b)[0];
          gx1+=Gx[x][y]*var1.at<Vec3b>(a,b)[1];
          gx2+=Gx[x][y]*var1.at<Vec3b>(a,b)[2];

          gy0+=Gy[x][y]*var1.at<Vec3b>(a,b)[0];
          gy1+=Gy[x][y]*var1.at<Vec3b>(a,b)[1];
          gy2+=Gy[x][y]*var1.at<Vec3b>(a,b)[2];

        }
      }
      av0=sqrt(gx0*gx0+gy0*gy0);
      av1=sqrt(gx1*gx1+gy1*gy1);
      av2=sqrt(gx2*gx2+gy2*gy2);
      var4.at<Vec3b>(i,j)={av0/div,av1/div,av2/div};
      var5.at<Vec3b>(i,j)[0]=var1.at<Vec3b>(i,j)[0]-var4.at<Vec3b>(i,j)[0];
      var5.at<Vec3b>(i,j)[1]=var1.at<Vec3b>(i,j)[1]-var4.at<Vec3b>(i,j)[1];
      var5.at<Vec3b>(i,j)[2]=var1.at<Vec3b>(i,j)[2]-var4.at<Vec3b>(i,j)[2];
    }
  }



  imshow("windows4",var1);
  imshow("windows5",var4);
  imshow("windows6",var5);

  waitKey(0);
  return 0;

}
