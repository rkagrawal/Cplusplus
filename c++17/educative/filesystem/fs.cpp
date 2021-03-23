#include <filesystem>
#include <iomanip>  
#include <iostream>

namespace fs = std::filesystem;

void DisplayDirectoryTree(const fs::path& pathToScan, int level = 0) {
    for (const auto& entry : fs::directory_iterator(pathToScan)) {
        const auto filenameStr = entry.path().filename().string();
        if (entry.is_directory()) {
            std::cout << std::setw(level * 3) << "" << filenameStr << '\n';
            DisplayDirectoryTree(entry, level + 1);
        }
        else if (entry.is_regular_file()) {
            std::cout << std::setw(level * 3) << ""<< filenameStr
                << ", size " << fs::file_size(entry) << " bytes\n";
        }
        else
            std::cout << std::setw(level * 3) << "" << " [?]" << filenameStr << '\n';
    }
}
int main(int argc, char* argv[]) {
    try  {
        const fs::path pathToShow{ argc >= 2 ? argv[1] : fs::current_path() };

        std::cout << "listing files in the directory: " 
                  << fs::absolute(pathToShow).string() << '\n';

        DisplayDirectoryTree(pathToShow);
    }
    catch (const fs::filesystem_error& err) {
        std::cerr << "filesystem error! " << err.what() << '\n';

    }
    catch (const std::exception& ex) {
        std::cerr << "general exception: " << ex.what() << '\n';
    }
}
