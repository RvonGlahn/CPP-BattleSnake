# C++ BattleSnake Project

![tests](https://github.com/RvonGlahn/CPP-BattleSnake/actions/workflows/ubuntu.yml/badge.svg)

This is a C++ library for battlesnake.
Different snakes will be provided for the use in battlesnake arenas.
You need a webserver to deploy a Snake.
For further details see the battlesnake [documentation](https://docs.battlesnake.com/references/api).

## Installation

Setup is easy with the help of make and cmake.
No dependencies are needed. Only Catch2 for testing the library is used.

```Bash
make install
make setup
```

You might need to restart the console here or use ``source ~/.profile`` on unix.

```Bash
make prepare
```

## Usage

Project is split in three libraries agents, environment and logic:

- Battlesnake game objects are implemented in the environment library.
- Heuristics, Algorithms and Game Trees can be found in the logic library.
- Agents use different logic and can be found in the agents library.

Include an agent in your webserver and make sure to parse the json requests correctly.
