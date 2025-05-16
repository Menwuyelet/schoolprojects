START TRANSACTION;
	USE DATABASEPROJECT;
	  INSERT INTO User (user_id, first_name, last_name, gender, date_of_birth)
     VALUES ('SCH/T0001/2020', 'Leo', 'Mesi', 'Male', '2005-05-10');
     INSERT INTO Address (address_id, city, kebele, home_number, postal_number)
     VALUES ('ADD/T0001/2020', 'Adama', 'bole', '205', '102');
     INSERT INTO Contact (contact_id, email, phone, user_id)
     VALUES ('CON/T0001/2020', 'Leo@example.com', '1010101', 'SCH/T0001/2020');
     
     UPDATE User
     SET address_id = 'ADD/T0001/2020'WHERE user_id = 'SCH/T0001/2020';
     
     INSERT INTO Staff (staff_id, role, hiring_date, salary, bank_account)
     VALUES ('SCH/T0001/2020', 'Teacher', '2000-02-02', '2000', '1000023434556');

     INSERT INTO Teacher (teacher_id, specialization)
     VALUES ('SCH/T0001/2020', 'Biology');

COMMIT;