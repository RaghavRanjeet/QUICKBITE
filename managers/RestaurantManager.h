#ifndef RESTAURANTMANAGER_H
#define RESTAURANTMANAGER_H

#include <vector> 
#include <string> 
#include <algorithm>
#include "../models/Restaurant.h"
using namespace std ;

class RestaurantManager{
private:
    vector<Restaurant*> restaurants;
    static RestaurantManager* instance;

    RestaurantManager(){
        // Private constructor
    }

public:
    static RestaurantManager* getInstance(){
        if(instance == nullptr){
            instance = new RestaurantManager();
        }
        return instance;
    }

    void addRestaurant(Restaurant* restaurant){
        restaurants.push_back(restaurant);
    }

    vector<Restaurants*> searchByLocation(string loc){
        vector<Restaurant*> result;
        transform(loc.begin(),loc.end(),loc.begin(), ::tolower);
        for(auto r: restaurants){
            string r1 = r->getLocation();
            transform(r1.begin(), r1.end(), r1.begin(), ::tolower);
            if(r1 == loc){
                result.push_back(r);
            }
        }
        return result;
    }
};

RestaurantManager* RestaurantManager::instance = nullptr;

#endif // RESTAURANTMANAGER_H