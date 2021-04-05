#include <opencv2/opencv.hpp>

namespace FrameProcessing {

cv::Mat grayscale(cv::Mat frame){
    cv::Mat grayframe;
    cv::cvtColor(frame, grayframe, CV_RGB2GRAY);
    cv::cvtColor(grayframe, frame, CV_GRAY2RGB);
    return frame;
}

}
