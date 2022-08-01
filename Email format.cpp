#include <iostream>
#include <string>
using namespace std;
int main() {

    /*initialize variables*/
    string userinput;
    string username;
    string host;
    string domain;

    int index1 = 0, index2 = 0;
    int alcount = 0;
    int hostcount = 0;
    int domcount = 0;
    cout << "If there is no message of 'wrong format', then your input is correct " << endl;

    cout << "enter a correct format of an email: " << endl;
    getline(cin, userinput);

    for (int i = 0; i < userinput.length(); i++) {

        if (userinput.at(i) == '@') {
            username = userinput.substr(0, i);
            index1 = i;
        }

        if (userinput.at(i) == '.') {

            host = userinput.substr(index1 + 1, i - index1 - 1);
            index2 = i;
        }

        domain = userinput.substr(index2 + 1, userinput.length() - index2);
    }

    //limit conditions for the username
    for (int j = 0; j < username.length(); j++) {
        if (isalpha(username.at(j)) != 0) {
            alcount++;
        }
    }
    if (alcount < 2) {
        cout << "wrong format" << endl;
    }

    //limit conditions for the host
    for (int j = 0; j < host.length(); j++) {
        if (isalpha(host.at(j)) != 0) {
            hostcount++;
        }
    }
    if (hostcount < 2) {
        cout << "wrong format" << endl;
    }

    //limit conditions for the domain
    for (int j = 0; j < domain.length(); j++) {
        if (isalpha(domain.at(j)) != 0) {
            domcount++;
        }
    }
    if (domcount < 2 || domcount >4) {
        cout << "wrong format" << endl;
    }



    // show every component


    cout << "-------------------------------" << endl;
    cout << "username: " << username << endl;
    cout << "host: " << host << endl;
    cout << "domain: " << domain << endl;



    return 0;

}

/*
If there is no message of 'wrong format', then your input is correct
enter a correct format of an email:
123a@qq.ca
wrong format
-------------------------------
username: 123a
host: qq
domain: ca


If there is no message of 'wrong format', then your input is correct
enter a correct format of an email:
lguan13@myseneca.ca
-------------------------------
username: lguan13
host: myseneca
domain: ca



*/