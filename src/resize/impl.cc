#include "impls.h"


cv::Mat my_resize(const cv::Mat& input, float scale) {
    /**
     * 要求：
     *      实现resize算法，只能使用基础的语法，比如说for循环，Mat的基本操作。不能
     * 用cv::resize。resize算法的内容自行查找学习，不是很难。
     * 
     * 提示：
     * 无。
     * 
     * 通过条件：
     * 运行测试点，你的结果跟答案长的差不多就行。
     */
    int new_rows = input.rows * scale, new_cols = input.cols * scale;
    // IMPLEMENT YOUR CODE HERE

    cv::Mat des;
    des.create(new_rows,new_cols,input.type());

    int sx,sy = 0;
    float fx = (float)input.cols / new_cols;
    float fy = (float)input.rows / new_rows;

    for(int x = 0;x < new_cols;x++){
        sx = fx * x + 0.5;
        for(int y = 0;y < new_rows;y++){
            sy = fy * y + 0.5;
            des.at<cv::Vec3b>(y,x) = input.at<cv::Vec3b>(sy,sx);
        }
        
    }

    //return cv::Mat::zeros(new_rows, new_cols, input.type());
    return des;
}