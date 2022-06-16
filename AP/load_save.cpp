#include "load_save.h"

void save_client(vector<Client> client_user)
{
    QJsonArray names, addresses, emails, phones, users, passwords;
    for(unsigned long long int i = 0; i<client_user.size(); i++)
    {
        names.append(client_user[i].get_name());
        addresses.append(client_user[i].get_address());
        emails.append(client_user[i].get_email());
        phones.append(client_user[i].get_phone_number());
        users.append(client_user[i].get_user_name());
        passwords.append(client_user[i].get_password());
    }

    QJsonObject j;
    j["Names"] = names;
    j["Addresses"] = addresses;
    j["Emails"] = emails;
    j["Phones"] = phones;
    j["Users"] = users;
    j["Passwords"] = passwords;
    QJsonDocument d(j);
    QFile f("All_client.json");
    f.open(QIODevice::WriteOnly);
    f.write(d.toJson());
    f.close();
}

void save_costumer(vector<Costumer> costumer_user)
{
    QJsonArray names, addresses, emails, phones, users, passwords;
    for(unsigned long long int i = 0; i<costumer_user.size(); i++)
    {
        names.append(costumer_user[i].get_name());
        addresses.append(costumer_user[i].get_address());
        emails.append(costumer_user[i].get_email());
        phones.append(costumer_user[i].get_phone_number());
        users.append(costumer_user[i].get_user_name());
        passwords.append(costumer_user[i].get_password());
    }

    QJsonObject j;
    j["Names"] = names;
    j["Addresses"] = addresses;
    j["Emails"] = emails;
    j["Phones"] = phones;
    j["Users"] = users;
    j["Passwords"] = passwords;
    QJsonDocument d(j);
    QFile f("All_costumer.json");
    f.open(QIODevice::WriteOnly);
    f.write(d.toJson());
    f.close();
}

void save_product(vector<Product> products)
{
    QJsonArray names, brands, types, colors, prices, stocks, sizes;
    for(unsigned long long int i = 0; i<products.size(); i++)
    {
        names.append(products[i].get_name());
        brands.append(products[i].get_brand());
        types.append(products[i].get_type());
        colors.append(products[i].get_color());
        prices.append(products[i].get_price());
        stocks.append(products[i].get_stock());
        sizes.append(products[i].get_size());
    }

    QJsonObject j;
    j["Names"] = names;
    j["Brands"] = brands;
    j["Types"] = types;
    j["Colors"] = colors;
    j["Prices"] = prices;
    j["Stocks"] = stocks;
    j["Sizes"] = sizes;
    QJsonDocument d(j);
    QFile f("All_product.json");
    f.open(QIODevice::WriteOnly);
    f.write(d.toJson());
    f.close();
}

vector<Client> load_client()
{
    QFile f("All_client.json");
    f.open(QIODevice::ReadOnly);
    QByteArray b = f.readAll();
    QJsonDocument d = QJsonDocument::fromJson(b);
    QJsonObject o = d.object();
    QJsonArray names, addresses, emails, phones, users, passwords;
    names = o["Names"].toArray();
    addresses = o["Addresses"].toArray();
    emails = o["Emails"].toArray();
    phones = o["Phones"].toArray();
    users = o["Users"].toArray();
    passwords = o["Passwords"].toArray();

    vector<Client> client_tmp;
    for(qsizetype i = 0; i<names.size(); i++)
    {
        Client *tmp = new Client();
        tmp->set_name(names[i].toString());
        tmp->set_address(addresses[i].toString());
        tmp->set_email(emails[i].toString());
        tmp->set_phone_number(phones[i].toString());
        tmp->set_user_name(users[i].toString());
        tmp->set_password(passwords[i].toString());
        client_tmp.push_back(*tmp);
        delete(tmp);
    }
    f.close();

    return client_tmp;
}

vector<Costumer> load_costumer()
{
    QFile f("All_costumer.json");
    f.open(QIODevice::ReadOnly);
    QByteArray b = f.readAll();
    QJsonDocument d = QJsonDocument::fromJson(b);
    QJsonObject o = d.object();
    QJsonArray names, addresses, emails, phones, users, passwords;
    names = o["Names"].toArray();
    addresses = o["Addresses"].toArray();
    emails = o["Emails"].toArray();
    phones = o["Phones"].toArray();
    users = o["Users"].toArray();
    passwords = o["Passwords"].toArray();

    vector<Costumer> costumer_tmp;
    for(qsizetype i = 0; i<names.size(); i++)
    {
        Costumer *tmp = new Costumer();
        tmp->set_name(names[i].toString());
        tmp->set_address(addresses[i].toString());
        tmp->set_email(emails[i].toString());
        tmp->set_phone_number(phones[i].toString());
        tmp->set_user_name(users[i].toString());
        tmp->set_password(passwords[i].toString());
        costumer_tmp.push_back(*tmp);
        delete(tmp);
    }
    f.close();

    return costumer_tmp;
}

vector<Product> load_product()
{
    QFile f("All_product.json");
    f.open(QIODevice::ReadOnly);
    QByteArray b = f.readAll();
    QJsonDocument d = QJsonDocument::fromJson(b);
    QJsonObject o = d.object();
    QJsonArray names, brands, types, colors, prices, stocks, sizes;
    names = o["Names"].toArray();
    brands = o["Brands"].toArray();
    types = o["Types"].toArray();
    colors = o["Colors"].toArray();
    prices = o["Prices"].toArray();
    stocks = o["Stocks"].toArray();
    sizes = o["Sizes"].toArray();

    vector<Product> product_tmp;
    for(qsizetype i = 0; i<names.size(); i++)
    {
        Product *tmp = new Product();
        tmp->set_name(names[i].toString());
        tmp->set_color(colors[i].toString());
        tmp->set_brand(brands[i].toString());
        tmp->set_type(types[i].toString());
        tmp->set_price(prices[i].toInt());
        tmp->set_size(sizes[i].toInt());
        tmp->set_stock(stocks[i].toInt());
        product_tmp.push_back(*tmp);
        delete(tmp);
    }
    f.close();

    return product_tmp;
}

bool check_file(QString path)
{
    QFileInfo check_file(path);
    // check if file exists and if yes: Is it really a file and no directory?
    if (check_file.exists() && check_file.isFile())
    {
        return true;
    }
    else
    {
        return false;
    }
}
