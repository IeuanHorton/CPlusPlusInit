#include <fstream>
#include <iostream>
#include <string>

class WriteCPlusPlusFiles{
    public:
        void writeCppFile(std::ofstream& outfile, std::string filename){
            std::string line = "";
            std::ifstream templeteCppFile;    

            while (getline(templeteCppFile, line)) {

                outfile << line + "\n";
            }
        }

        void writeHFile(){

        }

    private:
        std::string tempWord = "";
}; 

int main(int argc, char *argv[])
{
    std::string filename = "";
    std::ifstream templeteHFile;

    WriteCPlusPlusFiles wcppf;

    std::cout << "Please enter the name of the file you would like to create:";
    std::cin >> filename;//Gets file name from the user

    std::ofstream outfile (filename + ".cpp");//Creates CPP file with the given name
    std::ofstream headerFile (filename + ".h");//Creates Header file

    wcppf.writeCppFile(outfile, filename);
    wcppf.writeHFile();

    return 1;
}
