# 🚆 Railway Reservation System (C)

## 📌 Description
Railway Reservation System in C with ticket booking, fare calculation, and file handling for persistent storage.

---

## ✨ Features
- 🎫 Ticket Booking System  
- 👤 Passenger Details (Name, Age, etc.)  
- 🚆 Route Selection (Hyderabad → Chennai / Bangalore / Delhi)  
- 🛏️ Coach Selection (Sleeper / AC)  
- 💰 Automatic Fare Calculation  
- 💳 Payment Simulation  
- 📂 File Handling (Data stored in `railway_records.txt`)  
- 🔍 View All Booked Tickets  

---

## 🛠️ Technologies Used
- C Programming Language  
- Structures  
- Arrays  
- File Handling  

---

## 📁 Project Files
- `Railway.c` → Main source code  
- `railway_records.txt` → Stores booking data  

---

## ▶️ How to Run

### 1. Compile the code
```bash
gcc Railway.c -o railway
### 2.Run the program
./railway

📸 Sample Output
1. Book 2. View 3. Exit
Choice: 1

Name: Neeraj
Age: 20

1. Hyderabad-Chennai
2. Hyderabad-Bangalore
3. Hyderabad-Delhi

Choose route: 1
Choose coach: 2
Seats: 2

Total Fare: 2400
Confirm payment (1-Yes, 0-No): 1

--- TICKET ---
PNR: 1001
Name: Neeraj
Route: Hyderabad -> Chennai
Seats: 2 | Total: 2400
Status: Success
🎯 Learning Outcomes
Understanding of structures in C

Implementation of file handling

Handling user input

Building real-world console applications

🚀 Future Improvements
❌ Ticket Cancellation

📊 Seat Availability System

🔐 Admin Login

🖥️ GUI Version
