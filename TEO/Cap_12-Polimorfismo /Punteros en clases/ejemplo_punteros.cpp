// Fig. 12.6: fig12_06.cpp
// Introducing polymorphism, virtual functions and dynamic binding.

// * Demostrar polimorfismo invocando una función virtual 
// * de clase derivada mediante un puntero de clase base a un objeto de clase derivada.

// g++ ejemplo_punteros.cpp Employee/CommissionEmployee.cpp Employee/BasePlusCommissionEmployee.cpp Employee/Employee.cpp

#include <iostream>
#include <iomanip>

#include "Employee/CommissionEmployee.h"
#include "Employee/BasePlusCommissionEmployee.h"

using namespace std;

int main()
{
    
    // create base-class object
    CommissionEmployee commissionEmployee{
        "Sue", "Jones", "222-22-2222", 10000, .06};
    
    // create derived-class object
    BasePlusCommissionEmployee basePlusCommissionEmployee{
        "Bob", "Lewis", "333-33-3333", 5000, .04, 300};
    cout << fixed << setprecision(2); // set floating-point formatting
    
    // output objects using static binding
    cout << "INVOKING TOSTRING FUNCTION ON BASE-CLASS AND DERIVED-CLASS "
         << "\nOBJECTS WITH STATIC BINDING\n"
         << commissionEmployee.toString() // static binding
         << "\n\n"
         << basePlusCommissionEmployee.toString(); // static binding
    
    // output objects using dynamic binding
    cout << "\n\nINVOKING TOSTRING FUNCTION ON BASE-CLASS AND "
         << "\nDERIVED-CLASS OBJECTS WITH DYNAMIC BINDING";
    
    // natural: aim base-class pointer at base-class object
    const CommissionEmployee *commissionEmployeePtr{&commissionEmployee};
    cout << "\n\nCALLING VIRTUAL FUNCTION TOSTRING WITH BASE-CLASS POINTER"
         << "\nTO BASE-CLASS OBJECT INVOKES BASE-CLASS "
         << "TOSTRING FUNCTION:\n"
         << commissionEmployeePtr->toString(); // base version
    
    // natural: aim derived-class pointer at derived-class object
    const BasePlusCommissionEmployee *basePlusCommissionEmployeePtr{
        &basePlusCommissionEmployee}; // natural
    cout << "\n\nCALLING VIRTUAL FUNCTION TOSTRING WITH DERIVED-CLASS "
         << "POINTER\nTO DERIVED-CLASS OBJECT INVOKES DERIVED-CLASS "
         << "TOSTRING FUNCTION:\n"
         << basePlusCommissionEmployeePtr->toString(); // derived version
    
    // aim base-class pointer at derived-class object
    commissionEmployeePtr = &basePlusCommissionEmployee;
    cout << "\n\nCALLING VIRTUAL FUNCTION TOSTRING WITH BASE-CLASS POINTER"
         << "\nTO DERIVED-CLASS OBJECT INVOKES DERIVED-CLASS "
         << "TOSTRING FUNCTION:\n";
    
    // polymorphism; invokes BasePlusCommissionEmployee's toString
    // via base-class pointer to derived-class object
    cout << commissionEmployeePtr->toString() << endl;
}