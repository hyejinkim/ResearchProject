#include "ray.h"
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#include <sys/stat.h>
#include <sys/types.h>

using namespace std;

void RayFunc()
{
    int a = 1;
	int b = 0;
    int check;
    string dir, newdir;
    string trash = "/mnt/d/project/trash";
    //Makes a new directory path called trash.
    check = mkdir(trash.c_str(), 0777);
    if (!check)
    {
        printf("Directory created\n");
    }
    else
    {
        printf("Unable to create directory\n");
        exit(1);
    }
    
	//Copies the file transcript.txt into trash directory
    system("cp ./transcript.txt /mnt/d/project/trash");

	//For loop is established to recursively create new directories of trash with it's content transcript.txt
	for(int i = 1; i <= 9; i++)
    {
		stringstream ss,fs;

		ss << "/mnt/d/project/trash" << i;
        dir = ss.str();
        check = mkdir(dir.c_str(), 0777);

		if (!check)
        {
            printf("Directory created\n");
        }
		else 
        {
			printf("Unable to create directory\n");
			exit(1);
        }

        string cmd = "cp /mnt/d/project/trash/transcript.txt " + dir;
        system(cmd.c_str());
		cout << "You have been hacked! Dumping trash" << i << endl;
    }


	//The web browser provided is opened up as many times as the value of 'a' is
	while(b < a){
		system("cmd.exe /C start https://hackerone.com/");
		b++;
	}

	//The system will start playing the mp4 file using it's default media player
	// system("start ./wisdomdog.mp4");
}