# Game of Life (Hasbro) - Terminal Edition

A text-based implementation of the classic Hasbro board game "The Game of Life" built with C++ and ncurses.

## 📋 Features

- **Branching Path System**: Choose between College/Career, Family/Career paths, and Safe/Risk roads
- **1-2 Players**: Play against a friend
- **Terminal UI**: Clean interface using ncurses with box-drawing characters
- **Simple Controls**: Press ENTER to spin, make choices with letter keys

## 🎮 Game Flow

```
START
  │
  ├── COLLEGE ───┐
  │              │
  └── CAREER ────┘
         │
      GRADUATION
         │
    WEDDING DAY
         │
      ┌──┴──┐
      │     │
   FAMILY  CAREER
    PATH    PATH
      │     │
    HOUSE  PROMOTION
      │     │
   ┌──┴──┐  │
   │     │  │
SAFE  RISK  │
ROAD   ROAD │
   │     │  │
   └──┬──┴──┘
      │
   RETIREMENT
```

## 🎯 Space Effects

| Space | Effect |
|-------|--------|
| **START** | Begin here with $10,000 |
| **COLLEGE** | -$10K tuition, +$20K loan |
| **CAREER** | Get entry job: Clerk ($3K salary) |
| **GRADUATION** | College grad: Doctor ($8K) \| No college: Manager ($5K) |
| **WEDDING** | -$5K, married = Yes |
| **FAMILY PATH** | +1 kid, -$2K expenses |
| **CAREER PATH** | +$5K salary |
| **HOUSE** | -$50K, house = Yes ($100K value) |
| **PROMOTION** | +$5K salary |
| **SAFE ROAD** | +$3K safe gain |
| **RISK ROAD** | 50/50: +$15K or -$10K |
| **RETIREMENT** | Game ends, calculate winner |

## 🏆 Winning

Final score = Cash + (Kids × $20K) + (House ? $100K : 0)

## 🛠️ Requirements

- C++11 or later
- ncurses library
- Unix/Linux/macOS terminal

### Install ncurses:

**macOS:**
```bash
brew install ncurses
```

**Linux (Ubuntu/Debian):**
```bash
sudo apt-get install libncurses5-dev
```

## 📦 Compilation

```bash
# Clone the repository
git clone https://github.com/IJK7/COMP2113_Project.git
cd COMP2113_Project

# Compile
g++ -o gameoflife main.cpp Game.cpp Player.cpp Board.cpp -lncurses -std=c++11

# Run
./gameoflife
```

Or use the Makefile:
```bash
make
make run
```

## 🎮 How to Play (intrustions)

1. Run the game: `./gameoflife`
2. Enter number of players (1-2)
3. Enter player names
4. On your turn:
   - Press **ENTER** to spin the spinner
   - Make choices by pressing **A/B** when prompted
   - Press **ENTER** to continue to next player
5. First player to reach RETIREMENT triggers end game
6. Highest total wealth wins!

## 📁 Project Structure

```
COMP2113_Project/
├── main.cpp          # Main game loop
├── Game.hpp/cpp      # Game state management
├── Player.hpp/cpp    # Player class
├── Board.hpp/cpp     # Board and spaces
├── Makefile          # Compilation
└── README.md         # This file
```

## 🔧 Controls

- **ENTER**: Spin spinner / Continue
- **A/B**: Make choices at branches
- **Q**: Quit game
- **CTRL+C**: Exit

## ✨ Future Improvements

- [ ] Add more players (3-4)
- [ ] Stock market mini-game
- [ ] Insurance options
- [ ] Save/Load feature
- [ ] Color support
- [ ] Sound effects

## 📝 License

This project is for educational purposes. Game of Life is a trademark of Hasbro.

## 👥 Contributors

- Cheralyn
- Michelle
- Yin
- Carla
- Joylin

## 🐛 Known Issues

- None yet! Found a bug? Open an issue.

---

**Enjoy the game! May the best life win! 🎉**

