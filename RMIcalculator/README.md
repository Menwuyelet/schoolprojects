# Java RMI Scientific Calculator

## 📌 Description

This project is a **Java RMI (Remote Method Invocation)–based Scientific Calculator** that allows a client application to perform mathematical operations on a remote server.

The calculator supports both **basic arithmetic** and **scientific operations**, demonstrating how distributed applications communicate using Java RMI.  
All calculations are executed on the **server**, while the **client handles user interaction**.

---

## ✨ Features

### Basic Operations
- Addition
- Subtraction
- Multiplication
- Division

### Scientific Operations
- Power (raising a number to an exponent)
- Square root
- Sine (sin)
- Cosine (cos)
- Tangent (tan)

> Trigonometric functions accept input in **degrees** (converted internally to radians).

### Additional Functionality
- Menu-driven interface
- Continue performing the same operation without returning to the main menu
- Option to return to the main menu or exit
- Proper exception handling
- Remote method invocation using Java RMI

---


## ⚙️ Requirements

- Java Development Kit (JDK) 8 or later
- Command line / terminal
- Localhost network access

---

## 🚀 How to Run the Application

### 1️⃣ Compile All Files

Open a terminal in the project directory and run:

```bash
javac *.java
```
### 2️⃣ Start the RMI Registry
```bash
java CalculatorServer
## Expected output: Calculator RMI Server is running...
```
### 3️⃣ Run the Client Application
In a new terminal window, run:
```bash
java CalculatorClient
```

then follow the on-screen prompts to use the calculator.

---
Authored by Menwuyelet Temesgen
---