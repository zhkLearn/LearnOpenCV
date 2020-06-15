#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void example2_5(const Mat& img)
{
    imshow("2_5_in", img);

    Mat out_GaussianBlur;
    GaussianBlur(img, out_GaussianBlur, Size(5, 5), 3, 3);
    imshow("2_5_out_GaussianBlur", out_GaussianBlur);

    Mat out_blur;
    blur(img, out_blur, Size(5, 5));
    imshow("2_5_out_blur", out_blur);

    Mat out_medianBlur;
    medianBlur(img, out_medianBlur, 5);
    imshow("2_5_out_medianBlur", out_medianBlur);

    Mat out_bilateralFilter;
    bilateralFilter(img, out_bilateralFilter, 5, 3.0, 3.0);
    imshow("2_5_out_bilateralFilter", out_bilateralFilter);

    Mat out_pyrDown;
    pyrDown(img, out_pyrDown);
    imshow("2_5_out_pryDown", out_pyrDown);

    Mat out_gray, out_canny;
    cvtColor(img, out_gray, COLOR_BGR2GRAY);
    imshow("2_5_out_gray", out_gray);

    Canny(img, out_canny, 10, 100, 3, true);
    imshow("2_5_out_canny", out_canny);

    Vec3b bgr = img.at<Vec3b>(20, 780); // Notice: (y, x)
    cout << "BGR(100, 100) = (" << (unsigned int)bgr[0] << ", " << (unsigned int)bgr[1] << ", " << (unsigned int)bgr[2] << ")" << endl;

    Mat out_polar;
    logPolar(img, out_polar, Point2f(img.cols/2, img.rows/2), 100, WARP_FILL_OUTLIERS);
    imshow("2_5_out_logPolar", out_polar);

    waitKey(0);

    destroyAllWindows();
}

int main(int argc, char** argv)
{
    Mat img = imread(argv[1], -1);
    if (img.empty())
    {
        cout << "Cannot open file! " << argv[1] << endl;
        return -1;
    }

    example2_5(img);

    return 0;
}
