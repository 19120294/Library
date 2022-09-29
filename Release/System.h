#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include<string>
#include<string.h>
#include<stdlib.h>
#include <conio.h>
#include<windows.h>
using namespace std;

struct date {
    int day;
    int year;
    int month;
};

struct user {
    char username[30];
    char password[30];
    char name[30];
    int day;
    int month;
    int year;
    int CID;
    char address[50];
    char gender[6];
    bool active;
    int typee;

};
struct reader {
    int code;
    char name[30];
    int CID;
    date birth;
    char gender[6];
    char email[30];
    char address[50];
    date created;
    date expired;
};
struct book {
    char booktitle[100];
    double ISBN;
    
    char author[50];
    char publisher[50];
    int PYear;
    int cnt_genre;
    char genre[100][20];
    double cost;
    int cnt;
};
struct ticket {
    int code;
    date rent;
    date return_;
    date return_r;
    int cnt;
    int* ISBN;
    int type;
};

void flush_user(istream& , user []);
void flush_reader(istream& , reader []);
void flush_book(istream& , book []);
void flush_ticket(istream& , ticket []);
int login(char [], char [], user []);
void logout();
void flush_user_in(ostream& , user []);
void flush_reader_in(ostream& , reader []);
void flush_book_in(ostream& , book []);
void flush_ticket_in(ostream& , ticket []);


void changepass(user [], int);
void create(user []);
void editinfo(user [], int );
int searchh(user []);
void type_set(user [], int);
//2
void SeeListReader(reader []);
void addreader(reader []);
void EditInforReader(reader [], int );
void DeleteInforReader(reader[], int);
int SearchReaderByCID(reader [] , int);
int SearchReaderByName(reader [], char []);
//3

void outputbook(book );
void SeeListBook(book []);
void addbook(book [] );
void EditInforBook(book [], int );
void DeleteInforBook(book [], int );
int SearchBookByISBN(book [], int );
int SearchBookByName(book [], char []);
//4

void AddTicket(ticket []);

void out_ui(string);
void flush_out(user[], reader[], book[], ticket[]);
void func_Admin(user[], reader[], book[], ticket[]);
void func_Manager(user[], reader[], book[], ticket[]);
void func_Staff(user[], reader[], book[], ticket[]);










