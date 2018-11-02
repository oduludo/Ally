/**
 * main.cpp
 *
 * Generate a new Ally app
 */

#include <iostream>
#include <fstream>
#include <boost/filesystem.hpp>
#include <sstream>


namespace fs = boost::filesystem;


/*
 * First commandline argument: The action
 * Available options:
 *     - create
 */
int main(int argc, char* argv[]) {

    std::cout<<"Welcome to Ally"<<std::endl;

    if (argv[1]) {

        fs::path path = fs::current_path();
        fs::path new_path = path / fs::path{argv[2]};

        // Create the directory
        if (fs::create_directory(new_path)) {
            std::cerr << "Directory Created: " << new_path << std::endl;
        }

        // Create files
        // TODO: Create files and folders (from the source folder).
//        std::stringstream ss = new_path.string() << ""
//        std::ofstream outfile("test.txt");
//
//        outfile << "my text here!" << std::endl;
//
//        outfile.close();



    } else {
        std::cout << "Arguments missing" << std::endl;
    }

    return 0;

}
