#include <iostream> //this should be a set order
#include <string>
//Define declaration
#define password "recursion"

using namespace std;
//ENUM declaration
enum mainDish{pizza, pasta, lasagna};
enum drink{beer, tea, soda};
enum appetizer{palitroque, garlicBread, cheeseSticks};
enum paymentMethod{cash, creditCard};
//Struct declaration
struct address{
    int houseNumber;
    string neighborhood;
    string county;
    string state;
};

struct mainInfo{
    int idOrder;
    string name;
    mainDish orderDish;
    appetizer orderAppe;
    drink orderDrink;
    float price;
    paymentMethod orderPayment;
};

struct delivery{
    address deliveryAddress;
    int cellphone;
    mainInfo orderInfo;
};

struct houseOrder{
    int clientsPerTable;
    mainInfo orderInfo;
};

//global variables

bool isAdmin = false;
int idOrder = 1;

//prototypes
bool loginUser(void);
void printMenu(void);
void addOrder(delivery *array);
void addOrder(houseOrder *array);
void searchByName(delivery *array);
void searchByName(houseOrder *array);

int main(){
    //Used variable declaration
    delivery *deliArray = NULL;
    houseOrder *houArray = NULL;
    int option = 0;
    //login verification
    if(!loginUser()){
        return 0;
    }
    //basic program logic, menu
    do{
        printMenu();
        cin >> option;
        cin.ignore;

        switch(option){
            case 1:
                //Agregar ordenes a domicilio
                addOrder(deliArray);
                break;
            case 2:
                //Agregar ordenes en restaurante
                addOrder(houArray);
                break;
            case 3:
                //View Deliveries
                break;
            case 4:
                //View House Orders
                break;
            case 5:
                //Search by name
                cout << "Desea buscar por:\n 1. A domicilio\t 2. En restaurante\n";
                int aux;
                cin >> aux;
                if(aux == 1){
                    searchByName(deliArray);
                }
                else if(aux == 2){
                    searchByName(houArray);
                }
                break;
            default:
                break;
        }
    }while(option != 0);

    return 0;
}

void printMenu(void){
    cout << "SISTEMA DE DESPACHO DI MOLTO" << endl;
    cout << "\t1. Agregar ordenes a domicilio.\n";
    cout << "\t2. Agregar ordenes en restaurante.\n";
    cout << "\t3. Ver ordenes a domicilio.\n";
    cout << "\t4. Ver ordenes en restaurante.\n";
    cout << "\t5. Buscar por una orden.\n";
    cout << "Su opcion:\t";
}

bool loginUser(void){
    string enterPass = "";
    char option;
    cout << "Inicio de Sesion.\n";
    cout << "A - Administrador\n";
    cout << "E - Empleado\n";
    cout << "Su opcion: ";
    cin >> option;
    switch (option)
    {
    case 'a':
        
    case 'A':
        cout << "Digite la contrasena.\n";
        cin >> enterPass;
        if(enterPass.compare(password) == 0){
            isAdmin = true;
            return true;
        }
        else{
            cout << "Contrasena incorrecta.\n";
        }
        break;
    case 'e':

    case 'E':
        isAdmin = false;
        return true;
        break;
    default:
        break;
    }
    return false;
}

void addOrder(delivery *array){
    int size = 0, aux = 0;
    cout << "Cantidad de pedidos a ingresar: ";
    cin >> size;
    cin.ignore();

    array = new delivery[size];

    for(int i = 0; i < size; i++){
        cout << "Nombre:\t";
        getline(cin, array[i].orderInfo.name);
        cout << "Numero de telefono:\t";
        cin >> array[i].cellphone;
        cin.ignore();
        cout << "Direccion" << endl;
        cout << "Colonia:\t";
        getline(cin, array[i].deliveryAddress.neighborhood);
        cout << "Municipio:\t";
        getline(cin, array[i].deliveryAddress.county);
        cout << "Departamento:\t";
        cin >> array[i].deliveryAddress.houseNumber;
        cin.ignore();
        do{
            cout << "Entrada\n";
            cout << "\t1. Palitroque\n";
            cout << "\t2. Pan con ajo\n";
            cout << "\t3. Palitos de quesno";
            cout << "Su opcion: ";
            cin >> aux;
            cin.ignore();
            switch(aux){
                case 1:
                    array[i].orderInfo.orderAppe = palitroque;
                    break;
                case 2:
                    array[i].orderInfo.orderAppe = garlicBread;
                    break;
                case 3:
                    array[i].orderInfo.orderAppe = cheeseSticks;
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
                    array[i].orderInfo.orderDish = pizza;
                    break;
                case 2:
                    array[i].orderInfo.orderDish = pasta;
                    break;
                case 3:
                    array[i].orderInfo.orderDish = lasagna;
                    break;
                default:
                    cout << "Por favor escoga una opcion valida.\n";
                    break;
            }
        }while(aux != 1 && aux != 2 && aux != 3);

        do{
            cout << "Bebida\n";
            cout << "\t1. Cerveza";
            cout << "\t2. Te";
            cout << "\t3. Soda";
            cout << "Su opcion: ";
            cin >> aux;
            cin.ignore();
            switch(aux){
                case 1:
                    array[i].orderInfo.orderDrink = beer;
                    break;
                case 2:
                    array[i].orderInfo.orderDrink = tea;
                    break;
                case 3:
                    array[i].orderInfo.orderDrink = soda;
                    break;
                default:
                    cout << "Por favor escoga una opcion valida.\n";
                    break;
            }
        }while(aux != 1 && aux != 2 && aux != 3);
        
        array[i].orderInfo.idOrder = idOrder++;

        do{
            cout << "Metodo de pago\n";
            cout << "\t1. Efectivo";
            cout << "\t2. Tarjeta";
            cout << "Su opcion: ";
            cin >> aux;
            cin.ignore();
            switch(aux){
                case 1:
                    array[i].orderInfo.orderPayment = cash;
                    break;
                case 2:
                    array[i].orderInfo.orderPayment = creditCard;
                    break;
                default:
                    break;
            }
        }while(aux != 1 && aux != 2);

        cout << "Monto: ";
        cin >> array[i].orderInfo.price;
        cin.ignore();
    }
}

