# SaveDrops

SaveDrops is a simple C++ console-based blood group information lookup program. After a user logs in, they can select a blood group and view the information stored in the matching text file. The program also calculates how long ago the date in the file's `Validation:` line was and displays an eligibility status.

## Features

- Login using a predefined username and password.
- Search records by blood group.
- Supports all 8 common blood groups:
  - A+, A-
  - B+, B-
  - AB+, AB-
  - O+, O-
- Reads blood group information from a matching `.txt` file.
- Calculates the time elapsed since the validation date.
- Displays `Eligible` when more than 120 days have passed; otherwise displays `Not Eligible`.

## Requirements

- A C++ compiler that supports C++11 or later (for example, GCC).
- The program's blood group text files in the same directory as the executable/current working directory.

## Project Files

The program expects one text file for each blood group:

```text
A+.txt
A-.txt
B+.txt
B-.txt
AB+.txt
AB-.txt
O+.txt
O-.txt
```

When a user searches for a blood group, SaveDrops opens the corresponding file. If the file does not exist, it displays `File not found!`.

## Text File Format

Each blood group file should contain the information to display. Include a line beginning with `Validation:` followed by a date in `day.month.year` format.

Example:

```text
Blood Group: O+
Validation: 15.07.2026
```

The program prints ordinary lines as they appear in the file. For a line containing `Validation`, it calculates the elapsed time from the date and prints the result with an eligibility status.

## How to Compile

Using GCC:

```bash
g++ savedrops.cpp -o savedrops
```

If your source file has a different name, replace `savedrops.cpp` with that filename.

## How to Run

On Windows:

```bash
savedrops.exe
```

On Linux or macOS:

```bash
./savedrops
```

Enter the login details when prompted, then choose an option from the main menu:

1. Search by Blood Group
2. Exit

Enter a supported blood group (for example, `O+`) when asked.

## Login

The current source code contains hard-coded login credentials:

- **Username:** `Tanfir`
- **Password:** `15624`

These are stored directly in the source code. Change them in `main()` if you want different credentials.

## Eligibility Calculation

The program calculates the absolute difference between the current date and the date read from the `Validation:` line.

- More than 120 days: `Eligible`
- 120 days or fewer: `Not Eligible`

The displayed duration is expressed in days, months and days, or years and months, depending on the elapsed time.

## Important Notes

- Keep the `.txt` files in the program's working directory so the program can find them.
- Use the date format `day.month.year` for validation dates.
- The login credentials are hard-coded and are not secure for a real-world application.
- This is a basic console application; it does not currently provide a database, user registration, or record-editing interface.
