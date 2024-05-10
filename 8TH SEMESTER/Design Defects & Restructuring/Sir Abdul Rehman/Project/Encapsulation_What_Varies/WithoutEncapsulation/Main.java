package WithoutEncapsulation;

public class Main {

    public static void main(String[] args){
        Vehicle vehicle = new Vehicle("boat");

        if (vehicle.getType() == "car"){
            vehicle.drive();
        }
        else if (vehicle.getType() == "bike"){
            vehicle.ride();
        }
        else if (vehicle.getType() == "boat"){
            vehicle.steer();
        }
        else if (vehicle.getType() == "aeroplane"){
            vehicle.fly();
        }
        else{
            System.out.println("null vehicle");
        }
    }

}