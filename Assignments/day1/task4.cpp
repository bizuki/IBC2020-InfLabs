#include <iostream>
#include <string>
using namespace std;
struct user {
    string name;
    string password;
};

int main() {
    user Student = {"Andrey", "IloveGovnokod"};
    for (int i = 0; i < 3; i++) {
        cout << "Please input your name\n";
        string name;
        cin >> name;
        cout << "Please input your password\n";
        string password;
        cin >> password;
        if (Student.name == name && Student.password == password) {
            cout << "Access granted. Enjoy your free subscription for a month due a Coronavirus outbreak\n";
            return 0;
        }
        if (i == 2) {
            cout << "The number of attempts is exceeded and FBI is searching for you right now";
        } else {
            cout << "Try again\n";
        }
    }
}