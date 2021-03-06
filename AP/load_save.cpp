#include "load_save.h"

void save_client(vector<Client>& client_user)
{
    QJsonArray names, addresses, emails, phones, users, passwords, shopped, balances, deleted_times, login_res, buy_res, balance_res,
               themes;
    for(unsigned int i = 0; i<client_user.size(); i++)
    {
        names.append(client_user[i].get_name());
        addresses.append(client_user[i].get_address());
        emails.append(client_user[i].get_email());
        phones.append(client_user[i].get_phone_number());
        users.append(client_user[i].get_user_name());
        passwords.append(client_user[i].get_password());
        balances.append(QString::number(client_user[i].get_balance()));
        deleted_times.append(client_user[i].get_delete_time());
        login_res.append(client_user[i].get_login_restriction());
        buy_res.append(client_user[i].get_buy_add_restriction());
        balance_res.append(client_user[i].get_change_balance_restriction());
        themes.append(client_user[i].get_theme());
        QString line;
        for (unsigned int j = 0; j<client_user[i].get_shopped_items().size(); j++)
        {
            line = client_user[i].get_user_name();
            line.append(",");
            line.append(client_user[i].get_shopped_items()[j].get_name());
            line.append(",");
            line.append(client_user[i].get_shopped_items()[j].get_costumer_username());
            line.append(",");
            line.append(QString::number(client_user[i].get_shopped_items()[j].get_added_to_cart()));
            line.append(",");
            line.append(QString::number(client_user[i].get_shopped_items()[j].get_price()));
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
    j["Balance"] = balances;
    j["Delete_Time"] = deleted_times;
    j["Login_Restriction"] = login_res;
    j["Buy_Restriction"] = buy_res;
    j["Balance_Restriction"] = balance_res;
    j["Themes"] = themes;

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
    len = balances.count();
    for(int i=0; i<len; i++)
        balances.removeAt(0);
    len = deleted_times.count();
    for(int i=0; i<len; i++)
        deleted_times.removeAt(0);
    len = login_res.count();
    for(int i=0; i<len; i++)
        login_res.removeAt(0);
    len = buy_res.count();
    for(int i=0; i<len; i++)
        buy_res.removeAt(0);
    len = balance_res.count();
    for(int i=0; i<len; i++)
        balance_res.removeAt(0);
    len = themes.count();
    for(int i=0; i<len; i++)
        themes.removeAt(0);
}

void save_costumer(vector<Costumer> costumer_user)
{
    QJsonArray names, addresses, emails, phones, users, passwords, balances, deleted_times, login_res, add_res, balance_res,
               themes;
    for(unsigned int i = 0; i<costumer_user.size(); i++)
    {
        names.append(costumer_user[i].get_name());
        addresses.append(costumer_user[i].get_address());
        emails.append(costumer_user[i].get_email());
        phones.append(costumer_user[i].get_phone_number());
        users.append(costumer_user[i].get_user_name());
        passwords.append(costumer_user[i].get_password());
        balances.append(QString::number(costumer_user[i].get_balance()));
        deleted_times.append(costumer_user[i].get_delete_time());
        login_res.append(costumer_user[i].get_login_restriction());
        add_res.append(costumer_user[i].get_buy_add_restriction());
        balance_res.append(costumer_user[i].get_change_balance_restriction());
        themes.append(costumer_user[i].get_theme());
    }

    QJsonObject j;
    j["Names"] = names;
    j["Addresses"] = addresses;
    j["Emails"] = emails;
    j["Phones"] = phones;
    j["Users"] = users;
    j["Passwords"] = passwords;
    j["Balance"] = balances;
    j["Delete_Time"] = deleted_times;
    j["Login_Restriction"] = login_res;
    j["Add_Restriction"] = add_res;
    j["Balance_Restriction"] = balance_res;
    j["Themes"] = themes;

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
    len = balances.count();
    for(int i=0; i<len; i++)
        balances.removeAt(0);
    len = deleted_times.count();
    for(int i=0; i<len; i++)
        deleted_times.removeAt(0);
    len = login_res.count();
    for(int i=0; i<len; i++)
        login_res.removeAt(0);
    len = add_res.count();
    for(int i=0; i<len; i++)
        add_res.removeAt(0);
    len = balance_res.count();
    for(int i=0; i<len; i++)
        balance_res.removeAt(0);
    len = themes.count();
    for(int i=0; i<len; i++)
        themes.removeAt(0);
}

void save_client(Client & user)
{
    QFile f("All_client.json");
    f.open(QIODevice::ReadOnly);
    QByteArray b = f.readAll();
    QJsonDocument d = QJsonDocument::fromJson(b);
    QJsonObject o = d.object();
    QJsonArray names, addresses, emails, phones, users, passwords, old_shopped, new_shopped, balances, deleted_times,
               login_res, buy_res, balance_res, themes;
    names = o["Names"].toArray();
    addresses = o["Addresses"].toArray();
    emails = o["Emails"].toArray();
    phones = o["Phones"].toArray();
    users = o["Users"].toArray();
    old_shopped = o["Shopped"].toArray();
    passwords = o["Passwords"].toArray();
    balances = o["Balance"].toArray();
    deleted_times = o["Delete_Time"].toArray();
    login_res = o["Login_Restriction"].toArray();
    buy_res = o["Buy_Restriction"].toArray();
    balance_res = o["Balance_Restriction"].toArray();
    themes = o["Themes"].toArray();
    f.close();

    for (int l = 0; l <old_shopped.size(); l++)
    {
        string dummyLine = old_shopped[l].toString().toStdString();
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
        if(line_splitted[0] != user.get_user_name().toStdString())
        {
            new_shopped.append(old_shopped[l]);
        }
    }

    QString line = "";
    for (unsigned int j = 0; j<user.get_shopped_items().size(); j++)
    {
        line = user.get_user_name();
        line.append(",");
        line.append(user.get_shopped_items()[j].get_name());
        line.append(",");
        line.append(user.get_shopped_items()[j].get_costumer_username());
        line.append(",");
        line.append(QString::number(user.get_shopped_items()[j].get_added_to_cart()));
        line.append(",");
        line.append(QString::number(user.get_shopped_items()[j].get_price()));
        line.append(",");
        new_shopped.append(line);
    }

    QJsonObject j;
    j["Names"] = names;
    j["Addresses"] = addresses;
    j["Emails"] = emails;
    j["Phones"] = phones;
    j["Users"] = users;
    j["Passwords"] = passwords;
    j["Shopped"] = new_shopped;
    j["Balance"] = balances;
    j["Delete_Time"] = deleted_times;
    j["Login_Restriction"] = login_res;
    j["Buy_Restriction"] = buy_res;
    j["Balance_Restriction"] = balance_res;
    j["Themes"] = themes;

    QJsonDocument d2(j);
    f.open(QIODevice::WriteOnly);
    f.write(d2.toJson());
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
    len = old_shopped.count();
    for(int i=0; i<len; i++)
        old_shopped.removeAt(0);
    len = new_shopped.count();
    for(int i=0; i<len; i++)
        new_shopped.removeAt(0);
    len = balances.count();
    for(int i=0; i<len; i++)
        balances.removeAt(0);
    len = deleted_times.count();
    for(int i=0; i<len; i++)
        deleted_times.removeAt(0);
    len = login_res.count();
    for(int i=0; i<len; i++)
        login_res.removeAt(0);
    len = buy_res.count();
    for(int i=0; i<len; i++)
        buy_res.removeAt(0);
    len = balance_res.count();
    for(int i=0; i<len; i++)
        balance_res.removeAt(0);
    len = themes.count();
    for(int i=0; i<len; i++)
        themes.removeAt(0);
}

void save_product(vector<Product> products)
{
    QJsonArray names, brands, types, colors, prices, stocks, sizes, additional_info, weights, costumers, boughts, paths, add_cart,
               views;
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
        add_cart.append(products[i].get_added_to_cart());
        views.append(products[i].get_viewed());
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
    j["Cart"] = add_cart;
    j["Views"] = views;

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
    len = add_cart.count();
    for(int i=0; i<len; i++)
        add_cart.removeAt(0);
    len = views.count();
    for(int i=0; i<len; i++)
        views.removeAt(0);
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
        QJsonArray names, brands, types, colors, prices, stocks, sizes, additional_info, weights, costumers, boughts, paths, add_cart,
                   views;
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
        add_cart = o["Cart"].toArray();
        views = o["Views"].toArray();
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
        add_cart.append(pro.get_added_to_cart());
        views.append(pro.get_viewed());

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
        j["Cart"] = add_cart;
        j["Views"] = views;

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
        len = add_cart.count();
        for(int i=0; i<len; i++)
            add_cart.removeAt(0);
        len = views.count();
        for(int i=0; i<len; i++)
            views.removeAt(0);
    }
    else
    {
        QJsonArray names, brands, types, colors, prices, stocks, sizes, additional_info, weights, costumers, boughts, paths, add_cart;
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
        add_cart.append(pro.get_added_to_cart());

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
        j["Cart"] = add_cart;

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
        len = add_cart.count();
        for(int i=0; i<len; i++)
            add_cart.removeAt(0);
    }
}

vector<Client> load_client()
{
    QFile f("All_client.json");
    f.open(QIODevice::ReadOnly);
    QByteArray b = f.readAll();
    QJsonDocument d = QJsonDocument::fromJson(b);
    QJsonObject o = d.object();
    QJsonArray names, addresses, emails, phones, users, passwords, shopped, balances, deleted_times, login_res, buy_res, balance_res,
               themes;

    names = o["Names"].toArray();
    addresses = o["Addresses"].toArray();
    emails = o["Emails"].toArray();
    phones = o["Phones"].toArray();
    users = o["Users"].toArray();
    shopped = o["Shopped"].toArray();
    passwords = o["Passwords"].toArray();
    balances = o["Balance"].toArray();
    deleted_times = o["Delete_Time"].toArray();
    login_res = o["Login_Restriction"].toArray();
    buy_res = o["Buy_Restriction"].toArray();
    balance_res = o["Balance_Restriction"].toArray();
    themes = o["Themes"].toArray();

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
        tmp->set_balance(stoi(balances[i].toString().toStdString()));
        tmp->set_time_delete(deleted_times[i].toInt());
        tmp->set_login_restriction(login_res[i].toBool());
        tmp->set_buy_add_restriction(buy_res[i].toBool());
        tmp->set_change_balance_restriction(balance_res[i].toBool());
        tmp->set_theme(themes[i].toBool());
        if((deleted_times[i].toInt()) != -1)
            tmp->set_deleted_status(true);
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
                       all_products[k].get_costumer_username().toStdString() == line_splitted[2]
                       && QString::number(all_products[k].get_price()).toStdString() == line_splitted[4])
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
                        temporary.set_added_to_cart(stoi(line_splitted[3]));
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
    len = balances.count();
    for(int i=0; i<len; i++)
        balances.removeAt(0);
    len = deleted_times.count();
    for(int i=0; i<len; i++)
        deleted_times.removeAt(0);
    len = login_res.count();
    for(int i=0; i<len; i++)
        login_res.removeAt(0);
    len = buy_res.count();
    for(int i=0; i<len; i++)
        buy_res.removeAt(0);
    len = balance_res.count();
    for(int i=0; i<len; i++)
        balance_res.removeAt(0);
    len = themes.count();
    for(int i=0; i<len; i++)
        themes.removeAt(0);
    return client_tmp;
}

