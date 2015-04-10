#include <C_motionEstimation.h>

C_motionEstimation::C_motionEstimation(std::string fileNameFrame1, std::string fileNameFrame2)
{
    image1.load(fileNameFrame1);
    image2.load(fileNameFrame2);
    image1.display(NO_NORMALIZATION);
    image2.display(NO_NORMALIZATION);
}


bool C_motionEstimation::saveVectorField(std::string fileNameVectX, std::string fileNameVectY)
{
    std::ofstream myfile;
    myfile.open (fileNameVectX.data(), std::ios::out ); //| std::ios::binary
    if(myfile.is_open())
    {
        for(unsigned short l=0 ; l<vectX.getNbRow() ; l++)
        {
            for(unsigned short c=0 ; c<vectX.getNbColumn() ; c++)
            {
                myfile << vectX(l,c) << ", ";
            }
            myfile << std::endl;
        }
        myfile.close();
    }


    std::ofstream myfile2;
    myfile2.open (fileNameVectY.data(), std::ios::out );
    if(myfile2.is_open())
    {
        for(unsigned short l=0 ; l<vectY.getNbRow() ; l++)
        {
            for(unsigned short c=0 ; c<vectY.getNbColumn() ; c++)
            {
                myfile2 << vectY(l,c) << ", ";
            }
            myfile2 << std::endl;
        }
        myfile2.close();
    }
    return true;
}
