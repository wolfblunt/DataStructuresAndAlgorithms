'''
The line `cls._instance = super(MusicPlayer, cls).__new__(cls)` creates a new instance of MusicPlayer 
by calling the parent class’s `_new__` method and stores it in `cls._instance` to enforce the Singleton pattern, 
ensuring only one instance is ever created.
'''

'''
The __new__ method, which is a static method in Python responsible for creating a new instance of a class.
It's called before __init__ and controls the actual object creation.
'''

class MusicPlayer:
    _instance = None

    def __new__(cls):
        if cls._instance is None:
            cls._instance = super(MusicPlayer, cls).__new__(cls)
            cls._instance.current_song = None  # Initialize state
        return cls._instance

    def play_song(self, song: str):
        self.current_song = song
        return f"Playing {self.current_song}"

    def stop(self):
        if self.current_song:
            message = f"Stopped {self.current_song}"
            self.current_song = None
            return message
        return "No song is playing"

# Client code
def test_music_player():
    # Create two "instances" of MusicPlayer
    player1 = MusicPlayer()
    player2 = MusicPlayer()

    # Check if they are the same instance
    print(player1 is player2)  # Output: True

    # Use the player
    print(player1.play_song("Song A"))  # Output: Playing Song A
    print(player2.play_song("Song B"))  # Output: Playing Song B (overrides Song A)
    print(player1.current_song)         # Output: Song B (shared state)
    print(player2.stop())               # Output: Stopped Song B
    print(player1.current_song)         # Output: None (shared state)

# Usage
test_music_player()