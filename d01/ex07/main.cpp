#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char const *argv[])
{
    if (argc == 4) {
        std::string filename = argv[1];
        std::ifstream   ifs(filename);
        std::ofstream   ofs(filename + ".replace");

        if (!ifs || !ofs)
        {
            std::cerr << "Error opening files!" << std::endl;
            return 1;
        }

        std::ostringstream ss;
        ss << ifs.rdbuf();
        std::string res = ss.str();

        size_t pos = res.find(argv[2]);
        while (pos != std::string::npos) {
            res.replace(pos, std::strlen(argv[2]), argv[3]);
            pos = res.find(argv[2], pos + std::strlen(argv[3]));
        }

        ofs << res;

        ifs.close();
        ofs.close();
    } else {
        std::cout << "usage: FILENAME S1 S2" << std::endl;
    }
    return 0;
}