#include "pushswap.h"

void check_list(t_list *heada)
{
    t_list *trav = NULL;
    t_list *next = NULL;

    next = heada;
    while(next)
    {
        trav = next->next;
        while (trav)
        {
            if (*(int*)next->data == *(int*)trav->data)
            {
                ft_lstclear(&heada);
                exit(write (2,"Error , Duplicated number !",28));
            }

            trav = trav->next;
        }
        next = next->next;
    }
}

int  indexing(t_list *heada)
{
    t_list *first;
    t_list *second;
    int index;
    int qts;

    qts = 0;
    first = heada;
    while (first)
    {
        index = 0;
        second = heada;
        while (second)
        {
            if (*(int *)first->data > *(int *)second->data)
                index++;
            second = second->next;
        }
        first->index = index;
        first = first->next;
        qts++;
    }
    return (qts);
}
char *prepare_str(int argc, char *argv[])
{
    char *str;
    int  counter = 0;
    int i;
    int k;

    if (argc < 2)
        return (NULL);
    else if(argc >= 2)
    {
        counter = counter_args(argc, argv);
        if(counter == -1)
            exit(write (2,"error in the number !\n",23));
        str = malloc(counter + 1);
        if  (str == NULL)
            return NULL;
        str[0] = '\0';
        i = 1;
        while (i < argc)
        {
            k = 0;
            while (argv[i][k] &&  (argv[i][k]  == ' ' || argv[i][k]  == '\t'))
                    k++;
            if (argv[i][k] == '\0')
                return (free (str),NULL);
            str = ft_strcat(str, argv[i]);
            if (i < argc - 1)
                ft_strcat(str, " ");
            i++;
        }
    }
    return str;
}

int main (int argc, char *argv[])
{
    t_list *heada;
    t_list *headb;
    char *str;
    str = prepare_str(argc, argv);
    if (str == NULL)
        exit(write (2,"Error string khawi\n",19));
    char **tab = ft_split(str, ' ');
    free(str);
    heada = list_create(tab);
    free_tab(tab);
    check_list(heada);
    int q = indexing(heada);
    if (!check_sort(heada))
        choice(&heada,&headb,q);
    else 
        write (1,"list already sorted !\n",23);
    ft_lstclear(&heada);
  return (0);
}