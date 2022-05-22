#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>





int main(int argc, char const *argv[])
{
	std::ofstream image;
	image.open("test.ppm");

	srand(time(0));

	if(image.is_open()){
		// Place Header info
		image << "P3" << std::endl;
		image << "250 250" << std::endl;
		image << "255" << std::endl;

		for(int y = 0; y < 250; ++y){
			for(int x = 0; x < 250; ++x){
				image << (x * y) % 255 << " " << x << " " << x << std::endl;
				// image << (x * y) % 255 << " " << (x * y) % 255 << " " << (x * y) % 255 << std::endl;
				// image << rand() % 255 << " " << rand() % 255 << " " << rand() % 255 << std::endl;
			}
		}
	}

	image.close();
	
	return 0;
}