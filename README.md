# SuperMarket-Mangement-System
# SuperMarket Management System

This is a simple console-based SuperMarket Management System written in C++. It allows administrators to manage products and buyers to purchase products, with all data stored in a text file.

## Features
- **Administrator**
  - Add new products
  - Edit existing products
  - Delete products
- **Buyer**
  - View product list
  - Purchase products and generate receipt

## Files
- `supermarket.cpp`: Main source code for the application
- `database.txt`: Stores product information (product code, name, price, discount)
- `supermarket.exe`: Compiled executable (if present)

## How to Run
1. Compile the source code:
   ```sh
   g++ supermarket.cpp -o supermarket.exe
   ```
2. Run the program:
   ```sh
   supermarket.exe
   ```

## Usage
- On startup, choose Administrator or Buyer.
- Administrator login credentials:
  - Email: `sandeshparab2026@gmail.com`
  - Password: `Sohan@123`
- Follow on-screen instructions to manage products or make purchases.

## Data Format
Each product in `database.txt` is stored as:
```
<product_code> <product_name> <price> <discount>
```

## Notes
- All data is stored in plain text (`database.txt`).
- The program is for educational/demo purposes and does not use advanced security or error handling.

