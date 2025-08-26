#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <iostream>
#include <string> 
#include <vector> 
#include "MenuItem.h"
using namespace std;


class Restaurant {
private:
    string name;
    string location;
    vector<MenuItem> menu;
    int restaurantId;
    static int nextRestaurantId;

public:
    Restaurant(string &name, string &location){
        this->name = name ;
        this->location = location ;
        this->restaurantId = ++nextRestaurantId;
    }

    string getName() const {
        return name;
    }

    void setName(const string &n){
        name = n;
    }

    string getLocation() const {
        return location;
    }

    void setLocation(const string &loc){
        location = loc;
    }

    void addMenuItem(const MenuItem &item) {
        menu.push_back(item);
    }

    const vector<MenuItem>& getMenu() const {
        return menu;
    }

    ~Restaurant() {
        // Destructor
        cout<<"Destroying Restaurant: " << name << ", and clearing its menu" << endl;
        menu.clear();
    }
};

int Restaurant::nextRestaurantId = 0;

#endif