vector<Costumer> load_costumer()
{
    QFile f("All_costumer.json");
    f.open(QIODevice::ReadOnly);
    QByteArray b = f.readAll();
    QJsonDocument d = QJsonDocument::fromJson(b);
    QJsonObject o = d.object();
    QJsonArray names, addresses, emails, phones, users, passwords, balances, deleted_times, login_res, add_res, balance_res,
               themes;

    names = o["Names"].toArray();
    addresses = o["Addresses"].toArray();
    emails = o["Emails"].toArray();
    phones = o["Phones"].toArray();
    users = o["Users"].toArray();
    passwords = o["Passwords"].toArray();
    balances = o["Balance"].toArray();
    deleted_times = o["Delete_Time"].toArray();
    login_res = o["Login_Restriction"].toArray();
    add_res = o["Add_Restriction"].toArray();
    balance_res = o["Balance_Restriction"].toArray();
    themes = o["Themes"].toArray();

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
        tmp->set_balance(stoi(balances[i].toString().toStdString()));
        tmp->set_time_delete(deleted_times[i].toInt());
        tmp->set_login_restriction(login_res[i].toBool());
        tmp->set_buy_add_restriction(add_res[i].toBool());
        tmp->set_change_balance_restriction(balance_res[i].toBool());
        tmp->set_theme(themes[i].toBool());
        if((deleted_times[i].toInt()) != -1)
            tmp->set_deleted_status(true);
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
    len = balances.count();
    for(int i=0; i<len; i++)
        balances.removeAt(0);
    len = deleted_times.count();
    for(int i=0; i<len; i++)
        deleted_times.removeAt(0);
    len = login_res.count();
    for(int i=0; i<len; i++)
        login_res.removeAt(0);
    len = add_res.count();
    for(int i=0; i<len; i++)
        add_res.removeAt(0);
    len = balance_res.count();
    for(int i=0; i<len; i++)
        balance_res.removeAt(0);
    len = themes.count();
    for(int i=0; i<len; i++)
        themes.removeAt(0);
    return costumer_tmp;
}

