#include <iostream>
#include <iomanip>
#include <cmath>

class RobotStary {
public:
    virtual void idzDo(double x, double y) {
        std::cout << "RobotStary idzie do pozycji (" << x << ", " << y << ")" << std::endl;
    }
    virtual ~RobotStary() = default;
};

class RobotNowy {
public:
    void idzDo(double kat, double odleglosc) {

        std::cout << "RobotNowy idzie do pozycji (";
        std::cout << std::fixed << std::setprecision(2) << kat << "°, ";
        std::cout << std::defaultfloat << std::setprecision(6);
        std::cout << static_cast<int>(std::round(odleglosc)) << ")" << std::endl;
    }
};

class AdapterRobota : public RobotStary {
private:
    RobotNowy* robotNowy;

public:
    AdapterRobota(RobotNowy* robot) : robotNowy(robot) {}

    void idzDo(double x, double y) override {
        double kat = std::atan2(y, x) * 180.0 / M_PI;
        double odleglosc = std::sqrt(x*x + y*y);
        robotNowy->idzDo(kat, odleglosc);
    }
};

int main() {
    double x, y;
    std::cout << "Podaj współrzędne x: ";
    std::cin >> x;

    std::cout << "Podaj współrzędne y: ";
    std::cin >> y;

    RobotNowy* robotNowy = new RobotNowy();
    AdapterRobota adapter(robotNowy);

    adapter.idzDo(x, y);

    delete robotNowy;
    return 0;
}
