/* tests various return types */

/*
 * XXX: The below all work even if the codegen assumes int size (32 bits)
 * all the time.
 *
 * XXX: add structs or floats or longs or whatever if and when they get
 * added to the language because these would actually break under
 * the "everything is an int lol" scheme
 */

/*
 * For gcc to compile this, the functions must be defined first-depended-upon
 * first. Maybe the standard requires that ?
 */

char letter_of_the_alphabet(int index, int uppercase)
{
	if (index < 0 || index >= 26) {
		printf("there is no %d-th letter of the latin alphabet!!!",
			index + 1);
		return ' ';
	}
	if (uppercase)
		return 'A' + index;
	else
		return 'a' + index;
}

char *weird_message()
{
	char *buf = malloc(0x100);
	sprintf(buf, "a scalalable web 2.0 salad has been prepared with .NET");
	return buf;
}

char **collection_of_repeated_letters()
{
	int i, j;
	char **coll;
	char *ptr;
	coll = malloc(1000);	/* XXX: 10 * sizeof(char *) */
				/* I'm using a very big number
				 * in case the test-against compiler
				 * is 64-bit (or X-bit...)
				 * Otherwise it would be
				 * 10 * 4 bytes = 40
				 */
	for (i = 0; i < 10; ++i) {
		coll[i] = malloc(11);
		/*
		 * XXX: coll[i][j] = ...
		 * proboably this is really just a matter of
		 * fixing the parser
		 */
		ptr = coll[i];
		for (j = 0; j < 10; ++j)
			ptr[j] = letter_of_the_alphabet(i, 1);
		ptr[j] = 0;	/* XXX: '\0' */
	}
	return coll;
}

int pow2(int e)
{
	int p = 1;
	if (e < 0) {
		printf("2^%d is not an int, not today, not tomorrow\n", e);
		return 0;
	}
	while (e--)
		p *= 2;
	return p;
}

int main(int argc, char **argv)
{
	char *msg;
	char let;
	int ilet;
	int num;
	char **coll;
	int i;

	msg = weird_message();
	puts(msg);

	let = letter_of_the_alphabet(0, 0);
	printf("%c\n", let);

	ilet = let = letter_of_the_alphabet(20, 1);
	printf("%c%c\n", let, ilet);

	num = pow2(16);
	printf("%d\n", num);

	coll = collection_of_repeated_letters();
	for (i = 0; i < 10; ++i)
		puts(coll[i]);
}

