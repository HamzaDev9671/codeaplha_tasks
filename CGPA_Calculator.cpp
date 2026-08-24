#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

class Course{
public:
   string name, grade;
   int credit_hrs;
   float grade_points, quality_points;

   float gradetoPoints(){
        if(grade == "A"){
          return grade_points = 4.0;
         }
        else if(grade == "A-"){
          return grade_points = 3.7;
         }
         else if(grade == "B+"){
          return grade_points = 3.3;
         }
         else if(grade == "B"){
          return grade_points = 3.0;
         }
         else if(grade == "B-"){
          return grade_points = 2.7;
         }
         else if(grade == "C+"){
          return grade_points = 2.3; 
         }
         else if(grade == "C"){
          return grade_points = 2.0;
         }
         else if(grade == "D"){
          return grade_points = 1.0;
         }
         else if(grade == "F"){
          return grade_points = 0.0;
         }
         else{
          cout<<"\nInvalid Grade Input\n";
          return -1;
         }
      }

   float CalculateQualityPoints(){
        return quality_points = grade_points * credit_hrs;
      }
};

class Semester{
public:
  int Semcredit_hrs;
  float Sgpa, SemqualityPoints;

  float CalculateQualityPoints(){
    SemqualityPoints = Sgpa * Semcredit_hrs;
    return SemqualityPoints;
  }
};


int main(){
    cout<<fixed<<setprecision(2);
    cout<<"=== GPA Calculator ===";
    cout<<"\n--------------------------------";
    int choice;
    do{
    cout<<"\nWhat do you want to calculate: ";
    cout<<"\n1). SGPA";
    cout<<"\n2). CGPA";
    cout<<"\n3). Exit";
    
    cout<<"\nEnter your choice: ";
    cin>>choice;

    switch (choice){
    case 1:{
      vector <Course> courses;
    
      int totalCreditHours = 0;
      float totalQualityPoints = 0.0;
      float sgpa = 0.0;
   
      int n;
      do{
      cout<<"\nEnter number of courses: ";
      cin>>n;
      if(n <= 0){
        cout<<"\nEnter valid Input!";
      }
      }while(n<=0);
      for(int i=0; i<n; i++){
        Course c;

        cout<<"\nEnter course: "<<i+1<<endl;
        cout<<"Enter Course Name: ";
        cin.ignore();
        getline(cin, c.name);
        
        do{
        cout<<"Enter Credit hours: ";
        cin>>c.credit_hrs;
        if(c.credit_hrs<=0){
          cout<<"\nCredit Hours should be greater than 0\n";
        }
        }while(c.credit_hrs <=0);

        int result;
        do{
        cout<<"Enter grade obtained: ";
        cin>>c.grade;

        result = c.gradetoPoints();
        } while(result == -1);

        c.CalculateQualityPoints();
        totalCreditHours = totalCreditHours + c.credit_hrs;
        totalQualityPoints = totalQualityPoints + c.quality_points;
        courses.push_back(c);
      }
        cout<<endl;

      cout<<"\n\nTotal Credit Hours: "<<totalCreditHours;
      cout<<"\nTotal Quality Points: "<<totalQualityPoints;

      sgpa = totalQualityPoints / totalCreditHours;
      cout<<"\n\nSemester GPA is: "<<sgpa;      
      break;
     }
   
   case 2:{

      vector <Semester> semesters;
      int totalCreditHours = 0;
      float totalQualityPoints = 0.0;
      int n;
      do{
      cout<<"\nEnter number of Semesters: ";
      cin>>n;
      if(n <= 0){
        cout<<"\nEnter valid Input!";
      }
      }while(n<=0);

      for(int i=0; i<n; i++){
        Semester s;
        cout<<"\nEnter Semester "<<i+1;

        do{
        cout<<"\nEnter Semester GPA: ";
        cin>>s.Sgpa;
        if(s.Sgpa<0 || s.Sgpa>4.0){
          cout<<"\nGPA should be between 0 and 4.0";
        }
        }while(s.Sgpa<0 || s.Sgpa>4.0);

        do{
        cout<<"Enter Total Credit hours: ";
        cin>>s.Semcredit_hrs;
        if(s.Semcredit_hrs<=0){
          cout<<"\nCredit Hours should be greater than 0\n";
        }
        }while(s.Semcredit_hrs <=0);

        s.CalculateQualityPoints();
        totalCreditHours = totalCreditHours + s.Semcredit_hrs;
        totalQualityPoints = totalQualityPoints + s.SemqualityPoints;

        semesters.push_back(s);
      }

        float CGPA = totalQualityPoints / totalCreditHours;
        cout<<"\nYour CGPA is : "<<CGPA<<endl;
        break;
     }
      
      case 3:
       cout<<"\nThanks for using CGPA Calculator!";
       cout<<"\n---------------------------------";
       break;
      
      default:
       cout<<"Enter valid input!";
       break;
      
    }
  }while(choice!=3);
}