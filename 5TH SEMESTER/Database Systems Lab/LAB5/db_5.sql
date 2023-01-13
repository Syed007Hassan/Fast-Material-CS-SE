--practice
SELECT
    e.first_name,
    d.department_id,
    l.city,
    l.location_id
FROM
    employees e,
    departments d,
    locations l
WHERE
    e.department_id = d.department_id
    AND d.location_id = l.location_id;

1-Write a query to list the name, job name, department name, salary of the
employees according to the department in ascending order.

SELECT e.first_name, e.salary, d.department_id,d.department_name
from employees e, departments d
order by d.department_id asc;

select e.first_name, e.salary,d.department_id,d.department_name 
from Employees e join Departments d 
on e.department_id = d.department_id 
order by d.department_id asc;

2-Write a query to list the department where at least two employees are working.

select count(e.employee_id),d.department_name
from Employees e ,Departments d
where e.department_id = d.department_id 
Group by d.department_name
having count(e.employee_id) >= 2;

select * from Employees e intersect select * from Employees d;

3-Fetch all the records where salary of employee is less than the lower salary.

select e.first_name,e.salary,e.job_id 
from Employees e , Jobs j
where j.job_id = e.job_id And e.salary < j.min_salary;

4-Write a query to list the name, job name, annual salary, department id,
department name and city who earn 60000 in a year or not working as an
ANALYST.

select e.first_name, j.job_title, e.salary, d.department_id, l.location_id
from Employees e, Jobs j, locations l, Departments d
WHERE (E.DEPARTMENT_ID = D.DEPARTMENT_ID) AND (l.LOCATION_ID = d.LOCATION_ID) AND (E.JOB_ID= J.JOB_ID)
and (e.salary > 60000 or j.job_title != 'Analyst');

5-Write a query to print details of the employees who are also Managers.

select (e.first_name) as "Manager Name", (e.employee_id) as "Employee id" 
from employees e, employees ee
where ee.manager_id = e.employee_id;

6-List department number, Department name for all the departments in which
there are no employees in the department.

select count(*) as "dsf", e.department_id, d.department_name 
from departments d, employees e
where e.department_id = d.department_id
group by e.department_id,d.department_name
having count(*) < 1;

select e.department_id, d.department_name
from employees e, departments d
where e.department_id = d.department_id and e.department_id = 0;   --XXXX

7-Display employee name, salary, department name where all employees has
matching department as well as employee does not have any departments.
-- left outer join
select e.first_name, e.salary, d.department_name
from employees e, departments d
where e.department_id = d.department_id(+);

SELECT E.FIRST_NAME, E.SALARY, D.DEPARTMENT_NAME
FROM EMPLOYEES E, DEPARTMENTS D
WHERE E.DEPARTMENT_ID = D.DEPARTMENT_ID(+);

 select e.first_name||' '||e.last_name as Name,salary, d.department_name from employees e,
departments d where e.department_id=d.department_id(+) order by e.department_id;

select e.first_name, e.salary, d.department_id 
from employees e left outer join departments d
on e.department_id = d.department_id;

8-Display name, job ID, department name, street address and city of the
employee in which there is no state province.

select e.first_name, d.department_name, j.job_id,l.location_id,l.street_address,l.city
from employees e, departments d, jobs j, locations l
where l.location_id = d.location_id and d.department_id = e.department_id and j.job_id = e.job_id 
and l.state_province is null;

select e.first_name||' '||e.last_name as Name, e.job_ID, d.department_name, l.street_address,
l.city from employees e, locations l,departments d where d.department_id=e.department_id and
 d.location_id=l.location_id and l.state_province is null;

9-Write an SQL query to show records from one table that another table does not have.

select job_id from jobs minus select job_id from employees;

SELECT employee_id, job_id FROM employees MINUS SELECT
employee_id, job_id FROM job_history;

select employee_id, job_id From employees union select employee_id, job_id 
from job_history;

10-Display all employees who belong to country US but not belongs to state province Washington.

