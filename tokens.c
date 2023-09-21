#include "minishell.h"

t_token*    _create_token(char *value, enum e_token type, enum e_state state)
{
    t_token *token;

    token = malloc(sizeof(t_token));
    if (!token)
        return (NULL);
    token->content = value;
    token->type = type;
    token->state = state;
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

