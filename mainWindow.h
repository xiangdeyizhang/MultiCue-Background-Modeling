#pragma once

#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace std;


#if  CV_MAJOR_VERSION >= 4
#define CV_CAP_PROP_POS_FRAMES cv::CAP_PROP_POS_FRAMES
#define CV_CAP_PROP_FRAME_COUNT cv::CAP_PROP_FRAME_COUNT
#define CV_CAP_PROP_FPS cv::CAP_PROP_FPS
#endif

#include "algorithms.h"

namespace bgslibrary
{
  template<typename T> IBGS * createInstance() { return new T; }
  typedef std::map<std::string, IBGS*(*)()> map_ibgs;

  IBGS* get_alg(std::string alg_name);
  string get_algs_name();
}


class MainWindow 
{
public:
  MainWindow();
  ~MainWindow();

  long long frameNumber = 0;
  long long frameNumber_aux = 0;
  void setFrameNumber(long long frameNumber);
  int processFrame(const cv::Mat &cv_frame);
  IBGS *bgs;
  void createBGS();
  void destroyBGS();
  double duration = 0;
  int capture_length = 0;
};
