#include<iostream>
#include<string>
#include<fstream>
using namespace std;


void encryptdecrpyt(string &data){
    const char key='k';
    for (int i = 0; i < data.length(); i++){
        data[i]=data[i]^key;
    }
}

void addpass(){
    string site,user,pass;
    ofstream file("vault.txt");
    if (file.is_open()){
        cout<<"enter website name:";
        cin>>site;
        cout<<"enter username:";
        cin>>user;
        cout<<"enter password:";
        cin>>pass;
        encryptdecrpyt(user);
        encryptdecrpyt(pass);
        file<<site<<" "<<user<<" "<<pass;
    }
    file.close();
    cout<<"Saved";
}

void viewpass(){
    ifstream file("vault.txt");
    string site, user,pass;
    while (file>>site>>user>>pass)
    {
        cout<<"\nsite: "<<site<<endl;
        encryptdecrpyt(user);
        encryptdecrpyt(pass);
        cout<<"\nusername: "<<user<<endl;
        cout<<"\nPassword: "<<pass<<endl;
    }
    file.close();
}

void menu(){
    int choice;
    do{
    cout<<"\n1.Add Password \n2.View Passwords \n3.exit\n";
    cout<<"Enter choice";
    cin>>choice;
    switch (choice){
        case 1:
        addpass();
        break;

        case 2:
        viewpass();
        break;

        case 3:
        cout<<"Exiting the file";
        break;

    default:
    cout<<"invalid option";
        break;
}
    } while (choice !=3);
}


int main(){

    string pass="admin@123";
    string input;
    cout<<"enter master password:";
    cin>>input;
    if (input != pass){
        cout<<"Access denied";
        return 0;
    }
    cout<<"Login successfull"<<endl;
    menu();
 return 0;
}