#include <iostream>

using namespace std;

class helper
{
public:
	static bool searchstring(char* str1, char* str2)
	{
		for(int i=0; str2[i]!='\0'; i++)
		{
			if(str1[i]!=str2[i])
				return false;
		}
		return true;
	}
};


class Student
{
private:
	char name[50];
	char rollNo[8];
	float cgpa;
public:
	Student(char[],char[],float);
	void Print();
	float GetCGPA();
	char* GetNAME();

};

Student::Student(char rollnumber[8]="0000000", char NAME[50]="Student Name", float CGPA=0.0)
{
	for(int i=0; i<8; i++)
		rollNo[i]=rollnumber[i];
	int j;
	for(j=0; NAME[j]!='\0'; j++)
		name[j]=NAME[j];
	name[j]='\0';
	cgpa=CGPA;
}

void Student::Print()
{
	for(int i=0; name[i]!='\0'; i++)
	{
		cout<<name[i];
	}
	cout<<"(";
	for(int i=0; i<8; i++)
	{
		cout<<rollNo[i];
	}
	cout<<")";
}

float Student::GetCGPA()
{
	return cgpa;
}

char* Student::GetNAME()
{	
	return name;
}

class Society
{
private:
	char name[50];	
	Student* president;	
	Student* members[5];
public:
	Society(char[]);
	void PrintInfo();
	void AppointPresident(Student&);
	void AddMember(Student& );
	void SuspendMember(char* );
	~Society();
};

Society::Society(char NAME[50]="Society Name")
{
	int j;
	for(j=0; NAME[j]!='\0'; j++)
		name[j]=NAME[j];
	name[j]='\0';
	president=0;
	for(int i=0; i<5; i++)
	{
		members[i]=0;
	}
}

void Society::PrintInfo()
{
	cout<<"Society Name:\t";
	for(int i=0; name[i]!='\0'; i++)
	{
		cout<<name[i];
	}
	cout<<endl;
	if(president!=0)
	{
	    cout<<"President:\t";
		president->Print();
		
	}
	else
		cout<<"President:\t Not Available";
	cout<<endl;
	for(int i=0; i<5; i++)
	{
		if(members[i]!=0)
		{
			cout<<"Member "<<i+1<<":\t";
			members[i]->Print();
		}
		else
			cout<<"Member "<<i+1<<":\t"<<" Not Available";
		cout<<endl;

	}
}
void Society::AppointPresident(Student& s)
{
	float cgpa= s.GetCGPA();
	char* Name=0;
	Name=s.GetNAME();
	if(president==0 && cgpa>3.00)
	{
		    president=&s;
			cout<<Name<<"  has been appointed as President."<<endl;
	}
	else if(cgpa<3.00)
	{
		cout<<Name<<"  cannot be appointed as President. CGPA criteria not met."<<endl;
	}
	else if(president!=0)
		cout<<Name<<"  cannot be appointed as President. President position is NOT vacant."<<endl;
	
}

void Society::AddMember(Student& s)
{
	
	char* Name=0;
	Name=s.GetNAME();
	bool check=false;
	for(int i=0;i<5; i++)
	{
		if(members[i]==&s)
			check=true;
	}
	if(president!=&s && check!=true)
	{
		int i;
		for( i=0; i<5; i++)
		{
			if(members[i]==0)
			{
				members[i]=&s;
				cout<<Name<<" has been added to members list successfully."<<endl;
				break;
			}
	
		}
		if(i==5)
			cout<<Name<<" cannot be added to members list. Member position is NOT vacant."<<endl;
	}
	else if(president==&s)
		cout<<"President cannot be added in Members list."<<endl;
	else if(check==true)
		cout<<Name<<" already exists in Members list."<<endl;

}

void Society::SuspendMember(char* MemberName)
{

	int k=1;
	for(int i=0; i<5; i++)
	{
		char* TempName=0;
		TempName=members[i]->GetNAME();
		if(helper::searchstring(TempName, MemberName)==true)
		{
			members[i]=0;
			cout<<MemberName<<" has been suspended from Sports society."<<endl;
			break;
		}
		else
			k++;
		if(k==5)
			cout<<MemberName<<" NOT found in the Members list."<<endl;
	}
}

Society::~Society()
{
	president=0;
	for(int i=0; i<5; i++)
	{
		members[i]=0;
	}
}



void main()
{ 
	Student s1("12L1111", "Hashim Amla", 3.99);
	Student s2("13L1121", "Virat Kohli", 3.45);
	Student s3("13L1126", "Quinton de Kock", 2.98);
	Student s4("14L1361", "Joe Root", 2.99);
	Student s5("14L1124", "Martin Guptil", 3.09);
	Student s6("15L1314", "Rohit Sharma", 3.19);

	Society sports ("Sports");

	sports.PrintInfo();
	cout<<endl;

	sports.AppointPresident(s3);
	sports.AppointPresident(s1);
	sports.AppointPresident(s2);

	cout << endl << endl << endl;
	Student s7("15L1334", "Robert Elen", 2.19);
	sports.AddMember(s3);
	sports.AddMember(s2);
    sports.AddMember(s3);
	sports.AddMember(s1);
	sports.AddMember(s4);
	sports.AddMember(s5);
	sports.AddMember(s6);
	sports.AddMember(s7);

	sports.PrintInfo();

	cout << endl << endl << endl;
	sports.SuspendMember("abc");
	sports.SuspendMember("Martin Guptil");

	cout<<endl;
	sports.PrintInfo();
	cout << endl << endl << endl;
	Society ieee("IEEE");
	ieee.AppointPresident(s5);
	ieee.PrintInfo();
	
	system("pause");

}