#include <string>
#include <iostream>
#include <cstdio> 
#include <cstdlib> 
#include <direct.h>
#include <windows.h>

void listFiles (const string&path) {
  cout << "Listing files in Directory" << path << endl;
  WIN32_FIND_DATA findFileData;
  HANDLE hFind=FindFirstFile((path+"/*").c_str(),findFindData);
  if(hFind==INVALID_HANDLE_VALUE){
       cout <<"Error could not open directory"<< endl;
       return;
     }
     
    
