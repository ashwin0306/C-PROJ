
#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<iomanip.h>
#include<dos.h>		// for delay() function
#include<stdlib.h>	// for exit(() function
#include<stdio.h>	// for remove() and rename() function

class contact_list
{
	char fname[21];
	char lname[21];
	char mob[11];
	char city[16];

	public:
		contact_list()
		{
			strcpy(fname," ");
			strcpy(lname," ");
			strcpy(mob," ");
			strcpy(city," ");
		}
	char * get_fname(){return fname;}
	char * get_lname(){return lname;}
	char * get_mob(){return mob;}
	char * get_city(){return city;}

	void set_fname(char *tfname){strcpy(fname,tfname);}
	void set_lname(char *tlname){strcpy(lname,tlname);}
	void set_mob(char *tmob){strcpy(mob,tmob);}
	void set_city(char *tcity){strcpy(city,tcity);}

	void add_contact();
};

contact_list cl;

int ii=0;
void display_contact_list();
void display_contact_list_byname();
void display_contact_list_bycity();
void display_contact_list_bymob();
void display_details();
void display_deletedetails();
void search_menu();
char gfname[21];
char gcity[16];
char gmob[11];

ofstream ofile;
ifstream ifile;
fstream file;

void main()
{
	int opt,opt1;
	char ch,ch1,ach,gch;
	void drawbox_main();
	void drawbox_screen();
	void drawbox_modify();
	void drawbox_delete();
	void main_screen();
	void search_byname();
	void search_bycity();
	void search_bymob();
	void modify_bymob();
	void delete_bymob();
	void delete_contact();



	do
	{
		clrscr();
		drawbox_main();
		main_screen();
		cin>>opt;
		cin.get(ach);
	       switch(opt)
	       {
		case 1: clrscr();
			while(1)
			{
				drawbox_screen();
				cl.add_contact();
				gotoxy(45, 20);
				cout<<"Continue Add(y/n)=>";
				cin>>ach;
				cin.get(gch);
				if(ach!='y')
					break;
			}
			break;
		case 2: do
			{
				clrscr();
				drawbox_main();
				search_menu();
				cin>>opt1;
			       switch(opt1)
			       {
					case 1: clrscr();
						cin.get(ach);
						drawbox_screen();
						search_byname();
						break;
					case 2: clrscr();
						cin.get(ach);
						drawbox_screen();
						search_bymob();
						break;
					case 3: clrscr();
						cin.get(ach);
						drawbox_screen();
						search_bycity();
						break;
					case 4: clrscr();
						drawbox_screen();
						display_contact_list();
						break;
					case 5:break;
					default:
						gotoxy(41,14);
						cout<<"Invalid Choice!!!";
			       }
			       gotoxy(25, 20);
			       cout<<"Continue Display(y/n)=>";
			       cin>>ch1;
			       cin.get(ach);
			}while(ch1=='y');
			clrscr();
			drawbox_main();
			main_screen();
			break;
		case 3: clrscr();
			drawbox_modify();
			modify_bymob();
			break;
		case 4: clrscr();
			drawbox_delete();
			delete_bymob();
			gotoxy(45, 20);
			cout<<"Delete(y/n)=>";
			cin>>ach;
			cin.get(gch);
			if(ach=='y')
				delete_contact();
			break;
		case 5:exit(0);
		default:
			for(int i=0;i<=5;i++)
			{
				clrscr();
				delay(200);
				gotoxy(35,11);
				cprintf("Invalid Choice!!!");
				textcolor(RED);
				delay(300);
				drawbox_main();
				main_screen();
			}
			textcolor(WHITE);
	       }
	       gotoxy(25, 20);
	       cout<<"Continue(y/n)=>";
	       cin>>ch;
	} while(ch=='y');
	getch();

}	// main() ends here

