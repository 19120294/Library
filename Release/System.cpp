#include "System.h"
int ticket_num;
int user_cnt;
int reader_cnt;
int book_cnt;
int book_count_name;
int ticket_book_cnt;
int x;

void flush_user(istream& indev, user a[])
{
    user_cnt = 0;
    int i = 0;
    while (indev.getline(a[i].username, 30))
    {
        indev.getline(a[i].password, 30);
        indev.getline(a[i].name, 30);
        indev >> a[i].day;
        indev >> a[i].month;
        indev >> a[i].year;
        indev >> a[i].CID;
        indev.getline(a[i].address, 50);
        indev.getline(a[i].gender, 6);
        indev >> a[i].active;
        indev >> a[i].typee;
        i++;
        user_cnt++;
    }
}
void flush_reader(istream& indev, reader a[])
{
    reader_cnt = 0;
    int i = 0;
    while (indev >> a[i].code)
    {
        indev.getline(a[i].name, 30);
        indev >> a[i].CID;
        indev >> a[i].birth.day;
        indev >> a[i].birth.month;
        indev >> a[i].birth.year;
        indev.getline(a[i].gender, 6);
        indev.getline(a[i].email, 30);
        indev.getline(a[i].address, 50);
        indev >> a[i].created.day;
        indev >> a[i].created.month;
        indev >> a[i].created.year;
        indev >> a[i].expired.day;
        indev >> a[i].expired.month;
        indev >> a[i].expired.year;
        i++;
        reader_cnt++;
    }
}
void flush_book(istream& indev, book a[])
{
    book_cnt = 0;
    book_count_name = 0;
    int i = 0;
    while (indev.getline(a[i].booktitle, 30))
    {
        indev >> a[i].ISBN;
        
        indev.getline(a[i].author, 50);
        indev.getline(a[i].publisher, 50);
        indev >> a[i].PYear;
        indev >> a[i].cnt_genre;
        int m;
        for (m = 0; m < a[i].cnt_genre; m++)
        {
            indev.getline(a[i].genre[m], 20);
        }
        indev >> a[i].cost;
        indev >> a[i].cnt;
        //cout << a[i].cnt;
        i++;
        book_count_name++;
        book_cnt = book_cnt + a[i].cnt;
    }
}
void flush_ticket(istream& indev, ticket a[])
{
    ticket_book_cnt = 0;
    ticket_num = 0;
    int i = 0;
    while (indev >> a[i].code)
    {
        indev >> a[i].rent.day;
        indev >> a[i].rent.month;
        indev >> a[i].rent.year;
        indev >> a[i].return_.day;
        indev >> a[i].return_.month;
        indev >> a[i].return_.year;
        indev >> a[i].return_r.day;
        indev >> a[i].return_r.month;
        indev >> a[i].return_r.year;
        indev >> a[i].cnt;
        a[i].ISBN = new int[a[i].cnt];
        for (int j = 0; j < a[i].cnt; j++)
        {
            indev >> a[i].ISBN[j];
        }
        indev >> a[i].type;
        i++;
        ticket_book_cnt=ticket_book_cnt+a[i].cnt;
        ticket_num++;
    }
}
int login(char id[], char pass[], user a[])
{
    for (int i = 0; i < user_cnt; i++)
    {
        if (!strcmp(id, a[i].username)) {
            if (!strcmp(pass, a[i].password))
            {
                cout << "success" << endl;
                return i;
            }
            else
            {
                cout << "wrongpass";
                return -1;
            }
        }
    }
    cout << "not found" << endl;
    return -1;
}
void logout()
{
    system("cls");
}

void flush_user_in(ostream& indev, user a[])
{
    int i = 0;
    while (i < user_cnt)
    {
        indev << a[i].username;
        indev << a[i].password;
        indev << a[i].name;
        indev << a[i].day;
        indev << a[i].month;
        indev << a[i].year;
        indev << a[i].CID;
        indev << a[i].address;
        indev << a[i].gender;
        indev << a[i].active;
        indev << a[i].typee;
        i++;
    }
}

