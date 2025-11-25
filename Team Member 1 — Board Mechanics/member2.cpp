//#include <iostream>
//using namespace std;
//int currentLevel = 1;
//int maxUnlockedLevel = 1;
//int lives = 5;
//int volume = 5;
//int totalStars = 0;
//int levelStars[11] = { 0 };
//int getLevelMoves(int level)
//{
//    if (level == 1 || level == 2)
//        return 20;
//    if (level == 3 || level == 4)
//        return 18;
//    if (level == 5 || level == 6)
//        return 15;
//    if (level == 7 || level == 8)
//        return 12;
//    if (level == 9 || level == 10)
//        return 10;
//
//    return 0;
//}
//int calculateStars(int performance)
//{
//
//    if (performance >= 90)
//        return 3;
//    else if (performance >= 70)
//        return 2;
//    else if (performance >= 50)
//        return 1;
//    else
//        return 0;
//}
//
//
//void completeLevel(int performance)
//{
//    int stars = calculateStars(performance);
//    levelStars[currentLevel] = stars;
//    totalStars += stars;
//
//
//    if (currentLevel < 10)
//    {
//        currentLevel++;
//
//        if (currentLevel > maxUnlockedLevel)
//            maxUnlockedLevel = currentLevel;
//
//
//        if ((currentLevel % 5) == 1)
//        {
//            if (maxUnlockedLevel + 5 <= 10)
//                maxUnlockedLevel += 5;
//        }
//    }
//}
//int getDifficultyMoves(int difficulty, int baseMoves)
//{
//
//
//    if (difficulty == 1)
//        return baseMoves + 5;
//    else if (difficulty == 3)
//        return baseMoves - 5;
//    else
//        return baseMoves;
//}
//void setVolume(int v)
//{
//    if (v >= 0 && v <= 10)
//        volume = v;
//}
//
//
//void saveGame()
//{
//
//}
//
//void loadGame()
//{
//
//}
//
//
//void debugPrintStatus()
//{
//    cout << "Current Level: " << currentLevel << endl;
//    cout << "Max Unlocked Level: " << maxUnlockedLevel << endl;
//    cout << "Lives: " << lives << endl;
//    cout << "Volume: " << volume << endl;
//    cout << "Total Stars: " << totalStars << endl;
//}
//int main()
//{
//    int baseMoves = getLevelMoves(currentLevel);
//    int moves = getDifficultyMoves(2, baseMoves);
//    completeLevel(85);
//    return 0;
//}
