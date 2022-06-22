#include "load_save.h"

void save_client(vector<Client>& client_user)
{
    QJsonArray names, addresses, emails, phones, users, passwords, shopped;
    for(unsigned int i = 0; i<client_user.size(); i++)
    {
        names.append(client_user[i].get_name());
        addresses.append(client_user[i].get_address());
        emails.append(client_user[i].get_email());
        phones.append(client_user[i].get_phone_number());
        users.append(client_user[i].get_user_name());
        passwords.append(client_user[i].get_password());
        QString line;
        for (unsigned int j = 0; j<client_user[i].get_shopped_items().size(); j++)
        {
            line = client_user[i].get_user_name();
            line.append(",");
            line.append(client_user[i].get_shopped_items()[j].get_name());
            line.append(",");
            line.append(client_user[i].get_shopped_items()[j].get_costumer_username());
            line.append(",");
            shopped.append(line);
        }
        if(shopped.size() == 0 || line == "")
            shopped.append("");
    }

    QJsonObject j;
    j["Names"] = names;
    j["Addresses"] = addresses;
    j["Emails"] = emails;
    j["Phones"] = phones;
    j["Users"] = users;
    j["Passwords"] = passwords;
    j["Shopped"] = shopped;
    QJsonDocument d(j);
    QFile f("All_client.json");
    f.open(QIODevice::WriteOnly);
    f.write(d.toJson());
    f.close();
    int len = names.count();
    for(int i=0; i<len; i++)
        names.removeAt(0);
    len = addresses.count();
    for(int i=0; i<len; i++)
        addresses.removeAt(0);
    len = emails.count();
    for(int i=0; i<len; i++)
        emails.removeAt(0);
    len = phones.count();
    for(int i=0; i<len; i++)
        phones.removeAt(0);
    len = users.count();
    for(int i=0; i<len; i++)
        users.removeAt(0);
    len = passwords.count();
    for(int i=0; i<len; i++)
        passwords.removeAt(0);
    len = shopped.count();
    for(int i=0; i<len; i++)
        shopped.removeAt(0);
}

void save_costumer(vector<Costumer> costumer_user)
{
    QJsonArray names, addresses, emails, phones, users, passwords;
    for(unsigned int i = 0; i<costumer_user.size(); i++)
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
    int len = names.count();
    for(int i=0; i<len; i++)
        names.removeAt(0);
    len = addresses.count();
    for(int i=0; i<len; i++)
        addresses.removeAt(0);
    len = emails.count();
    for(int i=0; i<len; i++)
        emails.removeAt(0);
    len = phones.count();
    for(int i=0; i<len; i++)
        phones.removeAt(0);
    len = users.count();
    for(int i=0; i<len; i++)
        users.removeAt(0);
    len = passwords.count();
    for(int i=0; i<len; i++)
        passwords.removeAt(0);
}

void save_product(vector<Product> products)
{
    QJsonArray names, brands, types, colors, prices, stocks, sizes, additional_info, weights, costumers, boughts, paths;
    for(unsigned int i = 0; i<products.size(); i++)
    {
        names.append(products[i].get_name());
        brands.append(products[i].get_brand());
        types.append(products[i].get_type());
        colors.append(products[i].get_color());
        prices.append(products[i].get_price());
        stocks.append(products[i].get_stock());
        sizes.append(products[i].get_size());
        additional_info.append(products[i].get_additional_info());
        weights.append(products[i].get_weight());
        costumers.append(products[i].get_costumer_username());
        boughts.append(products[i].get_bought());
        paths.append(products[i].get_path());
    }

    QJsonObject j;
    j["Names"] = names;
    j["Brands"] = brands;
    j["Types"] = types;
    j["Colors"] = colors;
    j["Prices"] = prices;
    j["Stocks"] = stocks;
    j["Sizes"] = sizes;
    j["Info"] = additional_info;
    j["Weight"] = weights;
    j["Costumers"] = costumers;
    j["Boughts"] = boughts;
    j["Paths"] = paths;

    QJsonDocument d(j);
    QFile f("All_product.json");
    f.open(QIODevice::WriteOnly);
    f.write(d.toJson());
    f.close();

    int len = names.count();
    for(int i=0; i<len; i++)
        names.removeAt(0);
    len = brands.count();
    for(int i=0; i<len; i++)
        brands.removeAt(0);
    len = types.count();
    for(int i=0; i<len; i++)
        types.removeAt(0);
    len = colors.count();
    for(int i=0; i<len; i++)
        colors.removeAt(0);
    len = prices.count();
    for(int i=0; i<len; i++)
        prices.removeAt(0);
    len = stocks.count();
    for(int i=0; i<len; i++)
        stocks.removeAt(0);
    len = sizes.count();
    for(int i=0; i<len; i++)
        sizes.removeAt(0);
    len = additional_info.count();
    for(int i=0; i<len; i++)
        additional_info.removeAt(0);
    len = weights.count();
    for(int i=0; i<len; i++)
        weights.removeAt(0);
    len = costumers.count();
    for(int i=0; i<len; i++)
        costumers.removeAt(0);
    len = boughts.count();
    for(int i=0; i<len; i++)
        boughts.removeAt(0);
    len = paths.count();
    for(int i=0; i<len; i++)
        paths.removeAt(0);
}

