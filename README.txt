Part 1: Combinatorial Puzzle Verifier
Consider combinatorial puzzles, like those presented in lecture during lecture two. For example, one such
puzzle is POT + PAN = BIB. In these puzzles, you must assign each letter a distinct digit, such that if we
substitute the digits in place of the letters, the resulting mathematical equation is true.
In our continuing example, if we set P=2, O=3, T=1, A=7, N=4, B=5, and I=0, we get 231 + 274 = 505.
In the file verifySol.cpp, you will find an incomplete implementation for:
[[nodiscard]] bool verifySolution(const std::string& addend1, const
std::string& addend2,
const std::string& result,
const std::unordered_map<char, unsigned>& mapping);
The first part of your assignment is to finish implementing this.
addend1 will contain the first addend. In the above example this would be the string “POT”.
addend2 will contain the second addend. In the above example this would be the string “PAN”.
result will contain the sum. In the above example this would be the string “BIB”.
mapping will contain a mapping of letters (‘A’-’Z’) to digits (0-9). Your job is to have the verifySolution
return true if the provided mapping results in a mathematically correct equation. For example, the
mapping given above (P=2, O=3, T=1, A=7, N=4, B=5, I=0) would result in a true result from this function,
since it gives the equation 231 + 274 = 505. If the provided mapping does not result in a mathematically
valid equation you should return false.
To find out what the proposed mapping (mapping parameter) has for addend1[0] (the first character in
std::string addend1), you can use the member function at() of the unordered_map class: that is,
mapping.at(addend1[0]).
You are not required to check that the digits assigned are distinct, merely that it satisfies the equation.
Note that addend1, addend2, and result might not be equal in size. Furthermore, you may assume that
all characters appearing in any of the strings addend1, addend2, and/or result will appear in the mapping;
you do not need to check for that. Furthermore, none of the strings will be empty and each, with the
mapping, will evaluate to a number that is at most std::numeric_limits<unsigned int>::max().
There are many ways to solve this problem. If you are having trouble finding any way to write a solution to
it, please see a member of course staff.
Do not change the function prototype (function name, parameter types/names, or return type) since our
tests will depend on it!
Part 2: Linked-list based Stack
Fill in the functions in the file LinkedListStack.hpp. The reading in the assigned Zybook covers
linked-list based Stacks. The linked list must be of your own creation. You are prohibited from using any
standard library container classes for this part of the project. Using a standard library container, including
std::vector or std::stack, in implementing your LinkedListStack will be treated as a serious academic
integrity violation.
Do not change any of the following function prototypes (function name, parameter types/names, or return
type) since our tests will depend on them!
template <typename T>
class LinkedListLStack;
Defines the class LinkedListStack with one template parameter T. This template parameter will
only be tested with integer types (char, short, int, long, long long), unsigned integer types, and
std::string. However, there is nothing in the project that will limit you to those types if you so
desire.
LinkedListStack()
This is the constructor for the class. You should initialize any variables you add to the class here.
LinkedListStack(const LinkedListStack& st)
This is the copy constructor for the class. This must be a deep copy. Meaning all of the data from
one stack is copied to the other. If I make a copy of a stack and then modify the copy’s data the
original stack should not be affected. For example,
LinkedListStack<int> myStack;
myStack.push(5);
LinkedListStack<int> newStack = myStack;
myStack should not be affected by any following changes made to newStack.
LinkedListStack& operator=(const LinkedListStack& st)
This is the assignment operator for the LinkedListStack class. This must also be a deep copy and
will be called when an existing LinkedListStack object is assigned to a new one. Note, this is
subtly, but distinctly, different from when a new LinkedListStack is constructed using an
existing one, in which case the copy constructor above would be called.
LinkedListStack<int> myStack;
LinkedListStack<int> newStack;
newStack = myStack;
If the difference between the copy constructor and assignment operator is confusing: (1) I don’t
blame you. It is. (2) Consider carefully reviewing the material on cppreference.com (hyperlinked
at the beginning of each paragraph) and optionally coming to the lab hours to discuss with a tutor
or teaching assistant. You will be implementing a lot of these this quarter so it’s important to do
this early on!
LinkedListLStack(LinkedListStack&&) = delete
This is the class’s move constructor. You do not need to implement this (which is why it is marked
as deleted). It is included in the class definition purely to ensure that the behavior is defined.
LinkedListLStack& operator=(LinkedListStack&&) = delete
This is the class’s move assignment operator. You do not need to implement this (which is why it
is marked as deleted). It is included in the class definition purely to ensure that the behavior is
defined.
~LinkedListStack()
This is the class destructor. You are responsible for freeing any allocated memory here. You will
most likely be allocating memory to store the nodes within the LLStack implementation. Since
these allocations need to be dynamic, as we don’t know how large the stack will be, they should
be freed here in the destructor. It’s your job to come up with a traversal algorithm to accomplish
this. Note, if you elect to use shared pointers or unique pointers the compiler will generate code to
deallocate the memory for you if certain conditions are met. You should only use these
features of the standard library if you already understand them or are willing to put in extra
effort. In most industry settings features like these will be used as opposed to explicitly
implemented destructors.
[[nodiscard]] size_t size() const noexcept
This function returns the number of objects in the stack. It returns the count as a size_t. It is
marked const (also known as a constant member function) because it should not modify any
member variables that you’ve added to the class or call any function functions that are not
marked const as well. The advantage of marking this function as const is that it can be called on
constant LinkedListStack instances. It also allows the compiler to make additional
optimizations since it can assume the object this function is called on is not changed. This is a
fairly good StackOverflow answer that goes into additional detail.
[[nodiscard]] bool empty() const noexcept
Exactly as it sounds. Returns true if the LinkedListStack is empty, false if not.
[[nodiscard]] T& top()
Returns a reference to the element at the top of the stack. This is also known as the element that
was most recently pushed to the stack. Since this function returns a modifiable reference to an
object in the stack, it can be changed. Thus, this function is not marked const like the previous
two. If references are a little confusing, I encourage you to look at the linked material on
cppreference.com or attend the lab hours for additional help. You will be using a lot of them this
quarter.
If the stack is empty, this function should throw a StackEmptyException.
[[nodiscard]] const T& top() const
Returns a constant reference to the element on the top of the stack. Since this returns a
non-modifiable reference this function is marked const. Note the difference between this function
and the previous. Let’s say I had constant LinkedListStack and wanted to get the top element.
Without this function the following wouldn’t be possible (if it’s not clear why, post on EdStem or
come visit during lab hours!):
LinkedListStack<int> myStack;
myStack.push(5);
const LinkedListStack<int>& newConstStack = myStack;
EXPECT_EQ( newConstStack.top(), 5 );
If the stack is empty, this function should throw a StackEmptyException.
void push(const T& elem) noexcept
Push a parameter elem to the stack. This function should never throw an exception, thus it is
marked noexcept. However, it will modify member data of your stack class, so it is not marked
const.
void pop()
Just like it sounds. Pops the top element from the stack. This function does modify the data in the
underlying class so it is not marked const.
If the stack is empty, this function should throw a StackEmptyException.
Part 3: A simple calculator
In file postfixCalc.cpp, there is a stubbed function:
[[nodiscard]] unsigned postfixCalculator(const std::vector<std::string>&
entries)
You are to finish writing the function so that it calculates appropriately.
Every std::string in the vector “entries” is in one of two categories:
● A std::string that evaluations to an unsigned integer, such as “2” or “5000”
● A std::string that is one of four mathematical operators: “+” “-” “*” “/”
You are to evaluate the expression, described in post-fix. This is a series of individual entries, as
described above. Read them first to last. When you see one that is a number, push that ƒnumber to the
stack. When you see one that is an operator, apply that operator to the top two elements of the stack; if
the operator is not associative, the top of the stack is the second parameter to the operator.
When the last entry has been evaluated, there should be a single element of your stack. If this is the
case, that element is your answer; return it. Otherwise, the function cannot be evaluated. In this case,
throw a CannotEvaluateException. You should throw this exception whenever the state of the postfix
calculator is not evaluable. For example, if you receive an empty vector as input, you would throw this
exception.
You will need to use your LinkedListStack from the previous part as you solve this. You may not use any
standard library containers to solve this, other than referencing the std::vector provided as an
argument.
To clarify how a post-fix calculator works, let’s look at two examples. These are tests one through three
on the required list for this project (see file stacktests.cpp in the tst folder).
The first test case has the input “5”, “3”, “*” -- our procedure is to push 5 to our (initially empty) stack, then
push 3, then pop the two most recent pushes, multiply the two, and push the result of that. We are now
done with the input vector, and have one element (15) on our stack. This is our return value.
The second test case has the input “5”, “3”, “2”, “-”, “*”. The third has this input except the last entry. In
both, we push the three numbers before encountering the subtraction sign. Because subtraction is not
associative, we must interpret this as “3-2” and not as “2-3.” We compute this as one and push it to the
stack. In the third example, we’re out of input, but have two elements on the stack, and thus must throw
an exception. In the second, though, the multiplication sign remains, allowing us to reduce the stack to
one element by multiplying 5 and 1, pushing the result, seeing we’re out of input, and returning the sole
element of the stack.
You may assume that any entry that is not an operator will fit within a standard unsigned integer. You
may assume that the result of any operation in any test case we provide will be an unsigned integer. You
do not need to check for this in code -- none of the test cases we use in grading will break this promise.
For example, there is not a test case with {“8675309”, “1729”, “*”} as the input vector, as the result of that
multiplication exceeds the maximum value of a 32-bit unsigned integer.
You do not need to implement your own multiplication. If you detect that an entry in the input vector is the
string “*”, you may use the built-in unsigned multiplication in C++. The same goes for the other three
operators.
You will not be tested on divide by zero. Feel free to handle that however you wish, since the test cases
will not cover it