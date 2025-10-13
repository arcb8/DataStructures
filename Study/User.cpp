#include <iostream>

using std::string;

class User
{
    // Не видно вне класса
private:
    string address;
public:
    int age;
    string name;

    // Конструктор
    User(int _age, string _name, string _address)
    {
        age = _age;
        name = _name;
        address = _address;
    }
    // Метод вывода
    void display() {
        std::cout << "Age: " << age << " Name: " << name << " Address: " << address << std::endl;
    }

    // Деструктор
    ~User() {
        std::cout << "Called destructor ";
    }
};

int main()
{
    User user1(12, "Maxim", "Cheshmikioy");
    User user2(5, "Sanya", "lox");

    User* user = new User(19, "Tom", "London");
    delete user;

    std::cout << "\n-------------------------------\n";

    user1.display();
    user2.display();

    return 0;
}