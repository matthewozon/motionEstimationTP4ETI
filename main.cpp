#include <iostream>
#include <stdio.h>
#include <sstream>

#include <C_imgMatrix.h>
#include <C_motionEstimation.h>



int main(int argc, char *argv[])
{
    if(argc!=3) return -1;
    std::string file1 = argv[1];
    std::string file2 = argv[2];

    std::cout << "Input files: " << file1 << " " << file2 << std::endl;

    //display images
    //C_imgMatrix<double> IM1(file1); //load file1
    //C_imgMatrix<double> IM2(file2); //load file2

    //IM1.display(NO_NORMALIZATION); //display image 1
    //IM2.display(NO_NORMALIZATION); //display image 2


    //It's up to you!
    C_motionEstimation mvt(file1, file2);
    mvt.computeMotionField(1.0, 10);

    //display results...
    return 0;
}
