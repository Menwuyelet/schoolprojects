import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class CalculatorClient {

    public static void main(String[] args) {
        try {
            Registry registry = LocateRegistry.getRegistry("localhost", 1099);
            Calculator calculator = (Calculator) registry.lookup("CalculatorService");

            System.out.println("Add: " + calculator.add(10, 5));
            System.out.println("Subtract: " + calculator.subtract(10, 5));
            System.out.println("Multiply: " + calculator.multiply(10, 5));
            System.out.println("Divide: " + calculator.divide(10, 5));

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
