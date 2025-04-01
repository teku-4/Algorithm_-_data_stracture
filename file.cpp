#include <iostream>
#include <fstream>
using namespace std;

int main(){
	
	//to open frist declar of stream to write file
	//ofstream myFile;
	//myFile.open("hellow.txt");
	//myFile<<"hellow world this the file practicing code in c++";
	//myFile.close();

//to read string that are alred saved uses ifstream as we use to write ofstream

//appending file
//ofstream myFile;
//myFile.open("hellow.txt",ios::app);
     //myFile<<"\n this file is appended ";
    // myFile.close();
	//cout<<"\n file is appended succesfully"<<endl;
	
	//string text;
	
//ifstream myFile;
//	myFile.open("hellow.txt");
//	getline(myFile,text);
//	cout<<"the file is: "<<text<<endl;
//myFile.close(); 
//----------------------------------------------------
//appendindinding the name of students
//const int len=6;
//string name[len];
//for(int i=0;i<len;i++){
//	cout<<"Enter the name of "<<i+1<<"stud"<<endl;
//	getline(cin, name[i]);
//}
//for(int i=0;i<len;i++){
//	ofstream stud;
//	stud.open("studfile.txt",ios::app);
//	stud<<" - "<<name[i]<<endl;
//	stud.close();
//}
string name[6];
ifstream stud;
stud.open("studfile.tx");
for(int i=0;i<6;i++){
getline(stud,name[i]);
}
for(int j=0;j<6;j++){
cout<<name[j]<<endl;	
}

stud.close();
cout<<"file is succefully saved"<<endl;
		
	return 0;
}






























