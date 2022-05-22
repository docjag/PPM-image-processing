#include "img.hpp"
#include "rgb.hpp"



Image::Image() : w(0), h(0), pixels(nullptr) {}

Image::Image(const unsigned int& _w, const unsigned int& _h, const RGB& c = kBlack): 
    w(_w), h(_h), pixels(NULL){
    
    pixels = new RGB[w * h]; 
    
    for (int i = 0; i < w * h; ++i) 
        pixels[i] = c; 
} 

const RGB& operator [] (const unsigned int &i) const{
    return pixels[i];
}


RGB& operator [] (const unsigned int &i){
    return pixels[i];
}

Image::~Image(){
    if (pixels != NULL) 
        delete [] pixels;
}



const RGB Image::kBlack = RGB(0); 
const RGB Image::kWhite = RGB(1); 
const RGB Image::kRed   = RGB(1,0,0); 
const RGB Image::kGreen = RGB(0,1,0); 
const RGB Image::kBlue  = RGB(0,0,1); 