#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;
int main(){
    // string studname;
    // cout<<"Enter the the number of stud you want to insert: ";
    // int len;
    // cin>>len;
    // cin.ignore();
    // ofstream  myfile;
    // myfile.open("studinfo.txt",ios::app);
    // for(int i=0;i<len;i++){
    //     cout<<"Name of stud "<<(i+1)<<" ";
    //     getline(cin,studname);
    //     if(studname.empty()){
    //   continue;}
    //     myfile<<"\n"<<studname<<endl;
        
    // }
    // myfile.close();
    // cout<<"student file is saved"<<endl;
    // ifstream file("studinfo.txt");
    // if (!file) {
    //     cout << "Error: Cannot open file!\n";
    //     return 1;
    // }

    // cout << "Enter name to search: ";
    // string searchTerm;
    // getline(cin, searchTerm);
    // // searchTerm = toLower(searchTerm);

    // cout << "\nSearch results:\n";
    // string name;
    // bool found = false;
    
    // while (getline(file, name)) {
    //     if (name.find(searchTerm)!=string::npos){
    //         cout << "- " << name << endl;
    //         found = true;
    //     }
    // }

    // if (!found) {
    //     cout << "No matches found.\n";
    // }

    // file.close();
    char ch;
    cout<<"enter character to search"<<endl;
    cin>>ch;
    ifstream File;
    File.open("studinfo.txt");
    if(!File){
        cout<<"file open error"<<endl;
        return 1;
    }
    string names;
    while(getline(File,names)){
        for(int i=0;i<names.size();i++){
            if(names[i]==ch){
                cout<<"-"<<names<<endl;
            }
        }
    }
    return 0;
}