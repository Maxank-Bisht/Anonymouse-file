#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void menu();
class doc
{
	int dcode;
	char dname[50];
	char sp[50];
	public:
	void getdata()
	{
		cout<<"\nEnter doctor's code:";
		cin>>dcode;
		cout<<"Enter doctor's name:";
		gets(dname);
		cout<<"Department:";
		gets(sp);
	}
	void putdata()
	{
		cout<<"\nID:"<<dcode;
		cout<<"\nName:"<<dname;
		cout<<"\nDepartment:"<<sp;
	}
	int getid()
	{
		return dcode;
	}
	void write();

}d;
void doc::write()
{
	char ans='y';
	ofstream f;
	f.open("doc.dat",ios::app);
	while(ans=='y'||ans=='Y')
	{       d.getdata();
		cout<<"Do you want to continue:";
		cin>>ans;
		f.write((char*)&d,sizeof(d));
	 }
	 f.close();
}
void dis()
{       clrscr();
	ifstream f;
	f.open("doc.dat",ios::binary);
	cout<<"Details of Doctors are:";
	while(!f.eof())
	{
		f.read((char*)&d,sizeof(d));
		if(f.eof())
			break;
		d.putdata();
		cout<<"\n";
	}
	f.close();
	getch();
}
void sdoc()
{       clrscr();
	int id;
	cout<<"\nEnter the id of the doc:";
	cin>>id;
	char found='n';
	ifstream f;
	f.open("doc.dat");
	while(!f.eof())
	{
		f.read((char*)&d,sizeof(d));
		if(d.getid()==id)
		{
			cout<<"Details of the doctor is:\n";
			d.putdata();
			found='y';break;
		}
	}
	if(found=='n')
		cout<<"Record not found!!";
	f.close();
	getch();
}
void mdoc()
{
	clrscr();
	fstream fio;
	long pos;
	int m;

	char found,num='y';
	while(num=='y')
	{
		//TO MODIFY DATA FOR A PARTICULAR RECORD
		fio.open("doc.dat",ios::in|ios::out);
		cout<<"\tENTER DOCTOR ID TO BE MODIFIED:";
		cin>>m;
		while(!fio.eof())
		{       found='n';
			pos=fio.tellg();
			fio.read((char*)&d,sizeof(d));
			if(fio.eof())
				break;
			if(d.getid()==m)
			{
				found='y';
				d.getdata();
				fio.seekg(pos);
				fio.write((char*)&d,sizeof(d));
				break;
			}
		}
		if(found=='n')
			cout<<"\tNOT FOUND";
		else if(found=='y')
			cout<<"\n\tDATA HAS BEEN SUCCESSFULLY MODIFIED!";

		fio.close();
		cout<<"\n\tDO YOU WANT TO CONTINUE:";
		cin>>num;

	}
}
void ddoc()
{
	ifstream fin;
	ofstream fout;
	int no;
	char found='n';
	fin.open("doc.dat",ios::in);
	fout.open("temp.dat",ios::out);
	cout<<"Enter the id of the doctor to be deleted:";
	cin>>no;
	while(!fin.eof())
	{
		fin.read((char*)&d,sizeof(d));
		if(fin.eof())
			break;
		if(d.getid()==no)
			found='y';
		else
			fout.write((char*)&d,sizeof(d));
	}
	if(found=='n')
		cout<<"Record not found!!";
	else if(found=='y')
		cout<<"Record has been successfully deleted!";
	fin.close();
	fout.close();
	remove("doc.dat");
	rename("temp.dat","doc.dat");
	getch();
}

