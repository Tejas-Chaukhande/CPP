# Device Driver / Embedded Interview Preparation Notes

# 1. C Programming

## 1.1 Compilation Stages

Source → Preprocessor → Compiler → Assembler → Linker → Executable

```text
file.c
 ↓
Preprocessor (.i)
 ↓
Compiler (.s)
 ↓
Assembler (.o)
 ↓
Linker
 ↓
a.out / ELF / BIN
```

---

## 1.2 Pointers

### 3D Array Stored in Pointer

```c
#include <stdio.h>

int main()
{
int arr[2][3][4]={
{
{1,2,3,4},
{5,6,7,8},
{9,10,11,12}
},
{
{13,14,15,16},
{17,18,19,20},
{21,22,23,24}
}
};

int (*ptr)[3][4];

ptr=arr;

printf("%d\n",ptr[0][0][0]);
printf("%d\n",ptr[1][2][3]);

return 0;
}
```

---

## 1.3 Dangling Pointer

Pointer pointing to freed/invalid memory.

```c
int *ptr=malloc(sizeof(int));
free(ptr);

/* dangling pointer */
```

---

## 1.4 Wild Pointer

Declared but not initialized.

```c
int *ptr;

*ptr=10;
```

Contains garbage address.

---

## 1.5 Enum

Enum is user-defined datatype used to assign names to integral constants.

```c
enum state{
ON,
OFF
};
```

---

## 1.6 Macro

Preprocessor replacement before compilation.

```c
#define MAX 100
```

---

## 1.7 Memory Leak

Allocated memory not released.

```c
int *ptr=malloc(100);

/* forgot free(ptr) */
```

---

## 1.8 Structure Padding

Extra bytes inserted for alignment.

Advantages:

* Faster access
* CPU efficiency
* Proper alignment

---

## 1.9 Structure Packing

Remove compiler-added padding.

```c
#pragma pack(1)

struct Test{
char a;
int b;
};
```

or

```c
struct __attribute__((packed))
{
char a;
int b;
};
```

Used in:

* Device Drivers
* Hardware Registers
* Network Protocols
* File Formats

---

## 1.10 Reverse Number

Input:
1235

Output:
5321

```c
while(num){

rem=num%10;

rev=rev*10+rem;

num/=10;

}
```

---

## 1.11 Reverse Bits

Input:
40

```c
int rev_bit(int num,int size)
{
int rev=0;

for(int i=0;i<size;i++)
{
rev=(rev<<1)|(num&1);

num>>=1;
}

return rev;
}
```

---

## 1.12 Reverse Hex

Input:
0x1234

Output:
0x4321

```c
int rev=
((num&0xf000)>>12)|
((num&0x0f00)>>4)|
((num&0x00f0)<<4)|
((num&0x000f)<<12);
```

---

## 1.13 Toggle Bit

```c
num ^= (1<<pos);
```

---

## 1.14 Print First Unique Character

Practice problem.

---

## 1.15 Swap Adjacent Bits

```c
unsigned int swap_adjacent_bits(unsigned int num)
{
unsigned int even;

unsigned int odd;

even=num&0xAAAAAAAA;

odd=num&0x55555555;

even>>=1;

odd<<=1;

return even|odd;
}
```

---

## 1.16 Power of 2

```c
num>0 &&
(num&(num-1))==0
```

---

## 1.17 Power of 4

```c
(num>0)&&
((num&(num-1))==0)&&
((num-1)%3==0)
```

---

# 2. Complexity

## Time Complexity

| Complexity | Meaning      |
| ---------- | ------------ |
| O(1)       | Constant     |
| O(log n)   | Logarithmic  |
| O(n)       | Linear       |
| O(n log n) | Linearithmic |
| O(n²)      | Quadratic    |

Examples:

| Algorithm     | Time     |
| ------------- | -------- |
| Linear Search | O(n)     |
| Binary Search | O(log n) |
| Merge Sort    | O(nlogn) |
| Bubble Sort   | O(n²)    |

---

## Space Complexity

Measures extra memory consumed.

Includes:

* Variables
* Heap
* Stack
* Temporary arrays

---

# 3. Linux / Debug

## Segmentation Fault

Occurs due to:

* Invalid memory
* NULL access
* Buffer overflow

Debug:

```bash
gdb
bt
core
```

---

## Core Dump

Stores process memory during crash.

Enable:

```bash
ulimit -c unlimited
```

---

## GNU Debugger

```bash
gdb ./a.out
```

Commands:

```bash
break
run
next
step
print
bt
```

---

## T32 Debugging

* Breakpoints
* Memory View
* Registers
* Call Stack
* Trace

---

# 4. Embedded Concepts

## UART vs Temperature Sensor

### UART → Interrupt

Reason:

* Asynchronous
* Prevent data loss

### Sensor → Polling

Reason:

* Predictable updates

Principle:

Interrupt → Asynchronous

Polling → Periodic

---

## Interrupt

Signal that stops CPU execution and executes ISR.

Types:

* Hardware
* Software

---

## ISR vs Function

Function:

* Called explicitly

ISR:

* Triggered automatically

---

## Interrupt Flow

```text
Interrupt
↓

Save Context

↓

Execute ISR

↓

Restore Context

↓

Resume
```

---

## 8051 vs NVIC

8051:

* Fixed priorities

NVIC:

* Nested interrupts
* Dynamic priorities

---

# 5. Embedded Communication

Protocols:

* UART
* SPI
* I2C

Know:

* Speed
* Master/slave
* Full duplex

---

# 6. Processor Concepts

## ARM vs AI Processor

ARM:

* General purpose

AI Accelerator:

* Matrix compute optimized

---

## CISC vs RISC

CISC:

* Complex instructions

RISC:

* Simple instructions

---

## AI Accelerator

Purpose:

* Accelerate ML workloads

---

# 7. Memory

## Global Variables

Stored in:

```text
.data
.bss
```

Created during compile stage.

Allocated during loading.

---

# 8. JTAG

Hardware debug interface.

Uses:

* Flashing
* Debugging
* Breakpoints

---

# 9. Data Structures

## Queue (Linked List)

Practice:

* enqueue()
* dequeue()

Fix insertion bug in your implementation.

---

# 10. Function Call Flow

```text
main()

↓

save return address

↓

jump

↓

execute

↓

return

↓

resume
```
