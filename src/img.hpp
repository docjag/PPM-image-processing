#ifndef IMG_HPP
#define IMG_HPP


class Image{
public:
    Image() : w(0), h(0), pixels(nullptr) {}

    Image(const unsigned int& _w, const unsigned int& _h, const RGB& c = kBlack): 
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

    ~Image(){
        if (pixels != NULL) 
            delete [] pixels;
    }


    unsigned int w, h;                                          //Image resolution 
    RGB* pixels;                                                //1D array of pixels 
    
    // Static variable
    static const RGB kBlack, kWhite, kRed, kGreen, kBlue;       //Preset colors 

};

#endif