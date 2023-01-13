--TASK 1
connect system
create user hassan identified by fast;
grant all privileges to hassan;
alter user hassan account unlock;

--Task#02: Create table Jobs and job_History (ignore foreign keys relations) same fields as given in HR
--Schema in which job_ID is considered as primary key in jobs table.
CREATE TABLE JOBS AS (SELECT * FROM HR.JOBS WHERE 1=2);
ALTER TABLE JOBS ADD PRIMARY KEY (JOB_ID);

CREATE TABLE JOB_HISTORY AS (SELECT *FROM HR.JOB_HISTORY WHERE 1=2);
ALTER TABLE JOB_HISTORY ADD PRIMARY KEY (EMPLOYEE_ID);

--Task#03: Change the data type of ‘job_ID’ from character to numeric in Jobs table.(Like IT_Prog-&gt;101).
ALTER TABLE JOBS MODIFY JOB_ID NUMBER;
DESC JOBS;

--Task#04: Write a SQL statement to add job_id column in job_history table 
--as foreign key referencing to the primary key job_id of jobs table.
ALTER TABLE JOB_HISTORY MODIFY JOB_ID NUMBER;
ALTER TABLE JOB_HISTORY ADD FOREIGN KEY (JOB_ID) REFERENCES JOBS(JOB_ID);
DESC JOB_HISTORY;

--Task#05: Insert a new row in jobs table having all the attributes and the job_ID
--should update in job_History table as well.
INSERT INTO JOBS VALUES (1001,'Manager',1000,5000);
INSERT INTO JOB_HISTORY VALUES (2001, '08-JAN-00', '09-SEP-22',1001, 90);

--Task#06: Add Column Job_Nature in Jobs table.
ALTER TABLE JOBS ADD JOB_NATURE VARCHAR(30);

--Task#07: Create replica of employee table.
CREATE TABLE EMPLOYEES AS (SELECT * FROM HR.EMPLOYEES WHERE 1=2);

--Task#08: Write a SQL statement to add employee_id column in job_history table as foreign key 
--referencing to the primary key employee_id of employees table.
SELECT *FROM JOB_HISTORY;
ALTER TABLE JOB_HISTORY ADD FOREIGN KEY (EMPLOYEE_ID) REFERENCES EMPLOYEE(EMPLOYEE_ID);

--Task#09: Drop column Job_Nature.
ALTER TABLE JOBS DROP COLUMN JOB_NATURE;

--Task#10: ALTER table EMPLOYEE created in question 5 and apply the constraint CHECK on
--First_Name attribute such that ENAME should always be inserted in capital letters.
ALTER TABLE EMPLOYEES
ADD CONSTRAINTS ENAME CHECK (FIRST_NAME = UPPER(FIRST_NAME));

--Task#11: ALTER table EMPLOYEE created in question 5 and apply the constraint on SALary attribute
--such that no two salaries of the employees should be similar.(Hint Unique)
ALTER TABLE EMPLOYEES ADD CONSTRAINT UNIQUE_SAL UNIQUE(SALARY);

--Task#12: ALTER table Employee created in question 5 and apply constraint on Phone_No such 
--that Phone_No should not be entered empty (Hint modify).
ALTER TABLE EMPLOYEES MODIFY PHONE_NUMBER VARCHAR2(30) NOT NULL;

--Task#13: Write a SQL statement to insert one row into the table employees.
INSERT INTO EMPLOYEES VALUES(1052,'HASSAN','ALI','k201052@nu.edu.pk','09000786','08-JAN-00',101,750,10,90,15);

--Task#14: Write a SQL statement to change the salary of employee to 8000 who’s ID is 105, 
--if the existing salary is less than 1+000.
UPDATE EMPLOYEES SET SALARY = 8000 WHERE (EMPLOYEE_ID = 105 AND SALARY < 1000);

--Task#15: Write a SQL statement to add a primary key for a combination of columns employee_id and
--job_id in employees table, give the reason why this command is showing error.
ALTER TABLE EMPLOYEE
ADD CONSTRAINTS PRIMARY_KEY PRIMARY KEY (EMPLOYEE_ID,JOB_ID);

Error: A table can have only one primary key, in this case we are trying to make a composite key but there already exists a primary key
in employee table, we can not just directly add new key without deleting existing one.

--Task#16: Write a SQL statement to add an index named indx_job_id on job_id column in the table job_history.
CREATE INDEX indx_job_id ON JOB_HISTORY (JOB_ID);

Task#17: Write a SQL statement to remove employees table.
DROP TABLE EMPLOYEES;



