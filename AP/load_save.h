#ifndef LOAD_SAVE_H
#define LOAD_SAVE_H

#include <vector>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QFileInfo>
#include "client.h"
#include "costumer.h"
#include "process.h"
#include "admin.h"
using namespace std;

void save_client(vector<Client>);
void save_costumer(vector<Costumer>);
void save_product(vector<Product>);
vector<Client> load_client();
vector<Costumer> load_costumer();
vector<Product> load_product();
bool check_file(QString);

#endif // LOAD_SAVE_H
