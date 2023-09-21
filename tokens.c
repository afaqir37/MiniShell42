#include "minishell.h"

t_token*    _create_token(char *value, enum e_token type)
{
    t_token *token;

    token = malloc(sizeof(t_token));
    if (!token)
        return (NULL);
    token->type = type;
    token->content = value;
    token->next = NULL;
    return (token);
}

void    _add_token(t_token **head, t_token *new)
{
    t_token *current;

    if (!*head)
    {
        *head = new;
        return;
    }
    current = *head;
    while (current->next)
        current = current->next;
    current->next = new;
}

