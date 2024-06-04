# SotC_PALtoNTSC
SotC_PALtoNTSC is a simple tool to convert Shadow of the Colossus' remastered textures by Sad Origami from PAL (SCES-53326) to NTSC (SCUS-97472).

**Introduction**

Sad Origami is making an incredible work at [remastering the textures of the PS2 game Shadow of the Colossus](https://ko-fi.com/sadorigami), but it only work for the PAL version of the game (SCES-53326). This tool simply gathers, rename and copy its files to make them compatible with the NTSC version of the game (SCUS-97472).


**Compilation**

Simply use [w64devkit by skeeto](https://github.com/skeeto/w64devkit): ```g++ -O3 -std=c++17 -o SotC_PALtoNTSC.exe SotC_PALtoNTSC.cpp -lstdc++fs```


**How to**

1. Follow Sad Origami's instructions to add his texture pack to the PCSX2/textures folder.
2. Put SotC_PALtoNTSC.exe file in PCSX2/textures too.
3. Run the exe file, it's done.

**Note**

It is possible that this tool can convert other PS2 games texture packs from PAL to NTSC. Simply rename the folders sourceDir and destinationDir in the source code. If that's the case, please tell me, I'll modify the tool to convert any game from PAL to NTSC and the other way around. But right now, I'm under the Shadow of the Colossus.
