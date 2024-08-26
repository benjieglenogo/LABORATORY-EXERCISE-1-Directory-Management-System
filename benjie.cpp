#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

void display_main_menu();
void list_files_menu();
void list_all_files();
void create_directory();
void change_directory();

int main() {
    int choice;

    while (true) {
        display_main_menu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                list_files_menu();
                break;
            case 2:
                create_directory();
                break;
            case 3:
                change_directory();
                break;
            case 4:
                std::cout << "Exiting the program...\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
}
    void display_main_menu() {
    std::cout << "\nMAIN MENU\n";
    std::cout << "1. Display List of Files\n";
    std::cout << "2. Create New Directory\n";
    std::cout << "3. Change the Working Directory\n";
    std::cout << "4. Exit\n";
    std::cout << "Enter the Number: ";
}

void list_files_menu() {
    int choice;
    std::cout << "\nLIST FILE DETAIL\n";
    std::cout << "1. List All Files\n";
    std::cout << "2. List Files by Extension\n";
    std::cout << "3. List Files by Name\n";
    std::cout << "Enter the Number: ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            list_all_files();
            break;
        case 2:
            std::cout << "Listing files by extension is not yet implemented.\n";
            
            break;
        case 3:
            std::cout << "Listing files by name is not yet implemented.\n";
            
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
    }
}
  void list_all_files() {
    int file_count = 0;

    std::cout << "\nList of All Files:\n";

    try {
        for (const auto& entry : fs::directory_iterator(fs::current_path())) {
            if (fs::is_regular_file(entry)) {
                std::cout << entry.path().filename().string() << '\n';
                file_count++;
            }
        }
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

    std::cout << "\nTotal Files: " << file_count << '\n';
    std::cout << "Press any key to continue.";
  
}
   void create_directory() {
    std::string dir_name;
    std::cout << "Enter the name of the new directory: ";
    std::cin >> dir_name;

    try {
        if (fs::create_directory(dir_name)) {
            std::cout << "Directory '" << dir_name << "' created successfully.\n";
        } else {
            std::cout << "Failed to create directory. It may already exist.\n";
        }
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

    std::cout << "Press any key to continue.";
   
}

void change_directory() {
    std::string dir_path;
    std::cout << "Enter the path of the new working directory: ";
    std::cin >> dir_path;

    try {
        fs::current_path(dir_path);
        std::cout << "Changed working directory to '" << fs::current_path().string() << "'.\n";
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

    std::cout << "Press any key to continue.";

}
