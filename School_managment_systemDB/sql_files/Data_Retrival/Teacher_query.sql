START TRANSACTION;
    USE DATABASEPROJECT;
    SELECT 
        u.user_id AS teacher_id,
        u.first_name,
        u.last_name,
        u.gender,
        u.date_of_birth,
        a.city,
        a.kebele,
        a.home_number,
        a.postal_number,
        c.email AS teacher_email,
        c.phone AS teacher_phone,
        st.role,
        st.hiring_date,
        st.salary,
        st.bank_account,
        t.specialization,
        t.class_id,
        hr.class_id AS homeroom_class_id
    FROM 
        Teacher t
    LEFT JOIN Staff st ON t.teacher_id = st.staff_id
    LEFT JOIN User u ON st.staff_id = u.user_id
    LEFT JOIN Address a ON u.address_id = a.address_id
    LEFT JOIN Contact c ON u.user_id = c.user_id
    LEFT JOIN HomeRoom hr ON t.teacher_id = hr.teacher_id;
commit;