#include <iostream>
using namespace std;

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

//Overloading functions
void addTakeOut(){
}
void addHouseOrder(){
}
void showTakeOuts(){
}
void showHouseOrders(){
}
void reusedMenu(){
}
void showTotalPrice(){

}

void mainMenu(){
    //Main Menu.
    //Local variables.
    string userInput;
    bool correctPass = false;
    int userOption, counterTOrders = 0, counterIHOrders = 0;
    float totalPrice;

    takeOut takeOrder;
    inHouseOrder houseOrder;

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
        cout << "\t6- Salir." << endl;
        cin >> userOption;
        switch(userOption){
            case 1:
                addTakeOut(&takeOrder, &counterTOrders);
                break;
            case 2:
                addHouseOrder(&houseOrder, &counterIHOrders);
                break;
            case 3:
                showTakeOuts(&takeOrder);
                break;
            case 4:
                showHouseOrders(&houseOrder);
                break;
            case 5:
                showTotalPrice(&takeOrder, &houseOrder, &totalPrice);
                break;
        }
    }
}

void addTakeOut(takeOut *order, int *counter){
    bool type = true;
    //Adding orders 'to go'/delivery.
    if(*counter < 1){
        (*order).price = 0;
        cout << "Por favor digite su nombre. Solo el primer nombre es necesario.\n";
        getline(cin, (*order).clientName);
        
        cout << "Por favor digite su direccion.\n";
        getline(cin, (*order).clientAddress);

        cout << "Por favor digite su numero de telefono, con el formato XXXX-XXXX: \n";
        getline(cin, (*order).clientPhoneNumber);

        reusedMenu("\t1- Pizza", "\t2- Pasta", "\t3- Ensalada", &(*order).price, &(*order).mainDish);
        type = false;

        reusedMenu("\t1- Palitroques", "\t2- Palitos de Queso", &(*order).price, &(*order).appetizer, type);
        type = true;

        reusedMenu("\t1- Gaseosa", "\t2- Te", &(*order).price, &(*order).drink, type);

        cout << "Su total es: " << (*order).price << endl;
        cout << "Por medio de que se realizara el pago?\n";
        getline(cin, (*order).paymentMethod);

        *counter++;
    }
    else{
        cout << "En este momento el servidor no puede almacenar mas de una orden. Gracias por su comprension.\n";
    }
}

void addHouseOrder(inHouseOrder *order, int *counter){
    bool type = true;
    //Adding orders 'to go'/delivery.
    if(*counter < 1){
        (*order).price = 0;
        cout << "Por favor digite su nombre. Solo el primer nombre es necesario.\n";
        getline(cin, (*order).clientName);
        
        cout << "Por favor indique el numero de personas en la mesa.\n";
        cin >> (*order).clientsPerTable;

        reusedMenu("\t1- Pizza", "\t2- Pasta", "\t3- Ensalada", &(*order).price, &(*order).mainDish);
        type = false;

        reusedMenu("\t1- Palitroques", "\t2- Palitos de Queso", &(*order).price, &(*order).appetizer, type);
        type = true;

        reusedMenu("\t1- Gaseosa", "\t2- Te", &(*order).price, &(*order).drink, type);

        cout << "Su total es: " << (*order).price << endl;
        cout << "Por medio de que se realizara el pago?\n";
        getline(cin, (*order).paymentMethod);

        *counter++;
    }
    else{
        cout << "En este momento el servidor no puede almacenar mas de una orden. Gracias por su comprension.\n";
    }
}



int main(){
    //Flag used in menu display.
    bool inMenu = true;

}