vector<Product> load_product()
{
    QFile f("All_product.json");
    f.open(QIODevice::ReadOnly);
    QByteArray b = f.readAll();
    QJsonDocument d = QJsonDocument::fromJson(b);
    QJsonObject o = d.object();
    QJsonArray names, brands, types, colors, prices, stocks, sizes, additional_info, weights, costumers, boughts, paths, add_cart,
               views;
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
    add_cart = o["Cart"].toArray();
    views = o["Views"].toArray();
    f.close();

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
        tmp->set_path(paths[i].toString());
        tmp->set_added_to_cart(add_cart[i].toInt());
        tmp->set_viewed(views[i].toInt());
        product_tmp.push_back(*tmp);
        delete(tmp);
    }
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
    len = add_cart.count();
    for(int i=0; i<len; i++)
        add_cart.removeAt(0);

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
        // client user, product_name, costumer_user, brand, type, color, addinfo, path, count, total price, weight, date_time, address
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
        for(int i = 0; i < names.size(); i++)
        {
            if(names[i] == tmp.get_client_user_name())
            {
                flag = true;
                break;
            }
        }
        if(!flag)
            names.append(tmp.get_client_user_name());

        QString line = "";
        line.append(tmp.get_client_user_name());
        line.append(",");
        line.append(tmp.get_bought_product()[0].get_name());
        line.append(",");
        line.append(tmp.get_bought_product()[0].get_costumer_username());
        line.append(",");
        line.append(tmp.get_bought_product()[0].get_brand());
        line.append(",");
        line.append(tmp.get_bought_product()[0].get_type());
        line.append(",");
        line.append(tmp.get_bought_product()[0].get_color());
        line.append(",");
        line.append(tmp.get_bought_product()[0].get_additional_info());
        line.append(",");
        line.append(tmp.get_bought_product()[0].get_path());
        line.append(",");
        line.append(QString::number(tmp.get_bought_product()[0].get_added_to_cart()));
        line.append(",");
        line.append(QString::number(tmp.get_bought_product()[0].get_price() * tmp.get_bought_product()[0].get_added_to_cart()));
        line.append(",");
        line.append(QString::number(tmp.get_bought_product()[0].get_weight()));
        line.append(",");
        line.append(tmp.get_date_time());
        line.append(",");
        line.append(tmp.get_address());
        line.append(",");
        products.append(line);
        QJsonObject j;
        j["Names"] = names;
        j["Products"] = products;
        QJsonDocument d2(j);
        f.open(QIODevice::WriteOnly);
        f.write(d2.toJson());
        f.close();
        int len = names.count();
        for(int i=0; i<len; i++)
            names.removeAt(0);
        len = products.count();
        for(int i=0; i<len; i++)
            products.removeAt(0);
        line.clear();
    }
}

