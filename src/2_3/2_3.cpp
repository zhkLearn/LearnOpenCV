#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
	namedWindow("2_3", WINDOW_AUTOSIZE);
    VideoCapture cap;
    cap.open(argv[1]);

    Mat frame;
    while (true)
    {
        cap >> frame;
        if (frame.empty())
        {
            break;
        }
        imshow("2_3", frame);

        if (waitKey(33) >= 0)
        {
            break;
        }

    }

    return 0;	
}
