# Semaphore: Understand the use of semaphore

Error checking is avoided to make the program simple to understand.

Compilation steps:
1) gcc semaphore.c -o s -lrt -lpthread

Difference between mutex and semaphore

Feature        | Mutex (mutually exclusive)| Semaphore
-------------- | ---------------------- | -----------------------
Ownership      | Yes (thread-specific)  | No (any thread can do sem_wait() and sem_post())
Count          | Always 1               | Can be > 1 (You can have many resources)
Use case       | Exclusive lock         | Resource pool / signaling

Analogy:

Semaphore:
Think of a parking lot with 10 spaces: Up to 10 cars can park at the same time. Number of free spaces is the semaphore value.
He can give the car key to the guard. Eventhough the owner locks the carspace, the guard can also unlock it.

Eg2:
You have 2 printers available, lot of employess want to print it.

Analogy:
Imagine a single bathroom in a house.
Only one person can use it at a time. The person who uses it (locks it) should only unlock it.
