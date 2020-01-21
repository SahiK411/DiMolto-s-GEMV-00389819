#include <iostream>
using namespace std;

//Structs
struct takeOut{
    int id;
    name clientName;
    address clientAddress;
    string clientPhoneNumber;
    string mainDish;
    string appetizer;
    string drink;
    float price;
    string paymentMethod;
};

struct inHouseOrder{
    int id;
    name clientName;
    int clientsPerTable;
    string mainDish;
    string appetizer;
    string drink;
    float price;
    string paymentMethod;
};

struct address{
    string houseNumber;
    string neighborhood;
    string county;
    string state;
};

struct name{
    string firstName;
    string middleName;
    string surName;
    string lastName;
};

//Prototyping functions
void addTakeOut(takeOut *order[], int *counter);
void addHouseOrder(inHouseOrder *order[], int *counter);
void showTakeOuts(takeOut *order[], int size);
void showHouseOrders(inHouseOrder *order[], int size);
void reusedMenu(string option1, string option2, string option3, float *price, string *chosenOption);
void reusedMenu(string option1, string option2, float *price, string *chosenOption, bool type);
void showTotalPrice(takeOut *price1[], inHouseOrder *price2[], float *totalPrice, int size1, int size2);
void searchByName(takeOut *searched[], int size);
void searchByName(inHouseOrder *searched[], int size);
void deleteOrder(takeOut *searched[], int size);
void deleteOrder(inHouseOrder *searched[], int size);

void mainMenu(bool *outerCheck, int *sizeTOrders, int *sizeHOrders){
    //Main Menu.
    //Local variables.
    string userInput;
    bool correctPass = false, administrator = false;
    int userOption, sizeTOrders = 0, sizeHOrders = 0, temp = 0;
    float totalPrice;

    takeOut *takeOrder;
    inHouseOrder *houseOrder;

    takeOrder = new takeOut[*sizeTOrders];
    houseOrder = new inHouseOrder[*sizeHOrders];

    cout << "Con que tipo de cuenta desea operar?\n 1- Empleado \t2- Administrador\t 3- Salir\n";
    cin >> userInput;
    cin.ignore();

    if(userInput == "1"){
        correctPass = true;
        administrator = false;
    }
    else if(userInput == "2"){
        //Checking password
        cout << "Por favor digite la contrasena, o digite R para regresar.\n";
        getline(cin, userInput);
        if(userInput == "recursion"){
            cout << "Contrasena aceptada.\n";
            correctPass = true;
            administrator = true;
        }
        else if(userInput == "r" || userInput == "R"){
            cout << "Regresando.\n";
        }
        else{
            cout << "Contrasena incorrecta.\n";
        }
    }
    else if(userInput == "3"){
        *outerCheck = false;
    }

    for(int i = 0; i < *sizeTOrders; i++){
        takeOrder[i].id = 1001 + i;
        takeOrder[i].clientName.firstName = "";
        takeOrder[i].clientName.middleName = "";
        takeOrder[i].clientName.surName = "";
        takeOrder[i].clientName.lastName = "";
        takeOrder[i].clientPhoneNumber = "";
        takeOrder[i].clientAddress.houseNumber = "";
        takeOrder[i].clientAddress.neighborhood = "";
        takeOrder[i].clientAddress.county = "";
        takeOrder[i].clientAddress.state = "";
        takeOrder[i].appetizer = "";
        takeOrder[i].mainDish = "";
        takeOrder[i].drink = "";
        takeOrder[i].price = 0;
        takeOrder[i].paymentMethod = "";
    }
    for(int i = 0; i < *sizeHOrders; i++){
        houseOrder[i].id = 1001 + i;
        houseOrder[i].clientName.firstName = "";
        houseOrder[i].clientName.middleName = "";
        houseOrder[i].clientName.surName = "";
        houseOrder[i].clientName.lastName = "";
        houseOrder[i].clientsPerTable = 0;
        houseOrder[i].appetizer = "";
        houseOrder[i].mainDish = "";
        houseOrder[i].drink = "";
        houseOrder[i].price = 0;
        houseOrder[i].paymentMethod = "";
    }
    
    while(correctPass == true){
        cout << "Digite el numero de la opcion deseada.\n";
        cout << "\t1- Agregar un pedido a domicilio." << endl;
        cout << "\t2- Agregar un encargo en restaurante." << endl;
        cout << "\t3- Ver pedidos a domicilio." << endl;
        cout << "\t4- Ver encargos en restaurante." << endl;
        cout << "\t5- Ver total de venta." << endl;
        cout << "\t6- Buscar una orden por nombre." << endl;
        cout << "\t7- Borrar una orden." << endl;
        cout << "\t8- Regresar." << endl;
        cin >> userOption;
        switch(userOption){
            case 1:
                addTakeOut(&takeOrder, sizeTOrders);
                break;
            case 2:
                addHouseOrder(&houseOrder, sizeHOrders);
                break;
            case 3:
                showTakeOuts(&takeOrder, *sizeTOrders);
                break;
            case 4:
                showHouseOrders(&houseOrder, *sizeHOrders);
                break;
            case 5:
                showTotalPrice(&takeOrder, &houseOrder, &totalPrice, *sizeTOrders, *sizeHOrders);
                break;
            case 6:
                cout << "En cual directorio desea buscar?\n 1- A domicilio\t 2- En restaurante\n";
                cin >> temp;
                cin.ignore();
                if(temp == 1){
                    searchByName(&takeOrder, *sizeTOrders);
                }
                else if(temp == 2){
                    searchByName(&houseOrder, *sizeHOrders);
                }
                break;
            case 7:
                if(administrator == true){
                    
                }
                else{
                    cout << "Solo los administradores pueden borrar ordenes.\n";
                }
                break;
            case 8:
                correctPass = false;
                break;
            default:
                break;
        }
    }
}

