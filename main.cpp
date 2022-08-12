#include <iostream>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

class Collection{
public:
    int book_id;
    char book_name;
    char author;
    char publisher;
    char genre;
    int year;
    int pages;

    Collection()
    {
        book_id=0;
    }

};
class Book:public Collection{
public:
    int book_id;
    char book_name[40];
    char author[25];
    char publisher[20];
    char genre[20];
    int year;
    int pages;
public:
    virtual void addbook()
    {

    }
    virtual void deletebook()
    {

    }
    virtual void sortbooks()
    {

    }
    virtual void sortauthor()
    {

    }
    inline void acceptbook()
    {
        cout<<"Enter book id: ";
        cin>>book_id;
        cin.ignore();
        cout<<"Enter book name: ";
        cin.getline(book_name,40);
        cout<<"Enter author name: ";
        cin.getline(author,25);
        cout<<"Enter publisher: ";
        cin.getline(publisher,20);
        cout<<"Enter book genre: ";
        cin.getline(genre,20);
        cout<<"Enter year of issue: ";
        cin>>year;
        cout<<"Enter number of pages: ";
        cin>>pages;

    }
};


class Operation:public Collection,public Book{
public:
    Book obj;
    void addbook()
    {
        obj.acceptbook();
        fstream wr;
        wr.open("./book_data.txt",ios::app);
        wr.write((char *)&obj,sizeof(obj));
        cout<<"*****************************************"<<endl;
        cout<<"Book Added Successfully"<<endl;
        cout<<"*****************************************"<<endl;
    }

    void deletebook()
    {
        fstream rd,wr;
        rd.open("./book_data.txt",ios::in);
        wr.open("./temp.txt",ios::app);
        char n[50];
        cout<<"Enter name of the Book :";
        cin>>n;
        rd.seekg(0,ios::end);
        int size = rd.tellg()/sizeof(obj);
        rd.seekg(0,ios::beg);
        int flag = 0;
        for(int i=1;i<=size;i++)
        {
            rd.read((char*)&obj,sizeof(obj));
            if(strcmp(n,obj.book_name)==0)
            {
                cout<<"Book Removed"<<endl;
            }
            else
            {
                wr.write((char *)&obj,sizeof(obj));
            }
        }
        rd.close();
        wr.close();
        remove("./book_data.txt");
        rename("./temp.txt","./book_data.txt");

    }

    void sortauthor() {
        cout << "What author are you looking for: ";
        char sa[25];
        cin >> sa[25];
        vector<char> vecAuthor;
        if (std::find(vecAuthor.begin(), vecAuthor.end(), sa[25]) != vecAuthor.end());
        else
            cout << "I don't have this author" << endl;;
    }


    void sortbooks()
    {
        int choice;
        Book *bbr;
        Operation t2;

            while(1)
        {
            cout<<"What would you want me to do ?"<<endl;
            cout<<"1. Show all books by the same author"<<endl;
            cout<<"2. Show all books of a given genre and publisher"<<endl;
            cout<<"3. Show the name of the publisher with the maximum quantity of the books"<<endl;
            cout<<"4. Show TOP-3 genres (popularity is determined by the number of books in the genre)"<<endl;
            cout<<"5. Exit"<<endl;

            cin>>choice;
            if(choice == 1)
            {

                bbr=&t2;
                bbr->sortauthor();
            }
            else
            {
                break;
            }
        }
    }
};
int main()
{
    int choice;
    Book *bb;
    Operation t1;

        cout<<"********************* Welcome To Book Collection Management System *********R.J*********"<<endl;
        while(1)
        {
            cout<<"What would you want me to do ?"<<endl;
            cout<<"1. Add Book"<<endl;
            cout<<"2. Remove Book"<<endl;
            cout<<"3. Sort Books"<<endl;
            cout<<"4. Exit"<<endl;
            cin>>choice;
            if(choice == 1)
            {

                bb=&t1;
                bb->addbook();
            }
            else if(choice == 2)
            {

                bb=&t1;
                bb->deletebook();

            }
            else if(choice == 3)
            {

                bb=&t1;
                bb->sortbooks();

            }
            else
            {
                break;
            }
        }
        cout<<"Thanks for visiting, I hope to see you in September"<<endl<<"Have a Nice Day !"<<endl;

    return 0;
}