vector<Transaction> load_transaction()
{
    vector<Transaction> trans;
    // client user, product_name, costumer_user, brand, type, color, addinfo, path, count, total price, weight, date_time, address
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
    for(int j = 0; j < products.size(); j++)
    {
        vector<Product> bought_products;
        string dummyLine = products[j].toString().toStdString();
        size_t pos = 0;
        string token;
        string delimiter = ",";
        vector<string> splitted_line;
        while ((pos = dummyLine.find(delimiter)) != string::npos) // getting data from the file
        {
            token = dummyLine.substr(0, pos);
            splitted_line.push_back(token);
            dummyLine.erase(0, pos + delimiter.length());
        }

        tmp.set_client_user_name(QString::fromStdString(splitted_line[0]));
        Product temp;
        temp.set_name(QString::fromStdString(splitted_line[1]));
        temp.set_costumer_username(QString::fromStdString(splitted_line[2]));
        temp.set_brand(QString::fromStdString(splitted_line[3]));
        temp.set_type(QString::fromStdString(splitted_line[4]));
        temp.set_color(QString::fromStdString(splitted_line[5]));
        temp.set_additional_info(QString::fromStdString(splitted_line[6]));
        temp.set_path(QString::fromStdString(splitted_line[7]));
        temp.set_bought(stoi(splitted_line[8]));
        temp.set_price(stoi(splitted_line[9]));
        temp.set_weight(stoi(splitted_line[10]));
        tmp.set_date_time(QString::fromStdString(splitted_line[11]));
        tmp.set_address(QString::fromStdString(splitted_line[12]));
        bought_products.push_back(temp);
        tmp.set_bought_product(bought_products);
        trans.push_back(tmp);
    }
    return trans;
}

