#include <iostream>
#include <string>
using namespace std;

class Resturant;
class Order;

class Customer {
	string name;
public:
	Customer(string n="Unknown"): name(n) {}
	string GetName() const {
		return name;
	}
	void placeOrder(Resturant *r, string food);
};

class Resturant {
	string name;
public:
	Resturant(string n="Unknown"): name(n) {}
	string GetName() const {
		return name;
	}
	void takeOrder(Order *o);
};

void Customer::placeOrder(Resturant *r, string food){
	cout << name << " placed order at " << r->GetName() << " of " << food << endl;
}

class Order {
	static const int StartId=1001;
	static int OrderCount;
	int id;
	Customer customer;
	Resturant resturant;
	string foodItem;
public:
	Order(Customer c,Resturant r,string item){
		id=StartId+OrderCount;
		customer=c;
		resturant=r;
		foodItem=item;
		OrderCount++;
	}
	string GetfoodItem() const {
		return foodItem;
	}
	void show() const {
		cout << "Order #" << id << ": " << foodItem << " for " << customer.GetName() << " from " << resturant.GetName() << endl;
	}
};

void Resturant::takeOrder(Order *o){
	cout << name << " making: " << o->GetfoodItem() << endl;
}

int Order::OrderCount=0;

int main(){
	Customer c1("Bob"),c2("Alice");
	Resturant r1("Pizza Heaven"),r2("Taco Bell");
	Order o1(c1,r1,"Pepproni Pizza"),o2(c2,r2,"Cheese Taco");
	cout << "Placing Orders\n";
	c1.placeOrder(&r1,"Pepproni Pizza");
	c2.placeOrder(&r2,"Cheese Taco");
	cout << "\nOrder Details\n";
	o1.show();
	o2.show();
	cout << "\nResturant Status\n";
	r1.takeOrder(&o1);
	r2.takeOrder(&o2);
	return 0;
}