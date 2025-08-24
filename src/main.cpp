#include <fstream>
#include <iostream>
#include <string>
#include "Nutsedge.h"

class WriteCPlusPlusFiles{//TODO, push this to it's own file (maybe)
    
    private:
	    std::ifstream configFile;
	    std::string tempWord = "#TEMP#"; //TODO have this be easily changeable
	
    public:
        void writeCppFile(std::ofstream& outfile, std::ofstream& hOutfile, std::string filename){
            std::string line = ""; //string to read each line in the Templete File
            std::ifstream templeteCppFile; //TODO make and link file
	    templeteCppFile.open("template/template.cpp");

            while (getline(templeteCppFile, line)) {
		Nutsedge::AutoReplace(line, tempWord, filename);
                outfile << line + "\n";
            }

	    templeteCppFile.close();

	    std::ifstream templateHFile;
	    templateHFile.open("template/template.h");

	    while(getline(templateHFile, line)) {
	 	Nutsedge::AutoReplace(line, tempWord, filename);
		hOutfile << line + "\n";
	    }

	    templateHFile.close();
        }

	void gatherTempWord(){
		configFile.open("config.txt");
		if(!configFile.good()){
			std::string line = "";
			getline(configFile, line);
			tempWord = line;
		}
	}
}; 

int main(int argc, char *argv[])
{
    std::string filename = "";
    std::ifstream templeteHFile;

    WriteCPlusPlusFiles wcppf;

    wcppf.gatherTempWord();

    std::cout << "Please enter the name of the file you would like to create:";
    std::cin >> filename;//Gets file name from the user

    std::ofstream outfile (filename + ".cpp");//Creates CPP file with the given name
    std::ofstream headerFile (filename + ".h");//Creates Header file

    wcppf.writeCppFile(outfile,headerFile, filename);

    return 1;
}
