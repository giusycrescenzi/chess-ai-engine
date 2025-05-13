this is a chess engine, made by Giuseppe Crescenzi, giusycrescenzi on GitHub

WHY DID I START THIS PROJECT
- use pure C++, without big libraries like Qt, sfml, wxWidgets
- practice classes and ADTs, distribute the code
- start using ai
- improve problem solving

HOW DOES IT WORK
- the board class instantiate pieces and creates the space
- every piece has its own class, overloading the base class Piece
- check if moves are legal, if so the game goes on
- can be 1vsAI or 1vs1 with a friend