vector<Product> sort_function(vector<Product> allproducts, QString from_price, QString to_price, QString from_weight, QString to_weight, QString color, QString brand, QString type, bool min, bool max, bool newest, bool oldest, bool M_shopped, bool M_viewed, bool none, bool availale)
{
    vector<Product> updated = allproducts;
    vector<unsigned long long int> list;
    for(unsigned long long int i = 0; i <updated.size() ;i++)
    {
        // color || brand || type

        if(color != "")
        {    if(updated[i].get_color() != color)
            {
                list.push_back(i);
                continue;
            }
        }
        if(brand != "")
        {    if(updated[i].get_brand() != brand)
            {
                list.push_back(i);
                continue;
            }
        }
        if(type != "")
        {    if(updated[i].get_type() != type)
            {
                list.push_back(i);
                continue;
            }
        }
        if(availale)
        {    if(updated[i].get_stock() == 0)
            {
                list.push_back(i);
                continue;
            }
        }




        //price

        if(from_price == "" && to_price != "")
        {
            if(updated[i].get_price()>to_price.toInt())
            {
                list.push_back(i);
                continue;
            }
        }
        else if(from_price != "" && to_price == "")
        {
            if(updated[i].get_price()<from_price.toInt())
            {
                list.push_back(i);
                continue;
            }
        }
        else if(from_price != ""&& to_price != "")
        {
            if(updated[i].get_price()<from_price.toInt()||updated[i].get_price()>to_price.toInt())
            {
                list.push_back(i);
                continue;
            }
        }

        //weight

        if(from_weight == "" && to_weight != "")
        {
            if(updated[i].get_weight()>to_weight.toInt())
            {
                list.push_back(i);
                continue;
            }
        }
        else if(from_weight != "" && to_weight == "")
        {
            if(updated[i].get_weight()<from_weight.toInt())
            {
                list.push_back(i);
                continue;
            }
        }
        else if(from_weight != ""&& to_weight != "")
        {
            if(updated[i].get_weight()<from_weight.toInt()||updated[i].get_weight()>to_weight.toInt())
            {
                list.push_back(i);
                continue;
            }
        }
    }


    //erase


    sort(list.begin(), list.end(), greater<int>());
    for(unsigned long long int i = 0; i<list.size(); i++)
    {
        updated.erase(updated.begin()+list[i]);
    }

    //sort

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
    else if(newest)
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
        sort(updated.begin(),updated.end(),[](const Product& a, const Product& b) {
            return a.get_viewed() > b.get_viewed();});
    }
    else if(oldest||none)
        return updated;
    return updated;
}

