#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <dirent.h>

using namespace std;

int main(int argc, const char* argv[])
{
	clock_t begin = clock();

	string path;
	if (argc < 2) {
		cout << "A full file path is necessary as argument." << endl;
		exit(1);
	}

	int lambda = 250;
	if (argc == 3){
		lambda = stoi(string(argv[2]));
	}

	path = argv[1];
	vector<string> filenames;
	vector<string> paths;

	DIR* directory;
	struct dirent *ent;

	if ((directory = opendir (path.c_str())) != NULL) {
        /* print all the files and directories within directory */
	    while ((ent = readdir (directory)) != NULL) {
			string filename = string(ent->d_name);
			if (filename.find("JPG") == string::npos)
				continue;

			filenames.push_back(filename);
	  	}
	  	closedir (directory);
	} else {
	  	/* could not open directory */
	  	perror ("");
	  	return EXIT_FAILURE;
	}

	return 0;
}