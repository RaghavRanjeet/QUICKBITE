#ifndef SCHEDULEDORDERFACTORY_H
#define SCHEDULEDORDERFACTORY_H

#include "OrderFactory.h"
#include "../models/DeliveryOrder.h"
#include "../models/PickupOrder.h"
#include "../utils/TimeUtils.h"
using namespace std ;

class ScheduledOrderFactory : public OrderFactory {
    public:
        Order* createOrder(User* user, Cart* cart, Restaurant* restaurant, const vector<MenuItem>& menuItems,
                           PaymentStrategy* paymentStrategy, double totalCost, const string& orderType) override {
            Order* order = nullptr;
            if(orderType == "Delivery") {
                DeliveryOrder* deliveryOrder = new DeliveryOrder();
                deliveryOrder->setUserAddress(user->getAddress());
                order = deliveryOrder;
            } else if(orderType == "Pickup") {
                PickupOrder* pickupOrder = new PickupOrder();
                pickupOrder->setRestaurantAddress(restaurant->getLocation());
                order = pickupOrder;
            } else {
                cerr << "Invalid order type: " << orderType << endl;
                return nullptr;
            }

            order->setUser(user);
            order->setRestaurant(restaurant);
            order->setItems(menuItems);
            order->setPaymentStrategy(paymentStrategy);
            order->setTotal(totalCost);
            order->setScheduled(TimeUtils::getCurrentTime());

            return order;
        }
};

#endif // SCHEDULEDORDERFACTORY_H
