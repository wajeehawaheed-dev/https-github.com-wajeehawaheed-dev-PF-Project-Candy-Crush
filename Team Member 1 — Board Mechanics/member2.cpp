

#include <iostream>
using namespace std;

int currentLevel = 1;
int maxUnlockedLevel = 1;
int lives = 5;
int volume = 5;
bool isMuted = false;     // mute flag
int totalStars = 0;
int levelStars[15] = { 0 }; // level stars will be 15
int currentlivestars = 0;  // live stars
int score = 0; // level score will be updated inside game loop
int currentMoves = 0;
int savedLevel, savedMaxLevel, savedLives, savedTotalStars;
int savedLevelStars[15];
int savedVolume;
bool savedIsMuted;

// Score thresholds per level
int scorethreshold[10][3] = {
    {10000,15000,20000},   // LEVEL 1
    {12000,18000,30000},   // LEVEL 2
    {14000,24000,45000},   // LEVEL 3
    {16000,30000,60000},   // LEVEL 4
    {18000,38000,70000},   // LEVEL 5
    {20000,45000,75000},   // LEVEL 6
    {22000,55000,80000},   // LEVEL 7
    {24000,60000,85000},   // LEVEL 8
    {26000,75000,90000},   // LEVEL 9
    {50000,80000,1000000} // LEVEL 10
};

// FUNCTION THAT PASSES MOVES EACH LEVEL
int getLevelMoves(int level)
{
    if (level == 1 || level == 2)
        return 20;
    if (level == 3 || level == 4)
        return 18;
    if (level == 5 || level == 6)
        return 15;
    if (level == 7 || level == 8)
        return 12;
    if (level == 9 || level == 10)
        return 10;
    return 0;
}

// FUNCTION THAT RETURNS STARS
int calculateStars(int score, int currentLevel)
{
    int first = scorethreshold[currentLevel - 1][0];
    int second = scorethreshold[currentLevel - 1][1];
    int third = scorethreshold[currentLevel - 1][2];

    if (score >= third)
        return 3;
    else if (score >= second)
        return 2;
    else if (score >= first)
        return 1;
    else
        return 0;
}

// Update stars after score changes
void updateStars()
{
    currentlivestars = calculateStars(score, currentLevel);
}

// CHECK LEVEL PASS/FAIL BASED ON SCORE ONLY
bool isLevelPassed()
{
    int requiredScore = scorethreshold[currentLevel - 1][0]; // minimum score needed
    return score >= requiredScore;
}

// LEVEL FAIL – DECREASE LIVES
void failLevel()
{
    lives--;
}

// LEVEL COMPLETE – UPDATE STARS AND UNLOCK NEXT LEVEL
void completeLevel()
{
    int stars = calculateStars(score, currentLevel);
    levelStars[currentLevel - 1] = stars;
    totalStars += stars;

    if (currentLevel < 10)
    {
        currentLevel++;

        if (currentLevel > maxUnlockedLevel)
            maxUnlockedLevel = currentLevel;

        if ((currentLevel % 5) == 1) // unlock other 5 levels at levels like 1 and 6
        {
            if (maxUnlockedLevel + 5 <= 10)
                maxUnlockedLevel += 5;
        }
    }
}

// PLAY LEVEL UNTIL MOVES FINISH
void playLevel(int gain)
{
    if (score == 0) // first move of the level
    {
        score = 0; // reset score for every level
        currentMoves = getLevelMoves(currentLevel);
        currentlivestars = 0;
    }

    // validation
    if (gain < 0)
        return;

    score += gain;
    currentMoves--;

    updateStars();

    // If score already meets pass condition
    if (isLevelPassed())
    {
        completeLevel();
        return;
    }

    // After all moves
    if (currentMoves == 0)
        failLevel();
}

//                       MENU

// Pause / Resume
bool gamePaused = false;
void Pause() {
    gamePaused = !gamePaused;
}

// Restart current level
void restartLevel() {
    score = 0;
    currentMoves = getLevelMoves(currentLevel);
    currentlivestars = 0;
}

// Save game in memory
void saveGame() {
    savedLevel = currentLevel;
    savedMaxLevel = maxUnlockedLevel;
    savedLives = lives;
    savedTotalStars = totalStars;
    for (int i = 0; i < 15; i++)
        savedLevelStars[i] = levelStars[i];
    savedVolume = volume;
    savedIsMuted = isMuted;
}

// Load game from memory
void loadGame() {
    currentLevel = savedLevel;
    maxUnlockedLevel = savedMaxLevel;
    lives = savedLives;
    totalStars = savedTotalStars;
    for (int i = 0; i < 15; i++)
        levelStars[i] = savedLevelStars[i];
    volume = savedVolume;
    isMuted = savedIsMuted;

    restartLevel(); // reset level variables
}

void setVolume(int newVolume) {
    if (newVolume < 0) newVolume = 0;
    if (newVolume > 10) newVolume = 10;
    volume = newVolume;

    // Automatically unmute if volume > 0
    if (volume > 0)
        isMuted = false;
}

// Toggle mute/unmute
void Mute() {
    if (isMuted) {
        // Unmute
        if (volume == 0) volume = 5;
        isMuted = false;
    }
    else {
        // Mute
        isMuted = true;
        volume = 0;
    }
}