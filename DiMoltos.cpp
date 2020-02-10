#include <iostream>
#include <string> //Para valores string
#include <vector> //Para las listas dinamicas
#include <math.h> //Para la funcion ceil

//Define declaration
#define password "recursion"

using namespace std;

//ENUM declaration
enum mainDish{pizza = 0, pasta, lasagna};
enum drink{beer = 0, tea, soda};
enum appetizer{pizzaRolls = 0, garlicBread, cheeseSticks};
enum paymentMethod{cash = 0, creditCard};

//Structs
struct address{
    string houseNumber;
    string neighborhood;
    string county;
    string state;
};

struct name{
    string firstName;
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
int globalIDTake = 1;
int globalIDHouse = 1;
string printDish[] = {"Pizza", "Pasta", "Lasagna"};
string printAppe[] = {"Rollos de Pizza", "Pan con ajo", "Palitos de queso"};
string printDrink[] = {"Cerveza", "Te Helado", "Gaseosa"};
string printMethod[] = {"Efectivo", "Tarjeta"};


//Prototyping functions
void addTakeOut();
void addHouseOrder();
void showTakeOuts();
void showHouseOrders();
void showTotalPrice();
void deleteOrderTakeOut();
void deleteOrderHouse();
void menuAppe(takeOut* auxOrder);
void menuAppe(inHouseOrder* auxOrder);
void menuDish(takeOut* auxOrder);
void menuDish(inHouseOrder* auxOrder);
void menuDrink(takeOut* auxOrder);
void menuDrink(inHouseOrder* auxOrder);
void showTimeTake(int userID);
void showTimeHouse(int userID);
float showAverageTimeTake(float time, int currentPosition);
float showAverageTimeHouse(float time, int currentPosition);
void dispatchTakeOut();
void dispatchHouse();

void mainMenu(bool *outerCheck){
    //Main Menu.
    //Local variables.
    string userInput;
    bool correctPass = false, administrator = false;
    int userOption = 0;

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
        cout << "\t5- Despachar ordenes a domicilio." << endl;
        cout << "\t6- Despachar ordenes en restaurante." << endl;
        cout << "\t7- Ver tiempo de espera promedio a domicilio." << endl;
        cout << "\t8- Ver tiempo de espera promedio en restaurante." << endl;
        cout << "\t9- Cancelar una orden." << endl;
        cout << "\t10- Calcular total de venta." << endl;
        cout << "\t11- Cambiar de usuario." << endl;
        cout << "\t0- Salir." << endl;
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
                if(takeOrder.size() == 0){
                    cout << "No hay ordenes en proceso.\n";
                }
                else{
                showTakeOuts();
                }
                break;
            case 4:
                if(takeOrder.size() == 0){
                    cout << "No hay ordenes en proceso.\n";
                }
                else{
                showHouseOrders();
                }
                break;
            case 5:
                dispatchTakeOut();
                break;
            case 6:
                dispatchHouse();
                break;
            case 7:
                if(takeOrder.size() == 0){
                    cout << "No hay ordenes en proceso.\n";
                }
                else{
                    cout << "El tiempo de espera promedio es de: ";
                    cout << ceil(showAverageTimeTake(0, takeOrder.size() - 1) / takeOrder.size());
                    cout << " minutos.\n";
                }
                break;
            case 8:
                if(houseOrder.size() == 0){
                    cout << "No hay ordenes en proceso.\n";
                }
                else{
                    cout << "El tiempo de espera promedio es de: ";
                    cout << ceil(showAverageTimeHouse(0, houseOrder.size() - 1) / houseOrder.size());
                    cout << " minutos.\n";
                }
                break;
            case 9:
                if(administrator == true){
                    int deleteCheck = 0;
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
                            cout << "Valor invalido.\n";
                            break;
                    }
                }
                else{
                    cout << "Solo los administradores pueden borrar ordenes.\n";
                }
                break;
            case 10:
                showTotalPrice();
                break;
            case 11:
                correctPass = false;
                break;
            case 0:
                correctPass = false;
                *outerCheck = false;
                break;
            default:
                cout << "Valor Invalido.\n";
                break;
        }
    }
}

