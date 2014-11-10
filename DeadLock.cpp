Item1, Item2;
mutex_t;
function1() {
	Occupy(Item1);
	Request(Item2);
	Release(Item1);
}

function2() {
	Occupy(Item2);
	Request(Item1);
	Release(Item2);
}
