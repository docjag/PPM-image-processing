/*
* In C++, build a set of classes that can input and display grayscale and color images. For the
* purposes of this program, displaying an image is the same as printing the pixel values to the
* screen as a grid.
*
* Your code should have an abstract base class from which you derive two classes. The first one
* will handle 8-bit grayscale images and the second will handle 24-bit RGB images (each of the red,
* green and blue components are each 8-bits). These classes should be able to read images from a
* file and display the pixel values on the screen.
*
* The file format that you will read is simple. Files have a header in the first line that has three
* pieces of data:
* 		**type
*		**height
*		**width
*
* Type is 0 for grayscale images and 1 for RGB images. Height and width provide the size of the
* image. The rest of the file consists of the pixel values of the image. Grayscale images will have
* width*height values in row-major order. RGB images will have 3*width*height values in row-major 
* order with pixels of red plane followed by those of the green and blue planes.
*
*/


#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <sstream>


class Base{
public:
    virtual int ReadImage(const char *filename) = 0;
    virtual void DisplayImage() = 0;

};


class RGB : public Base{

public:
    RGB() : r(0), g(0), b(0){} 
    RGB(float c) : r(c), g(c), b(c) {} 
    RGB(float _r, float _g, float _b) : r(_r), g(_g), b(_b) {} 
    
    // Operators Overloading
    bool operator != (const RGB& rgb) const { 
        return rgb.r != r || rgb.g != g || rgb.b != b; 
    }

    RGB& operator *= (const RGB& rgb){
        r *= rgb.r, g *= rgb.g, b *= rgb.b; 
        return *this;
    }

    RGB& operator += (const RGB& rgb){
        r += rgb.r, g += rgb.g, b += rgb.b; 
        return *this;
    }


    int ReadImage(const char *filename);

    void DisplayImage();


    float r, g, b; 
};

int RGB::ReadImage(const char *filename) 
{ 
    std::ifstream ifs;

    ifs.open(filename); 

    Image src; 
    
    try { 
        if (ifs.fail())
            throw("Can't open input file"); 
        
        std::string header; 
        int w, h, b; 
        
        ifs >> header; 
        
        if (strcmp(header.c_str(), "P6") != 0) 
            throw("Can't read input file"); 
        
        ifs >> w >> h >> b; 
        
        src.w = w; 
        src.h = h; 
        
        src.pixels = new Rgb[w * h];  //this is throw an exception if bad_alloc 
        
        ifs.ignore(256, '\n');  //skip empty lines in necessary until we get to the binary data 
        
        unsigned char pix[3];  //read each pixel one by one and convert bytes to floats 
        
        for (int i = 0; i < w * h; ++i) { 
            ifs.read(reinterpret_cast<char *>(pix), 3); 
            
            src.pixels[i].r = pix[0] / 255.f; 
            src.pixels[i].g = pix[1] / 255.f; 
            src.pixels[i].b = pix[2] / 255.f; 
        } 
        ifs.close();

    } catch (const char *err) { 
        fprintf(stderr, "%s\n", err); 
        ifs.close(); 
    } 
 
    return 0; 
}

void RGB::DisplayImage(){
    std::cout << "Test" << std::cout;
}

// class Image{
// public:
//     Image() : w(0), h(0), pixels(nullptr) {}

//     Image(const unsigned int& _w, const unsigned int& _h, const RGB& c = kBlack): 
//         w(_w), h(_h), pixels(NULL){
        
//         pixels = new RGB[w * h]; 
        
//         for (int i = 0; i < w * h; ++i) 
//             pixels[i] = c; 
//     } 
    
//     const RGB& operator [] (const unsigned int &i) const{
//         return pixels[i];
//     }


//     RGB& operator [] (const unsigned int &i){
//         return pixels[i];
//     }

//     ~Image(){
//         if (pixels != NULL) 
//             delete [] pixels;
//     }


//     unsigned int w, h;                                          //Image resolution 
//     RGB* pixels;                                                //1D array of pixels 
    
//     // Static variable
//     static const RGB kBlack, kWhite, kRed, kGreen, kBlue;       //Preset colors 

// };

// const RGB Image::kBlack = RGB(0); 
// const RGB Image::kWhite = RGB(1); 
// const RGB Image::kRed   = RGB(1,0,0); 
// const RGB Image::kGreen = RGB(0,1,0); 
// const RGB Image::kBlue  = RGB(0,0,1); 

int main(int argc, char const *argv[])
{
    


    return 0;
}