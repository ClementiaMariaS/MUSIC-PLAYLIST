# 🎵 Music Playlist Management System

A **Music Playlist Management System implemented in C using a Doubly Circular Linked List**.

This project provides a menu-driven interface for managing songs and navigating through a playlist. The circular nature of the linked list allows continuous movement between songs, meaning the user can move from the **last song back to the first song** and from the **first song back to the last song**.

---

## 📌 Project Overview

The system stores information about each song using a node containing:

* **Song ID**
* **Song Name**
* **Artist Name**
* **Next Pointer**
* **Previous Pointer**

The songs are organized using a **Doubly Circular Linked List**, where every node has two connections:

```text
        Previous                    Next
           ←                         →
    ┌─────────────┐            ┌─────────────┐
    │   Song 1    │ ⇄ Song 2 ⇄ │   Song 3    │
    └─────────────┘            └─────────────┘
          ↑                            ↓
          └────────────────────────────┘
```

Because the list is circular:

```text
Song 1 → Song 2 → Song 3 → Song 1 → ...
```

and

```text
Song 1 ← Song 2 ← Song 3 ← Song 1 ← ...
```

---

## 🧠 What is a Doubly Circular Linked List?

A **Doubly Circular Linked List** is a linked list in which every node contains:

* A pointer to the **next node**
* A pointer to the **previous node**

Unlike a normal doubly linked list, the last node does not point to `NULL`. Instead:

```text
Last Node → First Node
First Node ← Last Node
```

Therefore, the list forms a continuous circle.

### Node Structure

```c
struct Song
{
    int id;
    char name[50];
    char artist[50];

    struct Song *next;
    struct Song *prev;
};
```

---

## ✨ Advantages

* Supports **forward and backward traversal**.
* Allows **continuous circular navigation**.
* No `NULL` pointer at the beginning or end of the playlist.
* Efficient insertion and deletion when the required node is known.
* Suitable for applications where users repeatedly move between elements.
* Makes both **Next** and **Previous** operations straightforward.

---

## 🌍 Applications

Doubly Circular Linked Lists are useful in systems that require continuous forward and backward navigation.

Examples include:

* 🎵 Music playlist systems
* 🖼️ Image/photo viewers
* 🎮 Game turn management
* 📑 Document/page navigation
* 🔄 CPU scheduling systems
* 🎞️ Media players
* 📚 Circular menus and navigation systems

---

## ⚙️ Features

The application provides the following operations:

| Option | Operation                           |
| ------ | ----------------------------------- |
| 1      | Add Song at Beginning               |
| 2      | Add Song at End                     |
| 3      | Delete Song using Song ID           |
| 4      | Search Song using Song ID           |
| 5      | Display Songs in Forward Direction  |
| 6      | Display Songs in Backward Direction |
| 7      | Move to Next Song                   |
| 8      | Move to Previous Song               |
| 9      | Display Total Number of Songs       |
| 10     | Exit                                |

---

## 🔄 Circular Navigation

The main advantage demonstrated by this project is circular navigation.

Suppose the playlist contains:

```text
┌─────────┐     ┌─────────┐     ┌─────────┐
│ Song 1  │ ⇄  │ Song 2  │ ⇄  │ Song 3  │
└─────────┘     └─────────┘     └─────────┘
      ↑                              ↓
      └──────────────────────────────┘
```

### Next Song

If the current song is `Song 3`:

```text
Song 1 → Song 2 → Song 3 → Song 1
                           ↑
                     wraps around
```

### Previous Song

If the current song is `Song 1`:

```text
Song 1 ← Song 2 ← Song 3
  ↑                    │
  └────────────────────┘
```

Thus, there is no stopping point at either end of the playlist.

---

## 🛠️ Technologies Used

* **Language:** C
* **Data Structure:** Doubly Circular Linked List
* **Memory Management:** Dynamic Memory Allocation using `malloc()` and `free()`
* **Compiler:** Any standard C compiler

### Header Files

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
```

---

## ▶️ How to Run

### 1. Clone the Repository

```bash
git clone <your-repository-url>
```

### 2. Navigate to the Project Directory

```bash
cd Music-Playlist-Management-System
```

### 3. Compile the Program

Using GCC:

```bash
gcc music_playlist.c -o music_playlist
```

### 4. Run the Program

**Windows:**

```bash
music_playlist.exe
```

**Linux / macOS:**

```bash
./music_playlist
```

---

## 🖥️ Program Menu

When the program starts, the following menu is displayed:

```text
===== MUSIC PLAYLIST MENU =====
1. Add Song at Beginning
2. Add Song at End
3. Delete Song
4. Search Song
5. Display Forward
6. Display Backward
7. Next Song
8. Previous Song
9. Total Songs
10. Exit

Enter Choice:
```

---

## 📋 Example Execution

### Adding Songs

```text
Enter Choice: 2

Enter Song ID: 101
Enter Song Name: Believer
Enter Artist Name: Imagine Dragons

Song added at end.
```

Another song can be added:

```text
Enter Choice: 2

Enter Song ID: 102
Enter Song Name: Perfect
Enter Artist Name: Ed Sheeran

Song added at end.
```

### Display Forward

```text
Playlist (Forward)

101 | Believer | Imagine Dragons
102 | Perfect | Ed Sheeran
```

### Display Backward

```text
Playlist (Backward)

102 | Perfect | Ed Sheeran
101 | Believer | Imagine Dragons
```

### Circular Navigation

If the current song is `Perfect`:

```text
Enter Choice: 7

Current Song:
101 | Believer | Imagine Dragons
```

The **Next Song** operation moves from the last song back to the first song.

Similarly, using **Previous Song** from the first song moves back to the last song.

---

## 🧩 Program Structure

The program is divided into separate functions for each operation:

```text
main()
 │
 ├── createNode()
 │
 ├── addBeginning()
 │
 ├── addEnd()
 │
 ├── deleteSong()
 │
 ├── searchSong()
 │
 ├── displayForward()
 │
 ├── displayBackward()
 │
 ├── nextSong()
 │
 ├── previousSong()
 │
 └── totalSongs()
```

This modular structure makes the program easier to understand, maintain, and extend.

---

## 💾 Dynamic Memory Management

Each song node is dynamically allocated using:

```c
malloc(sizeof(struct Song))
```

When a song is deleted, its allocated memory is released using:

```c
free(temp);
```

This prevents unnecessary memory usage during program execution.

---

## 🎯 Learning Outcomes

Through this project, the following concepts are demonstrated:

* Structures in C
* Pointers
* Dynamic memory allocation
* `malloc()` and `free()`
* Doubly linked lists
* Circular linked lists
* Insertion and deletion
* Searching
* Forward and backward traversal
* Menu-driven programming
* Memory management
* Circular navigation logic

---

## 📸 Program Execution

Screenshots of the program execution can be added below to demonstrate:

* Adding songs
* Searching for a song
* Forward traversal
* Backward traversal
* Next song navigation
* Previous song navigation
* Deleting a song
* Displaying total songs

### Sample Screenshot

> Add your program execution screenshot here.

---

## 👩‍💻 Project

**Music Playlist Management System**

Developed as a C Data Structures project demonstrating the practical implementation of a **Doubly Circular Linked List**.

---

### 📄 License

This project is intended for **educational purposes**.
