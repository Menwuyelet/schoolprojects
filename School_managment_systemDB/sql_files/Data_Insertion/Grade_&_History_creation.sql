START TRANSACTION;
	USE DATABASEPROJECT;
     INSERT INTO Grade(score, assesment_type, assessment_date, subject_id, student_id, teacher_id)
     VALUES (5, 'Quiz', '2024-05-05', 'BIO10', 'SCH/S0001/25', 'SCH/T0001/2020');
     
     INSERT INTO TotalGrade(total, subject_id, student_id, teacher_id)
     VALUES (80, 'BIO10', 'SCH/S0001/25', 'SCH/T0001/2020');

     INSERT INTO History(academic_year, overall_status, summary, student_id)
     VALUES('2025', 'Pass', 'Excelent Student.', 'SCH/S0001/25');

COMMIT;