#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

unsigned int reader_index =0; 
char str[];

double get_integer_at_index(int index)
{
	double result = 0;
	int i;
	for(i = index; isdigit(str[i]);i++)
	{
		result *= 10;
		result += (str[i]-'0');
	}
	reader_index = i;
	return result;
}

double get_product_of_operation(double left_operand, char operation, double right_operand)
{
	switch(operation){
		case '+':
			return left_operand + right_operand;
			break;
		case '-':
			return left_operand - right_operand;
			break;
		case '*':
			return left_operand * right_operand;
			break;
		case '/':
			if(right_operand == 0) exit(1);
			return left_operand / right_operand;
			break;
	}
	exit(1);
}

double get_result_in_parenthasies()
{
	if(str[reader_index]== '(') reader_index++;
	double left_operand = get_integer_at_index(reader_index);
	char operation;
	for(reader_index; str[reader_index] != '\0' && str[reader_index] != ')'; reader_index++)
	{
		if(isdigit(str[reader_index]))
		{
			left_operand = get_product_of_operation(left_operand,operation,get_integer_at_index(reader_index));
		}
		else if(str[reader_index] == '(')
			left_operand = get_product_of_operation(left_operand,operation,get_result_in_parenthasies());
		else 
		{
			operation = str[reader_index];
		}
	}
	return left_operand;
}


int main(void)
{
	scanf("%s",str);
	
	
	printf("%f%s",get_result_in_parenthasies(),"\n");
	return 0;
}