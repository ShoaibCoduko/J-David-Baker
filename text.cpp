#include<iostream>
#include<conio.h>
using namespace std;
class Student
{
	private:
		float quiz[4],assignment[2],mid_term,final;
		string student_id,student_name;
	public:
		Student()
		{}
		Student(string id,string name,float q[],float a[],float mid,float f)
		{
			student_id = id;
			student_name = name;
			for(int i=0;i<=3;i++)
				quiz[i] = q[i];
			for(int i=0;i<=1;i++)
				assignment[i] = a[i];
			mid_term = mid;
			final = f;
		}
		void enterData()
		{
			cout<<"Enter Student Id: ";
			cin>>student_id;
			cout<<"\nEnter Student Name: ";
			cin>>student_name;
			for(int i=0;i<=3;i++)
			{
				p:
				cout<<"\nEnter marks for Quiz";
				cout<<i+1;
				cout<<" <out of 10>: ";
				cin>>quiz[i];
				if(quiz[i] > 10)
				{
					cout<<"\nInvalid Marks, Marks should be between 0-10.\n";
					goto p;	
				}	
			}
			for(int i=0;i<=1;i++)
			{
				h:
				cout<<"\nEnter marks for assignment";
				cout<<i+1;
				cout<<" <out of 20>: ";
				cin>>assignment[i];
				if(assignment[i] > 20)
				{
					cout<<"\nInvalid marks, marks should be between 0-20.\n";
					goto h;	
				}
			}
			cout<<"\nEnter Marks in Mid Term <out of 40>: ";
			cin>>mid_term;
			cout<<"\nEnter Mrks in Final Term <out of 60>: ";
			cin>>final;
		}
		float calculateResult()
		{
			float q,a,mid,f;
			q = (quiz[0] + quiz[1] + quiz[2] + quiz[3])/40*10; 
			a = (assignment[0] + assignment[1])/40*20;
			mid = mid_term/40*30;
			f = final/60*40;
			return q + a + mid + f;
		}
		void displayData(float total)
		{
			cout<<student_id<<"\t"<<student_name<<"\t\t"<<(int)mid_term<<"\t\t"<<(int)final<<"\t\t"<<total<<"\n";
		}
};
main()
{
	Student* s[3];
	float quiz[4] = {4,6,2,8};
	float assignment[2] = {12,20};
	s[0] = new Student("BC210206485","Shoaib Ahmad",quiz,assignment,25,43);
	s[1] = new Student;
	s[2] = new Student;
	s[1] -> enterData();
	s[2] = s[1];
	cout<<"\n\nStudentID\tStudentName\tMidTermMarks\tFinalTermMarks\tTotalMarks\n";
	cout<<"---------------------------------------------------------------------------------\n";
	for(int i=0;i<=2;i++)
		s[i] -> displayData(s[i] -> calculateResult());
	getch();
	return 0;
}

