## Why Use It

Most of software design, or rather design of libraries, looks like this:
library author decides what type of data to represent and manipulate in memory;
Without exception, the library declares some number of *records*, each containing
some fields, and a set of functions that manipulate sets of these records while
maintaining some library-wide invariants.
At a higher level, the library author is said to pick some *data structure*
that offers efficient/economical creation,
modification, updates, and querying. Update operations range from allocation and 
handling of memory-related conditions and errors, to business logic (the most
application-specific part).

Designing abstract data structures is difficult because of the need to track  various 
pointers and cross-references in the resulting data structures, and subsequently 
rewriting these pointers without causing corruption. To be robust and to avoid leaks, 
the library must also track resources that were allocated.
This difficulty, and the corresponding debugging effort, which usually exceeds
the initial coding time by 10- or 100x, means that once a library has been built, it
is not updated frequently. 
Sometimes, the choice of the data structure itself makes adding additional
indexes impractical. For instance, if we think of our main data structure as being 
a "hash table of X", we have committed to a key-value map as the main access structure,
and all other operations are operations other than lookup by key are made less efficient.
And if we have decided to use "a binary tree of X", then we'll use the binary tree lookup
and not consider also hashing the items. This type of thinking characterizes "data structure" 
design, and is taught in schools. 
The very term "data structure" presupposes that we take our data and then structure
it somehow. The metaphor is some sort of data origame, or moving data around for 
better access. There is no concept of access as being separate from the data.
This is assumed to be the price to pay if we want to write good algorithms.

On the other hand, there is a different approach to handling data -- the database approach.
If the data structure approach blends data with indexing, the database approach maximally separates
them. The data which we want to handle is first split (factored) into various tables. 
A table contains a number of records, and each record has some fields (also known as attributes).
We then create *indexes on attributes*, so that we can quickly locate
any record. Typically, any number of such indexes are allowed by a database management system.
Then, we write a query in some special query language, and a mechanism known as the query
planner decides which indexes to use to answer the query (so it's not just a multiply-nested
for-loop over all tables) and hopefully completes the query. But not *that*
quickly. It is an accepted fact that you pay for the generality of this approach with
correspondingly low runtime performance. When you really want performance, you use classical
methods to get it.

And yet, we know that all programming can be viewed as manipulation of in-memory databases.
Thus, the main motivation of *amc* is to give you the flexibility of crafting your own 
in-memory database with any number of tables and indexes, without having to implement
all the operations that implement creation, replacement, update, deletion and querying
of these records.

As a software architect and user of amc, you decide on the schema to use for your in-memory
database, and amc follows the constraints in your schema to implement cascading deletes, 
automatic group-bys, fast allocation of records using chained memory pools, and many other things.
The number and the variety of structures generated by amc is more similar to that of
a standard C++ library than an RDBMS.

Amc generates roughly 20 lines of code for each line of input. The code it generates 
is usually of the most error-prone and performance-critical kind, and you can account
for the generated code at the assembly instruction level. The generated code is documented,
readable and debuggable, and is provided in a standard target language: a conservative subset of C++ 
(circa C++ 1997), eschewing all modern constructs. 
This value proposition has immense consequences:
it means that a large and expensive software project can become a medium-sized software project,
and a medium-sized software project can become a small software project. Ultimately, 
this is what makes amc worth learning

When you co-evolve the schema together with your application, you can easily add and
remove indexes on the fly, and fine-tune them later.
At the same time, you can co-evolve amc itself with the project.
That's because amc isn't built and installed on the host system as a stand-alone, 
binary package. It is provided in source code form and versioned together with the
project it supports, forming a single eco-system.

