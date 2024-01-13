#include <iostream>
using namespace std;
/*

*/
class GameEntry
{
    int score;
    string name;

public:
    GameEntry(const string &name = "", int score = 0)
    {
        this->name = name;
        this->score = score;
    }
    int getScore()
    {
        return score;
    }
    string getName()
    {
        return name;
    }
};

class Score
{
    GameEntry *entries;
    int numEntries, maxEntries;

public:
    Score(int max = 10)
    {
        maxEntries = max;
        numEntries = 0;
        entries = new GameEntry[maxEntries];
    }
    void add(GameEntry &e)
    {
        int newScore = e.getScore();
        if (numEntries == 0)
        {
            entries[numEntries] = e;
            numEntries++;
        }
        else if (numEntries == maxEntries)
        {
            if (newScore < entries[maxEntries - 1].getScore())
                return;
        }
        else{
            numEntries++;
            int i = numEntries - 2;
            while(i>=0 && newScore > entries[i].getScore()){
                entries[i + 1] = entries[i];
                i--;
            }
            entries[++i] = e;
        }
    }
    void display(){
        cout << "Name : Score \n";
        for (int i = 0; i < numEntries;i++){
            cout << entries[i].getName() << " " << entries[i].getScore() << endl;
        }
    }
};

int main()
{
    // Score obj;
    // GameEntry g1, g2, g3, g4, g5, g6;
    // g1 = GameEntry("Deepu",89);
    // g2 = GameEntry("Shiv",23);
    // g3 = GameEntry("Rudra",45);
    // g4 = GameEntry("Shivansh",90);
    // g5 = GameEntry("Deepu",89);
    // g6 = GameEntry("Sakshi",67);
    // obj.add(g1);
    // obj.add(g2);
    // obj.add(g3);
    // obj.add(g4);
    // obj.add(g5);
    // obj.add(g6);
    // obj.display();

    Score obj;
    GameEntry *g;
    int n, score;
    string name;
    cout << "Enter number of data entries : ";
    cin >> n;
    g = new GameEntry[n];
    for (int i = 0; i < n; i++)
    {
        cout << (i + 1) << ".Name ";
        cin >> name;
        cout << (i + 1) << ".Score : ";
        cin >> score;
        g[i] = GameEntry(name, score);
        obj.add(g[i]);
    }
    obj.display();
    return 0;
}