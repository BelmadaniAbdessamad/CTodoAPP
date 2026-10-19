# Todo App in C

A simple command-line Todo application written in C. This project helps practice fundamental C programming concepts, including structures, pointers, and user input.

## Features

- **Add todos:** Create new tasks.
- **List todos:** Display tasks in a formatted table.
- **Mark as done:** Update a task's status.
- **Remove todos:** Delete tasks from the list.



## Getting Started

### Prerequisites

You need a C compiler, such as GCC, installed on your system.

### Compilation

Compile the source files using GCC:

```bash
gcc main.c todoapp.c -o todoapp
```

Adjust the filenames if your project uses a different structure.

### Run the application

On Windows:

```bash
todoapp.exe
```

On Linux or macOS:

```bash
./todoapp
```

## Usage

Once the application starts, use the menu to manage your tasks:

- `A` — Add a todo
- `D` — Mark a todo as done
- `R` — Remove a todo
- `Q` — Quit the application

## Project Goals

This project is a learning exercise focused on:

- Structures (`struct`)
- Pointers 
- Functions and modular code organization
- Arrays and string manipulation

## Limitations

Todos are stored in memory and are lost when the application closes. Persistent storage is not implemented yet.

## Version

**1.0.0**

## Author

Abdessamad Belmadani