void check_and_create()
{
    if(!check_file("All_client.json"))
    {
        QJsonObject j;
        QJsonDocument d(j);
        QFile f("All_client.json");
        f.open(QIODevice::WriteOnly);
        f.write(d.toJson());
        f.close();
    }
    if(!check_file("All_costumer.json"))
    {
        QJsonObject j;
        QJsonDocument d(j);
        QFile f("All_costumer.json");
        f.open(QIODevice::WriteOnly);
        f.write(d.toJson());
        f.close();
    }
    if(!check_file("All_product.json"))
    {
        QJsonObject j;
        QJsonDocument d(j);
        QFile f("All_product.json");
        f.open(QIODevice::WriteOnly);
        f.write(d.toJson());
        f.close();
    }
    if(!check_file("All_transaction.json"))
    {
        QJsonObject j;
        QJsonDocument d(j);
        QFile f("All_transaction.json");
        f.open(QIODevice::WriteOnly);
        f.write(d.toJson());
        f.close();
    }
    if(!check_file("All_admin.txt"))
    {
        QFile f("All_admin.txt");
        f.open(QIODevice::WriteOnly);
        f.close();
    }
}

int current_client_index(QString username)
{
    vector <Client> _client = load_client();
    for (unsigned int i = 0 ; i < _client.size() ; i++ ){
        if (_client[i].get_user_name() == username){
            _client.clear();
            _client.shrink_to_fit();
            return i ;
        }
    }
    return -1;
}

int current_costumer_index(QString username)
{
    vector <Costumer> _costumer = load_costumer();
    for (unsigned int i = 0 ; i < _costumer.size() ; i++ ){
        if (_costumer[i].get_user_name() == username){
            _costumer.clear();
            _costumer.shrink_to_fit();
            return i ;
        }
    }
    return -1;
}

void add_viewed(vector<Product> &products, int index)
{
    products[index].set_viewed(products[index].get_viewed()+1);
}

QString show_balance(vector<Client> &clients, QString current)
{
    for (unsigned int i = 0 ; i < clients.size(); i++)
    {
        if (clients[i].get_user_name() == current)
            return "balance : "+QString::number(clients[i].get_balance());
    }
    return "";
}

