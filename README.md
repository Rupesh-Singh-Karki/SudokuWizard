Project Title: Sudoku Wizard

Description:

This project is a C++ application designed to solve 9x9 Sudoku puzzles efficiently using a backtracking algorithm. The program is structured to perform the following functions:

1.Input Handling: The user is prompted to enter a 9x9 Sudoku grid where empty cells are represented by zeros. The input grid is read and stored in a 2D vector.

2.Validation and Constraints: The solver employs a function to check if placing a number in a specific cell adheres to Sudoku rules. It ensures that the number does not violate
the constraints of uniqueness within its row, column, or 3x3 sub-grid.

3.Backtracking Algorithm: The core of the solver is the backtracking approach, which recursively tries to fill each empty cell with a number from 1 to 9. If placing a number leads
to a valid solution, the process continues. If a number does not lead to a solution, the algorithm backtracks by resetting the cell and trying the next number.

4.Output: Once the board is completely and correctly filled, the solution is displayed in a readable format, showing the solved Sudoku puzzle.

This project showcases the ability to implement classic algorithmic techniques for solving combinatorial problems, ensuring that the Sudoku puzzle is solved correctly and efficiently.
