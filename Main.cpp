#include "mainWindow.h"

int main()
{
  cv::VideoCapture cap("/home/xz/Documents/背景建模测试/VibePlus/build/7.mp4");
  string algorithm_name = "MultiCue";
  MainWindow bg_xiong ;
  bg_xiong.bgs =bgslibrary::get_alg(algorithm_name);

  cv::Mat cv_frame;
  bool Init =false;
  while( 1 )
  {
    cap >>cv_frame;
    if (cv_frame.empty())
    {
      bg_xiong.destroyBGS();
      return 0;
    }
    cv::resize(cv_frame,cv_frame,cv::Size(640,480),0,0,1);
     //初始化
    if(  !Init )
    {
      int frame_width  = cv_frame.size().width;
      int frame_height = cv_frame.size().height;
      Init =true;

    }
    else{
      double duration   = static_cast<double>(cv::getTickCount());
      bg_xiong.processFrame(cv_frame);
      duration          =(static_cast<double>(cv::getTickCount()) - duration) / cv::getTickFrequency();

      double fps = 1 / duration;
      cout<<"time=="<<duration*1000<<"ms"<<endl;
      cout<<"fps=="<<fps<<endl;
    }

    cv::imshow("cv_frame",cv_frame);
    cv::waitKey(1);
  }
}
