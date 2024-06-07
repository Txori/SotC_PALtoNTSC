# SotC_PALtoNTSC
SotC_PALtoNTSC is a simple tool to convert Shadow of the Colossus' remastered textures by Sad Origami from PAL (SCES-53326) to NTSC (SCUS-97472).

**Introduction**

Sad Origami is doing incredible work [remastering the textures of the PS2 game Shadow of the Colossus](https://ko-fi.com/sadorigami), but it only works for the PAL version of the game (SCES-53326). This tool simply gathers, renames and copies the files to make them compatible with the NTSC version of the game (SCUS-97472).


**Compilation**

Simply compile using the following command: ```g++ -O3 -std=c++17 -o SotC_PALtoNTSC.exe SotC_PALtoNTSC.cpp -lstdc++fs```

For Mac: ```g++ -O3 -std=c++17 -o SotC_PALtoNTSC SotC_PALtoNTSC.cpp```


**How to**

1. Follow Sad Origami's instructions to add his texture pack to the PCSX2/textures folder.
2. Place the output file in the PCSX2/textures folder.
3. Run the output file. It's done.

**Note**

It is possible that this tool can convert other PS2 game texture packs from PAL to NTSC. Simply rename the folders sourceDir and destinationDir in the source code. If that's the case, please let me know, I'll modify the tool to convert any game from PAL to NTSC and vice versa. But right now, I'm under the Shadow of the Colossus.
