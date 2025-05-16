import javax.swing.*;
import javax.swing.text.MutableAttributeSet;
import javax.swing.text.StyleConstants;
import javax.swing.text.StyledDocument;
import java.awt.*;
import java.awt.event.*;
import java.io.BufferedReader;
import java.io.FileWriter;
import java.io.BufferedWriter;
import java.io.FileReader;
import javax.swing.text.*;



public class LandingPage extends JFrame implements ActionListener {
    private JButton calculatorBtn, notepadBtn, aboutBtn;

    public LandingPage() {
        setTitle("Application Launcher");
        setSize(400, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        JPanel mainPanel = new JPanel();
        mainPanel.setLayout(new GridLayout(3, 1, 10, 10));
        mainPanel.setBorder(BorderFactory.createEmptyBorder(20, 20, 20, 20));
        mainPanel.setBackground(new Color(240, 240, 240));

        calculatorBtn = createStyledButton("Calculator", new Color(84, 50, 105));
        notepadBtn = createStyledButton("Notepad", new Color(33, 150, 243));
        aboutBtn = createStyledButton("About", new Color(50, 68, 105));

        mainPanel.add(calculatorBtn);
        mainPanel.add(notepadBtn);
        mainPanel.add(aboutBtn);

        add(mainPanel, BorderLayout.CENTER);
    }

    private JButton createStyledButton(String text, Color bgColor) {
        JButton button = new JButton(text);
        button.addActionListener(this);
        button.setBackground(bgColor);
        button.setForeground(Color.WHITE);
        button.setFont(new Font("Arial", Font.BOLD, 18));
        button.setFocusPainted(false);
        button.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));
        return button;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == calculatorBtn) {
            new ScientificCalculator().setVisible(true);
        } else if (e.getSource() == notepadBtn) {
            new Notepad().setVisible(true); 
        } else if (e.getSource() == aboutBtn) {
            new About().setVisible(true);
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            LandingPage launcher = new LandingPage();
            launcher.setVisible(true);
        });
    }

