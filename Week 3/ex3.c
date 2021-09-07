# include <stdio.h>
# include <stdlib.h>
# include <time.h>

int len;
struct L_List
{
	int val;
	struct L_List *nxt, *prv;
};
struct L_List *head = NULL;
void insert_node( struct L_List *node, int new_val )
{
	struct L_List* _node = malloc(sizeof(struct L_List));
	_node->nxt = NULL;
	_node->prv = node;
	_node->val = new_val;
	node->nxt = _node;
	len++;
}

void elements_print( struct L_List *node )
{
    if(node == NULL)
        return;
    printf("%d ", node->val);
    elements_print(node->nxt);
}

void delete_node( struct L_List *node )
{
	if( node->nxt != NULL && node->prv != NULL )
	{
		node->nxt->prv = node->prv;
		node->prv->nxt = node->nxt;
	}
	else if( node->nxt != NULL )
	{
		node->nxt->prv = NULL;
		head = node->nxt;
	}
	else if( node->prv != NULL )
		node->prv->nxt = NULL;
	else
		head = NULL;
	free(node);
	len--;
}

int main()
{
	srand(time(0));

	printf("\nEnter the size of the List: ");

	int n;
	scanf("%d", &n);
	struct L_List *now = NULL;
	for( int i = 1; i <= n; i ++ )
	{
		int x = rand() % 777;
		if( i > 1 )
		{
			insert_node(now, x);
			now = now->nxt;
		}
		else
		{
			head = (struct L_List*) malloc(sizeof(struct L_List));
			head->prv = NULL;
			head->nxt = NULL;
			head->val = x;
			now = head;
		}
	}
	printf("initial list: ");
	elements_print(head);

	printf("\n");
    printf("\n");

	while( len > 0 )
	{
		int ind = rand() % len + 1;
		now = head;
		for( int i = 0; i < ind; i ++ )
			now = now->nxt;

		delete_node(now);
		printf("element number %d is deleted from array\n", ind);
		printf("Our new array: ");
		elements_print(head);
		printf("\n");
		printf("\n");
	}
	return 0;
}

