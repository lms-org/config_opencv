#ifndef LMS_OPENCV_UTILS
#define LMS_OPENCV_UTILS
#include "lms/imaging/image.h"
#include <vector>

//default opencv includes
#include "opencv2/objdetect.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

namespace cv_utils{

//Not needed yet
//inline cv::Mat croppResize(const cv::Mat& input, int width,int height, int alignX, int alignY);
//inline cv::Mat croppResizeCentered(const cv::Mat& input, int width, int height);

    struct ImageWithFaces{
        const lms::imaging::Image* image;
        std::vector<cv::Rect> faces;
    };

    struct ImageWithBlobs{
        const lms::imaging::Image* image;
        std::vector<cv::KeyPoint> points;
    };

    inline cv::Mat croppResize(const cv::Mat& input, int width,int height, int alignX, int alignY){
        cv::Mat cropped(input,cv::Rect(alignX,alignY,width,height));
        cv::Mat output;
        cv::resize(cropped,output,cv::Size2d(((double)width)/cropped.cols,((double)height)/cropped.rows));
        return output;
    }
    inline cv::Mat croppResizeCentered(const cv::Mat& input, int width, int height){
        float ratio = ((float)width)/height;
        float currentRatio = ((float)input.rows)/input.cols;

        int alignX = 0;
        int alignY = 0;

        if(ratio > currentRatio){
            alignX = input.cols-input.rows*ratio;
        }else if(ratio < currentRatio){
            alignY = input.rows-input.cols*ratio;
        }
        return croppResize(input,width,height,alignX/2,alignY/2);

    }
}

#endif
