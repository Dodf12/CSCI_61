#include <iostream>
#include <queue>
#include <thread>
#include <chrono>
using namespace std;

//Food order Struct
struct FoodOrder
{
  string orderName;
  int priorityNum;
};

void processOrder(FoodOrder currentOrder)
 {

    //Says teh order and priority number
    cout << "Preparing " << currentOrder.orderName << " "<< "(Priority: " << currentOrder.priorityNum << ")" << endl;
    
    // Doing the required 2 second delay
    this_thread::sleep_for(chrono::seconds(2));
    
    //Says user order is done
    cout << "Order for" << currentOrder.orderName << " "<< "(Priority: " << currentOrder.priorityNum << ") is ready" <<endl;
}

//Overloaded both the < and > to compare the priority number for each FoodOrder object
bool operator < (const FoodOrder& obj1, const FoodOrder& obj2)
{
    bool result = obj1.priorityNum < obj2.priorityNum;
    return result;
}

bool operator > (const FoodOrder& obj1, const FoodOrder& obj2)
{
    bool result = obj1.priorityNum > obj2.priorityNum;
    return result;
}



int main() 
{
    priority_queue<FoodOrder> Orders;
    
    // Adding elements to priority queue.
    Orders.push({"Pizza", 3});
    Orders.push({"Burger", 2});
    Orders.push({"Salad", 1});
    Orders.push({"Pasta", 3});
    Orders.push({"Ice Cream", 2});
    
    //Output Results
    cout << "Restaurant Orders:" << endl;
    while (!Orders.empty()) 
    {
        processOrder(Orders.top());
        Orders.pop();
    }
    
    return 0;
}