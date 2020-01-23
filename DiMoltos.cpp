#include <iostream>
#include <string>

//Define declaration
#define password "recursion"

using namespace std;


//ENUM declaration
enum mainDish{pizza = 0, pasta, lasagna, n};
enum drink{beer = 0, tea, soda, o};
enum appetizer{pizzaRolls = 0, garlicBread, cheeseSticks, ne};
enum paymentMethod{cash = 0, creditCard, nu};

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
    mainDish orderDish;
    appetizer orderAppe;
    drink orderDrink;
    float price;
    paymentMethod orderMethod;
};

struct inHouseOrder{
    int id;
    name clientName;
    int clientsPerTable;
    mainDish orderDish;
    appetizer orderAppe;
    drink orderDrink;
    float price;
    paymentMethod orderMethod;
};

//Global Variables
int size1 = 0, size2 = 0;
string printDish[] = {"Pizza", "Pasta", "Lasagna", "none"};
string printAppe[] = {"Rollos de Pizza", "Pan con ajo", "Palitos de queso", "none"};
string printDrink[] = {"Cerveza", "Te", "Gaseosa", "none"};
string printMethod[] = {"Efectivo", "Tarjeta", "none"};


//Prototyping functions
void addTakeOut(takeOut *order[]);
void addHouseOrder(inHouseOrder *order[]);
void showTakeOuts(takeOut *order[]);
void showHouseOrders(inHouseOrder *order[]);
void showTotalPrice(takeOut *price1[], inHouseOrder *price2[], float *totalPrice);
void searchByName(takeOut *searched[]);
void searchByName(inHouseOrder *searched[]);
void deleteOrder(takeOut *searched[]);
void deleteOrder(inHouseOrder *searched[]);

