#ifndef LOAD_SAVE_H
#define LOAD_SAVE_H

#include <vector>
#include <algorithm>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QFileInfo>
#include <QMessageBox>
#include <QProcess>
#include <regex>
#include "client.h"
#include "costumer.h"
#include "process.h"
#include "admin.h"
#include "transaction.h"
#include "product.h"
#include <thread>
#include <QEventLoop>
#include <chrono>
#include <fstream>
using namespace std;

void save_client(vector<Client>&);
void save_costumer(vector<Costumer>);
void save_client(Client &);
void save_product(vector<Product>);
void save_product(Product &);
void save_transaction(Transaction &a);
void send_email(Transaction, QString);
vector<Transaction> load_transaction();
vector<Client> load_client();
vector<Costumer> load_costumer();
vector<Product> load_product();
bool check_file(QString);
vector<Product> sort_function(vector<Product>, QString,QString,QString,QString,QString,QString,QString, bool,bool,bool,bool,bool,bool,bool,bool);
void check_and_create();
int current_client_index(QString);
int current_costumer_index(QString);
void add_viewed(vector <Product> &, int);
QString show_balance(vector <Client>& , QString);
QString show_balance2(vector <Costumer>& , QString);
void confirm_payment(QString);
bool check_email(QString email);
void check_accounts();
//QString show_balance(vector <Costumer>& , QString);

#endif // LOAD_SAVE_H
