#include "impls.h"


std::pair<cv::Rect, cv::RotatedRect> get_rect_by_contours(const cv::Mat& input) {
    /**
     * 要求：
     * 使用findCountours函数找出输入图像（彩色图像）中的矩形轮廓，并且返回它的外接矩形，以及
     * 最小面积外接矩形。所需要的函数自行查找。
     * 
     * 通过条件：
     * 运行测试点，你找到的矩形跟答案一样就行。
    */
    std::pair<cv::Rect, cv::RotatedRect> res;
    // IMPLEMENT YOUR CODE HERE
    
    cv::Mat gray;
    cv::cvtColor(input,gray,cv::COLOR_BGR2GRAY);
    cv::Mat bin;
    cv::threshold(gray,bin,200,255,cv::THRESH_BINARY_INV);
    std::vector<std::vector<cv::Point>> temp;
    cv::findContours(bin,temp,cv::RETR_TREE,cv::CHAIN_APPROX_NONE);

    temp.pop_back();
    cv::Rect rect = cv::boundingRect(temp[0]);
    res.first = rect;

    cv::RotatedRect rotatedRect = cv::minAreaRect(temp[0]);
    res.second = rotatedRect;

    return res;
}