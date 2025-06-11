SELECT S.user_id,
    ROUND(CASE
        WHEN COALESCE(confirm, 0) = 0 THEN 0
        ELSE COALESCE(confirm, 0) / COALESCE(total, 0)
        END, 2) AS confirmation_rate
FROM Signups S
LEFT JOIN (
    SELECT C1.user_id, COUNT(C1.user_id) AS confirm
    FROM Confirmations C1
    WHERE action='confirmed'
    GROUP BY C1.user_id
) AS C_N ON S.user_id=C_N.user_id
LEFT JOIN (
    SELECT C2.user_id, COUNT(C2.user_id) AS total
    FROM Confirmations C2
    GROUP BY C2.user_id
) AS T ON S.user_id=T.user_id
