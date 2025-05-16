USE HospitalDB;

-- View All Bills with Patient Info
SELECT 
    B.bill_id,
    P.name AS patient_name,
    B.date,
    B.service_charges,
    B.medication_costs,
    (B.service_charges + B.medication_costs) AS total_amount
FROM 
    Bills B
JOIN 
    Patients P ON B.patient_id = P.patient_id;