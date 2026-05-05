# Inverted-Search-using-Hashing-
 This project implements an Inverted Index using efficient hashing techniques to enable fast full-text search across multiple documents.  An inverted index maps words → list of documents in which they appear, making it a core data structure used in modern search engines.


An inverted index maps each word to the list of documents (files) in which it appears. 
To improve efficiency, hashing is used based on the first character of each word:

- Index 0–25  → words starting with 'a' to 'z'
- Index 26    → digits and special characters

Each hash bucket contains:
1. A main linked list storing unique words
2. A sub-linked list for each word storing:
   - File names
   - Word occurrence count in each file

Core Operations Supported:

1. Create:
   - Parses all input files
   - Tokenizes words
   - Builds the hash-based inverted index

2. Search:
   - Accepts a query word
   - Computes hash index
   - Retrieves files containing the word with frequency

3. Display:
   - Prints the complete hash table
   - Shows words and corresponding file details

4. Update:
   - Updates the database when new files are added
   - Avoids duplication of existing data

5. Save:
   - Stores the inverted index into a file (.txt)
   - Enables persistence for future use

This implementation uses:
- Hash Tables
- Linked Lists (Main + Sub list)
- File Handling
- String Processing


