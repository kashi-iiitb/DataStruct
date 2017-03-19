/* function pointer example */
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* atoi */

struct str_fn_ptr{
	void (*function_ptr[3])(int);
//	void (*function_ptr2)(int);
//	void (*function_ptr3)(int);
};

void function_one(int num) {

char* num_to_str[10] = {"ten","one","two","three","four","five","six","seven","eight","nine"};
  printf ("%s\n",num_to_str[num%10]);
}
void function_three(int num) {

char* num_to_str[10] = {"thirty","twenty one","twenty two","twenty three","twenty four",
			"twenty five","twenty six","twenty seven","twenty eight","twenty nine"};
  printf ("%s\n",num_to_str[num%10]);
}
void function_two(int num) {

char* num_to_str[10] = {"twenty","eleven","twelve","thirteen","fourteen",
			"fifteen","sixteen","seventeen","eighteen","nineteen"};
  printf ("%s\n",num_to_str[num%10]);
}


int main (int argc, char* argv[])
{
  int i=0;
  int num=0;
  int index=0;	

  /*void (*function_ptr[3])(int);
  function_ptr[0] = function_one;
  function_ptr[1] = function_two;
  function_ptr[2] = function_three;*/
  struct str_fn_ptr str_fn_ptr1;
  str_fn_ptr1.function_ptr[0] = function_one;
  str_fn_ptr1.function_ptr[1] = function_two;
  str_fn_ptr1.function_ptr[2] = function_three;

  for(i=1;i<argc;i++)
  {
	num =  atoi(argv[i]);
	if(num<1 || num>50)
	{
		printf("number is out of range!!\n");
		return;
	}
	index = num/10;
	//(*function_ptr[index])(num);
	(*str_fn_ptr1.function_ptr[index])(num);
  }

  return 0;
}
