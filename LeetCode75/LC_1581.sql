SELECT customer_id, COUNT(customer_id) AS count_no_trans
FROM Visits
LEFT JOIN Transactions ON Visits.visit_id = Transactions.visit_id
WHERE transaction_id IS NULL
GROUP BY Visits.customer_id
