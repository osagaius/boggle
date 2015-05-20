# Team 10 - Boggle

![bogglepic.png](https://bitbucket.org/repo/g9Xa75/images/3830918110-bogglepic.png)

## Summary

This project implements of the popular game Boggle with C++ CLI, and allows players to interact with game with a fluid UI, and also allows them to store their score, with the hope of being the best Boggler.

## Algorithms & Data Structures
The list of valid words (dictionary) was stored in the application, and searched through, using a Trie data structure. In our implementation of the trie, or digital tree, each node's position in the tree defines the key with which it is associated. Using the trie, we can search for words in O(M) time.

## WOW Factors
### Missed Words
We implemented a feature which displays the possible words that the player could have guessed, once the game is completed. This feature was completed by implementing the depth first search algorithm and the Trie structure we developed.
### Trie Structure
As mentioned above, we implemented a complex data structure, which we subsequently leveraged for different parts of the game.

## Known Bugs
None.
