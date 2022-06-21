#ifndef LOAD_SAVE_H
#define LOAD_SAVE_H

#include <vector>
#include <algorithm>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QFileInfo>
#include "client.h"
#include "costumer.h"
#include "process.h"
#include "admin.h"
#include "transaction.h"
#include "product.h"
using namespace std;

void save_client(vector<Client>&);
void save_costumer(vector<Costumer>);
void save_product(vector<Product>);
void save_product(Product &);
void save_transaction(Transaction &a);
vector<Transaction> load_transaction();
vector<Client> load_client();
vector<Costumer> load_costumer();
vector<Product> load_product();
bool check_file(QString);
vector<Product> sort_function(vector<Product>, QString,QString,QString,QString,QString,QString,QString, bool,bool,bool,bool,bool,bool,bool,bool);
//bool incresingorder(Product,Product,QString);
//bool decreasingorder(Product,Product,QString);
#endif // LOAD_SAVE_H
