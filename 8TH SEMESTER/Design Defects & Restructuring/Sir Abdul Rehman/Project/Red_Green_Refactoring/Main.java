package Red_Green_Refactoring;

public class Main {
    // Step 1: Write a failing test (Red)

    public static void main() {
        Calculator calculator = new Calculator();
        int result = calculator.calculateSum(5, 10);
        // assertEquals(15, result);
        result = calculator.calculateSum(5, 5);
        // assertEquals(10, result);
        result = calculator.calculateSum(5, 7);
        // assertEquals(12, result);
    }
}
