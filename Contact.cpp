#include "Contact.h"
Contact::Contact(){
    this->next = nullptr;
}
Contact::Contact(int id, string name, string streetAddress, string city, string state,
                 string zip, string phone){
    this->id = id;
    this->name = name;
    this->streetAddress = streetAddress;
    this->city = city;
    this->state = state;
    this->zip = zip;
    this->phone = phone;
    this->next = nullptr;
}

int Contact:: GetID(){return id; }
void Contact::SetID(int id){
    this->id = id; }
Contact* Contact::GetNext(){
    return next; }
void Contact:: SetNext(Contact * next){ this->next = next; }
string Contact:: GetName(){ return name; }
string Contact::GetStreetAddress(){ return streetAddress;}
string Contact::GetCity(){ return city; }
string Contact::GetState(){ return state; }
string Contact::GetZip(){ return zip; }
string Contact::GetPhone(){ return phone; }


Contact& Contact::operator=(Contact &assignemnt_operator)
{
    this->name = assignemnt_operator.name;
    this-> streetAddress =assignemnt_operator.streetAddress;
    this-> city =assignemnt_operator.city;
    this->state =assignemnt_operator.state;
    this->zip =assignemnt_operator.zip;
    this->phone =assignemnt_operator.phone;
    return *this;
}
Contact::Contact(Contact &copy_contact)
{
    this->name=copy_contact.name;
    this-> streetAddress =copy_contact.streetAddress;
    this-> city = copy_contact.city;
    this->state =copy_contact.state;
    this->zip =copy_contact.zip;
    this->phone =copy_contact.phone;
}