#include<iostream>
#include<fstream>
using namespace std;
class Student_Management
{
    private:
        string name,rollno,fname,address;
        fstream file;
    public:
        void Add_Student_Record();
        void View_All_Student_Records();
        void Search_Student_Records();
}obj;
int main()
{
    char choice;
    cout<<"-------------------------------------------------------------------------------------"<<endl;
    cout<<"1- Add student Record"<<endl;
    cout<<"2- View All Student Records"<<endl;
    cout<<"3- Search Stdent Record"<<endl;
    cout<<"4- Exit"<<endl;
    cout<<"-------------------------------------------------------------------------------------"<<endl;
    cout<<"Enter your choice"<<endl;
    cin>>choice;
    switch(choice)
    {
        case '1':
            obj.Add_Student_Record();
            break;

        case '2':
            obj.View_All_Student_Records();
            break;

        case '3':
            obj.Search_Student_Records();
            break;
        
        case '4':
            return 0;
            break;
        default:
            cout<<"Invalid Input... Please Try Again";
    }
    cout<<endl;
    return 0;
}
void Student_Management::Add_Student_Record()
{
    cin.ignore();
    cout<<"---------------------------------ADD STUDENT RECORD------------------------------------------"<<endl;
    cout<<"Enter student name\n";
    getline(cin,name);
    cout<<"Enter student roll number\n";
    getline(cin,rollno);
    cout<<"Enter student father name\n";
    getline(cin,fname);
    cout<<"Enter full student address\n";
    getline(cin,address);
    file.open("addData.txt",ios :: out | ios :: app);
    file<<name<<"*"<<rollno<<"*"<<fname<<"*"<<address<<endl;
    file.close();
}
void Student_Management::View_All_Student_Records()
{
    cin.ignore();
    cout<<"--------------------------------------VIEW ALL STUDENTS RECORD----------------------------"<<endl;
    file.open("addData.txt",ios :: in);
    getline(file,name,'*');
    getline(file,rollno,'*');
    getline(file,fname,'*');
    getline(file,address,'\n');
    while(!file.eof())
    {
        cout<<"Student's Name   :"<<name<<"     Student's Roll No.   ::"<<rollno<<"       Student's Father Name   ::"<<fname<<"         Student's Address   ::"<<address<<endl;
        getline(file,name,'*');
        getline(file,rollno,'*');
        getline(file,fname,'*');
        getline(file,address,'\n');
    }
    file.close();
}
void Student_Management::Search_Student_Records()
{
    cin.ignore();
    cout<<"-----------------------------------------------Search Student Records-----------------------------"<<endl;
    string searchname;
    cout<<"Enter student's name"<<endl;
    getline(cin,searchname);
    file.open("addData.txt",ios :: in);
    getline(file,name,'*');
    getline(file,rollno,'*');
    getline(file,fname,'*');
    getline(file,address,'\n');
    while(!file.eof())
    {
        if(name==searchname)
        {
            cout<<"Student's Name   ::"<<name<<"   Student's Rollno   ::"<<rollno<<"   Student's Father Name   ::"<<fname<<"   Address   ::"<<address<<endl;
        }
        getline(file,name,'*');
        getline(file,rollno,'*');
        getline(file,fname,'*');
        getline(file,address,'\n');
    }
    file.close();
}