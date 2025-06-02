SELECT ST.student_id, ST.student_name, SU.subject_name, COUNT(E.student_id) attended_exams
FROM Students ST
CROSS JOIN Subjects SU
LEFT JOIN Examinations E ON ST.student_id=E.student_id AND SU.subject_name=E.subject_name
GROUP BY ST.student_id, SU.subject_name
ORDER BY ST.student_id, SU.subject_name
