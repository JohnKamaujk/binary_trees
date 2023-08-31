#include "binary_trees.h"

levelorder_queue_node_t *create_queue_node(binary_tree_t *node);
void free_queue(levelorder_queue_node_t *head);
void enqueue(binary_tree_t *node, levelorder_queue_node_t **head,
		levelorder_queue_node_t **tail);
void dequeue(levelorder_queue_node_t **head);
int binary_tree_is_complete(const binary_tree_t *tree);

/**
 * create_queue_node - Creates a new level-order traversal queue node.
 * @node: The binary tree node to store in the new queue node.
 *
 * Return: A pointer to the newly created queue node, or NULL on failure.
 */
levelorder_queue_node_t *create_queue_node(binary_tree_t *node)
{
	levelorder_queue_node_t *new_node = malloc(sizeof(levelorder_queue_node_t));

	if (new_node == NULL)
		return (NULL);

	new_node->node = node;
	new_node->next = NULL;

	return (new_node);
}

/**
 * free_queue - Frees the memory allocated for the level-order traversal queue.
 * @head: A pointer to the head of the queue.
 */
void free_queue(levelorder_queue_node_t *head)
{
	levelorder_queue_node_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

/**
 * enqueue - Enqueues a binary tree node to the level-order traversal queue.
 * @node: The binary tree node to enqueue.
 * @head: A double pointer to the head of the queue.
 * @tail: A double pointer to the tail of the queue.
 *
 * Description: Upon malloc failure, exits with a status code of 1.
 */
void enqueue(binary_tree_t *node, levelorder_queue_node_t **head,
		levelorder_queue_node_t **tail)
{
	levelorder_queue_node_t *new_node;

	new_node = create_queue_node(node);
	if (new_node == NULL)
	{
		free_queue(*head);
		exit(1);
	}

	new_node->node = node;
	new_node->next = NULL;

	if (*tail == NULL)
	{
		*head = new_node;
		*tail = new_node;
	}
	else
	{
		(*tail)->next = new_node;
		*tail = new_node;
	}
}

/**
 * dequeue - Removes the front node from the level-order traversal queue.
 * @head: A double pointer to the head of the queue.
 */
void dequeue(levelorder_queue_node_t **head)
{
	levelorder_queue_node_t *temp;

	temp = (*head)->next;
	free(*head);
	*head = temp;
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to traverse.
 *
 * Return: If the tree is NULL or not complete, 0.
 *         Otherwise, 1.
 *
 * Description: Upon malloc failure, exits with a status code of 1.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	levelorder_queue_node_t *queue_head = NULL;
	levelorder_queue_node_t *queue_tail = NULL;
	unsigned char flag = 0;

	if (tree == NULL)
		return (0);

	enqueue((binary_tree_t *)tree, &queue_head, &queue_tail);

	while (queue_head != NULL)
	{
		if (queue_head->node->left != NULL)
		{
			if (flag == 1)
			{
				free_queue(queue_head);
				return (0);
			}
			enqueue(queue_head->node->left, &queue_head, &queue_tail);
		}
		else
			flag = 1;

		if (queue_head->node->right != NULL)
		{
			if (flag == 1)
			{
				free_queue(queue_head);
				return (0);
			}
			enqueue(queue_head->node->right, &queue_head, &queue_tail);
		}
		else
			flag = 1;

		dequeue(&queue_head);
	}

	free_queue(queue_head);
	return (1);
}
