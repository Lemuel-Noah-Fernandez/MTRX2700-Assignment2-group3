#ifndef PARSER_HEADER
#define PARSER_HEADER

void serial_parser(char *serial_in, char **function_names);
//DETERMINATING OPERATIONS
const char *convert_string_to_lower_case(char *serial_in);
int command_syntax_identifier(char *serial_in);

//OPERATION INIT
void run_operation(char *serial_in, char **function_names);
void say_operation(char *serial_in);

//MISC FUNCTIONS
char * operand_distiller(char *command);
void no_operand();
void incorrect_operation();

#endif