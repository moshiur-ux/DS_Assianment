#include<bits/stdc++.h>
#define MAX 3
using namespace std;
class Course{
private:
    double credits;
    double Grade;
public:
    void set_credit()
    {
        cin>>credits;
    }
    double get_credit()
    {
        return credits;
    }
    void set_grade(double grade)
    {
        Grade=grade;
    }
    double get_grade()
    {
        return Grade;
    }
};
class Student{
private:

    Course total_number_of_course[MAX];
    int student_ID;
    float grade;
    double CGPA;

public:
    int merit_position;
    double getcgpa()
    {
      return CGPA;
    }
    int get_ID()
    {
        return student_ID;
    }
    void get_student_information(int k)
    {
        double total_credit=0.00;
        double total_earn_credit=0.00;
      cout<<"Enter the Student ID:"<<endl;
      cin>>student_ID;
      for(int i=0;i<MAX;i++)
      {
        cout<<"course:"<<i+1<<endl;
        cout<<"Grade:"<<endl;
        cin>>grade;
        total_number_of_course[i].set_grade(grade);
        cout<<"Credits:"<<endl;
        total_number_of_course[i].set_credit();
        total_credit+=total_number_of_course[i].get_credit();
        total_earn_credit+=total_number_of_course[i].get_credit()*grade;
      }
       CGPA= total_earn_credit/total_credit;
    }
};
 void get_merit(Student student[],int N){
    for(int i=0;i<N;i++){
        int merit=0;
        for(int j=0;j<N;j++){
            if(student[i].getcgpa()<student[j].getcgpa()) merit++;
        }student[i].merit_position=merit+1;
    }
 }
void result(Student student[],int Student_Number,int i)
{
    cout<<"Student ID:"<<student[i].get_ID()<<endl;
  cout<<"CGPA:"<<fixed<<setprecision(2)<<student[i].getcgpa()<<endl;
  cout<<"Merit Position:"<<student[i].merit_position<<endl;
}

int main(){
    cout<<"The number of student: ";
    int Student_Number;
    cin>>Student_Number;
     Student *student=new Student[Student_Number];
    for(int i=0;i<Student_Number;i++)
        {
       student[i].get_student_information(i);
    }
      get_merit(student,Student_Number);
    for(int i=0;i<Student_Number;i++)
    {
       result(student,Student_Number,i);
    }


    return 0;
}
