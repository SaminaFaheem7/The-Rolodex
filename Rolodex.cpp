
#include <iostream>
#include <iomanip>
#include "Rolodex.h"
using namespace std;
Rolodex::Rolodex(){
    head = new Contact;
}
Rolodex::~Rolodex(){
    Contact * current = head;
    while(current != nullptr){
        Contact * next = current->GetNext();
        delete current;
        current = next;
    }
    head = nullptr;
}
int Rolodex:: LoadFromFile(string filename){
    ifstream filename1(filename);
    if(!filename1.is_open()){
        return -1;
    }
    string line;
    int id =1;
    Contact * current = head;
    // first line is header row
    getline(filename1, line);
    while(getline(filename1, line)){
        stringstream ss(line);
        string first_name, last_name, company_name, address;
        string city, county, state, zip, phone1, phone, email;
        getline(ss, first_name, ',');
        getline(ss, last_name, ',');
        getline(ss, company_name, ',');
        getline(ss, address, ',');
        getline(ss, city, ',');
        getline(ss, county, ',');
        getline(ss, state, ',');
        getline(ss, zip, ',');
        getline(ss, phone1, ',');
        getline(ss, phone, ',');
        getline(ss, email, ',');
        Contact * contact = new Contact(id,last_name + ", " + first_name,address,city,
                                        state,zip,phone);
        current->SetNext(contact);
        current = current->GetNext();
        id++;
    }
    filename1.close();
    return this->Length();
}
void Rolodex::AddContact(string name, string streetAddress, string city, string state, string zip, string phone){

    Contact * current = head->GetNext();
    Contact * previous = head;
    int maxID = 0;
    while(current != nullptr){
        if(current->GetID() > maxID){
            maxID = current->GetID();
        }
        previous = previous->GetNext();
        current = current->GetNext();
    }
    // instantiate new Contact
    previous->SetNext(new Contact(maxID + 1, name, streetAddress, city, state,
                                  zip, phone));
}

int Rolodex ::Length(){
    Contact * current = head->GetNext();
    int length = 0;
    while(current != nullptr){
        length++;
        current = current->GetNext();
    }
    return length;
}

void Rolodex:: DeleteContact(int id){
    Contact * current = head->GetNext();
    Contact* prev = head;
    while(current != nullptr){

        if(current->id== id)
        {
            prev->SetNext(current->GetNext());
            delete current;
            break;
        }
        current = current->GetNext();
        prev= prev->GetNext();
    }
}

int Rolodex::GetMaxID(){
    Contact * current = head->GetNext();
    int maxID = 0;
    while(current != nullptr){
        if(maxID < current->GetID()){
            maxID = current->GetID();
        }
        current = current->GetNext();
    }
    return maxID;
}

void Rolodex:: DuplicateContact(int id) {
    Contact *current = head->GetNext();
    while (current != nullptr) {
        if (id == current->GetID()) {
            Contact *newContact = current;
            this->AddContact(current->GetName(), current->GetStreetAddress(), current->GetCity(),
                             current->GetState(), current->GetZip(), current->GetPhone());
            break;
        }
        current = current->GetNext();

    }
}

Contact * Rolodex ::FindContactByID(int id){
    Contact * current = head->GetNext();
    while(current != nullptr){
        if(id == current->GetID()){
            return current;
        }
        current = current->GetNext();
    }
    return current;
}

bool Rolodex:: IDExists(int id){
    Contact * current = head->GetNext();
    while(current != nullptr){
        if(id == current->GetID()){
            return true;
        }
        current = current->GetNext();
    }
    return false;
}

void Rolodex:: UpdateContact(int id, string name, string streetAddress, string city,
                             string state, string zip, string phone) {

    Contact *updatee = FindContactByID(id);
    Contact updator(updatee->GetID(), name, streetAddress, city, state, zip,
                    phone);
    *updatee = updator;
}

void Rolodex:: SortBy(Field field) {
    MergeSort(&head, field);

}

