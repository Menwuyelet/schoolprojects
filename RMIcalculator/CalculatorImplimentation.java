import java.rmi.server.UnicastRemoteObject;
import java.rmi.RemoteException;

public class CalculatorImplimentation extends UnicastRemoteObject implements Calculator {

    protected CalculatorImplimentation() throws RemoteException {
        super();
    }

    @Override
    public double add(double a, double b) throws RemoteException {
        return a + b;
    }

    @Override
    public double subtract(double a, double b) throws RemoteException {
        return a - b;
    }

    @Override
    public double multiply(double a, double b) throws RemoteException {
        return a * b;
    }

    @Override
    public double divide(double a, double b) throws RemoteException {
        if (b == 0) {
            throw new ArithmeticException("Cannot divide by zero");
        }
        return a / b;
    }
}
