#include "pushswap.h"


size_t	ft_strlen(const char *str)
{
	size_t	x;

	x = 0;
	while (str[x])
		x++;
	return (x);
}

char	*ft_strcat(char *dest, const char *src)
{
	size_t	sd;
	size_t	y;

	sd = 0;
	y = 0;
	while (dest[sd])
		sd++;
	while (src[y]) 
	{
		dest[sd + y] = src[y];
		y++;
	}
	dest[sd + y] = '\0'; 
	return (dest);
}
int  counter_args( int argc, char *argv[])
{
    int counter = 0;
    int i = 1;
    while (i < argc)
    {
        int j = 0;
        while (argv[i][j])
        {
            counter++;
            j++;
        }
        if (i < argc - 1)
            counter++;
        i++;
    }
    return counter;
}

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
	return (node);
}

int ft_atoi(const char *nptr)
{
    int x;
    int signe;
    int num;

    x = 0;
    signe = 1;
    num = 0;
    while (nptr[x] == '\t' || nptr[x] == ' ' || (nptr[x] >= 9 && nptr[x] <= 13))
        x++;
    if (nptr[x] == '+' || nptr[x] == '-')
        if (nptr[x++] == '-')
            signe *= -1;
        if(!nptr[x])
            exit(write (2,"error in the number !\n",23));
    while (nptr[x] >= '0' && nptr[x] <= '9')
    {
         if (signe == 1 && (num > INT_MAX / 10 || (num == INT_MAX / 10 && (nptr[x] - '0') > INT_MAX % 10)))
             exit(write(2, "error: number exceeds INT_MAX\n", 31));
        else if (signe == -1 && (num > (long)INT_MAX / 10 || (num == (long)INT_MAX / 10 && (nptr[x] - '0') > ((long)INT_MAX % 10 + 1))))
            exit(write(2, "error: number is less than INT_MIN\n", 36));
        num = num * 10 + (nptr[x] - '0');
        x++;
    }
    if (nptr[x] != '\0' && (!(nptr[x] >= '1' && nptr[x] <= '9')) )
            exit(write (2,"error in the number !\n",23));
    return (num * signe);
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

char *prepare_str(int argc, char *argv[])
{
    char *str;
    int  counter = 0;
    int i;

    if (argc < 2)
    {
        printf("Usage: %s <list of integers>\n", argv[0]);
        return NULL;
    }
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
            str = ft_strcat(str, argv[i]);
            if (i < argc - 1)
                ft_strcat(str, " ");
            i++;
        }
    }
    return str;
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
    t_list *node;
    int i;
    int check;

    i = 0;
    while (tab[i])
    {   
        check = ft_atoi(tab[i]);
        if (check<INT_MAX || check >INT_MIN)
            node = ft_lstnew(check);
        if (node == NULL)
        {
            printf("Error\n");
            return NULL;
        }
        node->next = heada;
        heada = node;
        i++;
    }
    return (heada);
}
void check_list(t_list *heada)
{
    t_list *trav = NULL;
    t_list *next = NULL;

    next = heada;
    //trav = (*heada)->next;
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
int main (int argc, char *argv[])
{
    t_list *heada;
    t_list *headb;
    char *str;
    str = prepare_str(argc, argv);
    if (str == NULL)
        return 1;
    char **tab = ft_split(str, ' ');
    free(str);
    heada = list_create(tab);
    free_tab(tab);
    check_list(heada);
    t_list *tmp = heada;
    while (tmp)
    {
        printf("%d ", *(int*)tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
    ft_lstclear(&heada);
  return (0);
}