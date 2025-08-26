#ifndef ORDERMANAGER_H
#define ORDERMANAGER_H

#include<vector>
#include <iostream>
#include "../models/Order.h"

using namespace std ;

class OrderManager{

private:
    vector<Order*> orders;
    static OrderManager* instance;

    OrderManager(){
        // Private constructor
    }

public:
    static OrderManager* getInstance() {
        if (instance == nullptr) {
            instance = new OrderManager();
        }
        return instance;
    }

    void addOrder(Order* order) {
        orders.push_back(order);
    }

    void listOrders(){
        cout<<"\n---ALL ORDERS---"
        for (auto order : orders) {
            cout << order->getType() << " order for " << order->getUser()->getName()
                    << " | Total: ₹" << order->getTotal()
                    << " | At: " << order->getScheduled() << endl;
        }
    }

};

OrderManager* OrderManager::instance = nullptr;

#endif // ORDERMANAGER_H