void mainMenu(bool *outerCheck){
    //Main Menu.
    //Local variables.
    string userInput;
    bool correctPass = false, administrator = false;
    int userOption, temp = 0;
    float totalPrice;
    if(size1 == 0 && size2 == 0){
        cout << "Con cuantas ordenes se trabajara a domicilio?\n";
        cin >> size1;
        cout << "Con cuantas ordenes se trabajara en el restaurante?\n";
        cin >> size2;
        cin.ignore();
    }
    
    if(size1 < 1 || size2 < 1){
        cout << "Por favor digite valores positivos.\n Con cuantas ordenes se trabajara a domicilio?\n";
        cin >> size1;
        cout << "Con cuantas ordenes se trabajara en el restaurante?\n";
        cin >> size2;
        cin.ignore();
    }

    takeOut *takeOrder;
    inHouseOrder *houseOrder;

    takeOrder = new takeOut[size1];
    houseOrder = new inHouseOrder[size2];

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

    for(int i = 0; i < size1; i++){
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
        takeOrder[i].orderAppe = appetizer::ne;
        takeOrder[i].orderDish = mainDish::n;
        takeOrder[i].orderDrink = drink::o;
        takeOrder[i].price = 0;
        takeOrder[i].orderMethod = paymentMethod::nu;
    }
    for(int i = 0; i < size2; i++){
        houseOrder[i].id = 1001 + i;
        houseOrder[i].clientName.firstName = "";
        houseOrder[i].clientName.middleName = "";
        houseOrder[i].clientName.surName = "";
        houseOrder[i].clientName.lastName = "";
        houseOrder[i].clientsPerTable = 0;
        houseOrder[i].orderAppe = appetizer::ne;
        houseOrder[i].orderDish = mainDish::n;
        houseOrder[i].orderDrink = drink::o;
        houseOrder[i].price = 0;
        houseOrder[i].orderMethod = paymentMethod::nu;
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
                addTakeOut(&takeOrder);
                break;
            case 2:
                addHouseOrder(&houseOrder);
                break;
            case 3:
                showTakeOuts(&takeOrder);
                break;
            case 4:
                showHouseOrders(&houseOrder);
                break;
            case 5:
                totalPrice = 0;
                showTotalPrice(&takeOrder, &houseOrder, &totalPrice);
                break;
            case 6:
                cout << "En cual directorio desea buscar?\n 1- A domicilio\t 2- En restaurante\n";
                cin >> temp;
                cin.ignore();
                if(temp == 1){
                    searchByName(&takeOrder);
                }
                else if(temp == 2){
                    searchByName(&houseOrder);
                }
                break;
            case 7:
                if(administrator == true){
                    int deleteCheck;
                    cout << "Que tipo de orden desea borrar?\n 1- A Domicilio\t 2- En restaurante\n";
                    cin >> deleteCheck;
                    switch(deleteCheck){
                        case 1:
                            deleteOrder(&takeOrder);
                            break;
                        case 2:
                            deleteOrder(&houseOrder);
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

void addTakeOut(takeOut *order[]){
    bool type = true, added = false;
    int currentOrder = 0, aux = 0;
    cout << "Que numero de orden a domicilio es esta?\n";
    cin >> currentOrder;
    cin.ignore();
    //Adding orders 'to go'/delivery.
    for (int i = 0; i < size1; i++){
        if((*order)[i].id == 1000 + currentOrder && (*order)[i].clientName.firstName == ""){
            (*order)[i].price = 0;
            cout << "Por favor digite su nombre.\n Ingrese el primer nombre.\n";
            getline(cin, (*order)[i].clientName.firstName);

            cout << "Ingrese el segundo nombre.\n";
            getline(cin, (*order)[i].clientName.middleName);

            cout << "Ingrese el primer apellido.\n";
            getline(cin, (*order)[i].clientName.surName);

            cout << "Ingrese el segundo apellido.\n";
            getline(cin, (*order)[i].clientName.lastName);
            
            cout << "Por favor digite su direccion.\n Ingrese el numero de casa.\n";
            getline(cin, (*order)[i].clientAddress.houseNumber);

            cout << "Ingrese la colonia.\n";
            getline(cin, (*order)[i].clientAddress.neighborhood);

            cout << "Ingrese el municipio.\n";
            getline(cin, (*order)[i].clientAddress.county);

            cout << "Ingrese el departamento.\n";
            getline(cin, (*order)[i].clientAddress.state);

            cout << "Por favor digite su numero de telefono, con el formato XXXX-XXXX: \n";
            getline(cin, (*order)[i].clientPhoneNumber);

            do{
                cout << "Entrada\n";
                cout << "\t1. Palitroque\n";
                cout << "\t2. Pan con ajo\n";
                cout << "\t3. Palitos de queso\n";
                cout << "Su opcion: ";
                cin >> aux;
                cin.ignore();
                switch(aux){
                    case 1: 
                        (*order)[i].orderAppe = appetizer::pizzaRolls;
                        (*order)[i].price += 3.99;
                        break;
                    case 2:
                        (*order)[i].orderAppe = appetizer::garlicBread;
                        (*order)[i].price += 2.99;
                        break;
                    case 3:
                        (*order)[i].orderAppe = appetizer::cheeseSticks;
                        (*order)[i].price += 3.99;
                        break;
                    default:
                        cout << "Por favor escoga una opcion valida.\n";
                        break;
                }
            }while(aux != 1 && aux != 2 && aux != 3);
            do{
                cout << "Plato principal\n";
                cout << "\t1. Pizza\n";
                cout << "\t2. Pasta\n";
                cout << "\t3. Lasagna\n";
                cout << "Su opcion: ";
                cin >> aux;
                cin.ignore();
                switch(aux){
                    case 1:
                        (*order)[i].orderDish = mainDish::pizza;
                        (*order)[i].price += 6.99;
                        break;
                    case 2:
                        (*order)[i].orderDish = mainDish::pasta;
                        (*order)[i].price += 9.99;
                        break;
                    case 3:
                        (*order)[i].orderDish = mainDish::lasagna;
                        (*order)[i].price += 8.99;
                        break;
                    default:
                        cout << "Por favor escoga una opcion valida.\n";
                        break;
                }
            }while(aux != 1 && aux != 2 && aux != 3);

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
                        (*order)[i].orderDrink = drink::beer;
                        (*order)[i].price += 2.50;
                        break;
                    case 2:
                        (*order)[i].orderDrink = drink::tea;
                        (*order)[i].price += 1.99;
                        break;
                    case 3:
                        (*order)[i].orderDrink = drink::soda;
                        (*order)[i].price += 0.99;
                        break;
                    default:
                        cout << "Por favor escoga una opcion valida.\n";
                        break;
                }
            }while(aux != 1 && aux != 2 && aux != 3);
            
            do{
                cout << "Metodo de pago\n";
                cout << "\t1. Efectivo\n";
                cout << "\t2. Tarjeta\n";
                cout << "Su opcion: ";
                cin >> aux;
                cin.ignore();
                switch(aux){
                    case 1:
                        (*order)[i].orderMethod = paymentMethod::cash;
                        break;
                    case 2:
                        (*order)[i].orderMethod = paymentMethod::creditCard;
                        break;
                    default:
                        break;
                }
            }while(aux != 1 && aux != 2);

            cout << "Su total es: " << (*order)[i].price << endl;
            added = true;
        }
        else if(added == true || i < size1 - 1){}
        else{
            cout << "Este numero de orden no es admitido dentro de esta sesion.\n";
        }   
    }
}
        
void addHouseOrder(inHouseOrder *order[]){
    bool type = true, added = false;
    int currentOrder = 0, aux = 0;
    cout << "Que numero de orden en restaurante es esta?\n";
    cin >> currentOrder;
    cin.ignore();
    //Adding orders in restaurant.
    for (int i = 0; i < size2; i++){
        if((*order)[i].id == 1000 + currentOrder && (*order)[i].clientName.firstName == ""){
            (*order)[i].price = 0;
            cout << "Por favor digite su nombre.\n Ingrese el primer nombre.\n";
            getline(cin, (*order)[i].clientName.firstName);

            cout << "Ingrese el segundo nombre.\n";
            getline(cin, (*order)[i].clientName.middleName);

            cout << "Ingrese el primer apellido.\n";
            getline(cin, (*order)[i].clientName.surName);

            cout << "Ingrese el segundo apellido.\n";
            getline(cin, (*order)[i].clientName.lastName);
            
            cout << "Por favor indique el numero de personas en la mesa.\n";
            cin >> (*order)[i].clientsPerTable;

            do{
                cout << "Entrada\n";
                cout << "\t1. Palitroque\n";
                cout << "\t2. Pan con ajo\n";
                cout << "\t3. Palitos de queso\n";
                cout << "Su opcion: ";
                cin >> aux;
                cin.ignore();
                switch(aux){
                    case 1: 
                        (*order)[i].orderAppe = appetizer::pizzaRolls;
                        (*order)[i].price += 3.99;
                        break;
                    case 2:
                        (*order)[i].orderAppe = appetizer::garlicBread;
                        (*order)[i].price += 2.99;
                        break;
                    case 3:
                        (*order)[i].orderAppe = appetizer::cheeseSticks;
                        (*order)[i].price += 3.99;
                        break;
                    default:
                        cout << "Por favor escoga una opcion valida.\n";
                        break;
                }
            }while(aux != 1 && aux != 2 && aux != 3);
            do{
                cout << "Plato principal\n";
                cout << "\t1. Pizza\n";
                cout << "\t2. Pasta\n";
                cout << "\t3. Lasagna\n";
                cout << "Su opcion: ";
                cin >> aux;
                cin.ignore();
                switch(aux){
                    case 1:
                        (*order)[i].orderDish = mainDish::pizza;
                        (*order)[i].price += 6.99;
                        break;
                    case 2:
                        (*order)[i].orderDish = mainDish::pasta;
                        (*order)[i].price += 9.99;
                        break;
                    case 3:
                        (*order)[i].orderDish = mainDish::lasagna;
                        (*order)[i].price += 8.99;
                        break;
                    default:
                        cout << "Por favor escoga una opcion valida.\n";
                        break;
                }
            }while(aux != 1 && aux != 2 && aux != 3);

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
                        (*order)[i].orderDrink = drink::beer;
                        (*order)[i].price += 2.50;
                        break;
                    case 2:
                        (*order)[i].orderDrink = drink::tea;
                        (*order)[i].price += 1.99;
                        break;
                    case 3:
                        (*order)[i].orderDrink = drink::soda;
                        (*order)[i].price += 0.99;
                        break;
                    default:
                        cout << "Por favor escoga una opcion valida.\n";
                        break;
                }
            }while(aux != 1 && aux != 2 && aux != 3);
            
            do{
                cout << "Metodo de pago\n";
                cout << "\t1. Efectivo\n";
                cout << "\t2. Tarjeta\n";
                cout << "Su opcion: ";
                cin >> aux;
                cin.ignore();
                switch(aux){
                    case 1:
                        (*order)[i].orderMethod = paymentMethod::cash;
                        break;
                    case 2:
                        (*order)[i].orderMethod = paymentMethod::creditCard;
                        break;
                    default:
                        break;
                }
            }while(aux != 1 && aux != 2);

            cout << "Su total es: " << (*order)[i].price << endl;
            added = true;    
        }
        else if(added == true || i < size2 - 1){
        }
        else{
            cout << "Este numero de orden no es admitido dentro de esta sesion.\n";
        }
    }
}