void flush_reader_in(ostream& indev, reader a[])
{
    int i = 0;
    while (i < reader_cnt)
    {
        indev << a[i].code;
        indev << a[i].name;
        indev << a[i].CID;
        indev << a[i].birth.day;
        indev << a[i].birth.month;
        indev << a[i].birth.year;
        indev << a[i].gender;
        indev << a[i].email;
        indev << a[i].address;
        indev << a[i].created.day;
        indev << a[i].created.month;
        indev << a[i].created.year;
        indev << a[i].expired.day;
        indev << a[i].expired.month;
        indev << a[i].expired.year;
        i++;

    }
}
void flush_book_in(ostream& indev, book a[])
{
    int i = 0;
    int cnt = 0;
    while (cnt <= book_cnt)
    {
        
        indev << a[i].ISBN;
        indev << a[i].booktitle;
        indev << a[i].author;
        indev << a[i].publisher;
        indev << a[i].PYear;
        indev << a[i].cnt_genre;
        int m = 0;
        for (m = 0; m < a[i].cnt_genre; m++)
        {
            indev << a[i].genre[m];
        }
        indev << a[i].cost;
        indev << a[i].cnt;
        cnt = cnt + a[i].cnt;
        i++;
    }
}
void flush_ticket_in(ostream& indev, ticket a[])
{
    int i = 0;
    int cnt = 0;
    while (cnt < ticket_book_cnt)
    {
        indev << a[i].code;
        indev << a[i].rent.day;
        indev << a[i].rent.month;
        indev << a[i].rent.year;
        indev << a[i].return_.day;
        indev << a[i].return_.month;
        indev << a[i].return_.year;
        indev << a[i].return_r.day;
        indev << a[i].return_r.month;
        indev << a[i].return_r.year;
        
        indev << a[i].cnt;
        for (int m = 0; m < a[i].cnt; m++)
        {
            indev << a[i].ISBN[m];
        }
        indev << a[i].type;
        cnt = cnt + a[i].cnt;
        i++;

    }
}
int searchh(user a[])
{
    char temp[30];
    cout << "nhap ten dang nhap muon tim: ";
    cin.ignore();
    cin.getline(temp, 30);
    for (int i = 0; i < user_cnt; i++)
    {
        if (!strcmp(a[i].username, temp))
            cout << a[i].name;
        return i;
    }
    cout << "not found";
    return -1;
}
void changepass(user a[], int pos)
{	
    char pass[30];
    cout << "nhap mk moi: ";
    cin.getline(pass, 30);
    strcpy(a[pos].password, pass);
    
}
void create(user a[])
{	
    cin.getline(a[user_cnt].username, 30);
    cin.getline(a[user_cnt].password, 30);
    cin.getline(a[user_cnt].name, 30);
    cin >> a[user_cnt].day;
    cin >> a[user_cnt].month;
    cin >> a[user_cnt].year;
    cin >> a[user_cnt].CID;
    cin.getline(a[user_cnt].address, 50);
    cin.getline(a[user_cnt].gender, 6);
    cin >> a[user_cnt].active;
    cin >> a[user_cnt].typee;

    user_cnt++;
}
void editinfo(user a[], int pos)
{   
    cout << "new name: ";
    cin.getline(a[pos].name, 30);
    cout << "new birthday: ";
    cin >> a[pos].day >> a[pos].month >> a[pos].year;
    cout << "new CID: ";
    cin >> a[pos].CID;
    cout << "new address: ";
    cin.getline(a[pos].address, 50);
    cout << "new gender: ";
    cin.getline(a[pos].gender, 6);

}

