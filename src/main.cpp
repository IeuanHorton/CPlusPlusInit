#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    std::string filename = "";

    std::cout << "Please enter the name of the file you would like to create:";
    std::cin >> filename;

    std::ofstream outfile (filename + ".cpp");
    std::ofstream headerFile (filename + ".h");


}