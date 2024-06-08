/*
    SotC_PALtoNTSC, by Etienne Bégué - www.txori.com
    Convert Shadow of the Colossus' remastered texture by Sad Origami
    from PAL (SCES-53326) to NTSC (SCUS-97472) version

    Compile using w64devkit (https://github.com/skeeto/w64devkit):
    g++ -O3 -std=c++17 -o SotC_PALtoNTSC.exe SotC_PALtoNTSC.cpp
*/

#include <iostream>
#include <filesystem>
#include <string>

// Folder paths
const std::string SOURCE_DIR = "SCES-53326/replacements";
const std::string DESTINATION_DIR = "SCUS-97472/replacements";

namespace fs = std::filesystem;

// Function to display an exit message and wait for user input
void exitMessage() {
    std::cout << std::endl;
    std::cout << "Press any key to exit" << std::endl;
#ifdef _WIN32
    system("pause >nul");
#else
    system("read -n 1 -s -r -p \"\"");
#endif
}

// Function to convert dds file nomenclature from PAL to NTSC
std::string convertFileName(const std::string& filename) {
    std::string prefix = filename.substr(0, filename.size() - 8); // Remove the last 8 characters
    int middleNum = filename[filename.size() - 8] - '0' - 4; // Convert middle character to integer and subtract 4
    std::string newMiddleChar = std::to_string(middleNum); // Convert the result back to string
    std::string suffix = filename.substr(filename.size() - 7); // Get the last 7 characters
    return prefix + newMiddleChar + suffix; // Assemble the new filename
}

void copyAndRenameFiles(const std::string& sourceDir, const std::string& destinationDir) {
    if (!fs::exists(sourceDir)) {
        std::cerr << "Error: Source directory '" << sourceDir << "' does not exist." << std::endl;
        exitMessage();
    }

    for (const auto& entry : fs::recursive_directory_iterator(sourceDir)) {
        if (entry.is_regular_file()) {
            std::string sourceFilePath = entry.path().string();
            std::string relativePath = entry.path().lexically_relative(fs::path(sourceDir)).string();

            // Skip files in "5) Bonus Material" folder that aren't present in the NTSC version
            if (sourceFilePath.find("5) Bonus Material") != std::string::npos) {
                continue;
            }

            std::string newFilename = convertFileName(entry.path().filename().string());
            std::string relativeDir = entry.path().parent_path().lexically_relative(fs::path(sourceDir)).string();
            std::string destinationFilePath = (fs::path(destinationDir) / fs::path(relativeDir) / newFilename).string();

            std::cout << sourceFilePath << std::endl;

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
    copyAndRenameFiles(SOURCE_DIR, DESTINATION_DIR);
    exitMessage();
    return 0;
}
