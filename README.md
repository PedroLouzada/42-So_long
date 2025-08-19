# So_long

<img src="imgs/gif/final.gif" width="600" alt="Gameplay Demo" />

## About the Project

**So_long** is a graphical 2D game developed as part of the 42 school curriculum.  
The goal is simple: the player must navigate a maze-like map, collect all collectibles, and reach the exit — all while avoiding enemies!

This was my **first graphical project** using the **MiniLibX** library. I implemented both the mandatory part and the **bonus features**, including **animated sprites** and **enemy AI** that moves dynamically across the map.

---

## What I Learned

- Using the **MiniLibX** graphics library for 2D rendering.
- Handling **keyboard events** and building an interactive game loop.
- Managing **tile-based maps** loaded from external `.ber` files.
- Implementing **pathfinding logic** and enemy movement.
- Creating a clean structure for **rendering, updating, and animating** sprites.
- Managing **game state transitions** (win/loss, collisions, etc).

---

## Features Implemented

### ✅ Mandatory Features

- Load and validate `.ber` map files.
- Display a 2D map with walls, collectibles, player, and exit.
- Player can move with keyboard arrows or WASD.
- Collectibles must all be gathered before exit becomes accessible.
- Input and map validation with error handling.

### ⭐ Bonus Features

- **Animated sprites** for player, collectibles, enemies, and environment.
- **Enemies** that cause the player to lose on contact.
- Smooth rendering and frame updates.

---

## Compatibility

This project is compatible with Linux and uses the **MiniLibX** graphics library.  
It follows 42's standard restrictions (no external libraries outside those allowed).

---

## How to Use

Clone the repository and compile using:

```bash
git clone https://github.com/PedroLouzada/so_long.git
cd so_long
make
```
Then, run the game with a .ber map file:
```bash
./so_long maps/map01.ber
```
## Map Rules for so_long

- The map must be rectangular (all rows have the same length).
- Must contain exactly one player (P).
- Must contain at least one collectible (C).
- Must contain exactly one exit (E).
- May contain zero or more enemies (X).
- Walls are represented by 1.
- Empty spaces are represented by 0.
- The map must be fully enclosed by walls (the outer edges should be all 1).
- The map must be winnable — meaning the player can collect all collectibles and reach the exit without impossible obstacles.
- Use WASD or arrow keys to move the player.
- Collect all items (C) and reach the exit (E). Avoid enemies!

## Future Improvements

- Implement more intelligent enemy AI (e.g. pathfinding).
- Add sound effects and background music.
- Create a full level editor.
- Improve animation transitions and framerate optimization.
- Add save/load system or level progression.

## Final Thoughts

So_long was an incredible introduction to graphics programming and event-driven logic.
It taught me a lot about state management, optimization, and user experience — and gave me the satisfaction of building a full playable game from scratch! 🕹️🔥

If you're starting this project, enjoy the creative process — it’s a perfect mix of logic and design.

## Contact
Feel free to reach out:

[Github](https://github.com/PedroLouzada)
