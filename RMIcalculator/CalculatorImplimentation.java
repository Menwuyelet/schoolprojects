import java.rmi.server.UnicastRemoteObject;
import java.rmi.RemoteException;

public class CalculatorImplimentation extends UnicastRemoteObject implements Calculator {
    protected CalculatorImplimentation() throws RemoteException {
        super();
    }

    public double add(double a, double b) throws RemoteException {
        return a + b;
    }

    public double subtract(double a, double b) throws RemoteException {
        return a - b;
    }

    public double multiply(double a, double b) throws RemoteException {
        return a * b;
    }

    public double divide(double a, double b) throws RemoteException {
        if (b == 0) {
            throw new ArithmeticException("Division by zero is not allowed");
        }
        return a / b;
    }

    public double power(double base, double exponent) throws RemoteException {
        return Math.pow(base, exponent);
    }

    public double squareRoot(double a) throws RemoteException {
        if (a < 0) {
            throw new ArithmeticException("Square root of negative number");
        }
        return Math.sqrt(a);
    }

    public double sin(double a) throws RemoteException {
        double radians = Math.toRadians(a);
        return Math.sin(radians);
    }

    public double cos(double a) throws RemoteException {
        double radians = Math.toRadians(a);
        return Math.cos(radians);
    }

    public double tan(double a) throws RemoteException {
        double radians = Math.toRadians(a);
        return Math.tan(radians);
    }
}