# Hostel Management

A console-based hostel management system written in C. Manages student records, room allocation and pricing, fees, food menu, complaints and feedback, using plain text files for storage.

## Features
- Student registration and records
- Room allocation, status and pricing
- Fee tracking
- Food menu management
- Complaints and feedback

## Build and run (Windows)
```bash
gcc hostelmange.c -o hostelmange
./hostelmange
```
The program uses `conio.h` and `windows.h`, so it targets Windows. Data files (`*.txt`) must sit in the same folder as the executable; `students.txt` contains sample data only.
