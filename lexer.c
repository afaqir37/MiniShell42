#include "minishell.h"
//  Shunting yard algorithm

// echo"$USER | "$$'$PATH'>file|cat <<limiter>file|cat<file>>out_file

t_token *_lexer(char *input)
{
	t_token             *head;
	t_token             *current;
    enum e_token   type;
    int                 i;
    int                 j;

    i = 0;
    j = 0;
    head = NULL;
    while(input[i]) {
        while(input[i] && (input[i] == ' ' || input[i] == '\t'))
            i++;
        if (!input[i])
            break;
        if (!_it_contains(input[i])) {
            j = i;
            while(input[i] && !_it_contains(input[i])) {
                i++;
            }
            type = WORD;
            current = _create_token(ft_substr(input, j, i - j), type);
            _add_token(&head, current);

        }
        else if (input[i] == '|') {
            current = _create_token(ft_substr(input, i, 1), PIPE);
            _add_token(&head, current);
            i++;
        }
        else if (input[i] == '<') {
            // in case here doc
            if (input[i] && input[i + 1] == '<') {
                current = _create_token(ft_substr(input, i, 2), HERE_DOC);
                _add_token(&head, current);
                i += 2;
            }
            else {
                current = _create_token(ft_substr(input, i, 1), REDIRECT_IN);
                _add_token(&head, current);
                i++;
            }
        }
        else if (input[i] == '>') {
            // in case append
            if (input[i] && input[i + 1] == '>') {
                current = _create_token(ft_substr(input, i, 2), REDIRECT_APPEND);
                _add_token(&head, current);
                i += 2;
            }
            else {
                current = _create_token(ft_substr(input, i, 1), REDIRECT_OUT);
                _add_token(&head, current);
                i++;
            }
        }
        else if (input[i] == '\"') {
            current = _create_token(ft_substr(input, i, 1), DOUBLE_QUOTE);
            _add_token(&head, current);
            i++;
            j = i;
            while(input[i] && input[i] != '\"')
                i++;
            if (!input[i]) {
                printf("Error: unclosed double quote\n");
                return (NULL);
            }
            else if (input[i] == '\"') {
                current = _create_token(ft_substr(input, j, i - j), WORD);
                _add_token(&head, current);
                current = _create_token(ft_substr(input, i, 1), DOUBLE_QUOTE);
                _add_token(&head, current);
                i++;
            }

        }
        else if (input[i] == '\'') {
            current = _create_token(ft_substr(input, i, 1), QUOTE);
            _add_token(&head, current);
            i++;
            j = i;
            while(input[i] && input[i] != '\'')
                i++;
            if (!input[i])
            {
                printf("Error: unclosed single quote\n");
                return (NULL);
            }
            else if (input[i] == '\'') {
                current = _create_token(ft_substr(input, j, i - j), WORD);
                _add_token(&head, current);
                current = _create_token(ft_substr(input, i, 1), QUOTE);
                _add_token(&head, current);
                i++;
            }
        }
}

return (head);
}