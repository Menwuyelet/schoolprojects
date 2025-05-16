START TRANSACTION;
CREATE DATABASE DATABASEPROJECT; 
USE DATABASEPROJECT; 
CREATE TABLE Address (
	address_id VARCHAR(15) PRIMARY KEY,
    city VARCHAR(100) NOT NULL,
    kebele VARCHAR(100) NOT NULL,
    home_number VARCHAR(100),
    postal_number VARCHAR(20)
);

CREATE TABLE User (
    user_id VARCHAR(15) PRIMARY KEY,
    first_name VARCHAR(50) NOT NULL,
    last_name VARCHAR(50) NOT NULL,
    gender ENUM('Male', 'Female') NOT NULL,
	date_of_birth DATE NOT NULL,
    address_id VARCHAR(15) NULL,
	FOREIGN KEY (address_id) REFERENCES Address(address_id)
);

CREATE TABLE Contact (
	contact_id VARCHAR(15) PRIMARY KEY,
    email VARCHAR(200) UNIQUE NOT NULL,
    phone VARCHAR(100) UNIQUE NOT NULL,
    user_id VARCHAR(15) UNIQUE,
    Foreign Key (user_id) REFERENCES User(user_id) ON DELETE CASCADE
);	
CREATE TABLE Subject (
	subject_id VARCHAR(15) PRIMARY KEY,
    subject_name VARCHAR(15) NOT NULL
);

CREATE TABLE Parent (
	parent_id VARCHAR(15) PRIMARY KEY,
    FOREIGN KEY (parent_id) REFERENCES User(user_id) ON DELETE CASCADE
);
CREATE TABLE Schedule (
	schedule_id VARCHAR(15)  PRIMARY KEY,
    details TEXT NOT NULL
);
CREATE TABLE Class (
	class_id VARCHAR(15) PRIMARY KEY,
    class_name VARCHAR(20) NOT NULL,
    academic_year YEAR NOT NULL,
    schedule_id VARCHAR(15) NULL,
    FOREIGN KEY (schedule_id) REFERENCES Schedule(schedule_id)
); 

CREATE TABLE ClassSubject (
    class_id VARCHAR(15),
    subject_id VARCHAR(15),
    PRIMARY KEY (class_id, subject_id),
    FOREIGN KEY (class_id) REFERENCES Class(class_id) ON DELETE CASCADE,
    FOREIGN KEY (subject_id) REFERENCES Subject(subject_id) ON DELETE CASCADE
);

CREATE TABLE Student (
	student_id VARCHAR(15) PRIMARY KEY,
    enrollment_date DATE NOT NULL,
    class_id VARCHAR(15) NULL,
    parent_id VARCHAR(15) NULL,
    FOREIGN KEY (student_id) REFERENCES User(user_id) ON DELETE CASCADE,
    FOREIGN KEY (class_id) REFERENCES Class(class_id),
    FOREIGN KEY (parent_id) REFERENCES Parent(parent_id)
);

   
CREATE TABLE History (
    academic_year YEAR NOT NULL,
    overall_status ENUM('Pass', 'Fail', 'Incomplete') NOT NULL,
    summary TEXT,
	modified_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    student_id VARCHAR(15),
    FOREIGN KEY (student_id) REFERENCES Student(student_id) ON DELETE CASCADE,
    PRIMARY KEY(academic_year, student_id)
);

CREATE TABLE Staff (
	staff_id VARCHAR(15) PRIMARY KEY,
    role VARCHAR(100),
    hiring_date DATE NOT NULL,
    salary DECIMAL(10,2) CHECK (salary > 0),
    bank_account VARCHAR(50) NOT NULL,
    FOREIGN KEY (staff_id) REFERENCES User(user_id) ON DELETE CASCADE
);
CREATE TABLE Teacher (
	teacher_id VARCHAR(15) PRIMARY KEY,
    specialization VARCHAR(100) NOT NULL,
    class_id VARCHAR(15) NULL,

    FOREIGN KEY (teacher_id) REFERENCES Staff(staff_id) ON DELETE CASCADE,
    FOREIGN KEY (class_id) REFERENCES Class(class_id)
);

CREATE TABLE Grade (
    score DECIMAL(4, 2),
    assesment_type ENUM('Exam', 'Quiz', 'Assignment', 'Project') NOT NULL,
    assessment_date DATE NOT NULL,
    subject_id VARCHAR(15),
    student_id VARCHAR(15),
    teacher_id VARCHAR(15),
    FOREIGN KEY (subject_id) REFERENCES Subject(subject_id),
    FOREIGN KEY (student_id) REFERENCES Student(student_id) ON DELETE CASCADE,
    FOREIGN KEY (teacher_id) REFERENCES Teacher(teacher_id),
    PRIMARY key (student_id, subject_id, assessment_date)
);
CREATE TABLE TotalGrade (    
    total DECIMAL(5, 2) CHECK (total BETWEEN 0 AND 100) NOT NULL,
    subject_id VARCHAR(15),
    student_id VARCHAR(15),
    teacher_id VARCHAR(15),
    FOREIGN KEY (subject_id) REFERENCES Subject(subject_id),
    FOREIGN KEY (student_id) REFERENCES Student(student_id) ON DELETE CASCADE,
    FOREIGN KEY (teacher_id) REFERENCES Teacher(teacher_id),
    PRIMARY key (student_id, subject_id)
);

-- to create home room - home teacher relation
CREATE TABLE HomeRoom (
	class_id VARCHAR(15) UNIQUE,
    teacher_id VARCHAR(15) UNIQUE,
    FOREIGN KEY (class_id) REFERENCES Class(class_id),
    FOREIGN KEY (teacher_id) REFERENCES Teacher(teacher_id),
    PRIMARY KEY (class_id, teacher_id)
);
COMMIT;
