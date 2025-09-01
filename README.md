# QuickBite  
A console-based food delivery management system built using **C++** and **Object-Oriented Programming (OOP)** principles.  

This project demonstrates real-world application of OOP concepts such as **Encapsulation, Inheritance, Polymorphism, Abstraction**, and common **Design Patterns** to simulate a modern food ordering platform.  

---

##  Features  
- **User Management**: Sign up, log in, and maintain user profiles.  
- **Restaurant & Menu**: Browse restaurants and dynamic menus.  
- **Cart & Orders**: Add/remove items, place orders, and view order history.  
- **Payment System**: Multiple payment options (UPI, Card, NetBanking) using **Strategy Pattern**.  
- **Order Types**: Pickup, Delivery, and Scheduled Orders using **Factory Pattern**.  
- **Admin Panel**: Manage restaurants, menus, and track orders.  
- **Persistence**: File-based storage of user data and order history.  
- **Notifications**: Alerts for order updates using a basic notification service.  

---

## OOP Concepts Implemented  
- **Encapsulation** → Classes for `User`, `Restaurant`, `MenuItem`, `Cart`, and `Order`.  
- **Inheritance & Polymorphism** → Payment strategies and different order types.  
- **Abstraction** → Interfaces (`IOrderFactory`, `IPaymentStrategy`) for modular design.  
- **Design Patterns** →  
  - **Strategy Pattern** → Payment handling.  
  - **Factory Pattern** → Order creation.  
  - **Singleton Pattern** → `OrderManager` and `RestaurantManager`.  

---

## UML Class Diagram  
The following UML diagram illustrates the architecture and design of **QuickBite**:  

![QuickBite UML](/quickbite-UML.png)  

---

## Future Improvements  
- Add **database integration** (MySQL/PostgreSQL) for persistent storage.  
- Build a **GUI/React frontend** and connect with APIs.  
- Implement **real-time order tracking** and notifications.  
- Add support for more **payment gateways** (PayPal, Wallets, etc.).  

---



