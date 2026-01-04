import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.Scanner;

public class CalculatorClient {

    public static void main(String[] args) {

        try {
            Registry registry = LocateRegistry.getRegistry("localhost", 1099);
            Calculator calculator = (Calculator) registry.lookup("CalculatorService");

            Scanner scanner = new Scanner(System.in);
            int choice;

            do {
                System.out.println("\n===== RMI Calculator =====");
                System.out.println("1. Add");
                System.out.println("2. Subtract");
                System.out.println("3. Multiply");
                System.out.println("4. Divide");
                System.out.println("5. Power");
                System.out.println("6. Square Root");
                System.out.println("7. Sin");
                System.out.println("8. Cos");
                System.out.println("9. Tan");
                System.out.println("0. Exit");
                System.out.print("Choose operation: ");

                choice = scanner.nextInt();

                if (choice == 0) {
                    System.out.println("Exiting calculator...");
                    break;
                }

                boolean continueOperation = true;

                while (continueOperation) {

                    double a, b, result;

                    switch (choice) {
                        case 1:
                            System.out.print("Enter two numbers: ");
                            a = scanner.nextDouble();
                            b = scanner.nextDouble();
                            result = calculator.add(a, b);
                            System.out.println("Result: " + result);
                            break;

                        case 2:
                            System.out.print("Enter two numbers: ");
                            a = scanner.nextDouble();
                            b = scanner.nextDouble();
                            result = calculator.subtract(a, b);
                            System.out.println("Result: " + result);
                            break;

                        case 3:
                            System.out.print("Enter two numbers: ");
                            a = scanner.nextDouble();
                            b = scanner.nextDouble();
                            result = calculator.multiply(a, b);
                            System.out.println("Result: " + result);
                            break;

                        case 4:
                            System.out.print("Enter two numbers: ");
                            a = scanner.nextDouble();
                            b = scanner.nextDouble();
                            if (a == 0) {
                                System.out.println("Result: " + 0);
                                break;
                            } else if (b == 0) {
                                System.out.println("ERR: Can not devide by ZERO.");
                                break;
                            }
                            result = calculator.divide(a, b);
                            System.out.println("Result: " + result);
                            break;

                        case 5:
                            System.out.print("Enter base and exponent: ");
                            a = scanner.nextDouble();
                            b = scanner.nextDouble();
                            result = calculator.power(a, b);
                            System.out.println("Result: " + result);
                            break;

                        case 6:
                            System.out.print("Enter number: ");
                            a = scanner.nextDouble();
                            result = calculator.squareRoot(a);
                            System.out.println("Result: " + result);
                            break;

                        case 7:
                            System.out.print("Enter angle (radians): ");
                            a = scanner.nextDouble();
                            result = calculator.sin(a);
                            System.out.println("Result: " + result);
                            break;

                        case 8:
                            System.out.print("Enter angle (radians): ");
                            a = scanner.nextDouble();
                            result = calculator.cos(a);
                            System.out.println("Result: " + result);
                            break;

                        case 9:
                            System.out.print("Enter angle (radians): ");
                            a = scanner.nextDouble();
                            result = calculator.tan(a);
                            System.out.println("Result: " + result);
                            break;

                        default:
                            System.out.println("Invalid choice!");
                            continueOperation = false;
                            continue;
                    }

                    System.out.println("\n1. Continue same operation");
                    System.out.println("2. Return to main menu");
                    System.out.print("Choose: ");
                    int option = scanner.nextInt();

                    if (option != 1) {
                        continueOperation = false;
                    }
                }

            } while (true);

            scanner.close();

        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}
