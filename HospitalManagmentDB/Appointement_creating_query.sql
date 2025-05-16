USE HospitalDB;
-- Inserting sample data into Appointments table by checking wether if the doctor is available or not using procedure.
DELIMITER //
CREATE PROCEDURE BookAppointment (
    IN appointmentID VARCHAR(15),
    IN patientID VARCHAR(15),
    IN doctorID VARCHAR(15),
    IN appointmentDate DATE,
    IN appointmentTime TIME
)
BEGIN
    IF EXISTS (
        SELECT 1 
        FROM Appointments 
        WHERE doctor_id = doctorID 
          AND appointment_date = appointmentDate 
          AND appointment_time = appointmentTime
    ) THEN
        SIGNAL SQLSTATE '45000' 
        SET MESSAGE_TEXT = 'The doctor is already booked at this time.';
    ELSE
        INSERT INTO Appointments (
            appointment_id, patient_id, doctor_id, appointment_date, appointment_time
        ) VALUES (
            appointmentID, patientID, doctorID, appointmentDate, appointmentTime
        );
    END IF;
END;
//
DELIMITER ;

-- calling the procedure and passing it he parameters to create apointment.
CALL BookAppointment(
    'APP0001/25',    -- appointment_id
    'P00001/25',     -- patient_id
    'D00001/20',     -- doctor_id
    '2025-01-02',    -- appointment_date
    '08:00'          -- appointment_time
);

-- calling the procedure again with conflicitng apointment to check. uncomment the procedure call below to see the erro mesage.
-- CALL BookAppointment(
--     'APP0002/25',    -- appointment_id
--     'P00002/25',     -- patient_id
--     'D00001/20',     -- doctor_id
--     '2025-01-02',    -- appointment_date
--     '08:00'          -- appointment_time
-- );


-- View All Appointments with Patient and Doctor Names
SELECT 
    A.appointment_id,
    P.name AS patient_name,
    D.name AS doctor_name,
    D.doctor_id AS doctor_id,
    A.appointment_date,
    A.appointment_time
FROM 
    Appointments A
JOIN 
    Patients P ON A.patient_id = P.patient_id
JOIN 
    Doctors D ON A.doctor_id = D.doctor_id;
