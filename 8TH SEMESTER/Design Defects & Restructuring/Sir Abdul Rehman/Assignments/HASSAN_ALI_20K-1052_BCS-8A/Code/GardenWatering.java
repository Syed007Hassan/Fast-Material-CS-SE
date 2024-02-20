
// WateringApp interface
interface WateringApp {
  public void scheduleWatering();
}

// Concrete implementation of WateringApp
class WateringAppImpl implements WateringApp {

  WateringAppImpl() {
    // Constructor logic
  }

  @Override
  public void scheduleWatering() {
    // Schedule watering logic
  }

}

// Valve class
class Valve {

  private String id;

  public void setId(String id) {
    this.id = id;
  }

  public String getId() {
    return this.id;
  }

}

// Legacy water valve controller
class GardenWaterValveLegacyController {

  public void activateValve(Valve valve) {
    // Logic to activate valve
  }

  public void disableValve(Valve valve) {
    // Logic to disable valve
  }

}

// Modern smart valve controller
class SmartWaterValveController {

  public void turnOnValve(String valveId) {
    System.out.println("Turning on valve " + valveId);
  }

  public void turnOffValve(String valveId) {
    System.out.println("Turning off valve " + valveId);
  }

}

// Valve adapter
class ValveAdapter extends GardenWaterValveLegacyController {

  private SmartWaterValveController smartController;

  public ValveAdapter(SmartWaterValveController smartController2) {
    this.smartController = smartController2;
  }

  @Override
  public void activateValve(Valve valve) {
    // Adapt to smart controller API
    smartController.turnOnValve(valve.getId());
  }

  @Override
  public void disableValve(Valve valve) {
    // Adapt to smart controller API
    smartController.turnOffValve(valve.getId());
  }

}

class GardenWatering {

  public static void main(String[] args) {

    // Create watering app
    WateringApp wateringApp = new WateringAppImpl();

    // Create legacy valves
    Valve gardenValve1 = new Valve();
    gardenValve1.setId("valve1");

    Valve gardenValve2 = new Valve();
    gardenValve2.setId("valve2");

    // Create smart valve controller
    SmartWaterValveController smartController = new SmartWaterValveController();

    // Create valve adapter
    ValveAdapter adapter = new ValveAdapter(smartController);

    // Schedule watering using adapter for both valve types
    wateringApp.scheduleWatering();
    adapter.activateValve(gardenValve1);

    wateringApp.scheduleWatering();
    adapter.activateValve(gardenValve2);

    // Disable valves
    adapter.disableValve(gardenValve1);
    adapter.disableValve(gardenValve2);
  }

}