#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <string> 
#include <vector> 
#include "User.h"
#include "Restaurant.h"
#include "MenuItem.h"
#include "../strategies/PaymentStrategy.h"
#include "../utils/TimeUtils.h"

using namespace std ;

class Order{

protected:
     static int nextOrder;
     int orderId ;
     User* user ;
     Restaurant* restaurant;
     vector<MenuItem> items;
     PaymentStrategy* paymentStrategy;
     double total;
     string scheduled;

public:
    Order(){
        orderId = ++nextOrder;
        user = nullptr;
        restaurant = nullptr;
        paymentStrategy = nullptr;
        total = 0.0;
        scheduled = "";
    } 

    virtual ~Order(){
        delete paymentStrategy;
    }

    bool processPaymet(){
        if(paymentStrategy){
            paymentStrategy->pay(total);
            return true ;
        }else{
            cout<<"Please choose a payment method first"<<endl;
            return false;
        }
    }

    virtual string getType() const = 0;

    int getOrderId() const {
        return orderId;
    }

    void setUser(User* u){
        user = u;
    }

    User* getUser() const {
        return user;
    }

    void setRestaurant(Restaurant* r){
        restaurant = r;
    }

    Restaurant* getRestaurant() const {
        return restaurant;
    }

    void setItems(const vector<MenuItem>& itemList){
        items = itemList;
        total = 0;
        for(auto &it : items){
            total+=it.getPrice();
        }
    }

    vector<MenuItem> getItems() const {
        return items;
    }

    void setPaymentStrategy(PaymentStrategy* s){
        paymentStrategy = s;
    }

    void setScheduled(const string& s){
        scheduled = s;
    }

    string getScheduled() const {
        return scheduled;
    }
    double getTotal() const {
        return total;
    }
    
    void setTotal(int total){
        this->total = total ;
    }
};

int Order::nextOrder = 0;

#endif // ORDER_H
