#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <iostream>

using namespace std;

void Grade_calculator();
void bill_cal();
void student();
void matrix();
void filereader();
void program();



int main(){
  int num;
  cout << "==================================================================================================\n";
  cout << "Welcome!, Please select your choice.\n";
  cout << "1, Grade calculator\n";
  cout << "2, Phone bill calculator\n";
  cout << "3, Student info\n";
  cout << "4, Matrix multiplication\n";
  cout << "5, Filereader\n";
  cout << "6, About the program\n";
  cout << "7, Exit the program\n\n";
  int choice;
  cout << "Choice: ";
  cin >> choice;

  switch (choice)
  {
  case 1:
    cout << "\n\n" << "****welcome to grade calculator.****\n\n";
    Grade_calculator();
    break;
  case 2:
    cout << "\n\n" << "****welcome to bill calculator.****\n\n";
    bill_cal();
    break;
  case 3:
    cout << "\n\n" << "****welcome to student information.****\n\n";
    student();
    break;
  case 4:
    cout << "\n\n" << "****welcome to matrix multiplier****\n\n";
    matrix();
    break;
  case 5:
    cout << "\n\n" << "****welcome to file reader****\n\n";
    filereader();
    break;
  case 6:
    cout << "\n\n" << "****welcome to about the program****\n\n";
    program();
    break;
  case 7:
    break;
  }
}
//the bill calculator program starts here.
void bill_cal(){
  int call;
  cout << "enter the number of calls: ";
  cin >> call;
  double bill;

  if (call <= 100){
    bill = 200.0;
  }
  else if (call > 100 ){
    int additional = call - 100;
    if (additional <= 50){
      bill = 200 + (additional * 0.6);
    }
    else if (additional >= 100){
      int add1 = 50;
      int add2 = 50;
      int add3 = (additional - 100);
      bill = 200 + (add1 * 0.6) +(add2*0.5) + add3 * 0.4;
    }
    else if(additional > 50){
      int add1 = additional - 50;
      bill = 200 + (50 * 0.6) + add1 * 0.5;
    }
   
  }
  cout << "\n" << "==================================================================================================\n\n";
  cout << "Your bill is $ " << bill << "\n\n";
  cout << "==================================================================================================\n";
//offers the choice to return to main page or use the program again or exit the entire program.
  cout << "if you want to return to first page chose 1, if you want to calculate your bill again chose 2, else chose 3 to end the program.\n";
  int ch;
  cin >> ch;
  cout << "\n";
  switch (ch)
  {
  case 1:
    main();
    break;
  case 2:
    bill_cal();
    break;
  case 3:
    cout << "thank you for chossing us. have a good day.\n\n";
    break;
  }
}

//the Grade calculator program starts here
void Grade_calculator(){
  int num;
  cout << "enter the number of the students: ";
  cin >> num;
  string arr [num] [7];
  string arr1 [7] = {"Name:", "Grade1:", "Grade2:", "Grade4:", "Grade5:", "Average:", "Wtd_Avg"};
  for (int i = 0; i < num; i++){
    cin.ignore();
    string Name;
    cout << "Enter the student name: ";
    getline(cin, Name);
    int grade1, grad2, grade3, grade4;
    double av1, av2;
    cout << "please enter the four grades: ";
    cin >> grade1 >> grad2 >> grade3 >> grade4;
    av1 = (grade1 + grad2 + grade3 + grade4) / 4;
    av2 = (grade1 * 0.2 + grad2 * 0.3 + grade3 * 0.3 + grade4 * 0.2) / (0.2 + 0.2 + 0.3 + 0.3);
    cout << av2;
    arr[i][0] = Name;
    arr[i][1] = to_string(grade1);
    arr[i][2] = to_string(grad2);
    arr[i][3] = to_string(grade3);
    arr[i][4] = to_string(grade4);
    arr[i][5] = to_string(av1);
    arr[i][6] = to_string(av2);
  }
  cout << "Name:" << "\t\t" << "Grade1:" << "\t\t" << "Grade2:" << "\t\t" << "Grade4:" << "\t\t" << "Grade5:" << "\t\t" << "Average:" << "\t\t" << "Wtd_Avg" << "\n\n";
  for (int i = 0; i < num; i++) {
    cout << to_string(i + 1) + ", ";
    for (int j = 0; j < 7; j++) {
      cout << arr[i][j] << "\t\t" ;
    }
    cout << "\n\n";
  }
//offers the choice to return to main page or use the program again or exit the entire program.
  cout << "**if you want to return to first page chose 1, if you want to calculate grades again chose 2 else chose 3 to end the program.**\n";
  int ch;
  cin >> ch;
  cout << "\n";
  switch (ch)
  {
  case 1:
    main();
    break;
  case 2:
    Grade_calculator();
    break;
  case 3:
    cout << "thank you for chossing us. have a good day.\n\n";
    break;
  }
}

