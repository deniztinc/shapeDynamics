# shapeDynamics

This project is a C++ program that simulates the management of various geometric shapes. The shapes are dynamically created, stored, and manipulated using linked lists. The program generates random shapes (such as circles, rectangles, and triangles), calculates their area and perimeter, and prints out relevant information about each shape.

Features:
* Shape Generation: Randomly generates geometric shapes like circles, rectangles, and triangles.
* Memory Management: Dynamically allocates and deallocates memory for each shape using smart pointers.
* Linked List Management: Stores shapes in a forward list, and allows insertion, removal, and sorting operations.
* Shape Operations: Computes area and perimeter for each shape and outputs the results.
* Shape Sorting: Groups and sorts shapes based on their perimeter or area.
  
Shapes Supported:
* Circle: Randomly generated radius with area and perimeter calculations.
* Rectangle: Randomly generated length and width with area and perimeter calculations.
* Triangle: Randomly generated side lengths with area and perimeter calculations.


Shape Class Hierarchy:

Shape (base class) provides common functionality for all shapes, including area and perimeter calculation.
Derived classes such as Circle, Rectangle, and Triangle implement specific shape details and calculations.

Shape Management:
* Shapes are stored in a linked list (forward_list).
* Shapes can be inserted, removed, and grouped by type or perimeter/area.
* Random Shape Generation:

Shapes are randomly created with random dimensions such as radius for a circle, or side lengths for a triangle.

Shape Operations:
* Each shape has methods to calculate its area and perimeter.
* Shapes are displayed with their type and calculated values.

Example Output:

Generated Shapes:
------------------
Shape: CIRCLE, Radius: 9.5, Area: 282.74, Perimeter: 59.69
Shape: RECTANGLE, Length: 10, Width: 5, Area: 50.00, Perimeter: 30.00
Shape: TRIANGLE, Side A: 3, Side B: 4, Side C: 5, Area: 6.00, Perimeter: 12.00

Shape List Sorted by Perimeter:
-------------------------------
Shape: TRIANGLE, Side A: 3, Side B: 4, Side C: 5, Area: 6.00, Perimeter: 12.00
Shape: RECTANGLE, Length: 10, Width: 5, Area: 50.00, Perimeter: 30.00
Shape: CIRCLE, Radius: 9.5, Area: 282.74, Perimeter: 59.69
