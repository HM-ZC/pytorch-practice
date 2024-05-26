#include <vector>
#include "EDLib.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <ros/ros.h>
#include "opencv2/opencv.hpp"
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/ximgproc.hpp"
#include <cv_bridge/cv_bridge.h>
#include "geometry_msgs/PoseStamped.h" 
#include <image_transport/image_transport.h>
#include <opencv2/ximgproc/edge_drawing.hpp>
#include <camera_info_manager/camera_info_manager.h>
#include <std_msgs/Bool.h>
#include <deque>
using namespace cv;
using namespace std;
using namespace cv::ximgproc;
////////////////////
int gradThresh=38;
int anchor_thresh=0;
int sigmai=3;
double sigma=sigmai;
int validateSegmentsb=1;
bool validateSegments=validateSegmentsb;
/////////////////////
double _line_error=5;
int _min_line_len =5 ;
double _max_distance_between_two_lines=5 ;
double _max_error=5;
int lineError=_line_error/1;
int maxDistanceBetweenTwoLines=_max_distance_between_two_lines/1;
int maxError=_max_error/1;
int counter=0;
//////////////////////
#define max2(a,b) (a>b?a:b)
#define max3(a,b,c) (a>b?max2(a,c):max2(b,c))
#define min2(a,b) (a<b?a:b)
#define min3(a,b,c) (a<b?min2(a,c):min2(b,c))

    int can =160;
//cvRetangle
struct mask
{
    int maskdata[20][4];
    int count;
    _Float32 px;
    _Float32 pz;
};

Mat undistort(Mat frame)
{
    cv::Mat k = (cv::Mat_<double>(3, 3) << 469.8769, 0, 334.8598,
                                          0.0, 469.8360, 240.2752,
                                          0.0, 0.0, 1.0);

    cv::Mat d = (cv::Mat_<double>(1, 5) << -0.0555, 0.0907, 0.0, 0.0, 0.0);

	int h = frame.rows;
    int w = frame.cols;
	cv::Mat mapx, mapy;
    cv::initUndistortRectifyMap(k, d, cv::noArray(), k, cv::Size(w, h), CV_32FC1, mapx, mapy);

    cv::Mat undistorted_frame;
    cv::remap(frame, undistorted_frame, mapx, mapy, cv::INTER_LINEAR);

    return undistorted_frame;
}

