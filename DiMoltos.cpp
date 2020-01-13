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

//Declaring functions

void reusedMenu(string option1, string option2, float *price, string *chosenOption, bool type){
    int userInput;
    cout << "Por favor escoga de entre las siguientes opciones, escribiendo el numero que se les antepone: \n";
    cout << option1 << endl << option2 << endl;
    cin >> userInput;
    if(type == true){
        switch(userInput){
            case 1:
                *price += 0.99;
                *chosenOption = "Gaseosa";
                break;
            case 2:
                *price += 1.99;
                *chosenOption = "Te";
                break;
            default:
                cout << "error";
                break;
        }
    }
    else{
        switch(userInput){
            case 1:
                *price += 3.99;
                *chosenOption = "Palitroques";
                break;
            case 2:
                *price += 2.99;
                *chosenOption = "Palitos de queso";
                break;
            default:
                cout << "error";
                break;
        }
    }
}

void reusedMenu(string option1, string option2, string option3, float *price, string *chosenOption){
    int userInput;
    cout << "Por favor escoga su plato principal de entre las siguientes opciones, escribiendo el numero que se les antepone: \n";
    cout << option1 << endl << option2 << endl << option3 << endl;
    cin >> userInput;
    switch(userInput){
        case 1:
            *price += 6.99;
            *chosenOption = "Pizza";
            break;
        case 2:
            *price += 9.99;
            *chosenOption = "Pasta";
            break;
        case 3:
            *price += 8.99;
            *chosenOption = "Ensalada";
            break;
        default:
            cout << "error";
            break;
    }
}

void addTakeOut(takeOut *order, int *counter){
    bool type = true;
    //Adding orders 'to go'/delivery.
    if(*counter < 1){
        (*order).price = 0;
        cout << "Por favor digite su nombre. Solo el primer nombre es necesario.\n";
        cin.ignore();
        getline(cin, (*order).clientName);
        
        cout << "Por favor digite su direccion.\n";
        cin.ignore();
        getline(cin, (*order).clientAddress);

        cout << "Por favor digite su numero de telefono, con el formato XXXX-XXXX: \n";
        cin.ignore();
        getline(cin, (*order).clientPhoneNumber);

        reusedMenu("\t1- Pizza", "\t2- Pasta", "\t3- Ensalada", &(*order).price, &(*order).mainDish);
        type = false;

        reusedMenu("\t1- Palitroques", "\t2- Palitos de Queso", &(*order).price, &(*order).appetizer, type);
        type = true;

        reusedMenu("\t1- Gaseosa", "\t2- Te", &(*order).price, &(*order).drink, type);

        cout << "Su total es: " << (*order).price << endl;
        cout << "Por medio de que se realizara el pago?\n";
        cin.ignore();
        getline(cin, (*order).paymentMethod);

        *counter++;
    }
    else{
        cout << "En este momento el servidor no puede almacenar mas de una orden. Gracias por su comprension.\n";
    }
}

void addHouseOrder(inHouseOrder *order, int *counter){
    bool type = true;
    //Adding orders in restaurant.
    if(*counter < 1){
        (*order).price = 0;
        cout << "Por favor digite su nombre. Solo el primer nombre es necesario.\n";
        cin.ignore();
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
        cin.ignore();
        getline(cin, (*order).paymentMethod);

        *counter++;
    }
    else{
        cout << "En este momento el servidor no puede almacenar mas de una orden. Gracias por su comprension.\n";
    }
}

void showTakeOuts(takeOut *order){
    cout << "Nombre del cliente: " << (*order).clientName << endl;
    cout << "Direccion del cliente: " << (*order).clientAddress << endl;
    cout << "Numero del cliente: " << (*order).clientPhoneNumber << endl;
    cout << "Plato principal: " << (*order).mainDish << endl;
    cout << "Aperitivo: " << (*order).appetizer << endl;
    cout << "Bebida: " << (*order).drink << endl;
    cout << "Precio: " << (*order).price << endl;
    cout << "Metodo de pago: " << (*order).paymentMethod << endl;
}

void showHouseOrders(inHouseOrder *order){
    cout << "Nombre del cliente: " << (*order).clientName << endl;
    cout << "Personas en la mesa: " << (*order).clientsPerTable << endl;
    cout << "Plato principal: " << (*order).mainDish << endl;
    cout << "Aperitivo: " << (*order).appetizer << endl;
    cout << "Bebida: " << (*order).drink << endl;
    cout << "Precio: " << (*order).price << endl;
    cout << "Metodo de pago: " << (*order).paymentMethod << endl;
}

void showTotalPrice(float price1, float price2, float *totalPrice){
    *totalPrice = price1 + price2;
    cout << "El precio total es: " << *totalPrice << "$\n";
}

void mainMenu(bool *outerCheck){
    //Main Menu.
    //Local variables.
    string userInput;
    bool correctPass = false;
    int userOption, counterTOrders = 0, counterIHOrders = 0;
    float totalPrice;

    takeOut takeOrder;
    takeOrder.price = 0;
    inHouseOrder houseOrder;
    houseOrder.price = 0;

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
    
    while(correctPass == true){
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
                showTotalPrice(takeOrder.price, houseOrder.price, &totalPrice);
                break;
            case 6:
                *outerCheck = false;
                correctPass = false;
                break;
        }
    }
}

int main(){
    //Flag used in menu display.
    bool inMenu = true;
    while(inMenu == true){
        mainMenu(&inMenu);
    }
    return 0;
}