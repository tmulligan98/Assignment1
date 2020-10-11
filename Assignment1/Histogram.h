#include "Utilities.h"
#include <iostream>
#include <fstream>
#include <list>

class Histogram
{
protected:
	Mat mImage;
	int mNumberChannels;
	int* mChannelNumbers;
	int* mNumberBins;
	float mChannelRange[2];

public:
	Histogram(Mat Image, int number_of_bins);
	void ComputeHistogram();

};

