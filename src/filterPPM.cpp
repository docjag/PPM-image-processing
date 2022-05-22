/*

Minilab Image Programming:
==========================
* (1) Your program will need 5 filters. You need:
* 	** at least one single color filter(can't be blue), 
* 	** one double/triple color filter (think changing multiple values),
*   ** and, the 3 other filters of your choice.

*   The 3 other of your choice can anything you want, they don't have to change colors.
*   they add things like borders to the photo.
* (2) Each filter needs its own function.
* (3) The user should be able to interact with your program by entering the name of the image
* and what filter should be applied.

*/

#include <iostream>
#include <fstream>
#include <sstream>



int main(int argc, char const *argv[])
{
	std::ifstream image;
	std::ofstream newImage;

	image.open("testimages/monument.ppm");
	newImage.open("outputimages/newMonument.ppm");

	// Copy over header information
	std::string type = "", width = "", height = "", RGB = "";
	image >> type;
	image >> width;
	image >> height;
	image >> RGB;

	// Insert meta data into the new image
	newImage << type << std::endl;
	newImage << width << " " << height << std::endl;
	newImage << RGB << std::endl;

	// Iterate through whole image and filter 
	std::string red="", green="", blue="";
	int r = 0, g = 0, b = 0;

	while(!image.eof()){
		image >> red;
		image >> green;
		image >> blue;

		std::stringstream redStringStream(red);
		std::stringstream greenStringStream(green);
		std::stringstream blueStringStream(blue);

		redStringStream >> r;
		greenStringStream >> g;
		blueStringStream >> b;

		// Filter Blue channel
		if(b + 50 > 255)
			b = 255;
		else
			b += 50;

		// Insert new pixel value to new image
		newImage << 255 << " " << 220 << " " << 220 << std::endl;
		newImage << r << " " << g << " " << b << std::endl;

	}

	image.close();
	newImage.close();



	return 0;
}