//the student information loger program starts here.
void student(){
    struct Stud{
    string name;
    string id;
    int creditHours;
    double cGPA;
  };
  Stud Student;
  cin.ignore();
  cout << "Enter the student name: ";
  getline(cin, Student.name);
  cout << "Enter student id: ";
  getline(cin, Student.id);
  cout << "Enter the credit hours: ";
  cin >> Student.creditHours;
  cout << "Enter the commulative GPA: ";
  cin >> Student.cGPA;

  cout << "STUDENT INFORMATION\n\n";
  cout << "Sudent Name: " 
      << Student.name<<"\n" 
      << "Student id: " 
      << Student.id << "\n" 
      << "Credit hours taken: " 
      << Student.creditHours 
      << "\n"<<"Commulative GPA: " 
      << Student.cGPA << "\n";

  cout << "\n\n" << "**if you want to return to first page chose 1, if you want to store other student choose 2 else chose 3 to end the program.**\n\n";
//offers the choice to return to main page or use the program again or exit the entire program.
  int ch;
  cin >> ch;
  cout << "\n";
  switch (ch)
  {
  case 1:
    main();
    break;
  case 2:
    student();
    break;
  case 3:
    cout << "thank you for chossing us. have a good day.\n\n";
    break;
  }
}

// the matrix multiplier program starts here.
void matrix(){
//takes the rows and columns of the two matrixs.
  cout << "==================================================================================================\n";
  cout << "\n";
  int r1, c1, r2, c2;//r1,r2 are rows of the first matrix and the second matrix respectivly. c1 and c2 are the columns.
  cout << "Pleas enter the first matrixs row: ";
  cin >> r1;
  cout << "colum: ";
  cin >> c1;
  cout << "enter the second matrixs row: ";
  cin >> r2;
  cout << "colum: ";
  cin >> c2;
  cout << "\n";
//intializes the matrix matA and matB with r1, r2 by c1, c2 size both.
  int matA[r1][c1],matB[r2][c2];//matA is the first matrix and matB is the second matrix.
//gets the elemnts of the first matrix from the user by iterating until all the rows and colums are filled.
  for (int i = 0; i < r1; i++){
    for(int j = 0; j < c1; j++){
      cout << "Enter element matA" << i+1 << j+1 << " : ";
      cin >> matA[i][j];
    }
  } 
  cout << "\n";
//gets the elemnts of the second matrix from the user by iterating until all the rows and colums are filled.
  cout << "enter the second matrix: \n" << endl;
  for (int i = 0; i < r2; i++){
    for(int j = 0; j < c2; j++){
      cout << "Enter element matB" << i+1 << j+1 << " : ";
      cin >> matB[i][j];
    }
  } 
//checks if the column of matrixs matA is equal to rows of matB to confirm thath the two matrixs can be multiplied.
  if (c1 == r2){
//intializes the product matrix with row number of r1 and column number of c2.
    int proMatrix [r1][c2];
    for (int i = 0; i < r1; i++){
      for (int j = 0; j < c2; j++){
        proMatrix[i][j] = 0;
      }
    }
  //callculates the product and assigns it to the product matrix.
   for (int i = 0; i < r1; i++){
      for (int j = 0; j < c2; j++){
        for (int m = 0; m < c1; m++){
          proMatrix[i][j] += matA[i][m] * matB[m][j];//since the product matrix is filled with 0s as elements we just add the multiplied values one by one to it to get our resul.
        }
      }
    }
  //prints out the product matrix.
    for (int i = 0; i < r1; i++){
       for (int j = 0; j < c2; ++j){
        cout <<" " << proMatrix[i][j];
        if(j == c2-1){
          cout << endl;
          }
      }
    }
  }
  //if the two matrixes dosen't meet the criteria to be multiplied, it prompts to enter new matrixes again to calculate.
  else{
    cout << "please enter the size of the matrixes that are computable. Thankyou. \n";
    matrix();
  }
//offers the choice to return to main page or use the program again or exit the entire program.
  cout << "**if you want to return to first page chose 1, if you want to calculate the matrix again chosse 2 else chose 3 to end the program.**\n";
  int ch;
  cin >> ch;
  cout << "\n";
  switch (ch)
  {
  case 1:
    main();
    break;
  case 2:
    matrix();
    break;
  case 3:
    cout << "thank you for chossing us. have a good day.\n\n";
    break;
  }

}

