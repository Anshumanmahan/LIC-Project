//Computer project
//Anshuman Dixit
//XII-A
//Roll no.-7
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<string.h>
#include<ctype.h>
#include <iostream>
#include <unistd.h>
using namespace std;
 struct lic
 {
   int age,term;
   char name[20],m;
   double p,s,ma,pr;
 }s;
//Declaration of functions
 void create();
 void intro();
 void Read();
 void search();
 void append();
 void modify();
 void Delete();
 void Del_sea();
 void modify_sea();
 void delay(int x) {
	usleep(x*1000);
}
int main()
{
  intro();
  int flag=0,a;
  char b,pass[20],p[20]="awesome";
  for(int i=3;i>0;i--)
  {
   cout<<i<<"  chances left";
   cout<<"\n\n\n\n\n                 Enter the password to enter the program  \t\n\t\t\t\t";
   gets(pass);
   if(strcmp(pass,p)==0)
   {
    flag=1;
    break;
   }
   cout<<"\t\tWRONG password\n\n";
  }
  if(flag==1)
  {
   cout<<"\n\n\n\n\t\t\t\t#########################";
   cout<<"\n\t\t\t\tLOADING...........";
   cout<<"\n\t\t\t\t#########################";
   delay(3000);
   do
   {
    cout<<"Enter \n 1 for creation \n 2 for reading \n 3 for appending \n"
      <<" 4 for searching \n 5 For modification \n 6 for Modify by search \n"
      <<" 7 for Deletion \n 8 for Delete by search \n 9 for exit";
    cin>>a;
    switch(a)
    {
     case 1:   cout<<"CREATING.......\n";
	       create();
	       break;
     case 2:   cout<<"READING........\n";
	       Read();
	       break;
     case 3:   cout<<"APPENDING......\n";
	       append();
	       break;
     case 4:   cout<<"SEARCHING......\n";
	       search();
	       break;
     case 5:   cout<<"MODIFICATION......\n";
	       modify();
	       break;
     case 6:   cout<<"MODIFICATION BY SEARCH.......\n";
	       modify_sea();
	       break;
     case 7:   cout<<"DELETION........\n";
	       Delete();
	       break;
     case 8:   cout<<"DELETION BY SEARCH.....\n";
	       Del_sea();
	       break;
     case 9:   exit(0);

    }
     cout<<"\n\nDo you want to continue working.(y/n)?";
     cin>>b;
  }while(b=='y'||b=='Y');
     cout<<"Thanks for using MY program.....happy diwali";
     cout<<"\n\nZINDGI KE SAATH BHI ZINDGI KE BAAD BHI";
 }
 else
 {
  cout<<"\t\tGO AND CHECK THE PASSWORD FIRST";
 }
return 0;
}
//Creation of the file
void create()
{
  ofstream file("lic.dat",ios::binary);
  double d;
  char a;
 do
 {
  cout<<"Enter name of the policy holder\t";
  gets(s.name);
  cout<<"Enter the age of the policy holder\t";
  cin>>s.age;
  cout<<"Enter the term of the policy\t";
  cin>>s.term;
  cout<<"Enter the sum assored\t";
  cin>>s.s;
  do
  {
   cout<<"Enter the mode of the policy.(Q for quaterly||"
       <<"H for half yearly||Y for yearly)\t";
   cin>>s.m;
   s.m=toupper(s.m);
  }while(s.m!='Q' && s.m!='H' && s.m!='Y');
  d=rand()%10000;
  s.p=d+100000;
  file.write((char *)&s,sizeof(s));
  cout<<"Do you want to continue entering the records.(y/n)";
  cin>>a;
 }while(a=='y'||a=='Y');
 file.close();
}
//Reading the file
void Read()
{
  char a;
  ifstream file("lic.dat",ios::binary);
  if(!file)
  {
   cout<<"File not present";
  }
  else
  {
   file.read((char *)&s,sizeof(s));
   while(!file.eof())
   {
    cout<<"enter a key to see the record";
    cin>>a;
    cout<<"***************************************************************";
    cout<<"***************************************************************";
    cout<<"***************************************************************";
    cout<<"***************************************************";
    cout<<"name : "<<"\t"<<s.name<<"\n";
    cout<<"age  : "<<"\t"<<s.age<<"\n";
    cout<<"term : "<<"\t"<<s.term<<"\n";
    if(s.m=='Q')
    {
     cout<<"policy mode : "<<"\t"<<s.m<<"\n";
     s.pr=s.s/(s.term*4);
    }
    else
    if(s.m=='H')
    {
     cout<<"policy mode : "<<"\t"<<s.m<<"\n";
     s.pr=s.s/(s.term*2);
    }
    else
    if(s.m=='Y')
    {
     cout<<"policy mode : "<<"\t"<<s.m<<"\n";
     s.pr=s.s/s.term;
    }
    else
    {
     cout<<"policy mode : "<<"\t";
     cout<<"Wrong choice\n";
    }
    cout<<"sum assored : "<<"\t"<<s.s<<"\n";
    cout<<"policy no.  : "<<"\t"<<s.p<<"\n";
    cout<<"premium     : "<<"\t"<<s.pr<<"\n";
    s.ma=s.s+(s.s*s.term)/20;
    cout<<"Maturity    : "<<"\t"<<s.ma;
    cout<<"\n"<<"***********************************************************";
    cout<<"*****************************************************************";
    cout<<"*****************************************************************";
    cout<<"***************************************************"<<"\n\n\n";
    file.read((char *)&s,sizeof(s));
   }
 }
 file.close();
}
//Appending the file
void append()
{
 ofstream file("lic.dat",ios::app);
 double d;
 char a;
 do
 {
  cout<<"Enter name of the policy holder\t";
  gets(s.name);
  cout<<"Enter the age of the policy holder\t";
  cin>>s.age;
  cout<<"Enter the term of the policy\t";
  cin>>s.term;
  cout<<"Enter the sum assored\t";
  cin>>s.s;
  do
  {
   cout<<"Enter the mode of the policy.(Q for quaterly||"
       <<"H for half yearly||Y for yearly)\t";
   cin>>s.m;
   s.m=toupper(s.m);
  }while(s.m!='Q' && s.m!='H' && s.m!='Y');
  d=rand()%10000;
  s.p=d+100000;
  file.write((char *)&s,sizeof(s));
  cout<<"Do you want to continue entering the records.(y/n)?\t";
  cin>>a;
 }while(a=='y'||a=='Y');
 file.close();
}
//searching in file
void search()
{
 char a[20];
 int flag=0;
 ifstream file("lic.dat",ios::binary);
 cout<<"Enter a name you want to search\t";
 gets(a);
 if(!file)
 {
  cout<<"File not present";
 }
 else
 {
  while(!file.eof())
  {
   file.read((char *)&s,sizeof(s));
   if(strcmp(a,s.name)==0)
   {
    cout<<"***************************************************************";
    cout<<"***************************************************************";
    cout<<"***************************************************************";
    cout<<"***************************************************";
    cout<<"name : "<<"\t"<<s.name<<"\n";
    cout<<"age  : "<<"\t"<<s.age<<"\n";
    cout<<"term : "<<"\t"<<s.term<<"\n";
    if(s.m=='Q')
    {
     cout<<"policy mode : "<<"\t"<<s.m<<"\n";
     s.pr=s.s/(s.term*4);
    }
    else
    if(s.m=='H')
    {
     cout<<"policy mode : "<<"\t"<<s.m<<"\n";
     s.pr=s.s/(s.term*2);
    }
    else
    if(s.m=='Y')
    {
     cout<<"policy mode : "<<"\t"<<s.m<<"\n";
     s.pr=s.s/s.term;
    }
    else
    {
     cout<<"policy mode : "<<"\t";
     cout<<"Wrong choice\n";
    }
    cout<<"sum assored : "<<"\t"<<s.s<<"\n";
    cout<<"policy no.  : "<<"\t"<<s.p<<"\n";
    cout<<"premium     : "<<"\t"<<s.pr<<"\n";
    s.ma=s.s+(s.s*s.term)/20;
    cout<<"Maturity    : "<<"\t"<<s.ma;
    cout<<"\n"<<"***********************************************************";
    cout<<"*****************************************************************";
    cout<<"*****************************************************************";
    cout<<"***************************************************"<<"\n\n\n";
    flag=1;
    break;
   }
  }
  if(flag==0)
  {
   cout<<"Record not found\n";
  }
 }
 file.close();
}
//Deleting a record from a file
void Delete()
{
 char a;
 ifstream file("lic.dat",ios::binary);
 ofstream file1("new.dat",ios::binary);
 if(!file1 && !file)
 {
  cout<<"Files missing";
 }
 else
 {
  file.read((char *)&s,sizeof(s));
  while(!file.eof())
  {
    cout<<"***************************************************************";
    cout<<"***************************************************************";
    cout<<"***************************************************************";
    cout<<"***************************************************";
    cout<<"name : "<<"\t"<<s.name<<"\n";
    cout<<"age  : "<<"\t"<<s.age<<"\n";
    cout<<"term : "<<"\t"<<s.term<<"\n";
    if(s.m=='Q')
    {
     cout<<"policy mode : "<<"\t"<<s.m<<"\n";
     s.pr=s.s/(s.term*4);
    }
    else
    if(s.m=='H')
    {
     cout<<"policy mode : "<<"\t"<<s.m<<"\n";
     s.pr=s.s/(s.term*2);
    }
    else
    if(s.m=='Y')
    {
     cout<<"policy mode : "<<"\t"<<s.m<<"\n";
     s.pr=s.s/s.term;
    }
    else
    {
     cout<<"policy mode : "<<"\t";
     cout<<"Wrong choice\n";
    }
    cout<<"sum assored : "<<"\t"<<s.s<<"\n";
    cout<<"policy no.  : "<<"\t"<<s.p<<"\n";
    cout<<"premium     : "<<"\t"<<s.pr<<"\n";
    s.ma=s.s+(s.s*s.term)/20;
    cout<<"Maturity    : "<<"\t"<<s.ma;
    cout<<"\n"<<"***********************************************************";
    cout<<"*****************************************************************";
    cout<<"*****************************************************************";
    cout<<"***************************************************"<<"\n\n\n";
    cout<<"Do you want to delete this record.(y/n)?";
    cin>>a;
    if(a=='n'|| a=='N')
    {
     file1.write((char *)&s,sizeof(s));
    }
    file.read((char *)&s,sizeof(s));
   }
 }
 file.close();
 file1.close();
 remove("lic.dat");
 rename("new.dat","lic.dat");
}
//modifying a file
void modify()
{
 char a,b,c,d,e,f;
 ofstream file1("new.dat",ios::binary);
 ifstream file("lic.dat",ios::binary);
 if(!file && !file1)
 {
  cout<<"Files missing";
 }
 else
 {
  file.read((char *)&s,sizeof(s));
  while(!file.eof())
  {
    cout<<"***************************************************************";
    cout<<"***************************************************************";
    cout<<"***************************************************************";
    cout<<"***************************************************";
    cout<<"name : "<<"\t"<<s.name<<"\n";
    cout<<"age  : "<<"\t"<<s.age<<"\n";
    cout<<"term : "<<"\t"<<s.term<<"\n";
    if(s.m=='Q')
    {
     cout<<"policy mode : "<<"\t"<<s.m<<"\n";
     s.pr=s.s/(s.term*4);
    }
    else
    if(s.m=='H')
    {
     cout<<"policy mode : "<<"\t"<<s.m<<"\n";
     s.pr=s.s/(s.term*2);
    }
    else
    if(s.m=='Y')
    {
     cout<<"policy mode : "<<"\t"<<s.m<<"\n";
     s.pr=s.s/s.term;
    }
    else
    {
     cout<<"policy mode : "<<"\t";
     cout<<"Wrong choice\n";
    }
    cout<<"sum assored : "<<"\t"<<s.s<<"\n";
    cout<<"policy no.  : "<<"\t"<<s.p<<"\n";
    cout<<"premium     : "<<"\t"<<s.pr<<"\n";
    s.ma=s.s+(s.s*s.term)/20;
    cout<<"Maturity    : "<<"\t"<<s.ma;
    cout<<"\n"<<"***********************************************************";
    cout<<"*****************************************************************";
    cout<<"*****************************************************************";
    cout<<"***************************************************"<<"\n\n\n";
   cout<<"Do you want to modify this record\t";
   cin>>a;
   if(a=='y' || a=='Y')
   {
    cout<<"\nDo you want to modify name\t";
    cin>>b;
    if(b=='y' || b=='Y')
    {
     cout<<"\nEnter modified name\t";
     gets(s.name);
    }
    cout<<"\nDo you want to modify age\t";
    cin>>c;
    if(c=='y' || c=='Y')
    {
     cout<<"\nEnter modified age\t";
     cin>>s.age;
    }
    cout<<"\nDo you want to modify term\t";
    cin>>d;
    if(d=='y' || d=='Y')
    {
     cout<<"\nEnter modified term\t";
     cin>>s.term;
    }
    cout<<"\nDo you want to modify sum assored\t";
    cin>>e;
    if(e=='y' || e=='Y')
    {
     cout<<"\nEnter modified sum assored\t";
     cin>>s.s;
    }
    cout<<"\nDo you want to modify mode\t";
    cin>>f;
    if(f=='y' || f=='Y')
    {
     do
     {
       cout<<"Enter the mode of the policy.(Q for quaterly||"
	   <<"H for half yearly||Y for yearly)\t";
       cin>>s.m;
       s.m=toupper(s.m);
     }while(s.m!='Q' && s.m!='H' && s.m!='Y');
    }
   }
   file1.write((char *)&s,sizeof(s));
   file.read((char *)&s,sizeof(s));
  }
 }
 file.close();
 file1.close();
 remove("lic.dat");
 rename("new.dat","lic.dat");
}
void Del_sea()
{
 char n[20];
 ifstream file("lic.dat",ios::binary);
 ofstream file1("new.dat",ios::binary);
 if(!file && file1)
 {
  cout<<"Files missing";
 }
 else
 {
  cout<<"Enter the name whose record is to be deleted\t";
  gets(n);
  file.read((char *)&s,sizeof(s));
  while(!file.eof())
  {
   if(strcmp(s.name,n)==0)
   {
    cout<<"***************************************************************";
    cout<<"***************************************************************";
    cout<<"***************************************************************";
    cout<<"***************************************************";
    cout<<"name : "<<"\t"<<s.name<<"\n";
    cout<<"age  : "<<"\t"<<s.age<<"\n";
    cout<<"term : "<<"\t"<<s.term<<"\n";
    if(s.m=='Q')
    {
     cout<<"policy mode : "<<"\t"<<s.m<<"\n";
     s.pr=s.s/(s.term*4);
    }
    else
    if(s.m=='H')
    {
     cout<<"policy mode : "<<"\t"<<s.m<<"\n";
     s.pr=s.s/(s.term*2);
    }
    else
    if(s.m=='Y')
    {
     cout<<"policy mode : "<<"\t"<<s.m<<"\n";
     s.pr=s.s/s.term;
    }
    else
    {
     cout<<"policy mode : "<<"\t";
     cout<<"Wrong choice\n";
    }
    cout<<"sum assored : "<<"\t"<<s.s<<"\n";
    cout<<"policy no.  : "<<"\t"<<s.p<<"\n";
    cout<<"premium     : "<<"\t"<<s.pr<<"\n";
    s.ma=s.s+(s.s*s.term)/20;
    cout<<"Maturity    : "<<"\t"<<s.ma;
    cout<<"\n"<<"***********************************************************";
    cout<<"*****************************************************************";
    cout<<"*****************************************************************";
    cout<<"***************************************************"<<"\n\n\n";
    cout<<"DELETING THIS RECORD..........";
   }
   else
   {
    file1.write((char *)&s,sizeof(s));
   }
   file.read((char *)&s,sizeof(s));
  }
 }
 file.close();
 file1.close();
 remove("lic.dat");
 rename("new.dat","lic.dat");
}
void modify_sea()
{
 char n[20],b,c,d,e,f;
 ifstream file("lic.dat",ios::binary);
 ofstream file1("new.dat",ios::binary);
 if(!file && !file1)
 {
  cout<<"FILES MISSING";
 }
 else
 {
  cout<<"Enter the name whose records are to be modified\t";
  gets(n);
  file.read((char *)&s,sizeof(s));
  while(!file.eof())
  {
   if(strcmp(s.name,n)==0)
   {
    cout<<"***************************************************************";
    cout<<"***************************************************************";
    cout<<"***************************************************************";
    cout<<"***************************************************";
    cout<<"name : "<<"\t"<<s.name<<"\n";
    cout<<"age  : "<<"\t"<<s.age<<"\n";
    cout<<"term : "<<"\t"<<s.term<<"\n";
    if(s.m=='Q')
    {
     cout<<"policy mode : "<<"\t"<<s.m<<"\n";
     s.pr=s.s/(s.term*4);
    }
    else
    if(s.m=='H')
    {
     cout<<"policy mode : "<<"\t"<<s.m<<"\n";
     s.pr=s.s/(s.term*2);
    }
    else
    if(s.m=='Y')
    {
     cout<<"policy mode : "<<"\t"<<s.m<<"\n";
     s.pr=s.s/s.term;
    }
    else
    {
     cout<<"policy mode : "<<"\t";
     cout<<"Wrong choice\n";
    }
    cout<<"sum assored : "<<"\t"<<s.s<<"\n";
    cout<<"policy no.  : "<<"\t"<<s.p<<"\n";
    cout<<"premium     : "<<"\t"<<s.pr<<"\n";
    s.ma=s.s+(s.s*s.term)/20;
    cout<<"Maturity    : "<<"\t"<<s.ma;
    cout<<"\n"<<"***********************************************************";
    cout<<"*****************************************************************";
    cout<<"*****************************************************************";
    cout<<"***************************************************"<<"\n\n\n";
    cout<<"\nDo you want to modify name\t";
    cin>>b;
    if(b=='y' || b=='Y')
    {
     cout<<"\nEnter modified name\t";
     gets(s.name);
    }
    cout<<"\nDo you want to modify age\t";
    cin>>c;
    if(c=='y' || c=='Y')
    {
     cout<<"\nEnter modified age\t";
     cin>>s.age;
    }
    cout<<"\nDo you want to modify term\t";
    cin>>d;
    if(d=='y' || d=='Y')
    {
     cout<<"\nEnter modified term\t";
     cin>>s.term;
    }
    cout<<"\nDo you want to modify sum assored\t";
    cin>>e;
    if(e=='y' || e=='Y')
    {
     cout<<"\nEnter modified sum assored\t";
     cin>>s.s;
    }
    cout<<"\nDo you want to modify mode\t";
    cin>>f;
    if(f=='y' || f=='Y')
    {
     do
     {
      cout<<"Enter the mode of the policy.(Q for quaterly||"
	  <<"H for half yearly||Y for yearly)\t";
      cin>>s.m;
      s.m=toupper(s.m);
     }while(s.m!='Q' && s.m!='H' && s.m!='Y');
    }
   }
     file1.write((char *)&s,sizeof(s));
     file.read((char *)&s,sizeof(s));
  }
 }
 file.close();
 file1.close();
 remove("lic.dat");
 rename("new.dat","lic.dat");
}
void intro() {
	cout<<"********************************************************************************";
	cout<<"\n\n\n\n\t\t\t\LIFE INSURANCE CORPORATION";
	cout<<"\n\n\t\t\t\         OF INDIA";
	cout<<"\n\n\n\n\t\t\tMADE BY : Anshuman Dixit";
	cout<<"\n\n\t\t     SCHOOL : DELHI PUBLIC SCHOOL,ELDECO";
	cout<<"\n\n\n\n\n";
	cout<<"********************************************************************************";
}


