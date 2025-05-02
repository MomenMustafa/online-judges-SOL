#include <bits/stdc++.h>
using namespace std;
// uva 10388

struct Player
{
    string name;
    deque<char> hadnPile;
    deque<char> groundPile;

    Player(string name, string pile) : name(name)
    {
        for (int i = 0; i < pile.size(); i++)
            hadnPile.push_back(pile[i]);
    }

    void DisplayGroundPile()
    {
        for (int i = groundPile.size() - 1; i >= 0; i--)
            cout << groundPile[i];
        cout << endl;
    }

    char FlipCard()
    {
        if (hadnPile.empty())
            NewPile();
        char card = hadnPile.front();
        hadnPile.pop_front();
        groundPile.push_back(card);
        return card;
    }
    static void Snap(Player &p1, Player &p2)
    {
        short winner = random() / 141 % 2;
        cout << "Snap! for ";
        if (winner == 0) // jane wins
        {
            cout << "Jane: ";
            p1.groundPile.insert(p1.groundPile.end(), p2.groundPile.begin(), p2.groundPile.end());
            p2.groundPile.clear();

            p1.DisplayGroundPile();
        }
        else // john wins
        {
            cout << "John: ";
            p2.groundPile.insert(p2.groundPile.end(), p1.groundPile.begin(), p1.groundPile.end());
            p1.groundPile.clear();

            p2.DisplayGroundPile();
        }
    }

    void NewPile()
    {
        while (!groundPile.empty())
        {
            hadnPile.push_back(groundPile.front());
            groundPile.pop_front();
        }
    }
};

struct Game
{
    int round;
    Player Jane;
    Player John;

    Game(string name1, string name2, string pile1, string pile2) : Jane(name1, pile1), John(name2, pile2) { round = 0; }

    string isWinner()
    {
        if (Jane.hadnPile.empty() && Jane.groundPile.empty())
            return John.name;
        else if (John.hadnPile.empty() && John.groundPile.empty())
            return Jane.name;

        return "ny"; // not yet
    }
    void draw()
    {
        if (++round == 1000)
        {
            cout << "Keeps going and going ...\n";
            return;
        }
        char johnCard = John.FlipCard();
        char janeCard = Jane.FlipCard();

        if (johnCard == janeCard)
        {
            Player::Snap(Jane, John);

            if (isWinner() != "ny")
            {
                cout << isWinner() << " wins." << endl;
                return;
            }
        }
    }
};
int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        string Jane, John;
        cin >> Jane >> John;
        Game game("Jane", "John", Jane, John);

        while (game.round < 1000)
        {
            game.draw();
            if (game.isWinner() != "ny")
                break;
        }
        if (t)
            puts("");
    }

    return 0;
}