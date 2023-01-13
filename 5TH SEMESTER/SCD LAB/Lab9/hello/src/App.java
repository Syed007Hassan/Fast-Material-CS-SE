

public class App {
    public App(int i, int j) {
    }

    public static void main(String[] args) throws Exception {
        System.out.println("Hello, World!");

        // Create a new instance of the class
        App app = new App();
       //create a method with two parameters
        app.add(5, 6);  
        

        //create a parametrized constructor
        App app2 = new App(5, 6);
    }

    private void add(int i, int j) {
    }
}
