# Matrix Multiplication Program in C++

## Description
This C++ program reads two square matrices from binary files, performs matrix multiplication, and writes the result to a new binary file.

## Features
- Reads matrix data from `matrix1.bin` and `matrix2.bin`
- Checks if matrices have the same size before processing
- Performs matrix multiplication efficiently
- Writes the resulting matrix to `result.bin`
- Uses binary file I/O for efficient storage and retrieval

## File Structure
```
📂 MatrixMultiplication
 ├── matrix.cpp          # C++ source code
 ├── matrix1.bin         # First input matrix (binary file)
 ├── matrix2.bin         # Second input matrix (binary file)
 ├── result.bin          # Output matrix (binary file)
 ├── README.md           # Project documentation
 ├── .gitignore          # Ignore unnecessary files (e.g., .exe, .bin)
```

## How It Works
1. The program reads the matrix size (`n x n`) from `matrix1.bin` and `matrix2.bin`.
2. It verifies that both matrices have the same size.
3. It loads the matrix data from the binary files into 2D arrays.
4. It performs **matrix multiplication** using the standard algorithm:
   \[
   C[i][j] = \sum_{k=0}^{n-1} A[i][k] \times B[k][j]
   \]
5. It writes the result to `result.bin`.

## Compilation & Execution
#### *Using g++ (Linux/macOS)*
```sh
g++ -o matrix matrix.cpp
./matrix
```

#### *Using MinGW (Windows)*
```sh
g++ -o matrix.exe matrix.cpp
matrix.exe
```

## Binary File Format
The binary files (`matrix1.bin` and `matrix2.bin`) store:
1. An integer `n` (size of the square matrix)
2. The matrix data stored as `n * n` integers

Example representation:
```
[ n | row1 | row2 | row3 | ... ]
```

## Expected Output
The program will generate a `result.bin` file containing:
1. An integer `n` (size of the result matrix)
2. The resulting `n x n` matrix stored in binary format

## Error Handling
The program ensures:
- Matrices are of the same size before multiplying
- Matrix size does not exceed `100 x 100`
- Proper error messages are displayed if files fail to open or read

## Example Use Case
To test the program, generate `matrix1.bin` and `matrix2.bin` using a helper script or another program that writes integer values in binary format.

## Improvements & Future Work
- Support for non-square matrices
- Implement error handling for malformed binary files
- Add a script to generate sample binary matrices for testing

## License
This project is licensed under the MIT License.


