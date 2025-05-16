START TRANSACTION;
	USE DATABASEPROJECT;
     
     INSERT INTO Subject(subject_id, subject_name)
     VALUES('BIO10', 'Biology');

     INSERT INTO Class(class_id, class_name, academic_year)
     VALUES('C10A', '10th A', '2025');


     INSERT INTO Schedule(schedule_id, details)
	VALUES ('SCHE/C10A/25','Weekly Schedule: Monday: 09:00 AM – Math 11:00 AM – Biology 03:00 PM – Physics, Tuesday: 10:00 AM – Chemistry 01:00 PM – English 04:00 PM – PE, Wednesday: 09:30 AM – Geography 12:00 PM – History 02:00 PM – ICT, Thursday: 10:00 AM – Civics 01:00 PM – Math 03:30 PM – Chemistry, Friday: 08:30 AM – Physics 11:00 AM – Biology 01:00 PM – ICT');
	

     UPDATE Class
     SET schedule_id = 'SCHE/C10A/25' 
     WHERE class_id = 'C10A';

     INSERT INTO ClassSubject(class_id, subject_id)
     VALUES ('C10A' ,'BIO10');

     INSERT INTO HomeRoom(class_id, teacher_id)
     VALUES('C10A', 'SCH/T0001/2020');

     UPDATE Teacher
     SET class_id = 'C10A'
     WHERE teacher_id = 'SCH/T0001/2020';

     UPDATE Student
     SET class_id = 'C10A'
     WHERE student_id = 'SCH/S0001/25';
COMMIT;