select e.first_name,l.state_province, l.country_id
from employees e, locations l, departments d
where (e.department_id = d.department_id) and (d.location_id = l.location_id)
and (l.country_id = 'US' and l.state_province <> 'Washington'); 


select count(job_id), job_id from employees group by job_id having count(job_id) > 2;

select d.department_name,e.department_id, avg(salary),count(*) 
from employees e, departments d
where e.department_id = d.department_id
group by e.department_id;

SELECT  E.DEPARTMENT_ID,AVG(SALARY),COUNT(*) 
FROM EMPLOYEES E,DEPARTMENTS D 
WHERE E.DEPARTMENT_ID = D.DEPARTMENT_ID
AND E.COMMISSION_PCT IS NOT NULL GROUP BY E.DEPARTMENT_ID

--1
SELECT INITCAP(LAST_NAME) FROM EMPLOYEES;
--2
SELECT LAST_NAME FROM EMPLOYEES WHERE LAST_NAME like '%aa%';
--3
SELECT COUNT(*),JOB_ID FROM EMPLOYEES GROUP BY JOB_ID;
--4
SELECT E.FIRST_NAME||' '||E.HIRE_DATE,LENGTH(E.FIRST_NAME) FROM EMPLOYEES E,JOBS J WHERE E.JOB_ID = J.JOB_ID 
AND J.JOB_TITLE = 'Sales Representative';
--5
SELECT E.FIRST_NAME, S.FIRST_NAME  FROM EMPLOYEES E,EMPLOYEES S WHERE E.EMPLOYEE_ID = S.MANAGER_ID ;
--6
UPDATE EMPLOYEES set SALARY=SALARY+(0.5*SALARY) where SALARY <=7000;
--7
SELECT  E.DEPARTMENT_ID,AVG(SALARY),COUNT(*)
FROM EMPLOYEES E,DEPARTMENTS D 
WHERE E.DEPARTMENT_ID = D.DEPARTMENT_ID
AND E.COMMISSION_PCT IS NOT NULL 
GROUP BY E.DEPARTMENT_ID;
--8
SELECT First_Name,HIRE_DATE FROM EMPLOYEES WHERE HIRE_DATE<'20-MAY-07';
--9
SELECT J.* FROM JOBS J , JOB_HISTORY H WHERE J.job_id = H.JOB_ID AND J.JOB_TITLE = 'Public Accountant';
--10

SELECT FIRST_NAME,SALARY,EMAIL,DEPARTMENT_ID FROM EMPLOYEES 
WHERE SALARY > (SELECT AVG(SALARY) FROM EMPLOYEES) ORDER BY SALARY desc;

--11

SELECT FIRST_NAME, SALARY,COMMISSION_PCT,SALARY+(commission_pct*salary) AS TOTALSALARY 
FROM EMPLOYEES WHERE COMMISSION_PCT IS NOT NULL ;
--12
SELECT L.CITY,L.COUNTRY_ID,D.DEPARTMENT_ID 
FROM LOCATIONS L,DEPARTMENTS D WHERE d.location_id = l.location_id AND d.department_id
IN

( SELECT
    department_id
  FROM
    employees
  GROUP BY
    department_id
HAVING
    COUNT(*) > 3
);
--13

SELECT
    e.department_id,
    d.department_name,
    l.city,
    l.country_id,
    l.postal_code
FROM
    employees e,
    departments d,
    locations l
WHERE
    e.manager_id = d.manager_id
    AND d.location_id = l.location_id;
--14

SELECT
    e.first_name,
    e.last_name,
    e.department_id,
    d.department_name
FROM
    employees e,
    departments d
WHERE
    e.department_id = d.department_id
    OR e.department_id IS NULL;
--15

SELECT
    e.first_name,
    e.last_name,
    e.salary,
    e.manager_id,
    d.department_name,
    l.city
FROM
    employees e,
    departments d,
    locations l
WHERE
    e.last_name LIKE '%y'
    AND e.department_id = d.department_id
        AND d.location_id = l.location_id;

select (months_between('10-DEC-23',sysdate) / 12)  from dual;
