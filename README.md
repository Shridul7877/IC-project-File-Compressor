# IC-Project File Compressor using Huffman Coding

## Project Overview

This project implements **File Compression and Decompression using the Huffman Coding Algorithm** in C.

Huffman Coding is a **lossless data compression algorithm** that reduces file size by assigning shorter binary codes to frequently occurring characters and longer codes to less frequent characters.

The project is divided into two major parts:
- **Compression**
- **Decompression**
The program reads an input file, compresses it into a binary encoded format, and later reconstructs the original file using decompression

## Huffman Coding Algorithm
Huffman Coding works in the following steps:

1. Read the input file  
2. Count frequency of each character  
3. Build Huffman Tree using a priority queue (min-heap concept)  
4. Generate unique binary codes for each character  
5. Encode the file using generated codes  
6. Store compressed data along with tree structure  
7. Rebuild the tree during decompression  
8. Decode the compressed file back to original content  

This ensures:
- Reduced storage size  
- No data loss  
- Efficient reconstruction

## Project Structure

## Compression Files
These files are used during compression:

| File | Purpose |
| `compression.c` | Main compression driver |
| `encoder.c` | Encodes file data using Huffman codes |
| `tree_builder.c` | Builds Huffman Tree |
| `frequency_io.c` | Handles character frequency calculation and file I/O |

## Decompression Files
These files are used during decompression:

**| File | Purpose |**
| `decompression.c` | Main decompression driver |
| `decode.c` | Decodes compressed binary data |
| `tree_rebuild.c` | Reconstructs Huffman Tree from stored data |
| `node.c` | Defines Huffman Tree node structure and supports tree operations |

## Compilation Instructions

### For Compression
Use the following GCC command:

```bash
gcc compression.c encoder.c tree_builder.c frequency_io.c -o compress
```

This creates the executable:
compress.exe

### For Decompression
Use the following GCC command:

```bash
gcc decompression.c decode.c tree_rebuild.c node.c -o decompress
```
This creates the executable:
decompress.exe

## Execution Instructions

### Run Compression

```bash
./compress
```
The program will:
- Read the input file  
- Generate frequency table  
- Build Huffman Tree  
- Compress the file  
- Save compressed output  

### Run Decompression
```bash
./decompress
```
The program will:
- Read compressed file  
- Rebuild Huffman Tree  
- Decode binary data  
- Restore original file

## Team Member Contributions

### Anshul – Compression Module & Frequency I/O
- Implemented `compression.c`
- Managed overall compression workflow
- Developed file reading logic
- Implemented `frequency_io.c`
- Managed character frequency calculations and file handling

### Hamza Khan – Encoding Module
- Implemented `encoder.c`
- Generated Huffman binary codes
- Encoded original file content using generated codes

### Anand Yadav – Tree Construction Module
- Implemented `tree_builder.c`
- Built Huffman Tree using character frequencies
- Managed tree generation logic

### Mithlesh Garhwal – Decompression Module
- Implemented `decompression.c`
- Controlled decompression workflow
- Managed restoration of original file

### Shridul Shrivastav – Decoding & Node Management
- Implemented `decode.c`
- Implemented `node.c`
- Managed node structure creation
- Supported tree traversal and decoding operations

### Vivek Meena – Tree Reconstruction Module
- Implemented `tree_rebuild.c`
- Reconstructed Huffman Tree from stored compressed data
- Managed restoration logic for decompression support

## Future Improvements
Possible future enhancements include:
- GUI-based compression tool  
- Support for larger files  
- Support for multiple file formats  
- Improved compression ratio optimization  
- Better error handling  
- File metadata preservation

## Conclusion
This project demonstrates the practical implementation of the **Huffman Coding Algorithm** for efficient file compression and decompression.
It provides:
- Efficient storage optimization  
- Lossless compression  
- Real-world application of Data Structures and Algorithms

This project helped in understanding:
- Trees  
- Priority Queues  
- Greedy Algorithms  
- File Handling in C  
- Memory efficient programming

## Developed For
Introduction To Computer Science Engineering Project
Implementation Language: C(only)
Algorithm Used: Huffman Coding
