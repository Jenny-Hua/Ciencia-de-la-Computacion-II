#ifndef __PERSON_H__
#define __PERSON_H__

#include <iostream>
#include <string>


class Person
{
    private:
        std::string name;
        int id;
    public:
        Person(std::string n ="", int i = 0) : name(n), id(i) {};   // construnctor con valores por defecto
        std::string getName() const {
            return name;
        }
        int getId()const {
            return id;
        }
        void setName(std::string n){
            name = n;
        }
        void setId(int id){
            this->id = id;
        }
};

#endif