void addTakeOut(){
    takeOut auxOrder;
    auxOrder.id = globalIDTake++;
    cout << "El identificador de esta orden es: " << auxOrder.id << endl;
    int aux;
    bool cont = true;
    //Adding orders 'to go'/delivery.
    auxOrder.price = 0;
    cout << "Por favor digite su nombre.\n Ingrese el primer nombre.\n";
    getline(cin, auxOrder.clientName.firstName);

    cout << "Ingrese el apellido.\n";
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
        menuAppe(&auxOrder);
        cout << "Continuar agregando?\n \t1. Si\n \t2. No\n";
        cin >> aux;
        cin.ignore();
        if(aux == 2){
            cont = false;
        }
        else{
            aux = 0;
        }
    }while(cont);
    do{
        cont = true;
        menuDish(&auxOrder);
        cout << "Continuar agregando?\n \t1. Si\n \t2. No\n";
        cin >> aux;
        cin.ignore();
        if(aux == 2){
            cont = false;
        }
        else{
            aux = 0;
        }
    }while(cont);
    do{
        cont = true;
        menuDrink(&auxOrder);
        cout << "Continuar agregando?\n \t1. Si\n \t2. No\n";
        cin >> aux;
        cin.ignore();
        if(aux == 2){
            cont = false;
        }
        else{
            aux = 0;
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
                cout << "Opcion invalida.\n";
                break;
        }
    }while(aux != 1 && aux != 2);

    takeOrder.insert(takeOrder.end() ,auxOrder);
    cout << "Su total es: $" << auxOrder.price << "." << endl;
}
        
void addHouseOrder(){
    inHouseOrder auxOrder;
    auxOrder.id = globalIDHouse++;
    cout << "El identificador de esta orden es: " << auxOrder.id << endl;
    auxOrder.price = 0;
    bool cont = true;
    int aux;
    //Adding orders in restaurant.
    cout << "Por favor digite su nombre.\n Ingrese el primer nombre.\n";
    getline(cin, auxOrder.clientName.firstName);

    cout << "Ingrese el apellido.\n";
    getline(cin, auxOrder.clientName.lastName);
            
    cout << "Por favor indique el numero de personas en la mesa.\n";
    cin >> auxOrder.clientsPerTable;
    cin.ignore();

    do{
        cont = true;
        menuAppe(&auxOrder);
        cout << "Continuar agregando?\n \t1. Si\n \t2. No\n";
        cin >> aux;
        cin.ignore();
        if(aux == 2){
            cont = false;
        }
        else{
            aux = 0;
        }
    }while(cont);
    do{
        cont = true;
        menuDish(&auxOrder);
        cout << "Continuar agregando?\n \t1. Si\n \t2. No\n";
        cin >> aux;
        cin.ignore();
        if(aux == 2){
            cont = false;
        }
        else{
            aux = 0;
        }
    }while(cont);

    do{
        cont = true;
        menuDrink(&auxOrder);
        cout << "Continuar agregando?\n \t1. Si\n \t2. No\n";
        cin >> aux;
        cin.ignore();
        if(aux == 2){
            cont = false;
        }
        else{
            aux = 0;
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
                cout << "Opcion Invalida.\n";
                break;
        }
    }while(aux != 1 && aux != 2);

    cout << "Su total es: $" << auxOrder.price << "." << endl;
    houseOrder.insert(houseOrder.end(), auxOrder);
}

void showTakeOuts(){
    if(takeOrder.empty()){
        return;
    }
    for(int i = 0; i < takeOrder.size(); i++){
        cout << "Identificador de orden: " << takeOrder[i].id << endl;
        cout << "Primer nombre del cliente: " << takeOrder[i].clientName.firstName << endl;
        cout << "Segundo apellido del cliente: " << takeOrder[i].clientName.lastName << endl;
        cout << "Numero de casa: " << takeOrder[i].clientAddress.houseNumber << endl;
        cout << "Colonia: " << takeOrder[i].clientAddress.neighborhood << endl;
        cout << "Municipio: " << takeOrder[i].clientAddress.county << endl;
        cout << "Departamento: " << takeOrder[i].clientAddress.state << endl;
        cout << "Numero del cliente: " << takeOrder[i].clientPhoneNumber << endl;
        cout << "Aperitivo(s): " << endl;
        for(int j = 0; j < takeOrder[i].orderAppe.size(); j++){
            cout << j + 1 << ": " << printAppe[takeOrder[i].orderAppe[j]] << endl;
        }
        cout << "Plato(s) principal(es): " << endl;
        for(int j = 0; j < takeOrder[i].orderDish.size(); j++){
            cout << j + 1 << ": " << printDish[takeOrder[i].orderDish[j]] << endl;
        }
        cout << "Bebida(s): " << endl;
        for(int j = 0; j < takeOrder[i].orderDrink.size(); j++){
            cout << j + 1 << ": " << printDrink[takeOrder[i].orderDrink[j]] << endl;
        }
        cout << "Subtotal: $" << takeOrder[i].price << endl;
        cout << "Total con impuesto: $" << (takeOrder[i].price * 1.13) << endl;
        cout << "Metodo de pago: " << printMethod[takeOrder[i].orderMethod] << endl;
        showTimeTake(takeOrder[i].id);
        cout << endl << endl;
    }
}

