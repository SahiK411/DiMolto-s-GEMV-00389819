#include <iostream>
#include <string>
#include <vector>

//Define declaration
#define password "recursion"

using namespace std;

//ENUM declaration
enum mainDish{pizza = 0, pasta, lasagna, n};
enum drink{beer = 0, tea, soda, o};
enum appetizer{pizzaRolls = 0, garlicBread, cheeseSticks, ne};
enum paymentMethod{cash = 0, creditCard, null};

//Structs
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

struct takeOut{
    int id;
    name clientName;
    address clientAddress;
    string clientPhoneNumber;
    vector <mainDish> orderDish;
    vector <appetizer> orderAppe;
    vector <drink> orderDrink;
    float price;
    paymentMethod orderMethod;
};

struct inHouseOrder{
    int id;
    name clientName;
    int clientsPerTable;
    vector <mainDish> orderDish;
    vector <appetizer> orderAppe;
    vector <drink> orderDrink;
    float price;
    paymentMethod orderMethod;
};

//Global Variables
vector <takeOut> takeOrder;
vector <inHouseOrder> houseOrder;
vector <takeOut> dispatchedTakeOut;
vector <inHouseOrder> dispatchedHouse;
string printDish[] = {"Pizza", "Pasta", "Lasagna", "none"};
string printAppe[] = {"Rollos de Pizza", "Pan con ajo", "Palitos de queso", "none"};
string printDrink[] = {"Cerveza", "Te Helado", "Gaseosa", "none"};
string printMethod[] = {"Efectivo", "Tarjeta", "none"};


//Prototyping functions
void addTakeOut();
void addHouseOrder();
void showTakeOuts();
void showHouseOrders();
void showTotalPrice();
void searchByNameTake();
void searchByNameHouse();
void deleteOrderTakeOut();
void deleteOrderHouse();

