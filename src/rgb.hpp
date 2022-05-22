#ifndef RGB_HPP
#define RGB_HPP

class RGB : public Base{

public:
    RGB(); 
    RGB(float c);
    RGB(float _r, float _g, float _b);
    
    // Operators Overloading
    bool operator != (const RGB& rgb) const;
    RGB& operator *= (const RGB& rgb);
    RGB& operator += (const RGB& rgb);

    void ReadImage(const char* fileName);

    void DisplayImage();

    friend float& operator += (float& f, const RGB rgb);

private:
    float r, g, b; 
};

#endif
