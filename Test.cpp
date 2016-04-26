#include<iostream>
#include<string>
using namespace std;
class Student{
	char* name;
	char ID[15];
	char number[15];
	char speciality[15];
	int  age;
public:
	Student();
	Student(char* na,char* id,char* num,char* spec,int ag);
	Student(const Student &per);
	~Student();
	char* GetName();
	char* GetID();
    char* GetNumber();
	char* GetSpeciality();
    int   GetAge();
	void  Display();
    void  Input();
};
Student::Student(){
	name=NULL;
    age=0;
}
Student::Student(char* na,char*id,char* num,char* spec,int ag){
	if(na){
		name=new char[strlen(na)+1];
		strcpy(name,na);
	}
	strcpy(ID,id);
	strcpy(number,num);
	strcpy(speciality,spec);
	age=ag;
}
Student::Student(const Student &per){
	if(per.name){
		name=new char[strlen(per.name)+1];
		strcpy(name,per.name);
	}
		strcpy(ID,per.ID);
		strcpy(number,per.number);
		strcpy(speciality,per.speciality);
		age=per.age;
}
Student::~Student(){
	if(name)
		delete[]name;
}
char *Student::GetName(){
	return name;	
}
char *Student::GetID(){
	return ID;
}
char *Student::GetNumber(){
	return number;
}
char *Student::GetSpeciality(){
	return speciality;
}
int Student::GetAge(){
	return age;
}
void Student::Display(){
	cout<<"姓名："<<name<<endl;
	cout<<"身份证："<<ID<<endl;
	cout<<"学号："<<number<<endl;
	cout<<"专业："<<speciality<<endl;
	cout<<"年龄："<<age<<endl;
}
void Student::Input(){
	char na[10];
	if(name)
		delete[]name;
	name=new char[strlen(na)+1];
	cout<<"输入名字："<<endl;
	cin>>na;
	strcpy(name,na);
	cout<<"输入身份证："<<endl;
	cin>>ID;
	cout<<"输入学号："<<endl;
	cin>>number;
	cout<<"输入专业："<<endl;
	cin>>speciality;
	cout<<"输入年龄："<<endl;
	cin>>age;
}
const int N=10;
int count=0;
void menu();
void InputStu(Student *array);
int SearchStu(Student *array,char *na);
void OutputStu(Student *array);
int main(){
	Student array[N];
	int choice;
	do{
		menu();
	cin>>choice;
	if(choice>=0&&choice<=3){
		switch(choice){
		case 1:InputStu(array);break;
		case 2:cout<<"Please input the name you want to search"<<endl;
			char na[20];
			cin>>na;
			int i;
			i=SearchStu(array,na);
			if(i==N)
				cout<<"查无此人"<<endl;
			else
				array[i].Display();
			break;
		case 3:OutputStu(array);break;
		case 0:break;
		}
	}
	}while(choice);
	return 0;
}
void menu(){
	cout<<"*******1.录入信息*******"<<endl;
	cout<<"*******2.查询信息*******"<<endl;
	cout<<"*******3.浏览信息*******"<<endl;
	cout<<"*******0.退    出*******"<<endl;
}
void InputStu(Student *array){
	char ch;
	do{
		array[count].Input();
		count++;
		cout<<"是否需要继续输入?(Y or N}"<<endl;
		cin>>ch;
	}while(ch=='Y');
}
int SearchStu(Student *array,char *na){
	int i,j=N;
	for(i=0;i<count;i++){
		if(strcmp(array[i].GetName(),na)==0)
			j=i;
	}
	return j;
}
void OutputStu(Student *array){
	cout<<"全校学生总数"<<count<<endl;
	for(int i=0;i<count;i++){
		array[i].Display();
	}
}
