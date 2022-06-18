//13) Создать класс базовый класс «квадрат».
//Элементы класса:
//поле, задающее длину стороны;
//конструктор для инициализации поля;
//метод для вычисления площади квадрата;
//метод для печати поля и площади квадрата.
//Создать производный класс «куб».
//Элементы класса:
//конструктор для инициализации поля;
//переопределенный метод для вычисления объема куба (вместо площади)
//(внутри переопределенного метода должен вызываться метод из базового
//класса).
//Соз13) Создать класс базовый класс «квадрат».
//Элементы класса:
//поле, задающее длину стороны;
//конструктор для инициализации поля;
//метод для вычисления площади квадрата;
//метод для печати поля и площади квадрата.
//Создать производный класс «куб».
//Элементы класса:
//конструктор для инициализации поля;
//переопределенный метод для вычисления объема куба (вместо площади)
//(внутри переопределенного метода должен вызываться метод из базового
//класса).
//Создать по 1 объекту каждого из классов. Объявить переменную - указатель,
//имеющею тип базового класса, вначале настроить ее на объект базового
//класса, вызвать метод базового класса через указатель на объект. Затем
//настроить ее на объект производного класса, вызвать метод производного
//класса через указатель на объект. Обеспечить статический полиморфизм.дать по 1 объекту каждого из классов. Объявить переменную - указатель,
//имеющею тип базового класса, вначале настроить ее на объект базового
//класса, вызвать метод базового класса через указатель на объект. Затем
//настроить ее на объект производного класса, вызвать метод производного
//класса через указатель на объект. Обеспечить статический полиморфизм.


#include <iostream>
#include <cmath>

class Square {
protected:
    double side;
public:
    explicit Square(double side) : side(side){};

    double calc() const {
        return side * side;
    };

    void print() {
        std::cout << "Side : " << side << " Area : " << this->calc() << std::endl;
    }

};

class Cube : public Square {
protected:
    double side;
public:
    explicit Cube(double side) : Square(side){};

    double calc() const {
        return Square::calc() * side;
    }

    void print() {
        Square::print();
        std::cout << " Vol " << this->calc() << std::endl;
    }
};


int main() {

    Square square(5);

    Cube cube(5);

    Square *psq = &square;

    // Статический полиформизм

    psq->print();

    psq = &cube;
    psq->print();

}