void type_set(user a[], int pos)
{
    cout << "phan quyen cho tai khoan: " << a[pos].name;
    cout << "1. doc gia" << endl << "2. nhan vien" << endl << "3. quan ly" << endl;
    cin >> a[pos].typee;
}
//2
void SeeListReader(reader a[])
{
    int i = 1;
    cout << "Danh sach doc gia trong thu vien: " << endl;
    cout << "Ma doc gia" << "\t\t" << "Ten " << endl;
    while (a->CID)
    {
        cout << i << " " << a->code << "\t\t" << a->name << endl;
    }
}
void addreader(reader a[])
{
    cout << "Nhap thong tin doc gia can them" << endl;
    cout << "Code: " << endl;
    cin >> a[reader_cnt].code;
    cout << "Name: " << endl;
    cin.getline(a[reader_cnt].name, 30);
    cin.ignore();
    cout << "CID:" << endl;
    cin >> a[reader_cnt].CID;
    cout << "Birth(dd/mm/yyyy):" << endl;
    cin >> a[reader_cnt].birth.day >> a[reader_cnt].birth.month >> a[reader_cnt].birth.year;
    cout << "Gender" << endl;
    cin.getline(a[reader_cnt].gender, 6);
    cin.ignore();
    cout << "Email" << endl;
    cin.getline(a[reader_cnt].email, 30);
    cin.ignore();
    cout << "Address" << endl;
    cin.getline(a[reader_cnt].address, 50);
    cin.ignore();
    cout << "Date created" << endl;
    cin >> a[reader_cnt].created.day >> a[reader_cnt].created.month >> a[reader_cnt].created.year;
    cout << "Date expired" << endl;
    cin >> a[reader_cnt].expired.day >> a[reader_cnt].expired.month >> a[reader_cnt].expired.year;
    reader_cnt++;
}
void EditInforReader(reader a[], int pos)
{
    int choice;
    while (1)
    {
        cout << "Nhap thong tin can chinh sua" << endl;
        cout << "0.Thoat khoi trinh chinh sua" << endl;
        cout << "1.Code" << endl;
        cout << "2.Name" << endl;
        cout << "3.CID" << endl;
        cout << "4.Birth" << endl;
        cout << "5.Gender" << endl;
        cout << "6.Email" << endl;
        cout << "7.Address" << endl;
        cout << "8.Date Created" << endl;
        cout << "9.Date expired" << endl;
        cin >> choice;
        if (choice == 0)
        {
            return;
        }
        if (choice == 1)
        {
            cout << "Code: " << endl;
            cin >> a[pos].code;
        }
        if (choice == 2)
        {
            cout << "Name: " << endl;
            cin.getline(a[pos].name, 30);
            cin.ignore();
        }
        if (choice == 3)
        {
            cout << "CID:" << endl;
            cin >> a[pos].CID;
        }
        if (choice == 4)
        {
            cout << "Birth(dd/mm/yyyy):" << endl;
            cin >> a[pos].birth.day >> a[pos].birth.month >> a[pos].birth.year;
        }
        if (choice == 5)
        {
            cout << "Gender" << endl;
            cin.getline(a[pos].gender, 6);
            cin.ignore();
        }
        if (choice == 6)
        {
            cout << "Email" << endl;
            cin.getline(a[pos].email, 30);
            cin.ignore();
        }
        if (choice == 7)
        {
            cout << "Address" << endl;
            cin.getline(a[pos].address, 50);
            cin.ignore();
        }
        if (choice == 8)
        {
            cout << "Date created" << endl;
            cin >> a[pos].created.day >> a[pos].created.month >> a[pos].created.year;
        }
        if (choice == 9)
        {
            cout << "Date expired" << endl;
            cin >> a[pos].expired.day >> a[pos].expired.month >> a[pos].expired.year;
        }
        system("pause");
    }
}
void DeleteInforReader(reader a[], int pos)
{
    cout << "Ban co chac muon xoa thong tin doc gia nay?" << endl;
    cout << "1.Co     2.Khong"<<endl;
    int check;
    cin >> check;
    if (check == 2) return;
                               
                for (int i = pos; i < reader_cnt - 1; i++) {
                    a[pos].code = a[pos+1].code;
                    a[pos].birth.day = a[pos+1].birth.day;
                    a[pos].birth.month = a[pos+1].birth.month;
                    a[pos].birth.year = a[pos+1].birth.year;
                    strcat(a[pos+1].gender , a[pos].gender);
                    strcat(a[pos+1].email , a[pos].email);
                    strcat(a[pos+1].address , a[pos].address);
                    a[pos].created.day = a[pos+1].created.day;
                    a[pos].created.month = a[pos+1].created.month;
                    a[pos].created.year = a[pos+1].created.year;
                    a[pos].expired.day = a[pos+1].expired.day;
                    a[pos].expired.month = a[pos+1].expired.month;
                    a[pos].expired.year = a[pos+1].expired.year;
                }
                
                --reader_cnt;
            
    
}
int SearchReaderByCID(reader a[], int S_CID)
{
    for (int i = 0; i < reader_cnt; i++)
    {
        if (a[i].CID == S_CID)
        {
            cout << "Doc gia can tim la:" << endl;
            cout << "Ma doc gia: " << a[i].code << endl;
            cout << "Ten doc gia: " << a[i].name << endl;
            cout << "CMND: " << a[i].CID << endl;
            cout << "Ngay/thang/nam sinh: " << a[i].birth.day << " " << a[i].birth.month << " " << a[i].birth.year << endl;
            cout << "Gioi tinh: " << a[i].gender << endl;
            cout << "Email: " << a[i].email << endl;
            cout << "Address: " << a[i].address << endl;
            cout << "Ngay lap the: " << a[i].created.day << " " << a[i].created.month << " " << a[i].created.year << endl;
            cout << "Ngay het han the: " << a[i].expired.day << " " << a[i].expired.month << " " << a[i].expired.year << endl;
            return i;
        }
    }
	cout<<"Not found!";
    return -1;
}
int SearchReaderByName(reader a[], char S_name[])
{
    for (int i = 0; i < reader_cnt; i++)
    {
        if (strcmp(a[i].name, S_name) == 0)
        {
            cout << "Doc gia can tim la:" << endl;
            cout << "Ma doc gia: " << a[i].code << endl;
            cout << "Ten doc gia: " << a[i].name << endl;
            cout << "CMND: " << a[i].CID << endl;
            cout << "Ngay/thang/nam sinh: " << a[i].birth.day << " " << a[i].birth.month << " " << a[i].birth.year << endl;
            cout << "Gioi tinh: " << a[i].gender << endl;
            cout << "Email: " << a[i].email << endl;
            cout << "Address: " << a[i].address << endl;
            cout << "Ngay lap the: " << a[i].created.day << " " << a[i].created.month << " " << a[i].created.year << endl;
            cout << "Ngay het han the: " << a[i].expired.day << " " << a[i].expired.month << " " << a[i].expired.year << endl;
	return i;        
}
cout<<"not found!";
return -1;
    }
}
//3

