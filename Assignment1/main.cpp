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

#define ARRAYSIZE 18

void displayImages(Mat image_array[]) {

	int index = 0;
	char c;
	

	while (index < ARRAYSIZE) {
		Mat image = image_array[index];
		imshow("Image", image);
		c = cv::waitKey();
		cv::destroyAllWindows();
		index++;

	}

}

void displayRedHue(Mat image_array[]) {

	Mat hls_image;
	int index = 0;
	char c;
	Mat mask1, mask2, combined;

	while (index < ARRAYSIZE) {

		cvtColor(image_array[index], hls_image, COLOR_BGR2HLS);

		
		inRange(hls_image, Scalar(0, 70, 50), Scalar(10, 255, 255), mask1);
		inRange(hls_image, Scalar(170, 70, 50), Scalar(180, 255, 255), mask2);
		//Since the red hue wraps around, we take two masks and combine them.

		combined = mask1 | mask2;

		imshow("Red Hue", combined);

		c = cv::waitKey();
		cv::destroyAllWindows();
		if (c == 'x')
			break;
		index++;
	}

}


void CalculateHueHistogram(Mat image_array[]) {

	char c;
	Mat hls_image;

	Mat mask1, mask2, combined;
	

	int index = 0;

	vector<Mat> hls_planes(3);
	


	int sum = 0;

	while (index < ARRAYSIZE) {
		cvtColor(image_array[index], hls_image, COLOR_BGR2HLS);

		inRange(hls_image, Scalar(0, 70, 50), Scalar(30, 255, 255), mask1);
		inRange(hls_image, Scalar(150, 70, 50), Scalar(180, 255, 255), mask2);
		//Since the red hue wraps around, we take two masks and combine them.

		combined = mask1 | mask2;

		split(hls_image, hls_planes);


		for (int y = 0; y < hls_image.rows; y++)
			for (int x = 0; x < hls_image.cols; x++) {
				if (hls_planes[0].at<uchar>(y, x) > 180) cout << "Hey wait a minute..." << endl;
				if (hls_planes[0].at<uchar>(y, x) < 30 || (hls_planes[0].at<uchar>(y, x) > 150 && hls_planes[0].at<uchar>(y, x) < 180))
					sum++;
			}
				

		cout << sum << endl;

		sum = 0;

		c = cv::waitKey();
		cv::destroyAllWindows();
		if (c == 'x')
			break;
		index++;
	}

}

void backProject(Mat imagearray[]) {

	//Histogram the image
	
	//Backproject this

	MatND* histogram = new MatND[imagearray[1].channels()];
	vector<Mat> channels(imagearray[1].channels());
	
	split(imagearray[1], channels);
	const int* channel_numbers = { 0 };
	float channel_range[] = { 0.0, 255.0 };

	const float* channel_ranges = channel_range;
	int number_bins = 64;
	
	for (int chan = 0; chan < imagearray[1].channels(); chan++)
		calcHist(&(channels[chan]), 1, channel_numbers, Mat(), histogram[chan], 1, &number_bins, &channel_ranges);


	//Threshold image to isolate spoon RGB values



}



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

	cout << "Press 1 to cycle through images." << endl;
	cout << "Press x to exit." << endl;

	int user_in;
	

	Mat image = image_arr[10];
	

	do {

		imshow("Image", image);
		user_in = cv::waitKey();
		cv::destroyAllWindows();
		

		switch (user_in) {
			case '1':
				displayImages(image_arr);
				break;
			case '2':
				displayRedHue(image_arr);
				break;
			case '3':
				CalculateHueHistogram(image_arr);
			default:
				break;

		}
		
	
	} while (user_in != 'x');


	cout << "Done." << endl;
}


	







	

	//Display Red and Hue Histogram
	//For each image, print out the number of spoons present.


