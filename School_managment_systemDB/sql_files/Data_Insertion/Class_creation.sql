START TRANSACTION;
	USE DATABASEPROJECT;
	INSERT INTO Subject(Subject_id, subject_name)
	VALUES (1, 'Biolgy');
	INSERT INTO Schedule(details)
	VALUES ('Weekly Schedule: Monday: 09:00 AM – Math 11:00 AM – Biology 03:00 PM – Physics, Tuesday: 10:00 AM – Chemistry 01:00 PM – English 04:00 PM – PE, Wednesday: 09:30 AM – Geography 12:00 PM – History 02:00 PM – ICT, Thursday: 10:00 AM – Civics 01:00 PM – Math 03:30 PM – Chemistry, Friday: 08:30 AM – Physics 11:00 AM – Biology 01:00 PM – ICT');
	INSERT INTO Class(class_name, academic_year, subject_id, schedule_id)
	VALUES ('10th A', '2025', 1, 1);
    
	UPDATE Student 
	SET class_id = 1
	WHERE student_id = 1; 
    
	UPDATE Teacher
	SET class_id = 1
	WHERE teacher_id = 3; 

	INSERT INTO HomeRoom(class_id, teacher_id)
	VALUES(1, 3);

COMMIT;