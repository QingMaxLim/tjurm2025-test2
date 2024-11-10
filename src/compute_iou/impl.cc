#include "impls.h"
#include <algorithm>

float compute_iou(const cv::Rect& a, const cv::Rect& b) {
    /**
     * 要求：
     *      有一个重要的指标叫做“交并比”，简称“IOU”，可以用于衡量
     * 两个矩形的重合程度，本练习要求自行学习交并比的计算方式，计算输入
     * 的两个矩形的交并比。
     * 
     * 提示：
     * (1) 注意OpenCV中规定的xy坐标系方向跟平常的xy坐标系不一样。
     * (2) 注意矩形的x, y, width, height四个属性在坐标系内的含义。
     * (3) 注意分母不要除以0（不过我们不会测试这一点）
     * 
     * 通过条件：
     * 运行测试点，显示通过就行，不通过会告诉你哪一组矩形错了。
    */
    // IMPLEMENT YOUR CODE HERE

    if(a.x > b.x + b.width) return 0.f;
    if(a.y > b.y + b.height) return 0.f;
    if(a.x + a.width < b.x) return 0.f;
    if(a.y + a.height < b.y) return 0.f;

    float overlap_w = std::min(a.x + a.width,b.x + b.width) - std::max(a.x,b.x);
    float overlap_h = std::min(a.x + a.height,b.x + b.height) - std::max(a.y,b.y);
    float iou = (overlap_w * overlap_h) / ((a.width * a.height) + (b.width * b.height) - (overlap_w * overlap_h));

    return iou;
}