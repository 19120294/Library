#include "System.h"
user a[100];
reader b[100];
book c[100];
ticket d[100];






int main()
{
  
    flush_out(a,b,c,d);
    //system("pause");
    char id[30];
    char pass[30];
    string k;
    cout << "Account:  ";
    cin.getline(id, 30);
    char chr = 0;
    int i = 0;
    cout << "PASS:  ";
    while (1) {
        chr = _getch();
        if (chr == 13) {
            break;
        }
        else if (chr == 8 ) {
            i = i > 0 ? i - 1 : i;
        }
        else {
            pass[i++] = chr;
            //cout << "*";
        }
    }
    cout << endl;
    pass[i] = '\0';
    cout << pass << endl;
    int x;
        x= login(id, pass, a);
    //1. Admin   2.Manager  3.Staff
   
        if (a[x].typee == 1) func_Admin(a, b, c, d);
        if (a[x].typee == 2) func_Manager(a, b, c, d);
        if (a[x].typee == 3) func_Staff(a, b, c, d);

        return 0;
    
    

  
}
