// RUN: clang -warn-dead-stores -warn-uninit-values -verify %s

void f1()
{
	int i;
	
	int j = i ? : 1; // expected-warning{{use of uninitialized variable}}
}

void *f2(int *i)
{
	return i ? : 0;
}

void *f3(int *i)
{
	int a;
	
	return &a ? : i;
}

void f4()
{
	char c[1 ? : 2];
}

