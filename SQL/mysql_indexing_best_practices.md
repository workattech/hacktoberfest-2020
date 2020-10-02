---
Author: Akhil Mathew
Title: MySQL indexing best practices.
Create indexes, but do it wisely. 
In this tutorial, I will explain the best practices that developers can implement for their MySQL performance tuning efforts.
---


TL;DR This story is going to be a bit longer than usual because the topic demands it’s so. Before jumping into the nitty-gritty of indexing your MySQL query, I think its good to share how I am worthful (which I think :-)) to create such a story. During my work tenure, I got a chance to work with MySQL databases having data size up to 700 Million. I know these numbers are way small. Even though, I am sharing you guys how I indexed and optimized queries. I will be emphasizing more on how to index rather than what is an index and why it’s required.

When you should Optimize MySQL database?

Ideally, query performance tuning should happen regularly.
Indexing is not a one-time process. It is advised to conduct weekly or monthly checks of database performance to prevent issues adversely affecting your applications.
The most obvious symptoms of performance problems are:
- Queries take a longer execution time than anticipated.
- Applications using the database become slower than usual.
- Connection timeouts errors.
- It is normal to have several concurrent queries running at one time on a busy system, but it becomes a problem when these queries are taking too long to finish.

How will you recognise which of your queries performing adversely?.

Grasping which of your MySQL query gone crazy is essential in diagnosing the performance issue.

Let me introduce two ways which are your friends in identifying the queries which caused the performance bottleneck.

MySQL Slow query log. Enable it.
processlist. Use it.

show processlist;
show full processlist;

How you will identify whether the query lacks an index?.

Now you understood which are those troublemakers in the application. But, how will you recognise that they perform adversely only due to lack of an index?.
Well, EXPLAIN statement of MySQL can be your lifesaver.

EXPLAIN is used to obtain a query execution plan (that is, an explanation of how MySQL would execute a query).
EXPLAIN works with SELECT, DELETE, REPLACE, and UPDATE (From Mysql version 5.7 onwards) statements.
Just like you, MySQL will have amazing plans for each query on how to execute, which index to pick, how to join tables and which order it should maintain for optimal performance.

Check out the below table description, I want you to memorise this table as it will be using in most of my examples.
The table doesn’t have any index at present.
Table description

Let’s take a sample query and analyse what EXPLAIN yields to it.

select * from master_users where email="akhil@gmail.com"

Explaining the above query gives as…

Before Index
Let’s breakdown the EXPLAIN result. 

As you can see MySQL had traversed through 152685 rows (See the column: rows) of the table to find a matching row and its equal to a full table scan because the table has 153728 rows in total. 
EXPLAIN result has two columns with names as possible keys and key. possible_keys column tells us what are the available indexes in a table or the indexes which may be used for our queries. keys column tells us what are the indexes that MySQL used for the analyzed query. 
As of now, both are empty. An empty key column provides you with the information that the query lacks an index.

Let’s add one index and examine what happens.
ALTER TABLE master_users ADD INDEX index_email(email)

After adding an index.

Now you can see that the query is better optimized and MySQL was able to find a matching result without traversing many rows.
If you notice, we have our index name present in both of the columns possible_keys and key.

You optimized a simple query but mine is a complex one!!!

I know that the query optimized just now is a piece of cake for you. Before jumping into more complex queries,
I want you to learn the Rule of Thumb in indexing.

MySQL can only use one index per each of the tables in a query (Exemptions are there. eg, Merging of indexes). 
Which ideally means that a table in a query, must use a single index for all where-clause, table join, group-by and order-by.

Believe me, learning this rule was a breakthrough in my career. I used to believe that, it’s required to add an individual single index on each of the columns used in WHERE clause, JOIN clause, group-by and order-by.

Let’s take another query.
select * from master_users where email="akhil@gmail.com" and category_id=3

Keeping the rule of thumb in mind, you already know that creating two indexes on email and category will not help.
If separate single-column indexes exist on col1 and col2, MySQL optimizer attempts to use the Index Merge optimization or attempts to find the most restrictive index by deciding which index excludes more rows and using that index to fetch the rows.
Now, what you will do?.

A multiple column (composite) index to the rescue..!
Composite index or Multiple columns index

To optimize such queries, you should create a composite or compound index. A composite index can be described as a compound of multiple columns.
By adding several columns into an index you can narrow down the number of rows MySQL has to traverse to find matching rows. An index may consist of up to 16 columns.

Let’s see, how you can create a composite index.