mask Rectang(Mat dst)
{   
    TickMeter tm;
    tm.start();
    mask m;
    Mat srcImg=dst;
    Mat dstImg = srcImg.clone();
    vector<vector<Point>> contours;
    vector<Vec4i> hierarcy;
    findContours(srcImg, contours, hierarcy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
    vector<Rect> boundRect(contours.size());  //定义外接矩形集合
    vector<RotatedRect> box(contours.size()); //定义最小外接矩形集合
    Point2f rect[4];
    m.maskdata[20][4]={0};
    for(int i=0; i<contours.size(); i++)
    {
        box[i] = minAreaRect(Mat(contours[i]));  //计算每个轮廓最小外接矩形
        boundRect[i] = boundingRect(Mat(contours[i]));
        circle(dstImg, Point(box[i].center.x, box[i].center.y), 5, Scalar(0,0,0), -1, 8);  //绘制最小外接矩形的中心点
        box[i].points(rect);  //把最小外接矩形四个端点复制给rect数组
        rectangle(dstImg, Point(boundRect[i].x, boundRect[i].y), Point(boundRect[i].x + boundRect[i].width, boundRect[i].y + boundRect[i].height), Scalar(255,255,255), 2, 8);
        m.maskdata[i][0]=boundRect[i].x;
        m.maskdata[i][1]=boundRect[i].y;
        m.maskdata[i][2]=boundRect[i].width;
        m.maskdata[i][3]=boundRect[i].height;
    }

    // cout<<"countersize:"<<contours.size()<<endl;
    m.count=contours.size();
    // imshow("dstimg",dstImg);
    // waitKey();
    return m;
}
//pre
mask pre(Mat img)
{   
    // Mat temp=Saturation(img,50);
    Mat temp=img;
    TickMeter tm;
    tm.start();
    mask m;
    Mat hsv,hsvout;
    cv::cvtColor(temp,hsv,cv::COLOR_BGR2HSV);
    cv::Scalar lowerBound(130, 42, 47);  
    cv::Scalar upperBound(170, 171, 242); 
    //////////////////////
    
    // purple low 139 89 59 high 163 181 196
   
    cv::inRange(hsv, lowerBound, upperBound,hsvout);

    /*清除小面积*/
    cv::Mat dst =hsvout.clone();
	std::vector<std::vector<cv::Point> > contours;  // 创建轮廓容器
	std::vector<cv::Vec4i> 	hierarchy;  
	// 寻找轮廓的函数
	// 第四个参数CV_RETR_EXTERNAL，表示寻找最外围轮廓
	// 第五个参数CV_CHAIN_APPROX_NONE，表示保存物体边界上所有连续的轮廓点到contours向量内
	cv::findContours(hsvout, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_NONE, cv::Point());
	if (!contours.empty()) 
	{
		std::vector<std::vector<cv::Point> >::const_iterator itc = contours.begin();
		// 遍历所有轮廓
		while (itc != contours.end()) 
		{
			// 定位当前轮廓所在位置
			cv::Rect rect = cv::boundingRect(cv::Mat(*itc));
            // contourArea函数计算连通区面积
			double area = contourArea(*itc);
			// 若面积小于设置的阈值
			if (area < 500) 
			{   
				// 遍历轮廓所在位置所有像素点
				for (int i = rect.y; i < rect.y + rect.height; i++) 
				{
					uchar *output_data = dst.ptr<uchar>(i);
					for (int j = rect.x; j < rect.x + rect.width; j++) 
					{
						// 将连通区的值置0
						if (output_data[j] != 0) 
						{
							output_data[j] = 0;
						}
					}
				}
			}
			itc++;
             
           
			
		}

	}
    m=Rectang(dst);
    return m;
}
Mat masker(Mat src)
{   
    mask data=pre(src);
    TickMeter tm;
    tm.start();
    Mat mask1;
    Mat img=src;
    Mat hsvPurple;
    mask1 = Mat::zeros(img.size(), CV_8UC1);//定成黑色
    img = Mat::zeros(img.size(), CV_8UC1);//定成黑色
    int count=data.count;
    int d=20;
    for(int i=0;i<count;i++)
    {
        // if(data.maskdata[i][0]+data.maskdata[i][2]<663-d)    data.maskdata[i][2]=data.maskdata[i][2]+d;
        // else    data.maskdata[i][2]=640-data.maskdata[i][0];
        // if(data.maskdata[i][1]+data.maskdata[i][3]<452-d)    data.maskdata[i][3]=data.maskdata[i][3]+d;
        // else    data.maskdata[i][3]=490-data.maskdata[i][1];
        if(data.maskdata[i][0]+data.maskdata[i][2]<640-d)    data.maskdata[i][2]=data.maskdata[i][2]+d;
        else    data.maskdata[i][2]=640-data.maskdata[i][0];
        if(data.maskdata[i][1]+data.maskdata[i][3]<480-d)    data.maskdata[i][3]=data.maskdata[i][3]+d;
        else    data.maskdata[i][3]=480-data.maskdata[i][1];
        if(data.maskdata[i][0]>d)    data.maskdata[i][0]=data.maskdata[i][0]-d;
        else    data.maskdata[i][0]=0;
        if(data.maskdata[i][1]>d)    data.maskdata[i][1]=data.maskdata[i][1]-d;
        else    data.maskdata[i][1]=0;    
        //矩形掩膜
        Rect r1(data.maskdata[i][0],data.maskdata[i][1],data.maskdata[i][2],data.maskdata[i][3]);
        mask1(r1).setTo(255);
    }
    src.copyTo(img, mask1);
    return img;
}

int float_to_int(float x)
{
        if (std::isinf(x) || std::isinf(-x)|| x!=x){
            return 0;
        }
    return (int)x;
}
//ed识别
mask reconize(Mat img,Ptr<EdgeDrawing> ed)
{    
    mask camera1;
    vector<Vec6d> ellipses,colors;
    vector<Vec4f> lines;
    Mat colorImg = img;
    /* 预处理步骤 - 高斯模糊
    cv::GaussianBlur(colorImg, colorImg, cv::Size(5, 5), 0);

    // 预处理步骤 - 转换为灰度图并进行直方图均衡化
    cv::Mat grayImg;
    cv::cvtColor(colorImg, grayImg, cv::COLOR_BGR2GRAY);
    cv::equalizeHist(grayImg, grayImg);
    // 应用CLAHE
    Ptr<cv::CLAHE> clahe = cv::createCLAHE();
    clahe->setClipLimit(2.0);
    clahe->apply(grayImg, grayImg);
    // 自适应阈值
    cv::Mat threshImg;
    cv::adaptiveThreshold(grayImg, threshImg, 255, cv::ADAPTIVE_THRESH_GAUSSIAN_C, cv::THRESH_BINARY, 11, 2);    clahe->setClipLimit(2.0);
    */
        EDColor testEDColor = EDColor(colorImg, gradThresh,anchor_thresh,sigmai,validateSegments);
        EDCircles colorCircle = EDCircles(testEDColor);
        vector<mCircle> found_ccircles = colorCircle.getCircles();
        int maxd=0;
        int maxr=0;
        float k,d,x;
        double maxDiameter = 0;
        // float d[found_ccircles.size()+1]={0};//深度
        for (int i = 0; i < found_ccircles.size(); i++)
        {
            Point center((int)found_ccircles[i].center.x, (int)found_ccircles[i].center.y);
            Size axes((int)found_ccircles[i].r, (int)found_ccircles[i].r);
            double angle(0.0);
            Scalar color = Scalar(0, 255, 0);
            double diameter = 2 * found_ccircles[i].r;
            if(found_ccircles[i].r>17)
            {
                ellipse(colorImg, center, axes, angle, 0, 360, color, 1, LINE_AA);
                // d[i]=23956/found_ccircles[i].r;//距离
            }
            if(found_ccircles[i].r>maxd)
            {
                maxd=found_ccircles[i].r;
                maxr=found_ccircles[i].center.x;
                maxDiameter = diameter; // 更新最大直径
            }
                
        }
        // 使用直径代替深度
        camera1.pz = float_to_int(maxDiameter);
        //k=190.0/maxr;
        //d=1.0*k*469.8769;
        x=maxr-334.8598;
        camera1.px=float_to_int(x);
        //camera1.pz=float_to_int(d);
        //camera1.px = float_to_int(1.0*(maxr-331.9190));

        // for (int i = 0; i < found_cellipses.size(); i++)
        // {   

        //     Point center((int)found_cellipses[i].center.x, (int)found_cellipses[i].center.y);
        //     Size axes((int)found_cellipses[i].axes.width, (int)found_cellipses[i].axes.height);
        //     double angle = found_cellipses[i].theta * 180 / CV_PI;
        //     Scalar color = Scalar(255, 255, 0);
        //     if(found_cellipses[i].axes.width>=80 && found_cellipses[i].axes.height>=80)
        //     {
        //         ellipse(colorImg1, center, axes, angle, 0, 360, color, 1, LINE_AA);
        //     }
        // }
        // cv::imshow("imgend",img);
        // cv::imshow("colorImg", colorImg);
        // cv::waitKey(10);
        
        counter++;
        return camera1;
}
class ImageProcessor
{
public:
    ros::NodeHandle nh_;
    image_transport::ImageTransport it_;
    image_transport::Subscriber image_sub_;
    ros::Publisher pub_;
    ros::Subscriber save_image_sub_;
    ros::Subscriber color_sub_;
    Ptr<EdgeDrawing> ed;
    bool save_next_image;
    bool color_detected; // 存储颜色检测结果
    std::deque<cv::Point2f> points; // 用于存储坐标的队列
    const int window_size = 10; // 滤波器的窗口大小
    // 多帧图像融合队列
    std::deque<cv::Mat> frames;
    const int frame_count = 3; // 多帧融合的帧数
    ImageProcessor()
        : it_(nh_), save_next_image(false)
    {
        // 订阅图像话题
        image_sub_ = it_.subscribe("/usb_cam/image_raw", 1, &ImageProcessor::imageCallback, this);

        // 发布球位置
        pub_ = nh_.advertise<geometry_msgs::PoseStamped>("/camera1/ball_position", 100);
        save_image_sub_ = nh_.subscribe("/trigger_save_image", 10, &ImageProcessor::triggerSaveImageCallback, this);

        // 订阅颜色检测结果消息
        color_sub_ = nh_.subscribe("/color_detection/purple_detected", 10, &ImageProcessor::colorDetectionCallback, this);
    }
    void triggerSaveImageCallback(const std_msgs::Bool::ConstPtr& msg)
    {
        save_next_image = msg->data;  // 根据接收到的消息设置是否保存图像
    }
    void colorDetectionCallback(const std_msgs::Bool::ConstPtr& msg)
    {
        color_detected = msg->data;  // 更新颜色检测结果
    }

    std::string generateFilename()
    {
    static int file_number = 0;  // 静态变量，每次调用函数都会递增
    std::stringstream ss;
    ss << "image_" << file_number++ << ".jpg"; // 格式例如: "image_1.jpg"
    return ss.str();
    }
    cv::Point2f movingAverageFilter(const cv::Point2f &new_point)
    {
        // 如果新点是无效的（为0），则不添加到队列
        if (new_point.y == 0) return cv::Point2f(0, 0);

        points.push_back(new_point);
        if (points.size() > window_size)
        {
            points.pop_front();
        }

        cv::Point2f sum(0, 0);
        for (const auto &point : points)
        {
            sum += point;
        }
        return sum / static_cast<float>(points.size());
    }
    void imageCallback(const sensor_msgs::ImageConstPtr& msg)
    {
        cv_bridge::CvImagePtr cv_ptr;
        try
        {
            cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
        }
        catch (cv_bridge::Exception& e)
        {
            ROS_ERROR("cv_bridge exception: %s", e.what());
            return;
        }

        // 图像处理逻辑
        cv::Mat src = cv_ptr->image;
        src = undistort(src);
        /* 保存帧到队列
        frames.push_back(src);
        if (frames.size() > frame_count) {
            frames.pop_front();
        }

        // 多帧图像融合
        cv::Mat fused_frame = cv::Mat::zeros(src.size(), src.type());
        for (const auto& frame : frames) {
            fused_frame += frame / static_cast<double>(frames.size());
        }
        */
        // 如果需要保存图像
        if (save_next_image)
        {
            std::string filename = "/root/edlib_ws/src/edlib/src/" + generateFilename();
            cv::imwrite(filename, src);  // 保存处理后的图像
            save_next_image = false; // 重置标志
        }
        /* 图像预处理
        cv::GaussianBlur(fused_frame, fused_frame, cv::Size(5, 5), 0);
        cv::Mat gray_image;
        cv::cvtColor(fused_frame, gray_image, cv::COLOR_BGR2GRAY);
        cv::equalizeHist(gray_image, gray_image);
        // 应用CLAHE
        Ptr<cv::CLAHE> clahe = cv::createCLAHE();
        clahe->setClipLimit(2.0);
        clahe->apply(gray_image, gray_image);
        cv::Mat thresh_image;
        cv::adaptiveThreshold(gray_image, thresh_image, 255, cv::ADAPTIVE_THRESH_GAUSSIAN_C, cv::THRESH_BINARY, 11, 2);
        */
        cv::Mat src1 = masker(src);
        cv::imshow("vedio1", src);
        cv::imshow("vedio2", src1);
        cv::waitKey(1);
        mask camera = reconize(src1, ed);
        // 获取未平滑的坐标点
        cv::Point2f raw_point(camera.px, camera.pz);

        // 应用移动平均滤波器
        cv::Point2f smoothed_point = movingAverageFilter(raw_point);

        // 如果平滑后的点为无效点（即之前所有点都是0），则跳过发布
        if (smoothed_point.y == 0) return;

        ROS_INFO("Ball Position - x: %f, y: %f", smoothed_point.x, smoothed_point.y);

        geometry_msgs::PoseStamped pose_msg;
        pose_msg.pose.position.x = camera.px;
        pose_msg.pose.position.y = camera.pz;
        pose_msg.pose.position.z = color_detected ? 1.0 : 0.0; // 根据颜色检测结果更新z值;
        pose_msg.pose.orientation.x = 0.0;
        pose_msg.pose.orientation.y = 0.0;
        pose_msg.pose.orientation.z = 0.0;
        pose_msg.pose.orientation.w = 1.0;
        pose_msg.header.frame_id = "ball_position";
        pose_msg.header.stamp = ros::Time::now();
        pub_.publish(pose_msg);
    }
};

int main(int argc, char **argv)
{
    putenv("QT_X11_NO_MITSHM=1");
    ros::init(argc, argv, "camera1");
    ImageProcessor ip;
    ros::spin();
    return 0;
}
/*
代码结构
主函数调用masker获取预处理图像 供reconize函数调用 EDlib完成圆识别
masker获取pre处理的图像，经行掩膜绘制
pre为Rectang提供hsv筛选下轮廓图的结果，同时返回rectang的轮廓角点结果
==>>所有有关hsv的修改应当在pre中进行
==>>所有有关掩膜形状的修改应当在masker中进行（结合rectang）
==>>所有有关最后圆形筛选的修改应当在reconzie中进行

*/ 