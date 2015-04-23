#include <iostream>
#include <stdio.h>
#include <sstream>

#include <C_imgMatrix.h>
#include <C_motionEstimation.h>
#include <C_blockMatching.h>



int main(int argc, char *argv[])
{
    if(argc!=3)
    {
        std::cout << "Command " << argv[0] << " must be run: " << argv[0] << " frame1<string> frame2<string>" << std::endl;
        return -1;
    }
    std::string file1 = argv[1];
    std::string file2 = argv[2];

    std::cout << "Input files: " << file1 << " " << file2 << std::endl;

    //display images
    //C_imgMatrix<double> IM1(file1); //load file1
    //C_imgMatrix<double> IM2(file2); //load file2

    //IM1.display(NO_NORMALIZATION); //display image 1
    //IM2.display(NO_NORMALIZATION); //display image 2

    bool blockMatching=true;

    if(blockMatching)
    {
        //block matching
        C_blockMatching blckMtch(file1 /**first frame*/, file2 /**second frame*/);

        //try different value of the parameters and observe the results
        C_imgMatrix<double> patch = blckMtch.createNextFrame(15/*#row blocks*/,15/*#column blocks*/,12/*row area param*/,12/*column area param*/);
        //C_imgMatrix<double> patch = blckMtch.createNextFrame(20,20,9,9);

        //show the difference between predicted frame and actual frame
        C_imgMatrix<double> diff((blckMtch.image2-patch).m_abs());
        diff.display(0);

        patch.savepng("patch.png");
    }
    else
    {
        C_motionEstimation mvt(file1 /**first frame*/, file2 /**second frame*/, 0.025 /**time between frames*/);

        //motion estimation using the original image and its Laplacian
        mvt.computeMotionFieldLap();
        mvt.saveVectorField("vectXLap","vectYLap");

        //motion estimation using the 8-neighboring system (try this method on null-divergence )
        mvt.computeMotionFieldV8();
        mvt.saveVectorField("vectXV8","vectYV8");

        //motion estimation using Horn and Schunck's method (try this method using different value of the regularizing parameter, and try different images)
        mvt.computeMotionFieldHnS(100.0,100);
        mvt.saveVectorField("vectXHnS","vectYHnS");

        //use octave/matlab to plot (quiver) a vector field on an image
    }


    return 0;
}
