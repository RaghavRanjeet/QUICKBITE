#ifndef QUICKBITEAPP_H
#define QUICKBITEAPP_H

#include <vector> 
#include <string>
#include "models/User.h"
#include "models/Restaurant.h"
#include "models/Cart.h"
#include "managers/OrderManager.h"
#include "managers/RestaurantManager.h"
#include "strategies/PaymentStrategy.h"
#include "strategies/UpiPaymentStrategy.h"
#include "factories/NowOrderFactory.h"
#include "factories/ScheduledOrderFactory.h"
#include "services/NotificationService.h"
#include "utils/TimeUtils.h"
using json = nlohmann::json;
using namespace std ;

class QuickBite{
public:
    QuickBite(){
        initializeRestaurants();
    }

    void initializeRestaurants(){
        Restaurant* restaurant1 = new Restaurant("Bikaner", "Delhi");
        restaurant1->addMenuItem(MenuItem("P1", "Chole Bhature", 120));
        restaurant1->addMenuItem(MenuItem("P2", "Samosa", 15));

        Restaurant* restaurant2 = new Restaurant("Haldiram", "Kolkata");
        restaurant2->addMenuItem(MenuItem("P1", "Raj Kachori", 80));
        restaurant2->addMenuItem(MenuItem("P2", "Pav Bhaji", 100));
        restaurant2->addMenuItem(MenuItem("P3", "Dhokla", 50));

        Restaurant* restaurant3 = new Restaurant("Saravana Bhavan", "Chennai");
        restaurant3->addMenuItem(MenuItem("P1", "Masala Dosa", 90));
        restaurant3->addMenuItem(MenuItem("P2", "Idli Vada", 60));
        restaurant3->addMenuItem(MenuItem("P3", "Filter Coffee", 30));

        RestaurantManager* restaurantManager = RestaurantManager::getInstance();
        restaurantManager->addRestaurant(restaurant1);
        restaurantManager->addRestaurant(restaurant2);
        restaurantManager->addRestaurant(restaurant3);

    }

    vector<Restaurant*> searchRestaurants(const string& location) {
        return RestaurantManager::getInstance()->searchByLocation(location);
    }

    void selectRestaurant(User* user, Restaurant* restaurant) {
        Cart* cart = user->getCart();
        cart->setRestaurant(restaurant);
    }

    void addToCart(User* user, const string& itemCode) {
        Restaurant* restaurant = user->getCart()->getRestaurant();
        if (!restaurant) {
            cout << "Please select a restaurant first." << endl;
            return;
        }
        for (const auto& item : restaurant->getMenu()) {
            if (item.getCode() == itemCode) {
                user->getCart()->addItem(item);
                break;
            }
        }
    }
    
     void payForOrder(User* user, Order* order) {
        bool isPaymentSuccess = order->processPayment();

        // clear user cart if payment is successful.
        if(isPaymentSuccess) {
            NotificationService* notification = new NotificationService();
            notification->notify(order);
            user->getCart()->clear();
        }  
    }

    void printUserCart(User* user) {
        cout << "Items in cart:" << endl;
        cout << "------------------------------------" << endl;
        for (const auto& item : user->getCart()->getItems()) {
            cout << item.getCode() << " : " << item.getName() << " : ₹" << item.getPrice() << endl;
        }
        cout << "------------------------------------" << endl;
        cout << "Grand total : ₹" << user->getCart()->getTotalCost() << endl;
    }

};

#endif // QUICKBITEAPP_H