void contact_list::add_contact()
{
	char ch;
	ofile.open("conlist.dat",ios::app|ios::binary);
	gotoxy(32, 6);
	cprintf("ADD CONTACT SCREEN");
	gotoxy(18, 10);
	cprintf("Fist Name [max 20 char(s)]:");
	cin.getline(cl.fname,21);
	gotoxy(18, 12);
	cprintf("Last Name [max 20 char(s)]:");
	cin.getline(cl.lname,21);
	gotoxy(18, 14);
	cprintf("Mobile [max 10 digits]    :");
	cin.getline(cl.mob,11);
	if(strlen(cl.mob)>=10)
		cin.get(ch);
	gotoxy(18, 16);
	cprintf("City   [max 15 char(s)]   :");
	cin.getline(cl.city,16);
	ofile.write((char*)&cl,sizeof(cl));
	ofile.close();
}

void main_screen()
{
		gotoxy(35, 6);
		cprintf("MAIN MENU");
		gotoxy(28, 8);
		cout<<"1. Add a contact";
		gotoxy(28, 10);
		cout<<"2. Display contact";
		gotoxy(28, 12);
		cout<<"3. Modify a contact";
		gotoxy(28,14);
		cout<<"4. Delete a contact";
		gotoxy(28, 16);
		cout<<"5. Exit";
		gotoxy(28,18);
		cout<<"Enter Choice[1-5]=>";
}

void search_menu()
{
		gotoxy(32, 6);
		cprintf("DISPLAY CONTACT LIST");
		gotoxy(28, 8);
		cout<<"1. List By First Name";
		gotoxy(28, 10);
		cout<<"2. List By Mobile";
		gotoxy(28, 12);
		cout<<"3. List By City";
		gotoxy(28, 14);
		cout<<"4. Display All" ;
		gotoxy(28,16);
		cout<<"5. Exit";
		gotoxy(28,18);
		cout<<"Enter Choice[1-5]=>";
}

void drawbox_main()
{
	int i,j;
	clrscr();
	for(i=4;i<22;i++)
	{
	       gotoxy(21,i);	// left vertical line
	       cout<<char(219);
	       gotoxy(60,i);
	       cout<<char(219); // right vertical line
	}
	for(j=21;j<=60;j++)
	{
	       gotoxy(j,3);
	       cout<<char(220);	//top horizontal line
	}
	for(j=21;j<=60;j++)
	{
	       gotoxy(j,21);
	       cout<<char(223); // bottom horizontal line
	}
}

void drawbox_screen()
{
	int i,j;
	clrscr();
	for(i=3;i<22;i++)
	{
	       gotoxy(2,i);
	       cout<<char(219);
	       gotoxy(77,i);
	       cout<<char(219);
	}
	for(j=2;j<=77;j++)
	{
	       gotoxy(j,2);
	       cout<<char(220);
	}
	for(j=2;j<=77;j++)
	{
	       gotoxy(j,22);
	       cout<<char(223);
	}
}

void drawbox_modify()
{
	int i,j;
	clrscr();
	for(i=2;i<22;i++)
	{
	       gotoxy(2,i);
	       cout<<char(219);
	       gotoxy(80,i);
	       cout<<char(219);
	       gotoxy(41,i);
	       cout<<char(219);
	}
	for(j=2;j<=80;j++)
	{
	       gotoxy(j,2);
	       cout<<char(220);
	}
	for(j=2;j<=80;j++)
	{
	       gotoxy(j,22);
	       cout<<char(223);
	}
}

void drawbox_delete()
{
	int i,j;
	clrscr();
	for(i=2;i<22;i++)
	{
	       gotoxy(2,i);
	       cout<<char(219);
	       gotoxy(80,i);
	       cout<<char(219);
	}
	for(j=2;j<=80;j++)
	{
	       gotoxy(j,2);
	       cout<<char(220);
	}
	for(j=2;j<=80;j++)
	{
	       gotoxy(j,22);
	       cout<<char(223);
	}
}

void search_byname()
{
	gotoxy(5,5);
	cout<<"Enter First Name :";
	cin.getline(gfname,21);
	display_contact_list_byname();

}

void search_bycity()
{
	gotoxy(5,5);
	cout<<"Enter City :";
	cin.getline(gcity,16);
	display_contact_list_bycity();

}