void showHouseOrders(){
    if(houseOrder.empty()){
        return;
    }
    for(int i = 0; i < houseOrder.size(); i++){
        cout << "Identificador de orden: " << houseOrder[i].id << endl;
        cout << "Primer nombre del cliente: " << houseOrder[i].clientName.firstName << endl;
        cout << "Segundo apellido del cliente: " << houseOrder[i].clientName.lastName << endl;
        cout << "Personas en la mesa: " << houseOrder[i].clientsPerTable << endl;
        cout << "Aperitivo(s): " << endl;
        for(int j = 0; j < houseOrder[i].orderAppe.size(); j++){
            cout << j + 1 << ": " << printAppe[houseOrder[i].orderAppe[j]] << endl;
        }
        cout << "Plato(s) principal(es): " << endl;
        for(int j = 0; j < houseOrder[i].orderDish.size(); j++){
            cout << j + 1 << ": " << printDish[houseOrder[i].orderDish[j]] << endl;
        }
        cout << "Bebida(s): " << endl;
        for(int j = 0; j < houseOrder[i].orderDrink.size(); j++){
            cout << j + 1 << ": " << printDrink[houseOrder[i].orderDrink[j]] << endl;
        }
        cout << "Subtotal: $" << houseOrder[i].price << endl;
        cout << "Total con impuesto: $" << (houseOrder[i].price * 1.13) << endl;
        cout << "Metodo de pago: " << printMethod[houseOrder[i].orderMethod] << endl;
        showTimeHouse(houseOrder[i].id);
        cout << endl << endl;
    }
}

