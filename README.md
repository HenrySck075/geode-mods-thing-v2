# Included in this mod (for now)
- Node events, including:
  + Node addition (when addChild is called, which means 1 node might get called multiple times)
  + Node removal (when removeChild is called)
  + Node parent move (when node gets removed but added to **another** parent on the same frame)
- [Free nitro](https://www.pixiv.net/en/artworks/93908269)

## What does a node event contains
- node events.
- ok seriously it contains every node changes mentioned above that happened in 1 frame (whatever cocos decides it is) 
- c++ code

