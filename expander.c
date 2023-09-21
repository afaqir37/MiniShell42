#include "minishell.h"

int _contains_dollar(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        if (str[i] == '$')
            return 1;
        i++;
    }
    return 0;
}

char    *_expand_word(char *content)
{
    char    *result;
    char    *tmp;
    char    *tmp2;
    char    *tmp3;
    int     i;
    int     j;
    int     k;

    i = 0;
    j = 0;
    k = 0;
    result = ft_calloc(1, 1);
               

    while (content[i])
    {  
        printf("%s\n", content);
        printf("%d\n", i);
        if (content[i] == '$')
        {
            tmp = ft_substr(content, j, i - j);
            tmp2 = ft_strjoin(result, tmp);
            free(result);
            result = tmp2;
            free(tmp);
            j = i;
            i++;
            while (content[i] && ft_isalnum(content[i]))
                i++;
            tmp = ft_substr(content, j + 1, i - j - 1);
            tmp2 = getenv(tmp);
            if (!tmp2)
                tmp2 = ft_strdup("");
            tmp3 = ft_strjoin(result, tmp2);
            printf("%s\n", tmp3);
            free(result);
            result = tmp3;
            free(tmp);
            free(tmp2);
            j = i;
        }
        if (content[i])
            i++;
      
    }
            printf("%s\n", tmp3);
    tmp = ft_substr(content, j, i - j);
    tmp2 = ft_strjoin(result, tmp);
    free(result);
    result = tmp2;
    free(tmp);
    return result;
}

void    _expander(t_token **result)
{
    t_token*    head;

    head = *result;
    while (head)
    {
        if (_contains_dollar(head->content) && (head->state == GENERAL || head->state == IN_DQUOTE))
        {
            
            head->content = _expand_word(head->content);
        }
        head = head->next;
    }
}