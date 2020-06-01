#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
	Mat img = imread(argv[1], -1);
    if (img.empty())
    {
        cout << "Cannot open file! " << argv[1] << endl;
        return -1;
    }
	
	namedWindow("2_1", WINDOW_AUTOSIZE);
	imshow("2_1", img);
    waitKey(0);
    destroyWindow("2_1");

    return 0;	
}
