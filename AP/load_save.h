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
#include <thread>
#include <QEventLoop>
#include <regex>
#include "client.h"
#include "costumer.h"
#include "process.h"
#include "admin.h"
#include "transaction.h"
#include "product.h"
#include <chrono>
#include <fstream>
#include <iostream>
using namespace std;

void save_client(vector<Client>&);
void save_costumer(vector<Costumer>);
void save_client(Client &);
void save_product(vector<Product>);
void save_product(Product &);
void save_transaction(Transaction &a);
void send_email(Transaction, QString);
void check_accounts();
void save_admin(Admin);
void delete_from_admins(QString);
void check_and_create();
void add_viewed(vector <Product> &, int);
void confirm_payment(QString);

int current_client_index(QString);
int current_costumer_index(QString);

vector<Transaction> load_transaction();
vector<Client> load_client();
vector<Costumer> load_costumer();
vector<Product> load_product();
vector<Product> sort_function(vector<Product>, QString,QString,QString,QString,QString,QString,QString, bool,bool,bool,bool,bool,bool,bool,bool);
vector<Admin> load_admin();

bool check_file(QString);
bool check_email(QString email);

QString show_balance(vector <Client>& , QString);
QString show_balance2(vector <Costumer>& , QString);

#endif // LOAD_SAVE_H
