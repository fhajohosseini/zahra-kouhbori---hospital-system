// ConsoleApplication15.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<iomanip>
#include<vector>
#include<conio.h>
#include<fstream>
#include<map>

using namespace std;
multimap<string, string>sevedSick;
//#########################################  person  ##########################################
class person
{
protected:
	string name, family, address, phone;
	int age;
	
public:
	person() {};
	person(string name, string family, string address, string phone, int age)
	{
		this->name = name;
		this->family = family;
		this->address = address;
		this->phone = phone;
		this->age = age;
	}
	void setName(string name)
	{
		this->name = name;
	}
	void setFamily(string family)
	{
		this->family = family;
	}
	void setAddress(string address)
	{
		this->address = address;
	}
	void setPhone(string phone)
	{
		this->phone = phone;
	}
	void setAge(int age)
	{
		this->age = age;
	}
	string getName()const
	{
		return name;
	}
	string getFamily()const
	{
		return family;
	}
	string getAddress()const
	{
		return address;
	}
	string getPhone()const
		{
			return phone;
		}
	int getAge()const
	{
		return age;
	}

	void report()
	{
		cout << name << setw(6) << " " << family << setw(10) << " " << address << setw(4) << " " << phone << setw(4) << " " << age ;
		
	}
};



//#########################################  sick  ##########################################
class sick:public person
{
private:
	int Idnumber;
	string sickness, doctorName;
	
	static int count;
public:
	sick() { }
	sick(string name, string family, string address, string phone, int age, int Idnumber,string sickness,string  doctorName):person(name,family,address,phone,age)
	{
		this->Idnumber = Idnumber;
		this->sickness = sickness;
		this->doctorName = doctorName;
		count++;
	}
	void setIdnumber(int Idnumber)
	{
		this->Idnumber = Idnumber;
	}
	void setSickness(string sickness)
	{
		this->sickness = sickness;
	}
	void setDoctorName(string doctorName)
	{
		this->doctorName = doctorName;
	}
	int getIdnumber()const
	{
		return Idnumber;
	}
string getSickness()const
	{
		return sickness;
	}
string getDoctorName()const
{
	return doctorName;
}
 static int getCount()
{
	return count;
}
 void report()
 {
	 cout << name << setw(8) << " " << family << setw(12) << " " << address << setw(6) << " " << phone << setw(8) << " " << age;
	 cout << setw(6) << " " << Idnumber << setw(10) << " " << sickness << setw(10) << " " << doctorName << setw(6) << " " << count << endl;
 }
 

};
//#########################################  doctor  ##########################################
class doctor :public person
{
private:
	int codeDoctor;
	string experties;
	static int number;

public:
	doctor() { }
	doctor(string name, string family, string address, string phone, int age, int codeDoctor, string experties) :person(name, family, address, phone, age)
	{
		this->codeDoctor = codeDoctor;
		this->experties = experties;
		number++;
	}
	void setCodeDoctor(int codeDoctor)
	{
		this->codeDoctor = codeDoctor;
	}
	void setExperties(string experties)
	{
		this->experties = experties;
	}
	
	int getCodeDoctor()const
	{
		return codeDoctor;
	}
	static int getNumber()
	{
		return number;
	}

	string getExperties()const
	{
		return experties;
	}
	void report()
	{
		cout << name << setw(10) << " " << family << setw(14) << " " << address << setw(15) << " " << phone << setw(8) << " " << age;
		cout << setw(9) << " " <<  codeDoctor<< setw(7) << " " << experties << setw(10) << " " << number << endl;

	}
};