void confirm_payment(QString client_id)
{
    int Index = current_client_index(client_id);
    vector<Product> all_products = load_product();
    vector<Client> all_clients = load_client();
    vector<Costumer> all_costumers = load_costumer();
    Transaction tmp;
    Transaction TEMP;
    TEMP.set_client_user_name(client_id);
    TEMP.set_date_time();
    TEMP.set_address(all_clients[Index].get_address());
    for (unsigned int i = 0  ; i < all_clients[Index].get_shopped_items().size() ; ++i)
    {
        for (unsigned int j = 0 ; j < all_products.size() ; ++j)
        {
            if (all_clients[Index].get_shopped_items()[i].get_name() == all_products[j].get_name()
                    && all_clients[Index].get_shopped_items()[i].get_costumer_username() == all_products[j].get_costumer_username())
            {
                 all_products[j].set_bought(all_products[j].get_bought() +
                 all_clients[Index].get_shopped_items()[i].get_added_to_cart());

                 all_products[j].set_stock(all_products[j].get_stock() -
                 all_clients[Index].get_shopped_items()[i].get_added_to_cart());

                 all_costumers[current_costumer_index(all_products[j].get_costumer_username())].set_balance(
                 all_costumers[current_costumer_index(all_products[j].get_costumer_username())].get_balance()
                 + (all_clients[Index].get_shopped_items()[i].get_price()*(all_clients[Index].get_shopped_items()[i].get_added_to_cart())));
            }
        }
        tmp.set_client_user_name(client_id);
        tmp.set_date_time();
        tmp.set_address(all_clients[Index].get_address());
        vector<Product> temp;
        temp.push_back(all_clients[Index].get_shopped_items()[i]);
        TEMP.push_product(temp[0]);
        tmp.set_bought_product(temp);
        save_transaction(tmp);
        temp.clear();
        temp.shrink_to_fit();
    }
    send_email(TEMP, client_id);
    all_clients[Index].clear_shopped_items();
    save_product(all_products);
    save_client(all_clients);
    save_costumer(all_costumers);
    all_clients.clear();
    all_clients.shrink_to_fit();
    all_products.clear();
    all_products.shrink_to_fit();
    all_costumers.clear();
    all_costumers.shrink_to_fit();

}

QString show_balance2(vector<Costumer> &costumers, QString current)
{
    for (unsigned int i = 0 ; i < costumers.size(); i++)
    {
        if (costumers[i].get_user_name() == current)
            return "balance : "+QString::number(costumers[i].get_balance());
    }
    return "";
}

bool check_email(QString email)
{
    const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return regex_match(email.toStdString(),pattern);
}

void check_accounts()
{
    vector<Client> clients = load_client();
    vector<Client> new_clients;
    vector<Costumer> costumers = load_costumer();
    vector<Costumer> new_costumers;
    vector<Product> products = load_product();
    vector<Product> new_products = products;
    const auto p1 = std::chrono::system_clock::now();
    int now = std::chrono::duration_cast<std::chrono::seconds>(p1.time_since_epoch()).count();

    for(unsigned int i = 0; i < clients.size(); i++)
    {
        if(clients[i].get_deleted_status() && ((now - clients[i].get_delete_time()) >= 259200))
        {
            vector<Admin> tmp = load_admin();
            for(unsigned int j = 0; j < tmp.size(); j++)
            {
                if(tmp[j].get_user_name() == clients[i].get_user_name())
                {
                    delete_from_admins(tmp[j].get_user_name());
                    break;
                }
            }
            tmp.clear();
            tmp.shrink_to_fit();
        }

        else
            new_clients.push_back(clients[i]);
    }

    int counter = 0;
    for(unsigned int i = 0; i < costumers.size(); i++)
    {
        if(costumers[i].get_deleted_status() && (now - costumers[i].get_delete_time() >= 259200))
        {
            for(unsigned int j = 0; j < products.size(); j++)
            {
                if(products[j].get_costumer_username() == costumers[i].get_user_name())
                {
                    new_products.erase(new_products.begin() + j - counter);
                    counter++;
                }
            }
            vector<Admin> tmp = load_admin();
            for(unsigned int j = 0; j < tmp.size(); j++)
            {
                if(tmp[j].get_user_name() == costumers[i].get_user_name())
                {
                    delete_from_admins(tmp[j].get_user_name());
                    break;
                }
            }
            tmp.clear();
            tmp.shrink_to_fit();
        }
        else
            new_costumers.push_back(costumers[i]);
    }

    clients.clear();
    clients.shrink_to_fit();
    costumers.clear();
    costumers.shrink_to_fit();
    products.clear();
    products.shrink_to_fit();
    save_client(new_clients);
    save_costumer(new_costumers);
    save_product(new_products);
    new_clients.clear();
    new_clients.shrink_to_fit();
    new_costumers.clear();
    new_costumers.shrink_to_fit();
    new_products.clear();
    new_products.shrink_to_fit();
}

