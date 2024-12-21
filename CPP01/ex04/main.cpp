#include <iostream>
#include <fstream>
#include <string>

void replace(const std::string& file, const std::string& s1, const std::string& s2) {
    std::ifstream inFile(file.c_str());
    if (!inFile.is_open()) {
        std::cerr << "Error: Could not open file." << std::endl;
        return;
    }

    std::string buffer;
    std::string line;
    while (std::getline(inFile, line)) {
        buffer += line + '\n';
    }
    inFile.close();

    std::string obuffer;
    std::string::size_type pos = 0;
    std::string::size_type len = s1.length();
    while ((pos = buffer.find(s1, pos)) != std::string::npos) {
        obuffer += buffer.substr(0, pos) + s2;
        pos += len;
        buffer = buffer.substr(pos);
        pos = 0;
    }
    obuffer += buffer;

    std::string outFileName = file + ".replace";
    std::ofstream outFile(outFileName.c_str());
    if (!outFile.is_open()) {
        std::cerr << "Error: Could not create output file." << std::endl;
        return;
    }
    outFile << obuffer;
    outFile.close();
    std::cout << "replaced \"" << s1 << "\" with \"" << s2 << "\"" << std::endl;
    std::cout << "output written to \"" << outFileName << "\"" << std::endl;
}

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cout << "usage: " << av[0] << " file strA strB" << std::endl;
        return 1;
    }

    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];

    replace(filename, s1, s2);

    return 0;
}