void showTakeOuts(takeOut *order[]){
    for(int i = 0; i < size1; i++){
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
        cout << "Plato principal: " << printDish[(*order)[i].orderDish] << endl;
        cout << "Aperitivo: " << printAppe[(*order)[i].orderAppe] << endl;
        cout << "Bebida: " << printDrink[(*order)[i].orderDrink] << endl;
        cout << "Precio: " << (*order)[i].price << endl;
        cout << "Metodo de pago: " << printMethod[(*order)[i].orderMethod] << endl;
    }
}

void showHouseOrders(inHouseOrder *order[]){
    string temp;
    for(int i = 0; i < size2; i++){
        cout << "Identificador de orden: " << (*order)[i].id << endl;
        cout << "Primer nombre del cliente: " << (*order)[i].clientName.firstName << endl;
        cout << "Segundo nombre del cliente: " << (*order)[i].clientName.middleName << endl;
        cout << "Primer apellido del cliente: " << (*order)[i].clientName.surName << endl;
        cout << "Segundo apellido del cliente: " << (*order)[i].clientName.lastName << endl;
        cout << "Personas en la mesa: " << (*order)[i].clientsPerTable << endl;
        cout << "Plato principal: " << printDish[(*order)[i].orderDish] << endl;
        cout << "Aperitivo: " << printAppe[(*order)[i].orderAppe] << endl;
        cout << "Bebida: " << printDrink[(*order)[i].orderDrink] << endl;
        cout << "Precio: " << (*order)[i].price << endl;
        cout << "Metodo de pago: " << printMethod[(*order)[i].orderMethod] << endl;
    }
}

