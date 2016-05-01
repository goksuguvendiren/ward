#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <dirent.h>
#include "../Header/bitmap.h"
#include "../Header/image.h"
#include "../Header/ward.h"

using namespace std;

int main(int argc, const char* argv[])
{
	clock_t begin = clock();

	/*string path;
	if (argc < 2) {
		cout << "A full file path is necessary as argument." << endl;
		exit(1);
	}

		path = argv[1];
		vector<string> filenames;
		vector<string> paths;

		DIR* directory;
		struct dirent *ent;

		if ((directory = opendir (path.c_str())) != NULL) {
			/* print all the files and directories within directory */
			/*while ((ent = readdir (directory)) != NULL) {
				string filename = string(ent->d_name);
				if (filename.find("JPG") == string::npos)
					continue;

				paths.push_back(path + filename);
				filenames.push_back(filename);
			}
		closedir (directory);
	} else {
		perror ("");
		return EXIT_FAILURE;
	}*/


	Image imageRef("/home/goksu/Samples/hand_held_exposures/bergama_01/IMG_6067.JPG");
	Image image("/home/goksu/Samples/hand_held_exposures/bergama_01/IMG_6068.JPG");

	Ward ward(imageRef, image);
	ward.Compute();


	return 0;
}