void addOrder(houseOrder *array){
    int size = 0, aux = 0;
    cout << "Cantidad de pedidos a ingresar: ";
    cin >> size;
    cin.ignore();

    array = new houseOrder[size];

    for(int i = 0; i < size; i++){
        cout << "Nombre:\t";
        getline(cin, array[i].orderInfo.name);
        cout << "Personas en la mesa:\t";
        cin >> array[i].clientsPerTable;
        cin.ignore();
        do{
            cout << "Entrada\n";
            cout << "\t1. Palitroque\n";
            cout << "\t2. Pan con ajo\n";
            cout << "\t3. Palitos de quesno";
            cout << "Su opcion: ";
            cin >> aux;
            cin.ignore();
            switch(aux){
                case 1:
                    array[i].orderInfo.orderAppe = palitroque;
                    break;
                case 2:
                    array[i].orderInfo.orderAppe = garlicBread;
                    break;
                case 3:
                    array[i].orderInfo.orderAppe = cheeseSticks;
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
                    array[i].orderInfo.orderDish = pizza;
                    break;
                case 2:
                    array[i].orderInfo.orderDish = pasta;
                    break;
                case 3:
                    array[i].orderInfo.orderDish = lasagna;
                    break;
                default:
                    cout << "Por favor escoga una opcion valida.\n";
                    break;
            }
        }while(aux != 1 && aux != 2 && aux != 3);

        do{
            cout << "Bebida\n";
            cout << "\t1. Cerveza";
            cout << "\t2. Te";
            cout << "\t3. Soda";
            cout << "Su opcion: ";
            cin >> aux;
            cin.ignore();
            switch(aux){
                case 1:
                    array[i].orderInfo.orderDrink = beer;
                    break;
                case 2:
                    array[i].orderInfo.orderDrink = tea;
                    break;
                case 3:
                    array[i].orderInfo.orderDrink = soda;
                    break;
                default:
                    cout << "Por favor escoga una opcion valida.\n";
                    break;
            }
        }while(aux != 1 && aux != 2 && aux != 3);
        
        array[i].orderInfo.idOrder = idOrder++;

        do{
            cout << "Metodo de pago\n";
            cout << "\t1. Efectivo";
            cout << "\t2. Tarjeta";
            cout << "Su opcion: ";
            cin >> aux;
            cin.ignore();
            switch(aux){
                case 1:
                    array[i].orderInfo.orderPayment = cash;
                    break;
                case 2:
                    array[i].orderInfo.orderPayment = creditCard;
                    break;
                default:
                    break;
            }
        }while(aux != 1 && aux != 2);

        cout << "Monto: ";
        cin >> array[i].orderInfo.price;
        cin.ignore();
    }
}

void searchByName(delivery *array){
    string aux = "";
    bool nameFound = false;
    int size = sizeof(array) / sizeof(delivery);
    cout << "Nomber a buscar: ";
    getline(cin, aux);

    for(int i = 0; i < size; i++){
        if(aux.compare(array[i].orderInfo.name) == 0){
            //Imprimir datos
            nameFound = true;
        }
    }
    // IF de linea
    //(Booleano) ? Codigo del if : Codigo del else, todos son campos necesarios
    (!nameFound) ? cout << "No existe ese usuario.\n": cout << "";
}
void searchByName(houseOrder *array){
    string aux = "";
    bool nameFound = false;
    int size = sizeof(array) / sizeof(houseOrder);
    cout << "Nomber a buscar: ";
    getline(cin, aux);

    for(int i = 0; i < size; i++){
        if(aux.compare(array[i].orderInfo.name) == 0){
            //Imprimire datos
            nameFound = true;
        }
    }
    // IF de linea
    //(Booleano) ? Codigo del if : Codigo del else, todos son campos necesarios
    (!nameFound) ? cout << "No existe ese usuario.\n": cout << "";
}