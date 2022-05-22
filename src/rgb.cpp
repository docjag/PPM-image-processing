#include "rgb.hpp"
#include "base.hpp"

RGB::RGB() : r(0), g(0), b(0){} 
RGB::RGB(float c) : r(c), g(c), b(c) {} 
RGB::RGB(float _r, float _g, float _b) : r(_r), g(_g), b(_b) {} 
    
// Operators Overloading
RGB::bool operator != (const RGB& rgb) const { 
	return rgb.r != r || rgb.g != g || rgb.b != b;
}

RGB::RGB& operator *= (const RGB& rgb){
    r *= rgb.r, g *= rgb.g, b *= rgb.b; 
    return *this;
}

RGB::RGB& operator += (const RGB& rgb){
    r += rgb.r, g += rgb.g, b += rgb.b; 
    return *this;
}

void RGB::ReadImage(const char* fileName){
    std::cout << "test" << std::endl;

}

void RGB::DisplayImage(){
    std::cout << "test" << std::endl;
}

friend float& operator += (float& f, const RGB rgb){
    f += (rgb.r + rgb.g + rgb.b) / 3.f; 
    return f;
}