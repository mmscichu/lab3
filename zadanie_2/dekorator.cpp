#include <iostream>
#include <string>
 
// Klasa bazowa Robot
class Robot {
public:
    virtual void operacja() = 0;
    virtual ~Robot() = default; 
};
 
// Klasa podstawowa robota
class RobotPodstawowy : public Robot {
public:
    void operacja() override {
        std::cout << "Robot podstawowy porusza się." << std::endl;
    }
};
 
// Klasa abstrakcyjna RobotDekorator
class RobotDekorator : public Robot {
protected:
    Robot* robot;
 
public:
    RobotDekorator(Robot* r) : robot(r) {}
    virtual void operacja() override {
        robot->operacja();
    }
    virtual ~RobotDekorator() = default;
};
 
// Klasa dekoratora - RobotZKamera
class RobotZKamera : public RobotDekorator {
public:
    RobotZKamera(Robot* r) : RobotDekorator(r) {
        std::cout << "Dodajemy kamerę do robota" << std::endl;
        }
 
    void operacja() override {
        robot->operacja();
        std::cout << "Robot ma kamerę, może nagrywać." << std::endl;
    }
};
 
// Klasa dekoratora - RobotZCzujnikiemTemperatury
class RobotZCzujnikiemTemperatury : public RobotDekorator {
public:
    RobotZCzujnikiemTemperatury(Robot* r) : RobotDekorator(r) {
        std::cout << "Dodajemy czujnik temperatury" << std::endl;
        }
 
    void operacja() override {
        robot->operacja();
        std::cout << "Robot ma czujnik temperatury." << std::endl;
    }
};
 
// Klasa dekoratora - RobotZDzwiekiem
class RobotZDzwiekiem : public RobotDekorator {
public:
    RobotZDzwiekiem(Robot* r) : RobotDekorator(r) {
        std::cout << "Dodajemy system dźwiękowy" << std::endl;
        }
 
    void operacja() override {
        robot->operacja();
        std::cout << "Robot ma system dźwiękowy." << std::endl;
    }
};
 
// Główna funkcja
int main() {
    // Tworzymy robota podstawowego
    Robot* robot = new RobotPodstawowy();
    robot->operacja();
    std::cout << std::endl;
 
    // Dodajemy kamerę do robota
    Robot* robotZKamera = new RobotZKamera(robot);
    robotZKamera->operacja();
    std::cout << std::endl;
 
    // Dodajemy czujnik temperatury
    Robot* robotZKameraICzujnikTemp = new RobotZCzujnikiemTemperatury(robotZKamera);
    robotZKameraICzujnikTemp->operacja();
    std::cout << std::endl;
 
    // Dodajemy system dźwiękowy
    Robot* robotWszystko = new RobotZDzwiekiem(robotZKameraICzujnikTemp);
    robotWszystko->operacja();
    // Zwolnienie pamięci
    delete robotWszystko;
    delete robotZKameraICzujnikTemp;
    delete robotZKamera;
    delete robot;
 
    return 0;
}