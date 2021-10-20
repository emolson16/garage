
using namespace std;
#include <iostream>
#include <string>

class Car {
  private: 
    double currentGas;
    double maxGas;
    double gasMileage;

  public:
    Car() {
        currentGas = 0;
        maxGas = 0;
    }

    void setInfo(double maxGasIn, double gasMileageIn) {
        gasMileage = gasMileageIn;
        maxGas = maxGasIn;
    }

    double getCurrentGas() {
        return currentGas;
    }

    double getGasMileage() {
        return gasMileage;
    }

    double getMaxGas() {
        return maxGas;
    }

    void fillFull() {
        currentGas = maxGas;
    }

    void fill(double gasIn) {
        currentGas += gasIn;
    }

    bool drive(double miles) {
        currentGas -= gasMileage * miles;
        if(currentGas < 0) {
            currentGas = 0;
            return false;
        }
        return true;
    }

    void printInfo() {
        cout << "Current gas: " << currentGas << endl;
        cout << "Max gas: " << maxGas << endl << endl;
    }
    

};

class Garage {
    private:
        int numCars;
        Car *garageArray;

    public:

        Garage(int numCarsIn) {
            numCars = numCarsIn;
            garageArray = new Car[numCars];
        }

        void fillCarsFull() {
            for(int i = 0; i < numCars; ++i) {
                garageArray[i].fillFull();
            }
        }

        void fillAmount(int index, double gas) {
            garageArray[index].fill(gas);
        }

        bool driveCar(int index, double miles) {
            return garageArray[index].drive(miles);
        }

        void setInfo(int index, double maxGas, double gasMileage) {
            garageArray[index].setInfo(maxGas, gasMileage);
        }

        void printGarageInfo() {
            for( int i = 0; i < numCars; ++i) {
                garageArray[i].printInfo();
            }
        }

        ~Garage() {
            delete[] garageArray;
            garageArray = NULL;
        }
};





int main() {

  // create garage with 3 cars and set info
  Garage myCars(3);

  myCars.setInfo(0, 12, 27.5);
  myCars.setInfo(1, 20, 14.3);
  myCars.setInfo(2, 15, 18);

  // should print 0 for all cars
  cout << "EMPTY CARS:" << endl;
  myCars.printGarageInfo();


  // fill cars up
  myCars.fillCarsFull();

  cout << "FULL CARS:" << endl;
  myCars.printGarageInfo();


  // drive cars
  myCars.driveCar(0, 500);
  myCars.driveCar(1, 2);
  myCars.driveCar(2, 100);

  // fill 
  myCars.fillAmount(0, 5);
  myCars.fillAmount(1, 3);
  myCars.fillAmount(2, 4);

  // drive again
  myCars.driveCar(0, 1);
  myCars.driveCar(1, 1);
  myCars.driveCar(2, 1);

  cout << "AFTER DRIVING:" << endl;

  myCars.printGarageInfo();



  return 0;
}