// the file reader program starts here.
void filereader(){
  int choice;
  int choice1;
  cout << "Sorry there is no existing file. create new by entering 1 or enter 0 to return to main page.\n\n";//tells the user that there is no saved file to access.
  cin >> choice1;
  if (choice1 == 1){
    cin.ignore();
    ofstream outFile("Example.txt");// opens our file.
    string txt;
      while (true) {
      cin.ignore(); // Servs as decoy call to make the getline function work properly.
      cout << "your file is open with the name 'Example.txt. write on and hit enter to close it. \n";
      getline(cin, txt);  // Read a line of input from the keyboard.
      outFile << txt << endl;  // Write the input to the file.
      outFile.close();
      break;
    }  
    //offers the choice to return to main page or read our file.
    cout << "you want: \n\n";
    cout << "1, read your file.\n";
    cout << "2, return to first page.\n";
    cin >> choice;
    ifstream inFile("Example.txt"); // opens our file to read it.
    string line;
    switch (choice)
    {
    case 1:
      cout << "Contents of the file:\n" << "=================================================================================================\n\n" << endl; 
      while (getline(inFile, line)) {
        cout << line << endl;
      }
      inFile.close();
      //offers the choice to return to main page or use the program again or exit the entire program.
      cout << "\n\n" << "=================================================================================================\n\n" << endl;
      cout << "you want: \n\n";
      cout << "1, return to main page.\n";
      cout << "2, to use the file reader again\n";
      cout << "3, close the program.\n";
      int n;
      cin >> n;
      if (n==1){
        main();
        break;
      }
      else if (n==2){
        filereader();
        break;
      }
      else if (n==3){
        cout << "thank you for chossing us. have a good day.\n\n";
        break;
      }
      break;
    case 2:
      main();
      break;
    }
  }
  else(choice1 == 0);{
    main();
  }  
}
// this section is the section telling about the program and the students who programed it.
void program(){
  cout << "^_____^   hi, welcome to our about the program page. I am Adama Science and Technology university 1st year Pre-Engineering section 39 student.\n"
       << "I developed this program for our C++ course project. Thankyou!  ^_____^\n";
  cout << "\n\n"<<"Student name and information: \n\n";
  cout << " Menwuyelet Temesgen  Sc. 39 \n";
  cout << "\n\n";
//offers the choice to return to main page or use the program again or exit the entire program.
  cout << "**if you want to return to first page chose 1, else chose 2 to end the program.**\n";
  int ch;
  cin >> ch;
  switch (ch)
  {
  case 1:
    main();
    break;
  case 2:
    cout<<"thank you for chossing us. have a good day.\n\n";
    break;
  }
}