void addTakeOut(takeOut *order[], int *counter){
    bool type = true;
    int currentOrder = 0;
    cout << "Que numero de orden es esta? (Solo cuente aquellas ordenes que se introducen en esta sesion y en esta categoria.)\n";
    cin >> currentOrder;
    //Adding orders 'to go'/delivery.
    for (int i = 0; i < *counter; i++){
     if((*order)[i].id == 1000 + currentOrder){
        (*order)[i].price = 0;
        cout << "Por favor digite su nombre.\n Ingrese el primer nombre.\n";
        cin.ignore();
        getline(cin, (*order)[i].clientName.firstName);

        cout << "Ingrese el segundo nombre.\n";
        cin.ignore();
        getline(cin, (*order)[i].clientName.middleName);

        cout << "Ingrese el primer apellido.\n";
        cin.ignore();
        getline(cin, (*order)[i].clientName.surName);

        cout << "Ingrese el segundo apellido.\n";
        cin.ignore();
        getline(cin, (*order)[i].clientName.lastName);
        
        cout << "Por favor digite su direccion.\n Ingrese el numero de casa.\n";
        cin.ignore();
        getline(cin, (*order)[i].clientAddress.houseNumber);

        cout << "Ingrese la colonia.\n";
        cin.ignore();
        getline(cin, (*order)[i].clientAddress.neighborhood);

        cout << "Ingrese el municipio.\n";
        cin.ignore();
        getline(cin, (*order)[i].clientAddress.county);

        cout << "Ingrese el departamento.\n";
        cin.ignore();
        getline(cin, (*order)[i].clientAddress.state);

        cout << "Por favor digite su numero de telefono, con el formato XXXX-XXXX: \n";
        cin.ignore();
        getline(cin, (*order)[i].clientPhoneNumber);

        reusedMenu("\t1- Pizza", "\t2- Pasta", "\t3- Ensalada", &(*order)[i].price, &(*order)[i].mainDish);
        type = false;

        reusedMenu("\t1- Palitroques", "\t2- Palitos de Queso", &(*order)[i].price, &(*order)[i].appetizer, type);
        type = true;

        reusedMenu("\t1- Gaseosa", "\t2- Te", &(*order)[i].price, &(*order)[i].drink, type);

        cout << "Su total es: " << (*order)[i].price << endl;
        cout << "Por medio de que se realizara el pago?\n";
        cin.ignore();
        getline(cin, (*order)[i].paymentMethod);
    }
    else{
        cout << "Este numero de orden no es admitido dentro de esta sesion.\n";
    }   
    }
}
        