ALTER TABLE <table-name> ADD INDEX index_co1_col2(column1, column2, column3,...)

Does the column’s order matters in a compound index?.

Yes, it does matters.
A column which is having the least cardinality value (Having less number of distinctive values) should always be positioned as the left-most side in a composite index.
Order of precedence of other columns also dependent on the cardinality of respective columns.

Now, How will you find the cardinality or number of distinct values of a column?. You can just perform a distinctive count query on the column. (It’s advised not to perform such queries mentioned below in a production DB when it is running in the peak time of traffic.)

select count(distinct(email)) from master_users
select count(distinct(category_id)) from master_users

Distinctive counts of each column

Here you can see that the cardinality of the category_id column is less than that of email column so that we should create a composite index just as follows.

ALTER TABLE master_users ADD INDEX index_category_email(category_id, email)

As you observe the order in which these columns are indexed, and thus how they are sorted will restrict the usage of our index to some particular queries only.

As an example, the index we’ve just created (category_id, email) would not be beneficial for a query such as:

select * from master_users where email=”akhil@gmail.com”

Why? Just now you said that a composite index will be beneficial for mine query.
Well, there is a reason for it.

If the table has a multiple-column index, any leftmost prefix of the index can be used by the optimizer to look up rows.
For example, if you have a three-column index on (col1, col2, col3), you have indexed search capabilities on (col1), (col1, col2), and (col1, col2, col3).
This means that MySQL optimizer can’t use an index to perform lookups if the query doesn’t contain the leftmost prefix column of the index. So the left-most column in a composite index is known as the Lookup column.
MySQL can use multiple-column indexes for queries that test all the columns in the index, or queries that test just the first column, the first two columns, the first three columns, and so on. If you specify the columns in the right order in the index definition, a single composite index can speed up several kinds of queries on the same table.

In the above query, I used email as the only WHERE clause term, hence composite index won’t be useful as it lacks lookup column of the index.
There is another advantage for the composite index; If an index exists on (col1, col2, col3), the same index can be equivalent to creating multiple indexes like an index on col1, index on (col1,col2) and index on (col1,col2,col3) provided index order matters.

if you have a three-column index on (col1, col2, col3), you have indexed search capabilities on (col1), (col1, col2), and (col1, col2, col3)
For example, let’s take an index (status, category_id, email). This index will be useful in below queries.

select * from master_users where status=1
select * from master_users where status=1 and category_id=3
select * from master_users where status=1 and category_id=3 and email="akhil@gmail.com"

But not in the below queries;

select * from master_users where category_id=3
select * from master_users where category_id=3 and email="akhil@gmail.com"

What if your query contains OR operator instead of AND?.

select status,category_id from master_users where status=1 or category_id=3
In this case, MySQL won’t be able to use the index on queries having an OR condition, even if the query contains lookup column and maintains the order of WHERE clause same as the index.
Therefore, it’s recommended to avoid such OR conditions and consider splitting the query to two parts, combined with a UNION DISTINCT (or even better, UNION ALL, in case you know there won’t be any duplicate results)

select status,category_id from master_users where status=1
UNION ALL
select status,category_id from master_users where category_id=3

What if your query contains GROUP BY and ORDER BY

let’s take the same index (status, category_id, email), and you run the query:

select * from master_users where status=1 ORDER BY category_id

This will use the composite index for the WHERE clause and if you think this will narrow down the records with the status having value as 1, sadly you now need to perform a sort on these resulting records to get them sorted by category_id. This is because the index didn’t sort the results by category_id in any meaningful way and ORDER BY clause lacks the lookup column.

This is known as a File Sort (some of you might have noticed this in an explain result). This happens because the index that we created failed to satisfy for the ORDER BY clause.
File Sort: A sort that occurs after the query; it requires fetching the data into a temporary buffer and sorting it before finally returning. This wouldn’t have been needed if the data was already sorted by the index in the way you wanted.

This also applies even If you only wanted to read 10 rows.

select * from master_users where status=1 ORDER BY category_id limit 5

You’ll still be fetching thousands of records, sorting them, and only after this, returning the top 5 while discarding the rest of the records you spent time processing.

select * from master_users where status=1 ORDER BY status, category_id

This query can leverage the usage of the mentioned index because it qualifies for both the WHERE clause and ORDER BY clause.

Consider another query, which sorts rows by the status in ascending order, and then by the category_id in descending order.

select * from master_users where status=1 ORDER BY status ASC, category_id DESC

MySQL cannot use indexes when sorting with a mixed order (both ASC and DESC in the same ORDER BY clause).

