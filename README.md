# Accounting-Program-for-a-Café

This is the implementation of a simple accounting program for a café. The program is given a sequence of entries, one per sold item. Each entry contains a timestamp, receipt number, sold item title and its cost. The task is to compute for each date (year, month and day) total amount of money earned, as well as number of unique customers (number of unique receipts).

The solution provides an implementation of HashMap and use it to solve the problem. 

Input

First line of the input contains a single number N (0<N≤50000) — the number of entries in the input. Following N lines each describe one entry. Each entry consists of 5 fields separated by spaces:

1) date (YYYY-MM-DD format),

2) time (HH:MM:SS format),

3) receipt ID (#<ID> format, where ID can contain digits, letters and dash (-)),

4) cost ($<number> format) and

5) item title (no specified format).


Output

The program should output K lines, where K is the number of different dates in the input. For each date the program should output a line with date (YYYY-MM-DD), total cost ($number) and number of unique receipt IDs (number).