void doctor()
{
	int ch;
	while(ch!=6)
	{
		a:
		clrscr();
		cout<<"\n\n\t\tWelcome to doctor department!!";
		cout<<"\n\n\tEnter from the following choice:";
		cout<<"\n\t1.Add";
		cout<<"\n\t2.Display";
		cout<<"\n\t3.Search";
		cout<<"\n\t4.Modify";
		cout<<"\n\t5.Delete";
		cout<<"\n\t6.Exit";
		cout<<"\n\nEnter your choice:";
		cin>>ch;
		if(ch==1)
			d.write();
		else if(ch==2)
			dis();
		else if(ch==3)
			sdoc();
		else if(ch==4)
			mdoc();
		else if(ch==5)
			ddoc();
		else if(ch==6)
			exit(0);
		else
		{
			cout<<"\tEnter a valid choice!!";
			getch();
			goto a;
		}
	}
	getch();
}

class pat
{
	int id;
	char pname[50];
	char pg[10];
	public:
	int getid()
	{
		return id;
	}
	void getdata()
	{		cout<<"\nEnter Patient's Id:";
			cin>>id;
			cout<<"Enter Patient's name:";
			gets(pname);
			cout<<"Enter Patient's Gender:";
			gets(pg);
	 }
	void putdata()
	{
		cout<<"\nID:"<<id;
		cout<<"\nName:"<<pname;
		cout<<"\nGender:"<<pg;
	}
	void write();
}p;
void pat::write()
	{
		char ans='y';
		ofstream f;
		f.open("pat.dat",ios::app);
		while(ans=='y'||ans=='Y')
		{
			p.getdata();
			cout<<"Do you want to continue:";
			cin>>ans;
			f.write((char*)&p,sizeof(p));
		}
		f.close();

	}
void display()
{       clrscr();
	ifstream f;
	f.open("pat.dat",ios::binary);
	cout<<"\n\nPatient Details are as follows:";
	while(!f.eof())
	{
		f.read((char*)&p,sizeof(p));
		if(f.eof())
			break;
		p.putdata();
		cout<<"\n";
	}
	f.close();
	getch();
}
void spat()
{
	clrscr();
	int id;
	cout<<"Enter the id of the patient:";
	cin>>id;
	char found='n';
	ifstream f;
	f.open("pat.dat");
	while(!f.eof())
	{
		f.read((char*)&p,sizeof(p));
		if(p.getid()==id)
		{
			cout<<"Details of the patient :\n";
			p.putdata();
			found='y';break;
		}
	}
	if(found=='n')
		cout<<"Record not found!!";
	f.close();
	getch();
}
void mpat()
{
	clrscr();
	fstream fio;
	long pos;
	int m;

	char found,num='y';
	while(num=='y')
	{
		//TO MODIFY DATA FOR A PARTICULAR RECORD
		fio.open("pat.dat",ios::in|ios::out);
		cout<<"\tENTER PATIENT ID TO BE MODIFIED:";
		cin>>m;
		while(!fio.eof())
		{
			found='n';
			pos=fio.tellg();
			fio.read((char*)&p,sizeof(p));
			if(fio.eof())
				break;
			if(p.getid()==m)
			{
				found='y';
				p.getdata();
				fio.seekg(pos);
				fio.write((char*)&p,sizeof(p));
				break;
			}
		}
		if(found=='n')
			cout<<"\tNOT FOUND";
		else if(found=='y')
			cout<<"\n\tDATA HAS BEEN SUCCESSFULLY MODIFIED!";

		fio.close();
		cout<<"\n\n\tDO YOU WANT TO CONTINUE:";
		cin>>num;

	}
}
void dpat()
{
	ifstream fin;
	ofstream fout;
	int no;
	char found='n';
	fin.open("pat.dat",ios::in);
	fout.open("temp.dat",ios::out);
	cout<<"Enter the id of the patient to be deleted:";
	cin>>no;
	while(!fin.eof())
	{
		fin.read((char*)&p,sizeof(p));
		if(fin.eof())
			break;
		if(p.getid()==no)
			found='y';
		else
			fout.write((char*)&p,sizeof(p));
	}
	if(found=='n')
		cout<<"Record not found!!";
	else if(found=='y')
		cout<<"Record has been successfully deleted!";
	fin.close();
	fout.close();
	remove("pat.dat");
	rename("temp.dat","pat.dat");
	getch();
}
void patient()
{
	int ch;
	while(ch!=6)
	{
		a:
		clrscr();
		cout<<"\n\n\t\tWelcome to patient portal!!";
		cout<<"\n\tEnter from the following choice:";
		cout<<"\n\t1.Add new record";
		cout<<"\n\t2.Display";
		cout<<"\n\t3.Search";
		cout<<"\n\t4.Modify";
		cout<<"\n\t5.Delete";
		cout<<"\n\t6.Exit";
		cout<<"\nEnter your choice:";
		cin>>ch;
		if(ch==1)
			p.write();
		else if(ch==2)
			display();
		else if(ch==3)
			spat();
		else if(ch==4)
			mpat();
		else if(ch==5)
			dpat();
		else if(ch==6)
			exit(0);
		else
		{
			cout<<"Enter a valid choice!!";
			getch();
			goto a;
		}
	}
	getch();
}

