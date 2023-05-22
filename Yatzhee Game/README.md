# Yatzhee Game

This is a simple implementation of the Yatzhee game in C. The game allows multiple players to play and keeps track of their scores. The program utilizes random number generation to simulate dice rolls.

## Rules of the Game

The Yatzhee game consists of multiple rounds, where each player takes turns rolling five dice. The player can choose to re-roll some or all of the dice up to three times. After each roll, the player selects a category to score their roll based on the combinations shown on the dice. The available categories include ones, twos, threes, fours, fives, sixes, three of a kind, four of a kind, full house, small straight, large straight, Yatzhee, and Lucy.

The game continues for 13 rounds, and at the end, the player with the highest total score wins. Additionally, players can earn bonus points if their total score in the ones to sixes categories is 63 or higher.

## How to Play

1. Run the program.
2. Enter the number of players participating in the game.
3. Enter the name and surname for each player.
4. Follow the prompts to play the game and make choices for dice rolls and scoring categories.
5. After completing 13 rounds, the winner will be announced based on the total scores.

## Code Structure

The code is structured as follows:

- The `gamer` structure defines the attributes for each player, including their scores, name, surname, and total score.
- The game logic is implemented in the `play_yatzhee` function, which handles the rounds, dice rolls, player turns, and scoring.
- There are separate functions for each scoring category, such as `number_calculator`, `tree_of_a_kind`, `four_of_a_kind`, `full_house`, `small_straight`, `large_straight`, `yatzhee`, `lucy`, and `pass`.
- The `player_entry` function collects player information.
- The `roll_dice` function generates random numbers to simulate dice rolls.

 ## Credits ##

This program was created by Anıl Akpınar.

Feel free to modify and use the code according to your needs. Have fun playing Yatzhee!


