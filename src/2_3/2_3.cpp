#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int g_state = 0;    //0: stop; 1: step; -1: run
int g_slider_position = 0;
VideoCapture g_cap;

void onTrackSlide(int pos, void *)
{
    g_cap.set(CAP_PROP_POS_FRAMES, pos);

    if (g_state == 0)
        g_state = 1;
}


int main(int argc, char** argv)
{
	namedWindow("2_3", WINDOW_AUTOSIZE);

    string str = argv[1];
    g_cap.open(str);

    int frames = (int)g_cap.get(CAP_PROP_FRAME_COUNT);
    int w = (int)g_cap.get(CAP_PROP_FRAME_WIDTH);
    int h = (int)g_cap.get(CAP_PROP_FRAME_HEIGHT);

    cout << "Video has " << frames << "(" << w << " x " << h << ")" <<endl;

    createTrackbar("Position", "2_3", &g_slider_position, frames, onTrackSlide);

    Mat frame;
    while (true)
    {
        if (g_state != 0)
        {
            g_cap >> frame;
            if (frame.empty())
            {
                break;
            }

            int curPos = (int)g_cap.get(CAP_PROP_POS_FRAMES);
            setTrackbarPos("Position", "2_3", curPos);

            imshow("2_3", frame);

            g_state -= 1;
        }

        char c = waitKey(10);
        if (c == 's')       //step
            g_state = 1;
        else if (c == 'r')  //run
            g_state = -1;
        else if (c == 27)   //ESC
            break;
    }

    return 0;	
}