void addHouseOrder(inHouseOrder *order[], int *counter){
    bool type = true;
    int currentOrder;
    cout << "Que numero de orden es esta? (Solo cuente aquellas ordenes que se introducen en esta sesion y en esta categoria.)\n";
    cin >> currentOrder;
    //Adding orders in restaurant.
    for (int i = 0; i < *counter; i++){
        if((*order)[i].id == 1000 + currentOrder){
            (*order)[i].price = 0;
            cout << "Por favor digite su nombre.\n Ingrese el primer nombre.\n";
            cin.ignore();
            getline(cin, (*order)[i].clientName.firstName);

            cout << "Ingrese el segundo nombre.\n";
            cin.ignore();
            getline(cin, (*order)[i].clientName.middleName);

            cout << "Ingrese el primer apellido.\n";
            cin.ignore();
            getline(cin, (*order)[i].clientName.surName);

            cout << "Ingrese el segundo apellido.\n";
            cin.ignore();
            getline(cin, (*order)[i].clientName.lastName);
            
            cout << "Por favor indique el numero de personas en la mesa.\n";
            cin >> (*order)[i].clientsPerTable;

            reusedMenu("\t1- Pizza", "\t2- Pasta", "\t3- Ensalada", &(*order)[i].price, &(*order)[i].mainDish);
            type = false;

            reusedMenu("\t1- Palitroques", "\t2- Palitos de Queso", &(*order)[i].price, &(*order)[i].appetizer, type);
            type = true;

            reusedMenu("\t1- Gaseosa", "\t2- Te", &(*order)[i].price, &(*order)[i].drink, type);

            cout << "Su total es: " << (*order)[i].price << endl;
            cout << "Por medio de que se realizara el pago?\n";
            cin.ignore();
            getline(cin, (*order)[i].paymentMethod);    
        }
        else{
            cout << "Este numero de orden no es admitido dentro de esta sesion.\n";
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

void showTakeOuts(takeOut *order[], int size){
    for(int i = 0; i < size; i++){
        cout << "Identificador de orden: " << (*order)[i].id << endl;
        cout << "Primer nombre del cliente: " << (*order)[i].clientName.firstName << endl;
        cout << "Segundo nombre del cliente: " << (*order)[i].clientName.middleName << endl;
        cout << "Primer apellido del cliente: " << (*order)[i].clientName.surName << endl;
        cout << "Segundo apellido del cliente: " << (*order)[i].clientName.lastName << endl;
        cout << "Numero de casa: " << (*order)[i].clientAddress.houseNumber << endl;
        cout << "Colonia: " << (*order)[i].clientAddress.neighborhood << endl;
        cout << "Municipio: " << (*order)[i].clientAddress.county << endl;
        cout << "Departamento: " << (*order)[i].clientAddress.state << endl;
        cout << "Numero del cliente: " << (*order)[i].clientPhoneNumber << endl;
        cout << "Plato principal: " << (*order)[i].mainDish << endl;
        cout << "Aperitivo: " << (*order)[i].appetizer << endl;
        cout << "Bebida: " << (*order)[i].drink << endl;
        cout << "Precio: " << (*order)[i].price << endl;
        cout << "Metodo de pago: " << (*order)[i].paymentMethod << endl;
    }
}

void showHouseOrders(inHouseOrder *order[], int size){
    for(int i = 0; i < size; i++){
        cout << "Identificador de orden: " << (*order)[i].id << endl;
        cout << "Primer nombre del cliente: " << (*order)[i].clientName.firstName << endl;
        cout << "Segundo nombre del cliente: " << (*order)[i].clientName.middleName << endl;
        cout << "Primer apellido del cliente: " << (*order)[i].clientName.surName << endl;
        cout << "Segundo apellido del cliente: " << (*order)[i].clientName.lastName << endl;
        cout << "Personas en la mesa: " << (*order)[i].clientsPerTable << endl;
        cout << "Plato principal: " << (*order)[i].mainDish << endl;
        cout << "Aperitivo: " << (*order)[i].appetizer << endl;
        cout << "Bebida: " << (*order)[i].drink << endl;
        cout << "Precio: " << (*order)[i].price << endl;
        cout << "Metodo de pago: " << (*order)[i].paymentMethod << endl;
    }
}

void showTotalPrice(takeOut *price1[], inHouseOrder *price2[], float *totalPrice, int size1, int size2){
    for(int i = 0; i < size1; i++){
        *totalPrice += (*price1)[i].price;
    }
    for(int i = 0; i < size2; i++){
        *totalPrice += (*price2)[i].price;
    }
    cout << "El precio total es: " << *totalPrice << "$\n";
}

void searchByName(takeOut *searched[], int size){
    //Function to find order by first name, last name
    string searchedName, searchedLast;
    bool type = true;
    int temp = 0, userInput;
    cout << "Ingrese el primer nombre de la orden que desea encontrar.\n";
    getline(cin, searchedName);
    cin.ignore();
    cout << "Ingrese el ultimo apellido de la orden que desea encontrar.\n";
    getline(cin, searchedLast);

    for(int i = 0; i < size; i++){
        if(searchedName == (*searched)[i].clientName.firstName && searchedLast == (*searched)[i].clientName.lastName){
            cout << "Orden encontrada! El identificador de la orden es: " << (*searched)[i].id << " .\n";
            cout << "Desea cambiar algo?\n 1- Si\t 2- No\n";
            cin.ignore();
            cin >> userInput;
            if(userInput == 1){
                cout << "Digite el numero de la opcion deseada.\n";
                cout << "\t1- Nombre." << endl;
                cout << "\t2- Direccion." << endl;
                cout << "\t3- Numero de telefono." << endl;
                cout << "\t4- Orden." << endl;
                cout << "\t5- Metodo de pago." << endl;
                cout << "\t6- Regresar." << endl;
                cin.ignore();
                cin >> temp;
                switch(temp){
                    case 1:
                        cout << "Por favor digite su nombre.\n Ingrese el primer nombre.\n";
                        cin.ignore();
                        getline(cin, (*searched)[i].clientName.firstName);

                        cout << "Ingrese el segundo nombre.\n";
                        cin.ignore();
                        getline(cin, (*searched)[i].clientName.middleName);

                        cout << "Ingrese el primer apellido.\n";
                        cin.ignore();
                        getline(cin, (*searched)[i].clientName.surName);

                        cout << "Ingrese el segundo apellido.\n";
                        cin.ignore();
                        getline(cin, (*searched)[i].clientName.lastName);
                        break;
                    case 2:
                        cout << "Por favor digite su direccion.\n Ingrese el numero de casa.\n";
                        cin.ignore();
                        getline(cin, (*searched)[i].clientAddress.houseNumber);

                        cout << "Ingrese la colonia.\n";
                        cin.ignore();
                        getline(cin, (*searched)[i].clientAddress.neighborhood);

                        cout << "Ingrese el municipio.\n";
                        cin.ignore();
                        getline(cin, (*searched)[i].clientAddress.county);

                        cout << "Ingrese el departamento.\n";
                        cin.ignore();
                        getline(cin, (*searched)[i].clientAddress.state);
                        break;
                    case 3:
                        cout << "Por favor digite su numero de telefono, con el formato XXXX-XXXX: \n";
                        cin.ignore();
                        getline(cin, (*searched)[i].clientPhoneNumber);
                        break;
                    case 4:
                        (*searched)[i].price = 0;
                        reusedMenu("\t1- Pizza", "\t2- Pasta", "\t3- Ensalada", &(*searched)[i].price, &(*searched)[i].mainDish);
                        type = false;

                        reusedMenu("\t1- Palitroques", "\t2- Palitos de Queso", &(*searched)[i].price, &(*searched)[i].appetizer, type);
                        type = true;

                        reusedMenu("\t1- Gaseosa", "\t2- Te", &(*searched)[i].price, &(*searched)[i].drink, type);
                        break;
                    case 5:
                        cout << "Por medio de que se realizara el pago?\n";
                        cin.ignore();
                        getline(cin, (*searched)[i].paymentMethod);
                        break;
                    case 6:
                        break;
                    default:
                        cout << "error" << endl;
                        break;
                }
            }
            else{}
        }
    }
}

void searchByName(inHouseOrder *searched[], int size){
    //Function to find order by first name, last name
    string searchedName, searchedLast;
    bool type = true;
    int temp = 0, userInput;
    cout << "Ingrese el primer nombre de la orden que desea encontrar.\n";
    getline(cin, searchedName);
    cin.ignore();
    cout << "Ingrese el ultimo apellido de la orden que desea encontrar.\n";
    getline(cin, searchedLast);

    for(int i = 0; i < size; i++){
        if(searchedName == (*searched)[i].clientName.firstName && searchedLast == (*searched)[i].clientName.lastName){
            cout << "Orden encontrada! El identificador de la orden es: " << (*searched)[i].id << " .\n";
            cout << "Desea cambiar algo?\n 1- Si\t 2- No\n";
            cin.ignore();
            cin >> userInput;
            if(userInput == 1){
                cout << "Digite el numero de la opcion deseada.\n";
                cout << "\t1- Nombre." << endl;
                cout << "\t2- Numero de clientes en la mesa." << endl;
                cout << "\t3- Orden." << endl;
                cout << "\t4- Metodo de pago." << endl;
                cout << "\t5- Regresar." << endl;
                cin.ignore();
                cin >> temp;
                switch(temp){
                    case 1:
                        cout << "Por favor digite su nombre.\n Ingrese el primer nombre.\n";
                        cin.ignore();
                        getline(cin, (*searched)[i].clientName.firstName);

                        cout << "Ingrese el segundo nombre.\n";
                        cin.ignore();
                        getline(cin, (*searched)[i].clientName.middleName);

                        cout << "Ingrese el primer apellido.\n";
                        cin.ignore();
                        getline(cin, (*searched)[i].clientName.surName);

                        cout << "Ingrese el segundo apellido.\n";
                        cin.ignore();
                        getline(cin, (*searched)[i].clientName.lastName);
                        break;
                    case 2:
                        cout << "Por favor digite el numero de clientes en la mesa: \n";
                        cin.ignore();
                        cin >> (*searched)[i].clientsPerTable;
                        break;
                    case 3:
                        (*searched)[i].price = 0;
                        reusedMenu("\t1- Pizza", "\t2- Pasta", "\t3- Ensalada", &(*searched)[i].price, &(*searched)[i].mainDish);
                        type = false;

                        reusedMenu("\t1- Palitroques", "\t2- Palitos de Queso", &(*searched)[i].price, &(*searched)[i].appetizer, type);
                        type = true;

                        reusedMenu("\t1- Gaseosa", "\t2- Te", &(*searched)[i].price, &(*searched)[i].drink, type);
                        break;
                    case 4:
                        cout << "Por medio de que se realizara el pago?\n";
                        cin.ignore();
                        getline(cin, (*searched)[i].paymentMethod);
                        break;
                    case 5:
                        break;
                    default:
                        cout << "error" << endl;
                        break;
                }
            }
            else{}
        }
    }
}

void deleteOrder(takeOut *searched[], int size){
    //Function to delete orders
    int userID, confirmation;
    bool found = false;
    cout << "Por favor ingrese el identificador de la orden.\n";
    cin >> userID;
    for(int i = 0; i < size; i++){
        if((*searched)[i].id == userID){
            found = true;
            cout << "Esta seguro que desea borrar esta orden?\n 1- Si\t 2- No\n";
            cin.ignore;
            cin >> confirmation;
            if(confirmation == 1){
                (*searched)[i].clientName.firstName = "";
                (*searched)[i].clientName.middleName = "";
                (*searched)[i].clientName.surName = "";
                (*searched)[i].clientName.lastName = "";
                (*searched)[i].clientPhoneNumber = "";
                (*searched)[i].clientAddress.houseNumber = "";
                (*searched)[i].clientAddress.neighborhood = "";
                (*searched)[i].clientAddress.county = "";
                (*searched)[i].clientAddress.state = "";
                (*searched)[i].appetizer = "";
                (*searched)[i].mainDish = "";
                (*searched)[i].drink = "";
                (*searched)[i].price = 0;
                (*searched)[i].paymentMethod = "";
            }
            else{}
        }
    }
    if(found == false){
        cout << "No se encontro la orden.\n";
    }
}

void deleteOrder(inHouseOrder *searched[], int size){
    //Function to delete orders
    int userID, confirmation;
    bool found = false;
    cout << "Por favor ingrese el identificador de la orden.\n";
    cin >> userID;
    for(int i = 0; i < size; i++){
        if((*searched)[i].id == userID){
            found = true;
            cout << "Esta seguro que desea borrar esta orden?\n 1- Si\t 2- No\n";
            cin.ignore;
            cin >> confirmation;
            if(confirmation == 1){
                (*searched)[i].clientName.firstName = "";
                (*searched)[i].clientName.middleName = "";
                (*searched)[i].clientName.surName = "";
                (*searched)[i].clientName.lastName = "";
                (*searched)[i].clientsPerTable = 0;
                (*searched)[i].appetizer = "";
                (*searched)[i].mainDish = "";
                (*searched)[i].drink = "";
                (*searched)[i].price = 0;
                (*searched)[i].paymentMethod = "";
            }
            else{}
        }
    }
    if(found == false){
        cout << "No se encontro la orden.\n";
    }
}

int main(){
    //Flag used in menu display.
    bool inMenu = true;
    int size1, size2;
    cout << "Con cuantas ordenes se trabajara a domicilio?\n";
    cin >> size1;
    cin.ignore();
    cout << "Con cuantas ordenes se trabajara en el restaurante?\n";
    cin >> size2;
    cin.ignore();
    while(inMenu == true){
        mainMenu(&inMenu, &size1, &size2);
    }
    return 0;
}