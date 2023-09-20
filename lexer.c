#include "minishell.h"
//  Shunting yard algorithm

echo "$USER | " $$'$PATH' > file| cat  << limiter > file | cat < file >> out_file

t_token *_lexer(char *input)
{
	t_token *head;
	t_token *current;
    int     i;

    i = 0;
    while(input[i]) {
        if (input[i] == ' ') {
            current = _create_token(WHITESPACE, " ");
            _add_token(&head, current);
            i++;
        }
        else if (input[i] == "\t") {
            current = _create_token(WHITESPACE, "\t");
            _add_token(&head, current);
            i++;
        }
        else if (input[i] == '|') {
            current = _create_token(PIPE, "|");
            _add_token(&head, current);
            i++;
        }
        else if (input[i] == '>') {
            current = _create_token(REDIRECT_OUT, ">");
            _add_token(&head, current);
            i++;
        }
        else if (input[i] == '<') {
            current = _create_token(REDIRECT_IN, "<");
            _add_token(&head, current);
            i++;
        }
        else if (input[i] == '$') {
            current = _create_token(ENV, "$");
            _add_token(&head, current);
            i++;
        }
        else if (input[i] == '\\') {
            current = _create_token(ESCAPE, "\\");
            _add_token(&head, current);
            i++;
        }
        else if (input[i] == '\'') {
            current = _create_token(QUOTE, "\'");
            _add_token(&head, current);
            i++;
        }
        else if (input[i] == '\"') {
            current = _create_token(DQUOTE, "\"");
            _add_token(&head, current);
            i++;
        }
        else if (input[i] == '\n') {
            current = _create_token(NEWLINE, "\n");
            _add_token(&head, current);
            i++;
        }
        else {
            // i need to retrieve the whole word then add it to the linked list

            

        }
        


}