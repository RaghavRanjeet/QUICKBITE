#ifndef CART_H
#define CART_H

#include <iostream>
#include <vector> 
#include <string> 
#include "../models/MenuItem.h"
#include "../models/Restaurant.h"

using namespace std;

class Cart{

private:
   Restaurant* restaurant;
   vector<MenuItem> items;

public:
    Cart(){
        restaurant = nullptr;
    }

    void addItem(const MenuItem &item){
        if(!restaurant){
            cerr << "No restaurant selected." << endl;
            return;
        }
        items.push_back(item);
    }

    void setRestaurant(Restaurant* res){
        restaurant = res;
    }

    Restaurant* getRestaurant() const{
        return restaurant;
    }

    double getTotalCost() const{
        double total = 0.0;
        for(const auto& item: items){
            total += item.getPrice();
        }
        return total;
    }

    bool isEmpty(){
        return (!restaurant && items.empty());
    }

    void clear(){
        items.clear();
        restaurant = nullptr;
    }

    const vector<MenuItem>& getItems() const{
        return items;
    }

    Order* checkoutNow(User* user, const string& orderType, PaymentStrategy* paymentStrategy) {
        return checkout(user, orderType, paymentStrategy, new NowOrderFactory());
    }

    Order* checkoutScheduled(User* user, const string& orderType, PaymentStrategy* paymentStrategy, const string& scheduleTime) {
        return checkout(user, orderType, paymentStrategy, new ScheduledOrderFactory(scheduleTime));
    }

    Order* checkout(User* user, const string& orderType, 
        PaymentStrategy* paymentStrategy, OrderFactory* orderFactory) {
        if (user->getCart()->isEmpty())
        return nullptr;

        Cart* userCart = user->getCart();
        Restaurant* orderedRestaurant = userCart->getRestaurant();
        vector<MenuItem> itemsOrdered = userCart->getItems();
        double totalCost = userCart->getTotalCost();

        Order* order = orderFactory->createOrder(user, userCart, orderedRestaurant, itemsOrdered, paymentStrategy, totalCost, orderType);
        OrderManager::getInstance()->addOrder(order);
        return order;
    }
     
};

#endif // CART_H