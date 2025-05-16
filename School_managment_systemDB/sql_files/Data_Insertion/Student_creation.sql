START TRANSACTION;
	USE DATABASEPROJECT;
	INSERT INTO User (user_id, first_name, last_name, gender, date_of_birth)
	VALUES ('SCH/S0001/25','John', 'Doe', 'Male', '2005-05-10');
    INSERT INTO Address (address_id, city, kebele, home_number, postal_number)
    VALUES ('ADD/S0001/25', 'Adama', 'bole', '204', '1002');
    INSERT INTO Contact (contact_id, email, phone, user_id)
    VALUES ('CON/S0001/25', 'JOHN@example.com', '001010101', 'SCH/S0001/25');
    
    UPDATE User
    SET address_id = 'ADD/S0001/25' WHERE user_id = 'SCH/S0001/25';
    
    INSERT INTO Student (student_id, enrollment_date)
    VALUES ('SCH/S0001/25', '2012-01-01');
    
    INSERT INTO User (user_id, first_name, last_name, gender, date_of_birth)
	VALUES ('SCH/P0001/25', 'Patric', 'Doe', 'Male', '1980-05-10');
    INSERT INTO Contact (contact_id,email, phone, user_id)
    VALUES ('CON/P0001/25', 'PATRIC@example.com', '00101010', 'SCH/P0001/25');
    
    UPDATE User
    SET address_id = 'ADD/S0001/25' WHERE user_id = 'SCH/P0001/25';
    
    INSERT INTO Parent (parent_id)
    VALUES ('SCH/P0001/25');

    UPDATE Student
    SET parent_id = 'SCH/P0001/25' WHERE student_id = 'SCH/S0001/25';
    
COMMIT;