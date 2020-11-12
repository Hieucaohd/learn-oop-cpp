#include "Beta.cpp"

int main(int argc, char const *argv[])
{
	Alpha A;
	Beta B;
	Alpha *Bptr = &A;
	// A.foo();
	// A.bar();
	// Bptr->foo();
	// Bptr->bar();
	Bptr = &B;
	Bptr->foo();
	Bptr->bar();
	return 0;
}