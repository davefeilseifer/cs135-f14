#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>


struct ImageData {
	int width;
	int height;
	unsigned char*** data;
};

/* image_to_array:
		function to take an image filename, load that image (using OpenCV), and then
		turn those image data into a 3D array (row, column, channel).

	arguments:
		const char* filename: the filename of the image file to be loaded
	
	returns:
		struct ImageData: a struct containing the image data that was loaded,
						  along with the image properties		
*/

ImageData image_to_array( const char* filename );

cv::Mat array_to_image( ImageData data, const char* display_name );