void save_product(Product& pro)
{
    if(check_file("All_product.json"))
    {
        QFile f("All_product.json");
        f.open(QIODevice::ReadOnly);
        QByteArray b = f.readAll();
        QJsonDocument d = QJsonDocument::fromJson(b);
        QJsonObject o = d.object();
        QJsonArray names, brands, types, colors, prices, stocks, sizes, additional_info, weights, costumers, boughts, paths;
        names = o["Names"].toArray();
        brands = o["Brands"].toArray();
        types = o["Types"].toArray();
        colors = o["Colors"].toArray();
        prices = o["Prices"].toArray();
        stocks = o["Stocks"].toArray();
        sizes = o["Sizes"].toArray();
        additional_info = o["Info"].toArray();
        weights = o["Weight"].toArray();
        costumers = o["Costumers"].toArray();
        boughts = o["Boughts"].toArray();
        paths = o["Paths"].toArray();
        f.close();

        names.append(pro.get_name());
        brands.append(pro.get_brand());
        types.append(pro.get_type());
        colors.append(pro.get_color());
        prices.append(pro.get_price());
        stocks.append(pro.get_stock());
        sizes.append(pro.get_size());
        additional_info.append(pro.get_additional_info());
        weights.append(pro.get_weight());
        costumers.append(pro.get_costumer_username());
        boughts.append(pro.get_bought());
        paths.append(pro.get_path());

        QJsonObject j;
        j["Names"] = names;
        j["Brands"] = brands;
        j["Types"] = types;
        j["Colors"] = colors;
        j["Prices"] = prices;
        j["Stocks"] = stocks;
        j["Sizes"] = sizes;
        j["Info"] = additional_info;
        j["Weight"] = weights;
        j["Costumers"] = costumers;
        j["Boughts"] = boughts;
        j["Paths"] = paths;

        QJsonDocument d2(j);
        f.open(QIODevice::WriteOnly);
        f.write(d2.toJson());
        f.close();

        int len = names.count();
        for(int i=0; i<len; i++)
            names.removeAt(0);
        len = brands.count();
        for(int i=0; i<len; i++)
            brands.removeAt(0);
        len = types.count();
        for(int i=0; i<len; i++)
            types.removeAt(0);
        len = colors.count();
        for(int i=0; i<len; i++)
            colors.removeAt(0);
        len = prices.count();
        for(int i=0; i<len; i++)
            prices.removeAt(0);
        len = stocks.count();
        for(int i=0; i<len; i++)
            stocks.removeAt(0);
        len = sizes.count();
        for(int i=0; i<len; i++)
            sizes.removeAt(0);
        len = additional_info.count();
        for(int i=0; i<len; i++)
            additional_info.removeAt(0);
        len = weights.count();
        for(int i=0; i<len; i++)
            weights.removeAt(0);
        len = costumers.count();
        for(int i=0; i<len; i++)
            costumers.removeAt(0);
        len = boughts.count();
        for(int i=0; i<len; i++)
            boughts.removeAt(0);
        len = paths.count();
        for(int i=0; i<len; i++)
            paths.removeAt(0);
    }
    else
    {
        QJsonArray names, brands, types, colors, prices, stocks, sizes, additional_info, weights, costumers, boughts;
        names.append(pro.get_name());
        brands.append(pro.get_brand());
        types.append(pro.get_type());
        colors.append(pro.get_color());
        prices.append(pro.get_price());
        stocks.append(pro.get_stock());
        sizes.append(pro.get_size());
        additional_info.append(pro.get_additional_info());
        weights.append(pro.get_weight());
        costumers.append(pro.get_costumer_username());
        boughts.append(pro.get_bought());

        QJsonObject j;
        j["Names"] = names;
        j["Brands"] = brands;
        j["Types"] = types;
        j["Colors"] = colors;
        j["Prices"] = prices;
        j["Stocks"] = stocks;
        j["Sizes"] = sizes;
        j["Info"] = additional_info;
        j["Weight"] = weights;
        j["Costumers"] = costumers;
        j["Boughts"] = boughts;

        QJsonDocument d(j);
        QFile f("All_product.json");
        f.open(QIODevice::WriteOnly);
        f.write(d.toJson());
        f.close();

        for(int i=0; i<names.count(); i++)
            names.removeAt(0);
        for(int i=0; i<brands.count(); i++)
            brands.removeAt(0);
        for(int i=0; i<types.count(); i++)
            types.removeAt(0);
        for(int i=0; i<colors.count(); i++)
            colors.removeAt(0);
        for(int i=0; i<prices.count(); i++)
            prices.removeAt(0);
        for(int i=0; i<stocks.count(); i++)
            stocks.removeAt(0);
        for(int i=0; i<sizes.count(); i++)
            sizes.removeAt(0);
        for(int i=0; i<additional_info.count(); i++)
            additional_info.removeAt(0);
        for(int i=0; i<weights.count(); i++)
            weights.removeAt(0);
        for(int i=0; i<costumers.count(); i++)
            costumers.removeAt(0);
        for(int i=0; i<boughts.count(); i++)
            boughts.removeAt(0);
    }
}