Note: This changed with the release of the reversed indexes functionality and MySQL 8.x.

Whatever you saw against ORDER BY is also applicable to GROUP BY statements. if you run the following query with the composite index on (status, category_id, email):

select * from master_users where status=1 GROUP BY category_id

The records are already sorted by status, category_id and email. This allows you to quickly filter down all the records with status=1. After these results are returned they are also then sorted based on category_id since the index orders the rows differently than required in the query.

What if your query contains JOINS?.

You should have indexes on all the columns used in the JOIN clauses. i.e, columns on each side of ON clause of a join must be indexed.

What if your query contains RANGE conditions?.

A query is treated as a Range query if it uses any or mix of following operators;
=, <=>, IN(), IS NULL, or IS NOT NULL, >, <, >=, <=, BETWEEN, !=, or <> operators, or LIKE comparisons (If the argument to LIKE is a constant string that does not start with a wildcard character.)

If you’re utilizing an index for range queries, try to make sure the column you’re specifying the range operator is ordered last within the index. You should only add one of them for each table — the most selective condition, as MySQL can only handle one ‘ranged column’ in each index

So what columns should I Index?
You should realize from all that we’ve discussed that it depends…
What columns you’re going to query
What JOINs you’ll perform
What ORDER/GROUP BYs etc.

A bonus topic: Covering Index

Before understanding what a covering index Is, let’s learn how MySQL fetch matching rows for a query.
A MySQL select query consists of two phases. 
A query phase and a fetch phase. In the query phase, MySQL tries to find primary key values of all matching rows using the index. In the fetch phase, MySQL uses these retrieved primary keys to fetch the actual row values.

If you have a MySQL with InnoDB engine, you will commonly use indexes such as Clustered index and secondary index.
When you define a PRIMARY KEY on your table, InnoDB uses it as the clustered index. InnoDB table storage is organized based on the values of the primary key columns, to speed up queries and sorts involving the primary key columns. All indexes other than the clustered index are known as secondary indexes.
Now the main point here is,

In InnoDB, each record in a secondary index contains the primary key columns for the row, as well as the columns specified for the secondary index. InnoDB uses this primary key value to search for the row in the clustered index.
So, MySQL has to depend on the Primary Key index to perform the fetch phase even if all the matching rows are identified using an index (Secondary index).
select mobile from master_users where mode=2
Consider the above query and assume you have created an index on ‘mode’.

MySQL can easily retrieve the Primary Key values for all the records with mode value as 2, however, to fetch the mobile column, MySQL would still need to use the primary key values to fetch row data from the Primary Key index.

Now, what if we add an index like this,

ALTER TABLE master_users ADD INDEX index_covering(mode, mobile)

Using above index, MySQL can easily retrieve the Primary Key values for all the records with mode value as 2, and to fetch the mobile column, MySQL no need to depend on the Primary Key index to fetch row data. Above query is completely covered by the index and hence known as a covering index.
The ideal database design uses a covering index where practical; the query results are computed entirely from the index, without reading the actual table data.

The Dos and Don’ts of Database Indexing

- Do not create indexes unless you know you’ll need them.
- Don’t index each column in the table separately.
- Avoid using functions on the Left Hand-Side of the Operator.
  Eg: select * from master_users where upper(email)="AKHIL@GMAIL.COM"
- If you use a function in the left-hand side of the operator then MySQL won't use index even if the column has an index on it.
  But, it’s ok to have a function in the right hand
  Eg: select * from master_users where created < now()
- Avoid Wildcard Characters at the Beginning of a LIKE Pattern.
  Don't: select * from master_users where email LIKE "%akhil%"
  Dos: select * from master_users where email LIKE "akhil%"
- MySQL won't use an index for wildcard searches
- Avoid OR conditions and use UNION as an alternative.
- Avoid sorting with a mixed order.
  Don't: select * from master_users where status=1 ORDER BY status ASC, category_id DESC
  Dos: select * from master_users where status=1 ORDER BY status ASC, category_id ASC
- In where clause, compare a column to a value which matches the column’s type.
  Don't: select * from master_users where email=101
  Dos: select * from master_users where email="101"
- Columns on each side of ON clause of a join must be of the same type.
- If columns on each side of ON clause of a join is VARCHAR, make sure the collations of each of the columns are identical.
- You do not want to place too many indexes on tables that are frequently updated
- Keep your table statistics up to date.
  This is done with ANALYZE TABLE table_name

Create indexes, but do it wisely. Happy indexing…!!!
