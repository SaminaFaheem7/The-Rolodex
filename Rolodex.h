
#ifndef PROGRAM5_ROLODEX_H
#define PROGRAM5_ROLODEX_H
#include "Contact.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;
enum Field {ID, NAME, CITY, STATE, ZIP};

class Rolodex {
public:
    Rolodex();
    ~Rolodex();
    int LoadFromFile(string filename);
    void AddContact(string name, string streetAddress, string city, string state, string zip, string phone);
    int Length();
    void DeleteContact(int id);
    int GetMaxID();
    void DuplicateContact(int id);
    Contact * FindContactByID(int id);
    bool IDExists(int id);
    void UpdateContact(int id, string name, string streetAddress, string city, string state, string zip, string phone);
    void SortBy(Field field);
    void MergeSort(Contact** headRef,Field field );
    Contact* SortedMergeName(Contact* a, Contact* b);
    Contact* SortedMergeID(Contact* a, Contact* b);
    Contact* SortedMergeCity(Contact* a, Contact* b);
    Contact* SortedMergeState(Contact* a, Contact* b);
    Contact* SortedMergeZip(Contact* a, Contact* b);
    void FrontBackSplit(Contact* source,Contact** frontRef, Contact** backRef);
    void PrintContact(Contact * contact);
    void PrintRolodex();

private:
    Contact * head;
};


#endif //PROGRAM5_ROLODEX_H
