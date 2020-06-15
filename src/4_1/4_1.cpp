#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
    const int n_mat_size = 5;
    const int n_mat_sz[] = { n_mat_size , n_mat_size , n_mat_size };

    Mat n_mat(3, n_mat_sz, CV_32FC1);

    RNG rng;
    rng.fill(n_mat, RNG::UNIFORM, 0.1f, 1.0f);

    const Mat* arrays[] = {&n_mat, 0};

    Mat my_Planes[1];
    NAryMatIterator it(arrays, my_Planes);

    float s = 0;
    int n = 0;
    for (int p = 0; p < it.nplanes; p++, ++it)
    {
        s += sum(it.planes[0])[0];
        n++;
    }

    cout << "it.size: " << it.size << ", it.nplanes: " << it.nplanes << ", Sum: " << s << endl;

    return 0;
}
