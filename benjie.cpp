#include <string>
#include <iostream>
#include <cstdio> 
#include <cstdlib> 
#include <direct.h>
#include <windows.h>


    void DFiles(){
        system("dir");  // windows command ni!!
        system("pause");  // mag pause ang screen kadali!!!
    }

void CRDirectory(){
    std::cout << "\nEnter the directory name: ";
    std::string dirName;
    std::cin >> dirName;
    
if (_mkdir(dirName.c_str()) == 0) {
        std::cout << "\nDirectory '" << dirName << "' Successfully Created\n";
    } else {
        std::cout << "\nFailed to Create Directory '" << dirName << "'\n";
    }

    system("pause");
}
   
