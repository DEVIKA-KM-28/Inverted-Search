📌 Overview
This project is an implementation of an **Inverted Search Engine** using **Hash Tables** and **Linked Lists** in C.  
It demonstrates how search engines efficiently retrieve information by creating an **inverted index**, mapping words to the files in which they appear along with their frequency.

⚙️ Features
- ✅ 27-bucket Hash Table (a–z + special characters) for efficient indexing  
- ✅ Nested Linked List to store word occurrences and file details  
- ✅ Fast word search across multiple files  
- ✅ Database creation from input files  
- ✅ Display indexed database  
- ✅ Save database to a backup file  
- ✅ Update database from backup file  
- ✅ File validation and duplicate file detection  
- ✅ Dynamic memory management in C  

🛠️ Technologies Used
  - Hash Tables  
  - Linked Lists  
  - File Handling  
  - Dynamic Memory Allocation  

📂 Project Structure
├── main.c
├── hash.c
├── list.c
├── file.c
├── *.h
├── input_files/
└── README.md

 ▶️ How to Run
1.Compile the program
gcc *.c 

2. Run the program
./a.out file1.txt file2.txt file3.txt 

💡 How It Works
Reads multiple text files
Breaks content into words
Stores each word in a hash table bucket
Maintains file name and word frequency using linked lists
Enables fast retrieval using the inverted index

📸 Sample Operations
Create Database
Search Word
Display Database
Save / Update Database

🎯 Learning Outcomes
Strong understanding of Data Structures (Hash Tables & Linked Lists)
Practical knowledge of File Handling in C
Experience with efficient searching techniques
Improved skills in memory management and modular programming
