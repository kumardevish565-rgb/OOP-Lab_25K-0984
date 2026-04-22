#include <iostream>
#include <string>
using namespace std;

class Package {
protected:
    float weight;
public: 
    Package(float w): weight(w) {}
    virtual double calculateCost() = 0;
};

class LocalPackage : public Package {
public:
    LocalPackage(float w): Package(w) {}
    double calculateCost() override {
        if(weight>20) {
            return weight*5+20;
        }
        else {
            return weight*5;
        }
    }
};

class InternationalPackage : public Package {
public:
    InternationalPackage(float w): Package(w) {}
private:
    double calculateCost() override {
        return weight*15+25;
    }
};

int main() {
    LocalPackage l1(15);
    Package* ptr=&l1;
    cout << "Total cost for local package is $" << ptr->calculateCost() << endl;
    InternationalPackage i1(20);
    ptr=&i1;
    cout << "Total cost for international package is $" << ptr->calculateCost() << endl;
    return 0;
}