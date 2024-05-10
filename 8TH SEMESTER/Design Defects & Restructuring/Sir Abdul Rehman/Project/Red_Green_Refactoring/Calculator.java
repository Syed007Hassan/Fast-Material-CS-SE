package Red_Green_Refactoring;

// Step 2: Implement the code to make the test pass (Green)
// public class Calculator {
//     public int calculateSum(int a, int b) {
//         return a + b;
//     }
// }

// Step 3: Refactor the code to improve quality
public class Calculator {
    public int calculateSum(int a, int b) {
        // Refactor by extracting the operation into a separate method
    return add(a, b);
    }
    
    private int add(int a, int b) {
        return a + b;
    }
}