void outputbook(book a)
{
    cout << "Ma ISBN: " << a.ISBN << endl;
    cout << "Ten sach: " << a.booktitle << endl;
    cout << "Tac gia: " << a.author << endl;
    cout << "Nha xuat ban: " << a.publisher << endl;
    cout << "Nam xuat ban: " << a.PYear << endl;
    for (int i = 0; i < a.cnt_genre; i++)
    {
        cout << "The loai sach: " << a.genre[i] << " ";
    }
    cout << endl;
    cout << "Gia sach: " << a.cost << endl;
    cout << "So luong sach " << a.cnt << endl;
}
void SeeListBook(book a[])
{
    cout << "DANH SACH CAC SACH TRONG THU VIEN" << endl;
    for (int i = 0; i < book_count_name; i++)
    {
        cout << i + 1 << endl;
        outputbook(a[i]);
    }
}
void addbook(book a[])
{
    cout << "Ma ISBN " << endl;
    cin >> a[book_cnt].ISBN;
    cout << "Ten sach: " << endl;
    cin >> a[book_cnt].booktitle;
    cout << "Tac gia: " << endl;
    cin >> a[book_cnt].author;
    cout << "Nha xuat ban: " << endl;
    cin >> a[book_cnt].publisher;
    cout << "Nam xuat ban: " << endl;
    cin >> a[book_cnt].PYear;
    cout << "So luong the loai cua sach" << endl;
    cin >> a[book_cnt].cnt_genre;
    cout << "Nhap tung the loai cua sach" << endl;
    for (int i = 0; i < a[book_cnt].cnt_genre; i++)
    {
        cin.getline(a[book_cnt].genre[i], 20);
        cin.ignore();
    }
    cout << endl;
    cout << "Gia sach: " << endl;
    cin >> a[book_cnt].cost;
    cout << "So luong sach " << endl;
    cin >> a[book_cnt].cnt;
    cout << endl;
    book_cnt++;
}
void EditInforBook(book a[], int pos)
{
    outputbook(a[pos]);
    int choice;
    while (1)
    {
        cout << "Nhap thong tin can chinh sua" << endl;
        cout << "0.Thoat khoi trinh chinh sua" << endl;
        cout << "1.ISBN" << endl;
        cout << "2.Ten sach" << endl;
        cout << "3.Tac gia" << endl;
        cout << "4.Nha xuat ban" << endl;
        cout << "5.Nam xuat ban" << endl;
        cout << "6.So luong the loai sach" << endl;
        cout << "7.The loai sach" << endl;
        cout << "8.Gia sach" << endl;
        cout << "9.So luong sach" << endl;
        cin >> choice;
        if (choice == 0)
        {
            return;
        }
        if (choice == 1)
        {
            cout << "ISBN: " << endl;
            cin >> a[pos].ISBN;
        }
        if (choice == 2)
        {
            cout << "Ten sach " << endl;
            cin.getline(a[pos].booktitle, 30);
            cin.ignore();
        }
        if (choice == 3)
        {
            cout << "Tac gia: " << endl;
            cin.getline(a[pos].author, 30);
            cin.ignore();
        }
        if (choice == 4)
        {
            cout << "Nha xuat ban" << endl;
            cin.getline(a[pos].publisher, 30);
            cin.ignore();
        }
        if (choice == 5)
        {
            cout << "Nam xuat ban" << endl;
            cin >> a[pos].PYear;
        }
        if (choice == 6)
        {
            cout << "So luong the loai sach" << endl;
            cin >> a[pos].cnt_genre;
        }
        if (choice == 7)
        {
            for (int i = 0; i < a[pos].cnt_genre; i++)
            {
                cin.getline(a[pos].genre[i], 20);
                cin.ignore();
            }
        }
        if (choice == 8)
        {
            cout << "Gia sach" << endl;
            cin >> a[pos].cost;
        }
        if (choice == 9)
        {
            cout << "So luong sach" << endl;
            cin >> a[pos].cnt;
        }
        system("pause");
    }
}
void DeleteInforBook(book a[], int pos)
{
    cout << "Ban co chac muon xoa thong tin quyen sach nay?" << endl;
    cout << "1.Co     2.Khong" << endl;
    int check;
    cin >> check;
    if (check == 2) return;

    for (int i = pos; i < book_count_name - 1; i++) {
        a[pos].ISBN = a[pos + 1].ISBN;
        strcat( a[pos].booktitle,a[pos].booktitle);
        strcat(a[pos+1].author ,a[pos].author);
        strcat(a[pos+1].publisher , a[pos].publisher);
        a[pos].publisher == a[pos + 1].publisher;
        a[pos].cnt_genre == a[pos + 1].cnt_genre;
        a[pos].cost == a[pos + 1].cost;
        a[pos].cnt = a[pos + 1].cnt;
        for (int j = 0; j < a[pos].cnt_genre; j++)
        {
            strcat(a[pos + 1].genre[j], a[pos].genre[j]);
        }
        
    }

    --book_count_name;
}
int SearchBookByISBN(book a[], int S_ISBN)
{
    for (int i = 0; i < book_cnt; i++)
    {
        if (a[i].ISBN == S_ISBN)
        {
            cout << "Sach can tim la: " << endl;
            outputbook(a[i]);
            return i;
        }
    }
    cout << "not found" << endl;
    return -1;
}
int SearchBookByName(book a[], char S_namebook[])
{
    for (int i = 0; i < book_cnt; i++)
    {
        if (strcmp(a[i].booktitle, S_namebook) == 0)
        {
            outputbook(a[i]);
            return i;
        }
    }
    cout << "not found";
    return -1;
}
//4

