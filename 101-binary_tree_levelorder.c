#include "binary_trees.h"

levelorder_queue_node_t *create_queue_node(binary_tree_t *node);
void free_queue(levelorder_queue_node_t *head);
void process_and_enqueue(binary_tree_t *node, levelorder_queue_node_t *head,
			levelorder_queue_node_t **tail, void (*func)(int));
void dequeue(levelorder_queue_node_t **head);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));

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
 * process_and_enqueue - Processes a binary tree node and enqueues its chidren.
 * @node: The binary tree node to process and enqueue.
 * @head: A pointer to the head of the queue.
 * @tail: A pointer to the tail of the queue.
 * @func: A function pointer to call on the node.
 */
void process_and_enqueue(binary_tree_t *node, levelorder_queue_node_t *head,
			levelorder_queue_node_t **tail, void (*func)(int))
{
	levelorder_queue_node_t *new_node;

	func(node->n);

	if (node->left != NULL)
	{
		new_node = create_queue_node(node->left);
		if (new_node == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = new_node;
		*tail = new_node;
	}
	if (node->right != NULL)
	{
		new_node = create_queue_node(node->right);
		if (new_node == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = new_node;
		*tail = new_node;
	}
}

/**
 * dequeue - Removes the head node from the level-order traversal queue.
 * @head: A pointer to the head of the queue.
 */
void dequeue(levelorder_queue_node_t **head)
{
	levelorder_queue_node_t *temp;

	temp = (*head)->next;
	free(*head);
	*head = temp;
}

/**
 * binary_tree_levelorder - Traverses a binary tree using levelorder traversal.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A function pointer to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	levelorder_queue_node_t *head, *tail;

	if (tree == NULL || func == NULL)
		return;

	head = tail = create_queue_node((binary_tree_t *)tree);
	if (head == NULL)
		return;

	while (head != NULL)
	{
		process_and_enqueue(head->node, head, &tail, func);
		dequeue(&head);
	}

	free_queue(head);

}