void search_bymob()
{
	gotoxy(5,5);
	cout<<"Enter Mobile No :";
	cin.getline(gmob,11);
	display_contact_list_bymob();

}

void delete_bymob()
{
	char ch;
	gotoxy(5,5);
	cout<<"Enter Mobile No :";
	cin.getline(gmob,11);
	if(strlen(gmob)>=10)
		cin.get(ch);
	display_deletedetails();

}

void display_deletedetails()
{
	int flag=0;
	char vfname[21],vlname[21],vmob[11],vcity[16],ch;
	ifile.open("conlist.dat",ios::in|ios::binary);
	while(ifile.read((char*)&cl,sizeof(cl)))
	{
		if(strcmp(cl.get_mob(),gmob)==0)
		{
		gotoxy(5,9);
		cout<<"First Name :";
		gotoxy(18,9);
		setw(20);
		cout<<cl.get_fname();
		gotoxy(5,11);
		cout<<"Last Name  :";
		gotoxy(18,11);
		setw(20);
		cout<<cl.get_lname();
		gotoxy(5,13);
		cout<<"Mobile     :" ;
		gotoxy(18,13);
		setw(10);
		cout<<cl.get_mob();
		gotoxy(5,15);
		cout<<"City       :";
		gotoxy(18,15);
		setw(15);
		cout<<cl.get_city();
		flag=1;
		break;
		}        // if compare ends here
	}	// while loop ends here
	if(flag==0)
	{
		for(int i=0;i<=5;i++)
			{
				clrscr();
				delay(200);
				gotoxy(35,11);
				cprintf("Record Not Found !");
				textcolor(RED);
				delay(300);
				drawbox_main();
				main_screen();
			}
	}
	ifile.close();
}
void delete_contact()
{
	ofile.open("tmp.dat",ios::out|ios::binary);
	ifile.open("conlist.dat",ios::in|ios::binary);
	while(ifile.read((char*)&cl,sizeof(cl)))
	{
		if(strcmp(cl.get_mob(),gmob)==0)
		{
			;
		}
		else
			ofile.write((char*)&cl,sizeof(cl));
	}
	ifile.close();
	ofile.close();
	remove("conlist.dat");
	rename("tmp.dat","conlist.dat");
}
void modify_bymob()
{
	char ch;
	gotoxy(5,5);
	cout<<"Enter Mobile No :";
	cin.getline(gmob,11);
	if(strlen(gmob)>=10)
		cin.get(ch);
	display_details();

}

void display_details()
{
	int pos=0,flag=0;
	char vfname[21],vlname[21],vmob[11],vcity[16],ch;
	file.open("conlist.dat",ios::in|ios::binary|ios::out);
	while(file.read((char*)&cl,sizeof(cl)))
	{
		pos=file.tellg();
		if(strcmp(cl.get_mob(),gmob)==0)
		{
		gotoxy(5,9);
		cout<<"First Name :";
		gotoxy(18,9);
		setw(20);
		cout<<cl.get_fname();
		gotoxy(5,11);
		cout<<"Last Name  :";
		gotoxy(18,11);
		setw(20);
		cout<<cl.get_lname();
		gotoxy(5,13);
		cout<<"Mobile     :" ;
		gotoxy(18,13);
		setw(10);
		cout<<cl.get_mob();
		gotoxy(5,15);
		cout<<"City       :";
		gotoxy(18,15);
		setw(15);
		cout<<cl.get_city();
		flag=1;
		break;
		}        // if compare ends here
	}	// while loop ends here
	if(flag==1)
	{
		gotoxy(51,5);
		cout<<"Modify Data";
		gotoxy(43,9);
		cout<<"First Name :";
		cin.getline(vfname,21);
		gotoxy(43,11);
		cout<<"Last  Name :";
		cin.getline(vlname,21);
		gotoxy(43,13);
		cout<<"Mobile     :";
		cin.getline(vmob,21);
		gotoxy(43,15);
		cout<<"City       :";
		cin.getline(vcity,21);

		cl.set_fname(vfname);
		cl.set_lname(vlname);
		cl.set_mob(vmob);
		cl.set_city(vcity);
		file.seekg((pos-sizeof(cl)),ios::beg);
		file.write((char*)&cl,sizeof(cl));
	}
	else if(flag==0)
	{
		for(int i=0;i<=5;i++)
			{
				clrscr();
				delay(200);
				gotoxy(35,11);
				cprintf("Record Not Found !");
				textcolor(RED);
				delay(300);
				drawbox_main();
				main_screen();
			}
	}
	file.close();
}

