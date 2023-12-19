#include "deck.h"
#include <string.h>
#include <stdlib.h>

/**
 * compare_cards - Comparison function for qsort.
 *
 * @card1: Pointer to the first card.
 * @card2: Pointer to the second card.
 *
 * Return: Integer less than, equal to, or greater than zero if card1 is found,
 *         respectively, to be less than, to match, or be greater than card2.
 */
int compare_cards(const void *card1, const void *card2)
{
	const card_t *c1 = *(const card_t **)card1;
	const card_t *c2 = *(const card_t **)card2;

	if (c1->kind != c2->kind)
		return (c1->kind - c2->kind);

	return (strcmp(c1->value, c2->value));
}

/**
 * sort_deck - Sorts a deck of cards.
 *
 * @deck: Pointer to the head of the deck.
 */
void sort_deck(deck_node_t **deck)
{
	size_t count = 0;
	deck_node_t *current = *deck;
	card_t *cards[52];
	size_t i;

	while (current)
	{
		cards[count++] = (card_t *)current->card;
		current = current->next;
	}

	qsort(cards, count, sizeof(card_t *), compare_cards);

	current = *deck;
	for (i = 0; i < count; ++i)
	{
		current->card = cards[i];
		current = current->next;
	}
}
