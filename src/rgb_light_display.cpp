#include <math.h>
#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <cv_bridge/cv_bridge.h>

using namespace cv;
using namespace std;

cv::Mat src, gray, edges, dst, cdst;
vector<Vec4i> lines;

image_transport::Publisher user_image_pub;
image_transport::Subscriber raw_image_sub;

void imageCallback(const sensor_msgs::ImageConstPtr& msg)
{
	cv::Mat im = cv_bridge::toCvShare(msg, "bgr8")->image;
    Mat_<Vec3b> imgvec = im;




    int total_r = 0;
    int total_g = 0;
    int total_b = 0;
    // for each pixel
    for( int r = 0; r < im.rows; ++r)
        for( int c = 0; c < im.cols; ++c )
            {
                // get the red,green, blue values of pixel
                imgvec(r,c)[0]

        // add red, green, blue values to the total red, green, blue values


    //if dominant color is red, rgb_dominant = 0
    // if (total_red > ... ) {
    //  rgb_dominant = 0;
    // }

    //if dominant color is green, rgb_dominant = 1
    //if (total_green > ... ) {
    //  rgb_dominant = 1;
    //}

    //if dominant color is blue, rgb_dominant = 2
    //if (total_blue > ... ) {
    //  rgb_dominant = 2;
    //}

}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "basic_cv");
  ros::NodeHandle nh;

  image_transport::ImageTransport it(nh);

  //advertise the topic with our processed image
  user_image_pub = it.advertise("/user/image1", 1);

  //subscribe to the raw usb camera image
  raw_image_sub = it.subscribe("/usb_cam/image_raw", 1, imageCallback);

  ros::spin();
}