void display_contact_list_byname()
{
	int j=0,k=4,m=1;
	clrscr();
	ifile.open("conlist.dat",ios::in|ios::binary);
	drawbox_screen();
	gotoxy(35,k);
	cout<<"CONTACT LIST";
	gotoxy(4,6);
	setw(2);
	cout<<"#";
	gotoxy(7,6);
	setw(20);
	cout<<"First Name";
	gotoxy(29,6);
	setw(20);
	cout<<"Last Name";
	gotoxy(51,6);
	setw(10);
	cout<<"Mobile";
	gotoxy(67,6);
	setw(15);
	cout<<"City";
	k+=4;
	while(ifile.read((char*)&cl,sizeof(cl)))
	{
		if(strcmp(cl.get_fname(),gfname)==0)
		{
		gotoxy(4,k);
		setw(2);
		cout<<m;
		gotoxy(7,k);
		setw(20);
		cout<<cl.get_fname();
		gotoxy(29,k);
		setw(20);
		cout<<cl.get_lname();
		gotoxy(51,k);
		setw(10);
		cout<<cl.get_mob();
		gotoxy(67,k);
		setw(15);
		cout<<cl.get_city();
		k++;
		m++;
		  if((m%12)==0)
		  {
			gotoxy(51,23);
			cout<<"Press any key to continue...";
			getch();
			clrscr();
			drawbox_screen();
			k=4;
			gotoxy(35,k);
			cout<<"CONTACT LIST";
			gotoxy(4,6);
			setw(2);
			cout<<"#";
			gotoxy(7,6);
			setw(20);
			cout<<"First Name";
			gotoxy(29,6);
			setw(20);
			cout<<"Last Name";
			gotoxy(51,6);
			setw(10);
			cout<<"Mobile";
			gotoxy(67,6);
			setw(15);
			cout<<"City";
			k+=4;
		  }	// if ends here
		}
	}		// while loop ends here
	ifile.close();
}

void display_contact_list_bycity()
{
	int j=0,k=4,m=1;
	clrscr();
	ifile.open("conlist.dat",ios::in|ios::binary);
	drawbox_screen();
	gotoxy(35,k);
	cout<<"CONTACT LIST";
	gotoxy(4,6);
	setw(2);
	cout<<"#";
	gotoxy(7,6);
	setw(20);
	cout<<"First Name";
	gotoxy(29,6);
	setw(20);
	cout<<"Last Name";
	gotoxy(51,6);
	setw(10);
	cout<<"Mobile";
	gotoxy(67,6);
	setw(15);
	cout<<"City";
	k+=4;
	while(ifile.read((char*)&cl,sizeof(cl)))
	{
		if(strcmp(cl.get_city(),gcity)==0)
		{
		gotoxy(4,k);
		setw(2);
		cout<<m;
		gotoxy(7,k);
		setw(20);
		cout<<cl.get_fname();
		gotoxy(29,k);
		setw(20);
		cout<<cl.get_lname();
		gotoxy(51,k);
		setw(10);
		cout<<cl.get_mob();
		gotoxy(67,k);
		setw(15);
		cout<<cl.get_city();
		k++;
		m++;
		if((m%12)==0)
		{
			gotoxy(51,23);
			cout<<"Press any key to continue...";
			getch();
			clrscr();
			drawbox_screen();
			k=4;
			gotoxy(35,k);
			cout<<"Contact List";
			gotoxy(4,6);
			setw(2);
			cout<<"#";
			gotoxy(7,6);
			setw(20);
			cout<<"First Name";
			gotoxy(29,6);
			setw(20);
			cout<<"Last Name";
			gotoxy(51,6);
			setw(10);
			cout<<"Mobile";
			gotoxy(67,6);
			setw(15);
			cout<<"City";
			k+=4;
		}	 // if ends here
		}	 // if compare ends here
		j++;
	}	       	// while loop ends here
	ifile.close();
}