void send_email(Transaction transactions, QString Clients_Id)
{
    vector <Client> global_clients = load_client();
    string text = "";
    int INDEX = current_client_index(Clients_Id);
    ofstream factor("temp.txt", ios::out);
    factor << global_clients[INDEX].get_name().toStdString() << endl;
    factor << global_clients[INDEX].get_email().toStdString() << endl;
    text += "Hello dear " + global_clients[INDEX].get_name().toStdString() + ", Thanks for your shopping from our store . \n";
    text += "Your orders has been sent at " + transactions.get_date_time().toStdString() + " . \nYou bought ";
    for (unsigned int i = 0 ; i < transactions.get_bought_product().size() ; ++i)
    {
        text += QString::number(transactions.get_bought_product()[i].get_added_to_cart()).toStdString() + " " +
                transactions.get_bought_product()[i].get_name().toStdString() + " for amount of " +
                QString::number(transactions.get_bought_product()[i].get_price()*transactions.get_bought_product()[i].get_added_to_cart()).toStdString() + " , ";
    }
    text.pop_back();
    text.pop_back();
    text += " . \n Address : " + global_clients[INDEX].get_address().toStdString();
    text += " . \n";
    text += "From Guys store <3 \n";
    factor << text ;
    factor.close();
    QStringList arguments { "../AP/main.py", "uzhsypapwsrayzdx" };
    QProcess p;
    p.start("python", arguments);
    p.waitForFinished();
}

vector<Admin> load_admin()
{
    ifstream admin("All_admin.txt", ios::in);
    vector<Admin> all_admins;
    if(admin.is_open())
    {
        string dummyLine;
        while (getline(admin, dummyLine))
        {
            if(dummyLine == "")
                break;
            size_t pos = 0;
            string token;
            string delimiter = ",";
            vector<string> splitted_line;
            while ((pos = dummyLine.find(delimiter)) != string::npos) // getting data from the file
            {
                token = dummyLine.substr(0, pos);
                dummyLine.erase(0, pos + delimiter.length());
                splitted_line.push_back(token);
            }
            Admin tmp;
            tmp.set_user_name(QString::fromStdString(splitted_line[0]));
            tmp.set_password(QString::fromStdString(splitted_line[1]));
            all_admins.push_back(tmp);
            splitted_line.clear();
            splitted_line.shrink_to_fit();
        }
    }
    admin.close();
    return all_admins;
}

void delete_from_admins(QString user)
{
    vector<Admin> admins = load_admin();
    for(unsigned int i = 0; i < admins.size(); i++)
    {
        if(admins[i].get_user_name() == user)
        {
            admins.erase(admins.begin() + i);
            break;
        }
    }
    // wipe data from file
    fstream admin("All_admin.txt", ofstream::out | ofstream::trunc);
    admin.close();

    //save to file
    for(unsigned int i = 0; i < admins.size(); i++)
        save_admin(admins[i]);

    admins.clear();
    admins.shrink_to_fit();
}

void save_admin(Admin new_admin)
{
    vector<Admin> admins = load_admin();
    bool flag = false;
    for(unsigned int i = 0; i < admins.size(); i++)
    {
        if(admins[i].get_user_name() == new_admin.get_user_name())
        {
            flag = true;
            break;
        }
    }

    if(!flag)
    {
        fstream admin("All_admin.txt", ios::app);
        if(admin.is_open())
        {
            admin << new_admin.get_user_name().toStdString() << "," << new_admin.get_password().toStdString() << "," << "\n";
        }
        admin.close();
    }
}