void showTotalPrice(){
    //Showing total price using dispatched orders
    float totalPrice = 0;
    if(dispatchedTakeOut.empty()){}
    else{
        for(int i = 0; i < dispatchedTakeOut.size(); i++){
            totalPrice += (dispatchedTakeOut[i].price * 1.13);
        }
    }
    if(dispatchedHouse.empty()){}
    else{
        for(int i = 0; i < dispatchedHouse.size(); i++){
            totalPrice += (dispatchedHouse[i].price * 1.13);
        }
    }
    cout.precision(5);
    cout << "El total en ventas (incluyendo el IVA) es de: $" << totalPrice << "\n";
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

void menuAppe(takeOut* auxOrder){
    //Appetizer menu for take out
    appetizer auxAppe;
    int aux;
    cout << "Entrada\n";
    cout << "\t1. Palitroque\n";
    cout << "\t2. Pan con ajo\n";
    cout << "\t3. Palitos de queso\n";
    cout << "\t4. Continuar sin pedir.\n";
    cout << "Su opcion: ";
    cin >> aux;
    cin.ignore();
    switch(aux){
        case 1: 
            auxAppe = appetizer::pizzaRolls;
            (*auxOrder).price += 4.99;
            (*auxOrder).orderAppe.insert((*auxOrder).orderAppe.end(), auxAppe);
            break;
        case 2:
            auxAppe = appetizer::garlicBread;
            (*auxOrder).price += 3.99;
            (*auxOrder).orderAppe.insert((*auxOrder).orderAppe.end(), auxAppe);
            break;
        case 3:
            auxAppe = appetizer::cheeseSticks;
            (*auxOrder).price += 3.75;
            (*auxOrder).orderAppe.insert((*auxOrder).orderAppe.end(), auxAppe);
            break;
        case 4:
            break;
        default:
            cout << "Por favor escoga una opcion valida.\n";
            break;
    }
}

void menuAppe(inHouseOrder* auxOrder){
    //Appetizer menu in restaurant
    appetizer auxAppe;
    int aux;
    cout << "Entrada\n";
    cout << "\t1. Palitroque\n";
    cout << "\t2. Pan con ajo\n";
    cout << "\t3. Palitos de queso\n";
    cout << "\t4. Continuar sin pedir.\n";
    cout << "Su opcion: ";
    cin >> aux;
    cin.ignore();
    switch(aux){
        case 1: 
            auxAppe = appetizer::pizzaRolls;
            (*auxOrder).price += 4.99;
            (*auxOrder).orderAppe.insert((*auxOrder).orderAppe.end(), auxAppe);
            break;
        case 2:
            auxAppe = appetizer::garlicBread;
            (*auxOrder).price += 3.99;
            (*auxOrder).orderAppe.insert((*auxOrder).orderAppe.end(), auxAppe);
            break;
        case 3:
            auxAppe = appetizer::cheeseSticks;
            (*auxOrder).price += 3.75;
            (*auxOrder).orderAppe.insert((*auxOrder).orderAppe.end(), auxAppe);
            break;
        case 4:
            break;
        default:
            cout << "Por favor escoga una opcion valida.\n";
            break;
    }
}

void menuDish(takeOut* auxOrder){
    //Main dish menu for take out
    mainDish auxDish;
    int aux;
    cout << "Plato principal\n";
    cout << "\t1. Pizza\n";
    cout << "\t2. Pasta\n";
    cout << "\t3. Lasagna\n";
    cout << "\t4. Continuar sin pedir.\n";
    cout << "Su opcion: ";
    cin >> aux;
    cin.ignore();
    switch(aux){
        case 1:
            auxDish = mainDish::pizza;
            (*auxOrder).price += 13.99;
            (*auxOrder).orderDish.insert((*auxOrder).orderDish.end(), auxDish);
            break;
        case 2:
            auxDish = mainDish::pasta;
            (*auxOrder).price += 5.55;
            (*auxOrder).orderDish.insert((*auxOrder).orderDish.end(), auxDish);
            break;
        case 3:
            auxDish = mainDish::lasagna;
            (*auxOrder).price += 6.25;
            (*auxOrder).orderDish.insert((*auxOrder).orderDish.end(), auxDish);
            break;
        case 4:
            break;
        default:
            cout << "Por favor escoga una opcion valida.\n";
            break;
    }
}

void menuDish(inHouseOrder* auxOrder){
    //Main dish menu in restaurant
    mainDish auxDish;
    int aux;
    cout << "Plato principal\n";
    cout << "\t1. Pizza\n";
    cout << "\t2. Pasta\n";
    cout << "\t3. Lasagna\n";
    cout << "\t4. Continuar sin pedir.\n";
    cout << "Su opcion: ";
    cin >> aux;
    cin.ignore();
    switch(aux){
        case 1:
            auxDish = mainDish::pizza;
            (*auxOrder).price += 13.99;
            (*auxOrder).orderDish.insert((*auxOrder).orderDish.end(), auxDish);
            break;
        case 2:
            auxDish = mainDish::pasta;
            (*auxOrder).price += 5.55;
            (*auxOrder).orderDish.insert((*auxOrder).orderDish.end(), auxDish);
            break;
        case 3:
            auxDish = mainDish::lasagna;
            (*auxOrder).price += 6.25;
            (*auxOrder).orderDish.insert((*auxOrder).orderDish.end(), auxDish);
            break;
        case 4:
            break;
        default:
            cout << "Por favor escoga una opcion valida.\n";
            break;
    }
}

void menuDrink(takeOut* auxOrder){
    //Drink menu for take out
    drink auxDrink;
    int aux;
    cout << "Bebida\n";
    cout << "\t1. Cerveza\n";
    cout << "\t2. Te Helado\n";
    cout << "\t3. Soda\n";
    cout << "\t4. Continuar sin pedir.\n";
    cout << "Su opcion: ";
    cin >> aux;
    cin.ignore();
    switch(aux){
        case 1:
            auxDrink = drink::beer;
            (*auxOrder).price += 1.99;
            (*auxOrder).orderDrink.insert((*auxOrder).orderDrink.end(), auxDrink);
            break;
        case 2:
            auxDrink = drink::tea;
            (*auxOrder).price += 1.15;
            (*auxOrder).orderDrink.insert((*auxOrder).orderDrink.end(), auxDrink);
            break;
        case 3:
            auxDrink = drink::soda;
            (*auxOrder).price += 0.95;
            (*auxOrder).orderDrink.insert((*auxOrder).orderDrink.end(), auxDrink);
            break;
        case 4:
            break;
        default:
            cout << "Por favor escoga una opcion valida.\n";
            break;
    }
}

void menuDrink(inHouseOrder* auxOrder){
    //Drink menu in restaurant
    drink auxDrink;
    int aux;
    cout << "Bebida\n";
    cout << "\t1. Cerveza\n";
    cout << "\t2. Te Helado\n";
    cout << "\t3. Soda\n";
    cout << "\t4. Continuar sin pedir.\n";
    cout << "Su opcion: ";
    cin >> aux;
    cin.ignore();
    switch(aux){
        case 1:
            auxDrink = drink::beer;
            (*auxOrder).price += 1.99;
            (*auxOrder).orderDrink.insert((*auxOrder).orderDrink.end(), auxDrink);
            break;
        case 2:
            auxDrink = drink::tea;
            (*auxOrder).price += 1.15;
            (*auxOrder).orderDrink.insert((*auxOrder).orderDrink.end(), auxDrink);
            break;
        case 3:
            auxDrink = drink::soda;
            (*auxOrder).price += 0.95;
            (*auxOrder).orderDrink.insert((*auxOrder).orderDrink.end(), auxDrink);
            break;
        case 4:
            break;
        default:
            cout << "Por favor escoga una opcion valida.\n";
            break;
    }
}

void dispatchTakeOut(){
    //Dispatch an order for take out
    int confirmation = 0;
    cout << "Se despachara la orden a domicilio mas vieja en la lista, desea continuar?\n 1. Si\t 2.No\n";
    cin >> confirmation;
    if(confirmation == 1){
        dispatchedTakeOut.insert(dispatchedTakeOut.end(), takeOrder.front());
        takeOrder.erase(takeOrder.begin());
    }
}

void dispatchHouse(){
    //Dispatch an order in restaurant
    int confirmation = 0;
    cout << "Se despachara la orden en restaurante mas vieja en la lista, desea continuar?\n 1. Si\t 2.No\n";
    cin >> confirmation;
    if(confirmation == 1){
        dispatchedHouse.insert(dispatchedHouse.end(), houseOrder.front());
        houseOrder.erase(houseOrder.begin());
    }
}

void showTimeTake(int userID){
    //Showing the individual time for take out orders
    float time;
    bool found = false;
    for(int i = 0; i < takeOrder.size(); i++){
        if(takeOrder[i].id == userID){
            found = true;
            time = takeOrder[i].orderAppe.size() * 1.10;
            time += takeOrder[i].orderDish.size() * 1.5;
            time += takeOrder[i].orderDrink.size() * 1.35;
            time += 15;
            ceil(time);
            cout << "Esta orden tomara aproximadamente " << time << " minutos.\n";
        }
    }
    if(found == false){
        cout << "No se encontro la orden.\n";
    }
}

void showTimeHouse(int userID){
    //Showing the individual time for restaurant orders
    float time = 0;
    bool found = false;
    for(int i = 0; i < houseOrder.size(); i++){
        if(houseOrder[i].id == userID){
            found = true;
            time = houseOrder[i].orderAppe.size() * 1.10;
            time += houseOrder[i].orderDish.size() * 1.5;
            time += houseOrder[i].orderDrink.size() * 1.35;
            ceil(time);
            cout << "Esta orden tomara aproximadamente " << time << " minutos.\n";
        }
    }
    if(found == false){
        cout << "No se encontro la orden.\n";
    }
}

float showAverageTimeTake(float time, int currentPosition){
    int temp = 0;
    if(currentPosition < 0){
        return time;
    }
    else{
        time += takeOrder[currentPosition].orderAppe.size() * 1.10;
        time += takeOrder[currentPosition].orderDish.size() * 1.5;
        time += takeOrder[currentPosition].orderDrink.size() * 1.35;
        time += 15;
        temp = currentPosition - 1;
        time = showAverageTimeTake(time, temp);
        return ceil(time);
    }
}

float showAverageTimeHouse(float time, int currentPosition){
    int temp = 0;
    if(currentPosition < 0){
        return time;
    }
    else{
        time += houseOrder[currentPosition].orderAppe.size() * 1.10;
        time += houseOrder[currentPosition].orderDish.size() * 1.5;
        time += houseOrder[currentPosition].orderDrink.size() * 1.35;
        temp = currentPosition - 1;
        time = showAverageTimeHouse(time, temp);
        return time;
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