void display_contact_list_bymob()
{
	int j=0,k=4,m=1;
	clrscr();
	ifile.open("conlist.dat",ios::in|ios::binary);
	drawbox_screen();
	gotoxy(35,k);
	cout<<"CONTACT LIST";
	gotoxy(4,6);
	setw(2);
	cout<<"#";
	gotoxy(7,6);
	setw(20);
	cout<<"First Name";
	gotoxy(29,6);
	setw(20);
	cout<<"Last Name";
	gotoxy(51,6);
	setw(10);
	cout<<"Mobile";
	gotoxy(67,6);
	setw(15);
	cout<<"City";
	k+=4;
	while(ifile.read((char*)&cl,sizeof(cl)))
	{
		if(strcmp(cl.get_mob(),gmob)==0)
		{
		gotoxy(4,k);
		setw(2);
		cout<<m;
		gotoxy(7,k);
		setw(20);
		cout<<cl.get_fname();
		gotoxy(29,k);
		setw(20);
		cout<<cl.get_lname();
		gotoxy(51,k);
		setw(10);
		cout<<cl.get_mob();
		gotoxy(67,k);
		setw(15);
		cout<<cl.get_city();
		k++;
		m++;
		if((m%12)==0)
		{
			gotoxy(51,23);
			cout<<"Press any key to continue...";
			getch();
			clrscr();
			drawbox_screen();
			k=4;
			gotoxy(35,k);
			cout<<"Contact List";
			gotoxy(4,6);
			setw(2);
			cout<<"#";
			gotoxy(7,6);
			setw(20);
			cout<<"First Name";
			gotoxy(29,6);
			setw(20);
			cout<<"Last Name";
			gotoxy(51,6);
			setw(10);
			cout<<"Mobile";
			gotoxy(67,6);
			setw(15);
			cout<<"City";
			k+=4;
		}	// if ends here
		}	 // if compare ends here
		j++;
	}		// while loop ends here
	ifile.close();
}

void display_contact_list()
{
	int j=0,k=4,m=1;
	ifile.open("conlist.dat",ios::in|ios::binary);
	gotoxy(35,k);
	cout<<"CONTACT LIST";
	gotoxy(4,6);
	setw(2);
	cout<<"#";
	gotoxy(7,6);
	setw(20);
	cout<<"First Name";
	gotoxy(29,6);
	setw(20);
	cout<<"Last Name";
	gotoxy(51,6);
	setw(10);
	cout<<"Mobile";
	gotoxy(67,6);
	setw(15);
	cout<<"City";
	k+=4;
	while(ifile.read((char*)&cl,sizeof(cl)))
	{
		gotoxy(4,k);
		setw(2);
		cout<<m;
		gotoxy(7,k);
		setw(20);
		cout<<cl.get_fname();
		gotoxy(29,k);
		setw(20);
		cout<<cl.get_lname();
		gotoxy(51,k);
		setw(10);
		cout<<cl.get_mob();
		gotoxy(67,k);
		setw(15);
		cout<<cl.get_city();
		k++;
		m++;
		if((m%12)==0)
		{
			gotoxy(51,23);
			cout<<"Press any key to continue...";
			getch();
			clrscr();
			drawbox_screen();
			k=4;
			gotoxy(35,k);
			cout<<"Contact List";
			gotoxy(4,6);
			setw(2);
			cout<<"#";
			gotoxy(7,6);
			setw(20);
			cout<<"First Name";
			gotoxy(29,6);
			setw(20);
			cout<<"Last Name";
			gotoxy(51,6);
			setw(10);
			cout<<"Mobile";
			gotoxy(67,6);
			setw(15);
			cout<<"City";
			k+=4;
		}
	}	// end while loop
	ifile.close();
}