/*
    SotC_PALtoNTSC, by Etienne Bégué - www.txori.com
    Convert Shadow of the Colossus' upscaled texture by Sad Origami
    from EU (SCES-53326) to US (SCUS-97472) version

    Compile using w64devkit (https://github.com/skeeto/w64devkit):
    g++ -O3 -std=c++17 -o SotC_PALtoNTSC.exe SotC_PALtoNTSC.cpp -lstdc++fs
*/

#include <iostream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

std::string convertFileName(const std::string& filename) {
    std::string prefix = filename.substr(0, filename.size() - 8); // Remove the last 8 characters
    int middleNum = filename[filename.size() - 8] - '0' - 4; // Convert middle character to integer and subtract 4
    std::string newMiddleChar = std::to_string(middleNum); // Convert the result back to string
    std::string suffix = filename.substr(filename.size() - 7); // Get the last 7 characters
    return prefix + newMiddleChar + suffix; // Assemble the new filename
}

void copyAndRenameFiles(const std::string& sourceDir, const std::string& destinationDir) {
    for (const auto& entry : fs::recursive_directory_iterator(sourceDir)) {
        if (entry.is_regular_file()) {
            std::string sourceFilePath = entry.path().string();
            std::string relativePath = entry.path().lexically_relative(fs::path(sourceDir)).string();

            std::string newFilename = convertFileName(entry.path().filename().string());
            std::string destinationFilePath = destinationDir + "/" + newFilename;

            std::cout << "Source file: " << sourceFilePath << std::endl;

            try {
                fs::create_directories(fs::path(destinationFilePath).parent_path());
                if (fs::exists(destinationFilePath)) {
                    fs::remove(destinationFilePath);
                }
                fs::copy_file(sourceFilePath, destinationFilePath, fs::copy_options::overwrite_existing);
            } catch (const std::exception& e) {
                std::cerr << "Error copying file: " << e.what() << std::endl;
            }
        }
    }
}

int main() {
    std::string sourceDir = "SCES-53326/replacements";
    std::string destinationDir = "SCUS-97472/replacements";

    copyAndRenameFiles(sourceDir, destinationDir);

    return 0;
}
