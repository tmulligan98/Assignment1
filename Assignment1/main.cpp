#include "Utilities.h"
#include <iostream>
#include <fstream>
#include <list>


//Macros
#define SAMPLE0 0
#define SAMPLE1 1
#define SAMPLE2 2

#define TEST1 3
#define TEST2 4
#define TEST3 5
#define TEST4 6
#define TEST5 7
#define TEST6 8
#define TEST7 9
#define TEST8 10
#define TEST9 11
#define TEST10 12
#define TEST11 13
#define TEST12 14
#define TEST13 15
#define TEST14 16
#define TEST15 17
#define TEST16 18
#define TEST17 19
#define TEST18 20


int main(int argc, const char** argv) {

	const char * file_location = "Media/";
	const char * image_files[] = {
		"BabyFood-Sample0.JPG", 
		"BabyFood-Sample1.JPG",
		"BabyFood-Sample2.JPG",
		"BabyFood-Test1.JPG",
		"BabyFood-Test2.JPG",
		"BabyFood-Test3.JPG",
		"BabyFood-Test4.JPG",
		"BabyFood-Test5.JPG",
		"BabyFood-Test6.JPG",
		"BabyFood-Test7.JPG",
		"BabyFood-Test8.JPG",
		"BabyFood-Test9.JPG",
		"BabyFood-Test10.JPG",
		"BabyFood-Test11.JPG",
		"BabyFood-Test12.JPG",
		"BabyFood-Test13.JPG",
		"BabyFood-Test14.JPG",
		"BabyFood-Test15.JPG",
		"BabyFood-Test16.JPG",
		"BabyFood-Test17.JPG",
		"BabyFood-Test18.JPG"};

	//Load the images to an array
	int num_images = sizeof(image_files) / sizeof(image_files[0]);
	//Construct array of Mat objects
	Mat* image_arr = new Mat[num_images];
	//Load images
	for (int i = 0; i < num_images; i++) {
		string filename(file_location);
		filename.append(image_files[i]);

		image_arr[i] = imread(filename, -1);
		if (image_arr[i].empty()) {
			cout << "ERROR: Could not open file " << image_arr[i] << endl;
			return -1;
		}
			
	}
	
};


	

	//Display the red channels of the image


	//Display images and handle SPACEBAR input to cycle through images


	//For each image, print out the number of spoons present.

