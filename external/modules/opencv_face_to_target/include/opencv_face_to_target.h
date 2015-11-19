#ifndef OPENCV_FACE_TO_TARGET_H
#define OPENCV_FACE_TO_TARGET_H

#include <lms/datamanager.h>
#include <lms/module.h>
#include <target/target.h>
#include <opencv_utils.h>

class OpencvFaceToTarget : public lms::Module {
public:
    bool initialize();
    bool deinitialize();
    bool cycle();
private:
    lms::ReadDataChannel<cv_utils::ImageWithFaces> iFaces;
    lms::WriteDataChannel<lms::target::Target> target;
};

#endif // OPENCV_FACE_TO_TARGET_H