vector<Client> load_client()
{
    QFile f("All_client.json");
    f.open(QIODevice::ReadOnly);
    QByteArray b = f.readAll();
    QJsonDocument d = QJsonDocument::fromJson(b);
    QJsonObject o = d.object();
    QJsonArray names, addresses, emails, phones, users, passwords, shopped;
    names = o["Names"].toArray();
    addresses = o["Addresses"].toArray();
    emails = o["Emails"].toArray();
    phones = o["Phones"].toArray();
    users = o["Users"].toArray();
    shopped = o["Shopped"].toArray();
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
        vector<Product> pro_temp;
        for (int l = 0; l <shopped.size(); l++)
        {
            string dummyLine = shopped[l].toString().toStdString();
            if(dummyLine == "")
                continue;
            size_t pos = 0;
            vector<string> line_splitted;
            string delimiter = ",";
            while ((pos = dummyLine.find(delimiter)) != string::npos)
            {
                line_splitted.push_back(dummyLine.substr(0, pos));
                dummyLine.erase(0, pos + delimiter.length());
            }
            if(line_splitted[0] == users[i].toString().toStdString())
            {
                Product temporary;
                QString tempo = QString::fromStdString(line_splitted[1]); // pro name
                temporary.set_name(tempo);
                tempo = QString::fromStdString(line_splitted[2]); // costumer
                temporary.set_costumer_username(tempo);
                vector<Product> all_products = load_product();
                for (unsigned int k = 0; k<all_products.size(); k++)
                {
                    if(all_products[k].get_name().toStdString() == line_splitted[1] &&
                       all_products[k].get_costumer_username().toStdString() == line_splitted[2])
                    {
                        temporary.set_additional_info(all_products[k].get_additional_info());
                        temporary.set_bought(all_products[k].get_bought());
                        temporary.set_brand(all_products[k].get_brand());
                        temporary.set_color(all_products[k].get_color());
                        temporary.set_price(all_products[k].get_price());
                        temporary.set_size(all_products[k].get_size());
                        temporary.set_stock(all_products[k].get_stock());
                        temporary.set_type(all_products[k].get_type());
                        temporary.set_weight(all_products[k].get_weight());
                        temporary.set_path(all_products[k].get_path());
                        break;
                    }
                }
                pro_temp.push_back(temporary);
                all_products.clear();
                all_products.shrink_to_fit();
            }
            else
                continue;
        }
        tmp->set_shopped_items(pro_temp);
        pro_temp.clear();
        pro_temp.shrink_to_fit();
        client_tmp.push_back(*tmp);
        delete(tmp);
    }
    f.close();
    int len = names.count();
    for(int i=0; i<len; i++)
        names.removeAt(0);
    len = addresses.count();
    for(int i=0; i<len; i++)
        addresses.removeAt(0);
    len = emails.count();
    for(int i=0; i<len; i++)
        emails.removeAt(0);
    len = phones.count();
    for(int i=0; i<len; i++)
        phones.removeAt(0);
    len = users.count();
    for(int i=0; i<len; i++)
        users.removeAt(0);
    len = passwords.count();
    for(int i=0; i<len; i++)
        passwords.removeAt(0);
    len = shopped.count();
    for(int i=0; i<len; i++)
        shopped.removeAt(0);
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
    int len = names.count();
    for(int i=0; i<len; i++)
        names.removeAt(0);
    len = addresses.count();
    for(int i=0; i<len; i++)
        addresses.removeAt(0);
    len = emails.count();
    for(int i=0; i<len; i++)
        emails.removeAt(0);
    len = phones.count();
    for(int i=0; i<len; i++)
        phones.removeAt(0);
    len = users.count();
    for(int i=0; i<len; i++)
        users.removeAt(0);
    len = passwords.count();
    for(int i=0; i<len; i++)
        passwords.removeAt(0);
    return costumer_tmp;
}

