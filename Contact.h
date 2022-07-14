#ifndef PROGRAM5_CONTACT_H
#define PROGRAM5_CONTACT_H
#include <string>
using namespace std;
class Contact {
public:
    Contact();
    Contact(int id, string name, string streetAddress, string city, string state, string zip, string phone);
    int GetID();
    Contact * GetNext();
    void SetID(int id);
    void SetNext(Contact * next);
    string GetName();
    string GetStreetAddress();
    string GetCity();
    string GetState();
    string GetZip();
    string GetPhone();
    Contact &operator=(Contact &assignemnt_operator);
    Contact(Contact &copy_contact);
    void FrontBackSplit(Contact* source, Contact** frontRef, Contact** backRef);
    int id;
    Contact* next;
private:

    string name;
    string streetAddress;
    string city;
    string state;
    string zip;
    string phone;
};


#endif //PROGRAM5_CONTACT_H
