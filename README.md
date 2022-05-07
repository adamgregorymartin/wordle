# wordle
This is a command line application for the NYT game Wordle. 
The project includes a framework to play the game and algorithms to estimate optimal guesses.

v1
Defines a framework for the game and an interface for a human to play.
The FeedbackBuilder and Feedback classes are designed to efficiently test a large number of words.
(Although this isn't important for the human only component currently implemented.)

Future Versions
Design an algorithm to compute effective guesses based on previous guesses and feedback.

  Resources:
    A list of ~13,000 valid Wordle words
    A list of english word frequency on the internet from Kaggle
    A list of previous Wordle solutions

  A brute force algorithm exploring the full game tree without optimization will not be tractable.
  For example:
    First define the following variables:
      P1 = Number of possible solutions before round 1 (~13,000)
      G1 = Number of possible guess words (~13,000 for every round in easy mode)
    If:
      P1 = 13,000, G1 = 13,000
      P2 = 1,500, G2 = 13,000
      P3 = 400, G3 = 13,000
      P4 = 100, G4 = 13,000
      P5 = 1
      Number of comparisons = 13000 * 13000 * 1500 * 13000 * 400 * 100 ~ 2.2x10^28
  
  Fortunately, there are some obvious optimizations.
    - Use a gready algorithm to minimize the number of possible solutions in n turns
      - Instead of minimizing the number of turns to rule out all but 1 word 
    - Prune guess words that are unlikely to be effective
    - Consider that some words are more likely than others
      - (The Kaggle online frequency of previous solutions appears log normal.)
      - 3/4 of the probability mass of P1 is likely far fewer than 13,000 * (3/4)
    - Within each round, the result following a complete representation of feedback may be cached.
    - The first guess can be computed ahead of time and stored.
    

