#include<iostream>
#include<string>
using namespace std;
#define SIZE 80
class Student{
	char *name;//姓名
	char ID[19];//身份证
	char number[10];//学号
	char speciality[20];//专业
	int  age;//年龄
public:
    Student();
	Student(char*na,char*id,char*num,char*spec,int ag);
	Student(const Student &per);
	~Student();
	char *GetName();
	char *GetID();
	char *GetNumber();
	char *GetSpec();
	int   GetAge();
	void Display();
	void Input();
};
Student::Student(){
	name=NULL;
	age=0;
}
Student::Student(char*na,char*id,char*num,char*spec,int ag){
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
	strcpy(speciality,per.speciality );
	age=per.age;
}
Student::~Student(){
	if(name)
		delete[]name;
}
char* Student::GetName(){
	return name;
}
char* Student::GetID(){
	return ID;
}
char* Student::GetNumber(){
	return number;
}
char* Student::GetSpec(){
	return speciality;
}
int Student::GetAge(){
	return age;
}
void Student::Display(){
	cout<<"学生信息："<<endl;
	cout<<"学生姓名  "<<name<<endl;
    cout<<"身份证号  "<<ID<<endl;
	cout<<"学 生 号  "<<number<<endl;
	cout<<"专    业  "<<speciality<<endl;
	cout<<"年    龄  "<<age<<endl;
}
void Student::Input(){
	char a[15];
	cout<<"输入姓名："<<endl;
	cin>>a;
	if(name)
		delete[]name;
	name=new char[strlen(a)+1];
	strcpy(name,a);
	cout<<"输入身份证号："<<endl;
	cin>>ID;
	cout<<"输入学生号："<<endl;
	cin>>number;
	cout<<"输入专业："<<endl;
	cin>>speciality;
	cout<<"输入年龄："<<endl;
	cin>>age;
}
void menu();
void InputStu(Student *array);
void OutputStu(Student *array);
int InsearStu(char *na,Student *array);
const int N=10;
int count=0;
int main(){
	Student array[N];
	int choice;
	do{
		menu();
	cout<<"Please input your choice"<<endl;
	cin>>choice;
	if(choice>=0&&choice<=3){
		switch(choice){
		case 1:InputStu(array);break;
		case 2:cout<<"Please input the name which you want to search"<<endl;
			char na[20];
			cin>>na;
			int i;
			i=InsearStu(na,array);
			if(i==N){
				cout<<"查无此人！"<<endl;
			}
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
	cout<<"**********1.录入信息**********"<<endl;
	cout<<"**********2.查询信息**********"<<endl;
	cout<<"**********3.浏览信息**********"<<endl;
	cout<<"**********0.退    出**********"<<endl;
}
void InputStu(Student *array){
	char ch;
	do{
		array[count].Input();
		count++;
		cout<<"你想要继续输入吗？Y or N"<<endl;
		cin>>ch;
	}while(ch=='Y');
}
int  InsearStu(char *na,Student *array){
	int i,j=N;
	for(i=0;i<count;i++){
		if(strcmp(array[i].GetName(),na)==0)
			j=i;
	}
	return j;
}
void OutputStu(Student *array){
	cout<<"学生总人数"<<count<<endl;
	for(int i=0;i<count;i++){
		array[i].Display();
	}
}




























