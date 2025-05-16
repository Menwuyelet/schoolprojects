-- Programed by: Menwuyelet Temesgen UGR/34920/16 Sec. 5

CREATE DATABASE HospitalDB;
USE HospitalDB;


-- Creating the Patients table.
CREATE TABLE Patients (
    patient_id VARCHAR(15) PRIMARY KEY,
    name VARCHAR(20),
    date_of_birth DATE,
    gender ENUM('Male', 'Female'),
    medical_history TEXT
);

-- Creating the Doctors table.
CREATE TABLE Doctors (
    doctor_id VARCHAR(15) PRIMARY KEY,
    name VARCHAR(20),
    gender ENUM('Male', 'Female'),
    specialty VARCHAR(50)
);

-- Creating the Appointments table.
CREATE TABLE Appointments (
    appointment_id VARCHAR(15) PRIMARY KEY,
    patient_id VARCHAR(15),
    doctor_id VARCHAR(15),
    appointment_date DATE,
    appointment_time TIME,
    FOREIGN KEY (patient_id) REFERENCES Patients(patient_id),
    FOREIGN KEY (doctor_id) REFERENCES Doctors(doctor_id)
);

-- Creating the Bills table.
CREATE TABLE Bills (
    bill_id VARCHAR(15) PRIMARY KEY,
    patient_id VARCHAR(15),
    date DATE,
    service_charges DECIMAL(10,2),
    medication_costs DECIMAL(10,2),
    FOREIGN KEY (patient_id) REFERENCES Patients(patient_id)
);

-- Inserting sample data into Patients table.
INSERT INTO Patients (patient_id, name, date_of_birth, gender, medical_history)
    VALUES 
        ('P00001/25', 'Abel Mekonin', '1990-02-15', 'Male', 'Asthma'),
        ('P00002/25', 'Lamin Yamal', '1985-07-20', 'Male', 'Muscel problems'),
        ('P00003/25', 'Frenkie deJong', '1978-11-02', 'Male', 'Hamstering');


-- Inserting sample data into Doctors table.
INSERT INTO Doctors (doctor_id, name, gender, specialty)
    VALUES 
        ('D00001/20', 'Dr. Ana Frank','Female', 'Physiologist'),
        ('D00002/21', 'Dr. Ted Mosby','Male', 'Surgeon'),
        ('D00003/21', 'Dr. Mekides Tekilu','Female', 'Resident Doctor');


-- Inserting sample data into Bills table
INSERT INTO Bills (bill_id, patient_id, date, service_charges, medication_costs)
    VALUES 
    ('BILL0001/25', 'P00001/25', '2025-01-02', 100, 350);