///////////////////////////////////////Calculator

    static class ScientificCalculator extends JFrame implements ActionListener {
        private JTextField display;
        private String[] buttonLabels = {
                "sin", "cos", "tan", "(", ")",
                "log", "ln", "sqrt", "^", "!",
                "7", "8", "9", "/", "C",
                "4", "5", "6", "*", "DEL",
                "1", "2", "3", "-", "π",
                "0", ".", "=", "+", "e"
        };

        public ScientificCalculator() {
            setTitle("Scientific Calculator");
            setSize(500, 400);
            setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
            setLayout(new BorderLayout());

            display = new JTextField("0");
            display.addKeyListener(new java.awt.event.KeyAdapter() {
                @Override
                public void keyPressed(java.awt.event.KeyEvent e) {
                    int key = e.getKeyCode();
                    String currentText = display.getText();

                    // Handle ENTER (calculate)
                    if (key == java.awt.event.KeyEvent.VK_ENTER) {
                        calculateResult();
                        e.consume();
                    }
                    // Handle ESCAPE (clear)
                    else if (key == java.awt.event.KeyEvent.VK_ESCAPE) {
                        display.setText("");
                        e.consume();
                    }
                    else if (key == java.awt.event.KeyEvent.VK_EQUALS){
                        calculateResult();
                        e.consume();
                    }
                    // Handle BACKSPACE (delete)
                    else if (key == java.awt.event.KeyEvent.VK_BACK_SPACE) {
                        if (!currentText.isEmpty()) {
                            display.setText(currentText.substring(0, currentText.length() - 1));
                        }
                        e.consume(); // Stop default backspace behavior
                    }
                }

                @Override
                public void keyTyped(java.awt.event.KeyEvent e) {
                    char ch = e.getKeyChar();
                    String currentText = display.getText();

                    // Handle digits, operators, or allowed symbols
                    if (Character.isDigit(ch) || "+-*/().^!".indexOf(ch) != -1) {
                        // Replace initial "0" if present
                        if (currentText.equals("0")) {
                            display.setText(String.valueOf(ch));
                        } else {
                            display.setText(currentText + ch);
                        }
                        e.consume(); // Stop JTextField from adding the character again
                    }
                    // Handle 'p' or 'P' for π
                    else if (ch == 'p' || ch == 'P') {
                        display.setText(currentText + Math.PI);
                        e.consume();
                    }
                    // Handle 'e' or 'E' for Euler's number
                    else if (ch == 'e' || ch == 'E') {
                        display.setText(currentText + Math.E);
                        e.consume();
                    }
                }
            });

            display.setFont(new Font("Arial", Font.PLAIN, 24));
            display.setHorizontalAlignment(JTextField.RIGHT);
            display.setEditable(true);
            display.setBackground(Color.WHITE);
            display.setForeground(Color.BLACK);
            add(display, BorderLayout.NORTH);

            JPanel buttonPanel = new JPanel(new GridLayout(6, 5, 2, 2));
            buttonPanel.setBackground(Color.WHITE);

            for (String label : buttonLabels) {
                JButton button = new JButton(label);
                button.addActionListener(this);
                button.setFont(new Font("Arial", Font.PLAIN, 18));
                if (label.matches("[0-9]|\\.")) {
                    button.setBackground(new Color(245, 158, 11));
                    button.setForeground(Color.BLACK);
                } else if (label.matches("[*\\+\\-\\/]")) {
                    button.setBackground(new Color(37, 99, 235));
                    button.setForeground(Color.BLACK);
                } else if (label.matches("sin|cos|tan|log|ln|sqrt|\\^|!")) {
                    button.setBackground(new Color(100, 116, 139));
                    button.setForeground(Color.WHITE);
                } else if (label.matches("C")) {
                    button.setBackground(new Color(245, 200, 25));
                    button.setForeground(Color.WHITE);
                } else {
                    button.setBackground(new Color(00, 116, 139));
                    button.setForeground(Color.WHITE);
                }
                buttonPanel.add(button);
            }

            add(buttonPanel, BorderLayout.CENTER);
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            String command = e.getActionCommand();
            String currentText = display.getText();

            switch (command) {
                case "=":
                    calculateResult();
                    break;
                case "C":
                    display.setText("");
                    break;
                case "DEL":
                    if (!currentText.isEmpty()) {
                        display.setText(currentText.substring(0, currentText.length() - 1));
                    }
                    break;
                case "sin":
                case "cos":
                case "tan":
                case "log":
                case "ln":
                case "sqrt":
                    display.setText(currentText + command + "(");
                    break;
                case "π":
                    display.setText(currentText + Math.PI);
                    break;
                case "e":
                    display.setText(currentText + Math.E);
                    break;
                default:
                    display.setText(currentText + command);
            }
        }

        private void calculateResult() {
            try {
                String expr = display.getText();
                double result = evaluateExpression(expr);
                if (Double.isInfinite(result)) {
                    display.setText("Can't divide by zero");
                } else if (result == (int) result) {
                    display.setText(Integer.toString((int) result));
                } else {
                    display.setText(Double.toString(result));
                }
            } catch (ArithmeticException ex) {
                display.setText("Can't divide by zero");
            } catch (Exception ex) {
                display.setText("Error");
            }
        }

        private double evaluateExpression(String expr) {
            expr = expr.replace("π", Double.toString(Math.PI))
                    .replace("e", Double.toString(Math.E));

            expr = expr.replaceAll("sin\\(([^)]+)\\)", "sin#$1")
                    .replaceAll("cos\\(([^)]+)\\)", "cos#$1")
                    .replaceAll("tan\\(([^)]+)\\)", "tan#$1")
                    .replaceAll("log\\(([^)]+)\\)", "log#$1")
                    .replaceAll("ln\\(([^)]+)\\)", "ln#$1")
                    .replaceAll("sqrt\\(([^)]+)\\)", "sqrt#$1");

            return evaluate(convertFunctions(expr));
        }

        private String convertFunctions(String expr) {
            while (expr.contains("#")) {
                int idx = expr.indexOf("#");
                int start = idx + 1;
                int end = start;
                int brackets = 0;
                while (end < expr.length()
                        && (brackets > 0 || Character.isDigit(expr.charAt(end)) || expr.charAt(end) == '.')) {
                    if (expr.charAt(end) == '(')
                        brackets++;
                    if (expr.charAt(end) == ')')
                        brackets--;
                    end++;
                }
                String sub = expr.substring(start, end);
                double val = evaluate(sub);
                String func = expr.substring(0, idx);
                double res;
                switch (func) {
                    case "sin":
                        res = Math.sin(Math.toRadians(val));
                        break;
                    case "cos":
                        res = Math.cos(Math.toRadians(val));
                        break;
                    case "tan":
                        res = Math.tan(Math.toRadians(val));
                        break;
                    case "log":
                        res = Math.log10(val);
                        break;
                    case "ln":
                        res = Math.log(val);
                        break;
                    case "sqrt":
                        res = Math.sqrt(val);
                        break;
                    default:
                        throw new RuntimeException("Unknown function");
                }
                expr = expr.substring(0, idx - func.length()) + res + expr.substring(end);
            }
            return expr;
        }

        //
        private int factorial(int n) {
            int result = 1;
            for (int i = 2; i <= n; i++) {
                result *= i;
            }
            return result;
        }
        //

        private double evaluate(String expr) {
            return new Object() {
                int pos = -1, ch;

                void nextChar() {
                    ch = (++pos < expr.length()) ? expr.charAt(pos) : -1;
                }

                boolean eat(int charToEat) {
                    while (ch == ' ')
                        nextChar();
                    if (ch == charToEat) {
                        nextChar();
                        return true;
                    }
                    return false;
                }

                double parse() {
                    nextChar();
                    double x = parseExpression();
                    if (pos < expr.length())
                        throw new RuntimeException("Unexpected: " + (char) ch);
                    return x;
                }

                double parseExpression() {
                    double x = parseTerm();
                    for (;;) {
                        if (eat('+'))
                            x += parseTerm();
                        else if (eat('-'))
                            x -= parseTerm();
                        else
                            return x;
                    }
                }

                double parseTerm() {
                    double x = parseFactor();
                    for (;;) {
                        if (eat('*'))
                            x *= parseFactor();
                        else if (eat('/')) {
                            double divisor = parseFactor();
                            if (divisor == 0)
                                throw new ArithmeticException("Division by zero");
                            x /= divisor;
                        } else
                            return x;
                    }
                }

                double parseFactor() {
                    if (eat('+'))
                        return parseFactor();
                    if (eat('-'))
                        return -parseFactor();

                    double x;
                    int startPos = this.pos;
                    if (eat('(')) {
                        x = parseExpression();
                        eat(')');
                    } else if ((ch >= '0' && ch <= '9') || ch == '.') {
                        while ((ch >= '0' && ch <= '9') || ch == '.')
                            nextChar();
                        x = Double.parseDouble(expr.substring(startPos, this.pos));
                    } else {
                        throw new RuntimeException("Unexpected: " + (char) ch);
                    }

                    if (eat('^'))
                        x = Math.pow(x, parseFactor());

                    // Add this for factorial support
                    while (eat('!')) {
                        if (x < 0 || x != (int) x)
                            throw new ArithmeticException("Invalid factorial input");
                        x = factorial((int) x);
                    }

                    return x;
                }
            }.parse();
        }
    }

