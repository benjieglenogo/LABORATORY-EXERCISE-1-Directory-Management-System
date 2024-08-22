#include <string>
#include <iostream>
#include <cstdio> 
#include <cstdlib> 
#include <direct.h>
#include <windows.h>


    void DFiles(){
        system("dir");  // windows command ni!!
        system("pause");  // mag pause ang screen kadyot!!!
    }

void CRDirectory(){
    std::cout << "\nEnter the directory name: ";
    std::string dirName;
    std::cin >> dirName;

   