//#############################################################################################
//
//#########################################  sick  ##########################################
vector<sick>lists1, lists2;
fstream outputfileS;
void writeSick()
{
	int Idnumber, age;
	string name, family, address, phone, sickness, doctorName;

	cout << "\n enter the number of sick: ";
	cin >> Idnumber;
	cout << "\n enter the name of sick: ";
	cin >> name;
	cout << "\n enter the family of sick: ";
	cin >> family;
	cout << "\n enter the address of sick: ";
	cin >> address;
	cout << "\n enter the phone of sick: ";
	cin >> phone;
	cout << "\n enter the age of sick: ";
	cin >> age;
	cout << "\n enter the sickness of sick: ";
	cin >> sickness;
	cout << "\n enter the doctorName of sick: ";
	cin >> doctorName;
	lists1.push_back(sick(name, family, address, phone, age, Idnumber, sickness, doctorName));

	outputfileS.open("sick.csv", ios::app);
		outputfileS << name + "," + family + "," + address + "," + phone + "," + to_string(age) + "," + to_string(Idnumber) + "," + sickness + "," + doctorName << endl;

}
void displayallSick()
{
	system("cls");
	cout << "\n\n\tall sick result   \n\n";
	cout << "================================================================================================\n";
	cout << "name     family      address      phone     age    idnumber    sickness   doctorName     count" << endl ;
	cout << "=================================================================================================\n";
	for (int i = 0;i < lists1.size();i++)
	{
		lists1[i].report();
	 }


}
void dispalayOneSick(int idnumber)
{
	system("cls");
	cout << "\n\n\tone sick result   \n\n";
	cout << "=========================================================================================="<<endl;
	cout << "name    family       address    phone     age   idnumber   sickness   doctorName   count"<<endl;
	cout << "==========================================================================================\n";
	for (int i = 0;i < lists1.size();i++)
	{
		if (lists1[i].getIdnumber() == idnumber)
		{
			lists1[i].report();
		}

	}
}
void modifySick(int idnumber)
{
	cout << "enter idnumber" << endl;
	cin >> idnumber;
	int a, age;
	string name, family, address, phone, sickness, doctorName;
	for (int i = 0;i < lists1.size();i++)
	{
		if (lists1[i].getIdnumber() == idnumber)
		{
			cout << "\n\n\n\tselect menu";
			cout << "\n\n\n\t1.name";
			cout << "\n\n\n\t2.family";
			cout << "\n\n\n\t3.address";
			cout << "\n\n\n\t4.phone";
			cout << "\n\n\n\t5.age";
			cout << "\n\n\n\t6.idnumber";
			cout << "\n\n\n\t7.sickness";
			cout << "\n\n\n\t8.doctorName";
			cout << "\n\n\n\t enter choice(1/2/3/4/5/6/7/8)";
			cin >> a;
			switch (a)
			{
			case 1:cout << "enter a name" << endl;cin >> name;lists1[i].setName(name);break;
			case 2:cout << "enter a family" << endl;cin >> family;lists1[i].setFamily(family);break;
			case 3:cout << "enter an address" << endl;cin >> address;lists1[i].setAddress(address);break;
			case 4:cout << "enter a phone" << endl;cin >> phone;lists1[i].setPhone(phone);break;
			case 5:cout << "enter an age " << endl;cin >> age;lists1[i].setAge(age);break;
			case 6:cout << "enter an idnumber" << endl;cin >> idnumber;lists1[i].setIdnumber(idnumber);break;
			case 7:cout << "enter a sickness" << endl;cin >> sickness;lists1[i].setSickness(sickness);break;
			case 8:cout << "enter a doctorName" << endl;cin >> doctorName;lists1[i].setDoctorName(doctorName);break;



			}

		}
	}
}
void deleteAllSick()
{
	lists1.clear();
}
void deleteOneSick(int Idnumber)
{
	cout << "enter idnumber\n";
	cin >> Idnumber;
	for (int i= 0;i <lists1.size();i++ )
	{
		if (lists1[i].getIdnumber() != Idnumber)
		{
			lists2.push_back(lists1[i]);
		}

	}
	lists1 = lists2;
	vector<sick>().swap(lists2);

}
multimap<string, string>getsavedSick()
{
	return sevedSick;
}
void regiester()
{

	for (int i = 0;i < lists1.size();i++)
	{
		
			sevedSick.insert(pair<string, string>(lists1[i].getDoctorName(),lists1[i] .getName() + " " + lists1[i].getFamily() + "   " + lists1[i].getSickness()));
		
	}

}
//#############################################################################################
//
//#########################################  doctor  ##########################################
vector<doctor>listd1, listd2;
fstream outputfiled;
void writeDoctor()
{
	int codeDoctor, age;
	string name, family, address, phone, experties;

	cout << "\n enter the number of doctor: ";
	cin >> codeDoctor;
	cout << "\n enter the name of doctor: ";
	cin >> name;
	cout << "\n enter the family of doctor: ";
	cin >> family;
	cout << "\n enter the address of doctor: ";
	cin >> address;
	cout << "\n enter the phone of doctor: ";
	cin >> phone;
	cout << "\n enter the age of doctor: ";
	cin >> age;
	cout << "\n enter the experties of doctor: ";
	cin >> experties;
	listd1.push_back(doctor(name, family, address, phone, age, codeDoctor, experties));

	outputfiled.open("doctor.csv", ios::app);
	outputfiled << name + "," + family + "," + address + "," + phone + "," + to_string(age) + "," + to_string(codeDoctor) + "," + experties << endl;

}
void displayallDoctor()
{
	system("cls");
	cout << "\n\n\tall doctor result   \n\n";
	cout << "======================================================================================\n";
	cout << "name      family       address    phone      age    codeDoctor    experties    number\n";
	cout << "======================================================================================\n";
	for (int i = 0;i < listd1.size();i++)
	{
		listd1[i].report();
	}


}
void dispalayOneDoctor(int codeDoctor)
{
	
	system("cls");
	cout << "\n\n\tone doctor result  \n\n";
	cout << "======================================================================================\n";
	cout << "name      family       address    phone      age    codeDoctor    experties    number\n";
	cout << "======================================================================================\n";
	for (int i = 0;i < listd1.size();i++)
	{
		if (listd1[i].getCodeDoctor() == codeDoctor)
		{
			listd1[i].report();
		}

	}
}
void modifyDoctor(int codedoctor)
{
	int a, age;
	string name, family, address, phone,  experties;
	for (int i = 0;i < listd1.size();i++)
	{
		if (listd1[i].getCodeDoctor() == codedoctor)
		{
			cout << "\n\n\n\tselect menu";
			cout << "\n\n\n\t1.name";
			cout << "\n\n\n\t2.family";
			cout << "\n\n\n\t3.address";
			cout << "\n\n\n\t4.phone";
			cout << "\n\n\n\t5.age";
			cout << "\n\n\n\t6.codeDoctor";
			cout << "\n\n\n\t7.experties";
			cout << "\n\n\n\t enter choice(1/2/3/4/5/6/7)";
			cin >> a;
			switch (a)
			{
			case 1:cout << "enter a name" << endl;cin >> name;listd1[i].setName(name);break;
			case 2:cout << "enter a family" << endl;cin >> family;listd1[i].setFamily(family);break;
			case 3:cout << "enter an address" << endl;cin >> address;listd1[i].setAddress(address);break;
			case 4:cout << "enter a phone" << endl;cin >> phone;listd1[i].setPhone(phone);break;
			case 5:cout << "enter an age " << endl;cin >> age;listd1[i].setAge(age);break;
			case 6:cout << "enter an idnumber" << endl;cin >> codedoctor;listd1[i].setCodeDoctor(codedoctor);break;
			case 7:cout << "enter a sickness" << endl;cin >> experties;listd1[i].setExperties(experties);break;
	
			}

		}
	}
}
void deleteAllDoctor()
{
	listd1.clear();
}
void deleteOneDoctor(int codeDoctor)
{
	for (int i = 0;i < listd1.size();i++)
	{
		if (listd1[i].getCodeDoctor() != codeDoctor)
		{
			listd2.push_back(listd1[i]);
		}

	}
	listd1 = listd2;
	vector<doctor>().swap(listd2);

}
vector<doctor>getDatad()
{
	return listd1;
}
void printsavedSick(string Family)
{
	regiester();
	
	multimap<string, string> list = getsavedSick();
	for (multimap<string, string>::iterator it = list.begin();it!=list.end();it++)
	{
		if (Family == it->first)
		{
			cout << it->second;
		}
	}
}
//===========================================menu=========================================
void intro()
{
	system("cls");
	cout << "\n\n\n\t\t SYSTEM HOSPITAL";
	cout << "\n\n\t\t ADVANCED C++ PROJECT";
	cout << "\n\n\n\t\t MADE BY :ZAHRA KOOHBORI";
	cout << "\n\n\t\t SCHOOL: QOM UNIVERSITY";
	cin.get();
}
void reportMenu()
{
	int a, e, f,z, idnumber;
	string Family;
	system("cls");
	cout << "\n\n\n\t REPORT MENU";
	cout << "\n\n\n\t\t 1_REPORTS";
	cout << "\n\n\t\t 2_BACK TO MAIN MENU";
	cout << "\n\n\t\t please enter your option(1-2)";
	cin >> a;
	switch (a)
	{
	case 1:
	{
		system("cls");
		cout << "\n\n\n\t REPORTS MENU";
		cout << "\n\n\n\t\t 1_SICK REPORTS";
		cout << "\n\n\t\t 2_DOCTOR REPORTS";
		cout << "\n\n\t\t please enter your option(1-2)";
		cin >> e;
		switch (e)
		{
		case 1:
		{
			cout << "\n\n\n\t\ 1_All sicks report";
			cout << "\n\n\n\t\ 2_one sick report";
			cout << "\n\n\t\t please enter your option(1-2)";
			cin >> f;
			switch (f)
			{
			case 1:displayallSick();
				_getch();
				break;
			case 2:
				cout << "\n enter the number of sick";
				cin >> idnumber;
				dispalayOneSick(idnumber);
				_getch();
				break;
			default: break;

			}
			break;
		}
		case 2:
		{
			
			cout << "\n\n\n\t\ 1_All doctors report";
			cout << "\n\n\n\t\ 2_one doctor report";
			cout << "\n\n\n\t\ 3_sicks of doctor report";
			cout << "\n\n\t\t please enter your option(1-3)";
			cin >> f;
			switch (f)
			{
			case 1:displayallDoctor();
				_getch();
				break;
			case 2:cout << "\n enter the number of doctor";
				cin >> idnumber;
				dispalayOneDoctor(idnumber) ;
				_getch();
				break;
			case 3:cout << "\n enter the family of doctor";
				cin >> Family;
				printsavedSick(Family);
					_getch();
			break;

			default: break;
			}
			break;
		
		}
		
		default: break;
		}
		break;

	}
	case 2: break;
	}
}
void enteryMenu()
{
	int a,b,c, num;
	char ch;
	system("cls");
	cout << "\n\n\n\t ENTRY MENU";
	cout << "\n\n\t\t 1_ ENTRY MENU SICK";
	cout << "\n\n\t\t 2_ENTRY MENU DOCTOR";
	cout << "\n\n\t\t 3_BACK TO MAIN MENU";
	cout << "\n\n\t\t please enter your option(1-3)";
	cin >> a;
	switch (a)
	{
		system("cls");
	case 1:
	{
		cout << "\n\n\n\t ENTRY MENU  SICK";
		cout << "\n\n\t\t1_CREAT SICK RECORD";
		cout << "\n\n\t\t 2_MODIFY SICK RECORD";
		cout << "\n\n\t\t 3_DETELE SICK RECORD";
		cout << "\n\n\t\t4_DETELE SICK RECORDS";
		cout << "\n\n\t\t 5_BACK TO MAIN MENU";
		cout << "\n\n\t\t please enter your option(1-5)";
		cin >> a;
		switch (a)
		{
		case 1:
		
			do
			{
				writeSick();
				cout << "\n Sick record has been created";
				system("cls");
				cout << "Do you want to insert new record of sick? Y|N";
				cin >> ch;
				system("cls");
			} while (ch == 'Y' || ch == 'y');
		   break;
		case 2:cout << "\n Enter the number of sick" << endl;
			cin >> num;modifySick(num);break;
			break;
		case 3:cout << "\n Enter the number of sick" << endl;
			cin >> num;deleteOneSick(num);break;
			break;
		case 4:deleteAllSick();break;
		case 5:break;
		}break;
	}


	case 2:
	{
		system("cls");

		cout << "\n\n\n\t ENTRY MENU  DOCTOR";
		cout << "\n\n\t\t1_CREAT DOCTOR RECORD";
		cout << "\n\n\t\t2_MODIFY  DOCTOR RECORD";
		cout << "\n\n\t\t3_DETELE DOCTOR RECORD";
		cout << "\n\n\t\t4_DETELE  DOCTOR RECORDS";
		cout << "\n\n\t\t5_BACK TO MAIN MENU";
		cout << "\n\n\t\t please enter your option(1-5)";
		cin >> a;
		switch (a)
		{
		case 1:
		
			do
			{
				writeDoctor();
				cout << "\n doctor record has been created";
				system("cls");
				cout << "Do you want to insert new record of doctor? Y|N";
				cin >> ch;
				system("cls");
			} while (ch == 'Y' || ch == 'y');
		break;
		case 2:cout << "\n Enter the number of doctor" << endl;
			cin >> num;modifyDoctor(num);break;
			break;
		case 3:cout << "\n Enter the number of doctor" << endl;
			cin >> num;deleteOneDoctor(num);break;
			break;

		case 4:deleteAllDoctor();break;
		case 5:break;
		}break;
	}

	case 3:break;
	}
	}
 int sick::count = 0;
int doctor::number = 0;
int main()
{
	intro();
	int a;
	
	do {
		system("cls");
		cout << "\n\n\n\t\t MAIN MENU";
		cout << "\n\n\t\t1_REPORT MENU";
		cout << "\n\n\n\t\t2_ENTRY/EDIT MENU";
		cout << "\n\n\t\t3_EXIT";
		cout << "\n\n\t\tplease enter your option(1-3)";
		cin >> a;
		system("cls");
		switch (a)
		{
		case 1:reportMenu();break;
		case 2:enteryMenu();break;
		case 3:break;
	

		}
		
	}while (a!=3);
	_getch();
	return 0;
}