///////////////////////////////////////Notepad

    static class Notepad extends JFrame {
        private JTextPane textPane;
        private JComboBox<String> fontBox;
        private JComboBox<Integer> sizeBox;
        private JButton boldBtn, italicBtn;

        public Notepad() {
            setTitle("Styled Text Editor");
            setLayout(new BorderLayout());

            textPane = new JTextPane();
            JScrollPane scrollPane = new JScrollPane(textPane);

            // Font families
            GraphicsEnvironment ge = GraphicsEnvironment.getLocalGraphicsEnvironment();
            String[] fonts = ge.getAvailableFontFamilyNames();
            fontBox = new JComboBox<>(fonts);
            fontBox.setSelectedItem("Serif");
            fontBox.setMaximumRowCount(8);

            // Font sizes
            Integer[] sizes = {8, 10, 12, 14, 16, 18, 20, 24, 28, 32, 36};
            sizeBox = new JComboBox<>(sizes);
            sizeBox.setSelectedItem(14);

            // Style buttons
            boldBtn = createCompactButton("B", Font.BOLD);
            italicBtn = createCompactButton("I", Font.ITALIC);

            // File buttons
            JButton newBtn = createCompactButton("New", -1);
            JButton openBtn = createCompactButton("Open", -1);
            JButton saveBtn = createCompactButton("Save", -1);

            // Add action listeners
            fontBox.addActionListener(e -> applyFont());
            sizeBox.addActionListener(e -> applySize());
            boldBtn.addActionListener(e -> toggleStyle(StyleConstants.Bold));
            italicBtn.addActionListener(e -> toggleStyle(StyleConstants.Italic));
            
            newBtn.addActionListener(e -> newFile());
            openBtn.addActionListener(e -> openFile());
            saveBtn.addActionListener(e -> saveFile());

            // Toolbar
            JToolBar toolBar = new JToolBar();
            toolBar.add(newBtn);
            toolBar.add(openBtn);
            toolBar.add(saveBtn);
            toolBar.add(boldBtn);
            toolBar.add(italicBtn);
            toolBar.addSeparator();
            toolBar.add(new JLabel("Font:"));
            toolBar.add(fontBox);
            toolBar.add(new JLabel("Size:"));
            toolBar.add(sizeBox);


            add(toolBar, BorderLayout.NORTH);
            add(scrollPane, BorderLayout.CENTER);

            setSize(600, 400);
            setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
            setVisible(true);
        }

        private JButton createCompactButton(String text, int style) {
            JButton btn = new JButton(text);
            btn.setMargin(new Insets(2, 6, 2, 6));
            if(style != -1) btn.setFont(btn.getFont().deriveFont(style));
            return btn;
        }

        private void newFile() {
            textPane.setText("");
        }

        private void openFile() {
            JFileChooser fc = new JFileChooser();
            if(fc.showOpenDialog(this) == JFileChooser.APPROVE_OPTION) {
                try (BufferedReader reader = new BufferedReader(new FileReader(fc.getSelectedFile()))) {
                    textPane.read(reader, null);
                } catch (Exception e) {
                    JOptionPane.showMessageDialog(this, "Error opening file");
                }
            }
        }

        private void saveFile() {
            JFileChooser fc = new JFileChooser();
            if(fc.showSaveDialog(this) == JFileChooser.APPROVE_OPTION) {
                try (BufferedWriter writer = new BufferedWriter(new FileWriter(fc.getSelectedFile()))) {
                    textPane.write(writer);
                } catch (Exception e) {
                    JOptionPane.showMessageDialog(this, "Error saving file");
                }
            }
        }

        private void applyFont() {
            String font = (String) fontBox.getSelectedItem();
            StyledDocument doc = textPane.getStyledDocument();
            int start = textPane.getSelectionStart();
            int end = textPane.getSelectionEnd();

            if(start == end) {
                MutableAttributeSet attrs = textPane.getInputAttributes();
                StyleConstants.setFontFamily(attrs, font);
            } else {
                Style style = textPane.addStyle("FontStyle", null);
                StyleConstants.setFontFamily(style, font);
                doc.setCharacterAttributes(start, end - start, style, false);
            }
        }

        private void applySize() {
            int size = (int) sizeBox.getSelectedItem();
            StyledDocument doc = textPane.getStyledDocument();
            int start = textPane.getSelectionStart();
            int end = textPane.getSelectionEnd();

            if(start == end) {
                MutableAttributeSet attrs = textPane.getInputAttributes();
                StyleConstants.setFontSize(attrs, size);
            } else {
                Style style = textPane.addStyle("SizeStyle", null);
                StyleConstants.setFontSize(style, size);
                doc.setCharacterAttributes(start, end - start, style, false);
            }
        }

        private void toggleStyle(Object styleConstant) {
            StyledDocument doc = textPane.getStyledDocument();
            int start = textPane.getSelectionStart();
            int end = textPane.getSelectionEnd();

            if(start == end) {
                MutableAttributeSet attrs = textPane.getInputAttributes();
                boolean current = styleConstant == StyleConstants.Bold ? 
                    StyleConstants.isBold(attrs) : StyleConstants.isItalic(attrs);
                if(styleConstant == StyleConstants.Bold) {
                    StyleConstants.setBold(attrs, !current);
                } else {
                    StyleConstants.setItalic(attrs, !current);
                }
                textPane.setCharacterAttributes(attrs, false);
            } else {
                Style style = textPane.addStyle("ToggleStyle", null);
                Element elem = doc.getCharacterElement(start);
                AttributeSet as = elem.getAttributes();
                style.addAttributes(as);

                boolean current = styleConstant == StyleConstants.Bold ? 
                    StyleConstants.isBold(as) : StyleConstants.isItalic(as);
                
                if(styleConstant == StyleConstants.Bold) {
                    StyleConstants.setBold(style, !current);
                } else {
                    StyleConstants.setItalic(style, !current);
                }
                doc.setCharacterAttributes(start, end - start, style, false);
            }
        }
    }

