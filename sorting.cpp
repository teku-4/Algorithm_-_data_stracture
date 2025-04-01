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
string temp;
for(int j=0;j<5;j++){
	for(int s=j+1;s<6;s++){
		if(name[j]>name[s]){
		    temp=name[j];
			name[j]=name[s];
			name[s]=temp;
		}
	}
cout<<name[j]<<endl;	
}

stud.close();
string keyname;
//----------------------------------------
cout<<"enter the name of students to search"<<endl;
	getline(cin,keyname);
	int index=0;
for(int a=0;a<6;a++){
	if(name[a]==keyname){
	index=a;
	break;	
	}
}
if(index==0){
	cout<<"the name you entered is not in this file"<<endl;
	
}
else{
	cout<<"the name you search is found at "<<index<<"whose name is "<<keyname<<endl;
}	
		
	return 0;
}






























