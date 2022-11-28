#include <iostream>
// #include <dos.h>
#include <conio.h>
#include <stdio.h>
#include <fstream>
using namespace std;

//=================================================================//
//                        Public class                             //
//=================================================================//
class hotel{
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
    void bill(int);             //for the bill of a record                


};
//=================================================================//
//                          Main menu                              //
//=================================================================//
void hotel::main_menu(){
    
    int choice;
    while(choice!=5){
        system("cls");
        
        //display of mainmenu
        
        cout<<"******************\n";
        cout<<"*     AR HOTEL   *\n";
        cout<<"******************\n"<<endl<<endl;
        cout<<"1. Book a room\n";
        cout<<"2. customer Records\n";
        cout<<"3. Room Alloted\n";
        cout<<"4. Edit Records\n";
        cout<<"5. Exit\n\n";

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

        case 5:system("exit");
        break;

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
void hotel::add(){


    system("cls");
    int choice;
    cout<<"      Booking Section    \n";
    cout<<"---------------------------\n\n";
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
void hotel::display(){

    system("cls");

ifstream fin("record.txt",ios::in);
int r,flag;

cout<<"\n Enter room number for a particular customer`s details :- ";cin>>r;

while(!fin.eof())
{

fin.read((char*)this,sizeof(hotel));
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
void hotel::rooms(){
      system("cls");

ifstream fin("record.txt",ios::in);
cout<<"\n\t\t\t    List Of Rooms Allotted";
cout<<"\n\t\t\t    ----------------------";
cout<<"\n\n Room No.\tName\t\tAddress\t\tPhone No.\n";

while(!fin.eof())
{

fin.read((char*)this,sizeof(hotel));
// cout<<"\n\n "<<room_no<<"\t\t"<<name;
// cout<<"\t\t"<<address<<"\t\t"<<phone;
cout<<"\n\n "<<room_no<<"\t\t"<<name<<"\t\t"<<address<<"\t\t"<<phone;

}

cout<<"\n\n\n\t\t\tPress any key to continue.....!!";
getch();
fin.close();
}
//=================================================================//
//                       4.Edit Records                            //
//=================================================================//
void hotel::edit(){
    int choice,r;
    while (choice!=3)
    {
         system("cls");


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

case 3:
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
void hotel::add_room(){
        system("cls");
        int r,flag;
        ofstream fout("record.txt");
        
        cout<<"\n Total no. of Rooms - 50\n";
        cout<<"\n ORDINARY Rooms from : [ 1 - 30 ]\n";
        cout<<"\n LUXUARY Rooms from  : [ 31 - 45 ]\n";
        cout<<"\n ROYAL Rooms from    : [ 46 - 50 ]\n"<<endl;
        
        cout<<"\n Enter The Room no. you want to stay in :- ";
        cin>>r;

    if(r<=50){

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
            
            fout.write((char*)this,sizeof(hotel));
            cout<<"\n The room number "<<r<<" is alloted for you...!"<<endl;
            
        }
    }
    else{
        system("cls");
        cout<<"\n\n";
        cout<<"\t\tWe don't have more than 50 rooms, so please change the number !"<<endl;
    }

        cout<<"\n Press any key to continue.....!!";
        getch();
        fout.close();
        system("cls");
        
}
//=================================================================//
//                   1.Book a room >> 1.About                      //
//=================================================================//
void hotel::about(){
    
    int choice;

    while(choice!=1){
    system("cls");
    cout<<"      Features    \n";
    cout<<"-------------------\n\n";
    
    cout<<"ORDINARY [Single & simple room] :\n\na) Single bed \nb) Smart TV \nc) A private bathroom and a shower \nd) Working desk.\n\n";
    cout<<"LUXUARY [Spacious room]:\n\na) King-size bed \nb) Smart TV \nc) Jacuzzi \nd) Wifi \ne) Single Recliner Sofa \nf) Working desk.\n\n";
    cout<<"ROYAL(V.I.P) [Studio Quality room] :\n\na) Special-size bed \nb) Smart TV \nc) Large size Heated Jacuzzi \nd) 5g- Wifi \ne) Spacious Recliner Sofa \nf) Working desk with precious views.\ng) Fully furnished apartment\n\n";

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
int hotel::check(int r)

{

int flag=0;

ifstream fin("record.txt",ios::in);

while(!fin.eof())
{

fin.read((char*)this,sizeof(hotel));
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
void hotel::modify(int r)

{

long pos,flag=0;

fstream file("record.txt",ios::in|ios::out|ios::binary);

while(!file.eof())
{

pos=file.tellg();
file.read((char*)this,sizeof(hotel));

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
file.write((char*)this,sizeof(hotel));
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
void hotel::delete_rec(int r)
{

int flag=0;
char ch;
ifstream fin("record.txt",ios::in);
ofstream fout("temp.dat",ios::out);

while(!fin.eof())
{

fin.read((char*)this,sizeof(hotel));
if(room_no==r)

{

cout<<"\n Name: "<<name;
cout<<"\n Address: "<<address;
cout<<"\n Phone No: "<<phone;
cout<<"\n\n Do you want to delete this record(y/n): ";
cin>>ch;

if(ch=='n')
fout.write((char*)this,sizeof(hotel));
flag=1;

}

else
fout.write((char*)this,sizeof(hotel));

}

fin.close();
fout.close();

if(flag==0)
cout<<"\n Sorry room no. not found or vacant...!!";

else
{

remove("record.txt");
rename("temp.dat","record.txt");

}

}
//=================================================================//
//                           First Page                            //
//=================================================================//
int main(){
    hotel h;

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

//Code End
