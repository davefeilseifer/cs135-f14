#include "image_to_array.h"
#include <stdio.h>

ImageData image_to_array( const char* filename )
{
	ImageData ret;

	cv::Mat image;
    image = cv::imread(filename, CV_LOAD_IMAGE_COLOR);   // Read the file

	ret.height = image.rows;
	ret.width = image.cols;

    if(! image.data )                              // Check for invalid input
    {
        printf("Could not open or find the image\n" );
        exit(-1);
    }

	// allocate memory for image
	ret.data = new unsigned char**[ret.height];
	for(int i = 0; i < ret.height; i++ )
	{
		ret.data[i] = new unsigned char*[ret.width];
		for( int j = 0; j < ret.width; j++ )
		{
			ret.data[i][j] = new unsigned char[3];
		}
	}

	// set image data
	for( int i = 0; i < ret.height; i++ )
	{
		for( int j = 0; j < ret.width; j++ )
		{
			for( int k = 0; k < 3; k++ )
			{
				ret.data[i][j][k] = image.at<cv::Vec3b>(i,j)[k];
			}
		}
	}

	return ret;
}

cv::Mat array_to_image( ImageData data, const char* display_name )
{
	// initialize image
	cv::Mat out_image(data.height,data.width, CV_8UC3, cv::Scalar(0,0,0));

	// copy image data to array
	for( int i = 0; i < data.height; i++ )
	{
		for( int j = 0; j < data.width; j++ )
		{
			for( int k = 0; k < 3; k++ )
			{
				out_image.at<cv::Vec3b>(i,j)[k] = data.data[i][j][k];
			}
		}
	}

	if( display_name != NULL )
	{

		// display image 
    	cv::namedWindow( display_name, cv::WINDOW_AUTOSIZE );// Create a window for display.
	    cv::imshow( display_name, out_image );                   // Show our image inside it.

	}
	return out_image;
}

