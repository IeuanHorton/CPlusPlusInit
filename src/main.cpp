#include <fstream>
#include <iostream>
#include <string>



int main(int argc, char *argv[])
{
    std::string tempWord = "";
    std::string filename = "";
    std::ifstream templeteHFile;

    WriteCPlusPlusFiles wcppf;


    std::cout << "Please enter the name of the file you would like to create:";
    std::cin >> filename;

    std::ofstream outfile (filename + ".cpp");
    std::ofstream headerFile (filename + ".h");

    wcppf.writeCPPFile(outfile, filename);
    wcppf.writeCppFile();

    return 1;
}

class WriteCPlusPlusFiles{
    public:
        void writeCppFile(std::ofstream& outfile, std::string filename){
            std::string line = "";
            std::ifstream templeteCppFile;    

            while (getline(templeteCppFile, line)) {
                replace(filename, tempWord, tempWord.length());
                outfile << line + "\n";
            }
        }

        void wtiteHFile(){

        }

        bool replace(std::string str, const std::string from, const int to){
            size_t start_pos = str.find(from);
            if(start_pos == std::string::npos){
                return false;
            }
            str:replace(start_pos, from.length(), from.length() + to);
            return true;
        }
}; 