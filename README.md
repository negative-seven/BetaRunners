# BetaRunners

BetaRunners is a [DepotDownloader](https://github.com/SteamRE/DepotDownloader) wrapper for old SpeedRunners manifests.

## Usage
1. Download the latest [release](https://github.com/negative-seven/BetaRunners/releases)
2. Unzip the files into a directory of your choice
3. Launch BetaRunners.exe
4. Input your Steam username, Steam password, Steam Guard code (if applicable) and game version
5. Wait a bit
6. Feel the nostalgia

## Compiling manually
```
git clone https://github.com/negative-seven/BetaRunners
cd BetaRunners
git submodule init
git submodule update
```
Then open BetaRunners.sln in Visual Studio 2015+ and compile

## Generating versions.txt manually
1. Download [versions.py](https://gist.github.com/ZombieWizzard/715932834ffba38ebb7b8dbef39cf60f)
2. Place in the same directory as DepotDownloader
3. Create a file called `userdetails.py` and create 2 variables user and password with your details
4. Create a line seperated list of manifests to extract versions from in a file called `manifests.txt`
5. Run versions.py with Python 3
