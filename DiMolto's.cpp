#include <iostream>
using namespace std;

void addTakeOut(){
    //Adding orders 'to go'/delivery.

}

void mainMenu(){
    //Main Menu.
    //Local variables.
    string userInput;
    bool correctPass = false;
    int userOption;
    float totalPrice;

    //Structs
    struct takeOut{
        string clientName;
        string clientAddress;
        string clientPhoneNumber;
        string mainDish;
        string appetizer;
        string drink;
        float price;
        string paymentMethod;
    };

    struct inHouseOrder{
        string clientName;
        int clientsPerTable;
        string mainDish;
        string appetizer;
        string drink;
        float price;
        string paymentMethod;
    };

    //Checking password
    cout << "Por favor digite la contrasena.\n";
    getline(cin, userInput);
    if(userInput == "recursion"){
        cout << "Contrasena aceptada.\n";
        correctPass = true;
    }
    else{
        cout << "Contrasena incorrecta.\n";
    }
    
    while(correctPass = true){
        cout << "Digite el numero de la opcion deseada.\n";
        cout << "\t1- Agregar un pedido a domicilio." << endl;
        cout << "\t2- Agregar un encargo en restaurante." << endl;
        cout << "\t3- Ver pedidos a domicilio." << endl;
        cout << "\t4- Ver encargos en restaurante." << endl;
        cout << "\t5- Ver total de venta." << endl;
        cin >> userOption;
        switch(userOption){
            case 1:
                addTakeOut();
        }
    }
}

int main(){
    //Flag used in menu display.
    bool inMenu = true;

}