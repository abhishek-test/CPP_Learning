#pragma once

#include "opencv2/opencv.hpp"

class Camera {

private:
    int frame_width;
    int frame_height;
    int camera_Id;
    cv::VideoCapture capObject;

public:
    Camera() {   // default constructor -> takes no args
		// not defined automatically if any constructor is defined
		// else a defaut constructor is define with no args
	    setWidth(640);
	    setHeight(480);
	    setCameraId(0);
	    capObject.open(camera_Id);
	    capObject.set(cv::CAP_PROP_FRAME_WIDTH, frame_width);
	    capObject.set(cv::CAP_PROP_FRAME_HEIGHT, frame_height);
    }

    Camera(int width, int height) {  // overloaded constructor
	    setWidth(width);
	    setHeight(height);
	    setCameraId(0);
	    capObject.open(camera_Id);
	    capObject.set(cv::CAP_PROP_FRAME_WIDTH, frame_width);
	    capObject.set(cv::CAP_PROP_FRAME_HEIGHT, frame_height);
    }

    Camera(int camId) {   // overloaded constructor
	    setWidth(640);
	    setHeight(480);
	    setCameraId(camId);
	    capObject.open(camera_Id);
	    capObject.set(cv::CAP_PROP_FRAME_WIDTH, frame_width);
	    capObject.set(cv::CAP_PROP_FRAME_HEIGHT, frame_height);
    }

    Camera(int camId, int width, int height) {	// overloaded constructor	
	    setWidth(width);
	    setHeight(height);
	    setCameraId(camId);
	    capObject.open(camera_Id);
	    capObject.set(cv::CAP_PROP_FRAME_WIDTH, frame_width);
	    capObject.set(cv::CAP_PROP_FRAME_HEIGHT, frame_height);
    }

    Camera(Camera &obj) {    // copy constructor -> used to copy data of one object to another
	    frame_width  = obj.frame_width;
	    frame_height = obj.frame_height;
	    camera_Id = obj.camera_Id;
	    capObject = obj.capObject;
    }

    // setter functions : used to set private/protected variables
    void Camera::setWidth(int width) {
	    frame_width = width;
    }

    void Camera::setHeight(int height) {
	    frame_height = height;
    }

    void Camera::setCameraId(int camId) {
	    camera_Id = camId;
    }

    cv::Mat Camera::readFrame() {
	    cv::Mat frame;
	    capObject >> frame;

	    return frame;
    }
};

int main()
{
	Camera camObj1;
	Camera camObj2(1280, 720);
	Camera camObj3(1); 
	Camera camObj4(1, 1920, 1080);

	Camera camObjCopy = camObj3;
	
	cv::Mat input = camObjCopy.readFrame();
}