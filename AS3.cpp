#include<iostream> 
#include<string> 
#include<iomanip> 
#include<stdexcept> 
#include<cstdlib> 
using namespace std; 
class Publication 
{ 
protected: 
 string title; 
 float price; 
public: 
 Publication() : title(""), price(0.0) {} 
 Publication(string title, float price) : title(title), price(price) {} 
 void display() 
 { 
 cout << "Title: " << title << endl; 
 cout << "Price: " << price << endl; 
 } 
}; 
class Book : public Publication 
{ 
private: 
 int page_count; 
public: 
 Book() : page_count(0) {} 
 Book(string title, float price, int page_count) : Publication(title, price), 
page_count(page_count) {} 
 void display() 
 { 
 Publication::display(); 
 cout << "Page Count: " << page_count << endl; 
 } 
}; 
class Tape : public Publication 
{ 
private: 
 float play_time; 
public: 
 Tape() : play_time(0.0) {} 
 Tape(string title, float price, float play_time) : Publication(title, price), 
play_time(play_time) {} 
 void display() 
 { 
 Publication::display(); 
 cout << "Playing Time (minutes): " << play_time << endl; 
 } 
}; 
int main() 
{ 
 string title; 
 float price; 
 char choice,another; 
 string book_title, tape_title; 
 float book_price, tape_price; 
 int book_page_count; 
 float tape_play_time; 
 int record=0; 
 int book_rec=0; 
 int audio_rec=0; 
 int pub_rec=0; 
 do 
 { 
 try 
 { 
 
 cout<<"\n\t*-*-*Menu*-*-*\t\n"<<endl; 
 cout<<"1)Insert the publication record"<<endl; 
 cout<<"2)Insert the Book record."<<endl; 
 cout<<"3)Insert the Audio Cassette record."<<endl; 
 cout<<"4)Display the Data Recorded."<<endl; 
 cout<<"5)Exit"<<endl; 
 cout<<"Enter your choice: "; 
 cin>> choice; 
 if(choice == '1') 
 { 
 cout<<"\n\tPublications"<<endl; 
 cout<<"Enter the Title: "; 
 cin>>ws; 
 cin>>title; 
 cin.ignore(); 
 cout<<"Enter the Price: "; 
 cin>>price; 
 record++; 
 pub_rec++; 
 cout<<"Total number of records created -"<<record<<endl; 
 cout<<"Publications - "<<pub_rec<<endl; 
 
 } 
 else if(choice == '2') 
 { 
 cout << "\n\tBOOK" << endl; 
 cout << "Enter the title: "; 
 cin >> ws; 
 cin >> book_title; 
 cout << "Enter the price: "; 
 cin >> book_price; 
 cout << "Enter the page count: "; 
 cin >> book_page_count; 
 record++; 
 book_rec++; 
 cout<<"Total number of records created -"<<record<<endl; 
 cout<<"Books - "<<book_rec<<endl; 
 } 
 else if(choice == '3') 
 { 
 cout <<"\n\tAudio Cassette" << endl; 
 cout << "Enter the title: "; 
 cin >> ws; 
 cin >> tape_title; 
 cout << "Enter the price: "; 
 cin >> tape_price; 
 cout << "Enter the playing time (in minutes): "; 
 cin >> tape_play_time; 
 record++; 
 audio_rec++; 
 cout<<"Total number of records created -"<<record<<endl; 
 cout<<"Audio Cassette - "<<audio_rec<<endl; 
 } 
 
 else if(choice == '4') 
 { 
 cout<<"Total number of records created -"<<record<<endl; 
 cout<<"Publications - "<<pub_rec<<endl; 
 cout<<"Books - "<<book_rec<<endl; 
 cout<<"Audio Cassette - "<<audio_rec<<endl; 
 
 Publication publication(title, price); 
 cout<<"\n\tPublication Information"<<endl; 
 publication.display(); 
 
 Book book(book_title, book_price, book_page_count); 
 cout << "\n\tBook Information" << endl; 
 book.display(); 
 
 Tape tape(tape_title, tape_price, tape_play_time); 
 cout << "\n\tAudio Cassette Information" << endl; 
 tape.display(); 
 } 
 else if(choice =='5') 
 { 
 break; 
 } 
 else 
 { 
 continue; 
 } 
 } 
 catch (...) 
 { 
 cerr << "An exception occurred. Setting all data members to zero." << endl; 
 Book book("", 0.0, 0); 
 Tape tape("", 0.0, 0.0); 
 
 cout << "\nReset Information:" << endl; 
 cout << "\nBook Information:" << endl; 
 book.display(); 
 
 cout << "\nAudio Cassette Information:" << endl; 
 tape.display(); 
 } 
 cout<<"Do you want to enter more publication(y/n)?: "; 
 cin>>another; 
 
 } 
 while (another == 'y'|| another =='Y'); 
 return 0; 
}