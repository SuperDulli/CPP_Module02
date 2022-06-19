# CPP_Module02
Ad-hoc polymorphism, operator overloading and Orthodox Canonical class form

## Orthodox Canonical Form
required member functions:
- Default constructor
- Copy constructor
- Copy assignment constructor
- Destructor

## ex00: My First Class in Orthodox Canonical Form

### Fixed-point number

fixed-point numbers offer a valuable balance between performance, accuracy, range and precision.
That explains why fixed-point numbers are particularly applicable to computer graphics, sound processing or scientific programming, just to name a few.

private members:
- an integer to store the fixed-point number value
- a static constant integer to store the number of fractional bits. Its value will be always be the integer literal 8.

public members:
- a default constructor that initializes the fixed-point number value to 0
- a copy constuctor
- a copy assignment operator overload
- a destructor
- a member function `int getRawBits(void) const` that returns the raw value of the fixed-point value
- a member function `int setRawBits(int const raw)` that sets the raw value of the fixed-point number.

## ex01: Towards a more useful fixed-point number class

adds the following puplic member funtions to the `Fixed` class:
- a constructor that takes a constant integer as a parameter and converts it to the corresponding fixed-point value
- a constructor that takes a constant floating-point number as a parameter and converts it to the corresponding fixed-point value
- a member fuction `float toFloat(void) const` that converts the fixed-point value to a floating-point value
- a member fuction `int toInt(void) const` that converts the fixed-point value to an integer value.

adds an overload of the insertion (`<<`) operator that inserts a floating-point representation of the fixed-point number into the output stream object passed as a parameter

## ex02: Now we're talking

adds the following puplic member funtions to the `Fixed` class to overload the the following operators:
- the 6 comparison operators: `>, <, >=, <=, == and !=`
- the 4 arithmetic operators: `+, -, * and /`
- the 4 increment/decrement (pre-increment, post-increment, pre-decrement and post-decrement) operators that will increase or decrease the fixed-point value from the smallest representable ϵ such as 1 + ϵ > 1.

adds the following public overloaded member functions:
- a static member function min that takes as parameters two references on fixed-point numbers and returns a reference to the smallest one
- a static member function min that takes as parameters two references to constant fixed-point numbers and returns a reference to the smallest one
- a static member function max that takes as parameters two references on fixed-point numbers and returns a reference to the greatest one
- a static member function max that takes as parameters two references to constant fixed-point numbers and returns a reference to the greatest one.

## ex03: BSP

BSP = Binary space partitioning

test wheter a point is inside of a triangle or not.

### Point class

represents a point in 2D space.

private members:
- a Fixed const attribute x
- a Fixed const attribute y.

public members:
- a default constructor that initializes x and y to 0
- a constructor that takes as parameters two floating-point numbers and initializes x and y with those parameters
- a constructor that takes as parameters two fixed-point numbers and initializes x and y with those parameters
- a copy constructor
- a copy assignment operator overload
- a destructor
- a static member function that takes as parameters two Points to be converted into a vector, that is returned as a Point
- a static member function that takes as parameters two vetors (here Points) to be converted into the cross product, that is returned as a fixed-point number

### bsp-function

`bool bsp(Point const a, Point const b, Point const c, Point const point)`
- a, b, c: The verticces of the triangle
- point: point to check
- returns true if the point is inside the triangle. False otherwise. Thus, if the point is a vertex or on an edge, it will return flase.
