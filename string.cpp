#include <iostream>
#include <cstdlib>//toclear system
#include <conio.h>//for getch to stain
#include <cctype>//to upper or lower case
#include <cstring>


using namespace std;

int main(){
	string name;
	cout<<"enter your name ?"<<endl;
	getline(cin,name);
 
	cout<<name<<endl;
	cout<<"your name contais a charcter"<<endl;
	int count=0;
	for(int i=0;i<name.size();i++ ){
		if (name[i]=='A' || name[i]== 'a' ){
			count++;
		}
	}
	cout<<"the numbers of character a in ur name is "<<count<<endl;
	string text;
	getch();
	system("cls");
	cout<<"enter the sentence"<<endl;
	
	getline(cin,text);
	int cont=0;
	for(int i=0;i<text.size();i++){
		if(text[i]==' '){
			cout<<"\n";
			cont++;
		}
	}
	cout<<"the senten you entered ocntanis "<<(cont+1) <<" words"<<endl;
	return 0;
}
