#include <iostream>
#include <dos.h>
#include <conio.h>
#include <stdio.h>
#include <fstream>
using namespace std;


//=================================================================//
//                        Public class                             //
//=================================================================//
class home{
    int room_no;
    char name[30];
    char address[50];
    char phone[10];

    public:
    void add_room();       //room number input
    void about();           //display all functions and room types
    void main_menu();		//to dispay the main menu
    void add();			//to book a room
    void display(); 		//to display the customer record
    void rooms();			//to display alloted rooms
    void edit();			//to edit the customer record
    int check(int);			//to check room status
    void modify(int);		//to modify the record
    void delete_rec(int);		//to delete the record
    void bill(int);                 //for the bill of a record


};
//=================================================================//
//                          Main menu                              //
//=================================================================//
void home::main_menu(){
    system("cls");
    int choice;
    while(choice!=5){
        
        //display of mainmenu
        
        cout<<"******************\n";
        cout<<"*     AR HOTEL   *\n";
        cout<<"******************\n"<<endl<<endl;
        cout<<"1. Book a room\n";
        cout<<"2. customer Records\n";
        cout<<"3. Room Alloted\n";
        cout<<"4. Edit Records\n";
        cout<<"5. Exit\n"<<endl;

        //display of mainmenu

        cout<<"Enter your number : ";cin>>choice;       //input of mainmenu
        

        switch (choice)
        {
        case 1:add();
            break;

        case 2:display();
            break;

        case 3:rooms();
            break;

        case 4:edit();
            break;

        case 5:break;

        default:
            cout<<"\n\nWrong choice !"<<endl;
            cout<<"press enter to continue...!!"<<endl;
            getch();                                    //error of wrong number
        }

    }

}
//=================================================================//
//                       1.Book a room                             //
//=================================================================//
void home::add(){

    system("cls");
    int choice;
    cout<<"******************\n";
    cout<<"*     AR HOTEL   *\n";
    cout<<"******************\n"<<endl<<endl;
    cout<<"1. About\n";
    cout<<"2. Select a room\n";
    cout<<"3. Back\n"<<endl;
    
    cout<<"choose your number : ";cin>>choice;
    switch (choice)
    {
    case 1:about();
        break;
    case 2:add_room();
        break;
    case 3:
        break;
    
    default:
        cout<<"\n\nWrong choice !"<<endl;
        cout<<"press enter to continue...!!"<<endl;
        getch();
    }
}
//=================================================================//
//                       2.Customer Records                        //
//=================================================================//
void home::display(){

    system("cls");

ifstream fin("Record.dat",ios::in);
int r,flag;

cout<<"\n Enter room no. for a particular customer`s details :- "<<endl;
cin>>r;

while(!fin.eof())
{

fin.read((char*)this,sizeof(home));
if(room_no==r)
{

  system("cls");
cout<<"\n Cusromer Details";
cout<<"\n ----------------";
cout<<"\n\n Room no: "<<room_no;
cout<<"\n Name: "<<name;
cout<<"\n Address: "<<address;
cout<<"\n Phone no: "<<phone;
flag=1;
break;

}

}

if(flag==0)
cout<<"\n Sorry Room no. not found or vacant....!!";
cout<<"\n\n Press any key to continue....!!";

getch();
fin.close();
system("cls");

}
//=================================================================//
//                       3.Room Alloted                            //
//=================================================================//
void home::rooms(){
      system("cls");

ifstream fin("Record.dat",ios::in);
cout<<"\n\t\t\t    List Of Rooms Allotted";
cout<<"\n\t\t\t    ----------------------";
cout<<"\n\n Room No.\tName\t\tAddress\t\tPhone No.\n";

while(!fin.eof())
{

fin.read((char*)this,sizeof(home));
cout<<"\n\n "<<room_no<<"\t\t"<<name;
cout<<"\t\t"<<address<<"\t\t"<<phone;

}

cout<<"\n\n\n\t\t\tPress any key to continue.....!!";
getch();
fin.close();
}
//=================================================================//
//                       4.Edit Records                            //
//=================================================================//
void home::edit(){
    int cho;
    while (cho!=3)
    {
         system("cls");

int choice,r;
cout<<"\n EDIT MENU";
cout<<"\n ---------";
cout<<"\n 1. Modify Customer Record";
cout<<"\n 2. Delete Customer Record";
cout<<"\n 3. Back";
cout<<"\n Enter your choice: ";

cin>>choice;
  system("cls");

// cout<<"\n Enter room no: " ;
// cin>>r;

switch(choice)
{

case 1:
cout<<"\n Enter room no: " ;
cin>>r;	
modify(r);
break;

case 2:
cout<<"\n Enter room no: " ;
cin>>r;	
delete_rec(r);
break;

case 3: main_menu();
break;

default: cout<<"\n Wrong Choice.....!!";

}
cout<<"\n Press any key to continue....!!!";

getch();

}
    

}
//=================================================================//
//                   1.Book a room >> 2.Select a room              //
//=================================================================//
void home::add_room(){
        system("cls");
        int r,flag;
        ofstream fout("Record.dat",ios::app);
        
        cout<<"\n Total no. of Rooms - 50\n";
        cout<<"\n ORDINARY Rooms from : [ 01 - 30 ]\n";
        cout<<"\n LUXUARY Rooms from  : [ 31 - 45 ]\n";
        cout<<"\n ROYAL Rooms from    : [ 46 - 50 ]\n"<<endl;
        cout<<"\n Enter The Room no. you want to stay in :- ";cin>>r;

        flag=check(r);

        if (flag)
        {
            cout<<"\n Sorry..!!!Room is already booked";
        }
        else{
            system("cls");
            room_no=r;
            cout<<"====================================\n";
            cout<<"* IMPORTENT : DO NOT USE SPACE KEY *\n";
            cout<<"====================================\n"<<endl;
            cout<<" Name: ";     cin>>name; 
            //cin.getline(name , sizeof(name));
            cout<<" Address: ";  cin>>address;
            //cin.getline(address , sizeof(address));
            cout<<" Phone No: "; cin>>phone;
            //cin.getline(phone , sizeof(phone));
            
            fout.write((char*)this,sizeof(home));
            cout<<"\n The room number "<<r<<" is alloted for you...!"<<endl;
            
        }
        cout<<"\n Press any key to continue.....!!";
        getch();
        fout.close();
        system("cls");
        
}
//=================================================================//
//                   1.Book a room >> 1.About                      //
//=================================================================//
void home::about(){
    system("cls");
    int choice;

    while(choice!=1){
    cout<<"******************\n";
    cout<<"*     AR HOTEL   *\n";
    cout<<"******************\n"<<endl<<endl;
    cout<<"      Features    \n\n";
    cout<<"ORDINARY : \n\n";
    cout<<"LUXUARY : \n\n";
    cout<<"ROYAL(V.I.P) : \n\n";

    cout<<"Press (1) for Back : ";cin>>choice;

    switch (choice)
    {

    case 1:add();
        break;

    default:
        break;
    }

    }   
}
//=================================================================//
//                          Check function                         //
//=================================================================//
int home::check(int r)