void screen()
{
	clrscr();
	cout<<"\n\n\n\n\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
	cout<<"\t\t@@ ____________________________________________ @@\n";
	cout<<"\t\t@@|                                            |@@\n";
	cout<<"\t\t@@|                                            |@@\n";
	cout<<"\t\t@@|                                            |@@\n";
	cout<<"\t\t@@|                                            |@@\n";
	cout<<"\t\t@@|                                            |@@\n";
	cout<<"\t\t@@|                                            |@@\n";
	cout<<"\t\t@@|                 WELCOME TO                 |@@\n";
	cout<<"\t\t@@|                                            |@@\n";
	cout<<"\t\t@@|          HOSPITAL MANAGEMENT SYSTEM        |@@\n";
	cout<<"\t\t@@|                                            |@@\n";
	cout<<"\t\t@@|                                            |@@\n";
	cout<<"\t\t@@|                                            |@@\n";
	cout<<"\t\t@@|                                            |@@\n";
	cout<<"\t\t@@|                                            |@@\n";
	cout<<"\t\t@@|                                            |@@\n";
	cout<<"\t\t@@|____________________________________________|@@\n";
	cout<<"\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\t";
	cout<<"\n PRESS ANY KEY TO CONTINUE.....";
	getch();

}
void password()
{
	a:
	clrscr();
	char pass[20];
	int a=0;
	cout<<"\n\n\n\t\t\tHOSPITAL MANAGEMENT SYSYTEM";
	cout<<"\n\t\t\t--------------------------";
	cout<<"\n\t\t\t          LOGIN";
	cout<<"\n\t\t\t--------------------------";
	cout<<"\n\n\t\t ENTER PASSWORD:-";
	gets(pass);
	if(strcmp(pass,"king")==0)
	{	cout<<"\n\tAccess granted.....";
		a=1;
	}
	else
	{	cout<<"\n\tAccess aborted.....";
		cout<<"\n\tPlease try again ";
		getch();
		goto a;
	}
	cout<<"\n\n\n\n\tPress any key to continue....";
	getch();
	if(a==1)
		menu();

}
void menu()
{

	int ch;
	m:
	clrscr();
	cout<<"\n\n\n\t\tHOSPITAL MANAGEMENT SYSTEM";
	cout<<"\n\n\tPlease choose from the folowing options:";
	cout<<"\n\n\t|----------------------------------------|";
	cout<<"\n\t|                                        |";
	cout<<"\n\t|	1 >>Patient Department           |";
	cout<<"\n\t|       2 >>Doctor Department            |";
	cout<<"\n\t|	3 >>Exit  		         |";
	cout<<"\n\t|                                        |";
	cout<<"\n\t|----------------------------------------|";
	cout<<"\n\nEnter your choice:";
	cin>>ch;
	if(ch==1)
		patient();
	else if(ch==2)
		doctor();
	else if(ch==3)
	{
		clrscr();
		cout<<"\n\n\tThank you!!";
	}
	else
	{
		cout<<"Enter a valid choice!!";
		getch();
		goto m;

	}


	getch();
}
void main()
{
	screen();
	password();

}