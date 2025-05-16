START TRANSACTION;
    SELECT 
        u.user_id AS student_id,
        u.first_name,
        u.last_name,
        u.gender,
        u.date_of_birth,
        a.city,
        a.kebele,
        a.home_number,
        a.postal_number,
        c.email AS student_email,
        c.phone AS student_phone,
        s.enrollment_date,
        s.class_id,
        cl.class_name,
        cl.academic_year,
        p.parent_id,
        pu.first_name AS parent_first_name,
        pu.last_name AS parent_last_name,
        pc.email AS parent_email,
        pc.phone AS parent_phone
    FROM 
        Student s
    LEFT JOIN User u ON s.student_id = u.user_id
    LEFT JOIN Address a ON u.address_id = a.address_id
    LEFT JOIN Contact c ON u.user_id = c.user_id
    LEFT JOIN Class cl ON s.class_id = cl.class_id
    LEFT JOIN Parent p ON s.parent_id = p.parent_id
    LEFT JOIN User pu ON p.parent_id = pu.user_id
    LEFT JOIN Contact pc ON pu.user_id = pc.user_id;
commit;

