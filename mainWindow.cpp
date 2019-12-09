#include "mainWindow.h"

namespace bgslibrary
{
  //template<typename T> IBGS* createInstance() { return new T; }
  //typedef std::map<std::string, IBGS*(*)()> map_ibgs;

  IBGS* get_alg(std::string alg_name)
  {
    map_ibgs map;
#if CV_MAJOR_VERSION >= 2 && CV_MAJOR_VERSION <= 3
    map["MultiCue"] = &createInstance<MultiCue>;
#endif
    return map[alg_name]();
  }

string get_algs_name()
{
    string stringList;
    stringList ="MultiCue";
    return stringList;
  }
}

MainWindow::MainWindow()
{

}

MainWindow::~MainWindow()
{

}



void MainWindow::destroyBGS()
{
  delete bgs;
}

int MainWindow::processFrame(const cv::Mat &cv_frame)
{
  cv::Mat cv_fg;
  cv::Mat cv_bg;
  bgs->process(cv_frame, cv_fg, cv_bg);
  return 0;
}




