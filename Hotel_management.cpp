#include<iostream>
#include<conio.h>
#include<fstream>
#define MAX 50

using namespace std;

class info
{
    public:
        void show()
        {
            system("cls");
            cout<<"\n\t\t\t****************************";
            cout<<"\n\t\t\t* HOTEL MANAGEMENT PROJECT *";
            cout<<"\n\t\t\t****************************";
            cout<<"\n\n\t\tDeveloped By:";
            cout<<"group 7";
            cout<<"\n\n                 25-Siddhesh Kadam";
            cout<<"\n                 26-Rohan Hanmante";
            cout<<"\n                 27-Arya Nikale";
            cout<<"\n                 28-Jhanvi Khot";
            cout<<"\n\n\n\n\n\n\n\t\t\t\t\tPress any key to continue....!!";
            getch();
            }
};

class hotel : public info{
    public:
        int room_no;
        char name[30];
        char address[50];
        char phone[10],email[30];
        int days,yes_no;
        long int cost;
        long int total;
        void input();
        void display();
        void display_all();
        void operator -()
        {
                  room_no=-2;
        }
};

void hotel :: input()
{
        system("cls");
        int flag=0,r;
        cout<<"\n Enter Customer Detalis";
        cout<<"\n ----------------------";
        cout<<"\n\n Room no: ";
        cout<<"\n Total no. of Rooms - 50\t Price/day";
        cout<<"\n Ordinary Rooms from 1 - 30\t 5000/day";
        cout<<"\n Luxury Rooms from 31 - 45\t 7000/day";
        cout<<"\n Royal Rooms from 46 - 50\t 10000/day";
        cout <<"\n Enter The Room no. you want to stay in :- "<<endl;
        cin>>room_no;
            fstream f;
            f.open("hotel_rooms.txt",ios::app);
            correct:
            cout<<" Name: ";
            cin>>name;
            cout<<" Address: ";
            cin>>address;
            cout<<" Phone No: ";
            cin>>phone;
            cout<<" Email: ";
            cin>>email;
            cout << "\n\nAre you sure the Details entered are correct? \nIf yes press 1 else 2: ";
            cin >> yes_no;
            if(yes_no==1)
            {
                    f<<endl;
                    f<<"*************DETAILS**************"<<endl;
                    f<<" NAME:       "<<name<<endl;
                    f<<" ROOM NO:    "<<room_no<<endl;
                    f<<" ADDRESS:    "<<address<<endl;
                    f<<" PHONE:      "<<phone<<endl;
                    f<<" EMAIL:      "<<email<<endl;
                    f<<"**********************************"<<endl<<endl;
            }
            else
            {
                    cout << "\nPlease  enter Details carefully!!";
                    goto correct;
            }
            cout << "\nFor how many days you want the room :- ";
            cin >> days;
            if(room_no<=30 && room_no>0)
            {
                cost=5000;
                total=cost*days;
                cout << "\nTotal= " << total;
            }
            if(room_no<=45 && room_no>30)
            {
                cost=7000;
                total=cost*days;
                cout << "\nTotal= " << total;
            }
            if(room_no<=50 && room_no>45)
            {
                cost=10000;
                total=cost*days;
                cout << "\nTotal= " << total;
            }
}

void hotel :: display()
{
        cout<<"\n Cusromer Details";
        cout<<"\n ----------------";
        cout<<"\n\n Room no: "<<room_no;
        cout<<"\n Name: "<<name;
        cout<<"\n Address: "<<address;
        cout<<"\n Phone no: "<<phone;
        if(room_no<=30 && room_no>0)
        {
            cout << "\nRoom type: Ordinary Room" ;
        }
        if(room_no<=45 && room_no>30)
        {
            cout << "\nRoom type: Luxury Room" ;
        }
        if(room_no<=50 && room_no>45)
        {
            cout << "\nRoom type: Royal Room" ;
        }
}
void hotel :: display_all()
{
            ifstream fin;
            fin.open("hotel_rooms.txt");
            char data;
            while(!fin.eof())
            {
                 fin.get (data);
                 cout<<data;
            }
}



int main()
{
        hotel h[MAX];
        int choice,cust_no=0,room_no=0,i,tries=0;
        hotel in;
        system("cls");
        in.show();
        system("cls");
        int adminpass=12345;
        int password;
        while(1)
        {
            ofstream logFile("hotel.txt",ios::app);
            next:
            system("cls");
            cout<<"\n\t\t\t\t*************************";
            cout<<"\n\t\t\t\t SIMPLE HOTEL MANAGEMENT ";
            cout<<"\n\t\t\t\t      * MAIN MENU *";
            cout<<"\n\t\t\t\t*************************";
            cout<<"\n\n\n\t\t\t1.Book A Room";
            cout<<"\n\t\t\t2.Customer Records";
            cout<<"\n\t\t\t3.All Records";
            cout<<"\n\t\t\t4.Delete Record";
            cout<<"\n\t\t\t5.Exit";
            cout<<"\n\n\t\t\tEnter Your Choice: ";
            cin>>choice;
                switch(choice)
                {
                case 1:
                       system("cls");
                       if (cust_no < MAX)
                       {
                           h[cust_no].input();
                           cust_no++;
                           logFile<<"Customer Details added"<<endl;
                           logFile.close();
                           getch();
                           cout<<"\nRoom Booked!";
                           cout<<"\n\n Press any key to continue....!!";
                           getch();
                           system("cls");
                        }
                        else
                        {
                            cout << "\nMax Customer record reached!!";
                            getch();
                            system("cls");
                        }
                break;
                case 2:
                        system("cls");
                        cout<<"\n Enter room no. for a particular customer`s details :- "<<endl;
                        cin>>room_no;
                        for( i=0;i<MAX;i++)
                        {
                            if(room_no==h[i].room_no)
                            {
                                h[i].display();
                                logFile<<"Customer Data Dispalyed of room no " << room_no <<endl;
                                logFile.close();
                                break;
                            }

                        }
                        if(room_no!=h[i].room_no)
                        {
                                cout << "\nThe room is vacant!!";
                        }
                        getch();
                        system("cls");
                break;
                case 3:

                        system("cls");
                        cout<<"\n\nPlease Enter the Admin Password: ";
                        cin>>password;
                        i=0;
                                if(password==adminpass)
                                {
                                        system("cls");
                                        logFile<<"All Customer Record Displayed to Admin "<<endl;
                                        logFile.close();
                                        cout<<"\nThis the Customer Record for the HOTEL: "<<endl;
                                        h[i].display_all();
                                        cout << "\n\n\t\t\tPress any key to continue.";
                                        getch();
                                }
                                if(password!=adminpass)
                                {
                                        cout<<"\n*Wrong password*";
                                        logFile<<"Admin tried to open all customer records!!"<<endl;
                                        logFile.close();
                                        getch();
                                }

                break;
                case 4:
                        system("cls");
                        cout<<"\nEnter the room_no: ";
                        cin >> room_no;
                        if(room_no>0)
                        {


                           -h[i];
                            cout<<"\nCustomer Record Deleted";
                            logFile<<"Customer Data Deleted of room no " << room_no <<endl;
                            logFile.close();

                        }
                        else
                        {
                            cout<<"\nNo customer there!!";
                        }
                        getch();
                        system("cls");
            break;
            case 5:
                    cout << "\nThank you!";
                    exit(0);
                    break;
            default:
                    cout << "\n\t*********INVALID**********";
                    break;
            }
        }
}
