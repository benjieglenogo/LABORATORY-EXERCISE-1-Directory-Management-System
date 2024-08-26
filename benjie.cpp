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
    
