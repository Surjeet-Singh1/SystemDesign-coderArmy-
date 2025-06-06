#include <bits/stdc++.h>
using namespace std;
class Car{
    protected:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;

    public:
    Car(string b,string m){
        this->brand=b;
        this->model=m;
        isEngineOn=false;
        currentSpeed=0;
    }

void startEngine(){
    isEngineOn=true;
    cout<<brand<<" "<<model<<" :Engine started."<<endl;
}


    void stopEngine(){
        isEngineOn=false;
        currentSpeed=0;
        cout<<brand<<" "<<model<<" :Engine turned off."<<endl;
    }

    

    void accelerate(){
        if(!isEngineOn){
            cout<<brand<<" "<<model<<" :Acceleration failed. Engine is off."<<endl;
            return;
        }
        currentSpeed+=20;
        cout<<brand<<" "<<model<<" :Accelerated to "<<currentSpeed<<" km/h."<<endl;

    }
    void brake(){
        currentSpeed-=20;
        if(currentSpeed<0){
            currentSpeed=0;
        }
        cout<<brand<<' '<<model<<" :Breaking speed is "<<currentSpeed<<" km/h."<<endl;
    }
    virtual ~Car(){}


};
class ManualCar: public Car{
    private:
    int currentGear;//specific to manualCar

    public:
    ManualCar(string b,string m): Car(b,m){
        currentGear=0;

    }
    //specialized method for manualCar
    void shiftGear(int gear){
        currentGear=gear;
        cout<<brand<<" "<<model<<" : Shifted to gear "<<currentGear<<"."<<endl;
    }
    
};
class ElectricCar: public Car{
    private:
    int batteryLevel; //specific to electricCar
    public:
    ElectricCar(string b,string m): Car(b,m){
        batteryLevel=100; // assuming battery starts fully charged
    }

    void chargeBattery(){
        batteryLevel=100;
        cout<<brand<<" "<<model<<" : Battery charged to "<<batteryLevel<<"%."<<endl;}
};
int main(){
    ManualCar* myManualCar=new ManualCar("Suzuki","Swift");
    myManualCar->startEngine();
    
    myManualCar->shiftGear(1);
    myManualCar->accelerate();
    myManualCar->brake();
    myManualCar->stopEngine();

delete myManualCar;

cout<<"----------------------------------"<<endl;

ElectricCar* myElectriccar=new ElectricCar("Tesla","Mode S");
myElectriccar->chargeBattery();
myElectriccar->startEngine();
myElectriccar->accelerate();    
myElectriccar->brake(); 
myElectriccar->stopEngine();
delete myElectriccar;
return 0;
}