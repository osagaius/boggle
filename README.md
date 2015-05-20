Boggle

![bogglepic.png](https://s3.amazonaws.com/osamedia/3830918110-bogglepic.png)

## Summary

This project implements the popular game, Boggle, with C++ CLI. It allows players to interact with game with a fluid UI (as shown above). It also allows players to store their scores, with the hope of being the best Boggler.

## Algorithms & Data Structures
The list of valid words (dictionary) was stored in the application, and searched through, using a Trie data structure. In our implementation of the trie, or digital tree, each node's position in the tree defines the key with which it is associated. Using the trie, we can search for words in O(M) time.

## Cool Stuff
We implemented a feature which displays the possible words that the player could have guessed, once the game is completed. This feature was completed by implementing the depth first search algorithm and the Trie structure we developed.
