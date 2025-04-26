#include <fstream>
#include <iostream>
using namespace std;
int main(){
    //buble sort
    string studs[]={"Abebe Beleachew","Makbel Kebede","Bereket Natneal","Barkot Samuel","Getachew Alemu","Abebe Alemayehu","Yayobe Shambel"};
  int len=sizeof(studs)/sizeof(studs[0]);
  for(int i=len-2;i>=0;i--)
   {
    for(int j=0;j<i;j++){
        if(studs[j]>studs[j+1]){
            swap(studs[j],studs[j+1]);
        }
    }
   }
   //file saving
   ofstream file;
   file.open("studFile.txt",ios::app);
   for(int i=0;i<len;i++){
    file<<studs[i]<<endl;
   }
   file.close();
   cout<<"the folowing file are saved succefully"<<endl;
   for(string name:studs){
    cout<<name<<endl;
   }
   string name, targetname;

   cout<<"enter the frist name you want to search ";
   cin>>targetname;
   cout<<endl;
   bool found=false;
   ifstream files;
   while(getline(files,name))
   {
    if(name.find(targetname)!=string::npos){
        cout<<"Name: "<<name;
        found=true;
    }
   }
   if(!found){
    cout<<"\nthere is no such file";
   }
    return 0;
}