///////////////////////////////////////About

    static class About extends JFrame {
        public About() {
            setTitle("About");
            setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
            setPreferredSize(new Dimension(500, 400)); 

            JPanel mainPanel = new JPanel(new BorderLayout());
            mainPanel.setBackground(new Color(50, 105, 93));
            mainPanel.setBorder(BorderFactory.createEmptyBorder(30, 30, 30, 30));


            JTextArea textArea = new JTextArea();
            textArea.setEditable(false);
            textArea.setLineWrap(true);
            textArea.setWrapStyleWord(true);

            
            String aboutText = "********************************************************************************************************************************\n\n"
                    +
                    "About The Program\n\n" +
                    "This program is developed by students of CSE section 5 and 6 for our OOP/Java course final project.\n\n"
                    +
                    "It contains two applications:\n" +
                    "1. Scientific Calculator\n" +
                    "2. Notepad\n\n" +
                    "Group members:\n" +
                    "1. Menwuyelet Temesgen\t\tUGR/34920/16\t\tSec.5\n" +
                    "2. Tadele  Rago       \t\tUGR/35460/16\t\tSec.6\n" +
                    "3. Betel Habtemariam  \t\tUGR/34042/16\t\tSec.6\n" +
                    "4. Nuredin Wario      \t\tUGR/35196/16\t\tSec.6\n" +
                    "5. Dawit Eyasu        \t\tUGR/34206/16\t\tSec.5\n" +
                    "6. Biniyam Teku       \t\tUGR/34102/16\t\tSEC.6\n" +
                    "==================== Thank you for using our program! we hope you enjoyed it. ^__^ ====================\n";

            textArea.setText(aboutText); // Set text once with all content

            // Styling
            textArea.setForeground(Color.WHITE);
            textArea.setBackground(new Color(50, 105, 93));
            textArea.setFont(new Font("Arial", Font.BOLD, 16)); // Increased font size
            textArea.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10)); // Add padding
            textArea.setMargin(new Insets(10, 10, 10, 10)); // Text margins

            // Disable text selection
            textArea.setHighlighter(null);

            // Add to scroll pane
            JScrollPane scrollPane = new JScrollPane(textArea);
            scrollPane.setBorder(BorderFactory.createEmptyBorder());
            scrollPane.getViewport().setBackground(new Color(50, 105, 93)); // Match background

            mainPanel.add(scrollPane, BorderLayout.CENTER);
            add(mainPanel);

            pack();
            setLocationRelativeTo(null);
        }
    }

}