{

int flag=0;

ifstream fin("Record.dat",ios::in);

while(!fin.eof())
{

fin.read((char*)this,sizeof(home));
if(room_no==r)
{

flag=1;
break;

}

}

fin.close();
return(flag);

}
//=================================================================//
//              4.Edit Records >> 1.Modify Customer Record         //
//=================================================================//
void home::modify(int r)

{

long pos,flag=0;

fstream file("Record.dat",ios::in|ios::out|ios::binary);

while(!file.eof())
{

pos=file.tellg();
file.read((char*)this,sizeof(home));

if(room_no==r)
{

cout<<"\n Enter New Details";
cout<<"\n -----------------";
cout<<"\n Name: ";
cin>>name;
cout<<" Address: ";
cin>>address;
cout<<" Phone no: ";
cin>>phone;
file.seekg(pos);
file.write((char*)this,sizeof(home));
cout<<"\n Record is modified....!!";
flag=1;
break;

}

}

if(flag==0)
cout<<"\n Sorry Room no. not found or vacant...!!";
file.close();

}
//=================================================================//
//              4.Edit Records >> 2.Delete Customer Record         //
//=================================================================//
void home::delete_rec(int r)
{

int flag=0;
char ch;
ifstream fin("Record.dat",ios::in);
ofstream fout("temp.dat",ios::out);

while(!fin.eof())
{

fin.read((char*)this,sizeof(home));
if(room_no==r)

{

cout<<"\n Name: "<<name;
cout<<"\n Address: "<<address;
cout<<"\n Phone No: "<<phone;
cout<<"\n\n Do you want to delete this record(y/n): ";
cin>>ch;

if(ch=='n')
fout.write((char*)this,sizeof(home));
flag=1;

}

else
fout.write((char*)this,sizeof(home));

}

fin.close();
fout.close();

if(flag==0)
cout<<"\n Sorry room no. not found or vacant...!!";

else
{

remove("Record.dat");
rename("temp.dat","Record.dat");

}

}
//=================================================================//
//                           First Page                            //
//=================================================================//
int main(){
    home h;

  system("cls");

cout<<"\n\t\t\t****************************";
cout<<"\n\t\t\t* HOTEL MANAGEMENT PROJECT *";
cout<<"\n\t\t\t****************************";
cout<<"\n\n\t\tDeveloped By:";
cout<<"\t Raj Sekhar Saha & Avishek Karmakar";
cout<<"\n\n\n\n\n\n\n\t\t\tPress any key to continue....!!";

getch();

h.main_menu();
return 0;
}