void showTotalPrice(takeOut *price1[], inHouseOrder *price2[], float *totalPrice){
    for(int i = 0; i < size1; i++){
        *totalPrice += (*price1)[i].price;
    }
    for(int i = 0; i < size2; i++){
        *totalPrice += (*price2)[i].price;
    }
    cout << "El precio total es: " << *totalPrice << "$\n";
}

void searchByName(takeOut *searched[]){
    //Function to find order by first name, last name
    string searchedName, searchedLast;
    bool type = true, found = false;
    int temp = 0, userInput;
    cout << "Ingrese el primer nombre de la orden que desea encontrar.\n";
    getline(cin, searchedName);
    cout << "Ingrese el ultimo apellido de la orden que desea encontrar.\n";
    getline(cin, searchedLast);

    for(int i = 0; i < size1; i++){
        int aux = 0;
        if(searchedName == (*searched)[i].clientName.firstName && searchedLast == (*searched)[i].clientName.lastName){
            found = true;
            cout << "Orden encontrada! El identificador de la orden es: " << (*searched)[i].id << " .\n";
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
                            getline(cin, (*searched)[i].clientName.firstName);

                            cout << "Ingrese el segundo nombre.\n";
                            getline(cin, (*searched)[i].clientName.middleName);

                            cout << "Ingrese el primer apellido.\n";
                            getline(cin, (*searched)[i].clientName.surName);

                            cout << "Ingrese el segundo apellido.\n";
                            getline(cin, (*searched)[i].clientName.lastName);
                            break;
                        case 2:
                            cout << "Por favor digite su direccion.\n Ingrese el numero de casa.\n";
                            cin.ignore();
                            getline(cin, (*searched)[i].clientAddress.houseNumber);

                            cout << "Ingrese la colonia.\n";
                            getline(cin, (*searched)[i].clientAddress.neighborhood);

                            cout << "Ingrese el municipio.\n";
                            getline(cin, (*searched)[i].clientAddress.county);

                            cout << "Ingrese el departamento.\n";
                            getline(cin, (*searched)[i].clientAddress.state);
                            break;
                        case 3:
                            cout << "Por favor digite su numero de telefono, con el formato XXXX-XXXX: \n";
                            cin.ignore();
                            getline(cin, (*searched)[i].clientPhoneNumber);
                            break;
                        case 4:
                            (*searched)[i].price = 0;
                            do{
                                cout << "Entrada\n";
                                cout << "\t1. Palitroque\n";
                                cout << "\t2. Pan con ajo\n";
                                cout << "\t3. Palitos de queso\n";
                                cout << "Su opcion: ";
                                cin >> aux;
                                cin.ignore();
                                switch(aux){
                                    case 1: 
                                        (*searched)[i].orderAppe = appetizer::pizzaRolls;
                                        (*searched)[i].price += 3.99;
                                        break;
                                    case 2:
                                        (*searched)[i].orderAppe = appetizer::garlicBread;
                                        (*searched)[i].price += 2.99;
                                        break;
                                    case 3:
                                        (*searched)[i].orderAppe = appetizer::cheeseSticks;
                                        (*searched)[i].price += 3.99;
                                        break;
                                    default:
                                        cout << "Por favor escoga una opcion valida.\n";
                                        break;
                                }
                            }while(aux != 1 && aux != 2 && aux != 3);
                            do{
                                cout << "Plato principal\n";
                                cout << "\t1. Pizza\n";
                                cout << "\t2. Pasta\n";
                                cout << "\t3. Lasagna\n";
                                cout << "Su opcion: ";
                                cin >> aux;
                                cin.ignore();
                                switch(aux){
                                    case 1:
                                        (*searched)[i].orderDish = mainDish::pizza;
                                        (*searched)[i].price += 6.99;
                                        break;
                                    case 2:
                                        (*searched)[i].orderDish = mainDish::pasta;
                                        (*searched)[i].price += 9.99;
                                        break;
                                    case 3:
                                        (*searched)[i].orderDish = mainDish::lasagna;
                                        (*searched)[i].price += 8.99;
                                        break;
                                    default:
                                        cout << "Por favor escoga una opcion valida.\n";
                                        break;
                                }
                            }while(aux != 1 && aux != 2 && aux != 3);

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
                                        (*searched)[i].orderDrink = drink::beer;
                                        (*searched)[i].price += 2.50;
                                        break;
                                    case 2:
                                        (*searched)[i].orderDrink = drink::tea;
                                        (*searched)[i].price += 1.99;
                                        break;
                                    case 3:
                                        (*searched)[i].orderDrink = drink::soda;
                                        (*searched)[i].price += 0.99;
                                        break;
                                    default:
                                        cout << "Por favor escoga una opcion valida.\n";
                                        break;
                                }
                            }while(aux != 1 && aux != 2 && aux != 3);
                            
                            
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
                                        (*searched)[i].orderMethod = paymentMethod::cash;
                                        break;
                                    case 2:
                                        (*searched)[i].orderMethod = paymentMethod::creditCard;
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

void searchByName(inHouseOrder *searched[]){
    //Function to find order by first name, last name
    string searchedName, searchedLast;
    bool type = true;
    int temp = 0, userInput;
    int aux = 0;
    cout << "Ingrese el primer nombre de la orden que desea encontrar.\n";
    getline(cin, searchedName);
    cout << "Ingrese el ultimo apellido de la orden que desea encontrar.\n";
    getline(cin, searchedLast);

    for(int i = 0; i < size2; i++){
        if(searchedName == (*searched)[i].clientName.firstName && searchedLast == (*searched)[i].clientName.lastName){
            cout << "Orden encontrada! El identificador de la orden es: " << (*searched)[i].id << " .\n";
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
                            getline(cin, (*searched)[i].clientName.firstName);

                            cout << "Ingrese el segundo nombre.\n";
                            getline(cin, (*searched)[i].clientName.middleName);

                            cout << "Ingrese el primer apellido.\n";
                            getline(cin, (*searched)[i].clientName.surName);

                            cout << "Ingrese el segundo apellido.\n";
                            getline(cin, (*searched)[i].clientName.lastName);
                            break;
                        case 2:
                            cout << "Por favor digite el numero de clientes en la mesa: \n";
                            cin.ignore();
                            cin >> (*searched)[i].clientsPerTable;
                            break;
                        case 3:
                            (*searched)[i].price = 0;
                            do{
                                cout << "Entrada\n";
                                cout << "\t1. Palitroque\n";
                                cout << "\t2. Pan con ajo\n";
                                cout << "\t3. Palitos de queso\n";
                                cout << "Su opcion: ";
                                cin >> aux;
                                cin.ignore();
                                switch(aux){
                                    case 1: 
                                        (*searched)[i].orderAppe = pizzaRolls;
                                        (*searched)[i].price += 3.99;
                                        break;
                                    case 2:
                                        (*searched)[i].orderAppe = garlicBread;
                                        (*searched)[i].price += 2.99;
                                        break;
                                    case 3:
                                        (*searched)[i].orderAppe = cheeseSticks;
                                        (*searched)[i].price += 3.99;
                                        break;
                                    default:
                                        cout << "Por favor escoga una opcion valida.\n";
                                        break;
                                }
                            }while(aux != 1 && aux != 2 && aux != 3);
                            do{
                                cout << "Plato principal\n";
                                cout << "\t1. Pizza\n";
                                cout << "\t2. Pasta\n";
                                cout << "\t3. Lasagna\n";
                                cout << "Su opcion: ";
                                cin >> aux;
                                cin.ignore();
                                switch(aux){
                                    case 1:
                                        (*searched)[i].orderDish = pizza;
                                        (*searched)[i].price += 6.99;
                                        break;
                                    case 2:
                                        (*searched)[i].orderDish = pasta;
                                        (*searched)[i].price += 9.99;
                                        break;
                                    case 3:
                                        (*searched)[i].orderDish = lasagna;
                                        (*searched)[i].price += 8.99;
                                        break;
                                    default:
                                        cout << "Por favor escoga una opcion valida.\n";
                                        break;
                                }
                            }while(aux != 1 && aux != 2 && aux != 3);

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
                                        (*searched)[i].orderDrink = beer;
                                        (*searched)[i].price += 2.50;
                                        break;
                                    case 2:
                                        (*searched)[i].orderDrink = tea;
                                        (*searched)[i].price += 1.99;
                                        break;
                                    case 3:
                                        (*searched)[i].orderDrink = soda;
                                        (*searched)[i].price += 0.99;
                                        break;
                                    default:
                                        cout << "Por favor escoga una opcion valida.\n";
                                        break;
                                }
                            }while(aux != 1 && aux != 2 && aux != 3);
                            
                            
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
                                        (*searched)[i].orderMethod = cash;
                                        break;
                                    case 2:
                                        (*searched)[i].orderMethod = creditCard;
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
}

void deleteOrder(takeOut *searched[]){
    //Function to delete orders
    int userID, confirmation;
    bool found = false;
    cout << "Por favor ingrese el identificador de la orden.\n";
    cin >> userID;
    for(int i = 0; i < size1; i++){
        if((*searched)[i].id == userID){
            found = true;
            cout << "Esta seguro que desea borrar esta orden?\n 1- Si\t 2- No\n";
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
                (*searched)[i].orderAppe = appetizer::ne;
                (*searched)[i].orderDish = mainDish::n;
                (*searched)[i].orderDrink = drink::o;
                (*searched)[i].price = 0;
                (*searched)[i].orderMethod = paymentMethod::nu;
                cin.ignore();
            }
            else{
                cin.ignore();
            }
        }
    }
    if(found == false){
        cout << "No se encontro la orden.\n";
    }
}

void deleteOrder(inHouseOrder *searched[]){
    //Function to delete orders
    int userID, confirmation;
    bool found = false;
    cout << "Por favor ingrese el identificador de la orden.\n";
    cin >> userID;
    for(int i = 0; i < size2; i++){
        if((*searched)[i].id == userID){
            found = true;
            cout << "Esta seguro que desea borrar esta orden?\n 1- Si\t 2- No\n";
            cin >> confirmation;
            if(confirmation == 1){
                (*searched)[i].clientName.firstName = "";
                (*searched)[i].clientName.middleName = "";
                (*searched)[i].clientName.surName = "";
                (*searched)[i].clientName.lastName = "";
                (*searched)[i].clientsPerTable = 0;
                (*searched)[i].orderAppe = appetizer::ne;
                (*searched)[i].orderDish = mainDish::n;
                (*searched)[i].orderDrink = drink::o;
                (*searched)[i].price = 0;
                (*searched)[i].orderMethod = paymentMethod::nu;
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