void AddTicket_take(ticket a[])
{
    cout << "Ma doc gia: ";
    cin >> a[ticket_num].code;
    cout << "Nhap ngay muon(Ngay thang nam): ";
    cin >> a[ticket_num].rent.day >> a[ticket_num].rent.month >> a[ticket_num].rent.year;
    a[ticket_num].type = 0;
    cout << "Nhap ngay tra du kien(Ngay thang nam): ";
    cin >> a[ticket_num].return_.day >> a[ticket_num].return_.month >> a[ticket_num].return_.year;
    a[ticket_num].return_r.day = 0;
    a[ticket_num].return_r.month = 0;
    a[ticket_num].return_r.year = 0;
    cout << "nhap so sach muon muon: ";
    cin >> a[ticket_num].cnt;
    for (int i = 0; i < a[ticket_num].cnt; i++)
    {
        cin >> a[ticket_num].ISBN[i];
    }
    a[ticket_num].type = 0;
    ticket_num++;
}
void AddTicket_r(ticket a[])
{
    int S_code,pos;
    cout << "Ma doc gia: ";
    cin >> S_code;

    for (int i = 0; i < ticket_num; i++)
    {
        if (a[i].code == S_code)
            pos = i;
    }
    cout << "Nhap ngay tra thuc te(Ngay thang nam): ";
    cin >> a[pos].return_r.day >> a[pos].return_r.month >> a[pos].return_r.year;
    if(a[pos].return_r.year<=a[pos].return_.year)
        if(a[pos].return_r.month<=a[pos].return_.month)
            if (a[pos].return_r.day <= a[pos].return_.day)
            {
                return;
            }
    a[pos].type = 1;
    return;

}
void out_ui(string a)
{
    string x;
    ifstream f(a);
    while (getline(f, x))
    {
        cout << x << endl;
    }
}
void flush_out(user a[], reader b[], book c[], ticket d[])
{
    ifstream fiu("userdata.bin");
    
    flush_user(fiu, a);
    fiu.close();
    ifstream fir("readerdata.bin");
    flush_reader(fir, b);
    fir.close();
    ifstream fib("books.bin");
    flush_book(fib, c);
    fib.close();
    ifstream fit("tickets.bin");
    flush_ticket(fit, d);
    fit.close();
}
void flush_in(user a[], reader b[], book c[], ticket d[])
{
    ofstream fiu("userdata.bin");

    flush_user_in(fiu, a);
    fiu.close();
    ofstream fir("readerdata.bin");
    flush_reader_in(fir, b);
    fir.close();
    ofstream fib("books.bin");
    flush_book_in(fib, c);
    fib.close();
    ofstream fit("tickets.bin");
    flush_ticket_in(fit, d);
    fit.close();
}
void func_Admin(user a[], reader b[], book c[], ticket d[])
{
    int choice;
    
    while (1)
    {
        system("cls");
        out_ui("Admin.bin");
        cout << "Chon chuc nang:  ";
        cin >> choice;
        system("cls");
        switch (choice)
        {
            int pos;
            case 1: {
                pos = searchh(a);
                changepass(a, pos);
                cout << endl;
                system("pause");
                break;
            }
            case 2: {
                pos = searchh(a);
                editinfo(a, pos); 
                cout << endl;
                system("pause");
                break;
            }
            case 3: {
                create(a); break;
            }
            case 4: {pos = searchh(a);
                type_set(a, pos);
                cout << endl;
                system("pause");
                break;
            }
            case 5: {
                SeeListReader(b);
                cout << endl;
                system("pause");
                break;
            }
            case 6: {
                addreader(b);
                cout << endl;
                system("pause");
                break;
            }
            case 7: {int S_CID;
                cout << "nhap cmnd cua doc gia can tim: ";
                cin >> S_CID;
                SearchReaderByCID(b, S_CID); 
                cout << endl;
                system("pause");
                break;
            }
            case 8: {char S_name[100];
                cout << "nhap ten doc gia can tim: ";
                SearchReaderByName(b, S_name);
                cout << endl;
                system("pause");
                break;
            }
            case 9: {
                char S_name[100];
                cout << "nhap ten doc gia can chinh sua: ";
                cin.getline(S_name, 100);
                int pos=SearchReaderByName(b, S_name);
                EditInforReader(b, pos);
                cout << endl;
                system("pause");
                break;
            }
            case 10: {
                char S_name[100];
                cout << "nhap ten doc gia can tim: ";
                cin.getline(S_name, 100);
                pos=SearchReaderByName(b, S_name);
                DeleteInforReader(b, pos);
                cout << endl;
                system("pause");
                break;
            }
            case 11: {
                SeeListBook(c);
                cout << endl;
                system("pause");
                break;
            }
            case 12: {
                addbook(c);
                cout << endl;
                system("pause");
                break;
            }
            case 13: {
                int S_ISBN;
                cout << "nhap ISBN cuon sach can tim: ";
                cin >> S_ISBN;
                SearchBookByISBN(c, S_ISBN);
                cout << endl;
                system("pause");
                break;
            }
            case 14: {
                char S_namebook[100];
                cout << "nhap ten sach can tim: ";
                cin.getline(S_namebook, 100);
                SearchBookByName(c, S_namebook);
                cout << endl;
                system("pause");
                break;

            }
            case 15: {
                char S_namebook[100];
                cout << "nhap ten sach can chinh sua: ";
                cin.getline(S_namebook, 100);
                pos= SearchBookByName(c, S_namebook);
                EditInforBook(c, pos);
                cout << endl;
                system("pause");
                break;
            }
            case 16: {
                char S_namebook[100];
                cout << "nhap ten sach can xoa: ";
                cin.getline(S_namebook, 100);
                pos = SearchBookByName(c, S_namebook);
                DeleteInforBook(c, pos);
                cout << endl;
                system("pause");
                break;
            }
            case 17: {
                AddTicket_take(d);
                cout << endl;
                system("pause");
                break;
            }
            case 18: {
                AddTicket_r(d);
                cout << endl;
                system("pause");
                break;
            }
            case 19: {
                cout << "So sach trong thu vien: " << book_cnt;
                cout << endl;
                system("pause");
                break;
            }
            case 20:
            {
                cout << "So luong doc gia: " << reader_cnt;
                cout << endl;
                system("pause");
                break;
            }
            case 21:
            {   int m = 0;
                int fm = 0;
                for (int i = 0; i < reader_cnt; i++)
                {
                    if (!strcmp(b[i].gender, "male")) m++;
                    else fm++;
                }
                cout << "So doc gia nam: " << m << endl;
                cout << "So doc gia nu: " << fm << endl;
                cout << endl;
                system("pause");
                break;
            }
            case 22:
            {
                cout << "so sach dang duoc muon: " << ticket_book_cnt << endl;
                cout << endl;
                system("pause");
                break;
            }
            case 23:
            {   cout << "Danh sach doc gia bi tre han";
                for (int i = 0; i < ticket_num; i++)
                {
                    if (d[i].type == 1)
                    {
                        cout << d[i].code<<endl;
                    }
                }
                cout << endl;
                system("pause");
                break;
                
            }
            case 24:
            {
                flush_in(a, b, c, d);
                cout << endl;
                system("pause");
                break;

            }
            case 0:
            {
                int choice;
                cout << "ban co muon luu du lieu?" << endl;
                cout << "1. Co      2. Khong";
                cin >> choice;
                if (choice == 1) {
                    flush_in(a, b, c, d); cout << "Da luu du lieu thanh cong" << endl;
                    system("pause");
                    return;
                }
                else return;
            }
        }
    }
}
void func_Manager(user a[], reader b[], book c[], ticket d[])
{
    int choice;

    while (1)
    {
        system("cls");
        out_ui("Manager.bin");
        cout << "Chon chuc nang:  ";
        cin >> choice;
        system("cls");
        switch (choice)
        {
            int pos;
        case 1: {
            pos = searchh(a);
            changepass(a, pos);
            cout << endl;
            system("pause");
            break;
        }
        case 2: {
            pos = searchh(a);
            editinfo(a, pos);
            cout << endl;
            system("pause");
            break;
        }
        
        case 3: {
            SeeListReader(b);
            cout << endl;
            system("pause");
            break;
        }
        case 4: {
            addreader(b);
            cout << endl;
            system("pause");
            break;
        }
        case 5: {int S_CID;
            cout << "nhap cmnd cua doc gia can tim: ";
            cin >> S_CID;
            SearchReaderByCID(b, S_CID);
            cout << endl;
            system("pause");
            break;
        }
        case 6: {char S_name[100];
            cout << "nhap ten doc gia can tim: ";
            SearchReaderByName(b, S_name);
            cout << endl;
            system("pause");
            break;
        }
        case 7: {
            char S_name[100];
            cout << "nhap ten doc gia can chinh sua: ";
            cin.getline(S_name, 100);
            int pos = SearchReaderByName(b, S_name);
            EditInforReader(b, pos);
            cout << endl;
            system("pause");
            break;
        }
        case 8: {
            char S_name[100];
            cout << "nhap ten doc gia can tim: ";
            cin.getline(S_name, 100);
            pos = SearchReaderByName(b, S_name);
            DeleteInforReader(b, pos);
            cout << endl;
            system("pause");
            break;
        }
        case 9: {
            SeeListBook(c);
            cout << endl;
            system("pause");
            break;
        }
        case 10: {
            addbook(c);
            cout << endl;
            system("pause");
            break;
        }
        case 11: {
            int S_ISBN;
            cout << "nhap ISBN cuon sach can tim: ";
            cin >> S_ISBN;
            SearchBookByISBN(c, S_ISBN);
            cout << endl;
            system("pause");
            break;
        }
        case 12: {
            char S_namebook[100];
            cout << "nhap ten sach can tim: ";
            cin.getline(S_namebook, 100);
            SearchBookByName(c, S_namebook);
            cout << endl;
            system("pause");
            break;

        }
        case 13: {
            char S_namebook[100];
            cout << "nhap ten sach can chinh sua: ";
            cin.getline(S_namebook, 100);
            pos = SearchBookByName(c, S_namebook);
            EditInforBook(c, pos);
            cout << endl;
            system("pause");
            break;
        }
        case 14: {
            char S_namebook[100];
            cout << "nhap ten sach can xoa: ";
            cin.getline(S_namebook, 100);
            pos = SearchBookByName(c, S_namebook);
            DeleteInforBook(c, pos);
            cout << endl;
            system("pause");
            break;
        }
        case 15: {
            AddTicket_take(d);
            cout << endl;
            system("pause");
            break;
        }
        case 16: {
            AddTicket_r(d);
            cout << endl;
            system("pause");
            break;
        }
        case 17: {
            cout << "So sach trong thu vien: " << book_cnt;
            cout << endl;
            system("pause");
            break;
        }
        case 18:
        {
            cout << "So luong doc gia: " << reader_cnt;
            cout << endl;
            system("pause");
            break;
        }
        case 19:
        {   int m = 0;
        int fm = 0;
        for (int i = 0; i < reader_cnt; i++)
        {
            if (!strcmp(b[i].gender, "male")) m++;
            else fm++;
        }
        cout << "So doc gia nam: " << m << endl;
        cout << "So doc gia nu: " << fm << endl;
        cout << endl;
        system("pause");
        break;
        }
        case 20:
        {
            cout << "so sach dang duoc muon: " << ticket_book_cnt << endl;
            cout << endl;
            system("pause");
            break;
        }
        case 21:
        {   cout << "Danh sach doc gia bi tre han";
        for (int i = 0; i < ticket_num; i++)
        {
            if (d[i].type == 1)
            {
                cout << d[i].code << endl;
            }
        }
        cout << endl;
        system("pause");
        break;

        }
        case 22:
        {
            flush_in(a, b, c, d);
            cout << "Da luu du lieu thanh cong."<<endl;
            system("pause");
            break;

        }
        case 0:
        {
            int choice;
            cout << "ban co muon luu du lieu?"<<endl;
            cout << "1. Co      2. Khong";
            cin >> choice;
            if (choice == 1) {
                flush_in(a, b, c, d); cout << "Da luu du lieu thanh cong"<<endl;
                system("pause");
                return;
            }
            else return;
        }
        }
    }
}
void func_Staff(user a[], reader b[], book c[], ticket d[])
{
    int choice;

    while (1)
    {
        system("cls");
        out_ui("Staff.bin");
        cout << "Chon chuc nang:  ";
        cin >> choice;
        system("cls");
        switch (choice)
        {
            int pos;
        case 1: {
            pos = searchh(a);
            changepass(a, pos);
            cout << endl;
            system("pause");
            break;
        }
        case 2: {
            pos = searchh(a);
            editinfo(a, pos);
            cout << endl;
            system("pause");
            break;
        }

        case 3: {
            SeeListReader(b);
            cout << endl;
            system("pause");
            break;
        }
        case 4: {
            addreader(b);
            cout << endl;
            system("pause");
            break;
        }
        case 5: {int S_CID;
            cout << "nhap cmnd cua doc gia can tim: ";
            cin >> S_CID;
            SearchReaderByCID(b, S_CID);
            cout << endl;
            system("pause");
            break;
        }
        case 6: {char S_name[100];
            cout << "nhap ten doc gia can tim: ";
            SearchReaderByName(b, S_name);
            cout << endl;
            system("pause");
            break;
        }
        case 7: {
            char S_name[100];
            cout << "nhap ten doc gia can chinh sua: ";
            cin.getline(S_name, 100);
            int pos = SearchReaderByName(b, S_name);
            EditInforReader(b, pos);
            cout << endl;
            system("pause");
            break;
        }
        
        case 8: {
            int S_ISBN;
            cout << "nhap ISBN cuon sach can tim: ";
            cin >> S_ISBN;
            SearchBookByISBN(c, S_ISBN);
            cout << endl;
            system("pause");
            break;
        }
        case 9: {
            char S_namebook[100];
            cout << "nhap ten sach can tim: ";
            cin.getline(S_namebook, 100);
            SearchBookByName(c, S_namebook);
            cout << endl;
            system("pause");
            break;

        }
        
        case 10: {
            AddTicket_take(d);
            cout << endl;
            system("pause");
            break;
        }
        case 11: {
            AddTicket_r(d);
            cout << endl;
            system("pause");
            break;
        }
        
        case 12:
        {
            cout << "so sach dang duoc muon: " << ticket_book_cnt << endl;
            cout << endl;
            system("pause");
            break;
        }
        case 13:
        {   cout << "Danh sach doc gia bi tre han";
        for (int i = 0; i < ticket_num; i++)
        {
            if (d[i].type == 1)
            {
                cout << d[i].code << endl;
            }
        }
        cout << endl;
        system("pause");
        break;

        }
        case 14:
        {
            flush_in(a, b, c, d);
            cout << "Da luu du lieu thanh cong." << endl;
            system("pause");
            break;

        }
        case 0:
        {
            int choice;
            cout << "ban co muon luu du lieu?" << endl;
            cout << "1. Co      2. Khong";
            cin >> choice;
            if (choice == 1) {
                flush_in(a, b, c, d); cout << "Da luu du lieu thanh cong" << endl;
                system("pause");
                return;
            }
            else return;
        }
        }
    }
}