#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <bitset>
#include <stdio.h>
#include <string.h>
#include <direct.h>
#include <cctype>
#include <cstring>
#include<opencv2/opencv.hpp> //opencv Libraries that are needed to load images
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <sys/stat.h>
#include <windows.h>
#include <xlnt/xlnt.hpp>
#include <curl/curl.h>
#include "boost/filesystem.hpp"

using namespace std;




/////////////////////////////////////////////////////////

void image()
{
    Mat img = imread("D:/Test.jpg"); //Store image
    if (img.empty())
    {
        cout << "Image Not found";
        return 0;
    }
    namedWindow("image", WINDOW_NORMAL); //Create the window where the image will be stored
    setWindowProperty("image", WND_PROP_FULLSCREEN, WINDOW_FULLSCREEN); //Changing the window size to fullscreen
    imshow("image", img);//Function to show image

    waitKey(1000);//Waitkey() make the image stay for 1000ms (1 second) or until the user enters any key
    setWindowProperty("image", WND_PROP_FULLSCREEN, WINDOW_NORMAL); //Changing the window properties to normal so we can resize it
    resizeWindow("image", 600, 600); // Resizing the window
    imshow("image", img);
    waitKey(1000);

    setWindowProperty("image", WND_PROP_FULLSCREEN, WINDOW_FULLSCREEN);
    imshow("image", img);

    waitKey(0);
}

int main(){
	image();
	return 0;
}



