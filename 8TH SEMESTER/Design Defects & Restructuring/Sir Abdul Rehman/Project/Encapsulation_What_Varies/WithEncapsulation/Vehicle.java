package WithEncapsulation;

public class Vehicle {
    
    String type;

    Vehicle(String type) {
        this.type = type;
    }

    public String getType(){
        return this.type;
    }

    public void setType(String type) {
        this.type = type;
    }

    public void drive(){
        System.out.println("Drive a car");
    }

    public void ride(){
        System.out.println("Ride a bike");
    }

    public void fly(){
        System.out.println("fly an aero plane");
    }

    public void steer(){
        System.out.println("steer a boat");
    }

    public void action(){
        if (getType() == "car"){
            drive();
        }
        else if (getType() == "bike"){
            ride();
        }
        else if (getType() == "boat"){
            steer();
        }
        else if (getType() == "aeroplane"){
            fly();
        }
        else{
            System.out.println("null vehicle");
        }
    }

}
