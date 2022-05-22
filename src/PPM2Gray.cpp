/*
Source: https://www.rkenmi.com/posts/ppm-image-to-grayscale-c?lang=jp
Step 1 - The class for PPM image: First, let's define a class for this PPM image.
Step 2 - Storing image data into object
*/

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>

class PPMImage {  
    public:
        PPMImage(){;};
        ~PPMImage(){
            delete threeChan;
        }

        friend std::istream& operator >>(std::ifstream& inputStream, PPMImage& img);
        friend std::ostream& operator <<(std::ofstream& outputStream, const PPMImage& img);
        
        void grayscale();

    private:
        std::string magicNumber;                // A "magic number" for identifying the file type
        int width;                              // Width of the image
        int height;                             // Height of the image
        int maxColorVal;                        // Maximum color value
        char *threeChan;                        // A series of rows and columns (raster) that stores important binary image data
};

std::istream& operator >>(std::ifstream& inputStream, PPMImage& img){  
    std::string fileName;
    char dump;

    inputStream >> img.magicNumber;

    std::string myString;
    inputStream >> myString;
    img.width = atoi(myString.c_str());

    inputStream >> myString;
    img.height = atoi(myString.c_str());

    inputStream >> myString;
    img.maxColorVal = atoi(myString.c_str());

    int memoryBlockSize = img.width * img.height * 3; //This means the size is 3 bytes

    img.threeChan = new char[memoryBlockSize];

    inputStream.read(&dump, 1); // ignore newline
    inputStream.read(img.threeChan, img.width * img.height * 3); //Read data into array

    return inputStream;
}

void PPMImage::grayscale(){  
    char *init, *reset;
    unsigned char oldRed, oldGreen, oldBlue, newRed, newGreen, newBlue;

    reset = threeChan;              // keep track of initial pointer position

    for(int i = 0; i < width * height; i++){
        init = threeChan;

        oldRed = *threeChan;
        threeChan++;
        
        oldGreen = *threeChan;
        threeChan++;
        
        oldBlue = *threeChan;

        newRed  = (oldRed * 0.299) + (oldGreen * 0.587) + (oldBlue * 0.114);
        newGreen = (oldRed * 0.299) + (oldGreen * 0.587) + (oldBlue * 0.114);
        newBlue = (oldRed * 0.299) + (oldGreen * 0.587) + (oldBlue * 0.114);

        threeChan = init;
        *threeChan = newRed;
        threeChan++;
        
        *threeChan = newGreen;
        threeChan++;
        
        *threeChan = newBlue;
        threeChan++;
    }
    threeChan = reset; // reset pointer position
}

std::ostream& operator <<(std::ofstream& outputStream, const PPMImage& img){  
    int memoryBlockSize = img.width * img.height * 3;
    outputStream << img.magicNumber << '\n' << img.width << ' ' << img.height << '\n' << img.maxColorVal << '\n';
    outputStream.write(img.threeChan, memoryBlockSize);

    return outputStream;
}

int main(){  
        PPMImage p;
        std::ifstream inStream;
        std::ofstream outStream;
        std::string srcFileName, outFileName;

        std::cout << "Please specify the source PPM filename: " << std::endl;
        // std::cin >> srcFileName;

        srcFileName = "monument.ppm";
        
        inStream.open(srcFileName);
        inStream >> p;
        inStream.close();
        
        std::cout << "Please specify the output PPM filename: " << std::endl;
        // std::cin >> outFileName;
        outFileName = "gray.ppm";
        
        p.grayscale();
        
        outStream.open(outFileName);
        outStream << p;
        outStream.close();
        
        std::cout <<  "The " << srcFileName << " has been converted to grayscale and saved as " << outFileName << std::endl;
}
