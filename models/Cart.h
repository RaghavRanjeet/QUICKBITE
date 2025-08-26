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
};

#endif // CART_H