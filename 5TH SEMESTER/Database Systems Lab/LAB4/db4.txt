-----------Practice--------
Select department_id, MIN(salary) as "Low salary" 
from Employees Group by DEPARTMENT_ID 
having MIN(salary) > 2500;

Finds the employees who have the highest salary:

select employee_id, salary from employees
where salary = (select max(salary) from EMPLOYEES);

Finds all employees who salaries are greater than the average salary of all employees:

select employee_id, salary from employees
where salary > 
(select avg(salary) from employees);

Show the name and dept_ID of all employees having location_ID=1700

SELECT first_name, department_id from employees
where department_id IN
(select department_id from departments where location_id = 1700); 

-----------Practice--------


----------LAB TASK----------
Task#01: For each department, retrieve the department no, the number of employees
in the department and their average salary.

SELECT DEPARTMENT_ID, COUNT(*) 
AS NUMBER_OF_EMPLOYEES, AVG(SALARY) 
FROM EMPLOYEES GROUP BY DEPARTMENT_ID;


Task#02: Write a Query to display the number of employees with the same job.

SELECT JOB_ID, COUNT(*) AS NUMBER_OF_EMPLOYEES 
FROM EMPLOYEES GROUP BY JOB_ID;


Task#03: Write a Query to select Firstname and Hiredate of Employees 
Hired right after the joining of employee_ID no 110.

SELECT FIRST_NAME, HIRE_DATE FROM EMPLOYEES WHERE HIRE_DATE > 
(SELECT HIRE_DATE FROM EMPLOYEES WHERE EMPLOYEE_ID = 110);


Task#04: Write a SQL query to select those departments where maximum salary is at least 15000.

SELECT DEPARTMENT_ID, MAX(SALARY) FROM EMPLOYEES
GROUP BY DEPARTMENT_ID HAVING MAX(SALARY) > 15000;   --output

SELECT department_id, salary FROM EMPLOYEES 
where salary > 
(select department_id from employees where max(salary) > 15000); --no output


Task#05: Write a query to display the employee number, 
name (first name and last name) and job title for all employees whose salary 
is smaller than any salary of those employees whose job title is IT_PROG.

SELECT EMPLOYEE_ID, FIRST_NAME || ' ' || LAST_NAME AS FULL_NAME, JOB_ID AS JOB_TITLE
FROM EMPLOYEES WHERE SALARY < ANY 
(SELECT SALARY  FROM EMPLOYEES WHERE JOB_ID = 'IT_PROG');


Task#06 Write a query in SQL to display all the information 
of those employees who did not have any job in the past.

SELECT *FROM EMPLOYEES WHERE DEPARTMENT_ID NOT IN
(SELECT DEPARTMENT_ID FROM JOB_HISTORY);


Task#07: Display the manager number and the salary of the lowest paid 
employee of that manager. Exclude anyone whose manager 
is not known. Exclude any groups where the minimum salary is 2000.
Sort the output is descending order of the salary.

SELECT MANAGER_ID, MIN(SALARY) FROM EMPLOYEES WHERE SALARY IN 
(SELECT MIN(SALARY) FROM EMPLOYEES GROUP BY MANAGER_ID HAVING (MIN(SALARY) <> 2000) 
AND MANAGER_ID IS NOT NULL) 
GROUP BY MANAGER_ID ORDER BY MIN(SALARY);


Task#08: Insert into employees_BKP as it should copy the record of the employee 
whose start date is ’13-JAN-01’ from job_History table.

CREATE TABLE EMPLOYEES_BKP AS SELECT * FROM EMPLOYEES WHERE 1=2;

INSERT INTO EMPLOYEES_BKP 
SELECT *FROM EMPLOYEES WHERE EMPLOYEE_ID =
(SELECT EMPLOYEE_ID FROM JOB_HISTORY WHERE START_DATE = '13-JAN-01');


Task#09: Update salary of employees by 20% increment having minimum salary of 6000.

UPDATE EMPLOYEES_BKP
SET SALARY = SALARY + (SALARY*0.2)
WHERE JOB_ID IN
(SELECT JOB_ID FROM JOBS WHERE MIN_SALARY = 6000);


Task#10: Delete the record of employees from employees_BKP who are manager 
and belongs to the department ‘Finance’.

DELETE FROM EMPLOYEES_BKP
WHERE MANAGER_ID IN 
(SELECT MANAGER_ID FROM DEPARTMENTS WHERE DEPARTMENT_NAME = 'Finance');


Task#11: For each department that has more than five employees, retrieve the department number and the 
number of its employees who are making more than $20,000.

SELECT DEPARTMENT_ID, COUNT(EMPLOYEE_ID) AS "NO OF EMPLOYEES" FROM EMPLOYEES WHERE
SALARY > 20000 GROUP BY DEPARTMENT_ID HAVING COUNT(EMPLOYEE_ID) > 5;

