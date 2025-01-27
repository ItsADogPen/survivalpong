- 2024 12 09 -
Project created
Initialized project with basic code for a moving racket (main.cpp/.h, player.cpp/.h)
Basic initialization of update & draw context (updatedraw.cpp/.h)
Base structure for all play objects to pseudo-inherit from (objstructs.h)
miscellenous defines --> miscdefs.h

- 2024 12 09 --- 2024 12 15 -
Bouncing ball (ball.cpp/.h)
Game state (gamestate.cpp/.h)
update & draw context loop w/ separate manager for each gamestate (updatedraw.cpp/.h, qmanager.cpp/.h)

- 2024 12 16 -
Fixed qmanager not passing the right size of array to the update & draw manager.
Begun implementing DeltaTime

- 2024 12 18 -
Implemented time stuff (gametime.cpp/.h)
	- FPS Counter
	- Delta Time hasn't been tested, but it's technically there.

- 2024 12 21 -
Tested DeltaTime. Unless I'm misunderstanding the fundamentals, I think it's working as intended

- 2024 12 23 -
powerup.cpp/.h
Testing power up items moving from top to bottom of the screen
	- There's graphical flickering but it's expected with the way it's implemented so far
	- (Refer to ToDo.md)

- 2025 01 10 -
Reworked the powerups. Moved all random chance logic into the Movement() loop
Conceptually set-up trail system for Ball

- 2025 01 20 -
Randomized x position of Ball's at start
Set-up basic trails system. Maybe make a comet-like graphic