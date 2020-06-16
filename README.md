# Cryptocurrency blockchain network

## **Purpose:** 
The program's architecture is based on a shared object library (.SO), 
which implements the main data structure used by all of the sub-programs
(LinkedList).

It's made out of 4 sub-programs managing a database of Bitcoin blocks:
(1)loading (from WEB source) the data to the db.
(2)displaying the data from the db, with the ability to execute searches.
(3)exporting data to a .csv file.

It was written as part of an assignment in LINUX embedded course.

### Program: #1
**Program's name:** printdb.out

**Purpose:** Print all the database to stdin.

### Program: #2
**Program's name:** formatter.out

**Purpose:** Export databse to *.csv format

### Program: #3
**Program's name:** reloader.out

**Purpose:** Reload the Bitcoin database.

### Program: #4
**Program's name:** block_finder.out

**Purpose:** Search for specific block according to Hash or Height values.

## **Compilation & Execution:**
Download \ clone the whole repo & run make command from the 
folder where you downloaded. After the compilaton is done, you can run each
one of the 4 sub programs by name.

## **Compatibility:**
Program was compiled and tested in Linux (Ubunto) environment.