void mainMenu(bool *outerCheck){
    //Main Menu.
    //Local variables.
    string userInput;
    bool correctPass = false, administrator = false;
    int userOption, temp = 0;

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
        if(userInput == password){
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
        cin.ignore();
        switch(userOption){
            case 1:
                addTakeOut();
                break;
            case 2:
                addHouseOrder();
                break;
            case 3:
                showTakeOuts();
                break;
            case 4:
                showHouseOrders();
                break;
            case 5:
                showTotalPrice();
                break;
            case 6:
                cout << "En cual directorio desea buscar?\n 1- A domicilio\t 2- En restaurante\n";
                cin >> temp;
                cin.ignore();
                if(temp == 1){
                    searchByNameTake();
                }
                else if(temp == 2){
                    searchByNameHouse();
                }
                break;
            case 7:
                if(administrator == true){
                    int deleteCheck;
                    cout << "Que tipo de orden desea borrar?\n 1- A Domicilio\t 2- En restaurante\n";
                    cin >> deleteCheck;
                    cin.ignore();
                    switch(deleteCheck){
                        case 1:
                            deleteOrderTakeOut();
                            break;
                        case 2:
                            deleteOrderHouse();
                            break;
                        default:
                            break;
                    }
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

void addTakeOut(){
    takeOut auxOrder;
    int aux;
    bool cont = true;
    mainDish auxDish;
    appetizer auxAppe;
    drink auxDrink;
    //Adding orders 'to go'/delivery.
    auxOrder.price = 0;
    cout << "Por favor digite su nombre.\n Ingrese el primer nombre.\n";
    getline(cin, auxOrder.clientName.firstName);

    cout << "Ingrese el segundo nombre.\n";
    getline(cin, auxOrder.clientName.middleName);

    cout << "Ingrese el primer apellido.\n";
    getline(cin, auxOrder.clientName.surName);

    cout << "Ingrese el segundo apellido.\n";
    getline(cin, auxOrder.clientName.lastName);
            
    cout << "Por favor digite su direccion.\n Ingrese el numero de casa.\n";
    getline(cin, auxOrder.clientAddress.houseNumber);

    cout << "Ingrese la colonia.\n";
    getline(cin, auxOrder.clientAddress.neighborhood);

    cout << "Ingrese el municipio.\n";
    getline(cin, auxOrder.clientAddress.county);

    cout << "Ingrese el departamento.\n";
    getline(cin, auxOrder.clientAddress.state);

    cout << "Por favor digite su numero de telefono, con el formato XXXX-XXXX: \n";
    getline(cin, auxOrder.clientPhoneNumber);

    do{
        cont = true;
        cout << "Entrada\n";
        cout << "\t1. Palitroque\n";
        cout << "\t2. Pan con ajo\n";
        cout << "\t3. Palitos de queso\n";
        cout << "Su opcion: ";
        cin >> aux;
        cin.ignore();
        switch(aux){
            case 1: 
                auxAppe = appetizer::pizzaRolls;
                auxOrder.price += 3.99;
                auxOrder.orderAppe.insert(auxOrder.orderAppe.end(), auxAppe);
                break;
            case 2:
                auxAppe = appetizer::garlicBread;
                auxOrder.price += 2.99;
                auxOrder.orderAppe.insert(auxOrder.orderAppe.end(), auxAppe);
                break;
            case 3:
                auxAppe = appetizer::cheeseSticks;
                auxOrder.price += 3.99;
                auxOrder.orderAppe.insert(auxOrder.orderAppe.end(), auxAppe);
                break;
            default:
                cout << "Por favor escoga una opcion valida.\n";
                break;
        }
        cout << "Continuar?\n \t1. Si\n \t2. No\n";
        cin >> aux;
        if(aux == 2){
            cont = false;
        }
    }while(cont);
    do{
        cont = true;
        cout << "Plato principal\n";
        cout << "\t1. Pizza\n";
        cout << "\t2. Pasta\n";
        cout << "\t3. Lasagna\n";
        cout << "Su opcion: ";
        cin >> aux;
        cin.ignore();
        switch(aux){
            case 1:
                auxDish = mainDish::pizza;
                auxOrder.price += 6.99;
                auxOrder.orderDish.insert(auxOrder.orderDish.end(), auxDish);
                break;
            case 2:
                auxDish = mainDish::pasta;
                auxOrder.price += 9.99;
                auxOrder.orderDish.insert(auxOrder.orderDish.end(), auxDish);
                break;
            case 3:
                auxDish = mainDish::lasagna;
                auxOrder.price += 8.99;
                auxOrder.orderDish.insert(auxOrder.orderDish.end(), auxDish);
                break;
            default:
                cout << "Por favor escoga una opcion valida.\n";
                break;
        }
        cout << "Continuar?\n \t1. Si\n \t2. No\n";
        cin >> aux;
        if(aux == 2){
            cont = false;
        }
    }while(cont);
    do{
        cout << "Bebida\n";
        cout << "\t1. Cerveza\n";
        cout << "\t2. Te\n";
        cout << "\t3. Soda\n";
        cout << "Su opcion: ";
        cin >> aux;
        cin.ignore();
        switch(aux){
            case 1:
                auxDrink = drink::beer;
                auxOrder.price += 2.50;
                auxOrder.orderDrink.insert(auxOrder.orderDrink.end(), auxDrink);
                break;
            case 2:
                auxDrink = drink::tea;
                auxOrder.price += 1.99;
                auxOrder.orderDrink.insert(auxOrder.orderDrink.end(), auxDrink);
                break;
            case 3:
                auxDrink = drink::soda;
                auxOrder.price += 0.99;
                auxOrder.orderDrink.insert(auxOrder.orderDrink.end(), auxDrink);
                break;
            default:
                cout << "Por favor escoga una opcion valida.\n";
                break;
        }
        cout << "Continuar?\n \t1. Si\n \t2. No\n";
        cin >> aux;
        if(aux == 2){
            cont = false;
        }
    }while(cont);
    do{
        cont = true;
        cout << "Metodo de pago\n";
        cout << "\t1. Efectivo\n";
        cout << "\t2. Tarjeta\n";
        cout << "Su opcion: ";
        cin >> aux;
        cin.ignore();
        switch(aux){
            case 1:
                auxOrder.orderMethod = paymentMethod::cash;
                break;
            case 2:
                auxOrder.orderMethod = paymentMethod::creditCard;
                break;
            default:
                break;
        }
    }while(aux != 1 && aux != 2);

    takeOrder.insert(takeOrder.end() ,auxOrder);
    cout << "Su total es: " << auxOrder.price << endl;
}
        
void addHouseOrder(){
    inHouseOrder auxOrder;
    auxOrder.price = 0;
    bool cont = true;
    int aux;
    mainDish auxDish;
    appetizer auxAppe;
    drink auxDrink;
    //Adding orders in restaurant.
    cout << "Por favor digite su nombre.\n Ingrese el primer nombre.\n";
    getline(cin, auxOrder.clientName.firstName);

    cout << "Ingrese el segundo nombre.\n";
    getline(cin, auxOrder.clientName.middleName);

    cout << "Ingrese el primer apellido.\n";
    getline(cin, auxOrder.clientName.surName);

    cout << "Ingrese el segundo apellido.\n";
    getline(cin, auxOrder.clientName.lastName);
            
    cout << "Por favor indique el numero de personas en la mesa.\n";
    cin >> auxOrder.clientsPerTable;

    do{
        cont = true;
        cout << "Entrada\n";
        cout << "\t1. Palitroque\n";
        cout << "\t2. Pan con ajo\n";
        cout << "\t3. Palitos de queso\n";
        cout << "Su opcion: ";
        cin >> aux;
        cin.ignore();
        switch(aux){
            case 1: 
                auxAppe = appetizer::pizzaRolls;
                auxOrder.price += 3.99;
                auxOrder.orderAppe.insert(auxOrder.orderAppe.end(), auxAppe);
                break;
            case 2:
                auxAppe = appetizer::garlicBread;
                auxOrder.price += 2.99;
                auxOrder.orderAppe.insert(auxOrder.orderAppe.end(), auxAppe);
                break;
            case 3:
                auxAppe = appetizer::cheeseSticks;
                auxOrder.price += 3.99;
                auxOrder.orderAppe.insert(auxOrder.orderAppe.end(), auxAppe);
                break;
            default:
                cout << "Por favor escoga una opcion valida.\n";
                break;
        }
        cout << "Continuar?\n \t1. Si\n \t2. No\n";
        cin >> aux;
        if(aux == 2){
            cont = false;
        }
    }while(cont);
    do{
        cont = true;
        cout << "Plato principal\n";
        cout << "\t1. Pizza\n";
        cout << "\t2. Pasta\n";
        cout << "\t3. Lasagna\n";
        cout << "Su opcion: ";
        cin >> aux;
        cin.ignore();
        switch(aux){
            case 1:
                auxDish = mainDish::pizza;
                auxOrder.price += 6.99;
                auxOrder.orderDish.insert(auxOrder.orderDish.end(), auxDish);
                break;
            case 2:
                auxDish = mainDish::pasta;
                auxOrder.price += 9.99;
                auxOrder.orderDish.insert(auxOrder.orderDish.end(), auxDish);
                break;
            case 3:
                auxDish = mainDish::lasagna;
                auxOrder.price += 8.99;
                auxOrder.orderDish.insert(auxOrder.orderDish.end(), auxDish);
                break;
            default:
                cout << "Por favor escoga una opcion valida.\n";
                break;
        }
        cout << "Continuar?\n \t1. Si\n \t2. No\n";
        cin >> aux;
        if(aux == 2){
            cont = false;
        }
    }while(cont);

    do{
        cont = true;
        cout << "Bebida\n";
        cout << "\t1. Cerveza\n";
        cout << "\t2. Te\n";
        cout << "\t3. Soda\n";
        cout << "Su opcion: ";
        cin >> aux;
        cin.ignore();
        switch(aux){
            case 1:
                auxDrink = drink::beer;
                auxOrder.price += 2.50;
                auxOrder.orderDrink.insert(auxOrder.orderDrink.end(), auxDrink);
                break;
            case 2:
                auxDrink = drink::tea;
                auxOrder.price += 1.99;
                auxOrder.orderDrink.insert(auxOrder.orderDrink.end(), auxDrink);
                break;
            case 3:
                auxDrink = drink::soda;
                auxOrder.price += 0.99;
                auxOrder.orderDrink.insert(auxOrder.orderDrink.end(), auxDrink);
                break;
            default:
                cout << "Por favor escoga una opcion valida.\n";
                break;
        }
        cout << "Continuar?\n \t1. Si\n \t2. No\n";
        cin >> aux;
        if(aux == 2){
            cont = false;
        }
    }while(cont);
    
    do{
        cout << "Metodo de pago\n";
        cout << "\t1. Efectivo\n";
        cout << "\t2. Tarjeta\n";
        cout << "Su opcion: ";
        cin >> aux;
        cin.ignore();
        switch(aux){
            case 1:
                auxOrder.orderMethod = paymentMethod::cash;
                break;
            case 2:
                auxOrder.orderMethod = paymentMethod::creditCard;
                break;
            default:
                break;
        }
    }while(aux != 1 && aux != 2);

    cout << "Su total es: " << auxOrder.price << endl;
}

void showTakeOuts(){
    for(int i = 0; i < takeOrder.size(); i++){
        cout << "Identificador de orden: " << takeOrder[i].id << endl;
        cout << "Primer nombre del cliente: " << takeOrder[i].clientName.firstName << endl;
        cout << "Segundo nombre del cliente: " << takeOrder[i].clientName.middleName << endl;
        cout << "Primer apellido del cliente: " << takeOrder[i].clientName.surName << endl;
        cout << "Segundo apellido del cliente: " << takeOrder[i].clientName.lastName << endl;
        cout << "Numero de casa: " << takeOrder[i].clientAddress.houseNumber << endl;
        cout << "Colonia: " << takeOrder[i].clientAddress.neighborhood << endl;
        cout << "Municipio: " << takeOrder[i].clientAddress.county << endl;
        cout << "Departamento: " << takeOrder[i].clientAddress.state << endl;
        cout << "Numero del cliente: " << takeOrder[i].clientPhoneNumber << endl;
        cout << "Plato(s) principal(es): " << endl;
        for(int j = 0; j < takeOrder[i].orderDish.size(); j++){
            cout << j << ": " << printDish[takeOrder[i].orderDish[j]] << endl;
        }
        cout << "Aperitivo(s): " << endl;
        for(int j = 0; j < takeOrder[i].orderAppe.size(); j++){
            cout << j << ": " << printDish[takeOrder[i].orderAppe[j]] << endl;
        }
        cout << "Bebida(s): " << endl;
        for(int j = 0; j < takeOrder[i].orderDrink.size(); j++){
            cout << j << ": " << printDish[takeOrder[i].orderDrink[j]] << endl;
        }
        cout << "Precio: " << takeOrder[i].price << endl;
        cout << "Metodo de pago: " << printMethod[takeOrder[i].orderMethod] << endl;
    }
}

void showHouseOrders(){
    string temp;
    for(int i = 0; i < houseOrder.size(); i++){
        cout << "Identificador de orden: " << houseOrder[i].id << endl;
        cout << "Primer nombre del cliente: " << houseOrder[i].clientName.firstName << endl;
        cout << "Segundo nombre del cliente: " << houseOrder[i].clientName.middleName << endl;
        cout << "Primer apellido del cliente: " << houseOrder[i].clientName.surName << endl;
        cout << "Segundo apellido del cliente: " << houseOrder[i].clientName.lastName << endl;
        cout << "Personas en la mesa: " << houseOrder[i].clientsPerTable << endl;
        cout << "Plato(s) principal(es): " << endl;
        for(int j = 0; j < houseOrder[i].orderDish.size(); j++){
            cout << j << ": " << printDish[houseOrder[i].orderDish[j]] << endl;
        }
        cout << "Aperitivo(s): " << endl;
        for(int j = 0; j < houseOrder[i].orderAppe.size(); j++){
            cout << j << ": " << printDish[houseOrder[i].orderAppe[j]] << endl;
        }
        cout << "Bebida(s): " << endl;
        for(int j = 0; j < houseOrder[i].orderDrink.size(); j++){
            cout << j << ": " << printDish[houseOrder[i].orderDrink[j]] << endl;
        }
        cout << "Precio: " << houseOrder[i].price << endl;
        cout << "Metodo de pago: " << printMethod[houseOrder[i].orderMethod] << endl;
    }
}

void showTotalPrice(){
    //Showing total price using dispatched orders
    float totalPrice = 0;
    for(int i = 0; i < dispatchedTakeOut.size(); i++){
        totalPrice += dispatchedTakeOut[i].price;
    }
    for(int i = 0; i < dispatchedHouse.size(); i++){
        totalPrice += dispatchedHouse[i].price;
    }
    cout << "Las ganancias de hoy son: " << totalPrice << "$\n";
}

void searchByNameTake(){
    //Function to find order by first name, last name
    string searchedName, searchedLast;
    bool found = false, cont = true;
    int temp = 0, userInput;
    appetizer auxAppe;
    mainDish auxDish;
    drink auxDrink;
    cout << "Ingrese el primer nombre de la orden que desea encontrar.\n";
    getline(cin, searchedName);
    cout << "Ingrese el ultimo apellido de la orden que desea encontrar.\n";
    getline(cin, searchedLast);

    for(int i = 0; i < takeOrder.size(); i++){
        int aux = 0;
        if(searchedName == takeOrder[i].clientName.firstName && searchedLast == takeOrder[i].clientName.lastName){
            found = true;
            cout << "Orden encontrada! El identificador de la orden es: " << takeOrder[i].id << " .\n";
            cout << "Desea cambiar algo?\n 1- Si\t 2- No\n";
            cin >> userInput;
            if(userInput == 1){
                while(temp != 6){
                    cout << "Digite el numero de la opcion deseada.\n";
                    cout << "\t1- Nombre." << endl;
                    cout << "\t2- Direccion." << endl;
                    cout << "\t3- Numero de telefono." << endl;
                    cout << "\t4- Orden." << endl;
                    cout << "\t5- Metodo de pago." << endl;
                    cout << "\t6- Regresar." << endl;
                    cin >> temp;
                    switch(temp){
                        case 1:
                            cout << "Por favor digite su nombre.\n Ingrese el primer nombre.\n";
                            cin.ignore();
                            getline(cin, takeOrder[i].clientName.firstName);

                            cout << "Ingrese el segundo nombre.\n";
                            getline(cin, takeOrder[i].clientName.middleName);

                            cout << "Ingrese el primer apellido.\n";
                            getline(cin, takeOrder[i].clientName.surName);

                            cout << "Ingrese el segundo apellido.\n";
                            getline(cin, takeOrder[i].clientName.lastName);
                            break;
                        case 2:
                            cout << "Por favor digite su direccion.\n Ingrese el numero de casa.\n";
                            cin.ignore();
                            getline(cin, takeOrder[i].clientAddress.houseNumber);

                            cout << "Ingrese la colonia.\n";
                            getline(cin, takeOrder[i].clientAddress.neighborhood);

                            cout << "Ingrese el municipio.\n";
                            getline(cin, takeOrder[i].clientAddress.county);

                            cout << "Ingrese el departamento.\n";
                            getline(cin, takeOrder[i].clientAddress.state);
                            break;
                        case 3:
                            cout << "Por favor digite su numero de telefono, con el formato XXXX-XXXX: \n";
                            cin.ignore();
                            getline(cin, takeOrder[i].clientPhoneNumber);
                            break;
                        case 4:
                            takeOrder[i].price = 0;
                            takeOrder[i].orderDish.clear();
                            takeOrder[i].orderDish.shrink_to_fit();
                            takeOrder[i].orderAppe.clear();
                            takeOrder[i].orderAppe.shrink_to_fit();
                            takeOrder[i].orderDrink.clear();
                            takeOrder[i].orderDrink.shrink_to_fit();
                            do{
                                cont = true;
                                cout << "Entrada\n";
                                cout << "\t1. Palitroque\n";
                                cout << "\t2. Pan con ajo\n";
                                cout << "\t3. Palitos de queso\n";
                                cout << "Su opcion: ";
                                cin >> aux;
                                cin.ignore();
                                switch(aux){
                                    case 1: 
                                        auxAppe = appetizer::pizzaRolls;
                                        takeOrder[i].price += 3.99;
                                        takeOrder[i].orderAppe.insert(takeOrder[i].orderAppe.end(), auxAppe);
                                        break;
                                    case 2:
                                        auxAppe = appetizer::garlicBread;
                                        takeOrder[i].price += 2.99;
                                        takeOrder[i].orderAppe.insert(takeOrder[i].orderAppe.end(), auxAppe);
                                        break;
                                    case 3:
                                        auxAppe = appetizer::cheeseSticks;
                                        takeOrder[i].price += 3.99;
                                        takeOrder[i].orderAppe.insert(takeOrder[i].orderAppe.end(), auxAppe);
                                        break;
                                    default:
                                        cout << "Por favor escoga una opcion valida.\n";
                                        break;
                                }
                                cout << "Continuar?\n \t1. Si\n \t2. No\n";
                                cin >> aux;
                                if(aux == 2){
                                    cont = false;
                                }
                            }while(cont);
                            do{
                                cont = true;
                                cout << "Plato principal\n";
                                cout << "\t1. Pizza\n";
                                cout << "\t2. Pasta\n";
                                cout << "\t3. Lasagna\n";
                                cout << "Su opcion: ";
                                cin >> aux;
                                cin.ignore();
                                switch(aux){
                                    case 1:
                                        auxDish = mainDish::pizza;
                                        takeOrder[i].price += 6.99;
                                        takeOrder[i].orderDish.insert(takeOrder[i].orderDish.end(), auxDish);
                                        break;
                                    case 2:
                                        auxDish = mainDish::pasta;
                                        takeOrder[i].price += 9.99;
                                        takeOrder[i].orderDish.insert(takeOrder[i].orderDish.end(), auxDish);
                                        break;
                                    case 3:
                                        auxDish = mainDish::lasagna;
                                        takeOrder[i].price += 8.99;
                                        takeOrder[i].orderDish.insert(takeOrder[i].orderDish.end(), auxDish);
                                        break;
                                    default:
                                        cout << "Por favor escoga una opcion valida.\n";
                                        break;
                                }
                                cout << "Continuar?\n \t1. Si\n \t2. No\n";
                                cin >> aux;
                                if(aux == 2){
                                    cont = false;
                                }
                            }while(cont);

                            do{
                                cont = true;
                                cout << "Bebida\n";
                                cout << "\t1. Cerveza\n";
                                cout << "\t2. Te\n";
                                cout << "\t3. Soda\n";
                                cout << "Su opcion: ";
                                cin >> aux;
                                cin.ignore();
                                switch(aux){
                                    case 1:
                                        auxDrink = drink::beer;
                                        takeOrder[i].price += 2.50;
                                        takeOrder[i].orderDrink.insert(takeOrder[i].orderDrink.end(), auxDrink);
                                        break;
                                    case 2:
                                        auxDrink = drink::tea;
                                        takeOrder[i].price += 1.99;
                                        takeOrder[i].orderDrink.insert(takeOrder[i].orderDrink.end(), auxDrink);            
                                        break;
                                    case 3:
                                        auxDrink = drink::soda;
                                        takeOrder[i].price += 0.99;
                                        takeOrder[i].orderDrink.insert(takeOrder[i].orderDrink.end(), auxDrink);
                                        break;
                                    default:
                                        cout << "Por favor escoga una opcion valida.\n";
                                        break;
                                }
                                cout << "Continuar?\n \t1. Si\n \t2. No\n";
                                cin >> aux;
                                if(aux == 2){
                                    cont = false;
                                }
                            }while(cont);
                            break;
                        case 5:
                            do{
                                cout << "Metodo de pago\n";
                                cout << "\t1. Efectivo\n";
                                cout << "\t2. Tarjeta\n";
                                cout << "Su opcion: ";
                                cin >> aux;
                                cin.ignore();
                                switch(aux){
                                    case 1:
                                        takeOrder[i].orderMethod = paymentMethod::cash;
                                        break;
                                    case 2:
                                        takeOrder[i].orderMethod = paymentMethod::creditCard;
                                        break;
                                    default:
                                        break;
                                }
                            }while(aux != 1 && aux != 2);
                            break;
                        case 6:
                            cin.ignore();
                            break;
                        default:
                            cout << "error" << endl;
                            break;
                    }
                }
            }
            else{}
        }
    }
    if(found == false){
        cout << "No se encontro esa orden.\n";
    }
}

void searchByNameHouse(){
    //Function to find order by first name, last name
    string searchedName, searchedLast;
    bool found = false, cont = true;
    int temp = 0, userInput;
    int aux = 0;
    appetizer auxAppe;
    mainDish auxDish;
    drink auxDrink;
    cout << "Ingrese el primer nombre de la orden que desea encontrar.\n";
    getline(cin, searchedName);
    cout << "Ingrese el ultimo apellido de la orden que desea encontrar.\n";
    getline(cin, searchedLast);

    for(int i = 0; i < houseOrder.size(); i++){
        if(searchedName == houseOrder[i].clientName.firstName && searchedLast == houseOrder[i].clientName.lastName){
            cout << "Orden encontrada! El identificador de la orden es: " << houseOrder[i].id << " .\n";
            cout << "Desea cambiar algo?\n 1- Si\t 2- No\n";
            cin >> userInput;
            if(userInput == 1){
                while(temp != 6){
                    cout << "Digite el numero de la opcion deseada.\n";
                    cout << "\t1- Nombre." << endl;
                    cout << "\t2- Numero de clientes en la mesa." << endl;
                    cout << "\t3- Orden." << endl;
                    cout << "\t4- Metodo de pago." << endl;
                    cout << "\t5- Regresar." << endl;
                    cin >> temp;
                    switch(temp){
                        case 1:
                            cout << "Por favor digite su nombre.\n Ingrese el primer nombre.\n";
                            cin.ignore();
                            getline(cin, houseOrder[i].clientName.firstName);

                            cout << "Ingrese el segundo nombre.\n";
                            getline(cin, houseOrder[i].clientName.middleName);

                            cout << "Ingrese el primer apellido.\n";
                            getline(cin, houseOrder[i].clientName.surName);

                            cout << "Ingrese el segundo apellido.\n";
                            getline(cin, houseOrder[i].clientName.lastName);
                            break;
                        case 2:
                            cout << "Por favor digite el numero de clientes en la mesa: \n";
                            cin.ignore();
                            cin >> houseOrder[i].clientsPerTable;
                            break;
                        case 3:
                            houseOrder[i].price = 0;
                            houseOrder[i].orderDish.clear();
                            houseOrder[i].orderDish.shrink_to_fit();
                            houseOrder[i].orderAppe.clear();
                            houseOrder[i].orderAppe.shrink_to_fit();
                            houseOrder[i].orderDrink.clear();
                            houseOrder[i].orderDrink.shrink_to_fit();
                            do{
                                cont = true;
                                cout << "Entrada\n";
                                cout << "\t1. Palitroque\n";
                                cout << "\t2. Pan con ajo\n";
                                cout << "\t3. Palitos de queso\n";
                                cout << "Su opcion: ";
                                cin >> aux;
                                cin.ignore();
                                switch(aux){
                                    case 1: 
                                        auxAppe = appetizer::pizzaRolls;
                                        houseOrder[i].price += 3.99;
                                        houseOrder[i].orderAppe.insert(houseOrder[i].orderAppe.end(), auxAppe);
                                        break;
                                    case 2:
                                        auxAppe = appetizer::garlicBread;
                                        houseOrder[i].price += 2.99;
                                        houseOrder[i].orderAppe.insert(houseOrder[i].orderAppe.end(), auxAppe);
                                        break;
                                    case 3:
                                        auxAppe = appetizer::cheeseSticks;
                                        houseOrder[i].price += 3.99;
                                        houseOrder[i].orderAppe.insert(houseOrder[i].orderAppe.end(), auxAppe);
                                        break;
                                    default:
                                        cout << "Por favor escoga una opcion valida.\n";
                                        break;
                                }
                                cout << "Continuar?\n \t1. Si\n \t2. No\n";
                                cin >> aux;
                                if(aux == 2){
                                    cont = false;
                                }
                            }while(cont);
                            do{
                                cont = true;
                                cout << "Plato principal\n";
                                cout << "\t1. Pizza\n";
                                cout << "\t2. Pasta\n";
                                cout << "\t3. Lasagna\n";
                                cout << "Su opcion: ";
                                cin >> aux;
                                cin.ignore();
                                switch(aux){
                                    case 1:
                                        auxDish = mainDish::pizza;
                                        houseOrder[i].price += 6.99;
                                        houseOrder[i].orderDish.insert(takeOrder[i].orderDish.end(), auxDish);
                                        break;
                                    case 2:
                                        auxDish = mainDish::pasta;
                                        houseOrder[i].price += 9.99;
                                        houseOrder[i].orderDish.insert(takeOrder[i].orderDish.end(), auxDish);
                                        break;
                                    case 3:
                                        auxDish = mainDish::lasagna;
                                        houseOrder[i].price += 8.99;
                                        houseOrder[i].orderDish.insert(takeOrder[i].orderDish.end(), auxDish);
                                        break;
                                    default:
                                        cout << "Por favor escoga una opcion valida.\n";
                                        break;
                                }
                                cout << "Continuar?\n \t1. Si\n \t2. No\n";
                                cin >> aux;
                                if(aux == 2){
                                    cont = false;
                                }
                            }while(cont);

                            do{
                                cont = true;
                                cout << "Bebida\n";
                                cout << "\t1. Cerveza\n";
                                cout << "\t2. Te\n";
                                cout << "\t3. Soda\n";
                                cout << "Su opcion: ";
                                cin >> aux;
                                cin.ignore();
                                switch(aux){
                                    case 1:
                                        auxDrink = drink::beer;
                                        houseOrder[i].price += 2.50;
                                        houseOrder[i].orderDrink.insert(takeOrder[i].orderDrink.end(), auxDrink);
                                        break;
                                    case 2:
                                        auxDrink = drink::tea;
                                        houseOrder[i].price += 1.99;
                                        houseOrder[i].orderDrink.insert(takeOrder[i].orderDrink.end(), auxDrink);            
                                        break;
                                    case 3:
                                        auxDrink = drink::soda;
                                        houseOrder[i].price += 0.99;
                                        houseOrder[i].orderDrink.insert(takeOrder[i].orderDrink.end(), auxDrink);
                                        break;
                                    default:
                                        cout << "Por favor escoga una opcion valida.\n";
                                        break;
                                }
                                cout << "Continuar?\n \t1. Si\n \t2. No\n";
                                cin >> aux;
                                if(aux == 2){
                                    cont = false;
                                }
                            }while(cont);
                            break;
                        case 4:
                            do{
                                cout << "Metodo de pago\n";
                                cout << "\t1. Efectivo\n";
                                cout << "\t2. Tarjeta\n";
                                cout << "Su opcion: ";
                                cin >> aux;
                                cin.ignore();
                                switch(aux){
                                    case 1:
                                        houseOrder[i].orderMethod = cash;
                                        break;
                                    case 2:
                                        houseOrder[i].orderMethod = creditCard;
                                        break;
                                    default:
                                        break;
                                }
                            }while(aux != 1 && aux != 2);
                            break;
                        case 5:
                            cin.ignore();
                            break;
                        default:
                            cout << "error" << endl;
                            break;
                    }
                }
            }
            else{}
        }
    }
    if(found == false){
        cout << "No se encontro la orden.\n";
    }
}

void deleteOrderTakeOut(){
    //Function to delete orders
    int userID, confirmation;
    bool found = false;
    cout << "Por favor ingrese el identificador de la orden.\n";
    cin >> userID;
    for(int i = 0; i < takeOrder.size(); i++){
        if(takeOrder[i].id == userID){
            found = true;
            cout << "Esta seguro que desea borrar esta orden?\n 1- Si\t 2- No\n";
            cin >> confirmation;
            if(confirmation == 1){
                for(auto iter = takeOrder.begin(); iter != takeOrder.end(); ++iter){
                    if(iter->id == userID){
                        iter = takeOrder.erase(iter);
                        break;
                    }
                }
            }
            else{}
        }
    }
    if(found == false){
        cout << "No se encontro la orden.\n";
    }
}

void deleteOrderHouse(){
    //Function to delete orders
    int userID, confirmation;
    bool found = false;
    cout << "Por favor ingrese el identificador de la orden.\n";
    cin >> userID;
    for(int i = 0; i < houseOrder.size(); i++){
        if(houseOrder[i].id == userID){
            found = true;
            cout << "Esta seguro que desea borrar esta orden?\n 1- Si\t 2- No\n";
            cin >> confirmation;
            cin.ignore();
            if(confirmation == 1){
                for(auto iter = houseOrder.begin(); iter != houseOrder.end(); ++iter){
                    if(iter->id == userID){
                        iter = houseOrder.erase(iter);
                        break;
                    }
                }
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
    while(inMenu == true){
        mainMenu(&inMenu);
    }
    return 0;
}