vector<Product> load_product()
{
    QFile f("All_product.json");
    f.open(QIODevice::ReadOnly);
    QByteArray b = f.readAll();
    QJsonDocument d = QJsonDocument::fromJson(b);
    QJsonObject o = d.object();
    QJsonArray names, brands, types, colors, prices, stocks, sizes, additional_info, weights, costumers, boughts, paths;
    names = o["Names"].toArray();
    brands = o["Brands"].toArray();
    types = o["Types"].toArray();
    colors = o["Colors"].toArray();
    prices = o["Prices"].toArray();
    stocks = o["Stocks"].toArray();
    sizes = o["Sizes"].toArray();
    additional_info = o["Info"].toArray();
    weights = o["Weight"].toArray();
    costumers = o["Costumers"].toArray();
    boughts = o["Boughts"].toArray();
    paths = o["Paths"].toArray();

    vector<Product> product_tmp;
    for(qsizetype i = 0; i<names.size(); i++)
    {
        Product *tmp = new Product();
        tmp->set_name(names[i].toString());
        tmp->set_color(colors[i].toString());
        tmp->set_brand(brands[i].toString());
        tmp->set_type(types[i].toString());
        tmp->set_price(prices[i].toInt());
        tmp->set_size(sizes[i].toString());
        tmp->set_stock(stocks[i].toInt());
        tmp->set_additional_info(additional_info[i].toString());
        tmp->set_weight(weights[i].toInt());
        tmp->set_costumer_username(costumers[i].toString());
        tmp->set_bought(boughts[i].toInt());
        product_tmp.push_back(*tmp);
        delete(tmp);
    }
    f.close();
    int len = names.count();
    for(int i=0; i<len; i++)
        names.removeAt(0);
    len = brands.count();
    for(int i=0; i<len; i++)
        brands.removeAt(0);
    len = types.count();
    for(int i=0; i<len; i++)
        types.removeAt(0);
    len = colors.count();
    for(int i=0; i<len; i++)
        colors.removeAt(0);
    len = prices.count();
    for(int i=0; i<len; i++)
        prices.removeAt(0);
    len = stocks.count();
    for(int i=0; i<len; i++)
        stocks.removeAt(0);
    len = sizes.count();
    for(int i=0; i<len; i++)
        sizes.removeAt(0);
    len = additional_info.count();
    for(int i=0; i<len; i++)
        additional_info.removeAt(0);
    len = weights.count();
    for(int i=0; i<len; i++)
        weights.removeAt(0);
    len = costumers.count();
    for(int i=0; i<len; i++)
        costumers.removeAt(0);
    len = boughts.count();
    for(int i=0; i<len; i++)
        boughts.removeAt(0);
    len = paths.count();
    for(int i=0; i<len; i++)
        paths.removeAt(0);

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

void save_transaction(Transaction& tmp)
{
    if(check_file("All_transaction.json"))
    {
        QFile f("All_transaction.json");
        f.open(QIODevice::ReadOnly);
        QByteArray b = f.readAll();
        QJsonDocument d = QJsonDocument::fromJson(b);
        QJsonObject o = d.object();
        QJsonArray products, names;
        products = o["Products"].toArray();
        names = o["Names"].toArray();
        f.close();
        bool flag = false;
        for(int i = 0; i<names.size(); i++)
        {
            if (names[i].toString() == tmp.get_client_user_name())
            {
                flag = true;
                break;
            }
        }
        if(!flag)
            names.append(tmp.get_client_user_name());
        QString line;
        for (unsigned int i = 0; i<tmp.get_bought_product().size(); i++)
        {
            line = tmp.get_client_user_name();
            line.append(",");
            line.append(tmp.get_bought_product()[i].get_name());
            line.append(",");
            line.append(tmp.get_bought_product()[i].get_costumer_username());
            line.append(",");
            products.append(line);
        }
        QJsonObject j;
        j["Products"] = products;
        j["Names"] = names;
        QJsonDocument d2(j);
        f.open(QIODevice::WriteOnly);
        f.write(d2.toJson());
        f.close();
        for(int i=0; i<=products.count(); i++)
            products.removeAt(0);
        for(int i=0; i<=names.count(); i++)
            names.removeAt(0);
    }

    else
    {
        //vector product, client user name
        QJsonArray products, names;
        names.append(tmp.get_client_user_name());
        QString line;
        for (unsigned int i = 0; i<tmp.get_bought_product().size(); i++)
        {
            line = tmp.get_client_user_name();
            line.append(",");
            line.append(tmp.get_bought_product()[i].get_name());
            line.append(",");
            line.append(tmp.get_bought_product()[i].get_costumer_username());
            line.append(",");
            products.append(line);
        }
        QJsonObject j;
        j["Names"] = names;
        j["Products"] = products;
        QJsonDocument d(j);
        QFile f("All_transaction.json");
        f.open(QIODevice::WriteOnly);
        f.write(d.toJson());
        f.close();
        for(int i=0; i<=products.count(); i++)
            products.removeAt(0);
        for(int i=0; i<=names.count(); i++)
            names.removeAt(0);
    }
}

vector<Transaction> load_transaction()
{
    vector<Transaction> trans;
    if(check_file("All_transaction.json"))
    {
        QFile f("All_transaction.json");
        f.open(QIODevice::ReadOnly);
        QByteArray b = f.readAll();
        QJsonDocument d = QJsonDocument::fromJson(b);
        QJsonObject o = d.object();
        QJsonArray products, names;
        products = o["Products"].toArray();
        names = o["Names"].toArray();
        f.close();
        Transaction tmp;
        vector<Product> pro_temp;
        for(int i = 0; i<names.size(); i++)
        {
            for(int j = 0; j<products.size(); j++)
            {
                string dummyLine = products[j].toString().toStdString();
                size_t pos = 0;
                vector<string> line_splitted;
                string delimiter = ",";
                while ((pos = dummyLine.find(delimiter)) != string::npos)
                {
                    line_splitted.push_back(dummyLine.substr(0, pos));
                    dummyLine.erase(0, pos + delimiter.length());
                }
                if(line_splitted[0] == names[i].toString().toStdString())
                {
                    QString tempo = QString::fromStdString(line_splitted[0]);
                    tmp.set_client_user_name(tempo);
                    Product temporary;
                    tempo = QString::fromStdString(line_splitted[1]);
                    temporary.set_name(tempo);
                    tempo = QString::fromStdString(line_splitted[2]);
                    temporary.set_costumer_username(tempo);
                    vector<Product> all_products = load_product();
                    for (unsigned int k = 0; k<all_products.size(); k++)
                    {
                        if(all_products[k].get_name().toStdString() == line_splitted[1] &&
                           all_products[k].get_costumer_username().toStdString() == line_splitted[2])
                        {
                            temporary.set_additional_info(all_products[k].get_additional_info());
                            temporary.set_bought(all_products[k].get_bought());
                            temporary.set_brand(all_products[k].get_brand());
                            temporary.set_color(all_products[k].get_color());
                            temporary.set_price(all_products[k].get_price());
                            temporary.set_size(all_products[k].get_size());
                            temporary.set_stock(all_products[k].get_stock());
                            temporary.set_type(all_products[k].get_type());
                            temporary.set_weight(all_products[k].get_weight());
                            temporary.set_path(all_products[k].get_path());
                            break;
                        }
                    }
                    pro_temp.push_back(temporary);
                    all_products.clear();
                    all_products.shrink_to_fit();
                }
            }
            tmp.set_bought_product(pro_temp);
            trans.push_back(tmp);
            pro_temp.clear();
            pro_temp.shrink_to_fit();
        }

        pro_temp.clear();
        pro_temp.shrink_to_fit();
        for(int i=0; i<=products.count(); i++)
            products.removeAt(0);
        for(int i=0; i<=names.count(); i++)
            names.removeAt(0);
    }
    else
    {
        //hey
    }
    return trans;
}

vector<Product> sort_function(vector<Product> allproducts, QString from_price, QString to_price, QString from_weight, QString to_weight, QString color, QString brand, QString type, bool min, bool max, bool newest, bool oldest, bool M_shopped, bool M_viewed, bool none, bool availale)
{
    vector<Product> updated = allproducts;
    vector<unsigned long long int> list;
    for(unsigned long long int i = 0; i <updated.size() ;i++)
    {
        bool check{false};
        if(updated[i].get_color() != color || updated[i].get_brand() != brand || updated[i].get_type() != type)
            check = true;
        else if(updated[i].get_price()<from_price.toInt() || updated[i].get_price() > to_price.toInt() || updated[i].get_weight()<from_weight.toInt() || updated[i].get_weight() > to_weight.toInt())
            check = true;
        else if(availale)
            if(updated[i].get_stock()==0)
                check = true;
        if(check)
            list.push_back(i);
    }
    sort(list.begin(), list.end(), greater<int>());
    for(unsigned long long int i = 0; i<list.size(); i++)
    {
        updated.erase(updated.begin()+i);
    }
    if(min)
    {
        sort(updated.begin(),updated.end(),[](const Product& a, const Product& b) {
            return a.get_price() < b.get_price();});
    }
    else if(max)
    {
        sort(updated.begin(),updated.end(),[](const Product& a, const Product& b) {
            return a.get_price() > b.get_price();});
    }
    else if(oldest)
    {
        reverse(updated.begin(),updated.end());
    }
    else if(M_shopped)
    {
        sort(updated.begin(),updated.end(),[](const Product& a, const Product& b) {
            return a.get_bought() > b.get_bought();});
    }
    else if(M_viewed)
    {
//        sort(updated.begin(),updated.end(),[](const Product& a, const Product& b) {
//            return a.get_view() > b.get_view();});
    }
    else if(newest||none)
        return updated;
    return updated;
}


//bool incresingorder(Product a, Product b, QString order)
//{
//    if(order == "MintoMax")
//        return a.get_price() < b.get_price();
//    else if(order == "MaxtoMin")
//        return a.get_price() > b.get_price();
//    else if(order == "Mostshopped")
//        return a.get_bought() < b.get_bought();
//    else if(order == )
//    return true;
//}
