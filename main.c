#include "pushswap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
    if (!node)
		return (NULL);
    node->data = malloc(sizeof(int));
	if (!node->data)
		return (NULL);
	*(int*)node->data = content;
	node->next = NULL;
    node->index = 0;
	return (node);
}


void	ft_lstclear(t_list **lst)
{
	t_list	*ptr;
	t_list	*ptr2;

	if (!lst || !*lst)
		return ;
	ptr = *lst;
	while (ptr != NULL)
	{
		ptr2 = ptr->next;
		free(ptr->data);
		free(ptr);
		ptr = ptr2;
	}
	*lst = NULL;
}

void free_tab(char **tab)
{
    char **tmp = tab;
    while (*tmp)
    {
        free(*tmp);
        tmp++;
    }
    free(tab);
}

void list_assign(char **tab, t_list *heada)
{
    int i = 0;
    while (tab[i])
    {   
        t_list *node = ft_lstnew(ft_atoi(tab[i]));
        if (node == NULL)
        {
            printf("Error\n");
            return;
        }
        node->next = heada;
        heada = node;
        i++;
    }
}
t_list *list_create(char **tab)
{
    t_list *heada = NULL;
    t_list *tail = NULL;
    t_list *node;
    int i;

    i = 0;
    while (tab[i])
    {   
        node = ft_lstnew(ft_atoi(tab[i]));
        if (node == NULL)
            return(write(2,"Error\n",7),NULL);
        if (heada == NULL)
        {
            heada = node;
            tail = node;
        }
        else 
        {
            tail->next = node;
            tail = node;   
        }
        i++;
    }
    return (heada);
}

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

int calc_exit(t_list * head,t_list * min)
{
    t_list *trav;
    int toptomin;
    int mintobot;

    trav = head;
    toptomin = 0;
    mintobot = 0;
        while (*(int*)trav->data != *(int*)min->data)
        {
            trav = trav->next;
            toptomin++; 
        }
        while(trav->next != NULL)
        {
            trav = trav->next;
            mintobot++;
        }
        return (toptomin > mintobot);
}
void sort2(t_list *heada)
{
    if (*(int*)heada->data > *(int*)heada->next->data)
        sa(heada);
}
void sort3(t_list **heada,t_list **headb)
{
    t_list *min;
    t_list *trav;

    min = *heada;
    trav = *heada;
    while (trav)
    {
        if (*(int*)trav->data < *(int*)min->data)
            min = trav;
        trav = trav->next;
    }
    if (calc_exit(*heada, min) == 1)
        while (*(int *)(*heada)->data != *(int *)min->data)
            rra(heada);
    else
        while (*(int *)(*heada)->data != *(int *)min->data)
            ra(heada);
    pb(heada,headb);
    sort2(*heada);
    pa(heada,headb);
}


void sort4 (t_list **heada , t_list **headb)
{
    t_list *min;
    t_list *trav;

    trav = *heada;
    min = *heada;
    while (trav)
    {
        if (*(int*)trav->data < *(int*)min->data)
            min = trav;
        trav = trav->next;
    }
    if (calc_exit(*heada, min) == 1)
        while (*(int *)(*heada)->data != *(int *)min->data)
            rra(heada);
    else
        while (*(int *)(*heada)->data != *(int *)min->data)
            ra(heada);
    pb(heada,headb);
    sort3(heada,headb);
    pa(heada,headb);
}
void    sort5(t_list **heada , t_list **headb)
{
    t_list *min;
    t_list *trav;

    trav = *heada;
    min = *heada;
    while (trav)
    {
        if (*(int*)trav->data < *(int*)min->data)
            min = trav;
        trav = trav->next;
    }
    if (calc_exit(*heada, min) == 1)
        while (*(int *)(*heada)->data != *(int *)min->data)
            rra(heada);
    else
        while (*(int *)(*heada)->data != *(int *)min->data)
            ra(heada);
    pb(heada,headb);
    sort4(heada,headb);
    pa(heada,headb);
}
int check_bits (int q)
{
    int bits;

    bits =0;
        while (q)
        {
            q >>= 1;
            bits++;
        }
        return (bits);
}

void radix (t_list **heada, t_list **headb, int q)
{
    int bits;
    int bit;

    bits = check_bits(q);
    bit = 0;
    while (bit < bits)
    {
        int count = q;
        while (count--)
        {
            if (((*heada)->index >> bit ) & 1)
                ra(heada);
            else
                pb(heada,headb);
        }
        while (*headb)
            pa(heada,headb);
        bit++;
    }
}

void choice( t_list **heada , t_list **headb , int q )
{
    if (q == 5)
        sort5 (heada,headb);
    else if (q == 4)
        sort4 (heada,headb);
    else if (q == 3)
        sort3 (heada,headb);
    else if (q == 2)
        sort2 (*heada);
    else if (q == 1)
        write (1," free w exit layr7em l walidin",31);
    else
        radix (heada,headb,q);
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
    choice(&heada,&headb,q);
    // t_list *trav = heada;
    // while (trav)
    // {
    //     printf("[%d] ", *(int *)trav->data);
    //     trav = trav->next;
    // }
    ft_lstclear(&heada);
  return (0);
}