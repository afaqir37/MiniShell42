#include "minishell.h"

int _it_contains(int c)
{
    if (c == '|' || c == '<' || c == '>'
        || c == '\t' || c == ' ')
        return (1);
    return (0);
}