void Rolodex:: MergeSort(Contact** headRef,Field field )
{
    Contact* head = *headRef;
    Contact* a;
    Contact* b;

    if ((head ==nullptr) || (head->next ==nullptr)) {
        return;
    }
    FrontBackSplit(head, &a, &b);
    MergeSort(&a, field);
    MergeSort(&b, field);
    if (field == ID) {
        *headRef = SortedMergeID(a, b);

    }
    else if (field == NAME){
        *headRef = SortedMergeName(a, b);
    }
    else if (field == CITY){
        *headRef = SortedMergeCity(a, b);
    }
    else if (field == STATE){
        *headRef = SortedMergeState(a, b);
    }
    else if (field == ZIP){
        *headRef = SortedMergeZip(a, b);
    }

}

Contact* Rolodex::SortedMergeName(Contact* a, Contact* b)
{
    Contact* result = nullptr;


    if (a ==nullptr)
        return (b);
    else if (b ==nullptr)
        return (a);


    if (a->GetName() <= b->GetName()) {
        result = a;
        result->SetNext(SortedMergeName(a->next, b));
    }
    else {
        result = b;
        result->SetNext(SortedMergeName(a, b->next));
    }
    return (result);
}

Contact* Rolodex:: SortedMergeID(Contact* a, Contact* b)
{
    Contact* result = nullptr;


    if (a ==nullptr)
        return (b);
    else if (b ==nullptr)
        return (a);


    if (a->GetID() <= b->GetID()) {
        result = a;
        result->SetNext(SortedMergeID(a->next, b));
    }
    else {
        result = b;
        result->SetNext(SortedMergeID(a, b->next));
    }
    return (result);
}
Contact* Rolodex:: SortedMergeCity(Contact* a, Contact* b)
{
    Contact* result = nullptr;


    if (a ==nullptr)
        return (b);
    else if (b ==nullptr)
        return (a);


    if (a->GetCity() <= b->GetCity()) {
        result = a;
        result->SetNext(SortedMergeCity(a->next, b));
    }
    else {
        result = b;
        result->SetNext(SortedMergeCity(a, b->next));
    }
    return (result);
}

Contact* Rolodex:: SortedMergeState(Contact* a, Contact* b)
{
    Contact* result = nullptr;


    if (a ==nullptr)
        return (b);
    else if (b ==nullptr)
        return (a);


    if (a->GetState() <= b->GetState()) {
        result = a;
        result->SetNext(SortedMergeState(a->next, b));
    }
    else {
        result = b;
        result->SetNext(SortedMergeState(a, b->next));
    }
    return (result);
}

Contact* Rolodex:: SortedMergeZip(Contact* a, Contact* b)
{
    Contact* result = nullptr;


    if (a ==nullptr)
        return (b);
    else if (b ==nullptr)
        return (a);


    if (a->GetZip() <= b->GetZip()) {
        result = a;
        result->SetNext(SortedMergeZip(a->next, b));
    }
    else {
        result = b;
        result->SetNext(SortedMergeZip(a, b->next));
    }
    return (result);
}

void Rolodex ::FrontBackSplit(Contact* source, Contact** frontRef, Contact** backRef)
{
    Contact* fast;
    Contact* slow;
    slow = source;
    fast = source->next;


    while (fast !=nullptr) {
        fast = fast->next;
        if (fast !=nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
    }


    *frontRef = source;
    *backRef = slow->next;
    slow->next =nullptr;
}

void Rolodex:: PrintContact(Contact * contact){
    if(contact == nullptr) {
        cout << "NullPtr" << endl;
        return;
    }
    if(contact == head){
        cout << "HEAD" << endl;
        return;
    }
    cout << setw(5) << contact->GetID();
    cout << setw(22) << contact->GetName();
    cout << setw(50) <<
         contact->GetStreetAddress() + ", " +
         contact->GetCity() + " " +
         contact->GetState() + " " +
         contact->GetZip();
    cout << setw(15) << contact->GetPhone();
    cout << endl;
}
void Rolodex:: PrintRolodex(){
    Contact * current = head->GetNext();
    cout << setw(5) << "ID";
    cout << setw(22) << "Name";
    cout << setw(50) << "Address";
    cout << setw(15) << "Phone";
    cout << endl;
    cout << "----------------------------------------------";
    cout << "----------------------------------------------";
    cout << endl;
    while(current != nullptr){
        PrintContact(current);
        current = current->GetNext();
    }
}