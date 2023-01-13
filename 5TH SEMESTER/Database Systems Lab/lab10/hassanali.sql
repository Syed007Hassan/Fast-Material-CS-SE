
/

SET AUTOCOMMIT OFF;


/
----------------1---------------

CREATE TABLE Persons
 (
  PersonID int PRIMARY KEY ,
  FirstName varchar(255),
  LastName varchar(255),
  Address varchar(255),
  City varchar(255),
  Age int
);

insert into Persons values(5,'Furqan','fazal','abc','Karachi',20);

SAVEPOINT after_5_rows;

insert into Persons values(6,'Munir','Abbasi','abc','Karachi',20);

insert into Persons values(7,'Erum','Zahid','abc','Karachi',20);

update Persons 
set FIRSTNAME = 'Rida'
where personid = 7;


ROLLBACK TO SAVEPOINT after_5_rows;

--AFTER PERFORMING ROLLBACK WE ONLY HAVE 5 ROWS IN TABLE

select * from PERSONS;

----------------2---------------

insert into Persons values(7,'Erum','Zahid','abc','Karachi',20);
insert into Persons values(8,'Mustafa','Zahid','abc','Karachi',28);

Update PERSONS
set age = 30
where PersonID = 8;

--SET TRANSACTION
--NAME 'update_on_same_id';
--

Update PERSONS
set age = 30
where PersonID = 8;


--Since we are updating a value that has not been committed yet so it will 
--not update the record on the new session, we need to commit that on previous seesion

select * from PERSONS;
set transaction name 'Afterupdate';

savepoint afterupdate;

Update PERSONS
set age = 32
where PersonID = 1;

set transaction name 'Afterupdate1';
savepoint afterupdate;

commit;

rollback to savepoint afterupdate;
-- once committed cant be rolled back


SET TRANSACTION NAME 'HELLO';

SAVEPOINT A;

ROLLBACK TO SAVEPOINT A;
/


