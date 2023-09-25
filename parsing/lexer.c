#include "../minishell.h"


t_token *_lexer(char *input)
{
	t_token             *head;
	t_token             *current;
    enum e_state        state;
    int                 i;
    int                 j;
    int                 token_created;
    char                *s;

    i = 0;
    j = 0;
    token_created = 0;
    head = NULL;
    s = ft_strdup("");
    while(input[i]) {
        token_created = 0;
        while(input[i] && (input[i] == ' ' || input[i] == '\t'))
            i++;
        if (!input[i])
            break;
        if (!_it_contains(input[i])) {
            j = i;
            while(input[i] && !_it_contains(input[i])) {
                if (input[i] == '\"') {
                    token_created = 1;
                    //s = ft_substr(input, j, i - j);
                    // current = _create_token(s, WORD, GENERAL, 0);
                    // _add_token(&head, current);
                    i++;
                    j = i;
                    while(input[i] && input[i] != '\"')
                        i++;
                    if (!input[i]) {
                        printf("Error: unclosed double quote\n");
                        return (NULL);
                    }
                else if (input[i] == '\"') {
                    if ((input[i+1] && _it_contains(input[i+1])) || !input[i+1])
                        current = _create_token(ft_strjoin(s, ft_substr(input, j, i - j)), WORD, IN_DQUOTE, 1);
                    else
                        current = _create_token(ft_strjoin(s, ft_substr(input, j, i - j)), WORD, IN_DQUOTE, 0);
                    _add_token(&head, current);
                    i++;
                    j = i;
                }
            
                }
                else if (input[i] == '\'') {
                    token_created = 1;
                    //s = ft_substr(input, j, i - j);
                    // current = _create_token(s, WORD, GENERAL, 43);
                    // _add_token(&head, current);
                    i++;
                    j = i;
                    while(input[i] && input[i] != '\'')
                        i++;
                    if (!input[i])
                    {
                        printf("Error: unclosed single quote\n");
                        return (NULL);
                    }
                    else if (input[i] == '\'' && i != j) {
                        if ((input[i+1] && _it_contains(input[i+1])) || !input[i+1])
                            current = _create_token(ft_strjoin(s, ft_substr(input, j, i - j)), WORD, IN_QUOTE, 1);
                        else
                            current = _create_token(ft_strjoin(s, ft_substr(input, j, i - j)), WORD, IN_QUOTE, 0);
                        _add_token(&head, current);
                        i++;
                        j = i;
                    }
                }
                else {
                    //printf("input[i] = %c\n", input[i]);
                    s = _append(s, input[i]);
                    i++;
                    if (_it_contains(input[i]) || !input[i] || input[i] == '\"' || input[i] == '\'') {
                        token_created = 1;
                        if (input[i] == '"' || input[i] == '\'')
                            current = _create_token(s, WORD, GENERAL, 0);
                        else
                            current = _create_token(s, WORD, GENERAL, 1);
                        _add_token(&head, current);
                        //free(s);
                        s = ft_strdup("");
                    }
                }
            }
            // if (!token_created) {
            //     current = _create_token(ft_substr(input, j, i - j), WORD, GENERAL, 1);
            //     _add_token(&head, current);                
            // }


        }
        else if (input[i] == '|') {
            current = _create_token(ft_substr(input, i, 1), PIPE, GENERAL, 1);
            _add_token(&head, current);
            i++;
        }
        else if (input[i] == '<') {
            // in case here doc
            if (input[i] && input[i + 1] == '<') {
                current = _create_token(ft_substr(input, i, 2), HERE_DOC, GENERAL, 1);
                _add_token(&head, current);
                i += 2;
            }
            else {
                current = _create_token(ft_substr(input, i, 1), REDIRECT_IN, GENERAL, 1);
                _add_token(&head, current);
                i++;
            }
        }
        else if (input[i] == '>') {
            // in case append
            if (input[i] && input[i + 1] == '>') {
                current = _create_token(ft_substr(input, i, 2), REDIRECT_APPEND, GENERAL, 1);
                _add_token(&head, current);
                i += 2;
            }
            else {
                current = _create_token(ft_substr(input, i, 1), REDIRECT_OUT, GENERAL, 1);
                _add_token(&head, current);
                i++;
            }
        }

}

return (head);
}