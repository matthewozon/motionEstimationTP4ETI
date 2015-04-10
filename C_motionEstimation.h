#ifndef C_MOTIONESTIMATION_H
#define C_MOTIONESTIMATION_H

#include <C_imgMatrix.h>

class C_motionEstimation
{
public:
    //ctor: load two images (frames of a movie)
    C_motionEstimation(std::string fileNameFrame1, std::string fileNameFrame2);

    //method that computes all iterations of Horn & Schunck method: stores the result in vectX & vectY
    bool computeMotionField(double alpha, unsigned long nbIteration){return false;}

    //the two frames
    C_imgMatrix<double> image1;
    C_imgMatrix<double> image2;

    //the vector field: flow vector
    C_imgMatrix<double> vectX;
    C_imgMatrix<double> vectY;

    //tool to save the vector field (may be useful to export result so that you can plot it using octave)
    bool saveVectorField(std::string fileNameVectX, std::string fileNameVectY);

private:
    //first order derivatives of the images
    C_imgMatrix<double> imDX;
    C_imgMatrix<double> imDY;
    C_imgMatrix<double> imDT;

    //methods that compute the derivatives
    void derivativeX(C_imgMatrix<double> im){return;}
    void derivativeY(C_imgMatrix<double> im){return;}
    void derivativeT(C_imgMatrix<double> imT, C_imgMatrix<double> imTDT){return;}

    //compute one iteration of Horn & Schunck method: one for each component
    double computeIterationX(double alpha){return 0.0;}
    double computeIterationY(double alpha){return 0.0;}

    //might be interesting to have those two...
    double computeAverageX(unsigned short i, unsigned short j){return 0.0;}
    double computeAverageY(unsigned short i, unsigned short j){return 0.0;}

    //init vector field: choose the right method
    bool initOpticalFlow(unsigned short METHOD){return false;}

};

#endif // C_MOTIONESTIMATION_H
